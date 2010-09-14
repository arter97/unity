/* unity-appinfo-manager.c generated by valac 0.9.8, the Vala compiler
 * generated from unity-appinfo-manager.vala, do not modify */

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
 * <http://www.gnu.org/licenses/>.
 *
 * Authored by Mikkel Kamstrup Erlandsen <mikkel.kamstrup@canonical.com>
 *
 */
/*
 * IMPLEMENTATION NOTE:
 * We want the generatedd C API to be nice and not too Vala-ish. We must
 * anticipate that place daemons consuming libunity will be written in
 * both Vala and C.
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <gio/gdesktopappinfo.h>


#define UNITY_TYPE_APP_INFO_MANAGER (unity_app_info_manager_get_type ())
#define UNITY_APP_INFO_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_APP_INFO_MANAGER, UnityAppInfoManager))
#define UNITY_APP_INFO_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_APP_INFO_MANAGER, UnityAppInfoManagerClass))
#define UNITY_IS_APP_INFO_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_APP_INFO_MANAGER))
#define UNITY_IS_APP_INFO_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_APP_INFO_MANAGER))
#define UNITY_APP_INFO_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_APP_INFO_MANAGER, UnityAppInfoManagerClass))

typedef struct _UnityAppInfoManager UnityAppInfoManager;
typedef struct _UnityAppInfoManagerClass UnityAppInfoManagerClass;
typedef struct _UnityAppInfoManagerPrivate UnityAppInfoManagerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_key_file_free0(var) ((var == NULL) ? NULL : (var = (g_key_file_free (var), NULL)))
typedef struct _UnityAppInfoManagerLookupAsyncData UnityAppInfoManagerLookupAsyncData;

struct _UnityAppInfoManager {
	GObject parent_instance;
	UnityAppInfoManagerPrivate * priv;
};

struct _UnityAppInfoManagerClass {
	GObjectClass parent_class;
};

struct _UnityAppInfoManagerPrivate {
	GeeMap* appinfo_by_id;
	GeeMap* monitors;
	GeeMap* categories_by_id;
	guchar* buffer;
	gint buffer_length1;
	gint _buffer_size_;
	gsize buffer_size;
};

struct _UnityAppInfoManagerLookupAsyncData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	UnityAppInfoManager* self;
	char* id;
	GAppInfo* result;
	gsize data_size;
	void* data;
	GFileInputStream* input;
	GFile* f;
	GFileInputStream* _tmp0_;
	GFileInputStream* _tmp1_;
	GFile* dir;
	char* dir_uri;
	GFileMonitor* monitor;
	GError * ioe;
	char* path;
	GFileInputStream* _tmp2_;
	GFileInputStream* _tmp3_;
	guchar* _tmp4_;
	GError * e;
	GKeyFile* keyfile;
	GError * ee;
	GDesktopAppInfo* appinfo;
	GError * _inner_error_;
};


static UnityAppInfoManager* unity_app_info_manager_singleton;
static UnityAppInfoManager* unity_app_info_manager_singleton = NULL;
static gpointer unity_app_info_manager_parent_class = NULL;

GType unity_app_info_manager_get_type (void) G_GNUC_CONST;
#define UNITY_APP_INFO_MANAGER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TYPE_APP_INFO_MANAGER, UnityAppInfoManagerPrivate))
enum  {
	UNITY_APP_INFO_MANAGER_DUMMY_PROPERTY
};
static UnityAppInfoManager* unity_app_info_manager_new (void);
static UnityAppInfoManager* unity_app_info_manager_construct (GType object_type);
char** unity_io_get_system_data_dirs (int* result_length1);
static void unity_app_info_manager_on_dir_changed (UnityAppInfoManager* self, GFileMonitor* mon, GFile* file, GFile* other_file, GFileMonitorEvent e);
static void _unity_app_info_manager_on_dir_changed_g_file_monitor_changed (GFileMonitor* _sender, GFile* file, GFile* other_file, GFileMonitorEvent event_type, gpointer self);
UnityAppInfoManager* unity_app_info_manager_get_instance (void);
GAppInfo* unity_app_info_manager_lookup (UnityAppInfoManager* self, const char* id);
GeeList* unity_app_info_manager_get_categories (UnityAppInfoManager* self, const char* id);
static void unity_app_info_manager_lookup_async_data_free (gpointer _data);
static void unity_app_info_manager_lookup_async_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
void unity_app_info_manager_lookup_async (UnityAppInfoManager* self, const char* id, GAsyncReadyCallback _callback_, gpointer _user_data_);
GAppInfo* unity_app_info_manager_lookup_finish (UnityAppInfoManager* self, GAsyncResult* _res_, GError** error);
static gboolean unity_app_info_manager_lookup_async_co (UnityAppInfoManagerLookupAsyncData* data);
void unity_io_open_from_data_dirs (const char* filename, GAsyncReadyCallback _callback_, gpointer _user_data_);
GFileInputStream* unity_io_open_from_data_dirs_finish (GAsyncResult* _res_, GError** error);
void unity_io_read_stream_async (GInputStream* input, guchar* buffer, int buffer_length1, gsize buffer_lenght, gint io_priority, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
void unity_io_read_stream_finish (GAsyncResult* _res_, void** data, gsize* size, GError** error);
static guchar* _vala_array_dup1 (guchar* self, int length);
void unity_app_info_manager_clear (UnityAppInfoManager* self);
static void unity_app_info_manager_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static void g_cclosure_user_marshal_VOID__STRING_OBJECT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);

static void _unity_app_info_manager_on_dir_changed_g_file_monitor_changed (GFileMonitor* _sender, GFile* file, GFile* other_file, GFileMonitorEvent event_type, gpointer self) {
	unity_app_info_manager_on_dir_changed (self, _sender, file, other_file, event_type);
}


static UnityAppInfoManager* unity_app_info_manager_construct (GType object_type) {
	UnityAppInfoManager * self;
	GeeMap* _tmp0_;
	GeeMap* _tmp1_;
	guchar* _tmp2_;
	GeeMap* _tmp3_;
	GError * _inner_error_ = NULL;
	self = (UnityAppInfoManager*) g_object_new (object_type, NULL);
	self->priv->appinfo_by_id = (_tmp0_ = (GeeMap*) gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, G_TYPE_APP_INFO, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_str_hash, g_str_equal, NULL), _g_object_unref0 (self->priv->appinfo_by_id), _tmp0_);
	self->priv->categories_by_id = (_tmp1_ = (GeeMap*) gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, GEE_TYPE_LIST, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_str_hash, g_str_equal, NULL), _g_object_unref0 (self->priv->categories_by_id), _tmp1_);
	self->priv->buffer_size = (gsize) 1024;
	self->priv->buffer = (_tmp2_ = g_new0 (guchar, self->priv->buffer_size), self->priv->buffer = (g_free (self->priv->buffer), NULL), self->priv->buffer_length1 = self->priv->buffer_size, self->priv->_buffer_size_ = self->priv->buffer_length1, _tmp2_);
	self->priv->monitors = (_tmp3_ = (GeeMap*) gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, G_TYPE_APP_INFO, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_str_hash, g_str_equal, NULL), _g_object_unref0 (self->priv->monitors), _tmp3_);
	{
		gint _tmp4_;
		char** path_collection;
		int path_collection_length1;
		int path_it;
		path_collection = unity_io_get_system_data_dirs (&_tmp4_);
		path_collection_length1 = _tmp4_;
		for (path_it = 0; path_it < _tmp4_; path_it = path_it + 1) {
			char* path;
			path = g_strdup (path_collection[path_it]);
			{
				char* _tmp5_;
				GFile* _tmp6_;
				GFile* dir;
				dir = (_tmp6_ = g_file_new_for_path (_tmp5_ = g_build_filename (path, "applications", NULL)), _g_free0 (_tmp5_), _tmp6_);
				{
					GFileMonitor* monitor;
					char* _tmp7_;
					monitor = g_file_monitor_directory (dir, G_FILE_MONITOR_NONE, NULL, &_inner_error_);
					if (_inner_error_ != NULL) {
						if (_inner_error_->domain == G_IO_ERROR) {
							goto __catch9_g_io_error;
						}
						_g_object_unref0 (dir);
						_g_free0 (path);
						path_collection = (_vala_array_free (path_collection, path_collection_length1, (GDestroyNotify) g_free), NULL);
						g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return NULL;
					}
					g_signal_connect_object (monitor, "changed", (GCallback) _unity_app_info_manager_on_dir_changed_g_file_monitor_changed, self, 0);
					gee_map_set (self->priv->monitors, _tmp7_ = g_file_get_uri (dir), monitor);
					_g_free0 (_tmp7_);
					_g_object_unref0 (monitor);
				}
				goto __finally9;
				__catch9_g_io_error:
				{
					GError * e;
					e = _inner_error_;
					_inner_error_ = NULL;
					{
						char* _tmp8_;
						g_warning ("unity-appinfo-manager.vala:68: Error setting up directory monitor on '" \
"%s': %s", _tmp8_ = g_file_get_uri (dir), e->message);
						_g_free0 (_tmp8_);
						_g_error_free0 (e);
					}
				}
				__finally9:
				if (_inner_error_ != NULL) {
					_g_object_unref0 (dir);
					_g_free0 (path);
					path_collection = (_vala_array_free (path_collection, path_collection_length1, (GDestroyNotify) g_free), NULL);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return NULL;
				}
				_g_object_unref0 (dir);
				_g_free0 (path);
			}
		}
		path_collection = (_vala_array_free (path_collection, path_collection_length1, (GDestroyNotify) g_free), NULL);
	}
	return self;
}


static UnityAppInfoManager* unity_app_info_manager_new (void) {
	return unity_app_info_manager_construct (UNITY_TYPE_APP_INFO_MANAGER);
}


/**
     * Get a ref to the singleton AppInfoManager
     */
