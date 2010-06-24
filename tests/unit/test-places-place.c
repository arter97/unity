/* test-places-place.c generated by valac, the Vala compiler
 * generated from test-places-place.vala, do not modify */

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
#include <unity-private.h>


#define UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_SUITE (unity_tests_unit_places_place_suite_get_type ())
#define UNITY_TESTS_UNIT_PLACES_PLACE_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_SUITE, UnityTestsUnitPlacesPlaceSuite))
#define UNITY_TESTS_UNIT_PLACES_PLACE_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_SUITE, UnityTestsUnitPlacesPlaceSuiteClass))
#define UNITY_TESTS_UNIT_IS_PLACES_PLACE_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_SUITE))
#define UNITY_TESTS_UNIT_IS_PLACES_PLACE_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_SUITE))
#define UNITY_TESTS_UNIT_PLACES_PLACE_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_SUITE, UnityTestsUnitPlacesPlaceSuiteClass))

typedef struct _UnityTestsUnitPlacesPlaceSuite UnityTestsUnitPlacesPlaceSuite;
typedef struct _UnityTestsUnitPlacesPlaceSuiteClass UnityTestsUnitPlacesPlaceSuiteClass;
typedef struct _UnityTestsUnitPlacesPlaceSuitePrivate UnityTestsUnitPlacesPlaceSuitePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_key_file_free0(var) ((var == NULL) ? NULL : (var = (g_key_file_free (var), NULL)))

struct _UnityTestsUnitPlacesPlaceSuite {
	GObject parent_instance;
	UnityTestsUnitPlacesPlaceSuitePrivate * priv;
};

struct _UnityTestsUnitPlacesPlaceSuiteClass {
	GObjectClass parent_class;
};


static gpointer unity_tests_unit_places_place_suite_parent_class = NULL;

GType unity_tests_unit_places_place_suite_get_type (void);
enum  {
	UNITY_TESTS_UNIT_PLACES_PLACE_SUITE_DUMMY_PROPERTY
};
#define UNITY_TESTS_UNIT_PLACES_PLACE_SUITE_DOMAIN "/Unit/Places/Place"
static void unity_tests_unit_places_place_suite_test_allocation (UnityTestsUnitPlacesPlaceSuite* self);
static void _unity_tests_unit_places_place_suite_test_allocation_gdata_test_func (gpointer self);
static void unity_tests_unit_places_place_suite_test_simple_placefile (UnityTestsUnitPlacesPlaceSuite* self);
static void _unity_tests_unit_places_place_suite_test_simple_placefile_gdata_test_func (gpointer self);
static void unity_tests_unit_places_place_suite_test_advanced_place_file (UnityTestsUnitPlacesPlaceSuite* self);
static void _unity_tests_unit_places_place_suite_test_advanced_place_file_gdata_test_func (gpointer self);
static void unity_tests_unit_places_place_suite_test_bad_simple_place_file (UnityTestsUnitPlacesPlaceSuite* self);
static void _unity_tests_unit_places_place_suite_test_bad_simple_place_file_gdata_test_func (gpointer self);
static void unity_tests_unit_places_place_suite_test_bad_advanced_place_file (UnityTestsUnitPlacesPlaceSuite* self);
static void _unity_tests_unit_places_place_suite_test_bad_advanced_place_file_gdata_test_func (gpointer self);
UnityTestsUnitPlacesPlaceSuite* unity_tests_unit_places_place_suite_new (void);
UnityTestsUnitPlacesPlaceSuite* unity_tests_unit_places_place_suite_construct (GType object_type);
static int _vala_strcmp0 (const char * str1, const char * str2);



static void _unity_tests_unit_places_place_suite_test_allocation_gdata_test_func (gpointer self) {
	unity_tests_unit_places_place_suite_test_allocation (self);
}


static void _unity_tests_unit_places_place_suite_test_simple_placefile_gdata_test_func (gpointer self) {
	unity_tests_unit_places_place_suite_test_simple_placefile (self);
}


