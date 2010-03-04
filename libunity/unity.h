/* unity.h generated by valac, the Vala compiler, do not modify */


#ifndef __UNITY_H__
#define __UNITY_H__

#include <glib.h>
#include <unique/unique.h>
#include <glib-object.h>
#include <clutter/clutter.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <clutk/clutk.h>
#include <gdk-pixbuf/gdk-pixdata.h>
#include <gio/gio.h>

G_BEGIN_DECLS


#define UNITY_TYPE_APPLICATION_COMMANDS (unity_application_commands_get_type ())

#define UNITY_TYPE_APPLICATION (unity_application_get_type ())
#define UNITY_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_APPLICATION, UnityApplication))
#define UNITY_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_APPLICATION, UnityApplicationClass))
#define UNITY_IS_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_APPLICATION))
#define UNITY_IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_APPLICATION))
#define UNITY_APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_APPLICATION, UnityApplicationClass))

typedef struct _UnityApplication UnityApplication;
typedef struct _UnityApplicationClass UnityApplicationClass;
typedef struct _UnityApplicationPrivate UnityApplicationPrivate;

#define UNITY_TYPE_SHELL (unity_shell_get_type ())
#define UNITY_SHELL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_SHELL, UnityShell))
#define UNITY_IS_SHELL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_SHELL))
#define UNITY_SHELL_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_TYPE_SHELL, UnityShellIface))

typedef struct _UnityShell UnityShell;
typedef struct _UnityShellIface UnityShellIface;

#define UNITY_TYPE_SHELL_MODE (unity_shell_mode_get_type ())

#define UNITY_WEBAPP_TYPE_CHROMIUM_WEB_APP (unity_webapp_chromium_web_app_get_type ())
#define UNITY_WEBAPP_CHROMIUM_WEB_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_WEBAPP_TYPE_CHROMIUM_WEB_APP, UnityWebappChromiumWebApp))
#define UNITY_WEBAPP_CHROMIUM_WEB_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_WEBAPP_TYPE_CHROMIUM_WEB_APP, UnityWebappChromiumWebAppClass))
#define UNITY_WEBAPP_IS_CHROMIUM_WEB_APP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_WEBAPP_TYPE_CHROMIUM_WEB_APP))
#define UNITY_WEBAPP_IS_CHROMIUM_WEB_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_WEBAPP_TYPE_CHROMIUM_WEB_APP))
#define UNITY_WEBAPP_CHROMIUM_WEB_APP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_WEBAPP_TYPE_CHROMIUM_WEB_APP, UnityWebappChromiumWebAppClass))

typedef struct _UnityWebappChromiumWebApp UnityWebappChromiumWebApp;
typedef struct _UnityWebappChromiumWebAppClass UnityWebappChromiumWebAppClass;
typedef struct _UnityWebappChromiumWebAppPrivate UnityWebappChromiumWebAppPrivate;

#define UNITY_DRAG_TYPE_MODEL (unity_drag_model_get_type ())
#define UNITY_DRAG_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_DRAG_TYPE_MODEL, UnityDragModel))
#define UNITY_DRAG_IS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_DRAG_TYPE_MODEL))
#define UNITY_DRAG_MODEL_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_DRAG_TYPE_MODEL, UnityDragModelIface))

typedef struct _UnityDragModel UnityDragModel;
typedef struct _UnityDragModelIface UnityDragModelIface;

#define UNITY_DRAG_TYPE_CONTROLLER (unity_drag_controller_get_type ())
#define UNITY_DRAG_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_DRAG_TYPE_CONTROLLER, UnityDragController))
#define UNITY_DRAG_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_DRAG_TYPE_CONTROLLER, UnityDragControllerClass))
#define UNITY_DRAG_IS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_DRAG_TYPE_CONTROLLER))
#define UNITY_DRAG_IS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_DRAG_TYPE_CONTROLLER))
#define UNITY_DRAG_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_DRAG_TYPE_CONTROLLER, UnityDragControllerClass))

typedef struct _UnityDragController UnityDragController;
typedef struct _UnityDragControllerClass UnityDragControllerClass;
typedef struct _UnityDragControllerPrivate UnityDragControllerPrivate;

#define UNITY_TYPE_ENTRY (unity_entry_get_type ())
#define UNITY_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_ENTRY, UnityEntry))
#define UNITY_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_ENTRY, UnityEntryClass))
#define UNITY_IS_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_ENTRY))
#define UNITY_IS_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_ENTRY))
#define UNITY_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_ENTRY, UnityEntryClass))

