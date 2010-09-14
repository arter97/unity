/* prism-handler.c generated by valac 0.9.8, the Vala compiler
 * generated from prism-handler.vala, do not modify */

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
#include <gee.h>


#define UNITY_WEBAPP_TYPE_PRISM (unity_webapp_prism_get_type ())
#define UNITY_WEBAPP_PRISM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_WEBAPP_TYPE_PRISM, UnityWebappPrism))
#define UNITY_WEBAPP_PRISM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_WEBAPP_TYPE_PRISM, UnityWebappPrismClass))
#define UNITY_WEBAPP_IS_PRISM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_WEBAPP_TYPE_PRISM))
#define UNITY_WEBAPP_IS_PRISM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_WEBAPP_TYPE_PRISM))
#define UNITY_WEBAPP_PRISM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_WEBAPP_TYPE_PRISM, UnityWebappPrismClass))

typedef struct _UnityWebappPrism UnityWebappPrism;
typedef struct _UnityWebappPrismClass UnityWebappPrismClass;
typedef struct _UnityWebappPrismPrivate UnityWebappPrismPrivate;
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

struct _UnityWebappPrism {
	GObject parent_instance;
	UnityWebappPrismPrivate * priv;
	char* name;
	char* id;
};

struct _UnityWebappPrismClass {
	GObjectClass parent_class;
};

struct _UnityWebappPrismPrivate {
	char* _url;
	char* _icon;
	char* webapp_dir;
};


static gpointer unity_webapp_prism_parent_class = NULL;

GType unity_webapp_prism_get_type (void) G_GNUC_CONST;
#define UNITY_WEBAPP_PRISM_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_WEBAPP_TYPE_PRISM, UnityWebappPrismPrivate))
enum  {
	UNITY_WEBAPP_PRISM_DUMMY_PROPERTY,
	UNITY_WEBAPP_PRISM_URL,
	UNITY_WEBAPP_PRISM_ICON
};
#define UNITY_WEBAPP_PRISM_webapp_ini_template "[Parameters]\n" \
"id=%s@unity.app\n" \
"name=%s\n" \
"uri=%s\n" \
"status=yes\n" \
"location=no\n" \
"sidebar=no\n" \
"navigation=no"
#define UNITY_WEBAPP_PRISM_webapp_desktop_template "[Desktop Entry]\n" \
"Name=%s\n" \
"Type=Application\n" \
"Comment=Web Application\n" \
"Exec=\"prism\" -webapp %s@unity.app\n" \
"Categories=GTK;Network;\n" \
"StartupWMClass=Prism\n" \
"StartupNotify=true\n" \
"Icon=%s\n"
UnityWebappPrism* unity_webapp_prism_new (const char* address, const char* icon);
UnityWebappPrism* unity_webapp_prism_construct (GType object_type, const char* address, const char* icon);
char* unity_webapp_prism_desktop_file_path (UnityWebappPrism* self);
static gboolean unity_webapp_prism_check_existance_of_app (UnityWebappPrism* self);
const char* unity_webapp_prism_get_url (UnityWebappPrism* self);
static void unity_webapp_prism_build_webapp (UnityWebappPrism* self);
const char* unity_webapp_prism_get_icon (UnityWebappPrism* self);
void unity_webapp_prism_add_to_favorites (UnityWebappPrism* self);
GType unity_favorites_get_type (void) G_GNUC_CONST;
UnityFavorites* unity_favorites_get_default (void);
static char* unity_webapp_prism_get_fav_uid (UnityWebappPrism* self);
char* unity_webapp_urlify (const char* uri);
void unity_favorites_set_string (UnityFavorites* self, const char* uid, const char* name, const char* value);
void unity_favorites_add_favorite (UnityFavorites* self, const char* uid);
GeeArrayList* unity_favorites_get_favorites (UnityFavorites* self);
char* unity_favorites_get_string (UnityFavorites* self, const char* uid, const char* name);
static void unity_webapp_prism_set_url (UnityWebappPrism* self, const char* value);
static void unity_webapp_prism_set_icon (UnityWebappPrism* self, const char* value);
static GObject * unity_webapp_prism_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_webapp_prism_finalize (GObject* obj);
static void unity_webapp_prism_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_webapp_prism_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);
static int _vala_strcmp0 (const char * str1, const char * str2);



