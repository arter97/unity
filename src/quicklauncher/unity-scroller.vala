/* -*- Mode: vala; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/*
 * Copyright (C) 2009 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by Gordon Allott <gord.allott@canonical.com>
 *
 */
using Unity.Quicklauncher;
namespace Unity.Widgets
{

  private enum ScrollerPhase
  {
    PANNING,
    SETTLING,
    REORDERING,
    FLUNG,
    BOUNCE
  }

  public enum ScrollerChildState
  {
    NORMAL,   /* normal view */
    HIDDEN,   /* still takes space but is not visible */
    REMOVED   /* ignored in the scroller, no space made */
  }

  public class ScrollerChild : Object
  {
    /* just a container for our children, we use an object basically just for
     * memory management. if the gobjectifying becomes an issue it should
     * be trivial to revert it to a struct with manual memory management
     * (ie: use no gobject features)
     */

    public float width = 0.0f;
    public float height = 0.0f;

    public float position = 0.0f;
    public ScrollerChildState state;

    public Clutter.Actor child;
    public Clutter.ActorBox box;

    private bool _is_hidden = false;
    public bool is_hidden {
      get { return this._is_hidden; }
      set {
        if (value && !this._is_hidden)
          {
            this.child.hide ();
          }
        if (!value && this._is_hidden)
          {
            this.child.show ();
          }

         this._is_hidden = value;
        }
    }

    public ScrollerChild ()
    {
    }
  }

  public class Scroller : Ctk.Actor, Clutter.Container
  {
    public bool order_changed;
    private const float DRAG_SAFE_ZONE = 200.0f;

    private ScrollerPhase phase;
    private uint drag_sensitivity = 3;
    private float click_start_pos = 0;
    private float _drag_pos = -0.0f;
    public float drag_pos {
      get { return this._drag_pos; }
      set {
        this._drag_pos = Math.floorf (value);
        this.queue_relayout ();
      }
    }
    private bool _is_dragging = false;
    private bool is_dragging {
        get { return this._is_dragging; }
        set
          {
            if (!this.is_dragging)
              {
                this.fling_timeline.stop ();
                if (this.scroll_anim is Clutter.Animation)
                  {
                    if (this.scroll_anim.has_property ("drag_pos"))
                      {
                        this.scroll_anim.unbind_property ("drag_pos");
                      }
                  }
              }
            foreach (ScrollerChild child in children)
              {
                child.child.set_reactive (!value);
              }
            this._is_dragging = value;
          }
    }
    private const float friction = 0.9f;
    private float last_drag_pos = 0.0f;
    private float fling_velocity = 0.0f;
    private uint fling_delta = 0;
    private uint last_mouse_event_time = 0;
    private float previous_y = -1000000000.0f;

    private ThemeImage bgtex;
    private ThemeImage top_shadow;
    private ThemeImage bottom_fade;

    private int _spacing;
    public int spacing {
      get { return _spacing; }
      set { queue_relayout (); _spacing = value; }
    }
    private Ctk.Orientation orientation = Ctk.Orientation.VERTICAL;

    private Gee.ArrayList<ScrollerChild> children;
    private float total_child_height;

    private Gee.HashMap<Clutter.Actor, Clutter.Animation> fadeout_stack;
    private Gee.HashMap<Clutter.Actor, Clutter.Animation> fadein_stack;
    private Gee.HashMap<Clutter.Actor, Clutter.Animation> anim_stack;
    private Clutter.Animation scroll_anim;

    private float hot_height = 0.0f;
    private float hot_start = 0.0f;

    private Clutter.Timeline fling_timeline;
    private bool button_down = false;

    public Scroller (Ctk.Orientation orientation, int spacing)
    {
      this.orientation = orientation;
      this.spacing = spacing;
      children = new Gee.ArrayList<ScrollerChild> ();
      fadeout_stack = new Gee.HashMap<Clutter.Actor, Clutter.Animation> ();
      fadein_stack = new Gee.HashMap<Clutter.Actor, Clutter.Animation> ();
      anim_stack = new Gee.HashMap<Clutter.Actor, Clutter.Animation> ();
    }

