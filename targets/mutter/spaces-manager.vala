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
 * Authored by Jason Smith <jason.smith@canonical.com>
 *
 */
 
using Unity.Launcher;
 
namespace Unity {
  
  public class SpacesButtonController : ScrollerChildController
  {
    SpacesManager parent { get; set; }
  
    public SpacesButtonController (SpacesManager _parent, ScrollerChild _child)
    {
      Object (child: _child);
      this.parent = _parent;

      name = "Workspace Overview";
      load_icon_from_icon_name ("workspace-switcher");
    }
  
    construct
    {
      child.group_type = ScrollerChild.GroupType.PLACE;
    }
    
    public override void activate ()
    {
      if (parent.showing)
        parent.hide_spaces_picker ();
      else
        parent.show_spaces_picker ();
    }
  }
  
  public class SpacesManager : GLib.Object
  {
    Clutter.Actor background;
    List<Clutter.Actor> clones;
    Plugin plugin;
    unowned Mutter.MetaScreen screen;
    ScrollerChild _button;
    SpacesButtonController controller;
    
    public ScrollerChild button {
      get {
        if (!(_button is ScrollerChild))
          {
            _button = new ScrollerChild ();
            controller = new SpacesButtonController (this, _button);
          }
        return _button;
      }
    }
    
    public uint top_padding { get; set; }
    public uint right_padding { get; set; }
    public uint bottom_padding { get; set; }
    public uint left_padding { get; set; }
    
    public uint spacing { get; set; }
    public bool showing { get; private set; }
    
    public SpacesManager (Plugin plugin) {
      this.plugin = plugin;
      this.plugin.workspace_switch_event.connect (this.workspace_switched);
    }
    
    construct
    {
      set_padding (50, 50, 50, 50);
      spacing = 15;
    }
    
    private void workspace_switched (Plugin plugin,
                                     List<Mutter.Window> windows,
                                     int from,
                                     int to,
                                     int direction) {
      this.plugin.plugin.effect_completed (windows.nth_data (0), Mutter.PLUGIN_SWITCH_WORKSPACE);
    }
    
    public void set_padding (uint top, uint right, uint left, uint bottom) {
      top_padding    = top;
      right_padding  = right;
      left_padding   = left;
      bottom_padding = bottom;
    }
    
    public void hide_spaces_picker () {
      select_workspace (null);
    }
    
    public void show_spaces_picker () {
      if (showing)
        return;
      
      showing = true;
      plugin.add_fullscreen_request (this);
      
      if (background is Clutter.Actor)
        background.destroy ();
      
      background = new Clutter.Rectangle.with_color ({0, 0, 0, 255});
      unowned Mutter.MetaScreen screen = plugin.plugin.get_screen (); 
      unowned GLib.List<Mutter.MetaWorkspace> workspaces = Mutter.MetaScreen.get_workspaces (screen);
      unowned Clutter.Container window_group = plugin.plugin.get_normal_window_group() as Clutter.Container;
      
      Mutter.MetaRectangle rect = {0, 0, 0, 0};
      Mutter.MetaScreen.get_monitor_geometry (screen, 0, rect);
      background.set_size (rect.width, rect.height);
      
      window_group.add_actor (background);
      background.raise_top ();
      
      foreach (unowned Mutter.MetaWorkspace workspace in workspaces)
        {
          Clutter.Actor clone = workspace_clone (workspace);
          clones.append (clone);
          
          window_group.add_actor (clone);
          clone.reactive = true;
          clone.raise_top ();
          clone.show ();
          
          unowned Mutter.MetaWorkspace cpy = workspace;
          clone.button_release_event.connect (() => { select_workspace (cpy); return true; });
        }
      
      layout_workspaces (clones, screen);
      
      unowned GLib.List<Mutter.Window> windows = plugin.plugin.get_windows ();
      foreach (Mutter.Window w in windows)
        {
            (w as Clutter.Actor).opacity = 0;
        }
    }
    
    private void select_workspace (Mutter.MetaWorkspace? workspace) {
      if (workspace == null)
        {
          workspace = Mutter.MetaScreen.get_active_workspace (plugin.plugin.get_screen ());
        }
        
      unlayout_workspaces (clones, plugin.plugin.get_screen (), Mutter.MetaWorkspace.index (workspace));
      clones = null;
      
      uint time_ = Mutter.MetaDisplay.get_current_time (Mutter.MetaScreen.get_display (Mutter.MetaWorkspace.get_screen (workspace)));
      Mutter.MetaWorkspace.activate (workspace, time_);
      plugin.remove_fullscreen_request (this);
      showing = false;
    }
    
