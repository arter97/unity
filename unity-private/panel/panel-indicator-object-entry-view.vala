/*
 * Copyright (C) 2010 Canonical Ltd
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
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 *              Jay Taoko <jay.taoko@canonical.com>
 */

namespace Unity.Panel.Indicators
{
  public class IndicatorObjectEntryView : Ctk.Box
  {
    public unowned Indicator.ObjectEntry entry { get; construct; }
    public signal void menu_moved (Gtk.MenuDirectionType type);

    private Clutter.CairoTexture bg;
    public  Ctk.Image     image;
    public  Ctk.Text      text;
    private bool          menu_is_open = false;

    private uint32 click_time;
    private float last_found_entry_x = 0.0f;

    private float last_width = 0;
    private float last_height = 0;

    public IndicatorObjectEntryView (Indicator.ObjectEntry _entry)
    {
      Object (entry:_entry,
              orientation: Ctk.Orientation.HORIZONTAL,
              spacing:3,
              homogeneous:false,
              reactive:true);
    }

    construct
    {
      /* Figure out if you need a label, text or both, create the ctk
       * representations.
       * Hook up the appropriate signals
       */
      padding = { 0, 4.0f, 0, 4.0f };

      button_press_event.connect (on_button_press_event);

      motion_event.connect (on_motion_event);
      scroll_event.connect (on_scroll_event);

      bg = new Clutter.CairoTexture (10, 10);
      bg.set_parent (this);
      bg.opacity = 0;
      bg.show ();

      if (entry.image is Gtk.Image)
        {
          image = new Ctk.Image (22);
          add_actor (image);
          image.show ();

          if (entry.image.icon_name != null)
            {
              image.stock_id = entry.image.icon_name;
            }

          if (entry.image.pixbuf != null)
            {
              image.pixbuf = entry.image.pixbuf;
              image.size = entry.image.pixbuf.width;
            }
        }

      entry.image.notify["pixbuf"].connect (() =>
        {
          if (entry.image.pixbuf is Gdk.Pixbuf)
            {
              image.pixbuf = entry.image.pixbuf;
              image.size = entry.image.pixbuf.width;
            }
        });

      entry.image.notify["icon-name"].connect (() =>
        {
          if (entry.image.icon_name != null)
            {
              image.stock_id = entry.image.icon_name;
              image.size = 22;
            }
        });

      unowned Gtk.IconTheme theme = Gtk.IconTheme.get_default ();
      theme.changed.connect (() =>
        {
          if (entry.image.icon_name != null)
            image.stock_id = entry.image.icon_name;
        });

      if (entry.label is Gtk.Label)
        {
          text = new Ctk.Text ("");
          text.color = { 233, 216, 200, 255 };
          add_actor (text);
          text.show ();

          text.text = entry.label.label;

          entry.label.notify["label"].connect (() =>
            {
              text.text = entry.label.label;
            });
        }
    }

    private void position_menu (Gtk.Menu menu,
                                out int  x,
                                out int  y,
                                out bool push_in)
    {
      y = (int)height;
      x = (int)last_found_entry_x;
    }

    public void show_menu ()
    {
      if (entry.menu is Gtk.Menu)
        {
          last_found_entry_x = x + get_parent ().x + get_parent ().get_parent ().x;
          MenuManager.get_default ().register_visible_menu (entry.menu);
          entry.menu.popup (null,
                            null,
                            position_menu,
                            1,
                            Clutter.get_current_event_time ());
          click_time = Clutter.get_current_event_time ();
          menu_shown ();
        }
    }

    private bool on_scroll_event (Clutter.Event e)
    {
      Clutter.ScrollEvent event = e.scroll;

      IndicatorObjectView parent = get_parent () as IndicatorObjectView;
      unowned Indicator.Object object = parent.indicator_object;

      Signal.emit_by_name (object, "scroll", 1, event.direction);

      return true;
    }