    construct {

      this.load_textures ();
      var mypadding = this.padding;

      mypadding.left = 0.0f;
      mypadding.right = 0.0f;
      mypadding.top = 5.0f;
      mypadding.bottom = 5.0f;

      this.padding = mypadding;

      // set a timeline for our fling animation
      this.fling_timeline = new Clutter.Timeline (1000);
      this.fling_timeline.loop = true;
      this.fling_timeline.new_frame.connect (this.on_scroller_frame);
      set_reactive (true);

      this.scroll_event.connect (this.on_scroll_event);
      this.button_press_event.connect (this.on_button_click_event);
      this.button_release_event.connect (this.on_button_release_event);
      this.motion_event.connect (this.on_motion_event);

      this.drag_pos = 0.0f;

      this.order_changed = true;
      var drag_controller = Drag.Controller.get_default ();
      drag_controller.drag_start.connect (this.on_unity_drag_start);
    }

    private void on_unity_drag_start (Drag.Model model)
    {
      // we aren't dragging outselfs so make sure we don't have button down set
      this.button_down = false;

      string data = model.get_drag_data ();
      // check to see if we are "interested" in the data, we just assume we
      // are for now

      // check to see if the data matches any of our children
      foreach (ScrollerChild container in this.children)
        {
          if (container.child.get_name () == data)
            {
              container.state = ScrollerChildState.HIDDEN;
            }
        }
      var drag_controller = Drag.Controller.get_default ();
      drag_controller.drag_motion.connect (this.on_unity_drag_motion);
      drag_controller.drag_drop.connect (this.on_unity_drag_drop);
    }

    private void on_unity_drag_motion (Drag.Model model, float x, float y)
    {
      //find child
      string data = model.get_drag_data ();
      // check to see if the data matches any of our children
      ScrollerChild? retcont = null;
      foreach (ScrollerChild container in this.children)
        {
          if (container.child.get_name () == data)
            {
              retcont = container;
            }
        }

      if (retcont == null) return;
      if (x > this.get_width () + this.DRAG_SAFE_ZONE)
        {
          if (retcont.state != ScrollerChildState.REMOVED) this.queue_relayout ();
          retcont.state = ScrollerChildState.REMOVED;
        }
      else
        {
          if (retcont.state != ScrollerChildState.HIDDEN) this.queue_relayout ();
          retcont.state = ScrollerChildState.HIDDEN;
        }

      ScrollerChild child_under = get_child_at_screen_positition (y);
      if (child_under != null && child_under != retcont)
        {
          // find the child before this one
          ScrollerChild previous_child = this.children.first ();
          foreach (ScrollerChild container in this.children)
            {
              if (container == child_under) break;
              previous_child = container;
            }
          if (previous_child == child_under)
            {
              // we have the first item, so just -1 to priority
              (retcont.child as LauncherView).model.priority = (child_under.child as LauncherView).model.priority - 1.0f;
            }
          else
            {
              // set a new priority half way between the two children
              float prev_priority = (previous_child.child as LauncherView).model.priority;
              float next_priority = (child_under.child as LauncherView).model.priority;
              float priority = next_priority - ((next_priority - prev_priority) / 2.0f);
              (retcont.child as LauncherView).model.priority = priority;
            }
          this.order_changed = true;
          this.queue_relayout ();
        }
    }

