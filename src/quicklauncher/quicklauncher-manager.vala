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
using Unity.Quicklauncher.Models;
namespace Unity.Quicklauncher
{

  public class Manager : Ctk.Bin
  {
    private Unity.Widgets.Scroller container;
    private Gee.HashMap<string,ApplicationModel> desktop_file_map;
    private Gee.HashMap<LauncherModel, LauncherView> model_map;

    private Launcher.Appman appman;
    private Launcher.Session session;

    // lazy init of gconf here :-) wait's until we need it
    private GConf.Client? gconf_client_;
    private GConf.Client? gconf_client {
      get {
        if (this.gconf_client_ is GConf.Client)
          {
            return this.gconf_client_;
          }
        else
          {
            return this.gconf_client_ = GConf.Client.get_default ();
          }
      }
    }

    construct
    {
      START_FUNCTION ();
      this.appman = Launcher.Appman.get_default ();
      this.session = Launcher.Session.get_default ();

      this.desktop_file_map = new Gee.HashMap<string, ApplicationModel> ();
      this.model_map = new Gee.HashMap<LauncherModel, LauncherView> ();

      this.container = new Unity.Widgets.Scroller (Ctk.Orientation.VERTICAL,
                                                   6);
      add_actor (container);

      build_favorites ();
      this.session.application_opened.connect (handle_session_application);

      Ctk.drag_dest_start (this.container);
      this.container.drag_motion.connect (on_drag_motion);
      this.container.drag_drop.connect (on_drag_drop);
      this.container.drag_data_received.connect (on_drag_data_received);

      END_FUNCTION ();
    }

    // returns which string is the currently set webapp device
    private string get_webapp_device ()
    {
      //check to see the unity dir exists
      try {
        bool dir_exists = this.gconf_client.dir_exists (UNITY_CONF_PATH);
        if (!dir_exists)
          {
            // make the directory
            this.gconf_client.add_dir (UNITY_CONF_PATH,
                                       GConf.ClientPreloadType.NONE);
          }
      }
      catch (Error e) {
        warning ("%s", e.message);
      }
          
      try {
        bool value = this.gconf_client.get_bool (UNITY_CONF_PATH + "/webapp_use_chromium");
        if (value)
          {
            return "chromium";
          }
      }
      catch (Error e) {
        return "prism";
      }
      return "prism";
    }

    private bool on_drag_motion (Ctk.Actor actor, Gdk.DragContext context,
                                 int x, int y, uint time_)
    {
      return true;
    }

    private bool on_drag_drop (Ctk.Actor actor, Gdk.DragContext context,
                               int x, int y, uint time_)
    {
      debug ("on_drag_drop called");
      if (context.targets != null)
      {
        Gtk.TargetList tl;
        Gdk.Atom target_type;
        // silly tricking vala into passing an array with no elements.
        // if anyone knows a way of doing this properly, please replace!
        Gtk.TargetEntry[]? targets = null;
        tl = new Gtk.TargetList (targets);
        tl.add_uri_targets (0);
        
        target_type = Ctk.drag_dest_find_target (context, tl);

        if (target_type.name () == "")
        {
          warning ("bad DND type");
          return false;
        }
        Ctk.drag_get_data (actor, context, target_type, time_);
        target_type = (Gdk.Atom) context.targets.nth_data (Unity.dnd_targets.TARGET_STRING);
        if (target_type.name () == "")
        {
          warning ("bad DND type");
          return false;
        }
        Ctk.drag_get_data (actor, context, target_type, time_);
        debug ("asking for data");
      } else
      {
        warning ("got a strange dnd");
        return false;
      }
      return true;
    }

    private void on_drag_data_received (Ctk.Actor actor,
                                        Gdk.DragContext context, int x, int y,
                                        Gtk.SelectionData data, uint target_type,
                                        uint time_)
    {
      debug ("on_drag_data_recieved called");
      bool dnd_success = false;
      bool delete_selection_data = false;
      // Deal with what we are given from source
      if ((data != null) && (data.length >= 0)) {
        if (context.action == Gdk.DragAction.MOVE) {
          delete_selection_data = true;
          debug ("delete_selection_data = true");
        }

        switch (target_type) {
        case Unity.dnd_targets.TARGET_URL:
          // we got a uri, forward it to the uri handler
          debug ("got a TARGET_URL");
          dnd_success = handle_uri ((string) data.data);
          break;
        default:
          break;
        }
      }

      if (dnd_success == false) {
        warning ("dnd transfer failed");
      }
      Gtk.drag_finish (context, dnd_success, delete_selection_data, time_);
    }

