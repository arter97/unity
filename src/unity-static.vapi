/* unity-static.vapi generated by valac, do not modify. */

[CCode (cprefix = "Unity", lower_case_cprefix = "unity_")]
namespace Unity {
	[CCode (cprefix = "UnityPanel", lower_case_cprefix = "unity_panel_")]
	namespace Panel {
		[CCode (cprefix = "UnityPanelIndicators", lower_case_cprefix = "unity_panel_indicators_")]
		namespace Indicators {
			[CCode (cheader_filename = "unity-static.h")]
			public class IndicatorEntry : Ctk.Box {
				public IndicatorEntry (Indicator.ObjectEntry entry);
				public void menu_key_moved (Gtk.MenuDirectionType type);
				public void menu_shown ();
				public void menu_vis_changed ();
				public Indicator.ObjectEntry entry { get; construct; }
				public Gtk.Menu menu { get; }
				public signal void menu_moved (Gtk.MenuDirectionType type);
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class IndicatorItem : Ctk.Box {
				public int position;
				public IndicatorItem ();
				public Indicator.Object get_object ();
				public void set_object (Indicator.Object object);
				public signal void menu_moved (Gtk.MenuDirectionType type);
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class View : Ctk.Box {
				public View ();
				public static int reorder_icons (Unity.Panel.Indicators.IndicatorItem a, Unity.Panel.Indicators.IndicatorItem b);
				public void show_entry (Unity.Panel.Indicators.IndicatorEntry entry);
			}
		}
		[CCode (cprefix = "UnityPanelTray", lower_case_cprefix = "unity_panel_tray_")]
		namespace Tray {
			[CCode (cheader_filename = "unity-static.h")]
			public class View : Ctk.Box {
				public View ();
				public void manage_stage (Clutter.Stage stage);
			}
		}
		[CCode (cheader_filename = "unity-static.h")]
		public class HomeButton : Ctk.Bin {
			public Unity.ThemeImage image;
			public HomeButton (Unity.Shell shell);
			public Unity.Shell shell { get; construct; }
			public signal void clicked (uint32 time_);
		}
		[CCode (cheader_filename = "unity-static.h")]
		public class View : Ctk.Actor {
			public View (Unity.Shell shell);
			public int get_indicators_width ();
			public void set_indicator_mode (bool mode);
			public Unity.Shell shell { get; construct; }
		}
		[CCode (cheader_filename = "unity-static.h")]
		public static bool? search_entry_has_focus;
	}
	[CCode (cprefix = "UnityPlaces", lower_case_cprefix = "unity_places_")]
	namespace Places {
		[CCode (cprefix = "UnityPlacesApplication", lower_case_cprefix = "unity_places_application_")]
		namespace Application {
			[CCode (cheader_filename = "unity-static.h")]
			public class ApplicationGroup : Ctk.Box {
				public int n_items;
				public ApplicationGroup (string group_name);
				public void add_icon (Unity.Places.Application.ApplicationIcon app);
				public override void allocate (Clutter.ActorBox box, Clutter.AllocationFlags flags);
				public override void get_preferred_height (float for_width, out float minimum_height, out float natural_height);
				public override void get_preferred_width (float for_height, out float minimum_width, out float natural_width);
				public bool on_maximize (Clutter.Event event);
				public bool on_minimize (Clutter.Event event);
			}
			[CCode (ref_function = "unity_places_application_application_icon_ref", unref_function = "unity_places_application_application_icon_unref", cheader_filename = "unity-static.h")]
			public class ApplicationIcon {
				public Ctk.Text label;
				public Ctk.Image view;
				public ApplicationIcon (int width, string name, string icon_name, string tooltip);
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class ApplicationView : Ctk.Box {
				public Unity.Places.Application.ApplicationGroup lastweek_app_group;
				public Unity.Places.Application.ApplicationGroup recent_app_group;
				public Unity.Places.Application.ApplicationGroup yesterday_app_group;
				public ApplicationView ();
				public override void allocate (Clutter.ActorBox box, Clutter.AllocationFlags flags);
			}
		}
		[CCode (cprefix = "UnityPlacesBar", lower_case_cprefix = "unity_places_bar_")]
		namespace Bar {
			[CCode (cheader_filename = "unity-static.h")]
			public class Model : GLib.Object {
				public string icon_name;
				public string name;
				public string tooltip;
				public Model (string name, string icon_name, string tooltip);
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class PlaceIcon : Ctk.Image {
				public PlaceIcon (int width, string name, string icon_name, string tooltip);
				public PlaceIcon.from_place (int size, Unity.Places.Place place);
				public Unity.Places.Place? place { get; set; }
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class View : Ctk.Box {
				public View (Unity.Places.Model model, Unity.Shell shell);
				public override void allocate (Clutter.ActorBox box, Clutter.AllocationFlags flags);
				public override void map ();
				public bool on_button_release (Clutter.Event event);
				public override void paint ();
				public override void unmap ();
				public Unity.Places.Model model { get; construct; }
				public Unity.Shell shell { get; construct; }
			}
		}
		[CCode (cprefix = "UnityPlacesCairoDrawing", lower_case_cprefix = "unity_places_cairo_drawing_")]
		namespace CairoDrawing {
			[CCode (cheader_filename = "unity-static.h")]
			public class EntryBackground : Ctk.Bin {
				public int Height;
				public int Width;
				public Clutter.CairoTexture cairotxt;
				public EntryBackground ();
				public void create_search_entry_background (int W, int H);
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class PlacesBackground : Ctk.Bin {
				[CCode (type_id = "UNITY_PLACES_CAIRO_DRAWING_PLACES_BACKGROUND_TYPE_TAB_RECT", cheader_filename = "unity-static.h")]
				public struct TabRect {
					public int left;
					public int right;
					public int top;
					public int bottom;
				}
				public int PlaceWidth;
				public Clutter.CairoTexture cairotxt;
				public PlacesBackground ();
				public void create_places_background (int WindowWidth, int WindowHeight, int TabPositionX, int TabWidth, int menu_width);
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class PlacesHSeparator : Ctk.Bin {
				public int Height;
				public int Width;
				public Clutter.CairoTexture cairotxt;
				public PlacesHSeparator ();
				public void CreateSeparator (int W, int H);
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class PlacesVSeparator : Ctk.Bin {
				public int Height;
				public int Width;
				public Clutter.CairoTexture cairotxt;
				public PlacesVSeparator ();
				public void CreateSeparator (int W, int H);
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class RectangleBox : Ctk.Bin {
				public int Height;
				public int Width;
				public Clutter.CairoTexture cairotxt;
				public RectangleBox ();
				public void CreateRectangleBox (int W, int H);
			}
		}
		[CCode (cprefix = "UnityPlacesDefault", lower_case_cprefix = "unity_places_default_")]
		namespace Default {
			[CCode (cheader_filename = "unity-static.h")]
			public class ActivityWidget : Ctk.Box {
				public ActivityWidget (int spacing, int size, string icon_name, string primary_text, string secondary_text);
				public bool on_clicked ();
				public bool on_enter ();
				public bool on_leave ();
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class Model : GLib.Object {
				public string icon_name;
				public string primary_text;
				public string secondary_text;
				public Model (string icon_name, string primary_text, string secondary_text);
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class View : Ctk.IconView {
				public View ();
				public override void allocate (Clutter.ActorBox box, Clutter.AllocationFlags flags);
			}
		}
		[CCode (cprefix = "UnityPlacesFile", lower_case_cprefix = "unity_places_file_")]
		namespace File {
			[CCode (cheader_filename = "unity-static.h")]
			public class FileGroup : Ctk.Box {
				public FileGroup (string group_name);
				public override void allocate (Clutter.ActorBox box, Clutter.AllocationFlags flags);
				public override void get_preferred_height (float for_width, out float minimum_height, out float natural_height);
				public override void get_preferred_width (float for_height, out float minimum_width, out float natural_width);
				public bool on_maximize (Clutter.Event event);
				public bool on_minimize (Clutter.Event event);
			}
			[CCode (ref_function = "unity_places_file_file_icon_ref", unref_function = "unity_places_file_file_icon_unref", cheader_filename = "unity-static.h")]
			public class FileIcon {
				public Ctk.Text label;
				public Ctk.Image view;
				public FileIcon (int width, string name, string icon_name, string tooltip);
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class FileView : Ctk.Box {
				public Unity.Places.File.FileGroup downloaded_file_group;
				public Unity.Places.File.FileGroup favourite_folder_group;
				public Unity.Places.File.FileGroup recent_file_group;
				public FileView ();
				public override void allocate (Clutter.ActorBox box, Clutter.AllocationFlags flags);
			}
		}
		[CCode (cprefix = "UnityPlacesSearchField", lower_case_cprefix = "unity_places_search_field_")]
		namespace SearchField {
			[CCode (cheader_filename = "unity-static.h")]
			public class View : Ctk.Box {
				public View ();
				public override void allocate (Clutter.ActorBox box, Clutter.AllocationFlags flags);
				public override void map ();
				public override void paint ();
				public override void unmap ();
			}
		}
		[CCode (cprefix = "UnityPlacesViews", lower_case_cprefix = "unity_places_views_")]
		namespace Views {
			[CCode (cheader_filename = "unity-static.h")]
			public class ResultsView : Ctk.Box, Unity.Places.PlaceView {
				public ResultsView ();
			}
		}
		[CCode (cheader_filename = "unity-static.h")]
		public class Controller : GLib.Object {
			public Controller (Unity.Shell shell);
			public Unity.Places.View get_view ();
			public void load_remote_places ();
			public Unity.Shell shell { get; construct; }
		}
		[CCode (cheader_filename = "unity-static.h")]
		public class Model : GLib.Object {
			public Gee.ArrayList<Unity.Places.Place> list;
			public Model ();
			public void add (Unity.Places.Place place);
			public void remove (Unity.Places.Place place);
			public signal void place_added (Unity.Places.Place place);
			public signal void place_changed (Unity.Places.Place place);
			public signal void place_removed (Unity.Places.Place place);
		}
		[CCode (cheader_filename = "unity-static.h")]
		public abstract class Place : GLib.Object {
			public Place (string name, string icon_name);
			public abstract Clutter.Actor get_view ();
			public bool active { get; set; }
			public string comment { get; construct; }
			public string icon_name { get; construct; }
			public string name { get; construct; }
			public signal void activated ();
		}
		[CCode (cheader_filename = "unity-static.h")]
		public class PlaceProxy : Unity.Places.Place {
			public PlaceProxy (string name, string icon_name, string comment, string dbus_name, string dbus_path);
			public override Clutter.Actor get_view ();
			public string dbus_name { get; construct; }
			public string dbus_path { get; construct; }
		}
		[CCode (cheader_filename = "unity-static.h")]
		public class View : Ctk.Box {
			public View (Unity.Places.Model model, Unity.Shell shell);
			public override void allocate (Clutter.ActorBox box, Clutter.AllocationFlags flags);
			public void set_content_view (Clutter.Actor actor);
			public Unity.Places.Model model { get; construct; }
			public Unity.Shell shell { get; construct; }
		}
		[CCode (cheader_filename = "unity-static.h")]
		public interface PlaceView : Clutter.Actor {
			public abstract void init_with_properties (GLib.HashTable<string,string> props);
		}
	}
	[CCode (cprefix = "UnityQuicklauncher", lower_case_cprefix = "unity_quicklauncher_")]
	namespace Quicklauncher {
		[CCode (cprefix = "UnityQuicklauncherModels", lower_case_cprefix = "unity_quicklauncher_models_")]
		namespace Models {
			[CCode (cheader_filename = "unity-static.h")]
			public class ApplicationModel : GLib.Object, Unity.Quicklauncher.Models.LauncherModel {
				public ApplicationModel (Launcher.Application application);
				public void do_save_priority ();
				public bool ensure_state ();
				public bool save_priority ();
				public Launcher.Application app { get; set; }
				public GLib.SList<Wnck.Window> windows { get; }
				public signal void windows_changed ();
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class ApplicationShortcut : GLib.Object, Unity.Quicklauncher.Models.ShortcutItem {
				public string desktop_location;
				public string exec;
				public string name;
				public ApplicationShortcut ();
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class LauncherPinningShortcut : GLib.Object, Unity.Quicklauncher.Models.ShortcutItem {
				public LauncherPinningShortcut (Unity.Quicklauncher.Models.ApplicationModel model);
				public Unity.Quicklauncher.Models.ApplicationModel app_model { get; construct; }
				public string name { get; }
			}
			[CCode (cheader_filename = "unity-static.h")]
			public class LibLauncherShortcut : GLib.Object, Unity.Quicklauncher.Models.ShortcutItem {
				public Launcher.Application app;
				public string name;
				public LibLauncherShortcut ();
			}
			[CCode (cheader_filename = "unity-static.h")]
			public interface LauncherModel : GLib.Object {
				public abstract void activate ();
				public abstract void close ();
				public abstract Gee.ArrayList<Unity.Quicklauncher.Models.ShortcutItem> get_menu_shortcut_actions ();
				public abstract Gee.ArrayList<Unity.Quicklauncher.Models.ShortcutItem> get_menu_shortcuts ();
				public abstract void regenerate_icon ();
				public abstract bool do_shadow { get; }
				public abstract Gdk.Pixbuf icon { get; }
				public abstract bool is_active { get; }
				public abstract bool is_fixed { get; }
				public abstract bool is_focused { get; }
				public abstract bool is_sticky { get; set; }
				public abstract bool is_urgent { get; }
				public abstract string name { get; }
				public abstract float priority { get; set; }
				public abstract bool readonly { get; }
				public abstract string uid { get; }
				public signal void activated ();
				public signal void notify_active ();
				public signal void notify_focused ();
				public signal void notify_icon ();
				public signal void request_attention ();
				public signal void urgent_changed ();
			}
			[CCode (cheader_filename = "unity-static.h")]
			public interface ShortcutItem : GLib.Object {
				public abstract void activated ();
				public abstract string get_name ();
			}
		}
		[CCode (cheader_filename = "unity-static.h")]
		public class LauncherView : Ctk.Actor, Unity.Drag.Model {
			public bool anim_priority_going_up;
			public Unity.Quicklauncher.Models.LauncherModel? model;
			public LauncherView (Unity.Quicklauncher.Models.LauncherModel model);
			public override void allocate (Clutter.ActorBox box, Clutter.AllocationFlags flags);
			public override void get_preferred_height (float for_width, out float minimum_height, out float natural_height);
			public override void get_preferred_width (float for_height, out float minimum_width, out float natural_width);
			public override void map ();
			public void notify_on_set_reactive ();
			public override void paint ();
			public override void pick (Clutter.Color color);
			public override void unmap ();
			public void update_window_struts (bool ignore_buffer);
			public Clutter.Animation anim { get; set; }
			public float anim_priority { get; set; }
			public bool is_hovering { get; set; }
			public int position { get; set; }
			public signal void clicked ();
			public signal void menu_closed (Unity.Quicklauncher.LauncherView sender);
			public signal void menu_opened (Unity.Quicklauncher.LauncherView sender);
			public signal void request_attention ();
			public signal void request_remove ();
		}
		[CCode (cheader_filename = "unity-static.h")]
		public class Manager : Ctk.Bin {
			public Manager ();
			public Unity.Quicklauncher.LauncherView active_launcher { get; set; }
			public signal void active_launcher_changed (Unity.Quicklauncher.LauncherView last, Unity.Quicklauncher.LauncherView current);
		}
		[CCode (cheader_filename = "unity-static.h")]
		public class QuicklistController : GLib.Object {
			public bool is_in_label;
			public bool is_in_menu;
			public weak Ctk.Menu menu;
			public QuicklistController ();
			public void close_menu ();
			public Ctk.Actor get_attached_actor ();
			public static unowned Unity.Quicklauncher.QuicklistController get_default ();
			public bool menu_is_open ();
			public void show_label (string label, Ctk.Actor attached_widget);
			public void show_menu (Gee.ArrayList<Unity.Quicklauncher.Models.ShortcutItem> prefix_shortcuts, Gee.ArrayList<Unity.Quicklauncher.Models.ShortcutItem> affix_shortcuts, bool hide_on_leave);
		}
		[CCode (cheader_filename = "unity-static.h")]
		public class QuicklistMenu : Ctk.Menu {
			public QuicklistMenu ();
			public override void paint ();
		}
		[CCode (cheader_filename = "unity-static.h")]
		public class QuicklistMenuItem : Ctk.Actor {
			public QuicklistMenuItem (string label);
			public override void get_preferred_height (float for_width, out float min_height_p, out float natural_height_p);
			public override void get_preferred_width (float for_height, out float min_width_p, out float natural_width_p);
			public string label { get; construct; }
			public signal void activated ();
		}
		[CCode (cheader_filename = "unity-static.h")]
		public class QuicklistMenuSeperator : Ctk.MenuSeperator {
			public QuicklistMenuSeperator ();
			public override void get_preferred_height (float for_width, out float min_height_p, out float natural_height_p);
			public override void get_preferred_width (float for_height, out float min_width_p, out float natural_width_p);
		}
		[CCode (cheader_filename = "unity-static.h")]
		public class View : Ctk.Bin {
			public Unity.Quicklauncher.Manager manager;
			public View (Unity.Shell shell);
			public float get_width ();
		}
		[CCode (cheader_filename = "unity-static.h")]
		public static Unity.Quicklauncher.QuicklistController? ql_controler_singleton;
	}
	[CCode (cprefix = "UnityWidgets", lower_case_cprefix = "unity_widgets_")]
	namespace Widgets {
		[CCode (cheader_filename = "unity-static.h")]
		public class Scroller : Ctk.Actor, Clutter.Container {
			public bool order_changed;
			public Scroller (Ctk.Orientation orientation, int spacing);
			public void add_actor (Clutter.Actor actor, bool is_fixed);
			public override void allocate (Clutter.ActorBox box, Clutter.AllocationFlags flags);
			public override void get_preferred_height (float for_width, out float minimum_height, out float natural_height);
			public override void get_preferred_width (float for_height, out float minimum_width, out float natural_width);
			public override void paint ();
			public override void pick (Clutter.Color color);
			public void remove_actor (Clutter.Actor actor_);
			public float drag_pos { get; set; }
			public int spacing { get; set; }
		}
		[CCode (cheader_filename = "unity-static.h")]
		public class ScrollerChild : GLib.Object {
			public Clutter.ActorBox box;
			public Clutter.Actor child;
			public float height;
			public float position;
			public Unity.Widgets.ScrollerChildState state;
			public float width;
			public ScrollerChild ();
			public bool is_hidden { get; set; }
		}
		[CCode (cprefix = "UNITY_WIDGETS_SCROLLER_CHILD_STATE_", cheader_filename = "unity-static.h")]
		public enum ScrollerChildState {
			NORMAL,
			HIDDEN,
			REMOVED
		}
	}
	[CCode (cheader_filename = "unity-static.h")]
	public class Background : Ctk.Bin {
		public Background ();
	}
	[CCode (cheader_filename = "unity-static.h")]
	public class UnderlayWindow : Gtk.Window, Unity.Shell {
		public UnderlayWindow (bool popup, int width, int height);
		public void on_active_window_changed (Wnck.Window? previous_window);
		public bool on_stage_button_press (Clutter.Event src);
		public override void show ();
		public bool is_popup { get; construct; }
		public int popup_height { get; construct; }
		public int popup_width { get; construct; }
	}
	[CCode (ref_function = "unity_workarea_ref", unref_function = "unity_workarea_unref", cheader_filename = "unity-static.h")]
	public class Workarea {
		public int bottom;
		public int left;
		public int right;
		public int top;
		public Workarea ();
		public void update_net_workarea ();
		public signal void workarea_changed ();
	}
	[CCode (cheader_filename = "unity-static.h")]
	public const string UNITY_CONF_PATH;
}
[CCode (cprefix = "Utils", lower_case_cprefix = "utils_")]
namespace Utils {
	[CCode (cheader_filename = "unity-static.h")]
	public static X.Window get_stage_window (Clutter.Stage stage);
	[CCode (cheader_filename = "unity-static.h")]
	public static void register_object_on_dbus (DBus.Connection conn, string path, GLib.Object object);
	[CCode (cheader_filename = "unity-static.h")]
	public static void set_strut (Gtk.Window* window, uint32 strut_size, uint32 strut_start, uint32 strut_end, uint32 top_size, uint32 top_start, uint32 top_end);
}
