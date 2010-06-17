/* unity.h generated by valac, the Vala compiler, do not modify */


#ifndef __UNITY_H__
#define __UNITY_H__

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <clutter/clutter.h>
#include <float.h>
#include <math.h>
#include <clutk/clutk.h>
#include <gdk-pixbuf/gdk-pixdata.h>
#include <cairo.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <gee.h>
#include <dee.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>

G_BEGIN_DECLS


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

#define UNITY_TYPE_UNITY_ICON (unity_unity_icon_get_type ())
#define UNITY_UNITY_ICON(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_UNITY_ICON, UnityUnityIcon))
#define UNITY_UNITY_ICON_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_UNITY_ICON, UnityUnityIconClass))
#define UNITY_IS_UNITY_ICON(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_UNITY_ICON))
#define UNITY_IS_UNITY_ICON_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_UNITY_ICON))
#define UNITY_UNITY_ICON_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_UNITY_ICON, UnityUnityIconClass))

typedef struct _UnityUnityIcon UnityUnityIcon;
typedef struct _UnityUnityIconClass UnityUnityIconClass;
typedef struct _UnityUnityIconPrivate UnityUnityIconPrivate;

#define UNITY_WEBAPP_TYPE_PRISM (unity_webapp_prism_get_type ())
#define UNITY_WEBAPP_PRISM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_WEBAPP_TYPE_PRISM, UnityWebappPrism))
#define UNITY_WEBAPP_PRISM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_WEBAPP_TYPE_PRISM, UnityWebappPrismClass))
#define UNITY_WEBAPP_IS_PRISM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_WEBAPP_TYPE_PRISM))
#define UNITY_WEBAPP_IS_PRISM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_WEBAPP_TYPE_PRISM))
#define UNITY_WEBAPP_PRISM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_WEBAPP_TYPE_PRISM, UnityWebappPrismClass))

typedef struct _UnityWebappPrism UnityWebappPrism;
typedef struct _UnityWebappPrismClass UnityWebappPrismClass;
typedef struct _UnityWebappPrismPrivate UnityWebappPrismPrivate;

#define UNITY_QUICKLIST_RENDERING_TYPE_SEPERATOR (unity_quicklist_rendering_seperator_get_type ())
#define UNITY_QUICKLIST_RENDERING_SEPERATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_QUICKLIST_RENDERING_TYPE_SEPERATOR, UnityQuicklistRenderingSeperator))
#define UNITY_QUICKLIST_RENDERING_SEPERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_QUICKLIST_RENDERING_TYPE_SEPERATOR, UnityQuicklistRenderingSeperatorClass))
#define UNITY_QUICKLIST_RENDERING_IS_SEPERATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_QUICKLIST_RENDERING_TYPE_SEPERATOR))
#define UNITY_QUICKLIST_RENDERING_IS_SEPERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_QUICKLIST_RENDERING_TYPE_SEPERATOR))
#define UNITY_QUICKLIST_RENDERING_SEPERATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_QUICKLIST_RENDERING_TYPE_SEPERATOR, UnityQuicklistRenderingSeperatorClass))

typedef struct _UnityQuicklistRenderingSeperator UnityQuicklistRenderingSeperator;
typedef struct _UnityQuicklistRenderingSeperatorClass UnityQuicklistRenderingSeperatorClass;
typedef struct _UnityQuicklistRenderingSeperatorPrivate UnityQuicklistRenderingSeperatorPrivate;

#define UNITY_QUICKLIST_RENDERING_TYPE_ITEM (unity_quicklist_rendering_item_get_type ())
#define UNITY_QUICKLIST_RENDERING_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_QUICKLIST_RENDERING_TYPE_ITEM, UnityQuicklistRenderingItem))
#define UNITY_QUICKLIST_RENDERING_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_QUICKLIST_RENDERING_TYPE_ITEM, UnityQuicklistRenderingItemClass))
#define UNITY_QUICKLIST_RENDERING_IS_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_QUICKLIST_RENDERING_TYPE_ITEM))
#define UNITY_QUICKLIST_RENDERING_IS_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_QUICKLIST_RENDERING_TYPE_ITEM))
#define UNITY_QUICKLIST_RENDERING_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_QUICKLIST_RENDERING_TYPE_ITEM, UnityQuicklistRenderingItemClass))

