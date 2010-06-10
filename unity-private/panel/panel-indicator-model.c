/* panel-indicator-model.c generated by valac, the Vala compiler
 * generated from panel-indicator-model.vala, do not modify */

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
 * Authored by canonical.com
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <gee.h>
#include <libindicator/indicator-object.h>
#include <stdlib.h>
#include <string.h>
#include <unity-utils.h>
#include <gtk/gtk.h>
#include <gio/gio.h>


#define UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL (unity_panel_indicators_indicators_model_get_type ())
#define UNITY_PANEL_INDICATORS_INDICATORS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL, UnityPanelIndicatorsIndicatorsModel))
#define UNITY_PANEL_INDICATORS_INDICATORS_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL, UnityPanelIndicatorsIndicatorsModelClass))
#define UNITY_PANEL_INDICATORS_IS_INDICATORS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL))
#define UNITY_PANEL_INDICATORS_IS_INDICATORS_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL))
#define UNITY_PANEL_INDICATORS_INDICATORS_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL, UnityPanelIndicatorsIndicatorsModelClass))

typedef struct _UnityPanelIndicatorsIndicatorsModel UnityPanelIndicatorsIndicatorsModel;
typedef struct _UnityPanelIndicatorsIndicatorsModelClass UnityPanelIndicatorsIndicatorsModelClass;
typedef struct _UnityPanelIndicatorsIndicatorsModelPrivate UnityPanelIndicatorsIndicatorsModelPrivate;

#define UNITY_PANEL_INDICATORS_TYPE_INDICATORS_FILE_MODEL (unity_panel_indicators_indicators_file_model_get_type ())
#define UNITY_PANEL_INDICATORS_INDICATORS_FILE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_FILE_MODEL, UnityPanelIndicatorsIndicatorsFileModel))
#define UNITY_PANEL_INDICATORS_INDICATORS_FILE_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_FILE_MODEL, UnityPanelIndicatorsIndicatorsFileModelClass))
#define UNITY_PANEL_INDICATORS_IS_INDICATORS_FILE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_FILE_MODEL))
#define UNITY_PANEL_INDICATORS_IS_INDICATORS_FILE_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_FILE_MODEL))
#define UNITY_PANEL_INDICATORS_INDICATORS_FILE_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_FILE_MODEL, UnityPanelIndicatorsIndicatorsFileModelClass))

typedef struct _UnityPanelIndicatorsIndicatorsFileModel UnityPanelIndicatorsIndicatorsFileModel;
typedef struct _UnityPanelIndicatorsIndicatorsFileModelClass UnityPanelIndicatorsIndicatorsFileModelClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _UnityPanelIndicatorsIndicatorsFileModelPrivate UnityPanelIndicatorsIndicatorsFileModelPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _UnityPanelIndicatorsIndicatorsModel {
	GObject parent_instance;
	UnityPanelIndicatorsIndicatorsModelPrivate * priv;
};

struct _UnityPanelIndicatorsIndicatorsModelClass {
	GObjectClass parent_class;
	GeeArrayList* (*get_indicators) (UnityPanelIndicatorsIndicatorsModel* self);
	char* (*get_indicator_name) (UnityPanelIndicatorsIndicatorsModel* self, IndicatorObject* o);
};

struct _UnityPanelIndicatorsIndicatorsFileModel {
	UnityPanelIndicatorsIndicatorsModel parent_instance;
	UnityPanelIndicatorsIndicatorsFileModelPrivate * priv;
	GeeHashMap* indicator_map;
	GeeArrayList* indicator_list;
};

struct _UnityPanelIndicatorsIndicatorsFileModelClass {
	UnityPanelIndicatorsIndicatorsModelClass parent_class;
};


