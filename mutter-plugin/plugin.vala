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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

namespace Unity
{
  public class Plugin : Object, Shell
  {
    /* Signals */
    public signal void window_minimized (Plugin plugin, Mutter.Window window);
    public signal void window_maximized (Plugin        plugin,
                                         Mutter.Window window,
                                         int           x,
                                         int           y,
                                         int           width,
                                         int           height);
    public signal void window_unmaximized (Plugin        plugin,
                                           Mutter.Window window,
                                           int           x,
                                           int           y,
                                           int           width,
                                           int           height);
    public signal void window_mapped (Plugin plugin, Mutter.Window window);
    public signal void window_destroyed (Plugin plugin, Mutter.Window window);
    public signal void window_kill_effect (Plugin        plugin,
                                           Mutter.Window window,
                                           ulong         events);

    /* Properties */
    private Mutter.Plugin? _plugin;
    public  Mutter.Plugin? plugin {
      get { return _plugin; }
      set { _plugin = value; this.real_construct (); }
    }

    private static const int PANEL_HEIGHT        = 23;
    private static const int QUICKLAUNCHER_WIDTH = 54;
    
    private Clutter.Stage    stage;
    private Application      app;
    private WindowManagement wm;

    /* Unity Components */
    private Background         background;
    private Quicklauncher.View quicklauncher;
    private Places.View        places;

    /* Places toggle */
    private bool places_showing;

    construct
    {
      string[] args = { "mutter" };

      Ctk.init_after (ref args);
      
      /* Unique instancing */
      this.app = new Unity.Application ();
      this.app.shell = this;
    }

    private void real_construct ()
    {
      this.wm = new WindowManagement (this);
      this.stage = (Clutter.Stage)this.plugin.get_stage ();

      this.background = new Background ();
      this.stage.add_actor (this.background);
      this.background.lower_bottom ();

      this.quicklauncher = new Quicklauncher.View (this);
      this.quicklauncher.opacity = 0;
      this.stage.add_actor (this.quicklauncher);
      this.stage.raise_child (this.quicklauncher,
                              this.plugin.get_window_group());
      this.quicklauncher.animate (Clutter.AnimationMode.EASE_IN_SINE, 400,
                                  "opacity", 255);

      this.places = new Places.View ();
      this.places.opacity = 0;
      this.stage.add_actor (this.places);
      this.stage.raise_child (this.places, this.quicklauncher);
      this.places_showing = false;

      this.relayout ();
    }

    private void relayout ()
    {
      float width, height;

      this.stage.get_size (out width, out height);

      this.background.set_size (width, height);
      this.background.set_position (0, 0);

      this.quicklauncher.set_size (this.QUICKLAUNCHER_WIDTH,
                                   height-this.PANEL_HEIGHT);
      this.quicklauncher.set_position (0, this.PANEL_HEIGHT);
      this.quicklauncher.set_clip (0, 0,
                                   this.QUICKLAUNCHER_WIDTH,
                                   height-this.PANEL_HEIGHT);

      this.places.set_size (width, height);
      this.places.set_position (0, 0);

      this.plugin.set_stage_input_area (0,
                                        this.PANEL_HEIGHT,
                                        this.QUICKLAUNCHER_WIDTH,
                                        (int)(height - this.PANEL_HEIGHT));

      /* Leaving this here to remind me that we need to use these when 
       * there are fullscreen windows etc
       * this.plugin.set_stage_input_region (uint region);
		   * this.plugin.set_stage_reactive (true);
       */
    }

    /*
     * SHELL IMPLEMENTATION
     */
    public Clutter.Stage get_stage ()
    {
      return this.stage;
    }

    public ShellMode get_mode ()
    {
      return ShellMode.UNDERLAY;
    }

    public void show_unity ()
    {
      if (this.places_showing)
        {
          this.places_showing = false;
          this.places.animate (Clutter.AnimationMode.EASE_OUT_SINE, 300,
                               "opacity", 0);
          var win_group = this.plugin.get_window_group ();
          win_group.animate (Clutter.AnimationMode.EASE_IN_SINE, 300,
                             "opacity", 255);

          this.plugin.set_stage_input_area (0,
                                            this.PANEL_HEIGHT,
                                            this.QUICKLAUNCHER_WIDTH,
                                            (int)(this.stage.height 
                                                    - this.PANEL_HEIGHT));
        }
      else
        {
          this.places_showing = true;
          this.places.animate (Clutter.AnimationMode.EASE_IN_SINE, 300,
                               "opacity", 255);
          
          var win_group = this.plugin.get_window_group ();
          win_group.animate (Clutter.AnimationMode.EASE_OUT_SINE, 300,
                              "opacity", 0);
          
          this.plugin.set_stage_input_area (0,
                                            this.PANEL_HEIGHT,
                                            (int)this.stage.width,
                                            (int)this.stage.height
                                                    - this.PANEL_HEIGHT);
        }
      debug ("Places showing: %s", this.places_showing ? "true":"false");
    }

    /*
     * MUTTER PLUGIN HOOKS
     */
    public void minimize (Mutter.Window window)
    {
      this.window_minimized (this, window);
    }

    public void maximize (Mutter.Window window,
                          int           x,
                          int           y,
                          int           width,
                          int           height)
    {
      this.window_maximized (this, window, x, y, width, height);
    }

    public void unmaximize (Mutter.Window window,
                            int           x,
                            int           y,
                            int           width,
                            int           height)
    {
      this.window_unmaximized (this, window, x, y, width, height);
    }

    public void map (Mutter.Window window)
    {
      this.window_mapped (this, window);
    }

    public void destroy (Mutter.Window window)
    {
      this.window_destroyed (this, window);
    }

    public void switch_workspace (List<Mutter.Window> windows,
                                  int                 from,
                                  int                 to,
                                  int                 direction)
    {
      debug ("Switch workplace");
    }

    public void kill_effect (Mutter.Window window, ulong events)
    {
      debug ("Window kill event");
      this.window_kill_effect (this, window, events);
    }
  }
}
