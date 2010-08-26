/* test-unit.c generated by valac 0.9.7, the Vala compiler
 * generated from test-unit.vala, do not modify */

/*
 * Copyright (C) 2010 Canonical Ltd
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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <clutk/clutk.h>
#include <gobject/gvaluecollector.h>


#define TYPE_MAIN (main_get_type ())
#define MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MAIN, Main))
#define MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MAIN, MainClass))
#define IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MAIN))
#define IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MAIN))
#define MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MAIN, MainClass))

typedef struct _Main Main;
typedef struct _MainClass MainClass;
typedef struct _MainPrivate MainPrivate;

#define UNITY_TESTS_UNIT_TYPE_UNITY_PIXBUF_CACHE_SUITE (unity_tests_unit_unity_pixbuf_cache_suite_get_type ())
#define UNITY_TESTS_UNIT_UNITY_PIXBUF_CACHE_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_UNITY_PIXBUF_CACHE_SUITE, UnityTestsUnitUnityPixbufCacheSuite))
#define UNITY_TESTS_UNIT_UNITY_PIXBUF_CACHE_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_UNITY_PIXBUF_CACHE_SUITE, UnityTestsUnitUnityPixbufCacheSuiteClass))
#define UNITY_TESTS_UNIT_IS_UNITY_PIXBUF_CACHE_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_UNITY_PIXBUF_CACHE_SUITE))
#define UNITY_TESTS_UNIT_IS_UNITY_PIXBUF_CACHE_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_UNITY_PIXBUF_CACHE_SUITE))
#define UNITY_TESTS_UNIT_UNITY_PIXBUF_CACHE_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_UNITY_PIXBUF_CACHE_SUITE, UnityTestsUnitUnityPixbufCacheSuiteClass))

typedef struct _UnityTestsUnitUnityPixbufCacheSuite UnityTestsUnitUnityPixbufCacheSuite;
typedef struct _UnityTestsUnitUnityPixbufCacheSuiteClass UnityTestsUnitUnityPixbufCacheSuiteClass;

#define UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE (unity_tests_unit_launcher_suite_get_type ())
#define UNITY_TESTS_UNIT_LAUNCHER_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE, UnityTestsUnitLauncherSuite))
#define UNITY_TESTS_UNIT_LAUNCHER_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE, UnityTestsUnitLauncherSuiteClass))
#define UNITY_TESTS_UNIT_IS_LAUNCHER_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE))
#define UNITY_TESTS_UNIT_IS_LAUNCHER_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE))
#define UNITY_TESTS_UNIT_LAUNCHER_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE, UnityTestsUnitLauncherSuiteClass))

typedef struct _UnityTestsUnitLauncherSuite UnityTestsUnitLauncherSuite;
typedef struct _UnityTestsUnitLauncherSuiteClass UnityTestsUnitLauncherSuiteClass;

#define UNITY_TESTS_UNIT_TYPE_QUICKLIST_SUITE (unity_tests_unit_quicklist_suite_get_type ())
#define UNITY_TESTS_UNIT_QUICKLIST_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_QUICKLIST_SUITE, UnityTestsUnitQuicklistSuite))
#define UNITY_TESTS_UNIT_QUICKLIST_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_QUICKLIST_SUITE, UnityTestsUnitQuicklistSuiteClass))
#define UNITY_TESTS_UNIT_IS_QUICKLIST_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_QUICKLIST_SUITE))
#define UNITY_TESTS_UNIT_IS_QUICKLIST_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_QUICKLIST_SUITE))
#define UNITY_TESTS_UNIT_QUICKLIST_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_QUICKLIST_SUITE, UnityTestsUnitQuicklistSuiteClass))

typedef struct _UnityTestsUnitQuicklistSuite UnityTestsUnitQuicklistSuite;
typedef struct _UnityTestsUnitQuicklistSuiteClass UnityTestsUnitQuicklistSuiteClass;

#define UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE (unity_tests_unit_panel_indicator_object_entry_view_suite_get_type ())
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE, UnityTestsUnitPanelIndicatorObjectEntryViewSuite))
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE, UnityTestsUnitPanelIndicatorObjectEntryViewSuiteClass))
#define UNITY_TESTS_UNIT_IS_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE))
#define UNITY_TESTS_UNIT_IS_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE))
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE, UnityTestsUnitPanelIndicatorObjectEntryViewSuiteClass))

typedef struct _UnityTestsUnitPanelIndicatorObjectEntryViewSuite UnityTestsUnitPanelIndicatorObjectEntryViewSuite;
typedef struct _UnityTestsUnitPanelIndicatorObjectEntryViewSuiteClass UnityTestsUnitPanelIndicatorObjectEntryViewSuiteClass;

#define UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_VIEW_SUITE (unity_tests_unit_panel_indicator_object_view_suite_get_type ())
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_VIEW_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_VIEW_SUITE, UnityTestsUnitPanelIndicatorObjectViewSuite))
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_VIEW_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_VIEW_SUITE, UnityTestsUnitPanelIndicatorObjectViewSuiteClass))
#define UNITY_TESTS_UNIT_IS_PANEL_INDICATOR_OBJECT_VIEW_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_VIEW_SUITE))
#define UNITY_TESTS_UNIT_IS_PANEL_INDICATOR_OBJECT_VIEW_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_VIEW_SUITE))
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_VIEW_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_VIEW_SUITE, UnityTestsUnitPanelIndicatorObjectViewSuiteClass))

typedef struct _UnityTestsUnitPanelIndicatorObjectViewSuite UnityTestsUnitPanelIndicatorObjectViewSuite;
typedef struct _UnityTestsUnitPanelIndicatorObjectViewSuiteClass UnityTestsUnitPanelIndicatorObjectViewSuiteClass;

#define UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_FILE_MODEL_SUITE (unity_tests_unit_places_place_file_model_suite_get_type ())
#define UNITY_TESTS_UNIT_PLACES_PLACE_FILE_MODEL_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_FILE_MODEL_SUITE, UnityTestsUnitPlacesPlaceFileModelSuite))
#define UNITY_TESTS_UNIT_PLACES_PLACE_FILE_MODEL_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_FILE_MODEL_SUITE, UnityTestsUnitPlacesPlaceFileModelSuiteClass))
#define UNITY_TESTS_UNIT_IS_PLACES_PLACE_FILE_MODEL_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_FILE_MODEL_SUITE))
#define UNITY_TESTS_UNIT_IS_PLACES_PLACE_FILE_MODEL_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_FILE_MODEL_SUITE))
#define UNITY_TESTS_UNIT_PLACES_PLACE_FILE_MODEL_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_FILE_MODEL_SUITE, UnityTestsUnitPlacesPlaceFileModelSuiteClass))

typedef struct _UnityTestsUnitPlacesPlaceFileModelSuite UnityTestsUnitPlacesPlaceFileModelSuite;
typedef struct _UnityTestsUnitPlacesPlaceFileModelSuiteClass UnityTestsUnitPlacesPlaceFileModelSuiteClass;

#define UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_SUITE (unity_tests_unit_places_place_suite_get_type ())
#define UNITY_TESTS_UNIT_PLACES_PLACE_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_SUITE, UnityTestsUnitPlacesPlaceSuite))
#define UNITY_TESTS_UNIT_PLACES_PLACE_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_SUITE, UnityTestsUnitPlacesPlaceSuiteClass))
#define UNITY_TESTS_UNIT_IS_PLACES_PLACE_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_SUITE))
#define UNITY_TESTS_UNIT_IS_PLACES_PLACE_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_SUITE))
#define UNITY_TESTS_UNIT_PLACES_PLACE_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_SUITE, UnityTestsUnitPlacesPlaceSuiteClass))

typedef struct _UnityTestsUnitPlacesPlaceSuite UnityTestsUnitPlacesPlaceSuite;
typedef struct _UnityTestsUnitPlacesPlaceSuiteClass UnityTestsUnitPlacesPlaceSuiteClass;

#define UNITY_TESTS_UNIT_TYPE_PLACES_SUITE (unity_tests_unit_places_suite_get_type ())
#define UNITY_TESTS_UNIT_PLACES_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_SUITE, UnityTestsUnitPlacesSuite))
#define UNITY_TESTS_UNIT_PLACES_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_PLACES_SUITE, UnityTestsUnitPlacesSuiteClass))
#define UNITY_TESTS_UNIT_IS_PLACES_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_SUITE))
#define UNITY_TESTS_UNIT_IS_PLACES_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_PLACES_SUITE))
#define UNITY_TESTS_UNIT_PLACES_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_SUITE, UnityTestsUnitPlacesSuiteClass))

typedef struct _UnityTestsUnitPlacesSuite UnityTestsUnitPlacesSuite;
typedef struct _UnityTestsUnitPlacesSuiteClass UnityTestsUnitPlacesSuiteClass;

#define UNITY_TESTS_UNIT_TYPE_PLACE_SUITE (unity_tests_unit_place_suite_get_type ())
#define UNITY_TESTS_UNIT_PLACE_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_PLACE_SUITE, UnityTestsUnitPlaceSuite))
#define UNITY_TESTS_UNIT_PLACE_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_PLACE_SUITE, UnityTestsUnitPlaceSuiteClass))
#define UNITY_TESTS_UNIT_IS_PLACE_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_PLACE_SUITE))
#define UNITY_TESTS_UNIT_IS_PLACE_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_PLACE_SUITE))
#define UNITY_TESTS_UNIT_PLACE_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_PLACE_SUITE, UnityTestsUnitPlaceSuiteClass))

typedef struct _UnityTestsUnitPlaceSuite UnityTestsUnitPlaceSuite;
typedef struct _UnityTestsUnitPlaceSuiteClass UnityTestsUnitPlaceSuiteClass;

#define UNITY_TESTS_UNIT_TYPE_PLACE_BROWSER_SUITE (unity_tests_unit_place_browser_suite_get_type ())
#define UNITY_TESTS_UNIT_PLACE_BROWSER_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_PLACE_BROWSER_SUITE, UnityTestsUnitPlaceBrowserSuite))
#define UNITY_TESTS_UNIT_PLACE_BROWSER_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_PLACE_BROWSER_SUITE, UnityTestsUnitPlaceBrowserSuiteClass))
#define UNITY_TESTS_UNIT_IS_PLACE_BROWSER_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_PLACE_BROWSER_SUITE))
#define UNITY_TESTS_UNIT_IS_PLACE_BROWSER_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_PLACE_BROWSER_SUITE))
#define UNITY_TESTS_UNIT_PLACE_BROWSER_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_PLACE_BROWSER_SUITE, UnityTestsUnitPlaceBrowserSuiteClass))

typedef struct _UnityTestsUnitPlaceBrowserSuite UnityTestsUnitPlaceBrowserSuite;
typedef struct _UnityTestsUnitPlaceBrowserSuiteClass UnityTestsUnitPlaceBrowserSuiteClass;

#define UNITY_TESTS_UNIT_TYPE_IO_SUITE (unity_tests_unit_io_suite_get_type ())
#define UNITY_TESTS_UNIT_IO_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_IO_SUITE, UnityTestsUnitIOSuite))
#define UNITY_TESTS_UNIT_IO_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_IO_SUITE, UnityTestsUnitIOSuiteClass))
#define UNITY_TESTS_UNIT_IS_IO_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_IO_SUITE))
#define UNITY_TESTS_UNIT_IS_IO_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_IO_SUITE))
#define UNITY_TESTS_UNIT_IO_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_IO_SUITE, UnityTestsUnitIOSuiteClass))

typedef struct _UnityTestsUnitIOSuite UnityTestsUnitIOSuite;
typedef struct _UnityTestsUnitIOSuiteClass UnityTestsUnitIOSuiteClass;

#define UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE (unity_tests_unit_app_info_manager_suite_get_type ())
#define UNITY_TESTS_UNIT_APP_INFO_MANAGER_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE, UnityTestsUnitAppInfoManagerSuite))
#define UNITY_TESTS_UNIT_APP_INFO_MANAGER_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE, UnityTestsUnitAppInfoManagerSuiteClass))
#define UNITY_TESTS_UNIT_IS_APP_INFO_MANAGER_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE))
#define UNITY_TESTS_UNIT_IS_APP_INFO_MANAGER_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE))
#define UNITY_TESTS_UNIT_APP_INFO_MANAGER_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_APP_INFO_MANAGER_SUITE, UnityTestsUnitAppInfoManagerSuiteClass))

typedef struct _UnityTestsUnitAppInfoManagerSuite UnityTestsUnitAppInfoManagerSuite;
typedef struct _UnityTestsUnitAppInfoManagerSuiteClass UnityTestsUnitAppInfoManagerSuiteClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _unity_tests_unit_launcher_suite_unref0(var) ((var == NULL) ? NULL : (var = (unity_tests_unit_launcher_suite_unref (var), NULL)))
#define _unity_tests_unit_quicklist_suite_unref0(var) ((var == NULL) ? NULL : (var = (unity_tests_unit_quicklist_suite_unref (var), NULL)))
#define _unity_tests_unit_places_suite_unref0(var) ((var == NULL) ? NULL : (var = (unity_tests_unit_places_suite_unref (var), NULL)))
#define _unity_tests_unit_place_suite_unref0(var) ((var == NULL) ? NULL : (var = (unity_tests_unit_place_suite_unref (var), NULL)))
#define _unity_tests_unit_place_browser_suite_unref0(var) ((var == NULL) ? NULL : (var = (unity_tests_unit_place_browser_suite_unref (var), NULL)))
#define _unity_tests_unit_io_suite_unref0(var) ((var == NULL) ? NULL : (var = (unity_tests_unit_io_suite_unref (var), NULL)))
#define _unity_tests_unit_app_info_manager_suite_unref0(var) ((var == NULL) ? NULL : (var = (unity_tests_unit_app_info_manager_suite_unref (var), NULL)))
typedef struct _ParamSpecMain ParamSpecMain;

struct _Main {
	GTypeInstance parent_instance;
	volatile int ref_count;
	MainPrivate * priv;
};

struct _MainClass {
	GTypeClass parent_class;
	void (*finalize) (Main *self);
};

struct _ParamSpecMain {
	GParamSpec parent_instance;
};


static gpointer main_parent_class = NULL;

gpointer main_ref (gpointer instance);
void main_unref (gpointer instance);
GParamSpec* param_spec_main (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_main (GValue* value, gpointer v_object);
void value_take_main (GValue* value, gpointer v_object);
gpointer value_get_main (const GValue* value);
GType main_get_type (void) G_GNUC_CONST;
enum  {
	MAIN_DUMMY_PROPERTY
};
gint main_main (char** args, int args_length1);
GType unity_tests_unit_unity_pixbuf_cache_suite_get_type (void) G_GNUC_CONST;
gpointer unity_tests_unit_launcher_suite_ref (gpointer instance);
void unity_tests_unit_launcher_suite_unref (gpointer instance);
GParamSpec* unity_tests_unit_param_spec_launcher_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_tests_unit_value_set_launcher_suite (GValue* value, gpointer v_object);
void unity_tests_unit_value_take_launcher_suite (GValue* value, gpointer v_object);
gpointer unity_tests_unit_value_get_launcher_suite (const GValue* value);
GType unity_tests_unit_launcher_suite_get_type (void) G_GNUC_CONST;
gpointer unity_tests_unit_quicklist_suite_ref (gpointer instance);
void unity_tests_unit_quicklist_suite_unref (gpointer instance);
GParamSpec* unity_tests_unit_param_spec_quicklist_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_tests_unit_value_set_quicklist_suite (GValue* value, gpointer v_object);
void unity_tests_unit_value_take_quicklist_suite (GValue* value, gpointer v_object);
gpointer unity_tests_unit_value_get_quicklist_suite (const GValue* value);
GType unity_tests_unit_quicklist_suite_get_type (void) G_GNUC_CONST;
GType unity_tests_unit_panel_indicator_object_entry_view_suite_get_type (void) G_GNUC_CONST;
GType unity_tests_unit_panel_indicator_object_view_suite_get_type (void) G_GNUC_CONST;
GType unity_tests_unit_places_place_file_model_suite_get_type (void) G_GNUC_CONST;
GType unity_tests_unit_places_place_suite_get_type (void) G_GNUC_CONST;
gpointer unity_tests_unit_places_suite_ref (gpointer instance);
void unity_tests_unit_places_suite_unref (gpointer instance);
GParamSpec* unity_tests_unit_param_spec_places_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_tests_unit_value_set_places_suite (GValue* value, gpointer v_object);
void unity_tests_unit_value_take_places_suite (GValue* value, gpointer v_object);
gpointer unity_tests_unit_value_get_places_suite (const GValue* value);
GType unity_tests_unit_places_suite_get_type (void) G_GNUC_CONST;
gpointer unity_tests_unit_place_suite_ref (gpointer instance);
void unity_tests_unit_place_suite_unref (gpointer instance);
GParamSpec* unity_tests_unit_param_spec_place_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_tests_unit_value_set_place_suite (GValue* value, gpointer v_object);
void unity_tests_unit_value_take_place_suite (GValue* value, gpointer v_object);
gpointer unity_tests_unit_value_get_place_suite (const GValue* value);
GType unity_tests_unit_place_suite_get_type (void) G_GNUC_CONST;
gpointer unity_tests_unit_place_browser_suite_ref (gpointer instance);
void unity_tests_unit_place_browser_suite_unref (gpointer instance);
GParamSpec* unity_tests_unit_param_spec_place_browser_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_tests_unit_value_set_place_browser_suite (GValue* value, gpointer v_object);
void unity_tests_unit_value_take_place_browser_suite (GValue* value, gpointer v_object);
gpointer unity_tests_unit_value_get_place_browser_suite (const GValue* value);
GType unity_tests_unit_place_browser_suite_get_type (void) G_GNUC_CONST;
gpointer unity_tests_unit_io_suite_ref (gpointer instance);
void unity_tests_unit_io_suite_unref (gpointer instance);
GParamSpec* unity_tests_unit_param_spec_io_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_tests_unit_value_set_io_suite (GValue* value, gpointer v_object);
void unity_tests_unit_value_take_io_suite (GValue* value, gpointer v_object);
gpointer unity_tests_unit_value_get_io_suite (const GValue* value);
GType unity_tests_unit_io_suite_get_type (void) G_GNUC_CONST;
gpointer unity_tests_unit_app_info_manager_suite_ref (gpointer instance);
void unity_tests_unit_app_info_manager_suite_unref (gpointer instance);
GParamSpec* unity_tests_unit_param_spec_app_info_manager_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_tests_unit_value_set_app_info_manager_suite (GValue* value, gpointer v_object);
void unity_tests_unit_value_take_app_info_manager_suite (GValue* value, gpointer v_object);
gpointer unity_tests_unit_value_get_app_info_manager_suite (const GValue* value);
GType unity_tests_unit_app_info_manager_suite_get_type (void) G_GNUC_CONST;
UnityTestsUnitUnityPixbufCacheSuite* unity_tests_unit_unity_pixbuf_cache_suite_new (void);
UnityTestsUnitUnityPixbufCacheSuite* unity_tests_unit_unity_pixbuf_cache_suite_construct (GType object_type);
UnityTestsUnitLauncherSuite* unity_tests_unit_launcher_suite_new (void);
UnityTestsUnitLauncherSuite* unity_tests_unit_launcher_suite_construct (GType object_type);
UnityTestsUnitQuicklistSuite* unity_tests_unit_quicklist_suite_new (void);
UnityTestsUnitQuicklistSuite* unity_tests_unit_quicklist_suite_construct (GType object_type);
UnityTestsUnitPanelIndicatorObjectEntryViewSuite* unity_tests_unit_panel_indicator_object_entry_view_suite_new (void);
UnityTestsUnitPanelIndicatorObjectEntryViewSuite* unity_tests_unit_panel_indicator_object_entry_view_suite_construct (GType object_type);
UnityTestsUnitPanelIndicatorObjectViewSuite* unity_tests_unit_panel_indicator_object_view_suite_new (void);
UnityTestsUnitPanelIndicatorObjectViewSuite* unity_tests_unit_panel_indicator_object_view_suite_construct (GType object_type);
UnityTestsUnitPlacesPlaceFileModelSuite* unity_tests_unit_places_place_file_model_suite_new (void);
UnityTestsUnitPlacesPlaceFileModelSuite* unity_tests_unit_places_place_file_model_suite_construct (GType object_type);
UnityTestsUnitPlacesPlaceSuite* unity_tests_unit_places_place_suite_new (void);
UnityTestsUnitPlacesPlaceSuite* unity_tests_unit_places_place_suite_construct (GType object_type);
UnityTestsUnitPlacesSuite* unity_tests_unit_places_suite_new (void);
UnityTestsUnitPlacesSuite* unity_tests_unit_places_suite_construct (GType object_type);
UnityTestsUnitPlaceSuite* unity_tests_unit_place_suite_new (void);
UnityTestsUnitPlaceSuite* unity_tests_unit_place_suite_construct (GType object_type);
UnityTestsUnitPlaceBrowserSuite* unity_tests_unit_place_browser_suite_new (void);
UnityTestsUnitPlaceBrowserSuite* unity_tests_unit_place_browser_suite_construct (GType object_type);
UnityTestsUnitIOSuite* unity_tests_unit_io_suite_new (void);
UnityTestsUnitIOSuite* unity_tests_unit_io_suite_construct (GType object_type);
UnityTestsUnitAppInfoManagerSuite* unity_tests_unit_app_info_manager_suite_new (void);
UnityTestsUnitAppInfoManagerSuite* unity_tests_unit_app_info_manager_suite_construct (GType object_type);
Main* main_new (void);
Main* main_construct (GType object_type);
static void main_finalize (Main* obj);



gint main_main (char** args, int args_length1) {
	gint result = 0;
	UnityTestsUnitUnityPixbufCacheSuite* unity_pixbuf_cache;
	UnityTestsUnitLauncherSuite* launcher;
	UnityTestsUnitQuicklistSuite* quicklists;
	UnityTestsUnitPanelIndicatorObjectEntryViewSuite* panel_object_entry_view_suite;
	UnityTestsUnitPanelIndicatorObjectViewSuite* panel_object_view_suite;
	UnityTestsUnitPlacesPlaceFileModelSuite* place_file_model;
	UnityTestsUnitPlacesPlaceSuite* places_place;
	UnityTestsUnitPlacesSuite* places;
	UnityTestsUnitPlaceSuite* place;
	UnityTestsUnitPlaceBrowserSuite* place_browser;
	UnityTestsUnitIOSuite* io;
	UnityTestsUnitAppInfoManagerSuite* appinfo_manager;
	UnityTestsUnitUnityPixbufCacheSuite* _tmp0_;
	UnityTestsUnitLauncherSuite* _tmp1_;
	UnityTestsUnitQuicklistSuite* _tmp2_;
	UnityTestsUnitPanelIndicatorObjectEntryViewSuite* _tmp3_;
	UnityTestsUnitPanelIndicatorObjectViewSuite* _tmp4_;
	UnityTestsUnitPlacesPlaceFileModelSuite* _tmp5_;
	UnityTestsUnitPlacesPlaceSuite* _tmp6_;
	UnityTestsUnitPlacesSuite* _tmp7_;
	UnityTestsUnitPlaceSuite* _tmp8_;
	UnityTestsUnitPlaceBrowserSuite* _tmp9_;
	UnityTestsUnitIOSuite* _tmp10_;
	UnityTestsUnitAppInfoManagerSuite* _tmp11_;
	unity_pixbuf_cache = NULL;
	launcher = NULL;
	quicklists = NULL;
	panel_object_entry_view_suite = NULL;
	panel_object_view_suite = NULL;
	place_file_model = NULL;
	places_place = NULL;
	places = NULL;
	place = NULL;
	place_browser = NULL;
	io = NULL;
	appinfo_manager = NULL;
	gtk_init (&args_length1, &args);
	ctk_init (&args_length1, &args);
	g_test_init (&args_length1, &args, NULL);
	unity_pixbuf_cache = (_tmp0_ = unity_tests_unit_unity_pixbuf_cache_suite_new (), _g_object_unref0 (unity_pixbuf_cache), _tmp0_);
	launcher = (_tmp1_ = unity_tests_unit_launcher_suite_new (), _unity_tests_unit_launcher_suite_unref0 (launcher), _tmp1_);
	quicklists = (_tmp2_ = unity_tests_unit_quicklist_suite_new (), _unity_tests_unit_quicklist_suite_unref0 (quicklists), _tmp2_);
	panel_object_entry_view_suite = (_tmp3_ = unity_tests_unit_panel_indicator_object_entry_view_suite_new (), _g_object_unref0 (panel_object_entry_view_suite), _tmp3_);
	panel_object_view_suite = (_tmp4_ = unity_tests_unit_panel_indicator_object_view_suite_new (), _g_object_unref0 (panel_object_view_suite), _tmp4_);
	place_file_model = (_tmp5_ = unity_tests_unit_places_place_file_model_suite_new (), _g_object_unref0 (place_file_model), _tmp5_);
	places_place = (_tmp6_ = unity_tests_unit_places_place_suite_new (), _g_object_unref0 (places_place), _tmp6_);
	places = (_tmp7_ = unity_tests_unit_places_suite_new (), _unity_tests_unit_places_suite_unref0 (places), _tmp7_);
	place = (_tmp8_ = unity_tests_unit_place_suite_new (), _unity_tests_unit_place_suite_unref0 (place), _tmp8_);
	place_browser = (_tmp9_ = unity_tests_unit_place_browser_suite_new (), _unity_tests_unit_place_browser_suite_unref0 (place_browser), _tmp9_);
	io = (_tmp10_ = unity_tests_unit_io_suite_new (), _unity_tests_unit_io_suite_unref0 (io), _tmp10_);
	appinfo_manager = (_tmp11_ = unity_tests_unit_app_info_manager_suite_new (), _unity_tests_unit_app_info_manager_suite_unref0 (appinfo_manager), _tmp11_);
	g_test_run ();
	result = 0;
	_unity_tests_unit_app_info_manager_suite_unref0 (appinfo_manager);
	_unity_tests_unit_io_suite_unref0 (io);
	_unity_tests_unit_place_browser_suite_unref0 (place_browser);
	_unity_tests_unit_place_suite_unref0 (place);
	_unity_tests_unit_places_suite_unref0 (places);
	_g_object_unref0 (places_place);
	_g_object_unref0 (place_file_model);
	_g_object_unref0 (panel_object_view_suite);
	_g_object_unref0 (panel_object_entry_view_suite);
	_unity_tests_unit_quicklist_suite_unref0 (quicklists);
	_unity_tests_unit_launcher_suite_unref0 (launcher);
	_g_object_unref0 (unity_pixbuf_cache);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return main_main (argv, argc);
}


Main* main_construct (GType object_type) {
	Main* self;
	self = (Main*) g_type_create_instance (object_type);
	return self;
}


Main* main_new (void) {
	return main_construct (TYPE_MAIN);
}


static void value_main_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_main_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		main_unref (value->data[0].v_pointer);
	}
}


static void value_main_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = main_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_main_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_main_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		Main* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = main_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_main_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	Main** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = main_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_main (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecMain* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_MAIN), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_main (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_MAIN), NULL);
	return value->data[0].v_pointer;
}


void value_set_main (GValue* value, gpointer v_object) {
	Main* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_MAIN));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_MAIN));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		main_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		main_unref (old);
	}
}


void value_take_main (GValue* value, gpointer v_object) {
	Main* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_MAIN));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_MAIN));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		main_unref (old);
	}
}


static void main_class_init (MainClass * klass) {
	main_parent_class = g_type_class_peek_parent (klass);
	MAIN_CLASS (klass)->finalize = main_finalize;
}


static void main_instance_init (Main * self) {
	self->ref_count = 1;
}


static void main_finalize (Main* obj) {
	Main * self;
	self = MAIN (obj);
}


GType main_get_type (void) {
	static volatile gsize main_type_id__volatile = 0;
	if (g_once_init_enter (&main_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_main_init, value_main_free_value, value_main_copy_value, value_main_peek_pointer, "p", value_main_collect_value, "p", value_main_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (MainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) main_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Main), 0, (GInstanceInitFunc) main_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType main_type_id;
		main_type_id = g_type_register_fundamental (g_type_fundamental_next (), "Main", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&main_type_id__volatile, main_type_id);
	}
	return main_type_id__volatile;
}


gpointer main_ref (gpointer instance) {
	Main* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void main_unref (gpointer instance) {
	Main* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		MAIN_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}