static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


UnityAppInfoManager* unity_app_info_manager_get_instance (void) {
	UnityAppInfoManager* result = NULL;
	if (unity_app_info_manager_singleton == NULL) {
		UnityAppInfoManager* _tmp0_;
		unity_app_info_manager_singleton = (_tmp0_ = unity_app_info_manager_new (), _g_object_unref0 (unity_app_info_manager_singleton), _tmp0_);
	}
	result = _g_object_ref0 (unity_app_info_manager_singleton);
	return result;
}


static void unity_app_info_manager_on_dir_changed (UnityAppInfoManager* self, GFileMonitor* mon, GFile* file, GFile* other_file, GFileMonitorEvent e) {
	char* desktop_id;
	char* path;
	GAppInfo* appinfo;
	g_return_if_fail (self != NULL);
	g_return_if_fail (mon != NULL);
	g_return_if_fail (file != NULL);
	desktop_id = g_file_get_basename (file);
	path = g_file_get_path (file);
	appinfo = NULL;
	if (gee_map_has_key (self->priv->appinfo_by_id, desktop_id)) {
		GAppInfo* _tmp0_;
		gee_map_unset (self->priv->appinfo_by_id, desktop_id, NULL);
		appinfo = (_tmp0_ = unity_app_info_manager_lookup (self, desktop_id), _g_object_unref0 (appinfo), _tmp0_);
		g_signal_emit_by_name (self, "changed", desktop_id, appinfo);
	}
	if (gee_map_has_key (self->priv->appinfo_by_id, path)) {
		GAppInfo* _tmp1_;
		gee_map_unset (self->priv->appinfo_by_id, path, NULL);
		appinfo = (_tmp1_ = unity_app_info_manager_lookup (self, path), _g_object_unref0 (appinfo), _tmp1_);
		g_signal_emit_by_name (self, "changed", path, appinfo);
	}
	_g_object_unref0 (appinfo);
	_g_free0 (path);
	_g_free0 (desktop_id);
}