static void _unity_tests_unit_places_place_suite_test_advanced_place_file_gdata_test_func (gpointer self) {
	unity_tests_unit_places_place_suite_test_advanced_place_file (self);
}


static void _unity_tests_unit_places_place_suite_test_bad_simple_place_file_gdata_test_func (gpointer self) {
	unity_tests_unit_places_place_suite_test_bad_simple_place_file (self);
}


static void _unity_tests_unit_places_place_suite_test_bad_advanced_place_file_gdata_test_func (gpointer self) {
	unity_tests_unit_places_place_suite_test_bad_advanced_place_file (self);
}


UnityTestsUnitPlacesPlaceSuite* unity_tests_unit_places_place_suite_construct (GType object_type) {
	UnityTestsUnitPlacesPlaceSuite * self;
	self = (UnityTestsUnitPlacesPlaceSuite*) g_object_new (object_type, NULL);
	unity_testing_logging_init_fatal_handler ();
	g_test_add_data_func (UNITY_TESTS_UNIT_PLACES_PLACE_SUITE_DOMAIN "/Allocation", self, _unity_tests_unit_places_place_suite_test_allocation_gdata_test_func);
	g_test_add_data_func (UNITY_TESTS_UNIT_PLACES_PLACE_SUITE_DOMAIN "/SimplePlaceFile", self, _unity_tests_unit_places_place_suite_test_simple_placefile_gdata_test_func);
	g_test_add_data_func (UNITY_TESTS_UNIT_PLACES_PLACE_SUITE_DOMAIN "/AdvancedPlaceFile", self, _unity_tests_unit_places_place_suite_test_advanced_place_file_gdata_test_func);
	g_test_add_data_func (UNITY_TESTS_UNIT_PLACES_PLACE_SUITE_DOMAIN "/BadSimplePlaceFile", self, _unity_tests_unit_places_place_suite_test_bad_simple_place_file_gdata_test_func);
	g_test_add_data_func (UNITY_TESTS_UNIT_PLACES_PLACE_SUITE_DOMAIN "/BadAdvancedPlaceFile", self, _unity_tests_unit_places_place_suite_test_bad_advanced_place_file_gdata_test_func);
	return self;
}


UnityTestsUnitPlacesPlaceSuite* unity_tests_unit_places_place_suite_new (void) {
	return unity_tests_unit_places_place_suite_construct (UNITY_TESTS_UNIT_TYPE_PLACES_PLACE_SUITE);
}


static void unity_tests_unit_places_place_suite_test_allocation (UnityTestsUnitPlacesPlaceSuite* self) {
	UnityPlacesPlace* place;
	g_return_if_fail (self != NULL);
	place = unity_places_place_new ("__name__", "__path__");
	g_assert (UNITY_PLACES_IS_PLACE (place));
	g_assert (_vala_strcmp0 (unity_places_place_get_dbus_name (place), "__name__") == 0);
	g_assert (_vala_strcmp0 (unity_places_place_get_dbus_path (place), "__path__") == 0);
	_g_object_unref0 (place);
}