    private void on_unity_drag_drop (Drag.Model model, float x, float y)
    {
      string data = model.get_drag_data ();
      // check to see if the data matches any of our children
      ScrollerChild? retcont = null;
      foreach (ScrollerChild container in this.children)
        {
          if (container.child.get_name () == data)
            {
              retcont = container;
            }
        }

      if (x > this.get_width ())
        {
          // we removed it so its not sticky anymore
          (retcont.child as LauncherView).model.is_sticky = false;
          (retcont.child as LauncherView).request_remove ();
        }
      else
        {
          retcont.state = ScrollerChildState.NORMAL;
          // we moved an item so its automatically pinned
          (retcont.child as LauncherView).model.is_sticky = true;
        }

      var drag_controller = Drag.Controller.get_default ();
      drag_controller.drag_motion.disconnect (this.on_unity_drag_motion);
      drag_controller.drag_drop.disconnect (this.on_unity_drag_drop);

      // we want to go through our lsit of children and normalize our
      // priorities else they will gravitate to small values
      // sticky always first
      float priority = 1.0001f;
      foreach (ScrollerChild container in this.children)
        {
          LauncherView child = container.child as LauncherView;
          if (child.model.is_sticky)
            {
              child.model.priority = priority;
              priority += 1.0f;
            }
        }
      // now do non sticky
      foreach (ScrollerChild container in this.children)
        {
          LauncherView child = container.child as LauncherView;
          if (!child.model.is_sticky)
            {
              child.model.priority = priority;
              priority += 1.0f;
            }
        }
      this.queue_relayout ();
      this.order_changed = true;
    }

    private ScrollerChild? get_child_at_screen_positition (float pos)
    {
      /* given a position in screenspace co-ords this attempts to return a
       * scroller child object
       */
      float x; float y;
      this.get_transformed_position (out x, out y);
      ScrollerChild? retcont = null;
      foreach (ScrollerChild container in this.children)
      {
        // the last container we find is the one we want... i think
        if (container.box.y1 + y < pos + this.padding.top)
          {
            retcont = container;
          }
      }
      return retcont;
    }

    private void load_textures ()
    {
      this.bgtex = new ThemeImage ("launcher_background_middle");
      this.top_shadow = new ThemeImage ("overflow_top");
      this.bottom_fade = new ThemeImage ("overflow_bottom");

      this.bgtex.set_repeat (false, true);
      this.top_shadow.set_repeat (true, false);
      this.bottom_fade.set_repeat (true, false);

      this.bgtex.set_parent (this);
      this.top_shadow.set_parent (this);
      this.bottom_fade.set_parent (this);

    }

    private void on_request_attention (LauncherView view)
    {
      /* when the app requests attention we need to scroll to it */
      // check to make sure we can actually scroll
      if (this.total_child_height > this.hot_height)
        return;

      // find the app in our list
      Clutter.Actor actor = view as Clutter.Actor;
      foreach (ScrollerChild container in this.children)
      {
        if (container.child == actor)
        {
          float scroll_px;
          scroll_px = container.box.y2 - hot_height - hot_start;

          if (scroll_anim is Clutter.Animation)
            scroll_anim.completed ();

          scroll_anim = animate (Clutter.AnimationMode.EASE_OUT_QUAD,
                                 200, "drag_pos",
                                 scroll_px);
          return;
        }
      }
    }

    private float settle_position;
    private const float BOUNCE_STRENGTH = 0.3f;
    private void on_scroller_frame (Clutter.Timeline timeline, int msecs)
    {
      // animate the scroller depeding on its phase
      uint delta = timeline.get_delta ();
      delta += this.stored_delta;
      if (delta <= 16)
        {
          this.stored_delta = delta;
          return;
        }

      while (delta > 16)
        {
          delta -= 16;
          switch (this.phase) {
            case (ScrollerPhase.SETTLING):
              this.do_anim_settle (timeline, msecs);
              break;
            case (ScrollerPhase.FLUNG):
              this.do_anim_fling (timeline, msecs);
              break;
            case (ScrollerPhase.BOUNCE):
              this.do_anim_bounce (timeline, msecs);
              break;
            default:
              break;
          }
        }

      this.stored_delta = delta;
    }