/**
     * Look up an AppInfo given its desktop id or absolute path. The desktop id
     * is the base filename of the .desktop file for the application including
     * the .desktop extension.
     *
     * If the AppInfo is not already cached this method will do synchronous
     * IO to look it up.
     */
GAppInfo* unity_app_info_manager_lookup (UnityAppInfoManager* self, const char* id) {
	GAppInfo* result = NULL;
	GAppInfo* appinfo;
	GKeyFile* keyfile;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (id != NULL, NULL);
	if (gee_map_has_key (self->priv->appinfo_by_id, id)) {
		result = (GAppInfo*) gee_map_get (self->priv->appinfo_by_id, id);
		return result;
	}
	appinfo = NULL;
	keyfile = g_key_file_new ();
	if (g_str_has_prefix (id, "/")) {
		GFile* _tmp2_;
		GFile* _tmp3_;
		GFile* dir;
		char* dir_uri;
		{
			g_key_file_load_from_file (keyfile, id, G_KEY_FILE_NONE, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch10_g_error;
			}
		}
		goto __finally10;
		__catch10_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				GKeyFile* _tmp0_;
				gboolean _tmp1_ = FALSE;
				keyfile = (_tmp0_ = NULL, _g_key_file_free0 (keyfile), _tmp0_);
				if (g_error_matches (e, G_IO_ERROR, G_IO_ERROR_NOT_FOUND)) {
					_tmp1_ = TRUE;
				} else {
					_tmp1_ = g_error_matches (e, G_KEY_FILE_ERROR, G_KEY_FILE_ERROR_NOT_FOUND);
				}
				if (!_tmp1_) {
					g_warning ("unity-appinfo-manager.vala:139: Error loading '%s': %s", id, e->message);
				}
				_g_error_free0 (e);
			}
		}
		__finally10:
		if (_inner_error_ != NULL) {
			_g_key_file_free0 (keyfile);
			_g_object_unref0 (appinfo);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		dir = (_tmp3_ = g_file_get_parent (_tmp2_ = g_file_new_for_path (id)), _g_object_unref0 (_tmp2_), _tmp3_);
		dir_uri = g_file_get_uri (dir);
		if (!gee_map_has_key (self->priv->monitors, dir_uri)) {
			{
				GFileMonitor* monitor;
				monitor = g_file_monitor_directory (dir, G_FILE_MONITOR_NONE, NULL, &_inner_error_);
				if (_inner_error_ != NULL) {
					if (_inner_error_->domain == G_IO_ERROR) {
						goto __catch11_g_io_error;
					}
					_g_free0 (dir_uri);
					_g_object_unref0 (dir);
					_g_key_file_free0 (keyfile);
					_g_object_unref0 (appinfo);
					g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return NULL;
				}
				g_signal_connect_object (monitor, "changed", (GCallback) _unity_app_info_manager_on_dir_changed_g_file_monitor_changed, self, 0);
				gee_map_set (self->priv->monitors, dir_uri, monitor);
				g_debug ("unity-appinfo-manager.vala:149: Monitoring extra app directory: %s", dir_uri);
				_g_object_unref0 (monitor);
			}
			goto __finally11;
			__catch11_g_io_error:
			{
				GError * ioe;
				ioe = _inner_error_;
				_inner_error_ = NULL;
				{
					g_warning ("unity-appinfo-manager.vala:151: Error setting up extra app directory m" \
"onitor on '%s': %s", dir_uri, ioe->message);
					_g_error_free0 (ioe);
				}
			}
			__finally11:
			if (_inner_error_ != NULL) {
				_g_free0 (dir_uri);
				_g_object_unref0 (dir);
				_g_key_file_free0 (keyfile);
				_g_object_unref0 (appinfo);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
		_g_free0 (dir_uri);
		_g_object_unref0 (dir);
	} else {
		char* path;
		char* full_path;
		path = g_build_filename ("applications", id, NULL, NULL);
		full_path = NULL;
		{
			char* _tmp4_ = NULL;
			char* _tmp5_;
			g_key_file_load_from_data_dirs (keyfile, path, &_tmp4_, G_KEY_FILE_NONE, &_inner_error_);
			full_path = (_tmp5_ = _tmp4_, _g_free0 (full_path), _tmp5_);
			if (_inner_error_ != NULL) {
				goto __catch12_g_error;
			}
		}
		goto __finally12;
		__catch12_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				GKeyFile* _tmp6_;
				gboolean _tmp7_ = FALSE;
				keyfile = (_tmp6_ = NULL, _g_key_file_free0 (keyfile), _tmp6_);
				if (g_error_matches (e, G_IO_ERROR, G_IO_ERROR_NOT_FOUND)) {
					_tmp7_ = TRUE;
				} else {
					_tmp7_ = g_error_matches (e, G_KEY_FILE_ERROR, G_KEY_FILE_ERROR_NOT_FOUND);
				}
				if (!_tmp7_) {
					g_warning ("unity-appinfo-manager.vala:165: Error loading '%s': %s", id, e->message);
				}
				_g_error_free0 (e);
			}
		}
		__finally12:
		if (_inner_error_ != NULL) {
			_g_free0 (full_path);
			_g_free0 (path);
			_g_key_file_free0 (keyfile);
			_g_object_unref0 (appinfo);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_g_free0 (full_path);
		_g_free0 (path);
	}
	if (keyfile != NULL) {
		GAppInfo* _tmp8_;
		appinfo = (_tmp8_ = (GAppInfo*) g_desktop_app_info_new_from_keyfile (keyfile), _g_object_unref0 (appinfo), _tmp8_);
		{
			gint categories_length1;
			gint _categories_size_;
			char** _tmp10_;
			gsize _tmp9_;
			char** categories;
			GeeArrayList* cats;
			categories = (_tmp10_ = g_key_file_get_string_list (keyfile, "Desktop Entry", "Categories", &_tmp9_, &_inner_error_), categories_length1 = _tmp9_, _categories_size_ = categories_length1, _tmp10_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_KEY_FILE_ERROR) {
					goto __catch13_g_key_file_error;
				}
				_g_key_file_free0 (keyfile);
				_g_object_unref0 (appinfo);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
			cats = gee_array_list_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL);
			{
				char** cat_collection;
				int cat_collection_length1;
				int cat_it;
				cat_collection = categories;
				cat_collection_length1 = categories_length1;
				for (cat_it = 0; cat_it < categories_length1; cat_it = cat_it + 1) {
					char* cat;
					cat = g_strdup (cat_collection[cat_it]);
					{
						gee_abstract_collection_add ((GeeAbstractCollection*) cats, cat);
						_g_free0 (cat);
					}
				}
			}
			gee_map_set (self->priv->categories_by_id, id, (GeeList*) cats);
			_g_object_unref0 (cats);
			categories = (_vala_array_free (categories, categories_length1, (GDestroyNotify) g_free), NULL);
		}
		goto __finally13;
		__catch13_g_key_file_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				_g_error_free0 (e);
			}
		}
		__finally13:
		if (_inner_error_ != NULL) {
			_g_key_file_free0 (keyfile);
			_g_object_unref0 (appinfo);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	} else {
		GAppInfo* _tmp11_;
		appinfo = (_tmp11_ = NULL, _g_object_unref0 (appinfo), _tmp11_);
	}
	gee_map_set (self->priv->appinfo_by_id, id, appinfo);
	result = appinfo;
	_g_key_file_free0 (keyfile);
	return result;
}


