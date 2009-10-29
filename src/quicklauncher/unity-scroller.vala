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

namespace Unity.Widgets
{
  public class Scroller : Ctk.Actor, Clutter.Container
  {
    
    private int _spacing;
    public int spacing {
      get { return _spacing; }
      set { queue_relayout (); _spacing = value; }
    }
    private Ctk.Orientation orientation;

    private Gee.ArrayList<Clutter.Actor> children;

    public Scroller (Ctk.Orientation orientation, int spacing) 
    {
      this.orientation = orientation;
      this.spacing = spacing;
    }

    construct {
      children = new Gee.ArrayList<Clutter.Actor> ();
      set_reactive (true);
    }

    /* Clutter methods */
    public override void get_preferred_width (float for_height, 
                                     out float minimum_width, 
                                     out float natural_width)
    {

      // if we are vertical, just figure out the width of the widest
      // child
      if (orientation == Ctk.Orientation.VERTICAL)
      {
        float pmin_width = 0.0f;
        float pnat_width = 0.0f;

        foreach (Clutter.Actor child in this.children)
        {
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

        debug ("min/nat width: %f - %f", minimum_width, natural_width);

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

      if (orientation == Ctk.Orientation.VERTICAL) 
      {
        
        float all_child_height = 0.0f;
        float max_child_height = 0.0f;

        foreach (Clutter.Actor child in this.children)
        {
          float cnat_height = 0.0f;
          float cmin_height = 0.0f;
          child.get_preferred_height (for_width, 
                                      out cmin_height, 
                                      out cnat_height);

          debug ("cnat_height: %f", cnat_height);

          //all_child_height += cnat_height + spacing;
          //all_child_height += 42 + spacing;
          max_child_height = max_child_height.max (max_child_height, 
                                                   cnat_height);
          
        }

        debug ("all child height; %f", all_child_height);

        minimum_height = all_child_height + padding.top + padding.bottom;
        natural_height = all_child_height + padding.top + padding.bottom;
        
        debug ("min/nat height: %f - %f", minimum_height, natural_height);

        return;
      }

      error ("Does not support Horizontal yet");

    }

    public override void allocate (Clutter.ActorBox box, 
                                   Clutter.AllocationFlags flags)
    {

      float width;
      float height;

      width = (box.x2 - box.x1) - padding.left - padding.right;
      height = (box.y2 - box.y1) - padding.top - padding.bottom;

      foreach (Clutter.Actor child in this.children)
      {
        float min_width = 0.0f;
        float min_height = 0.0f;
        float nat_width = 0.0f;
        float nat_height = 0.0f;

        child.get_preferred_width(box.y2 - box.y1, 
                                  out min_width, out nat_width);

        child.get_preferred_height(box.x2 - box.x1,
                                   out min_height, out nat_height);

        if (orientation == Ctk.Orientation.VERTICAL)
        {
          child.width = min_width;
          child.height = height;
        }
        else 
        {
          child.width = width;
          child.height = min_height;
        }

      }

      // position the actors

      float x = padding.left;
      float y = padding.top;

      foreach (Clutter.Actor child in this.children)
      {
        float child_width;
        float child_height;
        Clutter.ActorBox child_box;
        child.get_allocation_box (out child_box);
        
        child_width = child.width;
        child_height = child.height;

        if (orientation == Ctk.Orientation.VERTICAL)
        {
          child_box.x1 = (float)Math.floor (x);
          child_box.x2 = (float)Math.floor (x + child_width);
          child_box.y1 = (float)Math.floor (y);
          child_box.y2 = (float)Math.floor (y + child_height);
          
          y += child_height + spacing;
        }
        else 
        {
          error ("Does not support Horizontal yet");
        }

        child.allocate (child_box, flags);
      }
    }

    public override void pick (Clutter.Color color) 
    {
      /* FIXME! - vala wants to use clutter_actor_get_visible but clutter
       * does not expose that method.. not sure how to fix that yet
       */
      base.pick (color);

      bool is_visible = false;
      uint32 vis = flags & Clutter.ActorFlags.VISIBLE;
      if (vis != 0)
        is_visible = true;

      if (is_visible)
        paint ();
    }
    
    public override void paint ()
    {
      base.paint ();
      
      foreach (Clutter.Actor child in children) 
      {
        if ((child.flags & Clutter.ActorFlags.VISIBLE) != 0)
          child.paint ();
      }

    }
    

    public void add (Clutter.Actor actor)
    {
    }

    public void add_actor (Clutter.Actor actor)
    //  requires (!(actor in this.children))
      requires (this.get_parent () != null)
    {
      this.children.add (actor);
      actor.set_parent (this);

      this.queue_relayout ();
      this.actor_added (actor);
    }

    public void remove (Clutter.Actor actor)
    {

    }
    public void remove_actor (Clutter.Actor actor)
    //  requires (actor in this.children)
    {
      this.children.remove (actor);
      actor.unparent ();
      
      this.queue_relayout ();
      this.actor_removed (actor);
    }

    public void @foreach (Clutter.Callback callback)
    {
      foreach (Clutter.Actor child in this.children)
      {
        
        callback (child, null);
      }
    }
    
    /* empty interface methods */
    public void lower (Clutter.Actor actor, Clutter.Actor sibling)
    {
    }

    public void raise (Clutter.Actor actor, Clutter.Actor sibling)
    {
    }

    public void create_child_meta (Clutter.Actor actor) 
    {
    }

    public void destroy_child_meta (Clutter.Actor actor)
    {
    }

    public Clutter.ChildMeta get_child_meta (Clutter.Actor actor)
    {
      return null;
    }


    public void foreach_with_internals (Clutter.Callback callback)
    {
    }

    public void sort_depth_order ()
    {
    }
  } 
}
