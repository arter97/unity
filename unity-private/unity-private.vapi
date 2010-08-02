/* unity-private.vapi generated by valac, do not modify. */

[CCode (cprefix = "Unity", lower_case_cprefix = "unity_")]
namespace Unity {
	[CCode (cprefix = "UnityLauncher", lower_case_cprefix = "unity_launcher_")]
	namespace Launcher {
		[CCode (cheader_filename = "unity-private.h")]
		public class ApplicationController : Unity.Launcher.ScrollerChildController {
			public ApplicationController (string? desktop_file_, Unity.Launcher.ScrollerChild child_);
			public override void activate ();
			public void attach_application (Bamf.Application application);
			public void close_windows ();
			public void closed ();
			public bool debug_is_application_attached ();
			public void detach_application ();
			public override void get_menu_actions (Unity.Launcher.ScrollerChildController.menu_cb callback);
			public override Unity.Launcher.QuicklistController? get_menu_controller ();
			public override void get_menu_navigation (Unity.Launcher.ScrollerChildController.menu_cb callback);
			public float get_priority () throws Unity.Launcher.AppTypeError;
			public bool is_sticky ();
			public void set_priority (float priority);
			public void set_sticky (bool is_sticky = true);
			public string desktop_file { get; set; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class ApplicationQuicklistController : Unity.Launcher.QuicklistController {
			public ApplicationQuicklistController (Unity.Launcher.ScrollerChildController scroller_child);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class Launcher : GLib.Object {
			public Launcher (Unity.Shell shell);
			public Ctk.EffectCache get_actor_cache ();
			public Clutter.Actor get_container ();
			public Clutter.Actor get_view ();
			public float get_width ();
			public Unity.Launcher.ScrollerModel model { get; set; }
			public Unity.Shell shell { get; construct; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class LauncherContainer : Ctk.Bin {
			public Ctk.EffectCache cache;
			public LauncherContainer ();
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class QuicklistCheckMenuItem : Ctk.CheckMenuItem {
			public QuicklistCheckMenuItem ();
			public override void get_preferred_height (float for_width, out float min_height_p, out float natural_height_p);
			public override void get_preferred_width (float for_height, out float min_width_p, out float natural_width_p);
			public QuicklistCheckMenuItem.with_label (string label);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public abstract class QuicklistController : GLib.Object {
			protected Ctk.MenuExpandable? menu;
			public QuicklistController ();
			public static bool do_menus_match (Unity.Launcher.QuicklistController menu);
			public static unowned Unity.Launcher.QuicklistController get_current_menu ();
			public unowned Ctk.MenuExpandable? get_view ();
			public static bool is_menu_open ();
			public Unity.Launcher.ScrollerChildController attached_controller { get; construct; }
			public Unity.Launcher.QuicklistControllerState state { get; set; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class QuicklistImageMenuItem : Ctk.ImageMenuItem {
			public QuicklistImageMenuItem ();
			public override void get_preferred_height (float for_width, out float min_height_p, out float natural_height_p);
			public override void get_preferred_width (float for_height, out float min_width_p, out float natural_width_p);
			public QuicklistImageMenuItem.with_label (string label);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class QuicklistMenu : Ctk.MenuExpandable {
			public QuicklistMenu ();
			public override void paint ();
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class QuicklistMenuItem : Ctk.MenuItem {
			public QuicklistMenuItem ();
			public override void get_preferred_height (float for_width, out float min_height_p, out float natural_height_p);
			public override void get_preferred_width (float for_height, out float min_width_p, out float natural_width_p);
			public QuicklistMenuItem.with_label (string label);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class QuicklistMenuSeperator : Ctk.MenuSeperator {
			public QuicklistMenuSeperator ();
			public override void get_preferred_height (float for_width, out float min_height_p, out float natural_height_p);
			public override void get_preferred_width (float for_height, out float min_width_p, out float natural_width_p);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class QuicklistRadioMenuItem : Ctk.RadioMenuItem {
			public QuicklistRadioMenuItem (GLib.SList? group);
			public override void get_preferred_height (float for_width, out float min_height_p, out float natural_height_p);
			public override void get_preferred_width (float for_height, out float min_width_p, out float natural_width_p);
			public QuicklistRadioMenuItem.with_label (GLib.SList? group, string label);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class ScrollerChild : Ctk.Actor {
			[CCode (cprefix = "UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_", cheader_filename = "unity-private.h")]
			public enum GroupType {
				APPLICATION,
				PLACE,
				DEVICE,
				SYSTEM
			}
			public Unity.Launcher.ScrollerChildController controller;
			public Unity.Launcher.PinType pin_type;
			public ScrollerChild ();
			public override void allocate (Clutter.ActorBox box, Clutter.AllocationFlags flags);
			public void force_rotation_jump (float degrees);
			public Clutter.Actor get_content ();
			public override void get_preferred_height (float for_width, out float minimum_height, out float natural_height);
			public override void get_preferred_width (float for_height, out float minimum_width, out float natural_width);
			public override void map ();
			public override void paint ();
			public override void pick (Clutter.Color color);
			public string to_string ();
			public override void unmap ();
			public bool activating { get; set; }
			public bool active { get; set; }
			public Unity.Launcher.ScrollerChild.GroupType group_type { get; set construct; }
			public Gdk.Pixbuf icon { get; set; }
			public bool needs_attention { get; set; }
			public float position { get; set; }
			public float rotation { get; set; }
			public bool running { get; set; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public abstract class ScrollerChildController : GLib.Object, Unity.Drag.Model {
			[CCode (cheader_filename = "unity-private.h")]
			public delegate void menu_cb (Dbusmenu.Menuitem? menu);
			protected bool button_down;
			protected float click_start_pos;
			protected int drag_sensitivity;
			protected uint32 last_press_time;
			protected Unity.Launcher.ScrollerChildControllerMenuState menu_state;
			public ScrollerChildController (Unity.Launcher.ScrollerChild child_);
			public virtual void activate ();
			public virtual bool can_drag ();
			public void closed ();
			public virtual void get_menu_actions (Unity.Launcher.ScrollerChildController.menu_cb callback);
			public virtual Unity.Launcher.QuicklistController? get_menu_controller ();
			public virtual void get_menu_navigation (Unity.Launcher.ScrollerChildController.menu_cb callback);
			protected void load_icon_from_icon_name (string icon_name);
			public Unity.Launcher.ScrollerChild child { get; construct; }
			public bool hide { get; set; }
			protected Unity.Launcher.QuicklistController? menu { get; set; }
			public string name { get; set; }
			public signal void request_removal ();
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class ScrollerModel : GLib.Object {
			[CCode (ref_function = "unity_launcher_scroller_model_iterator_ref", unref_function = "unity_launcher_scroller_model_iterator_unref", cheader_filename = "unity-private.h")]
			public class Iterator {
				public Iterator (Gee.ArrayList arraylist);
				public Unity.Launcher.ScrollerChild @get ();
				public bool next ();
			}
			public int n_app_icons;
			public int n_device_icons;
			public int n_place_icons;
			public int n_system_icons;
			public ScrollerModel ();
			public void add (Unity.Launcher.ScrollerChild child);
			public int clamp (Unity.Launcher.ScrollerChild child, int value);
			public bool contains (Unity.Launcher.ScrollerChild child);
			public Unity.Launcher.ScrollerChild @get (int i);
			public int index_of (Unity.Launcher.ScrollerChild child);
			public void insert (Unity.Launcher.ScrollerChild child, int i);
			public Unity.Launcher.ScrollerModel.Iterator iterator ();
			public void move (Unity.Launcher.ScrollerChild child, int i);
			public void remove (Unity.Launcher.ScrollerChild child);
			public void @set (int i, Unity.Launcher.ScrollerChild item);
			public void sort (GLib.CompareFunc compare);
			public string to_string ();
			public int size { get; }
			public signal void child_added (Unity.Launcher.ScrollerChild child);
			public signal void child_removed (Unity.Launcher.ScrollerChild child);
			public signal void order_changed ();
		}
		[CCode (cheader_filename = "unity-private.h")]
		public interface ShortcutItem : GLib.Object {
			public abstract void activated ();
			public abstract string get_name ();
		}
		[CCode (cprefix = "UNITY_LAUNCHER_PIN_TYPE_", cheader_filename = "unity-private.h")]
		public enum PinType {
			UNPINNED,
			PINNED,
			ALWAYS,
			NEVER
		}
		[CCode (cprefix = "UNITY_LAUNCHER_QUICKLIST_CONTROLLER_STATE_", cheader_filename = "unity-private.h")]
		public enum QuicklistControllerState {
			LABEL,
			MENU,
			CLOSED
		}
		[CCode (cprefix = "UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_", cheader_filename = "unity-private.h")]
		public enum ScrollerChildControllerMenuState {
			NO_MENU,
			LABEL,
			MENU,
			MENU_CLOSE_WHEN_LEAVE
		}
		[CCode (cprefix = "UNITY_LAUNCHER_APP_TYPE_ERROR_", cheader_filename = "unity-private.h")]
		public errordomain AppTypeError {
			NO_DESKTOP_FILE,
		}
		[CCode (cheader_filename = "unity-private.h")]
		public static Unity.Launcher.QuicklistController? ql_controller_singleton;
	}
	[CCode (cprefix = "UnityPanel", lower_case_cprefix = "unity_panel_")]
	namespace Panel {
		[CCode (cprefix = "UnityPanelIndicators", lower_case_cprefix = "unity_panel_indicators_")]
		namespace Indicators {
			[CCode (cheader_filename = "unity-private.h")]
			public class IndicatorBar : Ctk.Box {
				public IndicatorBar ();
				public Unity.Panel.Indicators.IndicatorObjectView? get_indicator_view_matching (Indicator.Object o);
			}
			[CCode (cheader_filename = "unity-private.h")]
			public class IndicatorObjectEntryView : Ctk.Box {
				public Ctk.Image image;
				public Ctk.Text text;
				public IndicatorObjectEntryView (Indicator.ObjectEntry _entry);
				public bool is_open ();
				public void menu_key_moved (Gtk.MenuDirectionType type);
				public void menu_shown ();
				public void menu_vis_changed ();
				public bool on_button_press_event (Clutter.Event e);
				public bool on_motion_event (Clutter.Event e);
				public void show_menu ();
				public Indicator.ObjectEntry entry { get; construct; }
				public signal void menu_moved (Gtk.MenuDirectionType type);
			}
			[CCode (cheader_filename = "unity-private.h")]
			public class IndicatorObjectView : Ctk.Box {
				public IndicatorObjectView (Indicator.Object _object);
				public bool find_entry (Indicator.ObjectEntry entry);
				public Unity.Panel.Indicators.IndicatorObjectEntryView? get_entry_view (Indicator.ObjectEntry entry);
				public void open_first_menu_entry ();
				public void open_last_menu_entry ();
				public void remove_first_entry ();
				public void show_entry_menu (int entry);
				public Indicator.Object indicator_object { get; construct; }
				public signal void menu_moved (Gtk.MenuDirectionType type);
			}
			[CCode (cheader_filename = "unity-private.h")]
			public class IndicatorsFileModel : Unity.Panel.Indicators.IndicatorsModel {
				public Gee.ArrayList<Indicator.Object> indicator_list;
				public Gee.HashMap<Indicator.Object,string> indicator_map;
				public static Gee.HashMap<string,int> indicator_order;
				public IndicatorsFileModel ();
				public override string get_indicator_name (Indicator.Object o);
				public override Gee.ArrayList<Indicator.Object> get_indicators ();
				public static int indicator_sort_func (string a, string b);
			}
			[CCode (cheader_filename = "unity-private.h")]
			public abstract class IndicatorsModel : GLib.Object {
				public IndicatorsModel ();
				public static Unity.Panel.Indicators.IndicatorsModel get_default ();
				public abstract string get_indicator_name (Indicator.Object o);
				public abstract Gee.ArrayList<Indicator.Object> get_indicators ();
				public static void set_default (Unity.Panel.Indicators.IndicatorsModel model);
			}
			[CCode (cheader_filename = "unity-private.h")]
			public class MenuBar : Ctk.Box {
				public Unity.Panel.Indicators.IndicatorObjectView indicator_object_view;
				public MenuBar ();
			}
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class Background : Clutter.CairoTexture {
			public const string BG;
			public Background ();
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class HomeButton : Ctk.Button {
			public HomeButton (Unity.Shell shell);
			public Unity.Shell shell { get; construct; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class IndicatorBackground : Clutter.CairoTexture {
			public const string BG;
			public IndicatorBackground ();
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class SystemTray : Ctk.Box {
			public SystemTray ();
			public void manage_stage (Clutter.Stage stage);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class View : Ctk.Bin {
			public Ctk.EffectCache cache;
			public bool expanded;
			public View (Unity.Shell shell);
			public int get_indicators_width ();
			public int get_panel_height ();
			public void set_expanded (bool _expanded);
			public void set_indicator_mode (bool mode);
			public Unity.Shell shell { get; construct; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class WindowButton : Ctk.Button {
			public Clutter.Actor bg;
			public const string AMBIANCE;
			public WindowButton (string filename);
			public string filename { get; construct; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class WindowButtons : Ctk.Box {
			public WindowButtons ();
		}
	}
	[CCode (cprefix = "UnityPlaces", lower_case_cprefix = "unity_places_")]
	namespace Places {
		[CCode (cheader_filename = "unity-private.h")]
		public class Controller : GLib.Object {
			public Controller (Unity.Shell shell);
			public void activate_entry (string entry_name);
			public Unity.Places.View get_view ();
			public Unity.Places.PlaceModel model { get; set; }
			public Unity.Shell shell { get; construct; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class DefaultRenderer : Ctk.ScrollView, Unity.Place.Renderer {
			public DefaultRenderer ();
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class DefaultRendererGroup : Unity.ExpandingBin {
			public DefaultRendererGroup (uint group_id, string group_renderer, string display_name, string icon_hint, Dee.Model results);
			public string display_name { get; construct; }
			public uint group_id { get; construct; }
			public string group_renderer { get; construct; }
			public string icon_hint { get; construct; }
			public Dee.Model results { get; construct; }
			public signal void activated (string uri, string mimetype);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class FolderBrowserRenderer : Ctk.ScrollView, Unity.Place.Renderer {
			public FolderBrowserRenderer ();
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class MoreResultsButton : Ctk.Button {
			public MoreResultsButton ();
			public uint count { get; set; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class Place : GLib.Object {
			public GLib.Regex? mime_regex;
			public GLib.Regex? uri_regex;
			public Place (string dbus_name, string dbus_path);
			public bool activate (string uri);
			public void connect ();
			public unowned Gee.ArrayList<Unity.Places.PlaceEntry> get_entries ();
			public Unity.Places.PlaceEntry? get_nth_entry (int index);
			public static Unity.Places.Place? new_from_keyfile (GLib.KeyFile file, string id = "Unknown");
			public string dbus_name { get; construct; }
			public string dbus_path { get; construct; }
			public int n_entries { get; }
			public bool online { get; set; }
			public signal void entry_added (Unity.Places.PlaceEntry entry);
			public signal void entry_removed (Unity.Places.PlaceEntry entry);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class PlaceBar : Ctk.Box {
			public PlaceBar (Unity.Shell shell, Unity.Places.PlaceModel model);
			public void active_entry_name (string name);
			public void reset ();
			public Unity.Places.PlaceModel model { get; set construct; }
			public Unity.Shell shell { get; construct; }
			public signal void entry_view_activated (Unity.Places.PlaceEntry view, int x);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class PlaceBarBackground : Clutter.CairoTexture {
			public const string BG;
			public PlaceBarBackground (Unity.Shell shell);
			public int entry_position { get; set; }
			public Unity.Shell shell { get; construct; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class PlaceEntryDbus : GLib.Object, Unity.Places.PlaceEntry {
			[CCode (type_id = "UNITY_PLACES_PLACE_ENTRY_DBUS_TYPE_PLACE_ENTRY_INFO", cheader_filename = "unity-private.h")]
			public struct PlaceEntryInfo {
				public string dbus_path;
				public string name;
				public string icon;
				public uint position;
				public string[] mimetype;
				public bool sensitive;
				public string sections_model;
				public GLib.HashTable<string,string> hints;
			}
			[CCode (type_id = "UNITY_PLACES_PLACE_ENTRY_DBUS_TYPE_RENDERER_INFO", cheader_filename = "unity-private.h")]
			public struct RendererInfo {
				public string default_renderer;
				public string groups_model;
				public string results_model;
				public GLib.HashTable<string,string> renderer_hints;
			}
			public string entry_groups_model_name;
			public string entry_results_model_name;
			public string global_groups_model_name;
			public PlaceEntryDbus (string dbus_name, string dbus_path);
			public void update_info (GLib.ValueArray value_array);
			public PlaceEntryDbus.with_info (string dbus_name, string dbus_path, string name, string icon, string description, bool show_global, bool show_entry);
			public string? dbus_name { get; construct; }
			public string? dbus_path { get; construct; }
			public string global_results_model_name { get; set; }
			public string sections_model_name { get; set; }
			public bool show_entry { get; set construct; }
			public bool show_global { get; set construct; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class PlaceEntryScrollerChildController : Unity.Launcher.ScrollerChildController {
			public PlaceEntryScrollerChildController (Unity.Places.PlaceEntry entry);
			public override void activate ();
			public override bool can_drag ();
			public override void get_menu_actions (Unity.Launcher.ScrollerChildController.menu_cb callback);
			public override Unity.Launcher.QuicklistController? get_menu_controller ();
			public Unity.Places.PlaceEntry entry { get; construct; }
			public signal void clicked (uint section_id);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class PlaceEntryView : Ctk.Image {
			public PlaceEntryView (Unity.Places.PlaceEntry entry);
			public Unity.Places.PlaceEntry entry { get; construct; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class PlaceFileModel : Unity.Places.PlaceModel {
			public PlaceFileModel ();
			public PlaceFileModel.with_directory (string _directory);
			public bool @async { get; construct; }
			public string directory { get; construct; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class PlaceHomeEntry : GLib.Object, Unity.Places.PlaceEntry {
			public PlaceHomeEntry (Unity.Shell shell, Unity.Places.PlaceModel model);
			public Unity.Places.PlaceModel place_model { get; set construct; }
			public Unity.Shell shell { get; construct; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public abstract class PlaceModel : Gee.ArrayList<Unity.Places.Place> {
			public PlaceModel ();
			public signal void place_added (Unity.Places.Place place);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class PlaceSearchBar : Ctk.Box {
			public PlaceSearchBar ();
			public string get_search_text ();
			public void reset ();
			public void search (string text);
			public void set_active_entry_view (Unity.Places.PlaceEntry entry, int x, uint section = 0);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class PlaceSearchBarBackground : Ctk.Bin {
			public const string BG;
			public PlaceSearchBarBackground (Unity.Places.PlaceSearchNavigation nav, Unity.Places.PlaceSearchEntry search_entry);
			public bool update_background ();
			public int entry_position { get; set; }
			public Unity.Places.PlaceSearchNavigation navigation { get; construct; }
			public Unity.Places.PlaceSearchEntry search_entry { get; construct; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class PlaceSearchEntry : Ctk.Box {
			public Ctk.Image left_icon;
			public Unity.ThemeImage right_icon;
			public Ctk.Text text;
			public PlaceSearchEntry ();
			public void reset ();
			public signal void text_changed (string? text);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class PlaceSearchNavigation : Ctk.Box {
			public PlaceSearchNavigation ();
			public void set_active_entry (Unity.Places.PlaceEntry entry);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class PlaceSearchSectionsBar : Ctk.Box {
			public Unity.Places.SectionStyle _style;
			public PlaceSearchSectionsBar ();
			public void set_active_entry (Unity.Places.PlaceEntry entry);
			public void set_active_section (uint section_id);
			public Unity.Places.SectionStyle style { get; set; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class PlaceView : Ctk.Box {
			public PlaceView (Unity.Places.Place place);
			public Unity.Places.Place place { get; construct; }
			public signal void entry_activated (Unity.Places.PlaceEntryView entry_view);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class Tile : Ctk.Button {
			public Tile (Dee.ModelIter iter, string uri, string? icon_hint, string? mimetype, string display_name, string? comment);
			public void about_to_show ();
			public string? comment { get; construct; }
			public string display_name { get; construct; }
			public string? icon_hint { get; construct; }
			public Dee.ModelIter iter { get; construct; }
			public string? mimetype { get; construct; }
			public string uri { get; construct; }
			public signal void activated (string uri, string mimetype);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class TrashController : Unity.Launcher.ScrollerChildController {
			public const string ICON;
			public TrashController ();
			public override void activate ();
			public override bool can_drag ();
			public override void get_menu_actions (Unity.Launcher.ScrollerChildController.menu_cb callback);
			public override Unity.Launcher.QuicklistController? get_menu_controller ();
			public override void get_menu_navigation (Unity.Launcher.ScrollerChildController.menu_cb callback);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class View : Ctk.Box {
			public Unity.Places.PlaceHomeEntry home_entry;
			public Unity.Places.PlaceSearchBar search_bar;
			public const float PADDING;
			public View (Unity.Shell shell, Unity.Places.PlaceModel model);
			public void about_to_show ();
			public void hidden ();
			public void on_entry_view_activated (Unity.Places.PlaceEntry entry, uint section_id);
			public void shown ();
			public Unity.Places.PlaceModel model { get; construct; }
			public Unity.Shell shell { get; construct; }
		}
		[CCode (cheader_filename = "unity-private.h")]
		public interface PlaceEntry : GLib.Object {
			public abstract void connect ();
			public abstract void set_active_section (uint section_id);
			public abstract void set_global_search (string search, GLib.HashTable<string,string> hints);
			public abstract void set_search (string search, GLib.HashTable<string,string> hints);
			public abstract bool active { get; set; }
			public abstract string description { get; set construct; }
			public abstract Dee.Model? entry_groups_model { get; set; }
			public abstract Gee.HashMap<string,string>? entry_renderer_hints { get; set; }
			public abstract string entry_renderer_name { get; set; }
			public abstract Dee.Model? entry_results_model { get; set; }
			public abstract Dee.Model? global_groups_model { get; set; }
			public abstract Gee.HashMap<string,string>? global_renderer_hints { get; set; }
			public abstract string global_renderer_name { get; set; }
			public abstract Dee.Model? global_results_model { get; set; }
			public abstract Gee.HashMap<string,string> hints { get; set; }
			public abstract string icon { get; set construct; }
			public abstract string[] mimetypes { get; set; }
			public abstract string name { get; set construct; }
			public abstract bool online { get; set construct; }
			public abstract Unity.Places.Place? parent { get; set construct; }
			public abstract uint position { get; set; }
			public abstract Dee.Model? sections_model { get; set; }
			public abstract bool sensitive { get; set; }
			public signal void renderer_info_changed ();
			public signal void updated ();
		}
		[CCode (cprefix = "UNITY_PLACES_SECTION_STYLE_", cheader_filename = "unity-private.h")]
		public enum SectionStyle {
			BUTTONS,
			BREADCRUMB
		}
	}
	[CCode (cprefix = "UnityTesting", lower_case_cprefix = "unity_testing_")]
	namespace Testing {
		[CCode (cheader_filename = "unity-private.h")]
		public class Background : Ctk.Bin {
			public Background ();
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class Director : GLib.Object {
			public Director (Clutter.Stage stage);
			public void button_press (Clutter.Actor actor, uint32 button, bool autorelease, float relative_x, float relative_y, bool wait_for_animation);
			public void button_release (Clutter.Actor actor, uint32 button, float relative_x, float relative_y);
			public void do_wait_for_animation (Clutter.Actor actor);
			public void do_wait_for_timeout (uint32 msecs);
			public void enter_event (Clutter.Actor actor, float relative_x, float relative_y);
			public void leave_event (Clutter.Actor actor, float relative_x, float relative_y);
			public void motion_event (Clutter.Actor actor, float relative_startx, float relative_starty, float relative_endx, float relative_endy);
			public Clutter.Stage stage { get; construct; }
		}
		[CCode (ref_function = "unity_testing_logging_ref", unref_function = "unity_testing_logging_unref", cheader_filename = "unity-private.h")]
		public class Logging {
			public Logging ();
			public static bool fatal_handler (string? log_domain, GLib.LogLevelFlags flags, string? message);
			public static void init_fatal_handler ();
		}
		[CCode (ref_function = "unity_testing_object_registry_ref", unref_function = "unity_testing_object_registry_unref", cheader_filename = "unity-private.h")]
		public class ObjectRegistry {
			public ObjectRegistry ();
			public static Unity.Testing.ObjectRegistry get_default ();
			public Gee.ArrayList<GLib.Object> lookup (string name);
			public void register (string name, GLib.Object object);
		}
		[CCode (cheader_filename = "unity-private.h")]
		public class Window : Gtk.Window, Unity.Shell {
			public GtkClutter.Embed gtk_clutter;
			public Clutter.Stage stage;
			public Window (bool popup, int width, int height);
			public void init_test_mode ();
			public bool on_stage_button_press (Clutter.Event src);
			public override void show ();
			public void show_window_picker ();
			public bool is_popup { get; construct; }
			public int popup_height { get; construct; }
			public int popup_width { get; construct; }
		}
		[CCode (ref_function = "unity_testing_workarea_ref", unref_function = "unity_testing_workarea_unref", cheader_filename = "unity-private.h")]
		public class Workarea {
			public int bottom;
			public int left;
			public int right;
			public int top;
			public Workarea ();
			public void update_net_workarea ();
			public signal void workarea_changed ();
		}
	}
	[CCode (cheader_filename = "unity-private.h")]
	public class Application : Unique.App {
		public Application ();
		public Unique.Response on_message_received (int command, Unique.MessageData data, uint time_);
		public Unity.Shell? shell { get; set; }
	}
	[CCode (ref_function = "unity_process_info_ref", unref_function = "unity_process_info_unref", cheader_filename = "unity-private.h")]
	public class ProcessInfo {
		public double end;
		public string name;
		public double start;
		public ProcessInfo (string name);
	}
	[CCode (cheader_filename = "unity-private.h")]
	public class TimelineLogger : GLib.Object {
		public TimelineLogger ();
		public void end_process (string name);
		public static unowned Unity.TimelineLogger get_default ();
		public void start_process (string name);
		public void write_log (string filename);
	}
	[CCode (cprefix = "UNITY_APPLICATION_COMMANDS_", cheader_filename = "unity-private.h")]
	public enum ApplicationCommands {
		SHOW,
		MAKE_WEBAPP
	}
	[CCode (cheader_filename = "unity-private.h")]
	public static bool is_logging;
	[CCode (cheader_filename = "unity-private.h")]
	public static Unity.TimelineLogger? timeline_singleton;
	[CCode (cheader_filename = "unity-private.h")]
	public const string UNITY_CONF_PATH;
}
[CCode (cprefix = "Utils", lower_case_cprefix = "utils_")]
namespace Utils {
	[CCode (cheader_filename = "unity-private.h")]
	public static bool compare_snapshot (Clutter.Stage stage, string filename, int x, int y, int width, int height, bool expected = true);
	[CCode (cheader_filename = "unity-private.h")]
	public static X.Window get_stage_window (Clutter.Stage stage);
	[CCode (cheader_filename = "unity-private.h")]
	public static void register_object_on_dbus (DBus.Connection conn, string path, GLib.Object object);
	[CCode (cheader_filename = "unity-private.h")]
	public static bool save_snapshot (Clutter.Stage stage, string filename, int x, int y, int width, int height);
	[CCode (cheader_filename = "unity-private.h")]
	public static void set_strut (Gtk.Window* window, uint32 strut_size, uint32 strut_start, uint32 strut_end, uint32 top_size, uint32 top_start, uint32 top_end);
	[CCode (cheader_filename = "unity-private.h")]
	public static bool utils_compare_images (string img1_path, string img2_path);
	[CCode (cheader_filename = "unity-private.h")]
	public static bool window_is_decorated (uint32 xid);
	[CCode (cheader_filename = "unity-private.h")]
	public static void window_set_decorations (uint32 xid, uint decorations);
}
[CCode (cprefix = "G", lower_case_cprefix = "g_")]
namespace G {
	[CCode (cprefix = "GTest", lower_case_cprefix = "g_test_")]
	namespace Test {
		[CCode (ref_function = "g_test_log_ref", unref_function = "g_test_log_unref", cheader_filename = "unity-private.h")]
		public class Log {
			[CCode (cheader_filename = "unity-private.h")]
			public delegate bool LogFatalFunc (string? log_domain, GLib.LogLevelFlags flags, string? message);
			public Log ();
			public static void set_fatal_handler (G.Test.Log.LogFatalFunc func);
		}
	}
}
[CCode (cheader_filename = "unity-private.h")]
public class MenuManager : GLib.Object {
	public MenuManager ();
	public static MenuManager get_default ();
	public bool menu_is_open ();
	public void popdown_current_menu ();
	public void register_visible_menu (Gtk.Menu menu);
}