static UnityPanelIndicatorsIndicatorsModel* unity_panel_indicators_indicators_model__global_model;
static UnityPanelIndicatorsIndicatorsModel* unity_panel_indicators_indicators_model__global_model = NULL;
static gpointer unity_panel_indicators_indicators_model_parent_class = NULL;
extern GeeHashMap* unity_panel_indicators_indicators_file_model_indicator_order;
GeeHashMap* unity_panel_indicators_indicators_file_model_indicator_order = NULL;
static gpointer unity_panel_indicators_indicators_file_model_parent_class = NULL;

GType unity_panel_indicators_indicators_model_get_type (void);
enum  {
	UNITY_PANEL_INDICATORS_INDICATORS_MODEL_DUMMY_PROPERTY
};
UnityPanelIndicatorsIndicatorsFileModel* unity_panel_indicators_indicators_file_model_new (void);
UnityPanelIndicatorsIndicatorsFileModel* unity_panel_indicators_indicators_file_model_construct (GType object_type);
GType unity_panel_indicators_indicators_file_model_get_type (void);
UnityPanelIndicatorsIndicatorsModel* unity_panel_indicators_indicators_model_get_default (void);
void unity_panel_indicators_indicators_model_set_default (UnityPanelIndicatorsIndicatorsModel* model);
GeeArrayList* unity_panel_indicators_indicators_model_get_indicators (UnityPanelIndicatorsIndicatorsModel* self);
static GeeArrayList* unity_panel_indicators_indicators_model_real_get_indicators (UnityPanelIndicatorsIndicatorsModel* self);
char* unity_panel_indicators_indicators_model_get_indicator_name (UnityPanelIndicatorsIndicatorsModel* self, IndicatorObject* o);
static char* unity_panel_indicators_indicators_model_real_get_indicator_name (UnityPanelIndicatorsIndicatorsModel* self, IndicatorObject* o);
UnityPanelIndicatorsIndicatorsModel* unity_panel_indicators_indicators_model_construct (GType object_type);
static void unity_panel_indicators_indicators_model_finalize (GObject* obj);
enum  {
	UNITY_PANEL_INDICATORS_INDICATORS_FILE_MODEL_DUMMY_PROPERTY
};
gint unity_panel_indicators_indicators_file_model_indicator_sort_func (const char* a, const char* b);
static void unity_panel_indicators_indicators_file_model_load_indicator (UnityPanelIndicatorsIndicatorsFileModel* self, const char* filename, const char* leaf);
static GeeArrayList* unity_panel_indicators_indicators_file_model_real_get_indicators (UnityPanelIndicatorsIndicatorsModel* base);
static char* unity_panel_indicators_indicators_file_model_real_get_indicator_name (UnityPanelIndicatorsIndicatorsModel* base, IndicatorObject* o);
static void unity_panel_indicators_indicators_file_model_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


UnityPanelIndicatorsIndicatorsModel* unity_panel_indicators_indicators_model_get_default (void) {
	UnityPanelIndicatorsIndicatorsModel* result = NULL;
	if (unity_panel_indicators_indicators_model__global_model == NULL) {
		UnityPanelIndicatorsIndicatorsModel* _tmp0_;
		unity_panel_indicators_indicators_model__global_model = (_tmp0_ = (UnityPanelIndicatorsIndicatorsModel*) unity_panel_indicators_indicators_file_model_new (), _g_object_unref0 (unity_panel_indicators_indicators_model__global_model), _tmp0_);
	}
	result = _g_object_ref0 (unity_panel_indicators_indicators_model__global_model);
	return result;
}


void unity_panel_indicators_indicators_model_set_default (UnityPanelIndicatorsIndicatorsModel* model) {
	UnityPanelIndicatorsIndicatorsModel* _tmp0_;
	g_return_if_fail (model != NULL);
	unity_panel_indicators_indicators_model__global_model = (_tmp0_ = _g_object_ref0 (model), _g_object_unref0 (unity_panel_indicators_indicators_model__global_model), _tmp0_);
}


