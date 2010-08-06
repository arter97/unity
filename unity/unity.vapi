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
	[CCode (cprefix = "UnityIO", lower_case_cprefix = "unity_io_")]
	namespace IO {
		[CCode (cheader_filename = "unity.h")]
		public static string[] get_system_data_dirs ();
		[CCode (cheader_filename = "unity.h")]
		public static async GLib.FileInputStream? open_from_data_dirs (string filename) throws GLib.Error;
		[CCode (cheader_filename = "unity.h")]
		public static async GLib.FileInputStream? open_from_dirs (string filename, string[] dirs) throws GLib.Error;
		[CCode (cheader_filename = "unity.h")]
		public static async void read_stream_async (GLib.InputStream input, owned uchar[] buffer, size_t buffer_lenght, int io_priority, GLib.Cancellable? cancellable, out void* data, out size_t size) throws GLib.Error;
	}
	[CCode (cprefix = "UnityPlace", lower_case_cprefix = "unity_place_")]
	namespace Place {
		[CCode (cheader_filename = "unity.h")]
		public class Browser<E> : GLib.Object {
			public Browser (string dbus_path);
			public void clear ();
			public void go_back ();
			public void go_forward ();
			public void record_state (E state, string comment);
			public string dbus_path { get; set; }
			public signal void back (E state, string comment);
			public signal void forward (E state, string comment);
		}
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
			public Unity.Place.Activation? activation { get; set; }
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
			public Unity.Place.Search active_global_search { get; set; }
			public Unity.Place.Search active_search { get; set; }
			public uint active_section { get; set; }
			public Unity.Place.Browser? browser { get; set; }
			public string dbus_path { get; set construct; }
			public string display_name { get; set construct; }
			public Unity.Place.RendererInfo entry_renderer_info { get; }
			public Unity.Place.RendererInfo global_renderer_info { get; }
			public string icon { get; set construct; }
			public string[] mimetypes { get; set construct; }
			public uint position { get; set construct; }
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
		[CCode (ref_function = "unity_place_stack_ref", unref_function = "unity_place_stack_unref", cheader_filename = "unity.h")]
		public class Stack<E> {
			public Stack ();
			public void clear ();
			public bool is_empty ();
			public E peek ();
			public E pop ();
			public Unity.Place.Stack<E> push (E element);
			public int size ();
		}
		[CCode (cheader_filename = "unity.h")]
		[DBus (name = "com.canonical.Unity.Activation")]
		public interface Activation : GLib.Object {
			public abstract async bool activate (string uri) throws DBus.Error;
		}
		[CCode (cheader_filename = "unity.h")]
		public interface Renderer : Ctk.Actor {
			public abstract void set_models (Dee.Model groups, Dee.Model results, Gee.HashMap<string,string> hints);
			public signal void activated (string uri, string mimetype);
		}
	}
	[CCode (cprefix = "UnityQuicklistRendering", lower_case_cprefix = "unity_quicklist_rendering_")]
	namespace QuicklistRendering {
		[CCode (cheader_filename = "unity.h")]
		public class CheckmarkItem : GLib.Object {
			public CheckmarkItem ();
			public static void normal_mask (Cairo.Context cr, int w, int h, string font, string text, bool enabled);
			public static void selected_mask (Cairo.Context cr, int w, int h, string font, string text, bool enabled);
		}
		[CCode (cheader_filename = "unity.h")]
		public class Item : GLib.Object {
			public Item ();
			public static void normal_mask (Cairo.Context cr, int w, int h, string font, string text);
			public static void selected_mask (Cairo.Context cr, int w, int h, string font, string text);
		}
		[CCode (cheader_filename = "unity.h")]
		public class Menu : GLib.Object {
			public Menu ();
			public static void anchor_mask (out Cairo.Surface surf, int width, int height, float anchor_width, float anchor_height, bool negative, bool outline, float line_width, float[] rgba);
			public static void background (Cairo.Context cr, int w, int h, float anchor_y);
			public static void bottom_mask (out Cairo.Surface surf, int width, int height, float radius, float anchor_width, bool negative, bool outline, float line_width, float[] rgba);
			public static void dyn_mask (out Cairo.Surface surf, int width, int height, float anchor_width, bool negative, bool outline, float line_width, float[] rgba);
			public static void fill_mask (Cairo.Context cr, int w, int h, float anchor_y);
			public static void full_mask (Cairo.Context cr, int w, int h, float anchor_y);
			public static void outline_shadow_anchor (out Cairo.Surface surf, int width, int height, float anchor_width, float anchor_height, uint shadow_radius, float[] rgba_shadow, float line_width, float[] rgba_line);
			public static void outline_shadow_bottom (out Cairo.Surface surf, int width, int height, float anchor_width, float corner_radius, uint shadow_radius, float[] rgba_shadow, float line_width, float[] rgba_line);
			public static void outline_shadow_dyn (out Cairo.Surface surf, int width, int height, float anchor_width, uint shadow_radius, float[] rgba_shadow, float line_width, float[] rgba_line);
			public static void outline_shadow_top (out Cairo.Surface surf, int width, int height, float anchor_width, float corner_radius, uint shadow_radius, float[] rgba_shadow, float line_width, float[] rgba_line);
			public static void tint_dot_hl (out Cairo.Surface surf, int width, int height, float hl_x, float hl_y, float hl_size, float[] rgba_tint, float[] rgba_hl);
			public static void top_mask (out Cairo.Surface surf, int width, int height, float radius, float anchor_width, bool negative, bool outline, float line_width, float[] rgba);
		}
		[CCode (cheader_filename = "unity.h")]
		public class RadioItem : GLib.Object {
			public RadioItem ();
			public static void normal_mask (Cairo.Context cr, int w, int h, string font, string text, bool enabled);
			public static void selected_mask (Cairo.Context cr, int w, int h, string font, string text, bool enabled);
		}
		[CCode (cheader_filename = "unity.h")]
		public class Seperator : GLib.Object {
			public Seperator ();
			public static void fill_mask (Cairo.Context cr);
			public static void image_background (Cairo.Context cr, int w, int h);
		}
		[CCode (cheader_filename = "unity.h")]
		public static void get_text_extents (string font, string text, out int width, out int height);
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
	public class AppInfoManager : GLib.Object {
		public void clear ();
		public static Unity.AppInfoManager get_instance ();
		public GLib.AppInfo? lookup (string id);
		public async GLib.AppInfo? lookup_async (string id) throws GLib.Error;
	}
	[CCode (cheader_filename = "unity.h")]
	public class CairoCanvas : Ctk.Bin {
		[CCode (cheader_filename = "unity.h")]
		public delegate void CairoCanvasPaint (Cairo.Context cr, int width, int height);
		public Clutter.CairoTexture texture;
		public CairoCanvas (Unity.CairoCanvas.CairoCanvasPaint _func);
		public void update ();
	}
	[CCode (cheader_filename = "unity.h")]
	public class Entry : Ctk.Text {
		public Entry (string static_text);
		public string static_text { get; set construct; }
	}
	[CCode (cheader_filename = "unity.h")]
	public class ExpandingBin : Ctk.Bin {
		public const int ANIMATION_TIME;
		public ExpandingBin ();
		public Unity.ExpandingBinState bin_state { get; set; }
		public float size_factor { get; set; }
		public float unexpanded_height { get; set; }
	}
	[CCode (cheader_filename = "unity.h")]
	public abstract class Favorites : GLib.Object {
		public Favorites ();
		public abstract void add_favorite (string uid);
		public abstract string find_uid_for_desktop_file (string desktop_file);
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
		public override string find_uid_for_desktop_file (string desktop_file);
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
	public class PixbufCache : GLib.Object {
		public PixbufCache (bool _autodispose = false);
		public void clear ();
		public Gdk.Pixbuf? @get (string icon_id, int size);
		public static Unity.PixbufCache get_default ();
		public void @set (string icon_id, Gdk.Pixbuf pixbuf, int size);
		public async void set_image_from_gicon (Ctk.Image image, GLib.Icon icon, int size);
		public async void set_image_from_gicon_string (Ctk.Image image, string gicon_as_string, int size);
		public async void set_image_from_icon_name (Ctk.Image image, string icon_name, int size);
		public uint size { get; }
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
		public signal void changed ();
	}
	[CCode (cheader_filename = "unity.h")]
	public class UnityIcon : Ctk.Actor {
		public float rotation;
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
		public abstract void about_to_show_places ();
		public abstract void add_fullscreen_request (GLib.Object o);
		public abstract void close_xids (GLib.Array<uint32> xids);
		public abstract void do_window_action (uint32 xid, Unity.WindowAction action);
		public abstract void ensure_input_region ();
		public abstract void expose_xids (GLib.Array<uint32> xids);
		public abstract uint32 get_current_time ();
		public abstract int get_indicators_width ();
		public abstract int get_launcher_width_foobar ();
		public abstract Unity.ShellMode get_mode ();
		public abstract int get_panel_height_foobar ();
		public abstract Clutter.Stage get_stage ();
		public abstract void get_window_details (uint32 xid, out bool allows_resize, out bool is_maximised);
		public abstract void grab_keyboard (bool grab, uint32 timestamp);
		public abstract void hide_unity ();
		public abstract bool remove_fullscreen_request (GLib.Object o);
		public abstract void show_unity ();
		public abstract void show_window (uint32 xid);
		public abstract void stop_expose ();
		public abstract bool menus_swallow_events { get; }
		public signal void active_window_state_changed ();
		public signal void indicators_changed (int width);
		public signal void mode_changed (Unity.ShellMode mode);
		public signal void need_new_icon_cache ();
	}
	[CCode (cprefix = "UNITY_EXPANDING_BIN_STATE_", cheader_filename = "unity.h")]
	public enum ExpandingBinState {
		CLOSED,
		UNEXPANDED,
		EXPANDED
	}
	[CCode (cprefix = "UNITY_SHELL_MODE_", cheader_filename = "unity.h")]
	public enum ShellMode {
		MINIMIZED,
		DASH,
		EXPOSE
	}
	[CCode (cprefix = "UNITY_WINDOW_ACTION_", cheader_filename = "unity.h")]
	public enum WindowAction {
		CLOSE,
		MINIMIZE,
		MAXIMIZE,
		UNMAXIMIZE
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