/**
     * Look up XDG categories for for desktop id or file path @id.
     * Returns null if id is not found.
     * This method will do sync IO if the desktop file for @id is not
     * already cached. So if you are living in an async world you must first
     * do an async call to lookup_async(id) before calling this method, in which
     * case no sync io will be done.
     */
GeeList* unity_app_info_manager_get_categories (UnityAppInfoManager* self, const char* id) {
	GeeList* result = NULL;
	GAppInfo* appinfo;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (id != NULL, NULL);
	appinfo = unity_app_info_manager_lookup (self, id);
	if (appinfo == NULL) {
		result = NULL;
		_g_object_unref0 (appinfo);
		return result;
	}
	result = (GeeList*) gee_map_get (self->priv->categories_by_id, id);
	_g_object_unref0 (appinfo);
	return result;
}


static void unity_app_info_manager_lookup_async_data_free (gpointer _data) {
	UnityAppInfoManagerLookupAsyncData* data;
	data = _data;
	_g_free0 (data->id);
	_g_object_unref0 (data->result);
	g_object_unref (data->self);
	g_slice_free (UnityAppInfoManagerLookupAsyncData, data);
}


void unity_app_info_manager_lookup_async (UnityAppInfoManager* self, const char* id, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UnityAppInfoManagerLookupAsyncData* _data_;
	_data_ = g_slice_new0 (UnityAppInfoManagerLookupAsyncData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, unity_app_info_manager_lookup_async);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, unity_app_info_manager_lookup_async_data_free);
	_data_->self = g_object_ref (self);
	_data_->id = g_strdup (id);
	unity_app_info_manager_lookup_async_co (_data_);
}