typedef struct _UnityQuicklistRenderingItem UnityQuicklistRenderingItem;
typedef struct _UnityQuicklistRenderingItemClass UnityQuicklistRenderingItemClass;
typedef struct _UnityQuicklistRenderingItemPrivate UnityQuicklistRenderingItemPrivate;

#define UNITY_QUICKLIST_RENDERING_TYPE_MENU (unity_quicklist_rendering_menu_get_type ())
#define UNITY_QUICKLIST_RENDERING_MENU(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_QUICKLIST_RENDERING_TYPE_MENU, UnityQuicklistRenderingMenu))
#define UNITY_QUICKLIST_RENDERING_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_QUICKLIST_RENDERING_TYPE_MENU, UnityQuicklistRenderingMenuClass))
#define UNITY_QUICKLIST_RENDERING_IS_MENU(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_QUICKLIST_RENDERING_TYPE_MENU))
#define UNITY_QUICKLIST_RENDERING_IS_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_QUICKLIST_RENDERING_TYPE_MENU))
#define UNITY_QUICKLIST_RENDERING_MENU_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_QUICKLIST_RENDERING_TYPE_MENU, UnityQuicklistRenderingMenuClass))

typedef struct _UnityQuicklistRenderingMenu UnityQuicklistRenderingMenu;
typedef struct _UnityQuicklistRenderingMenuClass UnityQuicklistRenderingMenuClass;
typedef struct _UnityQuicklistRenderingMenuPrivate UnityQuicklistRenderingMenuPrivate;

#define UNITY_TYPE_SHELL_MODE (unity_shell_mode_get_type ())

#define UNITY_TYPE_DND_TARGETS (unity_dnd_targets_get_type ())

#define UNITY_TYPE_SHELL (unity_shell_get_type ())
#define UNITY_SHELL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_SHELL, UnityShell))
#define UNITY_IS_SHELL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_SHELL))
#define UNITY_SHELL_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_TYPE_SHELL, UnityShellIface))

typedef struct _UnityShell UnityShell;
typedef struct _UnityShellIface UnityShellIface;

#define UNITY_TYPE_THEME_FILE_PATH (unity_theme_file_path_get_type ())
#define UNITY_THEME_FILE_PATH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_THEME_FILE_PATH, UnityThemeFilePath))
#define UNITY_THEME_FILE_PATH_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_THEME_FILE_PATH, UnityThemeFilePathClass))
#define UNITY_IS_THEME_FILE_PATH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_THEME_FILE_PATH))
#define UNITY_IS_THEME_FILE_PATH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_THEME_FILE_PATH))
#define UNITY_THEME_FILE_PATH_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_THEME_FILE_PATH, UnityThemeFilePathClass))

typedef struct _UnityThemeFilePath UnityThemeFilePath;
typedef struct _UnityThemeFilePathClass UnityThemeFilePathClass;
typedef struct _UnityThemeFilePathPrivate UnityThemeFilePathPrivate;

#define UNITY_TYPE_THEME_IMAGE (unity_theme_image_get_type ())
#define UNITY_THEME_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_THEME_IMAGE, UnityThemeImage))
#define UNITY_THEME_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_THEME_IMAGE, UnityThemeImageClass))
#define UNITY_IS_THEME_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_THEME_IMAGE))
#define UNITY_IS_THEME_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_THEME_IMAGE))
#define UNITY_THEME_IMAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_THEME_IMAGE, UnityThemeImageClass))

typedef struct _UnityThemeImage UnityThemeImage;
typedef struct _UnityThemeImageClass UnityThemeImageClass;
typedef struct _UnityThemeImagePrivate UnityThemeImagePrivate;

