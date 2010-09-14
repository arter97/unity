/* test-ui.c generated by valac 0.9.8, the Vala compiler
 * generated from test-ui.vala, do not modify */

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
#include <unity.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <unity-private.h>
#include <gtk/gtk.h>
#include <clutk/clutk.h>
#include <gobject/gvaluecollector.h>


#define UNITY_TESTS_UI_TYPE_TEST_FAVORITES (unity_tests_ui_test_favorites_get_type ())
#define UNITY_TESTS_UI_TEST_FAVORITES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UI_TYPE_TEST_FAVORITES, UnityTestsUITestFavorites))
#define UNITY_TESTS_UI_TEST_FAVORITES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UI_TYPE_TEST_FAVORITES, UnityTestsUITestFavoritesClass))
#define UNITY_TESTS_UI_IS_TEST_FAVORITES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UI_TYPE_TEST_FAVORITES))
#define UNITY_TESTS_UI_IS_TEST_FAVORITES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UI_TYPE_TEST_FAVORITES))
#define UNITY_TESTS_UI_TEST_FAVORITES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UI_TYPE_TEST_FAVORITES, UnityTestsUITestFavoritesClass))

typedef struct _UnityTestsUITestFavorites UnityTestsUITestFavorites;
typedef struct _UnityTestsUITestFavoritesClass UnityTestsUITestFavoritesClass;
typedef struct _UnityTestsUITestFavoritesPrivate UnityTestsUITestFavoritesPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define TYPE_MAIN (main_get_type ())
#define MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MAIN, Main))
#define MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MAIN, MainClass))
#define IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MAIN))
#define IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MAIN))
#define MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MAIN, MainClass))

typedef struct _Main Main;
typedef struct _MainClass MainClass;
typedef struct _MainPrivate MainPrivate;

#define UNITY_TESTS_UI_TYPE_QUICKLIST_SUITE (unity_tests_ui_quicklist_suite_get_type ())
#define UNITY_TESTS_UI_QUICKLIST_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UI_TYPE_QUICKLIST_SUITE, UnityTestsUIQuicklistSuite))
#define UNITY_TESTS_UI_QUICKLIST_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UI_TYPE_QUICKLIST_SUITE, UnityTestsUIQuicklistSuiteClass))
#define UNITY_TESTS_UI_IS_QUICKLIST_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UI_TYPE_QUICKLIST_SUITE))
#define UNITY_TESTS_UI_IS_QUICKLIST_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UI_TYPE_QUICKLIST_SUITE))
#define UNITY_TESTS_UI_QUICKLIST_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UI_TYPE_QUICKLIST_SUITE, UnityTestsUIQuicklistSuiteClass))

typedef struct _UnityTestsUIQuicklistSuite UnityTestsUIQuicklistSuite;
typedef struct _UnityTestsUIQuicklistSuiteClass UnityTestsUIQuicklistSuiteClass;

#define UNITY_TESTS_UI_TYPE_HOME_BUTTON_SUITE (unity_tests_ui_home_button_suite_get_type ())
#define UNITY_TESTS_UI_HOME_BUTTON_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UI_TYPE_HOME_BUTTON_SUITE, UnityTestsUIHomeButtonSuite))
#define UNITY_TESTS_UI_HOME_BUTTON_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UI_TYPE_HOME_BUTTON_SUITE, UnityTestsUIHomeButtonSuiteClass))
#define UNITY_TESTS_UI_IS_HOME_BUTTON_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UI_TYPE_HOME_BUTTON_SUITE))
#define UNITY_TESTS_UI_IS_HOME_BUTTON_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UI_TYPE_HOME_BUTTON_SUITE))
#define UNITY_TESTS_UI_HOME_BUTTON_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UI_TYPE_HOME_BUTTON_SUITE, UnityTestsUIHomeButtonSuiteClass))

typedef struct _UnityTestsUIHomeButtonSuite UnityTestsUIHomeButtonSuite;
typedef struct _UnityTestsUIHomeButtonSuiteClass UnityTestsUIHomeButtonSuiteClass;