    private Clutter.Actor workspace_clone (Mutter.MetaWorkspace workspace) {
      Clutter.Group wsp;
      unowned GLib.List<Mutter.Window> windows;
      
      windows = plugin.plugin.get_windows ();
      wsp = new Clutter.Group ();
      
      List<Clutter.Actor> toplevel_windows = new List<Clutter.Actor> ();
      
      int active_workspace = Mutter.MetaScreen.get_active_workspace_index (plugin.plugin.get_screen ());

      foreach (Mutter.Window window in windows)
        {
          if (Mutter.MetaWindow.is_on_all_workspaces (window.get_meta_window ()) ||
              window.get_workspace () == Mutter.MetaWorkspace.index (workspace))
            {
            
              if (!(window.get_window_type () == Mutter.MetaCompWindowType.NORMAL ||
                    window.get_window_type () == Mutter.MetaCompWindowType.DIALOG ||
                    window.get_window_type () == Mutter.MetaCompWindowType.MODAL_DIALOG ||
                    window.get_window_type () == Mutter.MetaCompWindowType.UTILITY))
                continue;
            
              ExposeClone clone = new ExposeClone (window);
              clone.fade_on_close = false;
              
              wsp.add_actor (clone);
              toplevel_windows.prepend (clone);
          
              clone.set_size (window.width, window.height);
              clone.set_position (window.x, window.y);
              
              clone.show ();
            }
        }
      
      ExposeClone background_clone = new ExposeClone (plugin.background);
      background_clone.fade_on_close = false;
      
      wsp.add_actor (background_clone);
      background_clone.lower_bottom ();
      background_clone.show ();
      
      plugin.expose_manager.position_windows_on_grid (toplevel_windows, 50, 50, 50, 50);
      
      return wsp;
    }
    
    private void unlayout_workspaces (List<Clutter.Actor> clones, Mutter.MetaScreen screen, int focus) {
      uint length = clones.length ();
      
      int width  = (int) Math.ceil  (Math.sqrt ((double) length));
      int height = (int) Math.floor (Math.sqrt ((double) length));
      
      Mutter.MetaRectangle rect = {0, 0, 0, 0};
      Mutter.MetaScreen.get_monitor_geometry (screen, 0, rect);
      
      for (int y = 0; y < height; y++)
        {
          for (int x = 0; x < width; x++)
            {
              int index = y * width + x;
              
              int xoffset = (x - (focus % width)) * rect.width;
              int yoffset = (y - (focus / width)) * rect.height;
              
              warning ("%i %i", xoffset, yoffset);
              
              Clutter.Actor clone = (Clutter.Actor) clones.nth_data (index);
              
              Clutter.Animation anim = clone.animate (Clutter.AnimationMode.EASE_IN_OUT_SINE, 250,
                      "x", (float) xoffset,
                      "y", (float) yoffset,
                      "scale-x", 1.0f,
                      "scale-y", 1.0f);
              
              int active_workspace = Mutter.MetaScreen.get_active_workspace_index (plugin.plugin.get_screen ());
              foreach (Clutter.Actor actor in (clone as Clutter.Group).get_children ())
                if (actor is ExposeClone)
                  (actor as ExposeClone).restore_window_position (active_workspace);
              
              anim.completed.connect (() => {
                clone.destroy ();
                if (background != null)
                  {
                    background.destroy ();
                    background = null;
                  }
                unowned GLib.List<Mutter.Window> windows = plugin.plugin.get_windows ();
                foreach (Mutter.Window w in windows)
                  {
                    (w as Clutter.Actor).opacity = 255;
                  }
              });
            }
        }
    }
    
    private void layout_workspaces (List<Clutter.Actor> clones, Mutter.MetaScreen screen) {
      uint length = clones.length ();
      
      int width  = (int) Math.ceil  (Math.sqrt ((double) length));
      int height = (int) Math.floor (Math.sqrt ((double) length));
      
      Mutter.MetaRectangle rect = {0, 0, 0, 0};
      Mutter.MetaScreen.get_monitor_geometry (screen, 0, rect);
      
      int active = Mutter.MetaScreen.get_active_workspace_index (screen);
       
      int xoffset = -(active % width) * rect.width;
      int yoffset = -(active / width) * rect.height;
       
      uint item_width = (rect.width - left_padding - right_padding - (width - 1) * spacing) / width;
      float item_scale = (float) item_width / (float) rect.width;
      uint item_height = (uint) (rect.height * item_scale);
      
      for (int y = 0; y < height; y++)
        {
          for (int x = 0; x < width; x++)
            {
              int index = y * width + x;
              Clutter.Actor clone = (Clutter.Actor) clones.nth_data (index);
              
              clone.set_scale (1.0f, 1.0f);
              
              clone.x = (float) rect.width * x + xoffset;
              clone.y = (float) rect.height * y + yoffset;
              
              clone.animate (Clutter.AnimationMode.EASE_IN_OUT_SINE, 250,
                      "x", (float) left_padding + ((item_width + spacing) * x),
                      "y", (float) top_padding + ((item_height + spacing) * y),
                      "scale-x", item_scale,
                      "scale-y", item_scale);
            }
        }
    }
  }
  
}