    private void do_anim_settle (Clutter.Timeline timeline, int msecs)
    {
      var distance = this.settle_position - this.drag_pos;
      this.drag_pos += distance * 0.2f;
      if (Math.fabs (distance) < 1 )
        {
          timeline.stop ();
        }

    }

    private void do_anim_fling (Clutter.Timeline timeline, int msecs)
    {
      this.fling_velocity *= this.friction;
      this.drag_pos -= this.fling_velocity;

      if(this.fling_velocity <= -1.0 && this.drag_pos > this.total_child_height - height ||
         this.fling_velocity >= 1.0 && this.drag_pos < 0)
        {
          this.phase = ScrollerPhase.BOUNCE;
        }

      if (Math.fabs (this.fling_velocity) < 1.0 &&
          (this.drag_pos < 0 || this.drag_pos > this.total_child_height - this.height))
        {
          this.settle_position = get_aligned_settle_position ();
          this.phase = ScrollerPhase.SETTLING;
          return;
        }

      if (Math.fabs (this.fling_velocity) < 1.0)
        {
          timeline.stop ();
        }
    }

    private void do_anim_bounce (Clutter.Timeline timeline, int msecs)
    {
      this.fling_velocity *= 0.5f;
      this.drag_pos += this.fling_velocity;
      this.settle_position = get_aligned_settle_position ();
      this.phase = ScrollerPhase.SETTLING;
    }

    private uint stored_delta = 0;

    private void calculate_anchor (out int iterations, out float position)
    {
      float d = 0.0f;
      float v = fling_velocity;
      iterations = 0;
      while (v >= 1.0f || v <= -1.0)
        {
          iterations += 1;
          v *= this.friction;
          d -= v;
        }
      position = (float)this.drag_pos + d;
      return;
    }

    private float get_aligned_settle_position ()
    {
      /* attempts to integligently find hte correct settle position */
      // always align to the top item
      // always want a full scroller full of items

      if (this.drag_pos < 0)
        {
          // we always position on the first child
          ScrollerChild container = this.children[0];
          Clutter.ActorBox box = container.box;
          return box.y1 + this.drag_pos - this.padding.top;
        }

      if (this.drag_pos > this.total_child_height - height)
        {
          ScrollerChild last_container = this.children.get (this.children.size -1);
          foreach (ScrollerChild container in this.children)
            {
              Clutter.ActorBox box = container.box;
              if (box.y1 == 0.0 && box.y2 == 0.0) continue;
              if (box.y1 - box.get_height () > last_container.box.y1 - this.height)
                {
                  return box.y1 + this.drag_pos - this.padding.top;
                }
            }
        }

      else
        {
          for (var i = this.children.size - 1; i >= 0; i--)
            {
              ScrollerChild container = this.children.get(i);
              Clutter.ActorBox box = container.box;
              if (box.y1 == 0.0 && box.y2 == 0.0) continue;
              if (box.y1 < hot_start)
              {
                /* we have a container lower than the "hotarea" */
                float scroll_px = box.y1 + this.drag_pos - hot_start;
                return (float)scroll_px - this.padding.top;
              }
            }
        }

      return - this.padding.top;
    }

    private bool on_button_click_event (Clutter.Event event)
    {
      if (event.button.button != 1)
        {
           return false;
        }

      if (this.get_animation() is Clutter.Animation)
        {
          this.get_animation().completed ();
        }
      this.button_down = true;
      Clutter.ButtonEvent buttonevent = event.button;
      this.previous_y = buttonevent.y;
      this.last_drag_pos = (float)this.drag_pos;
      this.click_start_pos = buttonevent.y;
      return true;
    }