UnityWebappPrism* unity_webapp_prism_construct (GType object_type, const char* address, const char* icon) {
	UnityWebappPrism * self;
	g_return_val_if_fail (address != NULL, NULL);
	g_return_val_if_fail (icon != NULL, NULL);
	self = (UnityWebappPrism*) g_object_new (object_type, "url", address, "icon", icon, NULL);
	return self;
}


UnityWebappPrism* unity_webapp_prism_new (const char* address, const char* icon) {
	return unity_webapp_prism_construct (UNITY_WEBAPP_TYPE_PRISM, address, icon);
}


char* unity_webapp_prism_desktop_file_path (UnityWebappPrism* self) {
	char* result = NULL;
	char* _tmp0_;
	char* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	result = (_tmp1_ = g_strconcat (g_get_home_dir (), _tmp0_ = g_strdup_printf ("/.webapps/%s@unity.app", self->id), NULL), _g_free0 (_tmp0_), _tmp1_);
	return result;
}


static gboolean unity_webapp_prism_check_existance_of_app (UnityWebappPrism* self) {
	gboolean result = FALSE;
	GFile* webapp_dir_file;
	g_return_val_if_fail (self != NULL, FALSE);
	if (_vala_strcmp0 (self->priv->_url, "") == 0) {
		result = TRUE;
		return result;
	}
	webapp_dir_file = g_file_new_for_path (self->priv->webapp_dir);
	if (g_file_query_exists (webapp_dir_file, NULL)) {
		result = TRUE;
		_g_object_unref0 (webapp_dir_file);
		return result;
	}
	result = FALSE;
	_g_object_unref0 (webapp_dir_file);
	return result;
}


static void unity_webapp_prism_build_webapp (UnityWebappPrism* self) {
	char* webapp_ini;
	char* webapp_desktop;
	GFile* webapp_directory;
	char* _tmp0_;
	GFile* _tmp1_;
	GFile* inifile;
	char* _tmp2_;
	char* _tmp3_;
	GFile* _tmp4_;
	GFile* desktop_file;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	webapp_ini = g_strdup_printf (UNITY_WEBAPP_PRISM_webapp_ini_template, self->id, self->name, self->priv->_url);
	webapp_desktop = g_strdup_printf (UNITY_WEBAPP_PRISM_webapp_desktop_template, self->name, self->id, self->priv->_icon);
	webapp_directory = g_file_new_for_path (self->priv->webapp_dir);
	{
		g_file_make_directory_with_parents (webapp_directory, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch3_g_error;
		}
	}
	goto __finally3;
	__catch3_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("prism-handler.vala:114: %s", e->message);
			_g_error_free0 (e);
			_g_object_unref0 (webapp_directory);
			_g_free0 (webapp_desktop);
			_g_free0 (webapp_ini);
			return;
		}
	}
	__finally3:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (webapp_directory);
		_g_free0 (webapp_desktop);
		_g_free0 (webapp_ini);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	inifile = (_tmp1_ = g_file_new_for_path (_tmp0_ = g_strconcat (self->priv->webapp_dir, "/webapp.ini", NULL)), _g_free0 (_tmp0_), _tmp1_);
	{
		GFileOutputStream* file_stream;
		GDataOutputStream* data_stream;
		file_stream = g_file_create (inifile, G_FILE_CREATE_NONE, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch4_g_error;
		}
		data_stream = g_data_output_stream_new ((GOutputStream*) file_stream);
		g_data_output_stream_put_string (data_stream, webapp_ini, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_object_unref0 (data_stream);
			_g_object_unref0 (file_stream);
			goto __catch4_g_error;
		}
		_g_object_unref0 (data_stream);
		_g_object_unref0 (file_stream);
	}
	goto __finally4;
	__catch4_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("prism-handler.vala:127: %s", e->message);
			_g_error_free0 (e);
			_g_object_unref0 (inifile);
			_g_object_unref0 (webapp_directory);
			_g_free0 (webapp_desktop);
			_g_free0 (webapp_ini);
			return;
		}
	}
	__finally4:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (inifile);
		_g_object_unref0 (webapp_directory);
		_g_free0 (webapp_desktop);
		_g_free0 (webapp_ini);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	desktop_file = (_tmp4_ = g_file_new_for_path (_tmp3_ = g_strconcat (self->priv->webapp_dir, _tmp2_ = g_strdup_printf ("/%s.desktop", self->name), NULL)), _g_free0 (_tmp3_), _g_free0 (_tmp2_), _tmp4_);
	{
		GFileOutputStream* file_stream;
		GDataOutputStream* data_stream;
		file_stream = g_file_create (desktop_file, G_FILE_CREATE_NONE, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch5_g_error;
		}
		data_stream = g_data_output_stream_new ((GOutputStream*) file_stream);
		g_data_output_stream_put_string (data_stream, webapp_desktop, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_object_unref0 (data_stream);
			_g_object_unref0 (file_stream);
			goto __catch5_g_error;
		}
		_g_object_unref0 (data_stream);
		_g_object_unref0 (file_stream);
	}
	goto __finally5;
	__catch5_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("prism-handler.vala:140: could not write to %s/%s.desktop", self->priv->webapp_dir, self->name);
			_g_error_free0 (e);
			_g_object_unref0 (desktop_file);
			_g_object_unref0 (inifile);
			_g_object_unref0 (webapp_directory);
			_g_free0 (webapp_desktop);
			_g_free0 (webapp_ini);
			return;
		}
	}
	__finally5:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (desktop_file);
		_g_object_unref0 (inifile);
		_g_object_unref0 (webapp_directory);
		_g_free0 (webapp_desktop);
		_g_free0 (webapp_ini);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_object_unref0 (desktop_file);
	_g_object_unref0 (inifile);
	_g_object_unref0 (webapp_directory);
	_g_free0 (webapp_desktop);
	_g_free0 (webapp_ini);
}


