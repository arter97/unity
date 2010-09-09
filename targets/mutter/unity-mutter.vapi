/* unity-mutter.vapi generated by valac, do not modify. */

[CCode (cprefix = "Unity", lower_case_cprefix = "unity_")]
namespace Unity {
	[CCode (cheader_filename = "unity-mutter.h")]
	public class DragDest : Gtk.Window {
		public DragDest ();
	}
	[CCode (cheader_filename = "unity-mutter.h")]
	public class ExposeClone : Clutter.Group {
		public ExposeClone (Clutter.Actor source);
		public void restore_window_position (int active_workspace);
		public uint8 darken { get; set; }
		public bool enable_dnd { get; set; }
		public bool fade_on_close { get; set; }
		public uint8 hovered_opacity { get; set; }
		public Clutter.Actor pre_drag_parent { get; }
		public float pre_drag_scale_x { get; set; }
		public float pre_drag_scale_y { get; set; }
		public Clutter.Actor source { get; set; }
		public uint8 unhovered_opacity { get; set; }
		public signal void drag_dropped (Clutter.Actor onto);
	}
	[CCode (cheader_filename = "unity-mutter.h")]
	public class ExposeManager : GLib.Object {
		public GLib.List<Unity.ExposeClone> exposed_windows;
		public ExposeManager (Unity.Plugin plugin, Unity.Launcher.Launcher launcher);
		public void end_expose ();
		public void position_windows_on_grid (GLib.List<Clutter.Actor> _windows, int top_buffer, int left_buffer, int right_buffer, int bottom_buffer);
		public void start_expose (GLib.SList<Clutter.Actor> windows);
		public int bottom_buffer { get; set; }
		public bool coverflow { get; set; }
		public uint8 darken { get; set; }
		public bool expose_showing { get; set; }
		public uint8 hovered_opacity { get; set; }
		public int left_buffer { get; set; }
		public int right_buffer { get; set; }
		public int top_buffer { get; set; }
		public uint8 unhovered_opacity { get; set; }
	}
	[CCode (cheader_filename = "unity-mutter.h")]
	public class Maximus : GLib.Object {
		public static string user_unmaximize_hint;
		public Maximus ();
		public bool process_window (Mutter.Window window);
	}
	[CCode (cheader_filename = "unity-mutter.h")]
	public class Plugin : GLib.Object, Unity.Shell {
		public Unity.Gesture.Dispatcher gesture_dispatcher;
		public Plugin ();
		public void destroy (Mutter.Window window);
		public void expose_windows (GLib.SList<Clutter.Actor> windows, int left_buffer = 75);
		public int get_launcher_width ();
		public int get_panel_height ();
		public void map (Mutter.Window window);
		public void maximize (Mutter.Window window, int x, int y, int width, int height);
		public void minimize (Mutter.Window window);
		public void on_kill_switch_workspace ();
		public void on_kill_window_effects (Mutter.Window window);
		public void switch_workspace (int from, int to, int direction);
		public void unmaximize (Mutter.Window window, int x, int y, int width, int height);
		public Unity.Testing.Background background { get; set; }
		public Unity.ExposeManager expose_manager { get; set; }
		public bool expose_showing { get; }
		public Mutter.Plugin? plugin { get; set; }
		public signal void kill_switch_workspace (Unity.Plugin plugin);
		public signal void kill_window_effects (Unity.Plugin plugin, Mutter.Window window);
		public signal void restore_input_region (bool fullscreen);
		public signal void window_destroyed (Unity.Plugin plugin, Mutter.Window window);
		public signal void window_mapped (Unity.Plugin plugin, Mutter.Window window);
		public signal void window_maximized (Unity.Plugin plugin, Mutter.Window window, int x, int y, int width, int height);
		public signal void window_minimized (Unity.Plugin plugin, Mutter.Window window);
		public signal void window_unmaximized (Unity.Plugin plugin, Mutter.Window window, int x, int y, int width, int height);
		public signal void workspace_switch_event (Unity.Plugin plugin, int from, int to, int direction);
	}
	[CCode (cheader_filename = "unity-mutter.h")]
	public class SpacesButtonController : Unity.Launcher.ScrollerChildController {
		public SpacesButtonController (Unity.SpacesManager _parent, Unity.Launcher.ScrollerChild _child);
		public override void activate ();
		public override bool can_drag ();
		public override void get_menu_actions (Unity.Launcher.ScrollerChildController.menu_cb callback);
		public override Unity.Launcher.QuicklistController? get_menu_controller ();
		public override void get_menu_navigation (Unity.Launcher.ScrollerChildController.menu_cb callback);
	}
	[CCode (cheader_filename = "unity-mutter.h")]
	public class SpacesManager : GLib.Object {
		public SpacesManager (Unity.Plugin plugin);
		public void hide_spaces_picker ();
		public void set_padding (uint top, uint right, uint left, uint bottom);
		public void show_spaces_picker ();
		public uint bottom_padding { get; set; }
		public Unity.Launcher.ScrollerChild button { get; }
		public uint left_padding { get; set; }
		public uint right_padding { get; set; }
		public bool showing { get; set; }
		public uint spacing { get; set; }
		public uint top_padding { get; set; }
	}
	[CCode (cheader_filename = "unity-mutter.h")]
	public class WindowManagement : GLib.Object {
		public WindowManagement (Unity.Plugin p);
	}
	[CCode (cheader_filename = "unity-mutter.h")]
	public class WorkspaceClone : Clutter.Group {
		public WorkspaceClone (Mutter.MetaWorkspace wsp, Unity.Plugin plugin);
		public void grid ();
		public void ungrid ();
		public Mutter.MetaWorkspace workspace { get; set; }
	}
	[CCode (cprefix = "UNITY_INPUT_STATE_", cheader_filename = "unity-mutter.h")]
	public enum InputState {
		NONE,
		FULLSCREEN,
		UNITY,
		ZERO
	}
}