static GeeArrayList* unity_panel_indicators_indicators_model_real_get_indicators (UnityPanelIndicatorsIndicatorsModel* self) {
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `unity_panel_indicators_indicators_model_get_indicators'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


GeeArrayList* unity_panel_indicators_indicators_model_get_indicators (UnityPanelIndicatorsIndicatorsModel* self) {
	return UNITY_PANEL_INDICATORS_INDICATORS_MODEL_GET_CLASS (self)->get_indicators (self);
}


static char* unity_panel_indicators_indicators_model_real_get_indicator_name (UnityPanelIndicatorsIndicatorsModel* self, IndicatorObject* o) {
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `unity_panel_indicators_indicators_model_get_indicator_name'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


char* unity_panel_indicators_indicators_model_get_indicator_name (UnityPanelIndicatorsIndicatorsModel* self, IndicatorObject* o) {
	return UNITY_PANEL_INDICATORS_INDICATORS_MODEL_GET_CLASS (self)->get_indicator_name (self, o);
}


UnityPanelIndicatorsIndicatorsModel* unity_panel_indicators_indicators_model_construct (GType object_type) {
	UnityPanelIndicatorsIndicatorsModel * self;
	self = (UnityPanelIndicatorsIndicatorsModel*) g_object_new (object_type, NULL);
	return self;
}


static void unity_panel_indicators_indicators_model_class_init (UnityPanelIndicatorsIndicatorsModelClass * klass) {
	unity_panel_indicators_indicators_model_parent_class = g_type_class_peek_parent (klass);
	UNITY_PANEL_INDICATORS_INDICATORS_MODEL_CLASS (klass)->get_indicators = unity_panel_indicators_indicators_model_real_get_indicators;
	UNITY_PANEL_INDICATORS_INDICATORS_MODEL_CLASS (klass)->get_indicator_name = unity_panel_indicators_indicators_model_real_get_indicator_name;
	G_OBJECT_CLASS (klass)->finalize = unity_panel_indicators_indicators_model_finalize;
}


static void unity_panel_indicators_indicators_model_instance_init (UnityPanelIndicatorsIndicatorsModel * self) {
}


static void unity_panel_indicators_indicators_model_finalize (GObject* obj) {
	UnityPanelIndicatorsIndicatorsModel * self;
	self = UNITY_PANEL_INDICATORS_INDICATORS_MODEL (obj);
	G_OBJECT_CLASS (unity_panel_indicators_indicators_model_parent_class)->finalize (obj);
}


GType unity_panel_indicators_indicators_model_get_type (void) {
	static volatile gsize unity_panel_indicators_indicators_model_type_id__volatile = 0;
	if (g_once_init_enter (&unity_panel_indicators_indicators_model_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPanelIndicatorsIndicatorsModelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_panel_indicators_indicators_model_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPanelIndicatorsIndicatorsModel), 0, (GInstanceInitFunc) unity_panel_indicators_indicators_model_instance_init, NULL };
		GType unity_panel_indicators_indicators_model_type_id;
		unity_panel_indicators_indicators_model_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityPanelIndicatorsIndicatorsModel", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&unity_panel_indicators_indicators_model_type_id__volatile, unity_panel_indicators_indicators_model_type_id);
	}
	return unity_panel_indicators_indicators_model_type_id__volatile;
}


static gboolean string_contains (const char* self, const char* needle) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (needle != NULL, FALSE);
	result = strstr (self, needle) != NULL;
	return result;
}


