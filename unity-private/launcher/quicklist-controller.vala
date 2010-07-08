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
namespace Unity.Launcher
{
  public static QuicklistController? ql_controller_singleton;

  public enum QuicklistControllerState {
    LABEL,
    MENU,
    CLOSED
  }

  public abstract class QuicklistController : Object
  {
    protected Ctk.Menu? menu;
    public ScrollerChildController attached_controller {get; construct;}
    private QuicklistControllerState _state;
    public QuicklistControllerState state {
      get { return _state; }
      set
        {
          if (value == QuicklistControllerState.LABEL ||
              value == QuicklistControllerState.MENU)
            {
              // check our singleton for a previous menu
              if (ql_controller_singleton != this && ql_controller_singleton != null)
                {
                  var tmp_qlc = ql_controller_singleton; //ref the controller
                  tmp_qlc.state = QuicklistControllerState.CLOSED;
                  if (tmp_qlc.get_view () != null)
                    warning ("old menu not destroyed when opening new menu");
                }

              ql_controller_singleton = this;
            }

          if (value == QuicklistControllerState.CLOSED)
            {
              if (menu is Ctk.Menu)
                {
                  menu.destroy ();
                  menu = null;

                }
              ql_controller_singleton = null;
            }

          _state = value;
        }
    }

    public abstract Ctk.Menu? get_view ();

    public static unowned QuicklistController get_current_menu ()
    {
      // returns the current controller, thou does not own this!
      return ql_controller_singleton;
    }


    public static bool is_menu_open ()
    {
      // returns true if a menu is open
      if (ql_controller_singleton is QuicklistController)
        return ql_controller_singleton.state == QuicklistControllerState.MENU;

      return false;
    }

    public static bool do_menus_match (QuicklistController menu)
    {
      // returns true if the given menu matches ql_controller_singleton
      return menu == ql_controller_singleton;
    }
  }


  public class ApplicationQuicklistController : QuicklistController
  {
    public ApplicationQuicklistController (ApplicationController scroller_child)
    {
      Object (attached_controller: scroller_child);
    }

    construct
    {
      Unity.Testing.ObjectRegistry.get_default ().register ("QuicklistController",
                                                            this);

      new_menu ();
      notify["state"].connect (on_state_change);
      state = QuicklistControllerState.LABEL;
    }

    private void new_menu ()
    {
      menu = new QuicklistMenu () as Ctk.Menu;
      menu.destroy.connect (() => {
        Unity.global_shell.remove_fullscreen_request (this);
      });
      menu.set_swallow_clicks (Unity.global_shell.menus_swallow_events);
      menu.set_detect_clicks (false);
      menu.attach_to_actor (attached_controller.child as Ctk.Actor);
      ((attached_controller).child.get_stage () as Clutter.Stage).add_actor (menu);

      float x;
      float y;
      menu.get_position (out x, out y);
      menu.set_position (x - (float) 22.0f, y - 1.0f);
    }

    private void on_state_change ()
    {
      if (state == QuicklistControllerState.CLOSED) return;
      if (menu == null)
        {
          new_menu ();
          warning ("state change called on menu when menu does not exist");
        }
      if (state == QuicklistControllerState.LABEL)
        {
          // just build a menu with a label for the name
          menu.remove_all ();
          string label = attached_controller.name;

          var menuitem = new QuicklistMenuItem (label);
          menuitem.activated.connect (() => {
            state = QuicklistControllerState.CLOSED;
          });

          menu.append (menuitem, true);
        }
      else if (state == QuicklistControllerState.MENU)
        {

          // grab the top menu
          var top_menu = attached_controller.get_menu_actions ();
          if (top_menu is Dbusmenu.Menuitem)
            if (top_menu.get_root ())
              {
                // add a seperator for funsies
                var separator = new Unity.Launcher.QuicklistMenuSeperator ();
                menu.prepend (separator, false);

                //returns a correct root menu
                unowned GLib.List<Dbusmenu.Menuitem> menu_items = top_menu.get_children ();
                foreach (Dbusmenu.Menuitem menuitem in menu_items)
                  {
                    var view_menuitem = menu_item_from_dbusmenuitem (menuitem);
                    menu.prepend (view_menuitem, false);
                  }
              }
            else
              {
                warning ("menu given not a root item");
              }

          // grab the bottom menu
          var bottom_menu = attached_controller.get_menu_navigation ();
          if (bottom_menu is Dbusmenu.Menuitem)
            if (bottom_menu.get_root ())
              {
                // add a seperator for funsies
                var separator = new Unity.Launcher.QuicklistMenuSeperator ();
                menu.append (separator, false);
                //returns a correct root menu
                unowned GLib.List<Dbusmenu.Menuitem> menu_items = bottom_menu.get_children ();
                foreach (Dbusmenu.Menuitem menuitem in menu_items)
                  {
                    var view_menuitem = menu_item_from_dbusmenuitem (menuitem);
                    menu.append (view_menuitem, false);
                  }
              }
            else
              {
                warning ("menu given not a root item");
              }

          float x;
          float y;
          menu.get_position (out x, out y);
          if (x > 60-22)
            menu.set_position (x - (float) 22.0f, y - 1.0f);
        }
    }