    private bool on_button_release_event (Clutter.Event event)
    {
      if (event.button.button != 1)
        {
           return false;
        }
      this.button_down = false;

      if (this.is_dragging)
        {
          this.is_dragging = false;
          Clutter.ungrab_pointer ();
        }
      var release_event = event.button;
      int iters = 0;
      float position = 0.0f;

      calculate_anchor (out iters, out position);
      this.settle_position = position;

      if (this.fling_velocity > 0.0 && this.fling_velocity < 1.0)
        {
          this.fling_velocity = 2.0f;
        }
      if ((release_event.time - this.last_mouse_event_time) > 120)
        {
          this.phase = ScrollerPhase.SETTLING;
          this.settle_position = get_aligned_settle_position ();
          this.fling_timeline.start ();
        }

      else {
          this.phase = ScrollerPhase.FLUNG;
          this.fling_timeline.start ();
        }

      return true;
    }

    private bool on_motion_event (Clutter.Event event)
    {
      var drag_controller = Drag.Controller.get_default ();
      if (drag_controller.is_dragging)
      {
        return false;
      }
      if (this.button_down && this.is_dragging == false)
        {
          var diff = event.motion.y - this.click_start_pos;
          if (diff > this.drag_sensitivity || -diff > this.drag_sensitivity)
            {
              this.is_dragging = true;
            }
        }

      if (this.button_down && this.is_dragging)
        {
          Clutter.grab_pointer (this);

          /* Disable any animations on the children */
          Clutter.Event e = { 0 };
          e.type = Clutter.EventType.LEAVE;
          e.crossing.time = event.motion.time;
          e.crossing.flags = event.motion.flags;
          e.crossing.stage = event.motion.stage;
          e.crossing.x = event.motion.x;
          e.crossing.y = event.motion.y;

          foreach (ScrollerChild container in this.children)
            {
              Clutter.Actor child = container.child;

              if (child is Clutter.Actor)
                {
                  e.crossing.source = child;
                  child.do_event (e, false);
                }
            }
        }
      if (this.is_dragging == false)
        {
          return true;
        }

      Clutter.MotionEvent motionevent = event.motion;
      float vel_y = 0.0f;

      if (previous_y <= -1000000000.0)
      {
        vel_y = 0.0f;
      }
      else
      {
        vel_y = motionevent.y - previous_y;
      }

      // account for a drag on the velocity if scrolling out of the range
      // of the icons
      if (this.drag_pos < 0)
        {
          var distance = this.drag_pos;
          vel_y *= 1.0f - ((-distance / this.height) * 2.0f);
        }

      if (this.drag_pos > this.total_child_height - this.height)
        {
          var distance = this.drag_pos - (this.total_child_height - this.height);
          vel_y *= 1.0f - ((distance / this.height) * 2.0f);
        }

      uint delta = motionevent.time - this.last_mouse_event_time;
      this.last_mouse_event_time = motionevent.time;
      if (delta > 200)
        {
          delta = 1000/60;
        }

      this.fling_delta = delta;
      previous_y = motionevent.y;
      this.drag_pos -= vel_y;
      this.fling_velocity = vel_y * (delta / (1000.0f/60.0f));

      return true;
    }

    private bool on_scroll_event (Clutter.Event event)
    {
      Clutter.ScrollEvent scrollevent = event.scroll;
      if (scrollevent.direction == Clutter.ScrollDirection.UP)
      {
        this.fling_velocity = 16.0f;
        this.fling_timeline.start ();
      }
      else if (scrollevent.direction == Clutter.ScrollDirection.DOWN)
      {
        this.fling_velocity = -16.0f;
        this.fling_timeline.start ();
      }
      return true;
    }

    private static int sort_by_priority (void *a, void *b)
    {
      LauncherView viewa = (a as ScrollerChild).child as LauncherView;
      LauncherView viewb = (b as ScrollerChild).child as LauncherView;
      if (viewa.model.priority < viewb.model.priority) return -1;
      if (viewa.model.priority > viewb.model.priority) return +1;
      return 0;
    }