static char* string_slice (const char* self, glong start, glong end) {
	char* result = NULL;
	glong string_length;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	const char* start_string;
	g_return_val_if_fail (self != NULL, NULL);
	string_length = g_utf8_strlen (self, -1);
	if (start < 0) {
		start = string_length + start;
	}
	if (end < 0) {
		end = string_length + end;
	}
	if (start >= 0) {
		_tmp0_ = start <= string_length;
	} else {
		_tmp0_ = FALSE;
	}
	g_return_val_if_fail (_tmp0_, NULL);
	if (end >= 0) {
		_tmp1_ = end <= string_length;
	} else {
		_tmp1_ = FALSE;
	}
	g_return_val_if_fail (_tmp1_, NULL);
	g_return_val_if_fail (start <= end, NULL);
	start_string = g_utf8_offset_to_pointer (self, start);
	result = g_strndup (start_string, ((gchar*) g_utf8_offset_to_pointer (start_string, end - start)) - ((gchar*) start_string));
	return result;
}


UnityPanelIndicatorsIndicatorsFileModel* unity_panel_indicators_indicators_file_model_construct (GType object_type) {
	GError * _inner_error_;
	UnityPanelIndicatorsIndicatorsFileModel * self;
	char* skip_list;
	GeeHashMap* _tmp0_;
	GeeHashMap* _tmp1_;
	GeeArrayList* _tmp2_;
	char* _tmp3_;
	GFile* dir;
	_inner_error_ = NULL;
	self = (UnityPanelIndicatorsIndicatorsFileModel*) unity_panel_indicators_indicators_model_construct (object_type);
	START_FUNCTION ();
	skip_list = NULL;
	self->indicator_map = (_tmp0_ = gee_hash_map_new (INDICATOR_TYPE_OBJECT, (GBoxedCopyFunc) g_object_ref, g_object_unref, G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL, NULL, NULL), _g_object_unref0 (self->indicator_map), _tmp0_);
	unity_panel_indicators_indicators_file_model_indicator_order = (_tmp1_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, G_TYPE_INT, NULL, NULL, NULL, NULL, NULL), _g_object_unref0 (unity_panel_indicators_indicators_file_model_indicator_order), _tmp1_);
	self->indicator_list = (_tmp2_ = gee_array_list_new (INDICATOR_TYPE_OBJECT, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL), _g_object_unref0 (self->indicator_list), _tmp2_);
	gee_abstract_map_set ((GeeAbstractMap*) unity_panel_indicators_indicators_file_model_indicator_order, "libappmenu.so", GINT_TO_POINTER (1));
	gee_abstract_map_set ((GeeAbstractMap*) unity_panel_indicators_indicators_file_model_indicator_order, "libapplication.so", GINT_TO_POINTER (2));
	gee_abstract_map_set ((GeeAbstractMap*) unity_panel_indicators_indicators_file_model_indicator_order, "libsoundmenu.so", GINT_TO_POINTER (3));
	gee_abstract_map_set ((GeeAbstractMap*) unity_panel_indicators_indicators_file_model_indicator_order, "libmessaging.so", GINT_TO_POINTER (4));
	gee_abstract_map_set ((GeeAbstractMap*) unity_panel_indicators_indicators_file_model_indicator_order, "libdatetime.so", GINT_TO_POINTER (5));
	gee_abstract_map_set ((GeeAbstractMap*) unity_panel_indicators_indicators_file_model_indicator_order, "libme.so", GINT_TO_POINTER (6));
	gee_abstract_map_set ((GeeAbstractMap*) unity_panel_indicators_indicators_file_model_indicator_order, "libsession.so", GINT_TO_POINTER (7));
	skip_list = (_tmp3_ = g_strdup (g_getenv ("UNITY_PANEL_INDICATORS_SKIP")), _g_free0 (skip_list), _tmp3_);
	if (skip_list == NULL) {
		char* _tmp4_;
		skip_list = (_tmp4_ = g_strdup (""), _g_free0 (skip_list), _tmp4_);
	}
	if (_vala_strcmp0 (skip_list, "all") == 0) {
		g_message ("panel-indicator-model.vala:88: Skipping all indicator loading");
		_g_free0 (skip_list);
		return self;
	}
	gtk_icon_theme_append_search_path (gtk_icon_theme_get_default (), INDICATORICONSDIR);
	dir = g_file_new_for_path (INDICATORDIR);
	{
		GFileEnumerator* e;
		GeeArrayList* sos;
		GFileInfo* file_info;
		e = g_file_enumerate_children (dir, G_FILE_ATTRIBUTE_STANDARD_NAME, 0, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch4_g_error;
		}
		sos = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL);
		file_info = NULL;
		while (TRUE) {
			GFileInfo* _tmp5_;
			GFileInfo* _tmp6_;
			char* leaf;
			char* _tmp7_;
			gboolean _tmp8_;
			_tmp5_ = g_file_enumerator_next_file (e, NULL, &_inner_error_);
			if (_inner_error_ != NULL) {
				_g_object_unref0 (e);
				_g_object_unref0 (sos);
				_g_object_unref0 (file_info);
				goto __catch4_g_error;
			}
			if (!((file_info = (_tmp6_ = _tmp5_, _g_object_unref0 (file_info), _tmp6_)) != NULL)) {
				break;
			}
			leaf = g_strdup (g_file_info_get_name (file_info));
			if (string_contains (skip_list, leaf)) {
				_g_free0 (leaf);
				continue;
			}
			if ((_tmp8_ = _vala_strcmp0 (_tmp7_ = string_slice (leaf, g_utf8_strlen (leaf, -1) - 3, g_utf8_strlen (leaf, -1)), ".so") == 0, _g_free0 (_tmp7_), _tmp8_)) {
				gee_abstract_collection_add ((GeeAbstractCollection*) sos, leaf);
			}
			_g_free0 (leaf);
		}
		gee_list_sort ((GeeList*) sos, (GCompareFunc) unity_panel_indicators_indicators_file_model_indicator_sort_func);
		{
			GeeIterator* _leaf_it;
			_leaf_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) sos);
			while (TRUE) {
				char* leaf;
				char* _tmp9_;
				if (!gee_iterator_next (_leaf_it)) {
					break;
				}
				leaf = (char*) gee_iterator_get (_leaf_it);
				unity_panel_indicators_indicators_file_model_load_indicator (self, _tmp9_ = g_strconcat (INDICATORDIR, leaf, NULL), leaf);
				_g_free0 (_tmp9_);
				_g_free0 (leaf);
			}
			_g_object_unref0 (_leaf_it);
		}
		_g_object_unref0 (e);
		_g_object_unref0 (sos);
		_g_object_unref0 (file_info);
	}
	goto __finally4;
	__catch4_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			g_print ("Unable to read indicators: %s\n", _error_->message);
			_g_error_free0 (_error_);
		}
	}
	__finally4:
	if (_inner_error_ != NULL) {
		_g_free0 (skip_list);
		_g_object_unref0 (dir);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	END_FUNCTION ();
	_g_free0 (skip_list);
	_g_object_unref0 (dir);
	return self;
}