static void unity_tests_unit_places_place_suite_test_simple_placefile (UnityTestsUnitPlacesPlaceSuite* self) {
	GError * _inner_error_;
	GKeyFile* file;
	UnityPlacesPlace* place;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	file = g_key_file_new ();
	{
		g_key_file_load_from_file (file, TESTDIR "/data/place0.place", G_KEY_FILE_NONE, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_error ("test-places-place.vala:56: Unable to load test place: %s", e->message);
			_g_error_free0 (e);
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		_g_key_file_free0 (file);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	place = unity_places_place_new_from_keyfile (file, "Unknown");
	g_assert (UNITY_PLACES_IS_PLACE (place));
	g_assert (_vala_strcmp0 (unity_places_place_get_dbus_name (place), "org.ayatana.Unity.Place0") == 0);
	g_assert (_vala_strcmp0 (unity_places_place_get_dbus_path (place), "/org/ayatana/Unity/Place0") == 0);
	g_assert (unity_places_place_get_n_entries (place) == 0);
	_g_key_file_free0 (file);
	_g_object_unref0 (place);
}


static void unity_tests_unit_places_place_suite_test_advanced_place_file (UnityTestsUnitPlacesPlaceSuite* self) {
	GError * _inner_error_;
	GKeyFile* file;
	UnityPlacesPlace* place;
	UnityPlacesPlaceEntry* e;
	UnityPlacesPlaceEntry* _tmp0_;
	UnityPlacesPlaceEntry* _tmp1_;
	UnityPlacesPlaceEntry* _tmp2_;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	file = g_key_file_new ();
	{
		g_key_file_load_from_file (file, TESTDIR "/data/place1.place", G_KEY_FILE_NONE, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch1_g_error;
		}
	}
	goto __finally1;
	__catch1_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("test-places-place.vala:77: Unable to load test place: %s", _error_->message);
			_g_error_free0 (_error_);
		}
	}
	__finally1:
	if (_inner_error_ != NULL) {
		_g_key_file_free0 (file);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	place = unity_places_place_new_from_keyfile (file, "Unknown");
	g_assert (UNITY_PLACES_IS_PLACE (place));
	g_assert (_vala_strcmp0 (unity_places_place_get_dbus_name (place), "org.ayatana.Unity.Place1") == 0);
	g_assert (_vala_strcmp0 (unity_places_place_get_dbus_path (place), "/org/ayatana/Unity/Place1") == 0);
	g_assert (unity_places_place_get_n_entries (place) == 3);
	e = NULL;
	e = (_tmp0_ = unity_places_place_get_nth_entry (place, 0), _g_object_unref0 (e), _tmp0_);
	g_assert (UNITY_PLACES_IS_PLACE_ENTRY (e));
	g_assert (_vala_strcmp0 (unity_places_place_entry_get_dbus_path (e), "/org/ayatana/Unity/Place1/Entry1") == 0);
	g_assert (_vala_strcmp0 (unity_places_place_entry_get_name (e), "One") == 0);
	g_assert (_vala_strcmp0 (unity_places_place_entry_get_icon (e), "gtk-apply") == 0);
	g_assert (_vala_strcmp0 (unity_places_place_entry_get_description (e), "One Description") == 0);
	g_assert (unity_places_place_entry_get_show_global (e) == TRUE);
	g_assert (unity_places_place_entry_get_show_entry (e) == FALSE);
	e = (_tmp1_ = unity_places_place_get_nth_entry (place, 1), _g_object_unref0 (e), _tmp1_);
	g_assert (UNITY_PLACES_IS_PLACE_ENTRY (e));
	g_assert (_vala_strcmp0 (unity_places_place_entry_get_dbus_path (e), "/org/ayatana/Unity/Place1/Entry2") == 0);
	g_assert (_vala_strcmp0 (unity_places_place_entry_get_name (e), "Two") == 0);
	g_assert (_vala_strcmp0 (unity_places_place_entry_get_icon (e), "gtk-close") == 0);
	g_assert (_vala_strcmp0 (unity_places_place_entry_get_description (e), "Two Description") == 0);
	g_assert (unity_places_place_entry_get_show_global (e) == FALSE);
	g_assert (unity_places_place_entry_get_show_entry (e) == TRUE);
	e = (_tmp2_ = unity_places_place_get_nth_entry (place, 2), _g_object_unref0 (e), _tmp2_);
	g_assert (UNITY_PLACES_IS_PLACE_ENTRY (e));
	g_assert (_vala_strcmp0 (unity_places_place_entry_get_dbus_path (e), "/org/ayatana/Unity/Place1/Entry3") == 0);
	g_assert (_vala_strcmp0 (unity_places_place_entry_get_name (e), "Three") == 0);
	g_assert (_vala_strcmp0 (unity_places_place_entry_get_icon (e), "gtk-cancel") == 0);
	g_assert (_vala_strcmp0 (unity_places_place_entry_get_description (e), "Three Description") == 0);
	g_assert (unity_places_place_entry_get_show_global (e) == FALSE);
	g_assert (unity_places_place_entry_get_show_entry (e) == FALSE);
	_g_key_file_free0 (file);
	_g_object_unref0 (place);
	_g_object_unref0 (e);
}


static void unity_tests_unit_places_place_suite_test_bad_simple_place_file (UnityTestsUnitPlacesPlaceSuite* self) {
	GError * _inner_error_;
	GKeyFile* file;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	file = g_key_file_new ();
	{
		g_key_file_load_from_file (file, TESTDIR "/data/place0.badplace", G_KEY_FILE_NONE, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch2_g_error;
		}
	}
	goto __finally2;
	__catch2_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("test-places-place.vala:128: Unable to load test place: %s", _error_->message);
			_g_error_free0 (_error_);
		}
	}
	__finally2:
	if (_inner_error_ != NULL) {
		_g_key_file_free0 (file);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	if (g_test_trap_fork ((guint64) 0, G_TEST_TRAP_SILENCE_STDOUT | G_TEST_TRAP_SILENCE_STDERR)) {
		UnityPlacesPlace* place;
		place = unity_places_place_new_from_keyfile (file, "Unknown");
		g_assert (UNITY_PLACES_IS_PLACE (place));
		exit (0);
		_g_object_unref0 (place);
	}
	g_test_trap_has_passed ();
	g_test_trap_assert_stderr ("*Does not contain 'Place' grou*");
	_g_key_file_free0 (file);
}