#define UNITY_TESTS_UI_TYPE_AUTOMATION_BASIC_TEST_SUITE (unity_tests_ui_automation_basic_test_suite_get_type ())
#define UNITY_TESTS_UI_AUTOMATION_BASIC_TEST_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UI_TYPE_AUTOMATION_BASIC_TEST_SUITE, UnityTestsUIAutomationBasicTestSuite))
#define UNITY_TESTS_UI_AUTOMATION_BASIC_TEST_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UI_TYPE_AUTOMATION_BASIC_TEST_SUITE, UnityTestsUIAutomationBasicTestSuiteClass))
#define UNITY_TESTS_UI_IS_AUTOMATION_BASIC_TEST_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UI_TYPE_AUTOMATION_BASIC_TEST_SUITE))
#define UNITY_TESTS_UI_IS_AUTOMATION_BASIC_TEST_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UI_TYPE_AUTOMATION_BASIC_TEST_SUITE))
#define UNITY_TESTS_UI_AUTOMATION_BASIC_TEST_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UI_TYPE_AUTOMATION_BASIC_TEST_SUITE, UnityTestsUIAutomationBasicTestSuiteClass))

typedef struct _UnityTestsUIAutomationBasicTestSuite UnityTestsUIAutomationBasicTestSuite;
typedef struct _UnityTestsUIAutomationBasicTestSuiteClass UnityTestsUIAutomationBasicTestSuiteClass;

#define UNITY_TESTS_UI_TYPE_INDICATOR_TEST_SUITE (unity_tests_ui_indicator_test_suite_get_type ())
#define UNITY_TESTS_UI_INDICATOR_TEST_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UI_TYPE_INDICATOR_TEST_SUITE, UnityTestsUIIndicatorTestSuite))
#define UNITY_TESTS_UI_INDICATOR_TEST_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UI_TYPE_INDICATOR_TEST_SUITE, UnityTestsUIIndicatorTestSuiteClass))
#define UNITY_TESTS_UI_IS_INDICATOR_TEST_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UI_TYPE_INDICATOR_TEST_SUITE))
#define UNITY_TESTS_UI_IS_INDICATOR_TEST_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UI_TYPE_INDICATOR_TEST_SUITE))
#define UNITY_TESTS_UI_INDICATOR_TEST_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UI_TYPE_INDICATOR_TEST_SUITE, UnityTestsUIIndicatorTestSuiteClass))

typedef struct _UnityTestsUIIndicatorTestSuite UnityTestsUIIndicatorTestSuite;
typedef struct _UnityTestsUIIndicatorTestSuiteClass UnityTestsUIIndicatorTestSuiteClass;
#define _unity_testing_logging_unref0(var) ((var == NULL) ? NULL : (var = (unity_testing_logging_unref (var), NULL)))
typedef struct _ParamSpecMain ParamSpecMain;

struct _UnityTestsUITestFavorites {
	UnityFavorites parent_instance;
	UnityTestsUITestFavoritesPrivate * priv;
};

struct _UnityTestsUITestFavoritesClass {
	UnityFavoritesClass parent_class;
};

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


static gpointer unity_tests_ui_test_favorites_parent_class = NULL;
static gpointer main_parent_class = NULL;

