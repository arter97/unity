/* launcher-0.3.vapi generated by vapigen, do not modify. */

[CCode (cprefix = "Launcher", lower_case_cprefix = "launcher_")]
namespace Launcher {
	[CCode (cheader_filename = "launcher/launcher.h")]
	public class Application : GLib.Object {
		[CCode (has_construct_function = false)]
		public Application ();
		public void ensure_state ();
		[CCode (has_construct_function = false)]
		public Application.from_desktop_file (string desktop_file);
		[CCode (has_construct_function = false)]
		public Application.from_wnck_window (Wnck.Window window);
		public unowned GLib.SList get_categories ();
		public unowned string get_comment ();
		public unowned string get_desktop_file ();
		public unowned string get_exec_string ();
		public bool get_favorite ();
		public bool get_focused ();
		public unowned string get_icon_name ();
		public unowned string get_name ();
		public bool get_running ();
		public unowned string get_unique_string ();
		public unowned GLib.SList get_windows ();
		public bool has_minimized ();
		public bool launch () throws GLib.Error;
		public void minimize ();
		public bool owns_window (Wnck.Window window);
		public void restore ();
		public void set_desktop_file (string desktop_file);
		public void show ();
		public void update_windows ();
		public GLib.SList categories { get; }
		public string comment { get; }
		[NoAccessorMethod]
		public string desktop_file_path { owned get; set; }
		[NoAccessorMethod]
		public string exec { owned get; }
		public bool favorite { get; }
		[NoAccessorMethod]
		public bool focused { get; set; }
		public string icon_name { get; }
		public string name { get; }
		[NoAccessorMethod]
		public bool running { get; set; }
		public string unique_string { get; }
		public virtual signal void closed (Wnck.Window wnckwindow);
		public virtual signal void focus_changed ();
		public virtual signal void opened (Wnck.Window wnckwindow);
		public virtual signal void running_changed ();
	}
	[Compact]
	[CCode (cheader_filename = "launcher/launcher.h")]
	public class ApplicationWindow {
	}
	[CCode (cheader_filename = "launcher/launcher.h")]
	public class Appman : GLib.Object {
		public unowned Launcher.Application get_application_for_desktop_file (string desktop);
		public unowned Launcher.Application get_application_for_wnck_window (Wnck.Window wnck_window);
		public unowned GLib.Sequence get_applications ();
		public static unowned Launcher.Appman get_default ();
	}
	[Compact]
	[CCode (cheader_filename = "launcher/launcher.h")]
	public class Category {
		public weak GLib.Object parent_instance;
		[CCode (has_construct_function = false)]
		public Category (string name, string comment, string icon_name);
		public void add_application (Launcher.Application application);
		public void empty_applications ();
		public unowned GLib.SList get_applications ();
		public unowned string get_comment ();
		public unowned string get_icon_name ();
		public unowned string get_name ();
		public void remove_application (Launcher.Application application);
		public void sort_applications (GLib.CompareFunc sort_func);
	}
	[Compact]
	[CCode (cheader_filename = "launcher/launcher.h")]
	public class CategoryClass {
		public weak GLib.Callback application_added;
		public weak GLib.Callback application_removed;
		public weak GLib.ObjectClass parent_class;
		public weak GLib.Callback removed;
	}
	[CCode (cheader_filename = "launcher/launcher.h")]
	public class Favorites : GLib.Object {
		public bool add_favorite (string uid);
		public bool get_bool (string uid, string key);
		public static unowned Launcher.Favorites get_default ();
		public unowned GLib.SList get_favorites ();
		public float get_float (string uid, string key);
		public int get_int (string uid, string key);
		public unowned GLib.SList get_list (string uid, string key, Launcher.FavoritesListValue value_type);
		public unowned string get_string (string uid, string key);
		public bool remove_favorite (string uid);
		public void set_bool (string uid, string key, bool value);
		public void set_favorites (GLib.SList list);
		public void set_float (string uid, string key, float value);
		public void set_int (string uid, string key, int value);
		public void set_list (string uid, string key, Launcher.FavoritesListValue value_type, GLib.SList value);
		public void set_string (string uid, string key, string value);
	}
	[Compact]
	[CCode (type_id = "LAUNCHER_TYPE_FOLDER", cheader_filename = "launcher/launcher.h")]
	public class Folder {
		[CCode (has_construct_function = false)]
		public Folder (string name, string uri);
		public void activate () throws GLib.Error;
		public unowned string get_icon_name ();
		public unowned string get_name ();
		public unowned string get_uri ();
	}
	[CCode (cheader_filename = "launcher/launcher.h")]
	public class FolderBookmarks : GLib.Object {
		public unowned GLib.SList get_bookmarks ();
		public static unowned Launcher.FolderBookmarks get_default ();
		public virtual signal void bookmarks_changed ();
	}
	[CCode (cheader_filename = "launcher/launcher.h")]
	public class Menu : GLib.Object {
		public unowned GLib.SList get_applications ();
		public unowned GLib.SList get_categories ();
		public static unowned Launcher.Menu get_default ();
		public virtual signal void menu_changed ();
	}
	[CCode (cheader_filename = "launcher/launcher.h")]
	public class Session : GLib.Object {
		public static unowned Launcher.Session get_default ();
		public virtual signal void application_launching (Launcher.Application application);
		public virtual signal void application_opened (Launcher.Application application);
	}
	[CCode (cprefix = "LAUNCHER_FAVORITES_", has_type_id = "0", cheader_filename = "launcher/launcher.h")]
	public enum FavoritesListValue {
		STRING,
		INT,
		FLOAT,
		BOOL
	}
	[CCode (cheader_filename = "launcher/launcher.h")]
	public static unowned string icon_utils_icon_name_for_volume_uri (string uri);
}