GAppInfo* unity_app_info_manager_lookup_finish (UnityAppInfoManager* self, GAsyncResult* _res_, GError** error) {
	GAppInfo* result;
	UnityAppInfoManagerLookupAsyncData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static void unity_app_info_manager_lookup_async_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	UnityAppInfoManagerLookupAsyncData* data;
	data = _user_data_;
	data->_res_ = _res_;
	unity_app_info_manager_lookup_async_co (data);
}


/**
     * Look up an AppInfo given its desktop id or absolute path.
     * The desktop id is the base filename of the .desktop file for the
     * application including the .desktop extension.
     *
     * If the AppInfo is not already cached this method will do asynchronous
     * IO to look it up.
     */
static guchar* _vala_array_dup1 (guchar* self, int length) {
	return g_memdup (self, length * sizeof (guchar));
}


static gboolean unity_app_info_manager_lookup_async_co (UnityAppInfoManagerLookupAsyncData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
		case 3:
		goto _state_3;
		case 4:
		goto _state_4;
		case 5:
		goto _state_5;
	}
	_state_0:
	if (gee_map_has_key (data->self->priv->appinfo_by_id, data->id)) {
		data->result = (GAppInfo*) gee_map_get (data->self->priv->appinfo_by_id, data->id);
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
	if (g_str_has_prefix (data->id, "/")) {
		data->f = g_file_new_for_path (data->id);
		data->_state_ = 3;
		g_file_read_async (data->f, G_PRIORITY_DEFAULT, NULL, unity_app_info_manager_lookup_async_ready, data);
		return FALSE;
		_state_3:
		data->_tmp0_ = g_file_read_finish (data->f, data->_res_, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
			g_error_free (data->_inner_error_);
			_g_object_unref0 (data->f);
			_g_object_unref0 (data->input);
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
		data->input = (data->_tmp1_ = data->_tmp0_, _g_object_unref0 (data->input), data->_tmp1_);
		data->dir = g_file_get_parent (data->f);
		data->dir_uri = g_file_get_uri (data->dir);
		if (!gee_map_has_key (data->self->priv->monitors, data->dir_uri)) {
			{
				data->monitor = g_file_monitor_directory (data->dir, G_FILE_MONITOR_NONE, NULL, &data->_inner_error_);
				if (data->_inner_error_ != NULL) {
					if (data->_inner_error_->domain == G_IO_ERROR) {
						goto __catch14_g_io_error;
					}
					_g_free0 (data->dir_uri);
					_g_object_unref0 (data->dir);
					_g_object_unref0 (data->f);
					_g_object_unref0 (data->input);
					g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
					g_clear_error (&data->_inner_error_);
					return FALSE;
				}
				g_signal_connect_object (data->monitor, "changed", (GCallback) _unity_app_info_manager_on_dir_changed_g_file_monitor_changed, data->self, 0);
				gee_map_set (data->self->priv->monitors, data->dir_uri, data->monitor);
				g_debug ("unity-appinfo-manager.vala:247: Monitoring extra app directory: %s", data->dir_uri);
				_g_object_unref0 (data->monitor);
			}
			goto __finally14;
			__catch14_g_io_error:
			{
				data->ioe = data->_inner_error_;
				data->_inner_error_ = NULL;
				{
					g_warning ("unity-appinfo-manager.vala:249: Error setting up extra app directory m" \
"onitor on '%s': %s", data->dir_uri, data->ioe->message);
					_g_error_free0 (data->ioe);
				}
			}
			__finally14:
			if (data->_inner_error_ != NULL) {
				g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
				g_error_free (data->_inner_error_);
				_g_free0 (data->dir_uri);
				_g_object_unref0 (data->dir);
				_g_object_unref0 (data->f);
				_g_object_unref0 (data->input);
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
		}
		_g_free0 (data->dir_uri);
		_g_object_unref0 (data->dir);
		_g_object_unref0 (data->f);
	} else {
		data->path = g_build_filename ("applications", data->id, NULL, NULL);
		data->_state_ = 4;
		unity_io_open_from_data_dirs (data->path, unity_app_info_manager_lookup_async_ready, data);
		return FALSE;
		_state_4:
		data->_tmp2_ = unity_io_open_from_data_dirs_finish (data->_res_, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
			g_error_free (data->_inner_error_);
			_g_free0 (data->path);
			_g_object_unref0 (data->input);
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
		data->input = (data->_tmp3_ = data->_tmp2_, _g_object_unref0 (data->input), data->_tmp3_);
		_g_free0 (data->path);
	}
	if (data->input == NULL) {
		gee_map_set (data->self->priv->appinfo_by_id, data->id, NULL);
		data->result = NULL;
		_g_object_unref0 (data->input);
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
	{
		data->_state_ = 5;
		unity_io_read_stream_async ((GInputStream*) data->input, (data->_tmp4_ = data->self->priv->buffer, (data->_tmp4_ == NULL) ? ((gpointer) data->_tmp4_) : _vala_array_dup1 (data->_tmp4_, data->self->priv->buffer_length1)), data->self->priv->buffer_length1, data->self->priv->buffer_size, G_PRIORITY_DEFAULT, NULL, unity_app_info_manager_lookup_async_ready, data);
		return FALSE;
		_state_5:
		unity_io_read_stream_finish (data->_res_, &data->data, &data->data_size, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			goto __catch15_g_error;
		}
	}
	goto __finally15;
	__catch15_g_error:
	{
		data->e = data->_inner_error_;
		data->_inner_error_ = NULL;
		{
			g_warning ("unity-appinfo-manager.vala:277: Error reading '%s': %s", data->id, data->e->message);
			data->result = NULL;
			_g_error_free0 (data->e);
			_g_object_unref0 (data->input);
			{
				if (data->_state_ == 0) {
					g_simple_async_result_complete_in_idle (data->_async_result);
				} else {
					g_simple_async_result_complete (data->_async_result);
				}
				g_object_unref (data->_async_result);
				return FALSE;
			}
			_g_error_free0 (data->e);
		}
	}
	__finally15:
	if (data->_inner_error_ != NULL) {
		g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
		g_error_free (data->_inner_error_);
		_g_object_unref0 (data->input);
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
	data->keyfile = g_key_file_new ();
	{
		g_key_file_load_from_data (data->keyfile, (const char*) data->data, data->data_size, G_KEY_FILE_NONE, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			goto __catch16_g_error;
		}
	}
	goto __finally16;
	__catch16_g_error:
	{
		data->ee = data->_inner_error_;
		data->_inner_error_ = NULL;
		{
			g_warning ("unity-appinfo-manager.vala:288: Error parsing '%s': %s", data->id, data->ee->message);
			data->result = NULL;
			_g_error_free0 (data->ee);
			_g_key_file_free0 (data->keyfile);
			_g_object_unref0 (data->input);
			{
				if (data->_state_ == 0) {
					g_simple_async_result_complete_in_idle (data->_async_result);
				} else {
					g_simple_async_result_complete (data->_async_result);
				}
				g_object_unref (data->_async_result);
				return FALSE;
			}
			_g_error_free0 (data->ee);
		}
	}
	__finally16:
	if (data->_inner_error_ != NULL) {
		g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
		g_error_free (data->_inner_error_);
		_g_key_file_free0 (data->keyfile);
		_g_object_unref0 (data->input);
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
	data->appinfo = g_desktop_app_info_new_from_keyfile (data->keyfile);
	gee_map_set (data->self->priv->appinfo_by_id, data->id, (GAppInfo*) data->appinfo);
	g_free (data->data);
	data->result = (GAppInfo*) data->appinfo;
	_g_key_file_free0 (data->keyfile);
	_g_object_unref0 (data->input);
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
	_g_object_unref0 (data->appinfo);
	_g_key_file_free0 (data->keyfile);
	_g_object_unref0 (data->input);
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


void unity_app_info_manager_clear (UnityAppInfoManager* self) {
	g_return_if_fail (self != NULL);
	gee_map_clear (self->priv->appinfo_by_id);
}


static void unity_app_info_manager_class_init (UnityAppInfoManagerClass * klass) {
	unity_app_info_manager_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityAppInfoManagerPrivate));
	G_OBJECT_CLASS (klass)->finalize = unity_app_info_manager_finalize;
	/**
	     * Emitted whenever an AppInfo in any of the monitored paths change.
	     * Note that @new_appinfo may be null in case it has been removed.
	     */
	g_signal_new ("changed", UNITY_TYPE_APP_INFO_MANAGER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__STRING_OBJECT, G_TYPE_NONE, 2, G_TYPE_STRING, G_TYPE_APP_INFO);
}


static void unity_app_info_manager_instance_init (UnityAppInfoManager * self) {
	self->priv = UNITY_APP_INFO_MANAGER_GET_PRIVATE (self);
}


static void unity_app_info_manager_finalize (GObject* obj) {
	UnityAppInfoManager * self;
	self = UNITY_APP_INFO_MANAGER (obj);
	_g_object_unref0 (self->priv->appinfo_by_id);
	_g_object_unref0 (self->priv->monitors);
	_g_object_unref0 (self->priv->categories_by_id);
	self->priv->buffer = (g_free (self->priv->buffer), NULL);
	G_OBJECT_CLASS (unity_app_info_manager_parent_class)->finalize (obj);
}


/**
   * A singleton class that caches GLib.AppInfo objects.
   * Singletons are evil, yes, but this on slightly less
   * so because the exposed API is immutable.
   *
   * To detect when any of the managed AppInfo objects changes, appears,
   * or goes away listen for the 'changed' signal.
   */
GType unity_app_info_manager_get_type (void) {
	static volatile gsize unity_app_info_manager_type_id__volatile = 0;
	if (g_once_init_enter (&unity_app_info_manager_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityAppInfoManagerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_app_info_manager_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityAppInfoManager), 0, (GInstanceInitFunc) unity_app_info_manager_instance_init, NULL };
		GType unity_app_info_manager_type_id;
		unity_app_info_manager_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityAppInfoManager", &g_define_type_info, 0);
		g_once_init_leave (&unity_app_info_manager_type_id__volatile, unity_app_info_manager_type_id);
	}
	return unity_app_info_manager_type_id__volatile;
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



static void g_cclosure_user_marshal_VOID__STRING_OBJECT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__STRING_OBJECT) (gpointer data1, const char* arg_1, gpointer arg_2, gpointer data2);
	register GMarshalFunc_VOID__STRING_OBJECT callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__STRING_OBJECT) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_string (param_values + 1), g_value_get_object (param_values + 2), data2);
}