typedef struct _UnityEntry UnityEntry;
typedef struct _UnityEntryClass UnityEntryClass;
typedef struct _UnityEntryPrivate UnityEntryPrivate;

#define UNITY_TYPE_PROCESS_INFO (unity_process_info_get_type ())
#define UNITY_PROCESS_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_PROCESS_INFO, UnityProcessInfo))
#define UNITY_PROCESS_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_PROCESS_INFO, UnityProcessInfoClass))
#define UNITY_IS_PROCESS_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_PROCESS_INFO))
#define UNITY_IS_PROCESS_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_PROCESS_INFO))
#define UNITY_PROCESS_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_PROCESS_INFO, UnityProcessInfoClass))

typedef struct _UnityProcessInfo UnityProcessInfo;
typedef struct _UnityProcessInfoClass UnityProcessInfoClass;
typedef struct _UnityProcessInfoPrivate UnityProcessInfoPrivate;

#define UNITY_TYPE_TIMELINE_LOGGER (unity_timeline_logger_get_type ())
#define UNITY_TIMELINE_LOGGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_TIMELINE_LOGGER, UnityTimelineLogger))
#define UNITY_TIMELINE_LOGGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_TIMELINE_LOGGER, UnityTimelineLoggerClass))
#define UNITY_IS_TIMELINE_LOGGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_TIMELINE_LOGGER))
#define UNITY_IS_TIMELINE_LOGGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_TIMELINE_LOGGER))
#define UNITY_TIMELINE_LOGGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_TIMELINE_LOGGER, UnityTimelineLoggerClass))

typedef struct _UnityTimelineLogger UnityTimelineLogger;
typedef struct _UnityTimelineLoggerClass UnityTimelineLoggerClass;
typedef struct _UnityTimelineLoggerPrivate UnityTimelineLoggerPrivate;

#define UNITY_WEBAPP_TYPE_PRISM (unity_webapp_prism_get_type ())
#define UNITY_WEBAPP_PRISM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_WEBAPP_TYPE_PRISM, UnityWebappPrism))
#define UNITY_WEBAPP_PRISM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_WEBAPP_TYPE_PRISM, UnityWebappPrismClass))
#define UNITY_WEBAPP_IS_PRISM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_WEBAPP_TYPE_PRISM))
#define UNITY_WEBAPP_IS_PRISM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_WEBAPP_TYPE_PRISM))
#define UNITY_WEBAPP_PRISM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_WEBAPP_TYPE_PRISM, UnityWebappPrismClass))

typedef struct _UnityWebappPrism UnityWebappPrism;
typedef struct _UnityWebappPrismClass UnityWebappPrismClass;
typedef struct _UnityWebappPrismPrivate UnityWebappPrismPrivate;

#define UNITY_TYPE_DND_TARGETS (unity_dnd_targets_get_type ())

#define UNITY_TYPE_THEME_IMAGE (unity_theme_image_get_type ())
#define UNITY_THEME_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_THEME_IMAGE, UnityThemeImage))
#define UNITY_THEME_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_THEME_IMAGE, UnityThemeImageClass))
#define UNITY_IS_THEME_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_THEME_IMAGE))
#define UNITY_IS_THEME_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_THEME_IMAGE))
#define UNITY_THEME_IMAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_THEME_IMAGE, UnityThemeImageClass))

typedef struct _UnityThemeImage UnityThemeImage;
typedef struct _UnityThemeImageClass UnityThemeImageClass;
typedef struct _UnityThemeImagePrivate UnityThemeImagePrivate;

#define UNITY_WEBAPP_TYPE_FETCH_FILE (unity_webapp_fetch_file_get_type ())
#define UNITY_WEBAPP_FETCH_FILE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_WEBAPP_TYPE_FETCH_FILE, UnityWebappFetchFile))
#define UNITY_WEBAPP_FETCH_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_WEBAPP_TYPE_FETCH_FILE, UnityWebappFetchFileClass))
#define UNITY_WEBAPP_IS_FETCH_FILE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_WEBAPP_TYPE_FETCH_FILE))
#define UNITY_WEBAPP_IS_FETCH_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_WEBAPP_TYPE_FETCH_FILE))
#define UNITY_WEBAPP_FETCH_FILE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_WEBAPP_TYPE_FETCH_FILE, UnityWebappFetchFileClass))

typedef struct _UnityWebappFetchFile UnityWebappFetchFile;
typedef struct _UnityWebappFetchFileClass UnityWebappFetchFileClass;
typedef struct _UnityWebappFetchFilePrivate UnityWebappFetchFilePrivate;