    public override Ctk.Menu? get_view ()
    {
      return menu;
    }

    private Ctk.MenuItem menu_item_from_dbusmenuitem (Dbusmenu.Menuitem dbusmenuitem)
    {
      string label = "UNDEFINED";
      label = dbusmenuitem.property_get (Dbusmenu.MENUITEM_PROP_LABEL);

      var menuitem = new Ctk.MenuItem.with_label (label);
      //var menuitem = new QuicklistMenuItem (label);
      menuitem.reactive = true;
      menuitem.activated.connect (() => {
        dbusmenuitem.item_activated (Clutter.get_current_event_time ());
      });

      menuitem.activated.connect (() => {
        Idle.add (() => {
          state = QuicklistControllerState.CLOSED;
          return false;
        });
      });

      // add more menu item types here (check, radio, image) as views are made
      // right now we can just represent all menuitems as labels

      return menuitem as Ctk.MenuItem;
    }

  }

/*


  public class QuicklistController : Object
  {

    public static unowned QuicklistController get_default ()
    {
      if (Unity.Launcher.ql_controler_singleton == null) {
        Unity.Launcher.ql_controler_singleton= new QuicklistController ();
      }
      return Unity.Launcher.ql_controler_singleton;
    }

    public weak Ctk.Menu menu;
    public bool is_in_label = false;
    public bool is_in_menu = false;

    public signal void menu_state_changed (bool open);

    public QuicklistController ()
    {
      Unity.Testing.ObjectRegistry.get_default ().register ("QuicklistController",
                                                            this);
    }

    construct
    {
      var drag_controller = Drag.Controller.get_default ();
      drag_controller.drag_start.connect (this.on_unity_drag_start);
    }

    private void on_unity_drag_start (Drag.Model model)
    {
      if (this.menu_is_open ())
        this.menu.destroy ();
    }

    public void show_label (string label, Ctk.Actor attached_widget)
    {
      if (this.menu_is_open ())
        this.menu.destroy ();

      var menu = new QuicklistMenu () as Ctk.Menu;
      menu.destroy.connect (() => {
        if (is_in_menu)
          menu_state_changed (false);
      });
      this.menu = menu;
      this.menu.destroy.connect (() => {
        Unity.global_shell.remove_fullscreen_request (this);
      });
      this.menu.set_swallow_clicks (Unity.global_shell.menus_swallow_events);
      this.menu.set_detect_clicks (false);

      //make label
      var menuitem = new QuicklistMenuItem (label);
      menuitem.activated.connect (this.close_menu);
      menuitem.reactive = true;
      this.menu.append (menuitem, true);
      this.menu.attach_to_actor (attached_widget);
      (attached_widget.get_stage () as Clutter.Stage).add_actor (this.menu);

      float x;
      float y;
      this.menu.get_position (out x, out y);
      this.menu.set_position (x - (float) 22.0f, y - 1.0f);
      this.is_in_label = true;
    }

    private Gee.ArrayList<ShortcutItem> prefix_cache;
    private Gee.ArrayList<ShortcutItem> affix_cache;

    public void show_menu (Gee.ArrayList<ShortcutItem> prefix_shortcuts,
                           Gee.ArrayList<ShortcutItem> affix_shortcuts,
                           bool hide_on_leave)
    {
      this.prefix_cache = prefix_shortcuts;
      this.affix_cache = affix_shortcuts;

      this.is_in_label = false;
      Unity.global_shell.add_fullscreen_request (this);
      this.menu.close_on_leave = hide_on_leave;
      foreach (ShortcutItem shortcut in prefix_shortcuts)
        {
          var label = shortcut.get_name ();
          var menuitem = new QuicklistMenuItem (label);
          this.menu.prepend (menuitem, false);
          menuitem.activated.connect (shortcut.activated);
          menuitem.activated.connect (this.close_menu);
        }

      // Only add the separator if there are shortcuts beneath
      if (affix_shortcuts.size > 0)
        {
          Unity.Launcher.QuicklistMenuSeperator separator = new Unity.Launcher.QuicklistMenuSeperator ();
          this.menu.append (separator, false);
        }

      foreach (ShortcutItem shortcut in affix_shortcuts)
        {
          var label = shortcut.get_name ();
          var menuitem = new QuicklistMenuItem (label);
          this.menu.append (menuitem, false);
          menuitem.activated.connect (shortcut.activated);
          menuitem.activated.connect (this.close_menu);
        }
      this.menu.set_detect_clicks (true);
      menu_state_changed (true);
    }

    public void close_menu ()
    {
      if (this.menu is Ctk.Menu)
        {
          this.menu.destroy ();
        }
      this.is_in_label = false;
      this.is_in_menu = false;
    }

    public bool menu_is_open ()
    {
      return this.menu is Ctk.Menu;
    }

    public Ctk.Actor get_attached_actor ()
    {
      return this.menu.get_attached_actor ();
    }
  }
*/
}