void unity_webapp_prism_add_to_favorites (UnityWebappPrism* self) {
	UnityFavorites* favorites;
	char* uid;
	char* _tmp0_;
	char* _tmp1_;
	char* desktop_path;
	char* _tmp2_;
	char* _tmp3_;
	char* _tmp4_;
	g_return_if_fail (self != NULL);
	favorites = unity_favorites_get_default ();
	uid = unity_webapp_prism_get_fav_uid (self);
	if (_vala_strcmp0 (uid, "") != 0) {
		g_warning ("prism-handler.vala:152: %s is already a favorite", self->name);
		_g_free0 (uid);
		_g_object_unref0 (favorites);
		return;
	}
	desktop_path = (_tmp1_ = g_strconcat (self->priv->webapp_dir, _tmp0_ = g_strdup_printf ("/%s.desktop", self->name), NULL), _g_free0 (_tmp0_), _tmp1_);
	uid = (_tmp3_ = g_strconcat ("webapp-", _tmp2_ = g_path_get_basename (desktop_path), NULL), _g_free0 (uid), _tmp3_);
	_g_free0 (_tmp2_);
	uid = (_tmp4_ = unity_webapp_urlify (uid), _g_free0 (uid), _tmp4_);
	unity_favorites_set_string (favorites, uid, "type", "application");
	unity_favorites_set_string (favorites, uid, "desktop_file", desktop_path);
	unity_favorites_add_favorite (favorites, uid);
	_g_free0 (desktop_path);
	_g_free0 (uid);
	_g_object_unref0 (favorites);
}


/**
     * gets the favorite uid for this desktop file
     */
static char* unity_webapp_prism_get_fav_uid (UnityWebappPrism* self) {
	char* result = NULL;
	char* myuid;
	char* _tmp0_;
	char* _tmp1_;
	char* my_desktop_path;
	UnityFavorites* favorites;
	GeeArrayList* favorite_list;
	g_return_val_if_fail (self != NULL, NULL);
	myuid = g_strdup ("");
	my_desktop_path = (_tmp1_ = g_strconcat (self->priv->webapp_dir, _tmp0_ = g_strdup_printf ("/%s.desktop", self->name), NULL), _g_free0 (_tmp0_), _tmp1_);
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


const char* unity_webapp_prism_get_url (UnityWebappPrism* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_url;
	return result;
}


static void unity_webapp_prism_set_url (UnityWebappPrism* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_url = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_url), _tmp0_);
	g_object_notify ((GObject *) self, "url");
}


const char* unity_webapp_prism_get_icon (UnityWebappPrism* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_icon;
	return result;
}


static void unity_webapp_prism_set_icon (UnityWebappPrism* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_icon = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_icon), _tmp0_);
	g_object_notify ((GObject *) self, "icon");
}


