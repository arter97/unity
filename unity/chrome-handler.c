/* chrome-handler.c generated by valac 0.9.5, the Vala compiler
 * generated from chrome-handler.vala, do not modify */

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
 * Authored by Gordon Allott <gord.allott@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <float.h>
#include <math.h>
#include <gee.h>


#define UNITY_WEBAPP_TYPE_CHROMIUM_WEB_APP (unity_webapp_chromium_web_app_get_type ())
#define UNITY_WEBAPP_CHROMIUM_WEB_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_WEBAPP_TYPE_CHROMIUM_WEB_APP, UnityWebappChromiumWebApp))
#define UNITY_WEBAPP_CHROMIUM_WEB_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_WEBAPP_TYPE_CHROMIUM_WEB_APP, UnityWebappChromiumWebAppClass))
#define UNITY_WEBAPP_IS_CHROMIUM_WEB_APP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_WEBAPP_TYPE_CHROMIUM_WEB_APP))
#define UNITY_WEBAPP_IS_CHROMIUM_WEB_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_WEBAPP_TYPE_CHROMIUM_WEB_APP))
#define UNITY_WEBAPP_CHROMIUM_WEB_APP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_WEBAPP_TYPE_CHROMIUM_WEB_APP, UnityWebappChromiumWebAppClass))

typedef struct _UnityWebappChromiumWebApp UnityWebappChromiumWebApp;
typedef struct _UnityWebappChromiumWebAppClass UnityWebappChromiumWebAppClass;
typedef struct _UnityWebappChromiumWebAppPrivate UnityWebappChromiumWebAppPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define UNITY_TYPE_FAVORITES (unity_favorites_get_type ())
#define UNITY_FAVORITES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_FAVORITES, UnityFavorites))
#define UNITY_FAVORITES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_FAVORITES, UnityFavoritesClass))
#define UNITY_IS_FAVORITES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_FAVORITES))
#define UNITY_IS_FAVORITES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_FAVORITES))
#define UNITY_FAVORITES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_FAVORITES, UnityFavoritesClass))

typedef struct _UnityFavorites UnityFavorites;
typedef struct _UnityFavoritesClass UnityFavoritesClass;
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))

struct _UnityWebappChromiumWebApp {
	GObject parent_instance;
	UnityWebappChromiumWebAppPrivate * priv;
	char* name;
	char* id;
};

struct _UnityWebappChromiumWebAppClass {
	GObjectClass parent_class;
};

struct _UnityWebappChromiumWebAppPrivate {
	char* _url;
	char* _icon;
	char* webapp_dir;
};


static gpointer unity_webapp_chromium_web_app_parent_class = NULL;

GType unity_webapp_chromium_web_app_get_type (void) G_GNUC_CONST;
#define UNITY_WEBAPP_CHROMIUM_WEB_APP_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_WEBAPP_TYPE_CHROMIUM_WEB_APP, UnityWebappChromiumWebAppPrivate))
enum  {
	UNITY_WEBAPP_CHROMIUM_WEB_APP_DUMMY_PROPERTY,
	UNITY_WEBAPP_CHROMIUM_WEB_APP_URL,
	UNITY_WEBAPP_CHROMIUM_WEB_APP_ICON
};
#define UNITY_WEBAPP_CHROMIUM_WEB_APP_webapp_desktop_template "\n" \
"[Desktop Entry]\n" \
"Version=1.0\n" \
"Name=%s\n" \
"Exec=chromium-browser --class=\"chromium-browser\" --load-extension=/u" \
"sr/lib/chromium-webfav-extension %s\n" \
"Comment=A Chromium Webapp\n" \
"Terminal=false\n" \
"X-MultipleArgs=false\n" \
"Type=Application\n" \
"Icon=emblem-web\n" \
"Categories=Network;\n" \
"MimeType=text/html;\n" \
"StartupWMClass=Chromium\n" \
"StartupNotify=true\n"
UnityWebappChromiumWebApp* unity_webapp_chromium_web_app_new (const char* address, const char* icon);
UnityWebappChromiumWebApp* unity_webapp_chromium_web_app_construct (GType object_type, const char* address, const char* icon);
char* unity_webapp_chromium_web_app_desktop_file_path (UnityWebappChromiumWebApp* self);
const char* unity_webapp_chromium_web_app_get_url (UnityWebappChromiumWebApp* self);
static gboolean unity_webapp_chromium_web_app_check_existance_of_app (UnityWebappChromiumWebApp* self);
const char* unity_webapp_chromium_web_app_get_icon (UnityWebappChromiumWebApp* self);
static void unity_webapp_chromium_web_app_build_webapp (UnityWebappChromiumWebApp* self);
GType unity_favorites_get_type (void) G_GNUC_CONST;
UnityFavorites* unity_favorites_get_default (void);
static char* unity_webapp_chromium_web_app_get_fav_uid (UnityWebappChromiumWebApp* self);
char* unity_webapp_urlify (const char* uri);
void unity_favorites_set_string (UnityFavorites* self, const char* uid, const char* name, const char* value);
void unity_favorites_set_float (UnityFavorites* self, const char* uid, const char* name, float value);
void unity_favorites_add_favorite (UnityFavorites* self, const char* uid);
void unity_webapp_chromium_web_app_add_to_favorites (UnityWebappChromiumWebApp* self);
GeeArrayList* unity_favorites_get_favorites (UnityFavorites* self);
char* unity_favorites_get_string (UnityFavorites* self, const char* uid, const char* name);
static void unity_webapp_chromium_web_app_set_url (UnityWebappChromiumWebApp* self, const char* value);
static void unity_webapp_chromium_web_app_set_icon (UnityWebappChromiumWebApp* self, const char* value);
static GObject * unity_webapp_chromium_web_app_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_webapp_chromium_web_app_finalize (GObject* obj);
static void unity_webapp_chromium_web_app_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_webapp_chromium_web_app_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);
static int _vala_strcmp0 (const char * str1, const char * str2);