#define UNITY_WEBAPP_TYPE_WEBICON_FETCHER (unity_webapp_webicon_fetcher_get_type ())
#define UNITY_WEBAPP_WEBICON_FETCHER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_WEBAPP_TYPE_WEBICON_FETCHER, UnityWebappWebiconFetcher))
#define UNITY_WEBAPP_WEBICON_FETCHER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_WEBAPP_TYPE_WEBICON_FETCHER, UnityWebappWebiconFetcherClass))
#define UNITY_WEBAPP_IS_WEBICON_FETCHER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_WEBAPP_TYPE_WEBICON_FETCHER))
#define UNITY_WEBAPP_IS_WEBICON_FETCHER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_WEBAPP_TYPE_WEBICON_FETCHER))
#define UNITY_WEBAPP_WEBICON_FETCHER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_WEBAPP_TYPE_WEBICON_FETCHER, UnityWebappWebiconFetcherClass))

typedef struct _UnityWebappWebiconFetcher UnityWebappWebiconFetcher;
typedef struct _UnityWebappWebiconFetcherClass UnityWebappWebiconFetcherClass;
typedef struct _UnityWebappWebiconFetcherPrivate UnityWebappWebiconFetcherPrivate;

#define UNITY_WEBAPP_TYPE_ICON_BUILDER (unity_webapp_icon_builder_get_type ())
#define UNITY_WEBAPP_ICON_BUILDER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_WEBAPP_TYPE_ICON_BUILDER, UnityWebappIconBuilder))
#define UNITY_WEBAPP_ICON_BUILDER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_WEBAPP_TYPE_ICON_BUILDER, UnityWebappIconBuilderClass))
#define UNITY_WEBAPP_IS_ICON_BUILDER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_WEBAPP_TYPE_ICON_BUILDER))
#define UNITY_WEBAPP_IS_ICON_BUILDER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_WEBAPP_TYPE_ICON_BUILDER))
#define UNITY_WEBAPP_ICON_BUILDER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_WEBAPP_TYPE_ICON_BUILDER, UnityWebappIconBuilderClass))

typedef struct _UnityWebappIconBuilder UnityWebappIconBuilder;
typedef struct _UnityWebappIconBuilderClass UnityWebappIconBuilderClass;
typedef struct _UnityWebappIconBuilderPrivate UnityWebappIconBuilderPrivate;

typedef enum  {
	UNITY_APPLICATION_COMMANDS_SHOW = 1,
	UNITY_APPLICATION_COMMANDS_MAKE_WEBAPP
} UnityApplicationCommands;

struct _UnityApplication {
	UniqueApp parent_instance;
	UnityApplicationPrivate * priv;
};

struct _UnityApplicationClass {
	UniqueAppClass parent_class;
};

typedef enum  {
	UNITY_SHELL_MODE_UNDERLAY,
	UNITY_SHELL_MODE_OVERLAY
} UnityShellMode;

struct _UnityShellIface {
	GTypeInterface parent_iface;
	UnityShellMode (*get_mode) (UnityShell* self);
	ClutterStage* (*get_stage) (UnityShell* self);
	void (*show_unity) (UnityShell* self);
	gint (*get_indicators_width) (UnityShell* self);
	void (*ensure_input_region) (UnityShell* self);
	void (*add_fullscreen_request) (UnityShell* self, GObject* o);
	gboolean (*remove_fullscreen_request) (UnityShell* self, GObject* o);
	void (*grab_keyboard) (UnityShell* self, gboolean grab, guint32 timestamp);
	void (*show_window_picker) (UnityShell* self);
	gboolean (*get_menus_swallow_events) (UnityShell* self);
};

struct _UnityWebappChromiumWebApp {
	GObject parent_instance;
	UnityWebappChromiumWebAppPrivate * priv;
	char* name;
	char* id;
};

struct _UnityWebappChromiumWebAppClass {
	GObjectClass parent_class;
};

struct _UnityDragModelIface {
	GTypeInterface parent_iface;
	ClutterActor* (*get_icon) (UnityDragModel* self);
	char* (*get_drag_data) (UnityDragModel* self);
};

struct _UnityDragController {
	GObject parent_instance;
	UnityDragControllerPrivate * priv;
};

struct _UnityDragControllerClass {
	GObjectClass parent_class;
};

struct _UnityEntry {
	CtkText parent_instance;
	UnityEntryPrivate * priv;
};

struct _UnityEntryClass {
	CtkTextClass parent_class;
};

