/* unity-mutter.h generated by valac, the Vala compiler, do not modify */


#ifndef __UNITY_MUTTER_H__
#define __UNITY_MUTTER_H__

#include <glib.h>
#include <gtk/gtk.h>
#include <clutk/clutk.h>
#include <clutter/clutter.h>
#include <glib-object.h>
#include <unity.h>
#include <libwnck/libwnck.h>
#include <mutter-plugins.h>

G_BEGIN_DECLS


#define UNITY_TYPE_DRAG_DEST (unity_drag_dest_get_type ())
#define UNITY_DRAG_DEST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_DRAG_DEST, UnityDragDest))
#define UNITY_DRAG_DEST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_DRAG_DEST, UnityDragDestClass))
#define UNITY_IS_DRAG_DEST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_DRAG_DEST))
#define UNITY_IS_DRAG_DEST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_DRAG_DEST))
#define UNITY_DRAG_DEST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_DRAG_DEST, UnityDragDestClass))

typedef struct _UnityDragDest UnityDragDest;
typedef struct _UnityDragDestClass UnityDragDestClass;
typedef struct _UnityDragDestPrivate UnityDragDestPrivate;

#define UNITY_TYPE_INPUT_STATE (unity_input_state_get_type ())

#define UNITY_TYPE_ACTOR_BLUR (unity_actor_blur_get_type ())
#define UNITY_ACTOR_BLUR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_ACTOR_BLUR, UnityActorBlur))
#define UNITY_ACTOR_BLUR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_ACTOR_BLUR, UnityActorBlurClass))
#define UNITY_IS_ACTOR_BLUR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_ACTOR_BLUR))
#define UNITY_IS_ACTOR_BLUR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_ACTOR_BLUR))
#define UNITY_ACTOR_BLUR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_ACTOR_BLUR, UnityActorBlurClass))

typedef struct _UnityActorBlur UnityActorBlur;
typedef struct _UnityActorBlurClass UnityActorBlurClass;
typedef struct _UnityActorBlurPrivate UnityActorBlurPrivate;

#define UNITY_TYPE_PLUGIN (unity_plugin_get_type ())
#define UNITY_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_PLUGIN, UnityPlugin))
#define UNITY_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_PLUGIN, UnityPluginClass))
#define UNITY_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_PLUGIN))
#define UNITY_IS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_PLUGIN))
#define UNITY_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_PLUGIN, UnityPluginClass))

typedef struct _UnityPlugin UnityPlugin;
typedef struct _UnityPluginClass UnityPluginClass;
typedef struct _UnityPluginPrivate UnityPluginPrivate;

#define UNITY_TYPE_WINDOW_MANAGEMENT (unity_window_management_get_type ())
#define UNITY_WINDOW_MANAGEMENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_WINDOW_MANAGEMENT, UnityWindowManagement))
#define UNITY_WINDOW_MANAGEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_WINDOW_MANAGEMENT, UnityWindowManagementClass))
#define UNITY_IS_WINDOW_MANAGEMENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_WINDOW_MANAGEMENT))
#define UNITY_IS_WINDOW_MANAGEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_WINDOW_MANAGEMENT))
#define UNITY_WINDOW_MANAGEMENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_WINDOW_MANAGEMENT, UnityWindowManagementClass))

typedef struct _UnityWindowManagement UnityWindowManagement;
typedef struct _UnityWindowManagementClass UnityWindowManagementClass;
typedef struct _UnityWindowManagementPrivate UnityWindowManagementPrivate;

struct _UnityDragDest {
	GtkWindow parent_instance;
	UnityDragDestPrivate * priv;
};

struct _UnityDragDestClass {
	GtkWindowClass parent_class;
};

typedef enum  {
	UNITY_INPUT_STATE_NONE,
	UNITY_INPUT_STATE_FULLSCREEN,
	UNITY_INPUT_STATE_UNITY,
	UNITY_INPUT_STATE_ZERO
} UnityInputState;

struct _UnityActorBlur {
	CtkBin parent_instance;
	UnityActorBlurPrivate * priv;
};

struct _UnityActorBlurClass {
	CtkBinClass parent_class;
};

struct _UnityPlugin {
	GObject parent_instance;
	UnityPluginPrivate * priv;
};

struct _UnityPluginClass {
	GObjectClass parent_class;
};

struct _UnityWindowManagement {
	GObject parent_instance;
	UnityWindowManagementPrivate * priv;
};

struct _UnityWindowManagementClass {
	GObjectClass parent_class;
};


GType unity_drag_dest_get_type (void);
UnityDragDest* unity_drag_dest_new (void);
UnityDragDest* unity_drag_dest_construct (GType object_type);
GType unity_input_state_get_type (void);
GType unity_actor_blur_get_type (void);
UnityActorBlur* unity_actor_blur_new (ClutterActor* actor);
UnityActorBlur* unity_actor_blur_construct (GType object_type, ClutterActor* actor);
GType unity_plugin_get_type (void);
void unity_plugin_expose_windows (UnityPlugin* self, GSList* windows, gint left_buffer);
void unity_plugin_minimize (UnityPlugin* self, MutterWindow* window);
void unity_plugin_maximize (UnityPlugin* self, MutterWindow* window, gint x, gint y, gint width, gint height);
void unity_plugin_unmaximize (UnityPlugin* self, MutterWindow* window, gint x, gint y, gint width, gint height);
void unity_plugin_map (UnityPlugin* self, MutterWindow* window);
void unity_plugin_destroy (UnityPlugin* self, MutterWindow* window);
void unity_plugin_switch_workspace (UnityPlugin* self, GList* windows, gint from, gint to, gint direction);
void unity_plugin_kill_effect (UnityPlugin* self, MutterWindow* window, gulong events);
gint unity_plugin_get_panel_height (UnityPlugin* self);
gint unity_plugin_get_launcher_width (UnityPlugin* self);
UnityPlugin* unity_plugin_new (void);
UnityPlugin* unity_plugin_construct (GType object_type);
MutterPlugin* unity_plugin_get_plugin (UnityPlugin* self);
void unity_plugin_set_plugin (UnityPlugin* self, MutterPlugin* value);
gboolean unity_plugin_get_expose_showing (UnityPlugin* self);
GType unity_window_management_get_type (void);
UnityWindowManagement* unity_window_management_new (UnityPlugin* p);
UnityWindowManagement* unity_window_management_construct (GType object_type, UnityPlugin* p);


G_END_DECLS

#endif