UnityWebappChromiumWebApp* unity_webapp_chromium_web_app_construct (GType object_type, const char* address, const char* icon) {
	UnityWebappChromiumWebApp * self;
	g_return_val_if_fail (address != NULL, NULL);
	g_return_val_if_fail (icon != NULL, NULL);
	self = (UnityWebappChromiumWebApp*) g_object_new (object_type, "url", address, "icon", icon, NULL);
	return self;
}


UnityWebappChromiumWebApp* unity_webapp_chromium_web_app_new (const char* address, const char* icon) {
	return unity_webapp_chromium_web_app_construct (UNITY_WEBAPP_TYPE_CHROMIUM_WEB_APP, address, icon);
}


static const char* string_to_string (const char* self) {
	const char* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


char* unity_webapp_chromium_web_app_desktop_file_path (UnityWebappChromiumWebApp* self) {
	char* result = NULL;
	char* _tmp0_;
	char* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	result = (_tmp1_ = g_strconcat (self->priv->webapp_dir, _tmp0_ = g_strconcat ("chromium-webapp-", string_to_string (self->name), ".desktop", NULL), NULL), _g_free0 (_tmp0_), _tmp1_);
	return result;
}


static gboolean unity_webapp_chromium_web_app_check_existance_of_app (UnityWebappChromiumWebApp* self) {
	gboolean result = FALSE;
	char* _tmp1_;
	char* _tmp0_;
	GFile* _tmp2_;
	GFile* webapp_dir_file;
	g_return_val_if_fail (self != NULL, FALSE);
	if (_vala_strcmp0 (self->priv->_url, "") == 0) {
		result = TRUE;
		return result;
	}
	webapp_dir_file = (_tmp2_ = g_file_new_for_path (_tmp1_ = g_strconcat (self->priv->webapp_dir, _tmp0_ = g_strconcat ("chromium-webapp-", string_to_string (self->name), ".desktop", NULL), NULL)), _g_free0 (_tmp1_), _g_free0 (_tmp0_), _tmp2_);
	if (g_file_query_exists (webapp_dir_file, NULL)) {
		result = TRUE;
		_g_object_unref0 (webapp_dir_file);
		return result;
	}
	result = FALSE;
	_g_object_unref0 (webapp_dir_file);
	return result;
}


static void unity_webapp_chromium_web_app_build_webapp (UnityWebappChromiumWebApp* self) {
	GError * _inner_error_;
	char* webapp_desktop;
	char* _tmp1_;
	char* _tmp0_;
	GFile* webapp_directory;
	char* _tmp3_;
	char* _tmp2_;
	GFile* _tmp4_;
	GFile* desktop_file;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	webapp_desktop = g_strdup_printf (UNITY_WEBAPP_CHROMIUM_WEB_APP_webapp_desktop_template, self->name, self->priv->_url, self->priv->_icon);
	g_debug ("chrome-handler.vala:99: %s", _tmp1_ = g_strconcat ("building ", _tmp0_ = g_strconcat ("chromium-webapp-", string_to_string (self->name), ".desktop", NULL), NULL));
	_g_free0 (_tmp1_);
	_g_free0 (_tmp0_);
	webapp_directory = g_file_new_for_path (self->priv->webapp_dir);
	{
		g_debug ("chrome-handler.vala:104: attempting to build parent directorys for %s", self->priv->webapp_dir);
		if (!g_file_query_exists (webapp_directory, NULL)) {
			g_file_make_directory_with_parents (webapp_directory, NULL, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch0_g_error;
			}
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("chrome-handler.vala:111: %s", e->message);
			_g_error_free0 (e);
			_g_object_unref0 (webapp_directory);
			_g_free0 (webapp_desktop);
			return;
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (webapp_directory);
		_g_free0 (webapp_desktop);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	desktop_file = (_tmp4_ = g_file_new_for_path (_tmp3_ = g_strconcat (self->priv->webapp_dir, _tmp2_ = g_strconcat ("chromium-webapp-", string_to_string (self->name), ".desktop", NULL), NULL)), _g_free0 (_tmp3_), _g_free0 (_tmp2_), _tmp4_);
	{
		GFileOutputStream* file_stream;
		GDataOutputStream* data_stream;
		char* _tmp6_;
		char* _tmp5_;
		file_stream = g_file_create (desktop_file, G_FILE_CREATE_NONE, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch1_g_error;
		}
		data_stream = g_data_output_stream_new ((GOutputStream*) file_stream);
		g_data_output_stream_put_string (data_stream, webapp_desktop, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_object_unref0 (data_stream);
			_g_object_unref0 (file_stream);
			goto __catch1_g_error;
		}
		g_output_stream_close ((GOutputStream*) data_stream, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_object_unref0 (data_stream);
			_g_object_unref0 (file_stream);
			goto __catch1_g_error;
		}
		g_debug ("chrome-handler.vala:122: wrote to %s", _tmp6_ = g_strconcat (self->priv->webapp_dir, _tmp5_ = g_strconcat ("chromium-webapp-", string_to_string (self->name), ".desktop", NULL), NULL));
		_g_free0 (_tmp6_);
		_g_free0 (_tmp5_);
		_g_object_unref0 (data_stream);
		_g_object_unref0 (file_stream);
	}
	goto __finally1;
	__catch1_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("chrome-handler.vala:125: could not write to %s/%s.desktop", self->priv->webapp_dir, self->name);
			_g_error_free0 (e);
			_g_object_unref0 (desktop_file);
			_g_object_unref0 (webapp_directory);
			_g_free0 (webapp_desktop);
			return;
		}
	}
	__finally1:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (desktop_file);
		_g_object_unref0 (webapp_directory);
		_g_free0 (webapp_desktop);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_object_unref0 (desktop_file);
	_g_object_unref0 (webapp_directory);
	_g_free0 (webapp_desktop);
}


void unity_webapp_chromium_web_app_add_to_favorites (UnityWebappChromiumWebApp* self) {
	UnityFavorites* favorites;
	char* uid;
	char* _tmp0_;
	char* _tmp1_;
	char* desktop_path;
	char* _tmp3_;
	char* _tmp2_;
	char* _tmp4_;
	g_return_if_fail (self != NULL);
	favorites = unity_favorites_get_default ();
	uid = unity_webapp_chromium_web_app_get_fav_uid (self);
	if (_vala_strcmp0 (uid, "") != 0) {
		g_warning ("chrome-handler.vala:137: %s is already a favorite", self->name);
		_g_free0 (uid);
		_g_object_unref0 (favorites);
		return;
	}
	desktop_path = (_tmp1_ = g_strconcat (self->priv->webapp_dir, _tmp0_ = g_strconcat ("chromium-webapp-", string_to_string (self->name), ".desktop", NULL), NULL), _g_free0 (_tmp0_), _tmp1_);
	uid = (_tmp3_ = g_strconcat ("webapp-", _tmp2_ = g_path_get_basename (desktop_path), NULL), _g_free0 (uid), _tmp3_);
	_g_free0 (_tmp2_);
	uid = (_tmp4_ = unity_webapp_urlify (uid), _g_free0 (uid), _tmp4_);
	unity_favorites_set_string (favorites, uid, "type", "application");
	unity_favorites_set_string (favorites, uid, "desktop_file", desktop_path);
	unity_favorites_set_float (favorites, uid, "priority", -100000.0f);
	unity_favorites_add_favorite (favorites, uid);
	_g_free0 (desktop_path);
	_g_free0 (uid);
	_g_object_unref0 (favorites);
}


/**
     * gets the favorite uid for this desktop file
     */
static char* unity_webapp_chromium_web_app_get_fav_uid (UnityWebappChromiumWebApp* self) {
	char* result = NULL;
	char* myuid;
	char* _tmp0_;
	char* _tmp1_;
	char* my_desktop_path;
	UnityFavorites* favorites;
	GeeArrayList* favorite_list;
	g_return_val_if_fail (self != NULL, NULL);
	myuid = g_strdup ("");
	my_desktop_path = (_tmp1_ = g_strconcat (self->priv->webapp_dir, _tmp0_ = g_strconcat ("chromium-webapp-", string_to_string (self->name), ".desktop", NULL), NULL), _g_free0 (_tmp0_), _tmp1_);
	favorites = unity_favorites_get_default ();
	favorite_list = unity_favorites_get_favorites (favorites);
	{
		GeeIterator* _uid_it;
		_uid_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) favorite_list);
		while (TRUE) {
			char* uid;
			char* type;
			char* desktop_file;
			if (!gee_iterator_next (_uid_it)) {
				break;
			}
			uid = (char*) gee_iterator_get (_uid_it);
			type = unity_favorites_get_string (favorites, uid, "type");
			if (_vala_strcmp0 (type, "application") != 0) {
				_g_free0 (type);
				_g_free0 (uid);
				continue;
			}
			desktop_file = unity_favorites_get_string (favorites, uid, "desktop_file");
			if (_vala_strcmp0 (desktop_file, my_desktop_path) == 0) {
				char* _tmp2_;
				myuid = (_tmp2_ = g_strdup (uid), _g_free0 (myuid), _tmp2_);
			}
			_g_free0 (desktop_file);
			_g_free0 (type);
			_g_free0 (uid);
		}
		_g_object_unref0 (_uid_it);
	}
	result = myuid;
	_g_object_unref0 (favorite_list);
	_g_object_unref0 (favorites);
	_g_free0 (my_desktop_path);
	return result;
}


