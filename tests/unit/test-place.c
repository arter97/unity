/* test-place.c generated by valac, the Vala compiler
 * generated from test-place.vala, do not modify */

/* -*- Mode: vala; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
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
 * Authored by Mikkel Kamstrup Erlandsen <mikkel.kamstrup@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <unity.h>
#include <stdlib.h>
#include <string.h>
#include <dee.h>
#include <gobject/gvaluecollector.h>


#define UNITY_TESTS_UNIT_TYPE_PLACE_SUITE (unity_tests_unit_place_suite_get_type ())
#define UNITY_TESTS_UNIT_PLACE_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_PLACE_SUITE, UnityTestsUnitPlaceSuite))
#define UNITY_TESTS_UNIT_PLACE_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_PLACE_SUITE, UnityTestsUnitPlaceSuiteClass))
#define UNITY_TESTS_UNIT_IS_PLACE_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_PLACE_SUITE))
#define UNITY_TESTS_UNIT_IS_PLACE_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_PLACE_SUITE))
#define UNITY_TESTS_UNIT_PLACE_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_PLACE_SUITE, UnityTestsUnitPlaceSuiteClass))

typedef struct _UnityTestsUnitPlaceSuite UnityTestsUnitPlaceSuite;
typedef struct _UnityTestsUnitPlaceSuiteClass UnityTestsUnitPlaceSuiteClass;
typedef struct _UnityTestsUnitPlaceSuitePrivate UnityTestsUnitPlaceSuitePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _UnityTestsUnitParamSpecPlaceSuite UnityTestsUnitParamSpecPlaceSuite;

struct _UnityTestsUnitPlaceSuite {
	GTypeInstance parent_instance;
	volatile int ref_count;
	UnityTestsUnitPlaceSuitePrivate * priv;
};

struct _UnityTestsUnitPlaceSuiteClass {
	GTypeClass parent_class;
	void (*finalize) (UnityTestsUnitPlaceSuite *self);
};

struct _UnityTestsUnitParamSpecPlaceSuite {
	GParamSpec parent_instance;
};


static gpointer unity_tests_unit_place_suite_parent_class = NULL;

gpointer unity_tests_unit_place_suite_ref (gpointer instance);
void unity_tests_unit_place_suite_unref (gpointer instance);
GParamSpec* unity_tests_unit_param_spec_place_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_tests_unit_value_set_place_suite (GValue* value, gpointer v_object);
void unity_tests_unit_value_take_place_suite (GValue* value, gpointer v_object);
gpointer unity_tests_unit_value_get_place_suite (const GValue* value);
GType unity_tests_unit_place_suite_get_type (void);
enum  {
	UNITY_TESTS_UNIT_PLACE_SUITE_DUMMY_PROPERTY
};
void unity_tests_unit_place_suite_test_empty_controller (void);
static void _unity_tests_unit_place_suite_test_empty_controller_gdata_test_func (gpointer self);
void unity_tests_unit_place_suite_test_one_entry (void);
static void _unity_tests_unit_place_suite_test_one_entry_gdata_test_func (gpointer self);
void unity_tests_unit_place_suite_test_two_entries (void);
static void _unity_tests_unit_place_suite_test_two_entries_gdata_test_func (gpointer self);
void unity_tests_unit_place_suite_test_local_models (void);
static void _unity_tests_unit_place_suite_test_local_models_gdata_test_func (gpointer self);
UnityTestsUnitPlaceSuite* unity_tests_unit_place_suite_new (void);
UnityTestsUnitPlaceSuite* unity_tests_unit_place_suite_construct (GType object_type);
static void unity_tests_unit_place_suite_finalize (UnityTestsUnitPlaceSuite* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 40 "test-place.vala"
static void _unity_tests_unit_place_suite_test_empty_controller_gdata_test_func (gpointer self) {
#line 95 "test-place.c"
	unity_tests_unit_place_suite_test_empty_controller ();
}


#line 50 "test-place.vala"
static void _unity_tests_unit_place_suite_test_one_entry_gdata_test_func (gpointer self) {
#line 102 "test-place.c"
	unity_tests_unit_place_suite_test_one_entry ();
}


#line 79 "test-place.vala"
static void _unity_tests_unit_place_suite_test_two_entries_gdata_test_func (gpointer self) {
#line 109 "test-place.c"
	unity_tests_unit_place_suite_test_two_entries ();
}


#line 135 "test-place.vala"
static void _unity_tests_unit_place_suite_test_local_models_gdata_test_func (gpointer self) {
#line 116 "test-place.c"
	unity_tests_unit_place_suite_test_local_models ();
}


#line 28 "test-place.vala"
UnityTestsUnitPlaceSuite* unity_tests_unit_place_suite_construct (GType object_type) {
#line 123 "test-place.c"
	UnityTestsUnitPlaceSuite* self;
	self = (UnityTestsUnitPlaceSuite*) g_type_create_instance (object_type);
#line 30 "test-place.vala"
	g_test_add_data_func ("/Unit/Place/Empty", NULL, _unity_tests_unit_place_suite_test_empty_controller_gdata_test_func);
#line 32 "test-place.vala"
	g_test_add_data_func ("/Unit/Place/OneEntry", NULL, _unity_tests_unit_place_suite_test_one_entry_gdata_test_func);
#line 34 "test-place.vala"
	g_test_add_data_func ("/Unit/Place/TwoEntries", NULL, _unity_tests_unit_place_suite_test_two_entries_gdata_test_func);
#line 36 "test-place.vala"
	g_test_add_data_func ("/Unit/Place/LocalModels", NULL, _unity_tests_unit_place_suite_test_local_models_gdata_test_func);
#line 134 "test-place.c"
	return self;
}


#line 28 "test-place.vala"
UnityTestsUnitPlaceSuite* unity_tests_unit_place_suite_new (void) {
#line 28 "test-place.vala"
	return unity_tests_unit_place_suite_construct (UNITY_TESTS_UNIT_TYPE_PLACE_SUITE);
#line 143 "test-place.c"
}


#line 40 "test-place.vala"
void unity_tests_unit_place_suite_test_empty_controller (void) {
#line 149 "test-place.c"
	UnityPlaceController* ctl;
	UnityPlaceEntryInfo* _tmp0_;
#line 42 "test-place.vala"
	ctl = unity_place_controller_new ("/org/ayatana/unity/testplace");
#line 43 "test-place.vala"
	g_assert (UNITY_PLACE_IS_CONTROLLER (ctl));
#line 44 "test-place.vala"
	g_assert (!unity_place_controller_get_exported (ctl));
#line 45 "test-place.vala"
	g_assert (_vala_strcmp0 (unity_place_controller_get_dbus_path (ctl), "/org/ayatana/unity/testplace") == 0);
#line 46 "test-place.vala"
	g_assert (unity_place_controller_num_entries (ctl) == 0);
#line 47 "test-place.vala"
	g_assert ((_tmp0_ = unity_place_controller_get_entry (ctl, "no such entry")) == NULL);
#line 164 "test-place.c"
	_g_object_unref0 (_tmp0_);
	_g_object_unref0 (ctl);
}


#line 50 "test-place.vala"
void unity_tests_unit_place_suite_test_one_entry (void) {
#line 172 "test-place.c"
	char* entry_path;
	UnityPlaceEntryInfo* entry;
	UnityPlaceController* ctl;
	UnityPlaceEntryInfo* _tmp0_;
	char** _tmp2_;
	gint _entry_paths_size_;
	gint entry_paths_length1;
	gint _tmp1_;
	char** entry_paths;
	UnityPlaceEntryInfo** _tmp4_;
	gint _entries_size_;
	gint entries_length1;
	gint _tmp3_;
	UnityPlaceEntryInfo** entries;
	UnityPlaceEntryInfo* _tmp5_;
#line 52 "test-place.vala"
	entry_path = g_strdup ("/org/ayatana/unity/testplace/testentry1");
#line 53 "test-place.vala"
	entry = unity_place_entry_info_new (entry_path);
#line 54 "test-place.vala"
	g_assert (UNITY_PLACE_IS_ENTRY_INFO (entry));
#line 55 "test-place.vala"
	g_assert (_vala_strcmp0 (unity_place_entry_info_get_dbus_path (entry), entry_path) == 0);
#line 57 "test-place.vala"
	ctl = unity_place_controller_new ("/org/ayatana/unity/testplace");
#line 58 "test-place.vala"
	g_assert (unity_place_controller_num_entries (ctl) == 0);
#line 61 "test-place.vala"
	unity_place_controller_add_entry (ctl, entry);
#line 62 "test-place.vala"
	g_assert (unity_place_controller_num_entries (ctl) == 1);
#line 63 "test-place.vala"
	g_assert ((_tmp0_ = unity_place_controller_get_entry (ctl, entry_path)) == entry);
#line 206 "test-place.c"
	_g_object_unref0 (_tmp0_);
	entry_paths = (_tmp2_ = unity_place_controller_get_entry_paths (ctl, &_tmp1_), entry_paths_length1 = _tmp1_, _entry_paths_size_ = entry_paths_length1, _tmp2_);
#line 66 "test-place.vala"
	g_assert (entry_paths_length1 == 1);
#line 67 "test-place.vala"
	g_assert (_vala_strcmp0 (entry_paths[0], entry_path) == 0);
#line 213 "test-place.c"
	entries = (_tmp4_ = unity_place_controller_get_entries (ctl, &_tmp3_), entries_length1 = _tmp3_, _entries_size_ = entries_length1, _tmp4_);
#line 70 "test-place.vala"
	g_assert (entries_length1 == 1);
#line 71 "test-place.vala"
	g_assert (entries[0] == entry);
#line 74 "test-place.vala"
	unity_place_controller_remove_entry (ctl, entry_path);
#line 75 "test-place.vala"
	g_assert (unity_place_controller_num_entries (ctl) == 0);
#line 76 "test-place.vala"
	g_assert ((_tmp5_ = unity_place_controller_get_entry (ctl, entry_path)) == NULL);
#line 225 "test-place.c"
	_g_object_unref0 (_tmp5_);
	_g_free0 (entry_path);
	_g_object_unref0 (entry);
	_g_object_unref0 (ctl);
	entry_paths = (_vala_array_free (entry_paths, entry_paths_length1, (GDestroyNotify) g_free), NULL);
	entries = (_vala_array_free (entries, entries_length1, (GDestroyNotify) g_object_unref), NULL);
}


#line 79 "test-place.vala"
void unity_tests_unit_place_suite_test_two_entries (void) {
#line 237 "test-place.c"
	char* entry_path1;
	char* entry_path2;
	UnityPlaceEntryInfo* entry1;
	UnityPlaceEntryInfo* entry2;
	UnityPlaceController* ctl;
	UnityPlaceEntryInfo* _tmp0_;
	UnityPlaceEntryInfo* _tmp1_;
	char** _tmp3_;
	gint _entry_paths_size_;
	gint entry_paths_length1;
	gint _tmp2_;
	char** entry_paths;
	UnityPlaceEntryInfo** _tmp5_;
	gint _entries_size_;
	gint entries_length1;
	gint _tmp4_;
	UnityPlaceEntryInfo** entries;
	UnityPlaceEntryInfo* _tmp6_;
	UnityPlaceEntryInfo* _tmp7_;
	UnityPlaceEntryInfo* _tmp8_;
	UnityPlaceEntryInfo* _tmp9_;
	char** _tmp11_;
	gint _tmp10_;
	UnityPlaceEntryInfo** _tmp13_;
	gint _tmp12_;
#line 81 "test-place.vala"
	entry_path1 = g_strdup ("/org/ayatana/unity/testplace/testentry1");
#line 82 "test-place.vala"
	entry_path2 = g_strdup ("/org/ayatana/unity/testplace/testentry2");
#line 83 "test-place.vala"
	entry1 = unity_place_entry_info_new (entry_path1);
#line 84 "test-place.vala"
	entry2 = unity_place_entry_info_new (entry_path2);
#line 86 "test-place.vala"
	ctl = unity_place_controller_new ("/org/ayatana/unity/testplace");
#line 87 "test-place.vala"
	g_assert (unity_place_controller_num_entries (ctl) == 0);
#line 89 "test-place.vala"
	unity_place_controller_add_entry (ctl, entry1);
#line 90 "test-place.vala"
	g_assert (unity_place_controller_num_entries (ctl) == 1);
#line 92 "test-place.vala"
	unity_place_controller_add_entry (ctl, entry2);
#line 93 "test-place.vala"
	g_assert (unity_place_controller_num_entries (ctl) == 2);
#line 95 "test-place.vala"
	g_assert ((_tmp0_ = unity_place_controller_get_entry (ctl, entry_path1)) == entry1);
#line 285 "test-place.c"
	_g_object_unref0 (_tmp0_);
#line 96 "test-place.vala"
	g_assert ((_tmp1_ = unity_place_controller_get_entry (ctl, entry_path2)) == entry2);
#line 289 "test-place.c"
	_g_object_unref0 (_tmp1_);
	entry_paths = (_tmp3_ = unity_place_controller_get_entry_paths (ctl, &_tmp2_), entry_paths_length1 = _tmp2_, _entry_paths_size_ = entry_paths_length1, _tmp3_);
#line 99 "test-place.vala"
	g_assert (entry_paths_length1 == 2);
#line 100 "test-place.vala"
	g_assert (_vala_strcmp0 (entry_paths[0], entry_path1) == 0);
#line 101 "test-place.vala"
	g_assert (_vala_strcmp0 (entry_paths[1], entry_path2) == 0);
#line 298 "test-place.c"
	entries = (_tmp5_ = unity_place_controller_get_entries (ctl, &_tmp4_), entries_length1 = _tmp4_, _entries_size_ = entries_length1, _tmp5_);
#line 104 "test-place.vala"
	g_assert (entries_length1 == 2);
#line 105 "test-place.vala"
	g_assert (entries[0] == entry1);
#line 106 "test-place.vala"
	g_assert (entries[1] == entry2);
#line 110 "test-place.vala"
	unity_place_controller_add_entry (ctl, entry1);
#line 111 "test-place.vala"
	g_assert (unity_place_controller_num_entries (ctl) == 2);
#line 113 "test-place.vala"
	unity_place_controller_add_entry (ctl, entry2);
#line 114 "test-place.vala"
	g_assert (unity_place_controller_num_entries (ctl) == 2);
#line 118 "test-place.vala"
	unity_place_controller_remove_entry (ctl, entry_path1);
#line 119 "test-place.vala"
	g_assert (unity_place_controller_num_entries (ctl) == 1);
#line 120 "test-place.vala"
	g_assert ((_tmp6_ = unity_place_controller_get_entry (ctl, entry_path1)) == NULL);
#line 320 "test-place.c"
	_g_object_unref0 (_tmp6_);
#line 121 "test-place.vala"
	g_assert ((_tmp7_ = unity_place_controller_get_entry (ctl, entry_path2)) == entry2);
#line 324 "test-place.c"
	_g_object_unref0 (_tmp7_);
#line 123 "test-place.vala"
	unity_place_controller_remove_entry (ctl, entry_path2);
#line 124 "test-place.vala"
	g_assert (unity_place_controller_num_entries (ctl) == 0);
#line 125 "test-place.vala"
	g_assert ((_tmp8_ = unity_place_controller_get_entry (ctl, entry_path1)) == NULL);
#line 332 "test-place.c"
	_g_object_unref0 (_tmp8_);
#line 126 "test-place.vala"
	g_assert ((_tmp9_ = unity_place_controller_get_entry (ctl, entry_path2)) == NULL);
#line 336 "test-place.c"
	_g_object_unref0 (_tmp9_);
#line 128 "test-place.vala"
	entry_paths = (_tmp11_ = unity_place_controller_get_entry_paths (ctl, &_tmp10_), entry_paths = (_vala_array_free (entry_paths, entry_paths_length1, (GDestroyNotify) g_free), NULL), entry_paths_length1 = _tmp10_, _entry_paths_size_ = entry_paths_length1, _tmp11_);
#line 129 "test-place.vala"
	g_assert (entry_paths_length1 == 0);
#line 131 "test-place.vala"
	entries = (_tmp13_ = unity_place_controller_get_entries (ctl, &_tmp12_), entries = (_vala_array_free (entries, entries_length1, (GDestroyNotify) g_object_unref), NULL), entries_length1 = _tmp12_, _entries_size_ = entries_length1, _tmp13_);
#line 132 "test-place.vala"
	g_assert (entries_length1 == 0);
#line 346 "test-place.c"
	_g_free0 (entry_path1);
	_g_free0 (entry_path2);
	_g_object_unref0 (entry1);
	_g_object_unref0 (entry2);
	_g_object_unref0 (ctl);
	entry_paths = (_vala_array_free (entry_paths, entry_paths_length1, (GDestroyNotify) g_free), NULL);
	entries = (_vala_array_free (entries, entries_length1, (GDestroyNotify) g_object_unref), NULL);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 135 "test-place.vala"
void unity_tests_unit_place_suite_test_local_models (void) {
#line 364 "test-place.c"
	UnityPlaceEntryInfo* entry;
	DeeModel* sections_model;
	UnityPlaceRendererInfo* renderer;
	DeeModel* groups_model;
	DeeModel* results_model;
#line 137 "test-place.vala"
	entry = unity_place_entry_info_new ("/foo/bar");
#line 138 "test-place.vala"
	sections_model = (DeeModel*) ((DeeSequenceModel*) dee_sequence_model_new ((guint) 2, G_TYPE_STRING, G_TYPE_STRING, NULL));
#line 141 "test-place.vala"
	unity_place_entry_info_set_sections_model (entry, sections_model);
#line 142 "test-place.vala"
	g_assert (unity_place_entry_info_get_sections_model (entry) == sections_model);
#line 143 "test-place.vala"
	g_assert (dee_model_get_n_rows (sections_model) == 0);
#line 145 "test-place.vala"
	renderer = _g_object_ref0 (unity_place_entry_info_get_entry_renderer_info (entry));
#line 146 "test-place.vala"
	g_assert (UNITY_PLACE_IS_RENDERER_INFO (renderer));
#line 147 "test-place.vala"
	groups_model = (DeeModel*) ((DeeSequenceModel*) dee_sequence_model_new ((guint) 3, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, NULL));
#line 151 "test-place.vala"
	unity_place_renderer_info_set_groups_model (renderer, groups_model);
#line 152 "test-place.vala"
	g_assert (unity_place_renderer_info_get_groups_model (renderer) == groups_model);
#line 153 "test-place.vala"
	g_assert (dee_model_get_n_rows (groups_model) == 0);
#line 155 "test-place.vala"
	results_model = (DeeModel*) ((DeeSequenceModel*) dee_sequence_model_new ((guint) 6, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_UINT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, NULL));
#line 162 "test-place.vala"
	unity_place_renderer_info_set_results_model (renderer, results_model);
#line 163 "test-place.vala"
	g_assert (unity_place_renderer_info_get_results_model (renderer) == results_model);
#line 164 "test-place.vala"
	g_assert (dee_model_get_n_rows (results_model) == 0);
#line 400 "test-place.c"
	_g_object_unref0 (entry);
	_g_object_unref0 (sections_model);
	_g_object_unref0 (renderer);
	_g_object_unref0 (groups_model);
	_g_object_unref0 (results_model);
}


static void unity_tests_unit_value_place_suite_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void unity_tests_unit_value_place_suite_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		unity_tests_unit_place_suite_unref (value->data[0].v_pointer);
	}
}


static void unity_tests_unit_value_place_suite_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = unity_tests_unit_place_suite_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer unity_tests_unit_value_place_suite_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* unity_tests_unit_value_place_suite_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		UnityTestsUnitPlaceSuite* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = unity_tests_unit_place_suite_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* unity_tests_unit_value_place_suite_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	UnityTestsUnitPlaceSuite** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = unity_tests_unit_place_suite_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* unity_tests_unit_param_spec_place_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	UnityTestsUnitParamSpecPlaceSuite* spec;
	g_return_val_if_fail (g_type_is_a (object_type, UNITY_TESTS_UNIT_TYPE_PLACE_SUITE), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer unity_tests_unit_value_get_place_suite (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_PLACE_SUITE), NULL);
	return value->data[0].v_pointer;
}


void unity_tests_unit_value_set_place_suite (GValue* value, gpointer v_object) {
	UnityTestsUnitPlaceSuite* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_PLACE_SUITE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, UNITY_TESTS_UNIT_TYPE_PLACE_SUITE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		unity_tests_unit_place_suite_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		unity_tests_unit_place_suite_unref (old);
	}
}


void unity_tests_unit_value_take_place_suite (GValue* value, gpointer v_object) {
	UnityTestsUnitPlaceSuite* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_PLACE_SUITE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, UNITY_TESTS_UNIT_TYPE_PLACE_SUITE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		unity_tests_unit_place_suite_unref (old);
	}
}


static void unity_tests_unit_place_suite_class_init (UnityTestsUnitPlaceSuiteClass * klass) {
	unity_tests_unit_place_suite_parent_class = g_type_class_peek_parent (klass);
	UNITY_TESTS_UNIT_PLACE_SUITE_CLASS (klass)->finalize = unity_tests_unit_place_suite_finalize;
}


static void unity_tests_unit_place_suite_instance_init (UnityTestsUnitPlaceSuite * self) {
	self->ref_count = 1;
}


static void unity_tests_unit_place_suite_finalize (UnityTestsUnitPlaceSuite* obj) {
	UnityTestsUnitPlaceSuite * self;
	self = UNITY_TESTS_UNIT_PLACE_SUITE (obj);
}


GType unity_tests_unit_place_suite_get_type (void) {
	static volatile gsize unity_tests_unit_place_suite_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_unit_place_suite_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { unity_tests_unit_value_place_suite_init, unity_tests_unit_value_place_suite_free_value, unity_tests_unit_value_place_suite_copy_value, unity_tests_unit_value_place_suite_peek_pointer, "p", unity_tests_unit_value_place_suite_collect_value, "p", unity_tests_unit_value_place_suite_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUnitPlaceSuiteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_unit_place_suite_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUnitPlaceSuite), 0, (GInstanceInitFunc) unity_tests_unit_place_suite_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType unity_tests_unit_place_suite_type_id;
		unity_tests_unit_place_suite_type_id = g_type_register_fundamental (g_type_fundamental_next (), "UnityTestsUnitPlaceSuite", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&unity_tests_unit_place_suite_type_id__volatile, unity_tests_unit_place_suite_type_id);
	}
	return unity_tests_unit_place_suite_type_id__volatile;
}


gpointer unity_tests_unit_place_suite_ref (gpointer instance) {
	UnityTestsUnitPlaceSuite* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void unity_tests_unit_place_suite_unref (gpointer instance) {
	UnityTestsUnitPlaceSuite* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		UNITY_TESTS_UNIT_PLACE_SUITE_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
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