    public bool on_button_press_event (Clutter.Event e)
    {
      if (entry.menu is Gtk.Menu)
        {
          if(menu_is_open)
            {
              entry.menu.popdown();
              menu_is_open = false;
              return true;
            }
          else
            {
              last_found_entry_x = x + get_parent ().x + get_parent ().get_parent ().x;
              MenuManager.get_default ().register_visible_menu (entry.menu);
              entry.menu.popup (null,
                                    null,
                                    position_menu,
                                    e.button.button,
                                    e.button.time);
              click_time = Clutter.get_current_event_time ();
              menu_is_open = true;
              menu_shown ();
            }
        }
     return true;
    }

    public bool on_motion_event (Clutter.Event e)
    {
      if ((entry.menu is Gtk.Menu) && MenuManager.get_default ().menu_is_open ())
        {
          show_menu ();
          return true;
        }
      return false;
    }

    public void menu_shown()
    {
      if (entry.menu is Gtk.Menu)
        {
          /* Show the menu and connect various signal to update the menu if
           * necessary.
           */
          entry.menu.move_current.connect (menu_key_moved);
          entry.menu.notify["visible"].connect (menu_vis_changed);
          bg.animate (Clutter.AnimationMode.EASE_OUT_QUAD, 200, "opacity", 255);
        }
    }

    public void menu_vis_changed ()
    {
      bool vis = (entry.menu.get_flags () & Gtk.WidgetFlags.VISIBLE) != 0;
      if (vis == false)
        {
          /* The menu isn't visible anymore. Disconnect some signals. */
          bg.animate (Clutter.AnimationMode.EASE_OUT_QUAD, 200, "opacity", 0);
          entry.menu.move_current.disconnect (menu_key_moved);
          entry.menu.notify["visible"].disconnect (menu_vis_changed);
          menu_is_open = false;
        }
    }

    public void menu_key_moved (Gtk.MenuDirectionType type)
    {
      if (type != Gtk.MenuDirectionType.PARENT &&
          type != Gtk.MenuDirectionType.CHILD)
        return;

      menu_moved (type);
    }

    /*
     * CLUTTER OVERRIDES
     */
    private override void allocate (Clutter.ActorBox        box,
                                    Clutter.AllocationFlags flags)
    {
      float width;
      float height;

      base.allocate (box, flags);

      width = Math.floorf (box.x2 - box.x1);
      height = Math.floorf (box.y2 - box.y1);

      Clutter.ActorBox child_box = { 0 };
      child_box.x1 = 0;
      child_box.x2 = width;
      child_box.y1 = 0;
      child_box.y2 = height;

      if (width != last_width || height != last_height)
        {
          last_width = width;
          last_height = height;
          Idle.add (update_bg);
        }

      bg.allocate (child_box, flags);
    }

    private override void paint ()
    {
      bg.paint ();
      base.paint ();
    }

    private override void map ()
    {
      base.map ();
      bg.map ();
    }

    private override void unmap ()
    {
      base.unmap ();
      bg.unmap ();
    }

    private bool update_bg ()
    {
      Cairo.Context cr;
      int width = (int)last_width;
      int height = (int)last_height;

      bg.set_surface_size (width, height);

      cr = bg.create ();

      cr.set_operator (Cairo.Operator.CLEAR);
      cr.paint ();

      cr.set_operator (Cairo.Operator.OVER);

      cr.set_line_width (1.0);

      cr.set_source_rgba (1.0, 1.0, 1.0, 0.2);

      cr.move_to (1, height);

      cr.line_to (1, 7);

      cr.curve_to (1, 2,
                   1, 2,
                   10, 2);

      cr.line_to (width-10, 2);

      cr.curve_to (width, 2,
                   width, 2,
                   width, 7);

      cr.line_to (width, height);

      cr.line_to (1, height);

      var pat = new Cairo.Pattern.linear (1, 0, 1, height);
      pat.add_color_stop_rgba (0.0, 0.8509f, 0.8196f, 0.7294f, 1.0f);
      pat.add_color_stop_rgba (1.0, 0.7019f, 0.6509f, 0.5137f, 1.0f);
      cr.set_source (pat);
      cr.fill ();

      return false;
    }
  }
}