    /*
     * Clutter methods
     */
    public override void get_preferred_width (float for_height,
                                     out float minimum_width,
                                     out float natural_width)
    {
      minimum_width = 0;
      natural_width = 0;

      // if we are vertical, just figure out the width of the widest
      // child
      if (orientation == Ctk.Orientation.VERTICAL)
      {
        float pmin_width = 0.0f;
        float pnat_width = 0.0f;

        foreach (ScrollerChild childcontainer in this.children)
        {
          Clutter.Actor child = childcontainer.child;
          float cmin_width = 0.0f;
          float cnat_width = 0.0f;

          child.get_preferred_width (for_height,
                                     out cmin_width,
                                     out cnat_width);

          pmin_width = pmin_width.max(pmin_width, cmin_width);
          pnat_width = pnat_width.max(pnat_width, cnat_width);

        }

        pmin_width += padding.left + padding.right;
        pnat_width += padding.left + padding.right;

        minimum_width = pmin_width;
        natural_width = pnat_width;

        return;
      }

      // we have no support for horizontal yet
      error ("no support for horizontal orientation yet");

    }

    public override void get_preferred_height (float for_width,
                                      out float minimum_height,
                                      out float natural_height)
    {
      minimum_height = 0.0f;
      natural_height = 0.0f;

      float cnat_height = 0.0f;
      float cmin_height = 0.0f;
      float all_child_height = 0.0f;

      if (orientation == Ctk.Orientation.VERTICAL)
      {
        foreach (ScrollerChild childcontainer in this.children)
        {
          Clutter.Actor child = childcontainer.child;
          cnat_height = 0.0f;
          cmin_height = 0.0f;
          child.get_preferred_height (for_width,
                                      out cmin_height,
                                      out cnat_height);

          all_child_height += cnat_height;
        }

        minimum_height = all_child_height + padding.top + padding.bottom;
        natural_height = all_child_height + padding.top + padding.bottom;
        return;
      }
      error ("Does not support Horizontal yet");
    }

    public override void allocate (Clutter.ActorBox box,
                                   Clutter.AllocationFlags flags)
    {
      base.allocate (box, flags);
      if (this.order_changed)
        {
          this.children.sort ((CompareFunc)(this.sort_by_priority));
          this.order_changed = false;
        }

      this.height = box.y2 - box.y1;
      this.total_child_height = 0.0f;
      float x = padding.left;
      float y = padding.top;
      float hot_negative = 0;
      float hot_positive = box.get_height ();
      this.hot_start = hot_negative;
      Clutter.ActorBox child_box;

      y = hot_start - (float)this.drag_pos;
      hot_height = hot_positive - hot_negative;

      /* itterate though each child and position correctly
       * also whist we are here we check to see if the child is outside of our
       * "hot" area, if so, mark it as unresponsive and fade it out
       */
      foreach (ScrollerChild childcontainer in this.children)
      {
        Clutter.Actor child = childcontainer.child;
        if (childcontainer.state == ScrollerChildState.REMOVED)
          {
            continue;
          }
        float min_height, natural_height;
        child.get_allocation_box (out child_box);
        child.get_preferred_height (box.get_width (), out min_height, out natural_height);
        if (orientation == Ctk.Orientation.VERTICAL)
        {

          child_box.x1 = x;
          child_box.x2 = x + child.width + padding.right;
          child_box.y1 = y + padding.top;
          child_box.y2 = y + min_height + padding.top;

          y += child_box.get_height () + spacing;
          this.total_child_height += child_box.get_height () + spacing;
        }
        else
        {
          error ("Does not support Horizontal yet");
        }

        childcontainer.box = child_box;
        child.allocate (child_box, flags);

        // if the child is outside our hot area, we hide it and set unreactive
        if ((child_box.y2 < hot_negative) || (child_box.y1 > hot_positive))
          {
            if (!childcontainer.is_hidden)
              {
                childcontainer.is_hidden = true;
                child.set_reactive (false);
              }
          }
        else
          {
            if (childcontainer.is_hidden)
              {
                childcontainer.is_hidden = false;
                child.set_reactive (true);
              }
          }
      }

      /* also allocate our background graphics */
      this.bgtex.get_allocation_box (out child_box);
      child_box.y1 = box.y1 - (float)drag_pos - box.get_height () * 2;
      child_box.y2 = box.y2 - (float)drag_pos + box.get_height () * 2;
      child_box.x1 = box.x1;
      child_box.x2 = box.x2;
      this.bgtex.allocate (child_box, flags);
      this.bgtex.set_clip (box.x1, drag_pos + box.get_height () * 2 - 1,
                           box.get_width (), box.get_height ());

      child_box.y1 = box.y1;
      child_box.y2 = box.y1 + 7.0f;

      this.top_shadow.allocate (child_box, flags);

      child_box.y1 = box.get_height() - 32;
      child_box.y2 = box.get_height();

      this.bottom_fade.allocate (child_box, flags);

    }