struct _UnityProcessInfo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	UnityProcessInfoPrivate * priv;
	char* name;
	double start;
	double end;
};

struct _UnityProcessInfoClass {
	GTypeClass parent_class;
	void (*finalize) (UnityProcessInfo *self);
};

struct _UnityTimelineLogger {
	GObject parent_instance;
	UnityTimelineLoggerPrivate * priv;
};

struct _UnityTimelineLoggerClass {
	GObjectClass parent_class;
};

struct _UnityWebappPrism {
	GObject parent_instance;
	UnityWebappPrismPrivate * priv;
	char* name;
	char* id;
};

struct _UnityWebappPrismClass {
	GObjectClass parent_class;
};

typedef enum  {
	UNITY_DND_TARGETS_TARGET_INT32,
	UNITY_DND_TARGETS_TARGET_STRING,
	UNITY_DND_TARGETS_TARGET_URL,
	UNITY_DND_TARGETS_TARGET_OTHER
} Unitydnd_targets;

struct _UnityThemeImage {
	ClutterTexture parent_instance;
	UnityThemeImagePrivate * priv;
	GdkPixbuf* icon;
};

struct _UnityThemeImageClass {
	ClutterTextureClass parent_class;
};

struct _UnityWebappFetchFile {
	GObject parent_instance;
	UnityWebappFetchFilePrivate * priv;
};

struct _UnityWebappFetchFileClass {
	GObjectClass parent_class;
};

struct _UnityWebappWebiconFetcher {
	GObject parent_instance;
	UnityWebappWebiconFetcherPrivate * priv;
};

struct _UnityWebappWebiconFetcherClass {
	GObjectClass parent_class;
};

struct _UnityWebappIconBuilder {
	GObject parent_instance;
	UnityWebappIconBuilderPrivate * priv;
};

struct _UnityWebappIconBuilderClass {
	GObjectClass parent_class;
};


