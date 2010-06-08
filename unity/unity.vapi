/* unity.vapi generated by valac, do not modify. */

[CCode (cprefix = "Unity", lower_case_cprefix = "unity_")]
namespace Unity {
	[CCode (cprefix = "UnityDrag", lower_case_cprefix = "unity_drag_")]
	namespace Drag {
		[CCode (cheader_filename = "unity.h")]
		public class Controller : GLib.Object {
			public Controller ();
			public static unowned Unity.Drag.Controller get_default ();
			public Unity.Drag.Model get_drag_model ();
			public void start_drag (Unity.Drag.Model model, float offset_x, float offset_y);
			public bool is_dragging { get; }
			public signal void drag_drop (Unity.Drag.Model model, float x, float y);
			public signal void drag_motion (Unity.Drag.Model model, float x, float y);
			public signal void drag_start (Unity.Drag.Model model);
		}
		[CCode (cheader_filename = "unity.h")]
		public interface Model : GLib.Object {
			public abstract string get_drag_data ();
			public abstract Clutter.Actor get_icon ();
		}
		[CCode (cheader_filename = "unity.h")]
		public static Unity.Drag.Controller? controller_singleton;
	}
	[CCode (cprefix = "UnityPlace", lower_case_cprefix = "unity_place_")]
	namespace Place {
		[CCode (cheader_filename = "unity.h")]
		public class Controller : GLib.Object {
			public Controller (string dbus_path);
			public void add_entry (Unity.Place.EntryInfo entry);
			public void export () throws DBus.Error;
			public Unity.Place.EntryInfo[] get_entries ();
			public Unity.Place.EntryInfo? get_entry (string dbus_path);
			public string[] get_entry_paths ();
			public uint num_entries ();
			public void remove_entry (string dbus_path);
			public void unexport () throws DBus.Error;
			public string dbus_path { get; construct; }
			public bool exported { get; }
		}
		[CCode (cheader_filename = "unity.h")]
		public class EntryInfo : GLib.Object {
			public EntryInfo (string dbus_path);
			public void clear_hint (string hint);
			public void clear_hints ();
			public string? get_hint (string hint);
			public uint num_hints ();
			public void set_hint (string hint, string val);
			public bool active { get; set; }
			public uint active_section { get; set; }
			public string dbus_path { get; set construct; }
			public string display_name { get; set construct; }
			public Unity.Place.RendererInfo entry_renderer_info { get; }
			public Unity.Place.RendererInfo global_renderer_info { get; }
			public Unity.Place.SearchHandler global_search_handler { get; set; }
			public string icon { get; set construct; }
			public string[] mimetypes { get; set construct; }
			public uint position { get; set construct; }
			public Unity.Place.SearchHandler search_handler { get; set; }
			public Dee.Model sections_model { get; set construct; }
			public bool sensitive { get; set construct; }
		}
		[CCode (cheader_filename = "unity.h")]
		public class RendererInfo : GLib.Object {
			public void clear_hint (string hint);
			public void clear_hints ();
			public string? get_hint (string hint);
			public uint num_hints ();
			public void set_hint (string hint, string val);
			public string default_renderer { get; set; }
			public Dee.Model groups_model { get; set; }
			public Dee.Model results_model { get; set; }
		}
		[CCode (cheader_filename = "unity.h")]
		public class Search : GLib.InitiallyUnowned {
			public Search (string search, GLib.HashTable<string,string> hints);
			public void clear_hint (string hint);
			public void clear_hints ();
			public string? get_hint (string hint);
			public string get_search_string ();
			public uint num_hints ();
			public void set_hint (string hint, string val);
		}
		[CCode (cheader_filename = "unity.h")]
		public delegate uint SearchHandler (Unity.Place.Search search);
	}
	[CCode (cprefix = "UnityQuicklistRendering", lower_case_cprefix = "unity_quicklist_rendering_")]
	namespace QuicklistRendering {
		[CCode (cheader_filename = "unity.h")]
		public class Item : GLib.Object {
			public Item ();
			public static void get_text_extents (string font, string text, out int width, out int height);
			public static void normal_mask (Cairo.Context cr, int w, int h, string font, string text);
			public static void selected_mask (Cairo.Context cr, int w, int h, string font, string text);
		}
		[CCode (cheader_filename = "unity.h")]
		public class Menu : GLib.Object {
			public Menu ();
			public static void background (Cairo.Context cr, int w, int h, float anchor_y);
			public static void fill_mask (Cairo.Context cr, int w, int h, float anchor_y);
			public static void full_mask (Cairo.Context cr, int w, int h, float anchor_y);
		}
		[CCode (cheader_filename = "unity.h")]
		public class Seperator : GLib.Object {
			public Seperator ();
			public static void fill_mask (Cairo.Context cr);
			public static void image_background (Cairo.Context cr, int w, int h);
		}
	}
	[CCode (cprefix = "UnityWebapp", lower_case_cprefix = "unity_webapp_")]
	namespace Webapp {
		[CCode (cheader_filename = "unity.h")]
		public class ChromiumWebApp : GLib.Object {
			public string id;
			public string name;
			public ChromiumWebApp (string address, string icon);
			public void add_to_favorites ();
			public string desktop_file_path ();
			public string icon { get; construct; }
			public string url { get; construct; }
		}
		[CCode (cheader_filename = "unity.h")]
		public class FetchFile : GLib.Object {
			public FetchFile (string uri);
			public async void fetch_data ();
			public string uri { get; construct; }
			public signal void completed (GLib.ByteArray data);
			public signal void failed ();
		}
		[CCode (cheader_filename = "unity.h")]
		public class Prism : GLib.Object {
			public string id;
			public string name;
			public Prism (string address, string icon);
			public void add_to_favorites ();
			public string desktop_file_path ();
			public string icon { get; construct; }
			public string url { get; construct; }
		}
		[CCode (cheader_filename = "unity.h")]
		public class WebiconFetcher : GLib.Object {
			public WebiconFetcher (string uri, string destination, string desktop_file);
			public void fetch_webapp_data ();
			public string desktop_location { get; construct; }
			public string destination { get; construct; }
			public string uri { get; construct; }
			public signal void completed (string location);
			public signal void failed ();
		}
		[CCode (cheader_filename = "unity.h")]
		public static string get_hostname (string uri);
		[CCode (cheader_filename = "unity.h")]
		public static string urlify (string uri);
	}
	[CCode (cheader_filename = "unity.h")]
	public class Entry : Ctk.Text {
		public Entry (string static_text);
		public string static_text { get; set construct; }
	}
	[CCode (cheader_filename = "unity.h")]
	public abstract class Favorites : GLib.Object {
		public Favorites ();
		public abstract void add_favorite (string uid);
		public abstract bool? get_bool (string uid, string name);
		public static Unity.Favorites get_default ();
		public abstract Gee.ArrayList<string> get_favorites ();
		public abstract float? get_float (string uid, string name);
		public abstract int? get_int (string uid, string name);
		public abstract string? get_string (string uid, string name);
		public abstract bool is_favorite (string uid);
		public abstract void remove_favorite (string uid);
		public abstract void set_bool (string uid, string name, bool value);
		public abstract void set_float (string uid, string name, float value);
		public abstract void set_int (string uid, string name, int value);
		public abstract void set_string (string uid, string name, string value);
		public signal void favorite_added (string uid);
		public signal void favorite_changed (string uid);
		public signal void favorite_removed (string uid);
	}
	[CCode (cheader_filename = "unity.h")]
	public class GConfFavorites : Unity.Favorites {
		public GConfFavorites ();
		public override void add_favorite (string uid);
		public override bool? get_bool (string uid, string name);
		public override Gee.ArrayList<string> get_favorites ();
		public override float? get_float (string uid, string name);
		public override int? get_int (string uid, string name);
		public override string? get_string (string uid, string name);
		public override bool is_favorite (string uid);
		public override void remove_favorite (string uid);
		public override void set_bool (string uid, string name, bool value);
		public override void set_float (string uid, string name, float value);
		public override void set_int (string uid, string name, int value);
		public override void set_string (string uid, string name, string value);
	}
	[CCode (cheader_filename = "unity.h")]
	public class ThemeFilePath : GLib.Object {
		public ThemeFilePath ();
		public void add_icon_theme (Gtk.IconTheme theme);
		public async void get_icon_filepath (string icon_name);
		public signal void failed ();
		public signal void found_icon_path (string filepath);
	}
	[CCode (cheader_filename = "unity.h")]
	public class ThemeImage : Clutter.Texture {
		public Gdk.Pixbuf? icon;
		public ThemeImage (string icon_name);
		public string icon_name { get; set construct; }
	}
	[CCode (cheader_filename = "unity.h")]
	public class UnityIcon : Ctk.Actor {
		public UnityIcon (Clutter.Texture? icon, Clutter.Texture? bg_tex);
		public override void allocate (Clutter.ActorBox box, Clutter.AllocationFlags flags);
		public override void get_preferred_height (float for_width, out float minimum_height, out float natural_height);
		public override void get_preferred_width (float for_height, out float minimum_width, out float natural_width);
		public override void map ();
		public override void paint ();
		public static void paint_real (Clutter.Actor actor);
		public override void pick (Clutter.Color color);
		public override void unmap ();
		public Clutter.Texture? bg_color { get; construct; }
		public Clutter.Texture? icon { get; construct; }
	}
	[CCode (cheader_filename = "unity.h")]
	public interface Shell : GLib.Object {
		public abstract void add_fullscreen_request (GLib.Object o);
		public abstract void close_xids (GLib.Array<uint32> xids);
		public abstract void ensure_input_region ();
		public abstract void expose_xids (GLib.Array<uint32> xids);
		public abstract int get_indicators_width ();
		public abstract int get_launcher_width_foobar ();
		public abstract Unity.ShellMode get_mode ();
		public abstract int get_panel_height_foobar ();
		public abstract Clutter.Stage get_stage ();
		public abstract void grab_keyboard (bool grab, uint32 timestamp);
		public abstract bool remove_fullscreen_request (GLib.Object o);
		public abstract void show_unity ();
		public abstract void show_window (uint32 xid);
		public abstract void show_window_picker ();
		public abstract void stop_expose ();
		public abstract bool menus_swallow_events { get; }
		public signal void indicators_changed (int width);
		public signal void need_new_icon_cache ();
	}
	[CCode (cprefix = "UNITY_SHELL_MODE_", cheader_filename = "unity.h")]
	public enum ShellMode {
		UNDERLAY,
		OVERLAY
	}
	[CCode (cprefix = "UNITY_DND_TARGETS_", cheader_filename = "unity.h")]
	public enum dnd_targets {
		TARGET_INT32,
		TARGET_STRING,
		TARGET_URL,
		TARGET_OTHER
	}
	[CCode (cheader_filename = "unity.h")]
	public static Unity.Favorites favorites_singleton;
	[CCode (cheader_filename = "unity.h")]
	public static Unity.Shell? global_shell;
	[CCode (cheader_filename = "unity.h")]
	public static void get_average_color (Gdk.Pixbuf source, out uint red, out uint green, out uint blue);
	[CCode (cheader_filename = "unity.h")]
	public static void hsv_to_rgb (float hue, float sat, float val, out float r, out float g, out float b);
	[CCode (cheader_filename = "unity.h")]
	public static bool icon_name_exists_in_theme (string icon_name, string theme);
	[CCode (cheader_filename = "unity.h")]
	public static bool pixbuf_is_tile (Gdk.Pixbuf source);
	[CCode (cheader_filename = "unity.h")]
	public static void rgb_to_hsv (float r, float g, float b, out float hue, out float sat, out float val);
}