static void unity_tests_unit_places_place_suite_test_bad_advanced_place_file (UnityTestsUnitPlacesPlaceSuite* self) {
	GError * _inner_error_;
	GKeyFile* file;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	file = g_key_file_new ();
	{
		g_key_file_load_from_file (file, TESTDIR "/data/place1.badplace", G_KEY_FILE_NONE, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch3_g_error;
		}
	}
	goto __finally3;
	__catch3_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("test-places-place.vala:148: Unable to load test place: %s", _error_->message);
			_g_error_free0 (_error_);
		}
	}
	__finally3:
	if (_inner_error_ != NULL) {
		_g_key_file_free0 (file);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	if (g_test_trap_fork ((guint64) 0, G_TEST_TRAP_SILENCE_STDOUT | G_TEST_TRAP_SILENCE_STDERR)) {
		UnityPlacesPlace* place;
		place = unity_places_place_new_from_keyfile (file, "Unknown");
		g_assert (UNITY_PLACES_IS_PLACE (place));
		exit (0);
		_g_object_unref0 (place);
	}
	g_test_trap_has_passed ();
	g_test_trap_assert_stderr ("*Does not contain valid DBusObjectPat*");
	_g_key_file_free0 (file);
}


static void unity_tests_unit_places_place_suite_class_init (UnityTestsUnitPlacesPlaceSuiteClass * klass) {
	unity_tests_unit_places_place_suite_parent_class = g_type_class_peek_parent (klass);
}


static void unity_tests_unit_places_place_suite_instance_init (UnityTestsUnitPlacesPlaceSuite * self) {
}


GType unity_tests_unit_places_place_suite_get_type (void) {
	static volatile gsize unity_tests_unit_places_place_suite_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_unit_places_place_suite_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUnitPlacesPlaceSuiteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_unit_places_place_suite_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUnitPlacesPlaceSuite), 0, (GInstanceInitFunc) unity_tests_unit_places_place_suite_instance_init, NULL };
		GType unity_tests_unit_places_place_suite_type_id;
		unity_tests_unit_places_place_suite_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityTestsUnitPlacesPlaceSuite", &g_define_type_info, 0);
		g_once_init_leave (&unity_tests_unit_places_place_suite_type_id__volatile, unity_tests_unit_places_place_suite_type_id);
	}
	return unity_tests_unit_places_place_suite_type_id__volatile;
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