GType unity_tests_ui_test_favorites_get_type (void) G_GNUC_CONST;
enum  {
	UNITY_TESTS_UI_TEST_FAVORITES_DUMMY_PROPERTY
};
static GeeArrayList* unity_tests_ui_test_favorites_real_get_favorites (UnityFavorites* base);
static char* unity_tests_ui_test_favorites_real_find_uid_for_desktop_file (UnityFavorites* base, const char* desktop_file);
static void unity_tests_ui_test_favorites_real_add_favorite (UnityFavorites* base, const char* uid);
static void unity_tests_ui_test_favorites_real_remove_favorite (UnityFavorites* base, const char* uid);
static gboolean unity_tests_ui_test_favorites_real_is_favorite (UnityFavorites* base, const char* uid);
static char* unity_tests_ui_test_favorites_real_get_string (UnityFavorites* base, const char* uid, const char* name);
static void unity_tests_ui_test_favorites_real_set_string (UnityFavorites* base, const char* uid, const char* name, const char* value);
static gint* unity_tests_ui_test_favorites_real_get_int (UnityFavorites* base, const char* uid, const char* name);
static void unity_tests_ui_test_favorites_real_set_int (UnityFavorites* base, const char* uid, const char* name, gint value);
static float* unity_tests_ui_test_favorites_real_get_float (UnityFavorites* base, const char* uid, const char* name);
static void unity_tests_ui_test_favorites_real_set_float (UnityFavorites* base, const char* uid, const char* name, float value);
static gboolean* unity_tests_ui_test_favorites_real_get_bool (UnityFavorites* base, const char* uid, const char* name);
static void unity_tests_ui_test_favorites_real_set_bool (UnityFavorites* base, const char* uid, const char* name, gboolean value);
UnityTestsUITestFavorites* unity_tests_ui_test_favorites_new (void);
UnityTestsUITestFavorites* unity_tests_ui_test_favorites_construct (GType object_type);
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
GType unity_tests_ui_quicklist_suite_get_type (void) G_GNUC_CONST;
GType unity_tests_ui_home_button_suite_get_type (void) G_GNUC_CONST;
GType unity_tests_ui_automation_basic_test_suite_get_type (void) G_GNUC_CONST;
GType unity_tests_ui_indicator_test_suite_get_type (void) G_GNUC_CONST;
UnityTestsUIAutomationBasicTestSuite* unity_tests_ui_automation_basic_test_suite_new (void);
UnityTestsUIAutomationBasicTestSuite* unity_tests_ui_automation_basic_test_suite_construct (GType object_type);
UnityTestsUIQuicklistSuite* unity_tests_ui_quicklist_suite_new (void);
UnityTestsUIQuicklistSuite* unity_tests_ui_quicklist_suite_construct (GType object_type);
UnityTestsUIHomeButtonSuite* unity_tests_ui_home_button_suite_new (void);
UnityTestsUIHomeButtonSuite* unity_tests_ui_home_button_suite_construct (GType object_type);
UnityTestsUIIndicatorTestSuite* unity_tests_ui_indicator_test_suite_new (void);
UnityTestsUIIndicatorTestSuite* unity_tests_ui_indicator_test_suite_construct (GType object_type);
static gboolean _lambda0_ (void);
static gboolean __lambda0__gsource_func (gpointer self);
Main* main_new (void);
Main* main_construct (GType object_type);
static void main_finalize (Main* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



static GeeArrayList* unity_tests_ui_test_favorites_real_get_favorites (UnityFavorites* base) {
	UnityTestsUITestFavorites * self;
	GeeArrayList* result = NULL;
	GeeArrayList* retlist;
	self = (UnityTestsUITestFavorites*) base;
	retlist = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL);
	gee_abstract_collection_add ((GeeAbstractCollection*) retlist, "app-firefox");
	result = retlist;
	return result;
}


static char* unity_tests_ui_test_favorites_real_find_uid_for_desktop_file (UnityFavorites* base, const char* desktop_file) {
	UnityTestsUITestFavorites * self;
	char* result = NULL;
	self = (UnityTestsUITestFavorites*) base;
	g_return_val_if_fail (desktop_file != NULL, NULL);
	result = g_strdup ("app-firefox");
	return result;
}


static void unity_tests_ui_test_favorites_real_add_favorite (UnityFavorites* base, const char* uid) {
	UnityTestsUITestFavorites * self;
	self = (UnityTestsUITestFavorites*) base;
	g_return_if_fail (uid != NULL);
}


static void unity_tests_ui_test_favorites_real_remove_favorite (UnityFavorites* base, const char* uid) {
	UnityTestsUITestFavorites * self;
	self = (UnityTestsUITestFavorites*) base;
	g_return_if_fail (uid != NULL);
}


static gboolean unity_tests_ui_test_favorites_real_is_favorite (UnityFavorites* base, const char* uid) {
	UnityTestsUITestFavorites * self;
	gboolean result = FALSE;
	self = (UnityTestsUITestFavorites*) base;
	g_return_val_if_fail (uid != NULL, FALSE);
	result = TRUE;
	return result;
}