const char* unity_webapp_chromium_web_app_get_url (UnityWebappChromiumWebApp* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_url;
	return result;
}


static void unity_webapp_chromium_web_app_set_url (UnityWebappChromiumWebApp* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_url = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_url), _tmp0_);
	g_object_notify ((GObject *) self, "url");
}


const char* unity_webapp_chromium_web_app_get_icon (UnityWebappChromiumWebApp* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_icon;
	return result;
}


static void unity_webapp_chromium_web_app_set_icon (UnityWebappChromiumWebApp* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_icon = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_icon), _tmp0_);
	g_object_notify ((GObject *) self, "icon");
}


static GObject * unity_webapp_chromium_web_app_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityWebappChromiumWebApp * self;
	GError * _inner_error_;
	parent_class = G_OBJECT_CLASS (unity_webapp_chromium_web_app_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_WEBAPP_CHROMIUM_WEB_APP (obj);
	_inner_error_ = NULL;
	{
		char** _tmp1_;
		gint _split_url_size_;
		gint split_url_length1;
		char** _tmp0_;
		char** split_url;
		char* _tmp2_;
		char* _tmp5_;
		char* _tmp6_;
		gboolean exists;
		split_url = (_tmp1_ = _tmp0_ = g_strsplit (self->priv->_url, "://", 2), split_url_length1 = _vala_array_length (_tmp0_), _split_url_size_ = split_url_length1, _tmp1_);
		self->name = (_tmp2_ = g_strdup (split_url[1]), _g_free0 (self->name), _tmp2_);
		{
			GRegex* regex;
			char* _tmp3_;
			char* _tmp4_;
			regex = g_regex_new ("(\\?|/|~|=)", 0, 0, &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch2_g_regex_error;
				}
				split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
			}
			_tmp3_ = g_regex_replace (regex, self->name, (gssize) (-1), 0, "-", 0, &_inner_error_);
			if (_inner_error_ != NULL) {
				_g_regex_unref0 (regex);
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch2_g_regex_error;
				}
				_g_regex_unref0 (regex);
				split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
			}
			self->name = (_tmp4_ = _tmp3_, _g_free0 (self->name), _tmp4_);
			_g_regex_unref0 (regex);
		}
		goto __finally2;
		__catch2_g_regex_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("chrome-handler.vala:62: %s", e->message);
				_g_error_free0 (e);
			}
		}
		__finally2:
		if (_inner_error_ != NULL) {
			split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		self->id = (_tmp5_ = g_strdup (self->name), _g_free0 (self->id), _tmp5_);
		self->priv->webapp_dir = (_tmp6_ = g_strconcat (g_get_home_dir (), "/.local/share/applications/", NULL), _g_free0 (self->priv->webapp_dir), _tmp6_);
		exists = unity_webapp_chromium_web_app_check_existance_of_app (self);
		if (!exists) {
			unity_webapp_chromium_web_app_build_webapp (self);
		}
		split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
	}
	return obj;
}