static GObject * unity_webapp_prism_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityWebappPrism * self;
	GError * _inner_error_;
	parent_class = G_OBJECT_CLASS (unity_webapp_prism_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_WEBAPP_PRISM (obj);
	_inner_error_ = NULL;
	{
		gint split_url_length1;
		gint _split_url_size_;
		char** _tmp1_;
		char** _tmp0_;
		char** split_url;
		char* _tmp2_;
		char* _tmp5_;
		char* _tmp6_;
		char* _tmp7_;
		gboolean exists;
		split_url = (_tmp1_ = _tmp0_ = g_strsplit (self->priv->_url, "://", 2), split_url_length1 = _vala_array_length (_tmp0_), _split_url_size_ = split_url_length1, _tmp1_);
		self->name = (_tmp2_ = g_strdup (split_url[1]), _g_free0 (self->name), _tmp2_);
		{
			GRegex* regex;
			char* _tmp3_;
			char* _tmp4_;
			regex = g_regex_new ("(/)", 0, 0, &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch6_g_regex_error;
				}
				split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
			}
			_tmp3_ = g_regex_replace (regex, self->name, (gssize) (-1), 0, "-", 0, &_inner_error_);
			if (_inner_error_ != NULL) {
				_g_regex_unref0 (regex);
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch6_g_regex_error;
				}
				_g_regex_unref0 (regex);
				split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
			}
			self->name = (_tmp4_ = _tmp3_, _g_free0 (self->name), _tmp4_);
			_g_regex_unref0 (regex);
		}
		goto __finally6;
		__catch6_g_regex_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("prism-handler.vala:67: %s", e->message);
				_g_error_free0 (e);
			}
		}
		__finally6:
		if (_inner_error_ != NULL) {
			split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		self->id = (_tmp5_ = g_strdup (self->name), _g_free0 (self->id), _tmp5_);
		self->priv->webapp_dir = (_tmp7_ = g_strconcat (g_get_home_dir (), _tmp6_ = g_strdup_printf ("/.webapps/%s@unity.app", self->id), NULL), _g_free0 (self->priv->webapp_dir), _tmp7_);
		_g_free0 (_tmp6_);
		exists = unity_webapp_prism_check_existance_of_app (self);
		if (!exists) {
			unity_webapp_prism_build_webapp (self);
		}
		split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
	}
	return obj;
}


static void unity_webapp_prism_class_init (UnityWebappPrismClass * klass) {
	unity_webapp_prism_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityWebappPrismPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_webapp_prism_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_webapp_prism_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_webapp_prism_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_webapp_prism_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_WEBAPP_PRISM_URL, g_param_spec_string ("url", "url", "url", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_WEBAPP_PRISM_ICON, g_param_spec_string ("icon", "icon", "icon", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_webapp_prism_instance_init (UnityWebappPrism * self) {
	self->priv = UNITY_WEBAPP_PRISM_GET_PRIVATE (self);
}


static void unity_webapp_prism_finalize (GObject* obj) {
	UnityWebappPrism * self;
	self = UNITY_WEBAPP_PRISM (obj);
	_g_free0 (self->priv->_url);
	_g_free0 (self->priv->_icon);
	_g_free0 (self->name);
	_g_free0 (self->id);
	_g_free0 (self->priv->webapp_dir);
	G_OBJECT_CLASS (unity_webapp_prism_parent_class)->finalize (obj);
}


GType unity_webapp_prism_get_type (void) {
	static volatile gsize unity_webapp_prism_type_id__volatile = 0;
	if (g_once_init_enter (&unity_webapp_prism_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityWebappPrismClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_webapp_prism_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityWebappPrism), 0, (GInstanceInitFunc) unity_webapp_prism_instance_init, NULL };
		GType unity_webapp_prism_type_id;
		unity_webapp_prism_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityWebappPrism", &g_define_type_info, 0);
		g_once_init_leave (&unity_webapp_prism_type_id__volatile, unity_webapp_prism_type_id);
	}
	return unity_webapp_prism_type_id__volatile;
}


static void unity_webapp_prism_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityWebappPrism * self;
	self = UNITY_WEBAPP_PRISM (object);
	switch (property_id) {
		case UNITY_WEBAPP_PRISM_URL:
		g_value_set_string (value, unity_webapp_prism_get_url (self));
		break;
		case UNITY_WEBAPP_PRISM_ICON:
		g_value_set_string (value, unity_webapp_prism_get_icon (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_webapp_prism_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityWebappPrism * self;
	self = UNITY_WEBAPP_PRISM (object);
	switch (property_id) {
		case UNITY_WEBAPP_PRISM_URL:
		unity_webapp_prism_set_url (self, g_value_get_string (value));
		break;
		case UNITY_WEBAPP_PRISM_ICON:
		unity_webapp_prism_set_icon (self, g_value_get_string (value));
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