static char* unity_tests_ui_test_favorites_real_get_string (UnityFavorites* base, const char* uid, const char* name) {
	UnityTestsUITestFavorites * self;
	char* result = NULL;
	self = (UnityTestsUITestFavorites*) base;
	g_return_val_if_fail (uid != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	if (_vala_strcmp0 (name, "type") == 0) {
		result = g_strdup ("application");
		return result;
	}
	result = g_strdup ("/usr/share/applications/firefox.desktop");
	return result;
}


static void unity_tests_ui_test_favorites_real_set_string (UnityFavorites* base, const char* uid, const char* name, const char* value) {
	UnityTestsUITestFavorites * self;
	self = (UnityTestsUITestFavorites*) base;
	g_return_if_fail (uid != NULL);
	g_return_if_fail (name != NULL);
	g_return_if_fail (value != NULL);
}


static gint* unity_tests_ui_test_favorites_real_get_int (UnityFavorites* base, const char* uid, const char* name) {
	UnityTestsUITestFavorites * self;
	gint* result = NULL;
	self = (UnityTestsUITestFavorites*) base;
	g_return_val_if_fail (uid != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	result = NULL;
	return result;
}


static void unity_tests_ui_test_favorites_real_set_int (UnityFavorites* base, const char* uid, const char* name, gint value) {
	UnityTestsUITestFavorites * self;
	self = (UnityTestsUITestFavorites*) base;
	g_return_if_fail (uid != NULL);
	g_return_if_fail (name != NULL);
}


static float* unity_tests_ui_test_favorites_real_get_float (UnityFavorites* base, const char* uid, const char* name) {
	UnityTestsUITestFavorites * self;
	float* result = NULL;
	self = (UnityTestsUITestFavorites*) base;
	g_return_val_if_fail (uid != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	result = NULL;
	return result;
}


static void unity_tests_ui_test_favorites_real_set_float (UnityFavorites* base, const char* uid, const char* name, float value) {
	UnityTestsUITestFavorites * self;
	self = (UnityTestsUITestFavorites*) base;
	g_return_if_fail (uid != NULL);
	g_return_if_fail (name != NULL);
}


static gboolean* unity_tests_ui_test_favorites_real_get_bool (UnityFavorites* base, const char* uid, const char* name) {
	UnityTestsUITestFavorites * self;
	gboolean* result = NULL;
	self = (UnityTestsUITestFavorites*) base;
	g_return_val_if_fail (uid != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	result = NULL;
	return result;
}


static void unity_tests_ui_test_favorites_real_set_bool (UnityFavorites* base, const char* uid, const char* name, gboolean value) {
	UnityTestsUITestFavorites * self;
	self = (UnityTestsUITestFavorites*) base;
	g_return_if_fail (uid != NULL);
	g_return_if_fail (name != NULL);
}


UnityTestsUITestFavorites* unity_tests_ui_test_favorites_construct (GType object_type) {
	UnityTestsUITestFavorites * self;
	self = (UnityTestsUITestFavorites*) unity_favorites_construct (object_type);
	return self;
}


UnityTestsUITestFavorites* unity_tests_ui_test_favorites_new (void) {
	return unity_tests_ui_test_favorites_construct (UNITY_TESTS_UI_TYPE_TEST_FAVORITES);
}


static void unity_tests_ui_test_favorites_class_init (UnityTestsUITestFavoritesClass * klass) {
	unity_tests_ui_test_favorites_parent_class = g_type_class_peek_parent (klass);
	UNITY_FAVORITES_CLASS (klass)->get_favorites = unity_tests_ui_test_favorites_real_get_favorites;
	UNITY_FAVORITES_CLASS (klass)->find_uid_for_desktop_file = unity_tests_ui_test_favorites_real_find_uid_for_desktop_file;
	UNITY_FAVORITES_CLASS (klass)->add_favorite = unity_tests_ui_test_favorites_real_add_favorite;
	UNITY_FAVORITES_CLASS (klass)->remove_favorite = unity_tests_ui_test_favorites_real_remove_favorite;
	UNITY_FAVORITES_CLASS (klass)->is_favorite = unity_tests_ui_test_favorites_real_is_favorite;
	UNITY_FAVORITES_CLASS (klass)->get_string = unity_tests_ui_test_favorites_real_get_string;
	UNITY_FAVORITES_CLASS (klass)->set_string = unity_tests_ui_test_favorites_real_set_string;
	UNITY_FAVORITES_CLASS (klass)->get_int = unity_tests_ui_test_favorites_real_get_int;
	UNITY_FAVORITES_CLASS (klass)->set_int = unity_tests_ui_test_favorites_real_set_int;
	UNITY_FAVORITES_CLASS (klass)->get_float = unity_tests_ui_test_favorites_real_get_float;
	UNITY_FAVORITES_CLASS (klass)->set_float = unity_tests_ui_test_favorites_real_set_float;
	UNITY_FAVORITES_CLASS (klass)->get_bool = unity_tests_ui_test_favorites_real_get_bool;
	UNITY_FAVORITES_CLASS (klass)->set_bool = unity_tests_ui_test_favorites_real_set_bool;
}


static void unity_tests_ui_test_favorites_instance_init (UnityTestsUITestFavorites * self) {
}


GType unity_tests_ui_test_favorites_get_type (void) {
	static volatile gsize unity_tests_ui_test_favorites_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_ui_test_favorites_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUITestFavoritesClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_ui_test_favorites_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUITestFavorites), 0, (GInstanceInitFunc) unity_tests_ui_test_favorites_instance_init, NULL };
		GType unity_tests_ui_test_favorites_type_id;
		unity_tests_ui_test_favorites_type_id = g_type_register_static (UNITY_TYPE_FAVORITES, "UnityTestsUITestFavorites", &g_define_type_info, 0);
		g_once_init_leave (&unity_tests_ui_test_favorites_type_id__volatile, unity_tests_ui_test_favorites_type_id);
	}
	return unity_tests_ui_test_favorites_type_id__volatile;
}


static gboolean _lambda0_ (void) {
	gboolean result = FALSE;
	g_test_run ();
	gtk_main_quit ();
	result = FALSE;
	return result;
}


static gboolean __lambda0__gsource_func (gpointer self) {
	gboolean result;
	result = _lambda0_ ();
	return result;
}


gint main_main (char** args, int args_length1) {
	gint result = 0;
	UnityTestingLogging* logger;
	UnityTestsUIQuicklistSuite* quicklist_suite;
	UnityTestsUIHomeButtonSuite* home_button_suite;
	UnityTestsUIAutomationBasicTestSuite* basic_test_suite;
	UnityTestsUIIndicatorTestSuite* indicator_test_suite;
	UnityTestingLogging* _tmp0_;
	UnityTestsUIAutomationBasicTestSuite* _tmp1_;
	UnityTestsUIQuicklistSuite* _tmp2_;
	UnityTestsUIHomeButtonSuite* _tmp3_;
	UnityTestsUIIndicatorTestSuite* _tmp4_;
	logger = NULL;
	quicklist_suite = NULL;
	home_button_suite = NULL;
	basic_test_suite = NULL;
	indicator_test_suite = NULL;
	g_setenv ("UNITY_DISABLE_TRAY", "1", TRUE);
	g_setenv ("UNITY_DISABLE_IDLES", "1", TRUE);
	g_setenv ("UNITY_PANEL_INDICATORS_SKIP", "all", TRUE);
	gtk_init (&args_length1, &args);
	g_object_set (gtk_settings_get_default (), "gtk-xft-dpi", 96 * 1024, NULL);
	ctk_init (&args_length1, &args);
	g_test_init (&args_length1, &args, NULL);
	logger = (_tmp0_ = unity_testing_logging_new (), _unity_testing_logging_unref0 (logger), _tmp0_);
	basic_test_suite = (_tmp1_ = unity_tests_ui_automation_basic_test_suite_new (), _g_object_unref0 (basic_test_suite), _tmp1_);
	quicklist_suite = (_tmp2_ = unity_tests_ui_quicklist_suite_new (), _g_object_unref0 (quicklist_suite), _tmp2_);
	home_button_suite = (_tmp3_ = unity_tests_ui_home_button_suite_new (), _g_object_unref0 (home_button_suite), _tmp3_);
	indicator_test_suite = (_tmp4_ = unity_tests_ui_indicator_test_suite_new (), _g_object_unref0 (indicator_test_suite), _tmp4_);
	g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) 3, __lambda0__gsource_func, NULL, NULL);
	gtk_main ();
	result = 0;
	_g_object_unref0 (indicator_test_suite);
	_g_object_unref0 (basic_test_suite);
	_g_object_unref0 (home_button_suite);
	_g_object_unref0 (quicklist_suite);
	_unity_testing_logging_unref0 (logger);
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
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
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


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