    private bool test_url (string url)
      {
        // just returns if the given string is really a url
        try {
          Regex match_url = new Regex (
            """((https?|s?ftp):((//)|(\\\\))+[\w\d:#@%/;$()~_?\+-=\\\.&]*)"""
          );
          if (match_url.match (url))
            {
              return true;
            }

        } catch (RegexError e) {
          warning ("%s", e.message);
          return false;
        }
        return false;
      }

    private bool handle_uri (string uri)
    {
      debug ("handling uri: " + uri);
      string clean_uri = uri.split("\n", 2)[0].split("\r", 2)[0];

      try {
        var regex = new Regex ("\\s");
        clean_uri = regex.replace (clean_uri, -1, 0, "");
      } catch (RegexError e) {
        warning ("%s", e.message);
      }
      clean_uri.strip();
      
      debug ("clean uri: " + clean_uri);

      var split_uri = clean_uri.split ("://", 2);
      
      if (test_url (clean_uri))
      {
        //we have a http url, webapp it
        string webapp_device = this.get_webapp_device ();
        switch (webapp_device) {
          case "prism":
            var webapp = new Prism (clean_uri);
            webapp.add_to_favorites ();
            break;

          case "chromium":
            var webapp = new ChromiumWebApp (clean_uri);
            webapp.add_to_favorites ();
            break;

          default:
            warning ("unknown webapp device %s", webapp_device);
            break;
        }
      }

      else if (".desktop" in Path.get_basename (clean_uri))
      {
        // we have a potential desktop file, test it.
        try
        {
          var desktop_file = new KeyFile ();
          desktop_file.load_from_file (split_uri[1], 0);
        } catch (Error e)
        {
          // not a desktop file
          error (e.message);
          return false;
        }

        var favorites = Launcher.Favorites.get_default ();
        string uid = "app-" + Path.get_basename (clean_uri);
        debug ("adding to favourites: " + uid);
        favorites.set_string (uid, "type", "application");
        favorites.set_string (uid, "desktop_file", split_uri[1]);
        favorites.add_favorite (uid);
      }
      else
      {
        return false;
      }

      build_favorites ();
      return true;
    }

    private void build_favorites ()
    {
      START_FUNCTION ();
      var favorites = Launcher.Favorites.get_default ();

      unowned SList<string> favorite_list = favorites.get_favorites();
      foreach (weak string uid in favorite_list)
        {
          string process_name = "favorite" + uid;
          LOGGER_START_PROCESS (process_name);
          // we only want favorite *applications* for the moment
          var type = favorites.get_string(uid, "type");
          if (type != "application")
              continue;

          string? desktop_file = favorites.get_string(uid, "desktop_file");
          assert (desktop_file != "");

          if (desktop_file != null && !(desktop_file in desktop_file_map.keys))
            {
              ApplicationModel model = get_model_for_desktop_file (desktop_file);
              model.is_sticky = true;
              LauncherView view = get_view_for_model (model);

              add_view (view);
            }

          LOGGER_END_PROCESS (process_name);
        }

      END_FUNCTION ();
    }


   private void handle_session_application (Launcher.Application app)
    {
      var desktop_file = app.get_desktop_file ();
      if (desktop_file != null)
      {
        ApplicationModel model = get_model_for_desktop_file (desktop_file);
        LauncherView view = get_view_for_model (model);
        if (view.get_parent () == null)
        {
          add_view (view);
        }
      }
    }


    private ApplicationModel get_model_for_desktop_file (string uri)
    {
      /* we check to see if we already have this desktop file loaded,
       * if so, we just use that one instead of creating a new model
       */
      if (uri in desktop_file_map.keys)
        {
          return desktop_file_map[uri];
        }

      ApplicationModel model = new ApplicationModel (uri);
      desktop_file_map[uri] = model;
      return model;
    }

    private LauncherView get_view_for_model (LauncherModel model)
    {
      if (model in this.model_map.keys)
        {
          return this.model_map[model];
        }

      LauncherView view = new LauncherView (model);
      this.model_map[model] = view;
      return view;
    }


    /**
     * adds the LauncherView @view to the launcher
     */
    private void add_view (LauncherView view)
    {
      if (view == null)
      {
        return;
      }
      container.add_actor(view);
      view.request_remove.connect(remove_view);
    }

    private void remove_view (LauncherView view)
    {
      // for now just remove the application quickly. at some point
      // i would assume we have to pretty fading though, thats trivial to do

      this.container.remove_actor (view);
    }

  }
}
