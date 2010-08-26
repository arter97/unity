/* unity-pixbuf-cache.c generated by valac 0.9.7, the Vala compiler
 * generated from unity-pixbuf-cache.vala, do not modify */

/*
 * Copyright (C) 2010 Canonical, Ltd.
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License
 * version 3.0 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3.0 for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see
  <http://www.gnu.org/licenses/>.
 *
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gee.h>
#include <gdk-pixbuf/gdk-pixdata.h>
#include <clutter/clutter.h>
#include <gio/gio.h>
#include <clutk/clutk.h>


#define UNITY_TYPE_PIXBUF_CACHE (unity_pixbuf_cache_get_type ())
#define UNITY_PIXBUF_CACHE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_PIXBUF_CACHE, UnityPixbufCache))
#define UNITY_PIXBUF_CACHE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_PIXBUF_CACHE, UnityPixbufCacheClass))
#define UNITY_IS_PIXBUF_CACHE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_PIXBUF_CACHE))
#define UNITY_IS_PIXBUF_CACHE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_PIXBUF_CACHE))
#define UNITY_PIXBUF_CACHE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_PIXBUF_CACHE, UnityPixbufCacheClass))

typedef struct _UnityPixbufCache UnityPixbufCache;
typedef struct _UnityPixbufCacheClass UnityPixbufCacheClass;
typedef struct _UnityPixbufCachePrivate UnityPixbufCachePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_TYPE_SHELL (unity_shell_get_type ())
#define UNITY_SHELL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_SHELL, UnityShell))
#define UNITY_IS_SHELL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_SHELL))
#define UNITY_SHELL_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_TYPE_SHELL, UnityShellIface))

typedef struct _UnityShell UnityShell;
typedef struct _UnityShellIface UnityShellIface;

#define UNITY_TYPE_SHELL_MODE (unity_shell_mode_get_type ())

#define UNITY_TYPE_WINDOW_ACTION (unity_window_action_get_type ())
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _UnityPixbufCacheSetImageFromIconNameData UnityPixbufCacheSetImageFromIconNameData;
#define _gtk_icon_info_free0(var) ((var == NULL) ? NULL : (var = (gtk_icon_info_free (var), NULL)))
typedef struct _UnityPixbufCacheSetImageFromGiconStringData UnityPixbufCacheSetImageFromGiconStringData;
typedef struct _UnityPixbufCacheSetImageFromGiconData UnityPixbufCacheSetImageFromGiconData;

struct _UnityPixbufCache {
	GObject parent_instance;
	UnityPixbufCachePrivate * priv;
};

struct _UnityPixbufCacheClass {
	GObjectClass parent_class;
};

struct _UnityPixbufCachePrivate {
	GtkIconTheme* theme;
	GeeHashMap* cache;
	gboolean autodispose;
};

typedef enum  {
	UNITY_SHELL_MODE_MINIMIZED,
	UNITY_SHELL_MODE_DASH,
	UNITY_SHELL_MODE_EXPOSE
} UnityShellMode;

typedef enum  {
	UNITY_WINDOW_ACTION_CLOSE,
	UNITY_WINDOW_ACTION_MINIMIZE,
	UNITY_WINDOW_ACTION_MAXIMIZE,
	UNITY_WINDOW_ACTION_UNMAXIMIZE
} UnityWindowAction;

struct _UnityShellIface {
	GTypeInterface parent_iface;
	guint32 (*get_current_time) (UnityShell* self);
	UnityShellMode (*get_mode) (UnityShell* self);
	ClutterStage* (*get_stage) (UnityShell* self);
	void (*show_unity) (UnityShell* self);
	void (*hide_unity) (UnityShell* self);
	gint (*get_indicators_width) (UnityShell* self);
	gint (*get_launcher_width_foobar) (UnityShell* self);
	gint (*get_panel_height_foobar) (UnityShell* self);
	void (*ensure_input_region) (UnityShell* self);
	void (*add_fullscreen_request) (UnityShell* self, GObject* o);
	gboolean (*remove_fullscreen_request) (UnityShell* self, GObject* o);
	void (*grab_keyboard) (UnityShell* self, gboolean grab, guint32 timestamp);
	void (*about_to_show_places) (UnityShell* self);
	void (*close_xids) (UnityShell* self, GArray* xids);
	void (*show_window) (UnityShell* self, guint32 xid);
	void (*expose_xids) (UnityShell* self, GArray* xids);
	void (*stop_expose) (UnityShell* self);
	void (*get_window_details) (UnityShell* self, guint32 xid, gboolean* allows_resize, gboolean* is_maximised);
	void (*do_window_action) (UnityShell* self, guint32 xid, UnityWindowAction action);
	gboolean (*get_menus_swallow_events) (UnityShell* self);
	gboolean (*get_super_key_active) (UnityShell* self);
	void (*set_super_key_active) (UnityShell* self, gboolean value);
	gboolean (*get_is_starting) (UnityShell* self);
	void (*set_is_starting) (UnityShell* self, gboolean value);
};

struct _UnityPixbufCacheSetImageFromIconNameData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	UnityPixbufCache* self;
	CtkImage* image;
	char* icon_name;
	gint size;
	char* key;
	GdkPixbuf* ret;
	GdkPixbuf* _tmp0_;
	GdkPixbuf* _tmp1_;
	GError * e;
	GError * _inner_error_;
};

struct _UnityPixbufCacheSetImageFromGiconStringData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	UnityPixbufCache* self;
	CtkImage* image;
	char* gicon_as_string;
	gint size;
	char* key;
	GdkPixbuf* ret;
	GdkPixbuf* _tmp0_;
	GdkPixbuf* _tmp1_;
	char* _tmp2_;
	GError * err;
	GIcon* icon;
	GtkIconInfo* info;
	GdkPixbuf* _tmp3_;
	GdkPixbuf* _tmp4_;
	gboolean _tmp5_;
	gboolean _tmp6_;
	gboolean _tmp7_;
	char* real_name;
	GdkPixbuf* _tmp8_;
	GdkPixbuf* _tmp9_;
	char* _tmp10_;
	GError * e;
	GError * _inner_error_;
};

struct _UnityPixbufCacheSetImageFromGiconData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	UnityPixbufCache* self;
	CtkImage* image;
	GIcon* icon;
	gint size;
};


extern UnityPixbufCache* unity__pixbuf_cache;
UnityPixbufCache* unity__pixbuf_cache = NULL;
extern UnityShell* unity_global_shell;
static gpointer unity_pixbuf_cache_parent_class = NULL;

#define UNITY_hash_template "%s%d"
GType unity_pixbuf_cache_get_type (void) G_GNUC_CONST;
#define UNITY_PIXBUF_CACHE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TYPE_PIXBUF_CACHE, UnityPixbufCachePrivate))
enum  {
	UNITY_PIXBUF_CACHE_DUMMY_PROPERTY,
	UNITY_PIXBUF_CACHE_SIZE
};
UnityPixbufCache* unity_pixbuf_cache_new (gboolean _autodispose);
UnityPixbufCache* unity_pixbuf_cache_construct (GType object_type, gboolean _autodispose);
GType unity_shell_mode_get_type (void) G_GNUC_CONST;
GType unity_window_action_get_type (void) G_GNUC_CONST;
GType unity_shell_get_type (void) G_GNUC_CONST;
static void unity_pixbuf_cache_on_shell_destroyed (UnityPixbufCache* self);
static void _unity_pixbuf_cache_on_shell_destroyed_gweak_notify (gpointer self, GObject* object);
UnityPixbufCache* unity_pixbuf_cache_get_default (void);
void unity_pixbuf_cache_set (UnityPixbufCache* self, const char* icon_id, GdkPixbuf* pixbuf, gint size);
GdkPixbuf* unity_pixbuf_cache_get (UnityPixbufCache* self, const char* icon_id, gint size);
void unity_pixbuf_cache_clear (UnityPixbufCache* self);
static void unity_pixbuf_cache_set_image_from_icon_name_data_free (gpointer _data);
static void unity_pixbuf_cache_set_image_from_icon_name_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
void unity_pixbuf_cache_set_image_from_icon_name (UnityPixbufCache* self, CtkImage* image, const char* icon_name, gint size, GAsyncReadyCallback _callback_, gpointer _user_data_);
void unity_pixbuf_cache_set_image_from_icon_name_finish (UnityPixbufCache* self, GAsyncResult* _res_);
static gboolean unity_pixbuf_cache_set_image_from_icon_name_co (UnityPixbufCacheSetImageFromIconNameData* data);
static gboolean _unity_pixbuf_cache_set_image_from_icon_name_co_gsource_func (gpointer self);
static void unity_pixbuf_cache_set_image_from_gicon_string_data_free (gpointer _data);
static void unity_pixbuf_cache_set_image_from_gicon_string_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
void unity_pixbuf_cache_set_image_from_gicon_string (UnityPixbufCache* self, CtkImage* image, const char* gicon_as_string, gint size, GAsyncReadyCallback _callback_, gpointer _user_data_);
void unity_pixbuf_cache_set_image_from_gicon_string_finish (UnityPixbufCache* self, GAsyncResult* _res_);
static gboolean unity_pixbuf_cache_set_image_from_gicon_string_co (UnityPixbufCacheSetImageFromGiconStringData* data);
void unity_pixbuf_cache_set_image_from_gicon (UnityPixbufCache* self, CtkImage* image, GIcon* icon, gint size, GAsyncReadyCallback _callback_, gpointer _user_data_);
void unity_pixbuf_cache_set_image_from_gicon_finish (UnityPixbufCache* self, GAsyncResult* _res_);
static gboolean _unity_pixbuf_cache_set_image_from_gicon_string_co_gsource_func (gpointer self);
static void unity_pixbuf_cache_set_image_from_gicon_data_free (gpointer _data);
static void unity_pixbuf_cache_set_image_from_gicon_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gboolean unity_pixbuf_cache_set_image_from_gicon_co (UnityPixbufCacheSetImageFromGiconData* data);
guint unity_pixbuf_cache_get_size (UnityPixbufCache* self);
static GObject * unity_pixbuf_cache_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_pixbuf_cache_finalize (GObject* obj);
static void unity_pixbuf_cache_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);



static void _unity_pixbuf_cache_on_shell_destroyed_gweak_notify (gpointer self, GObject* object) {
	unity_pixbuf_cache_on_shell_destroyed (self);
}


UnityPixbufCache* unity_pixbuf_cache_construct (GType object_type, gboolean _autodispose) {
	UnityPixbufCache * self;
	self = (UnityPixbufCache*) g_object_new (object_type, NULL);
	self->priv->autodispose = _autodispose;
	if (self->priv->autodispose) {
		if (UNITY_IS_SHELL (unity_global_shell)) {
			g_object_weak_ref ((GObject*) unity_global_shell, _unity_pixbuf_cache_on_shell_destroyed_gweak_notify, self);
		}
	}
	return self;
}


UnityPixbufCache* unity_pixbuf_cache_new (gboolean _autodispose) {
	return unity_pixbuf_cache_construct (UNITY_TYPE_PIXBUF_CACHE, _autodispose);
}


static void unity_pixbuf_cache_on_shell_destroyed (UnityPixbufCache* self) {
	g_return_if_fail (self != NULL);
	if (unity__pixbuf_cache == self) {
		UnityPixbufCache* _tmp0_;
		unity__pixbuf_cache = (_tmp0_ = NULL, _g_object_unref0 (unity__pixbuf_cache), _tmp0_);
	} else {
		g_object_unref ((GObject*) self);
	}
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


UnityPixbufCache* unity_pixbuf_cache_get_default (void) {
	UnityPixbufCache* result = NULL;
	if (unity__pixbuf_cache == NULL) {
		UnityPixbufCache* _tmp0_;
		unity__pixbuf_cache = (_tmp0_ = unity_pixbuf_cache_new (TRUE), _g_object_unref0 (unity__pixbuf_cache), _tmp0_);
	}
	result = _g_object_ref0 (unity__pixbuf_cache);
	return result;
}


void unity_pixbuf_cache_set (UnityPixbufCache* self, const char* icon_id, GdkPixbuf* pixbuf, gint size) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (icon_id != NULL);
	g_return_if_fail (pixbuf != NULL);
	gee_abstract_map_set ((GeeAbstractMap*) self->priv->cache, _tmp0_ = g_strdup_printf (UNITY_hash_template, icon_id, size), pixbuf);
	_g_free0 (_tmp0_);
}


GdkPixbuf* unity_pixbuf_cache_get (UnityPixbufCache* self, const char* icon_id, gint size) {
	GdkPixbuf* result = NULL;
	char* _tmp0_;
	GdkPixbuf* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (icon_id != NULL, NULL);
	result = (_tmp1_ = (GdkPixbuf*) gee_abstract_map_get ((GeeAbstractMap*) self->priv->cache, _tmp0_ = g_strdup_printf (UNITY_hash_template, icon_id, size)), _g_free0 (_tmp0_), _tmp1_);
	return result;
}


void unity_pixbuf_cache_clear (UnityPixbufCache* self) {
	g_return_if_fail (self != NULL);
	gee_abstract_map_clear ((GeeAbstractMap*) self->priv->cache);
}


static void unity_pixbuf_cache_set_image_from_icon_name_data_free (gpointer _data) {
	UnityPixbufCacheSetImageFromIconNameData* data;
	data = _data;
	_g_object_unref0 (data->image);
	_g_free0 (data->icon_name);
	g_object_unref (data->self);
	g_slice_free (UnityPixbufCacheSetImageFromIconNameData, data);
}


void unity_pixbuf_cache_set_image_from_icon_name (UnityPixbufCache* self, CtkImage* image, const char* icon_name, gint size, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UnityPixbufCacheSetImageFromIconNameData* _data_;
	_data_ = g_slice_new0 (UnityPixbufCacheSetImageFromIconNameData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, unity_pixbuf_cache_set_image_from_icon_name);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, unity_pixbuf_cache_set_image_from_icon_name_data_free);
	_data_->self = g_object_ref (self);
	_data_->image = _g_object_ref0 (image);
	_data_->icon_name = g_strdup (icon_name);
	_data_->size = size;
	unity_pixbuf_cache_set_image_from_icon_name_co (_data_);
}


void unity_pixbuf_cache_set_image_from_icon_name_finish (UnityPixbufCache* self, GAsyncResult* _res_) {
	UnityPixbufCacheSetImageFromIconNameData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void unity_pixbuf_cache_set_image_from_icon_name_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	UnityPixbufCacheSetImageFromIconNameData* data;
	data = _user_data_;
	data->_res_ = _res_;
	unity_pixbuf_cache_set_image_from_icon_name_co (data);
}


static gboolean _unity_pixbuf_cache_set_image_from_icon_name_co_gsource_func (gpointer self) {
	gboolean result;
	result = unity_pixbuf_cache_set_image_from_icon_name_co (self);
	return result;
}


static gboolean unity_pixbuf_cache_set_image_from_icon_name_co (UnityPixbufCacheSetImageFromIconNameData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
		case 10:
		goto _state_10;
	}
	_state_0:
	data->key = g_strdup_printf (UNITY_hash_template, data->icon_name, data->size);
	data->ret = (GdkPixbuf*) gee_abstract_map_get ((GeeAbstractMap*) data->self->priv->cache, data->key);
	if (GDK_IS_PIXBUF (data->ret)) {
		ctk_image_set_from_pixbuf (data->image, data->ret);
		_g_object_unref0 (data->ret);
		_g_free0 (data->key);
		{
			if (data->_state_ == 0) {
				g_simple_async_result_complete_in_idle (data->_async_result);
			} else {
				g_simple_async_result_complete (data->_async_result);
			}
			g_object_unref (data->_async_result);
			return FALSE;
		}
	}
	g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _unity_pixbuf_cache_set_image_from_icon_name_co_gsource_func, data, NULL);
	data->_state_ = 10;
	return FALSE;
	_state_10:
	;
	if (data->ret == NULL) {
		{
			data->_tmp0_ = gtk_icon_theme_load_icon (data->self->priv->theme, data->icon_name, data->size, 0, &data->_inner_error_);
			if (data->_inner_error_ != NULL) {
				goto __catch33_g_error;
			}
			data->ret = (data->_tmp1_ = _g_object_ref0 (data->_tmp0_), _g_object_unref0 (data->ret), data->_tmp1_);
			if (GDK_IS_PIXBUF (data->ret)) {
				gee_abstract_map_set ((GeeAbstractMap*) data->self->priv->cache, data->key, data->ret);
			}
		}
		goto __finally33;
		__catch33_g_error:
		{
			data->e = data->_inner_error_;
			data->_inner_error_ = NULL;
			{
				g_warning ("unity-pixbuf-cache.vala:132: Unable to load icon_name: %s", data->e->message);
				_g_error_free0 (data->e);
			}
		}
		__finally33:
		if (data->_inner_error_ != NULL) {
			_g_object_unref0 (data->ret);
			_g_free0 (data->key);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
			g_clear_error (&data->_inner_error_);
			return FALSE;
		}
	}
	if (GDK_IS_PIXBUF (data->ret)) {
		ctk_image_set_from_pixbuf (data->image, data->ret);
	}
	_g_object_unref0 (data->ret);
	_g_free0 (data->key);
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
}


static void unity_pixbuf_cache_set_image_from_gicon_string_data_free (gpointer _data) {
	UnityPixbufCacheSetImageFromGiconStringData* data;
	data = _data;
	_g_object_unref0 (data->image);
	_g_free0 (data->gicon_as_string);
	g_object_unref (data->self);
	g_slice_free (UnityPixbufCacheSetImageFromGiconStringData, data);
}


void unity_pixbuf_cache_set_image_from_gicon_string (UnityPixbufCache* self, CtkImage* image, const char* gicon_as_string, gint size, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UnityPixbufCacheSetImageFromGiconStringData* _data_;
	_data_ = g_slice_new0 (UnityPixbufCacheSetImageFromGiconStringData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, unity_pixbuf_cache_set_image_from_gicon_string);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, unity_pixbuf_cache_set_image_from_gicon_string_data_free);
	_data_->self = g_object_ref (self);
	_data_->image = _g_object_ref0 (image);
	_data_->gicon_as_string = g_strdup (gicon_as_string);
	_data_->size = size;
	unity_pixbuf_cache_set_image_from_gicon_string_co (_data_);
}


void unity_pixbuf_cache_set_image_from_gicon_string_finish (UnityPixbufCache* self, GAsyncResult* _res_) {
	UnityPixbufCacheSetImageFromGiconStringData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void unity_pixbuf_cache_set_image_from_gicon_string_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	UnityPixbufCacheSetImageFromGiconStringData* data;
	data = _user_data_;
	data->_res_ = _res_;
	unity_pixbuf_cache_set_image_from_gicon_string_co (data);
}


static gboolean _unity_pixbuf_cache_set_image_from_gicon_string_co_gsource_func (gpointer self) {
	gboolean result;
	result = unity_pixbuf_cache_set_image_from_gicon_string_co (self);
	return result;
}


static const char* string_to_string (const char* self) {
	const char* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
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


static glong string_get_length (const char* self) {
	glong result;
	g_return_val_if_fail (self != NULL, 0L);
	result = g_utf8_strlen (self, -1);
	return result;
}


static gboolean unity_pixbuf_cache_set_image_from_gicon_string_co (UnityPixbufCacheSetImageFromGiconStringData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
		case 11:
		goto _state_11;
	}
	_state_0:
	data->key = g_strdup_printf (UNITY_hash_template, data->gicon_as_string, data->size);
	data->ret = (GdkPixbuf*) gee_abstract_map_get ((GeeAbstractMap*) data->self->priv->cache, data->key);
	if (GDK_IS_PIXBUF (data->ret)) {
		ctk_image_set_from_pixbuf (data->image, data->ret);
		_g_object_unref0 (data->ret);
		_g_free0 (data->key);
		{
			if (data->_state_ == 0) {
				g_simple_async_result_complete_in_idle (data->_async_result);
			} else {
				g_simple_async_result_complete (data->_async_result);
			}
			g_object_unref (data->_async_result);
			return FALSE;
		}
	}
	g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _unity_pixbuf_cache_set_image_from_gicon_string_co_gsource_func, data, NULL);
	data->_state_ = 11;
	return FALSE;
	_state_11:
	;
	if (data->ret == NULL) {
		if (g_utf8_get_char (g_utf8_offset_to_pointer (data->gicon_as_string, 0)) == '/') {
			{
				data->_tmp0_ = gdk_pixbuf_new_from_file (data->gicon_as_string, &data->_inner_error_);
				if (data->_inner_error_ != NULL) {
					goto __catch34_g_error;
				}
				data->ret = (data->_tmp1_ = data->_tmp0_, _g_object_unref0 (data->ret), data->_tmp1_);
			}
			goto __finally34;
			__catch34_g_error:
			{
				data->err = data->_inner_error_;
				data->_inner_error_ = NULL;
				{
					g_message (data->_tmp2_ = g_strconcat ("Unable to load ", string_to_string (data->gicon_as_string), " as file: %s", NULL), data->err->message);
					_g_free0 (data->_tmp2_);
					_g_error_free0 (data->err);
				}
			}
			__finally34:
			if (data->_inner_error_ != NULL) {
				_g_object_unref0 (data->ret);
				_g_free0 (data->key);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
				g_clear_error (&data->_inner_error_);
				return FALSE;
			}
		}
		if (data->ret == NULL) {
			{
				data->icon = g_icon_new_for_string (data->gicon_as_string, &data->_inner_error_);
				if (data->_inner_error_ != NULL) {
					goto __catch35_g_error;
				}
				data->info = gtk_icon_theme_lookup_by_gicon (data->self->priv->theme, data->icon, data->size, 0);
				if (data->info != NULL) {
					data->_tmp3_ = gtk_icon_info_load_icon (data->info, &data->_inner_error_);
					if (data->_inner_error_ != NULL) {
						_gtk_icon_info_free0 (data->info);
						goto __catch35_g_error;
					}
					data->ret = (data->_tmp4_ = data->_tmp3_, _g_object_unref0 (data->ret), data->_tmp4_);
				}
				if (data->ret == NULL) {
					if (g_str_has_suffix (data->gicon_as_string, ".png")) {
						data->_tmp7_ = TRUE;
					} else {
						data->_tmp7_ = g_str_has_suffix (data->gicon_as_string, ".xpm");
					}
					if (data->_tmp7_) {
						data->_tmp6_ = TRUE;
					} else {
						data->_tmp6_ = g_str_has_suffix (data->gicon_as_string, ".gir");
					}
					if (data->_tmp6_) {
						data->_tmp5_ = TRUE;
					} else {
						data->_tmp5_ = g_str_has_suffix (data->gicon_as_string, ".jpg");
					}
					if (data->_tmp5_) {
						data->real_name = string_slice (data->gicon_as_string, (glong) 0, string_get_length (data->gicon_as_string) - 4);
						data->_tmp8_ = gtk_icon_theme_load_icon (data->self->priv->theme, data->real_name, data->size, 0, &data->_inner_error_);
						if (data->_inner_error_ != NULL) {
							_g_free0 (data->real_name);
							_gtk_icon_info_free0 (data->info);
							goto __catch35_g_error;
						}
						data->ret = (data->_tmp9_ = _g_object_ref0 (data->_tmp8_), _g_object_unref0 (data->ret), data->_tmp9_);
						_g_free0 (data->real_name);
					}
				}
				_gtk_icon_info_free0 (data->info);
			}
			goto __finally35;
			__catch35_g_error:
			{
				data->e = data->_inner_error_;
				data->_inner_error_ = NULL;
				{
					g_warning (data->_tmp10_ = g_strconcat ("Unable to load icon ", string_to_string (data->gicon_as_string), ": '%s'", NULL), data->e->message);
					_g_free0 (data->_tmp10_);
					_g_error_free0 (data->e);
				}
			}
			__finally35:
			if (data->_inner_error_ != NULL) {
				_g_object_unref0 (data->ret);
				_g_free0 (data->key);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
				g_clear_error (&data->_inner_error_);
				return FALSE;
			}
		}
		if (GDK_IS_PIXBUF (data->ret)) {
			gee_abstract_map_set ((GeeAbstractMap*) data->self->priv->cache, data->key, data->ret);
		}
	}
	if (GDK_IS_PIXBUF (data->ret)) {
		ctk_image_set_from_pixbuf (data->image, data->ret);
	}
	_g_object_unref0 (data->ret);
	_g_free0 (data->key);
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
}


static void unity_pixbuf_cache_set_image_from_gicon_data_free (gpointer _data) {
	UnityPixbufCacheSetImageFromGiconData* data;
	data = _data;
	_g_object_unref0 (data->image);
	_g_object_unref0 (data->icon);
	g_object_unref (data->self);
	g_slice_free (UnityPixbufCacheSetImageFromGiconData, data);
}


void unity_pixbuf_cache_set_image_from_gicon (UnityPixbufCache* self, CtkImage* image, GIcon* icon, gint size, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UnityPixbufCacheSetImageFromGiconData* _data_;
	_data_ = g_slice_new0 (UnityPixbufCacheSetImageFromGiconData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, unity_pixbuf_cache_set_image_from_gicon);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, unity_pixbuf_cache_set_image_from_gicon_data_free);
	_data_->self = g_object_ref (self);
	_data_->image = _g_object_ref0 (image);
	_data_->icon = _g_object_ref0 (icon);
	_data_->size = size;
	unity_pixbuf_cache_set_image_from_gicon_co (_data_);
}


void unity_pixbuf_cache_set_image_from_gicon_finish (UnityPixbufCache* self, GAsyncResult* _res_) {
	UnityPixbufCacheSetImageFromGiconData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void unity_pixbuf_cache_set_image_from_gicon_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	UnityPixbufCacheSetImageFromGiconData* data;
	data = _user_data_;
	data->_res_ = _res_;
	unity_pixbuf_cache_set_image_from_gicon_co (data);
}


static gboolean unity_pixbuf_cache_set_image_from_gicon_co (UnityPixbufCacheSetImageFromGiconData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
		case 12:
		goto _state_12;
	}
	_state_0:
	data->_state_ = 12;
	unity_pixbuf_cache_set_image_from_gicon_string (data->self, data->image, g_icon_to_string (data->icon), data->size, unity_pixbuf_cache_set_image_from_gicon_ready, data);
	return FALSE;
	_state_12:
	unity_pixbuf_cache_set_image_from_gicon_string_finish (data->self, data->_res_);
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
}


guint unity_pixbuf_cache_get_size (UnityPixbufCache* self) {
	guint result;
	g_return_val_if_fail (self != NULL, 0U);
	result = (guint) gee_map_get_size ((GeeMap*) self->priv->cache);
	return result;
}


static GObject * unity_pixbuf_cache_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPixbufCache * self;
	parent_class = G_OBJECT_CLASS (unity_pixbuf_cache_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PIXBUF_CACHE (obj);
	{
		GeeHashMap* _tmp0_;
		self->priv->theme = gtk_icon_theme_get_default ();
		self->priv->cache = (_tmp0_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, GDK_TYPE_PIXBUF, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL, NULL, NULL), _g_object_unref0 (self->priv->cache), _tmp0_);
	}
	return obj;
}


static void unity_pixbuf_cache_class_init (UnityPixbufCacheClass * klass) {
	unity_pixbuf_cache_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPixbufCachePrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_pixbuf_cache_get_property;
	G_OBJECT_CLASS (klass)->constructor = unity_pixbuf_cache_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_pixbuf_cache_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PIXBUF_CACHE_SIZE, g_param_spec_uint ("size", "size", "size", 0, G_MAXUINT, 0U, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void unity_pixbuf_cache_instance_init (UnityPixbufCache * self) {
	self->priv = UNITY_PIXBUF_CACHE_GET_PRIVATE (self);
	self->priv->autodispose = FALSE;
}


static void unity_pixbuf_cache_finalize (GObject* obj) {
	UnityPixbufCache * self;
	self = UNITY_PIXBUF_CACHE (obj);
	_g_object_unref0 (self->priv->cache);
	G_OBJECT_CLASS (unity_pixbuf_cache_parent_class)->finalize (obj);
}


GType unity_pixbuf_cache_get_type (void) {
	static volatile gsize unity_pixbuf_cache_type_id__volatile = 0;
	if (g_once_init_enter (&unity_pixbuf_cache_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPixbufCacheClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_pixbuf_cache_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPixbufCache), 0, (GInstanceInitFunc) unity_pixbuf_cache_instance_init, NULL };
		GType unity_pixbuf_cache_type_id;
		unity_pixbuf_cache_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityPixbufCache", &g_define_type_info, 0);
		g_once_init_leave (&unity_pixbuf_cache_type_id__volatile, unity_pixbuf_cache_type_id);
	}
	return unity_pixbuf_cache_type_id__volatile;
}


static void unity_pixbuf_cache_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPixbufCache * self;
	self = UNITY_PIXBUF_CACHE (object);
	switch (property_id) {
		case UNITY_PIXBUF_CACHE_SIZE:
		g_value_set_uint (value, unity_pixbuf_cache_get_size (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