GType unity_application_commands_get_type (void);
GType unity_application_get_type (void);
UnityApplication* unity_application_new (void);
UnityApplication* unity_application_construct (GType object_type);
UniqueResponse unity_application_on_message_received (UnityApplication* self, gint command, UniqueMessageData* data, guint time_);
GType unity_shell_mode_get_type (void);
GType unity_shell_get_type (void);
UnityShell* unity_application_get_shell (UnityApplication* self);
void unity_application_set_shell (UnityApplication* self, UnityShell* value);
GType unity_webapp_chromium_web_app_get_type (void);
UnityWebappChromiumWebApp* unity_webapp_chromium_web_app_new (const char* address, const char* icon);
UnityWebappChromiumWebApp* unity_webapp_chromium_web_app_construct (GType object_type, const char* address, const char* icon);
char* unity_webapp_chromium_web_app_desktop_file_path (UnityWebappChromiumWebApp* self);
void unity_webapp_chromium_web_app_add_to_favorites (UnityWebappChromiumWebApp* self);
const char* unity_webapp_chromium_web_app_get_url (UnityWebappChromiumWebApp* self);
const char* unity_webapp_chromium_web_app_get_icon (UnityWebappChromiumWebApp* self);
GType unity_drag_model_get_type (void);
ClutterActor* unity_drag_model_get_icon (UnityDragModel* self);
char* unity_drag_model_get_drag_data (UnityDragModel* self);
GType unity_drag_controller_get_type (void);
extern UnityDragController* unity_drag_controller_singleton;
UnityDragController* unity_drag_controller_get_default (void);
void unity_drag_controller_start_drag (UnityDragController* self, UnityDragModel* model, float offset_x, float offset_y);
UnityDragController* unity_drag_controller_new (void);
UnityDragController* unity_drag_controller_construct (GType object_type);
gboolean unity_drag_controller_get_is_dragging (UnityDragController* self);
GType unity_entry_get_type (void);
UnityEntry* unity_entry_new (const char* static_text);
UnityEntry* unity_entry_construct (GType object_type, const char* static_text);
const char* unity_entry_get_static_text (UnityEntry* self);
void unity_entry_set_static_text (UnityEntry* self, const char* value);
gpointer unity_process_info_ref (gpointer instance);
void unity_process_info_unref (gpointer instance);
GParamSpec* unity_param_spec_process_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_value_set_process_info (GValue* value, gpointer v_object);
gpointer unity_value_get_process_info (const GValue* value);
GType unity_process_info_get_type (void);
UnityProcessInfo* unity_process_info_new (const char* name);
UnityProcessInfo* unity_process_info_construct (GType object_type, const char* name);
GType unity_timeline_logger_get_type (void);
extern UnityTimelineLogger* unity_timeline_singleton;
extern gboolean unity_is_logging;
UnityTimelineLogger* unity_timeline_logger_get_default (void);
void unity_timeline_logger_start_process (UnityTimelineLogger* self, const char* name);
void unity_timeline_logger_end_process (UnityTimelineLogger* self, const char* name);
void unity_timeline_logger_write_log (UnityTimelineLogger* self, const char* filename);
UnityTimelineLogger* unity_timeline_logger_new (void);
UnityTimelineLogger* unity_timeline_logger_construct (GType object_type);
GType unity_webapp_prism_get_type (void);
UnityWebappPrism* unity_webapp_prism_new (const char* address, const char* icon);
UnityWebappPrism* unity_webapp_prism_construct (GType object_type, const char* address, const char* icon);
char* unity_webapp_prism_desktop_file_path (UnityWebappPrism* self);
void unity_webapp_prism_add_to_favorites (UnityWebappPrism* self);
const char* unity_webapp_prism_get_url (UnityWebappPrism* self);
const char* unity_webapp_prism_get_icon (UnityWebappPrism* self);
GType unity_dnd_targets_get_type (void);
UnityShellMode unity_shell_get_mode (UnityShell* self);
ClutterStage* unity_shell_get_stage (UnityShell* self);
void unity_shell_show_unity (UnityShell* self);
gint unity_shell_get_indicators_width (UnityShell* self);
void unity_shell_ensure_input_region (UnityShell* self);
void unity_shell_add_fullscreen_request (UnityShell* self, GObject* o);
gboolean unity_shell_remove_fullscreen_request (UnityShell* self, GObject* o);
void unity_shell_grab_keyboard (UnityShell* self, gboolean grab, guint32 timestamp);
void unity_shell_show_window_picker (UnityShell* self);
gboolean unity_shell_get_menus_swallow_events (UnityShell* self);
extern UnityShell* unity_global_shell;
gboolean unity_icon_name_exists_in_theme (const char* icon_name, const char* theme);
GType unity_theme_image_get_type (void);
UnityThemeImage* unity_theme_image_new (const char* icon_name);
UnityThemeImage* unity_theme_image_construct (GType object_type, const char* icon_name);
const char* unity_theme_image_get_icon_name (UnityThemeImage* self);
void unity_theme_image_set_icon_name (UnityThemeImage* self, const char* value);
char* unity_webapp_urlify (const char* uri);
GType unity_webapp_fetch_file_get_type (void);
UnityWebappFetchFile* unity_webapp_fetch_file_new (const char* uri);
UnityWebappFetchFile* unity_webapp_fetch_file_construct (GType object_type, const char* uri);
void unity_webapp_fetch_file_fetch_data (UnityWebappFetchFile* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void unity_webapp_fetch_file_fetch_data_finish (UnityWebappFetchFile* self, GAsyncResult* _res_);
const char* unity_webapp_fetch_file_get_uri (UnityWebappFetchFile* self);
char* unity_webapp_get_hostname (const char* uri);
GType unity_webapp_webicon_fetcher_get_type (void);
UnityWebappWebiconFetcher* unity_webapp_webicon_fetcher_new (const char* uri, const char* destination, const char* desktop_file);
UnityWebappWebiconFetcher* unity_webapp_webicon_fetcher_construct (GType object_type, const char* uri, const char* destination, const char* desktop_file);
void unity_webapp_webicon_fetcher_fetch_webapp_data (UnityWebappWebiconFetcher* self);
const char* unity_webapp_webicon_fetcher_get_uri (UnityWebappWebiconFetcher* self);
const char* unity_webapp_webicon_fetcher_get_destination (UnityWebappWebiconFetcher* self);
const char* unity_webapp_webicon_fetcher_get_desktop_location (UnityWebappWebiconFetcher* self);
GType unity_webapp_icon_builder_get_type (void);
UnityWebappIconBuilder* unity_webapp_icon_builder_new (const char* dest, GdkPixbuf* source);
UnityWebappIconBuilder* unity_webapp_icon_builder_construct (GType object_type, const char* dest, GdkPixbuf* source);
void unity_webapp_icon_builder_load_layers (UnityWebappIconBuilder* self);
void unity_webapp_icon_builder_build_icon (UnityWebappIconBuilder* self);
const char* unity_webapp_icon_builder_get_destination (UnityWebappIconBuilder* self);
GdkPixbuf* unity_webapp_icon_builder_get_source (UnityWebappIconBuilder* self);


G_END_DECLS

#endif