UnityPanelIndicatorsIndicatorsFileModel* unity_panel_indicators_indicators_file_model_new (void) {
	return unity_panel_indicators_indicators_file_model_construct (UNITY_PANEL_INDICATORS_TYPE_INDICATORS_FILE_MODEL);
}


gint unity_panel_indicators_indicators_file_model_indicator_sort_func (const char* a, const char* b) {
	gint result = 0;
	g_return_val_if_fail (a != NULL, 0);
	g_return_val_if_fail (b != NULL, 0);
	result = GPOINTER_TO_INT (gee_abstract_map_get ((GeeAbstractMap*) unity_panel_indicators_indicators_file_model_indicator_order, a)) - GPOINTER_TO_INT (gee_abstract_map_get ((GeeAbstractMap*) unity_panel_indicators_indicators_file_model_indicator_order, b));
	return result;
}


static void unity_panel_indicators_indicators_file_model_load_indicator (UnityPanelIndicatorsIndicatorsFileModel* self, const char* filename, const char* leaf) {
	IndicatorObject* o;
	IndicatorObject* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (filename != NULL);
	g_return_if_fail (leaf != NULL);
	o = NULL;
	o = (_tmp0_ = indicator_object_new_from_file (filename), _g_object_unref0 (o), _tmp0_);
	if (INDICATOR_IS_OBJECT (o)) {
		gee_abstract_map_set ((GeeAbstractMap*) self->indicator_map, o, leaf);
		gee_abstract_collection_add ((GeeAbstractCollection*) self->indicator_list, o);
	} else {
		g_warning ("panel-indicator-model.vala:149: Unable to load %s\n", filename);
	}
	_g_object_unref0 (o);
}