#define UNITY_TYPE_FAVORITES (unity_favorites_get_type ())
#define UNITY_FAVORITES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_FAVORITES, UnityFavorites))
#define UNITY_FAVORITES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_FAVORITES, UnityFavoritesClass))
#define UNITY_IS_FAVORITES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_FAVORITES))
#define UNITY_IS_FAVORITES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_FAVORITES))
#define UNITY_FAVORITES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_FAVORITES, UnityFavoritesClass))

typedef struct _UnityFavorites UnityFavorites;
typedef struct _UnityFavoritesClass UnityFavoritesClass;
typedef struct _UnityFavoritesPrivate UnityFavoritesPrivate;

#define UNITY_TYPE_GCONF_FAVORITES (unity_gconf_favorites_get_type ())
#define UNITY_GCONF_FAVORITES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_GCONF_FAVORITES, UnityGConfFavorites))
#define UNITY_GCONF_FAVORITES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_GCONF_FAVORITES, UnityGConfFavoritesClass))
#define UNITY_IS_GCONF_FAVORITES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_GCONF_FAVORITES))
#define UNITY_IS_GCONF_FAVORITES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_GCONF_FAVORITES))
#define UNITY_GCONF_FAVORITES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_GCONF_FAVORITES, UnityGConfFavoritesClass))

typedef struct _UnityGConfFavorites UnityGConfFavorites;
typedef struct _UnityGConfFavoritesClass UnityGConfFavoritesClass;
typedef struct _UnityGConfFavoritesPrivate UnityGConfFavoritesPrivate;

#define UNITY_PLACE_TYPE_RENDERER_INFO (unity_place_renderer_info_get_type ())
#define UNITY_PLACE_RENDERER_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACE_TYPE_RENDERER_INFO, UnityPlaceRendererInfo))
#define UNITY_PLACE_RENDERER_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACE_TYPE_RENDERER_INFO, UnityPlaceRendererInfoClass))
#define UNITY_PLACE_IS_RENDERER_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACE_TYPE_RENDERER_INFO))
#define UNITY_PLACE_IS_RENDERER_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACE_TYPE_RENDERER_INFO))
#define UNITY_PLACE_RENDERER_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACE_TYPE_RENDERER_INFO, UnityPlaceRendererInfoClass))

typedef struct _UnityPlaceRendererInfo UnityPlaceRendererInfo;
typedef struct _UnityPlaceRendererInfoClass UnityPlaceRendererInfoClass;
typedef struct _UnityPlaceRendererInfoPrivate UnityPlaceRendererInfoPrivate;

#define UNITY_PLACE_TYPE_SEARCH (unity_place_search_get_type ())
#define UNITY_PLACE_SEARCH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACE_TYPE_SEARCH, UnityPlaceSearch))
#define UNITY_PLACE_SEARCH_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACE_TYPE_SEARCH, UnityPlaceSearchClass))
#define UNITY_PLACE_IS_SEARCH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACE_TYPE_SEARCH))
#define UNITY_PLACE_IS_SEARCH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACE_TYPE_SEARCH))
#define UNITY_PLACE_SEARCH_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACE_TYPE_SEARCH, UnityPlaceSearchClass))

typedef struct _UnityPlaceSearch UnityPlaceSearch;
typedef struct _UnityPlaceSearchClass UnityPlaceSearchClass;
typedef struct _UnityPlaceSearchPrivate UnityPlaceSearchPrivate;

#define UNITY_PLACE_TYPE_ENTRY_INFO (unity_place_entry_info_get_type ())
#define UNITY_PLACE_ENTRY_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACE_TYPE_ENTRY_INFO, UnityPlaceEntryInfo))
#define UNITY_PLACE_ENTRY_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACE_TYPE_ENTRY_INFO, UnityPlaceEntryInfoClass))
#define UNITY_PLACE_IS_ENTRY_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACE_TYPE_ENTRY_INFO))
#define UNITY_PLACE_IS_ENTRY_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACE_TYPE_ENTRY_INFO))
#define UNITY_PLACE_ENTRY_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACE_TYPE_ENTRY_INFO, UnityPlaceEntryInfoClass))