    public override void pick (Clutter.Color color)
    {
      base.pick (color);
      foreach (ScrollerChild childcontainer in this.children)
      {
        Clutter.Actor child = childcontainer.child;
        child.paint ();
      }
    }


    public override void paint ()
    {
      bgtex.paint ();

      foreach (ScrollerChild childcontainer in this.children)
      {
        Clutter.Actor child = childcontainer.child;
        if (childcontainer.state == ScrollerChildState.NORMAL)
          {
            if ((child.flags & Clutter.ActorFlags.VISIBLE) != 0)
              child.paint ();
          }
      }
      this.top_shadow.paint ();
      this.bottom_fade.paint ();
    }


    public void add (Clutter.Actor actor)
    {
      this.add_actor (actor);
    }

    public void add_actor (Clutter.Actor actor)
      requires (this.get_parent () != null)
    {
      var container = new ScrollerChild ();
      container.child = actor;
      container.state = ScrollerChildState.NORMAL;
      this.children.add (container);
      actor.set_parent (this);

      /* if we have an LauncherView we need to tie it to our attention
       * grabber
       */
      if (actor is LauncherView)
      {
        LauncherView view = actor as LauncherView;
        view.request_attention.connect (on_request_attention);
      }

      /* set a clip on the actor */
      actor.set_clip (0, -200, 58, 400);

      this.queue_relayout ();
      this.actor_added (actor);
    }

    public void remove (Clutter.Actor actor)
    {
      this.remove_actor (actor);
    }

    public void remove_actor (Clutter.Actor actor)
    {
      ScrollerChild found_container = null;
      foreach (ScrollerChild container in this.children) {
        if (container.child == actor)
        {
          found_container = container;
          break;
        }
      }
      if (found_container is ScrollerChild)
      {
        found_container.child = null;
        this.children.remove (found_container);
        actor.unparent ();

        this.queue_relayout ();
        this.actor_removed (actor);
        actor.remove_clip ();
      }
    }

    public void @foreach (Clutter.Callback callback, void* userdata)
    {
      foreach (ScrollerChild childcontainer in this.children)
      {
        Clutter.Actor child = childcontainer.child;
        callback (child, null);
      }
    }

    public void foreach_with_internals (Clutter.Callback callback,
                                        void* userdata)
    {
      callback (this.bgtex, null);
      callback (this.top_shadow, null);
      callback (this.bottom_fade, null);
      foreach (ScrollerChild childcontainer in this.children)
      {
        Clutter.Actor child = childcontainer.child;
        callback (child, null);
      }
    }


    /* empty interface methods */
    public void create_child_meta (Clutter.Actor actor)
    {
    }

    public void destroy_child_meta (Clutter.Actor actor)
    {
    }

    public new void lower (Clutter.Actor actor, Clutter.Actor sibling)
    {
    }

    public new void raise (Clutter.Actor actor, Clutter.Actor sibling)
    {
    }
    /* has to return something, implimentation does not have ? so we can't
     * return null without a warning =\
     */
    public Clutter.ChildMeta? get_child_meta (Clutter.Actor actor)
    {
      return null;
    }

    public void sort_depth_order ()
    {
    }
  }
}