static GeeArrayList* unity_panel_indicators_indicators_file_model_real_get_indicators (UnityPanelIndicatorsIndicatorsModel* base) {
	UnityPanelIndicatorsIndicatorsFileModel * self;
	GeeArrayList* result = NULL;
	self = (UnityPanelIndicatorsIndicatorsFileModel*) base;
	result = _g_object_ref0 (self->indicator_list);
	return result;
}


static char* unity_panel_indicators_indicators_file_model_real_get_indicator_name (UnityPanelIndicatorsIndicatorsModel* base, IndicatorObject* o) {
	UnityPanelIndicatorsIndicatorsFileModel * self;
	char* result = NULL;
	self = (UnityPanelIndicatorsIndicatorsFileModel*) base;
	g_return_val_if_fail (o != NULL, NULL);
	result = (char*) gee_abstract_map_get ((GeeAbstractMap*) self->indicator_map, o);
	return result;
}


static void unity_panel_indicators_indicators_file_model_class_init (UnityPanelIndicatorsIndicatorsFileModelClass * klass) {
	unity_panel_indicators_indicators_file_model_parent_class = g_type_class_peek_parent (klass);
	UNITY_PANEL_INDICATORS_INDICATORS_MODEL_CLASS (klass)->get_indicators = unity_panel_indicators_indicators_file_model_real_get_indicators;
	UNITY_PANEL_INDICATORS_INDICATORS_MODEL_CLASS (klass)->get_indicator_name = unity_panel_indicators_indicators_file_model_real_get_indicator_name;
	G_OBJECT_CLASS (klass)->finalize = unity_panel_indicators_indicators_file_model_finalize;
}


static void unity_panel_indicators_indicators_file_model_instance_init (UnityPanelIndicatorsIndicatorsFileModel * self) {
}


static void unity_panel_indicators_indicators_file_model_finalize (GObject* obj) {
	UnityPanelIndicatorsIndicatorsFileModel * self;
	self = UNITY_PANEL_INDICATORS_INDICATORS_FILE_MODEL (obj);
	_g_object_unref0 (self->indicator_map);
	_g_object_unref0 (self->indicator_list);
	G_OBJECT_CLASS (unity_panel_indicators_indicators_file_model_parent_class)->finalize (obj);
}


GType unity_panel_indicators_indicators_file_model_get_type (void) {
	static volatile gsize unity_panel_indicators_indicators_file_model_type_id__volatile = 0;
	if (g_once_init_enter (&unity_panel_indicators_indicators_file_model_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPanelIndicatorsIndicatorsFileModelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_panel_indicators_indicators_file_model_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPanelIndicatorsIndicatorsFileModel), 0, (GInstanceInitFunc) unity_panel_indicators_indicators_file_model_instance_init, NULL };
		GType unity_panel_indicators_indicators_file_model_type_id;
		unity_panel_indicators_indicators_file_model_type_id = g_type_register_static (UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL, "UnityPanelIndicatorsIndicatorsFileModel", &g_define_type_info, 0);
		g_once_init_leave (&unity_panel_indicators_indicators_file_model_type_id__volatile, unity_panel_indicators_indicators_file_model_type_id);
	}
	return unity_panel_indicators_indicators_file_model_type_id__volatile;
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