typedef struct _UnityPlaceEntryInfo UnityPlaceEntryInfo;
typedef struct _UnityPlaceEntryInfoClass UnityPlaceEntryInfoClass;
typedef struct _UnityPlaceEntryInfoPrivate UnityPlaceEntryInfoPrivate;

#define UNITY_PLACE_TYPE_CONTROLLER (unity_place_controller_get_type ())
#define UNITY_PLACE_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACE_TYPE_CONTROLLER, UnityPlaceController))
#define UNITY_PLACE_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACE_TYPE_CONTROLLER, UnityPlaceControllerClass))
#define UNITY_PLACE_IS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACE_TYPE_CONTROLLER))
#define UNITY_PLACE_IS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACE_TYPE_CONTROLLER))
#define UNITY_PLACE_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACE_TYPE_CONTROLLER, UnityPlaceControllerClass))

typedef struct _UnityPlaceController UnityPlaceController;
typedef struct _UnityPlaceControllerClass UnityPlaceControllerClass;
typedef struct _UnityPlaceControllerPrivate UnityPlaceControllerPrivate;

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

struct _UnityUnityIcon {
	CtkActor parent_instance;
	UnityUnityIconPrivate * priv;
	float rotation;
};

struct _UnityUnityIconClass {
	CtkActorClass parent_class;
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

struct _UnityQuicklistRenderingSeperator {
	GObject parent_instance;
	UnityQuicklistRenderingSeperatorPrivate * priv;
};

struct _UnityQuicklistRenderingSeperatorClass {
	GObjectClass parent_class;
};

struct _UnityQuicklistRenderingItem {
	GObject parent_instance;
	UnityQuicklistRenderingItemPrivate * priv;
};

struct _UnityQuicklistRenderingItemClass {
	GObjectClass parent_class;
};

struct _UnityQuicklistRenderingMenu {
	GObject parent_instance;
	UnityQuicklistRenderingMenuPrivate * priv;
};

struct _UnityQuicklistRenderingMenuClass {
	GObjectClass parent_class;
};

typedef enum  {
	UNITY_SHELL_MODE_UNDERLAY,
	UNITY_SHELL_MODE_OVERLAY
} UnityShellMode;

typedef enum  {
	UNITY_DND_TARGETS_TARGET_INT32,
	UNITY_DND_TARGETS_TARGET_STRING,
	UNITY_DND_TARGETS_TARGET_URL,
	UNITY_DND_TARGETS_TARGET_OTHER
} Unitydnd_targets;

struct _UnityShellIface {
	GTypeInterface parent_iface;
	UnityShellMode (*get_mode) (UnityShell* self);
	ClutterStage* (*get_stage) (UnityShell* self);
	void (*show_unity) (UnityShell* self);
	gint (*get_indicators_width) (UnityShell* self);
	gint (*get_launcher_width_foobar) (UnityShell* self);
	gint (*get_panel_height_foobar) (UnityShell* self);
	void (*ensure_input_region) (UnityShell* self);
	void (*add_fullscreen_request) (UnityShell* self, GObject* o);
	gboolean (*remove_fullscreen_request) (UnityShell* self, GObject* o);
	void (*grab_keyboard) (UnityShell* self, gboolean grab, guint32 timestamp);
	void (*show_window_picker) (UnityShell* self);
	void (*close_xids) (UnityShell* self, GArray* xids);
	void (*show_window) (UnityShell* self, guint32 xid);
	void (*expose_xids) (UnityShell* self, GArray* xids);
	void (*stop_expose) (UnityShell* self);
	gboolean (*get_menus_swallow_events) (UnityShell* self);
};

struct _UnityThemeFilePath {
	GObject parent_instance;
	UnityThemeFilePathPrivate * priv;
};

struct _UnityThemeFilePathClass {
	GObjectClass parent_class;
};

struct _UnityThemeImage {
	ClutterTexture parent_instance;
	UnityThemeImagePrivate * priv;
	GdkPixbuf* icon;
};

struct _UnityThemeImageClass {
	ClutterTextureClass parent_class;
};

struct _UnityFavorites {
	GObject parent_instance;
	UnityFavoritesPrivate * priv;
};

struct _UnityFavoritesClass {
	GObjectClass parent_class;
	GeeArrayList* (*get_favorites) (UnityFavorites* self);
	void (*add_favorite) (UnityFavorites* self, const char* uid);
	void (*remove_favorite) (UnityFavorites* self, const char* uid);
	gboolean (*is_favorite) (UnityFavorites* self, const char* uid);
	char* (*get_string) (UnityFavorites* self, const char* uid, const char* name);
	void (*set_string) (UnityFavorites* self, const char* uid, const char* name, const char* value);
	gint* (*get_int) (UnityFavorites* self, const char* uid, const char* name);
	void (*set_int) (UnityFavorites* self, const char* uid, const char* name, gint value);
	float* (*get_float) (UnityFavorites* self, const char* uid, const char* name);
	void (*set_float) (UnityFavorites* self, const char* uid, const char* name, float value);
	gboolean* (*get_bool) (UnityFavorites* self, const char* uid, const char* name);
	void (*set_bool) (UnityFavorites* self, const char* uid, const char* name, gboolean value);
};

struct _UnityGConfFavorites {
	UnityFavorites parent_instance;
	UnityGConfFavoritesPrivate * priv;
};

struct _UnityGConfFavoritesClass {
	UnityFavoritesClass parent_class;
};

struct _UnityPlaceRendererInfo {
	GObject parent_instance;
	UnityPlaceRendererInfoPrivate * priv;
};

struct _UnityPlaceRendererInfoClass {
	GObjectClass parent_class;
};

struct _UnityPlaceSearch {
	GInitiallyUnowned parent_instance;
	UnityPlaceSearchPrivate * priv;
};

struct _UnityPlaceSearchClass {
	GInitiallyUnownedClass parent_class;
};

typedef guint (*UnityPlaceSearchHandler) (UnityPlaceSearch* search, void* user_data);
struct _UnityPlaceEntryInfo {
	GObject parent_instance;
	UnityPlaceEntryInfoPrivate * priv;
};

struct _UnityPlaceEntryInfoClass {
	GObjectClass parent_class;
};

struct _UnityPlaceController {
	GObject parent_instance;
	UnityPlaceControllerPrivate * priv;
};

struct _UnityPlaceControllerClass {
	GObjectClass parent_class;
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
UnityDragModel* unity_drag_controller_get_drag_model (UnityDragController* self);
UnityDragController* unity_drag_controller_new (void);
UnityDragController* unity_drag_controller_construct (GType object_type);
gboolean unity_drag_controller_get_is_dragging (UnityDragController* self);
GType unity_entry_get_type (void);
UnityEntry* unity_entry_new (const char* static_text);
UnityEntry* unity_entry_construct (GType object_type, const char* static_text);
const char* unity_entry_get_static_text (UnityEntry* self);
void unity_entry_set_static_text (UnityEntry* self, const char* value);
void unity_rgb_to_hsv (float r, float g, float b, float* hue, float* sat, float* val);
void unity_hsv_to_rgb (float hue, float sat, float val, float* r, float* g, float* b);
gboolean unity_pixbuf_is_tile (GdkPixbuf* source);
void unity_get_average_color (GdkPixbuf* source, guint* red, guint* green, guint* blue);
GType unity_unity_icon_get_type (void);
UnityUnityIcon* unity_unity_icon_new (ClutterTexture* icon, ClutterTexture* bg_tex);
UnityUnityIcon* unity_unity_icon_construct (GType object_type, ClutterTexture* icon, ClutterTexture* bg_tex);
void unity_unity_icon_paint_real (ClutterActor* actor);
ClutterTexture* unity_unity_icon_get_icon (UnityUnityIcon* self);
ClutterTexture* unity_unity_icon_get_bg_color (UnityUnityIcon* self);
GType unity_webapp_prism_get_type (void);
UnityWebappPrism* unity_webapp_prism_new (const char* address, const char* icon);
UnityWebappPrism* unity_webapp_prism_construct (GType object_type, const char* address, const char* icon);
char* unity_webapp_prism_desktop_file_path (UnityWebappPrism* self);
void unity_webapp_prism_add_to_favorites (UnityWebappPrism* self);
const char* unity_webapp_prism_get_url (UnityWebappPrism* self);
const char* unity_webapp_prism_get_icon (UnityWebappPrism* self);
GType unity_quicklist_rendering_seperator_get_type (void);
void unity_quicklist_rendering_seperator_fill_mask (cairo_t* cr);
void unity_quicklist_rendering_seperator_image_background (cairo_t* cr, gint w, gint h);
UnityQuicklistRenderingSeperator* unity_quicklist_rendering_seperator_new (void);
UnityQuicklistRenderingSeperator* unity_quicklist_rendering_seperator_construct (GType object_type);
GType unity_quicklist_rendering_item_get_type (void);
void unity_quicklist_rendering_item_get_text_extents (const char* font, const char* text, gint* width, gint* height);
void unity_quicklist_rendering_item_normal_mask (cairo_t* cr, gint w, gint h, const char* font, const char* text);
void unity_quicklist_rendering_item_selected_mask (cairo_t* cr, gint w, gint h, const char* font, const char* text);
UnityQuicklistRenderingItem* unity_quicklist_rendering_item_new (void);
UnityQuicklistRenderingItem* unity_quicklist_rendering_item_construct (GType object_type);
GType unity_quicklist_rendering_menu_get_type (void);
void unity_quicklist_rendering_menu_full_mask (cairo_t* cr, gint w, gint h, float anchor_y);
void unity_quicklist_rendering_menu_fill_mask (cairo_t* cr, gint w, gint h, float anchor_y);
void unity_quicklist_rendering_menu_background (cairo_t* cr, gint w, gint h, float anchor_y);
UnityQuicklistRenderingMenu* unity_quicklist_rendering_menu_new (void);
UnityQuicklistRenderingMenu* unity_quicklist_rendering_menu_construct (GType object_type);
GType unity_shell_mode_get_type (void);
GType unity_dnd_targets_get_type (void);
GType unity_shell_get_type (void);
UnityShellMode unity_shell_get_mode (UnityShell* self);
ClutterStage* unity_shell_get_stage (UnityShell* self);
void unity_shell_show_unity (UnityShell* self);
gint unity_shell_get_indicators_width (UnityShell* self);
gint unity_shell_get_launcher_width_foobar (UnityShell* self);
gint unity_shell_get_panel_height_foobar (UnityShell* self);
void unity_shell_ensure_input_region (UnityShell* self);
void unity_shell_add_fullscreen_request (UnityShell* self, GObject* o);
gboolean unity_shell_remove_fullscreen_request (UnityShell* self, GObject* o);
void unity_shell_grab_keyboard (UnityShell* self, gboolean grab, guint32 timestamp);
void unity_shell_show_window_picker (UnityShell* self);
void unity_shell_close_xids (UnityShell* self, GArray* xids);
void unity_shell_show_window (UnityShell* self, guint32 xid);
void unity_shell_expose_xids (UnityShell* self, GArray* xids);
void unity_shell_stop_expose (UnityShell* self);
gboolean unity_shell_get_menus_swallow_events (UnityShell* self);
extern UnityShell* unity_global_shell;
GType unity_theme_file_path_get_type (void);
void unity_theme_file_path_add_icon_theme (UnityThemeFilePath* self, GtkIconTheme* theme);
void unity_theme_file_path_get_icon_filepath (UnityThemeFilePath* self, const char* icon_name, GAsyncReadyCallback _callback_, gpointer _user_data_);
void unity_theme_file_path_get_icon_filepath_finish (UnityThemeFilePath* self, GAsyncResult* _res_);
UnityThemeFilePath* unity_theme_file_path_new (void);
UnityThemeFilePath* unity_theme_file_path_construct (GType object_type);
gboolean unity_icon_name_exists_in_theme (const char* icon_name, const char* theme);
GType unity_theme_image_get_type (void);
UnityThemeImage* unity_theme_image_new (const char* icon_name);
UnityThemeImage* unity_theme_image_construct (GType object_type, const char* icon_name);
const char* unity_theme_image_get_icon_name (UnityThemeImage* self);
void unity_theme_image_set_icon_name (UnityThemeImage* self, const char* value);
GType unity_favorites_get_type (void);
extern UnityFavorites* unity_favorites_singleton;
UnityFavorites* unity_favorites_get_default (void);
GeeArrayList* unity_favorites_get_favorites (UnityFavorites* self);
void unity_favorites_add_favorite (UnityFavorites* self, const char* uid);
void unity_favorites_remove_favorite (UnityFavorites* self, const char* uid);
gboolean unity_favorites_is_favorite (UnityFavorites* self, const char* uid);
char* unity_favorites_get_string (UnityFavorites* self, const char* uid, const char* name);
void unity_favorites_set_string (UnityFavorites* self, const char* uid, const char* name, const char* value);
gint* unity_favorites_get_int (UnityFavorites* self, const char* uid, const char* name);
void unity_favorites_set_int (UnityFavorites* self, const char* uid, const char* name, gint value);
float* unity_favorites_get_float (UnityFavorites* self, const char* uid, const char* name);
void unity_favorites_set_float (UnityFavorites* self, const char* uid, const char* name, float value);
gboolean* unity_favorites_get_bool (UnityFavorites* self, const char* uid, const char* name);
void unity_favorites_set_bool (UnityFavorites* self, const char* uid, const char* name, gboolean value);
UnityFavorites* unity_favorites_construct (GType object_type);
GType unity_gconf_favorites_get_type (void);
UnityGConfFavorites* unity_gconf_favorites_new (void);
UnityGConfFavorites* unity_gconf_favorites_construct (GType object_type);
GType unity_place_renderer_info_get_type (void);
void unity_place_renderer_info_set_hint (UnityPlaceRendererInfo* self, const char* hint, const char* val);
char* unity_place_renderer_info_get_hint (UnityPlaceRendererInfo* self, const char* hint);
void unity_place_renderer_info_clear_hint (UnityPlaceRendererInfo* self, const char* hint);
void unity_place_renderer_info_clear_hints (UnityPlaceRendererInfo* self);
guint unity_place_renderer_info_num_hints (UnityPlaceRendererInfo* self);
const char* unity_place_renderer_info_get_default_renderer (UnityPlaceRendererInfo* self);
void unity_place_renderer_info_set_default_renderer (UnityPlaceRendererInfo* self, const char* value);
DeeModel* unity_place_renderer_info_get_groups_model (UnityPlaceRendererInfo* self);
void unity_place_renderer_info_set_groups_model (UnityPlaceRendererInfo* self, DeeModel* value);
DeeModel* unity_place_renderer_info_get_results_model (UnityPlaceRendererInfo* self);
void unity_place_renderer_info_set_results_model (UnityPlaceRendererInfo* self, DeeModel* value);
GType unity_place_search_get_type (void);
UnityPlaceSearch* unity_place_search_new (const char* search, GHashTable* hints);
UnityPlaceSearch* unity_place_search_construct (GType object_type, const char* search, GHashTable* hints);
char* unity_place_search_get_search_string (UnityPlaceSearch* self);
void unity_place_search_set_hint (UnityPlaceSearch* self, const char* hint, const char* val);
char* unity_place_search_get_hint (UnityPlaceSearch* self, const char* hint);
void unity_place_search_clear_hint (UnityPlaceSearch* self, const char* hint);
void unity_place_search_clear_hints (UnityPlaceSearch* self);
guint unity_place_search_num_hints (UnityPlaceSearch* self);
GType unity_place_entry_info_get_type (void);
UnityPlaceEntryInfo* unity_place_entry_info_new (const char* dbus_path);
UnityPlaceEntryInfo* unity_place_entry_info_construct (GType object_type, const char* dbus_path);
void unity_place_entry_info_set_hint (UnityPlaceEntryInfo* self, const char* hint, const char* val);
char* unity_place_entry_info_get_hint (UnityPlaceEntryInfo* self, const char* hint);
void unity_place_entry_info_clear_hint (UnityPlaceEntryInfo* self, const char* hint);
void unity_place_entry_info_clear_hints (UnityPlaceEntryInfo* self);
guint unity_place_entry_info_num_hints (UnityPlaceEntryInfo* self);
UnityPlaceRendererInfo* unity_place_entry_info_get_entry_renderer_info (UnityPlaceEntryInfo* self);
UnityPlaceRendererInfo* unity_place_entry_info_get_global_renderer_info (UnityPlaceEntryInfo* self);
const char* unity_place_entry_info_get_dbus_path (UnityPlaceEntryInfo* self);
void unity_place_entry_info_set_dbus_path (UnityPlaceEntryInfo* self, const char* value);
const char* unity_place_entry_info_get_display_name (UnityPlaceEntryInfo* self);
void unity_place_entry_info_set_display_name (UnityPlaceEntryInfo* self, const char* value);
const char* unity_place_entry_info_get_icon (UnityPlaceEntryInfo* self);
void unity_place_entry_info_set_icon (UnityPlaceEntryInfo* self, const char* value);
guint unity_place_entry_info_get_position (UnityPlaceEntryInfo* self);
void unity_place_entry_info_set_position (UnityPlaceEntryInfo* self, guint value);
char** unity_place_entry_info_get_mimetypes (UnityPlaceEntryInfo* self, int* result_length1);
void unity_place_entry_info_set_mimetypes (UnityPlaceEntryInfo* self, char** value, int value_length1);
gboolean unity_place_entry_info_get_sensitive (UnityPlaceEntryInfo* self);
void unity_place_entry_info_set_sensitive (UnityPlaceEntryInfo* self, gboolean value);
DeeModel* unity_place_entry_info_get_sections_model (UnityPlaceEntryInfo* self);
void unity_place_entry_info_set_sections_model (UnityPlaceEntryInfo* self, DeeModel* value);
gboolean unity_place_entry_info_get_active (UnityPlaceEntryInfo* self);
void unity_place_entry_info_set_active (UnityPlaceEntryInfo* self, gboolean value);
guint unity_place_entry_info_get_active_section (UnityPlaceEntryInfo* self);
void unity_place_entry_info_set_active_section (UnityPlaceEntryInfo* self, guint value);
UnityPlaceSearchHandler unity_place_entry_info_get_search_handler (UnityPlaceEntryInfo* self, gpointer* result_target);
void unity_place_entry_info_set_search_handler (UnityPlaceEntryInfo* self, UnityPlaceSearchHandler value, gpointer value_target);
UnityPlaceSearchHandler unity_place_entry_info_get_global_search_handler (UnityPlaceEntryInfo* self, gpointer* result_target);
void unity_place_entry_info_set_global_search_handler (UnityPlaceEntryInfo* self, UnityPlaceSearchHandler value, gpointer value_target);
GType unity_place_controller_get_type (void);
UnityPlaceController* unity_place_controller_new (const char* dbus_path);
UnityPlaceController* unity_place_controller_construct (GType object_type, const char* dbus_path);
void unity_place_controller_add_entry (UnityPlaceController* self, UnityPlaceEntryInfo* entry);
UnityPlaceEntryInfo* unity_place_controller_get_entry (UnityPlaceController* self, const char* dbus_path);
void unity_place_controller_remove_entry (UnityPlaceController* self, const char* dbus_path);
guint unity_place_controller_num_entries (UnityPlaceController* self);
char** unity_place_controller_get_entry_paths (UnityPlaceController* self, int* result_length1);
UnityPlaceEntryInfo** unity_place_controller_get_entries (UnityPlaceController* self, int* result_length1);
void unity_place_controller_export (UnityPlaceController* self, GError** error);
void unity_place_controller_unexport (UnityPlaceController* self, GError** error);
const char* unity_place_controller_get_dbus_path (UnityPlaceController* self);
gboolean unity_place_controller_get_exported (UnityPlaceController* self);
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


G_END_DECLS

#endif