static void unity_webapp_chromium_web_app_class_init (UnityWebappChromiumWebAppClass * klass) {
	unity_webapp_chromium_web_app_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityWebappChromiumWebAppPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_webapp_chromium_web_app_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_webapp_chromium_web_app_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_webapp_chromium_web_app_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_webapp_chromium_web_app_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_WEBAPP_CHROMIUM_WEB_APP_URL, g_param_spec_string ("url", "url", "url", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_WEBAPP_CHROMIUM_WEB_APP_ICON, g_param_spec_string ("icon", "icon", "icon", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_webapp_chromium_web_app_instance_init (UnityWebappChromiumWebApp * self) {
	self->priv = UNITY_WEBAPP_CHROMIUM_WEB_APP_GET_PRIVATE (self);
}


static void unity_webapp_chromium_web_app_finalize (GObject* obj) {
	UnityWebappChromiumWebApp * self;
	self = UNITY_WEBAPP_CHROMIUM_WEB_APP (obj);
	_g_free0 (self->priv->_url);
	_g_free0 (self->priv->_icon);
	_g_free0 (self->name);
	_g_free0 (self->id);
	_g_free0 (self->priv->webapp_dir);
	G_OBJECT_CLASS (unity_webapp_chromium_web_app_parent_class)->finalize (obj);
}


GType unity_webapp_chromium_web_app_get_type (void) {
	static volatile gsize unity_webapp_chromium_web_app_type_id__volatile = 0;
	if (g_once_init_enter (&unity_webapp_chromium_web_app_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityWebappChromiumWebAppClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_webapp_chromium_web_app_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityWebappChromiumWebApp), 0, (GInstanceInitFunc) unity_webapp_chromium_web_app_instance_init, NULL };
		GType unity_webapp_chromium_web_app_type_id;
		unity_webapp_chromium_web_app_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityWebappChromiumWebApp", &g_define_type_info, 0);
		g_once_init_leave (&unity_webapp_chromium_web_app_type_id__volatile, unity_webapp_chromium_web_app_type_id);
	}
	return unity_webapp_chromium_web_app_type_id__volatile;
}


static void unity_webapp_chromium_web_app_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityWebappChromiumWebApp * self;
	self = UNITY_WEBAPP_CHROMIUM_WEB_APP (object);
	switch (property_id) {
		case UNITY_WEBAPP_CHROMIUM_WEB_APP_URL:
		g_value_set_string (value, unity_webapp_chromium_web_app_get_url (self));
		break;
		case UNITY_WEBAPP_CHROMIUM_WEB_APP_ICON:
		g_value_set_string (value, unity_webapp_chromium_web_app_get_icon (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_webapp_chromium_web_app_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityWebappChromiumWebApp * self;
	self = UNITY_WEBAPP_CHROMIUM_WEB_APP (object);
	switch (property_id) {
		case UNITY_WEBAPP_CHROMIUM_WEB_APP_URL:
		unity_webapp_chromium_web_app_set_url (self, g_value_get_string (value));
		break;
		case UNITY_WEBAPP_CHROMIUM_WEB_APP_ICON:
		unity_webapp_chromium_web_app_set_icon (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
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


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
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




