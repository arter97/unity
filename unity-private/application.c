/* application.c generated by valac 0.9.5, the Vala compiler
 * generated from application.vala, do not modify */

/*
 * Copyright (C) 2009 Canonical Ltd
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
#include <unique/unique.h>
#include <unity.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define UNITY_TYPE_APPLICATION_COMMANDS (unity_application_commands_get_type ())

#define UNITY_TYPE_APPLICATION (unity_application_get_type ())
#define UNITY_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_APPLICATION, UnityApplication))
#define UNITY_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_APPLICATION, UnityApplicationClass))
#define UNITY_IS_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_APPLICATION))
#define UNITY_IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_APPLICATION))
#define UNITY_APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_APPLICATION, UnityApplicationClass))

typedef struct _UnityApplication UnityApplication;
typedef struct _UnityApplicationClass UnityApplicationClass;
typedef struct _UnityApplicationPrivate UnityApplicationPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))

typedef enum  {
	UNITY_APPLICATION_COMMANDS_SHOW = 1,
	UNITY_APPLICATION_COMMANDS_MAKE_WEBAPP
} UnityApplicationCommands;

struct _UnityApplication {
	UniqueApp parent_instance;
	UnityApplicationPrivate * priv;
};

struct _UnityApplicationClass {
	UniqueAppClass parent_class;
};

struct _UnityApplicationPrivate {
	UnityShell* _shell;
	UnityWebappWebiconFetcher* webicon_fetcher;
};


static gpointer unity_application_parent_class = NULL;

GType unity_application_commands_get_type (void) G_GNUC_CONST;
GType unity_application_get_type (void) G_GNUC_CONST;
#define UNITY_APPLICATION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TYPE_APPLICATION, UnityApplicationPrivate))
enum  {
	UNITY_APPLICATION_DUMMY_PROPERTY,
	UNITY_APPLICATION_SHELL
};
UnityApplication* unity_application_new (void);
UnityApplication* unity_application_construct (GType object_type);
UnityShell* unity_application_get_shell (UnityApplication* self);
UniqueResponse unity_application_on_message_received (UnityApplication* self, gint command, UniqueMessageData* data, guint time_);
void unity_application_set_shell (UnityApplication* self, UnityShell* value);
static UniqueResponse _unity_application_on_message_received_unique_app_message_received (UniqueApp* _sender, gint command, UniqueMessageData* message_data, guint time_, gpointer self);
static GObject * unity_application_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_application_finalize (GObject* obj);
static void unity_application_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_application_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);



GType unity_application_commands_get_type (void) {
	static volatile gsize unity_application_commands_type_id__volatile = 0;
	if (g_once_init_enter (&unity_application_commands_type_id__volatile)) {
		static const GEnumValue values[] = {{UNITY_APPLICATION_COMMANDS_SHOW, "UNITY_APPLICATION_COMMANDS_SHOW", "show"}, {UNITY_APPLICATION_COMMANDS_MAKE_WEBAPP, "UNITY_APPLICATION_COMMANDS_MAKE_WEBAPP", "make-webapp"}, {0, NULL, NULL}};
		GType unity_application_commands_type_id;
		unity_application_commands_type_id = g_enum_register_static ("UnityApplicationCommands", values);
		g_once_init_leave (&unity_application_commands_type_id__volatile, unity_application_commands_type_id);
	}
	return unity_application_commands_type_id__volatile;
}


UnityApplication* unity_application_construct (GType object_type) {
	UnityApplication * self;
	self = (UnityApplication*) g_object_new (object_type, "name", "com.canonical.Unity", NULL);
	return self;
}


UnityApplication* unity_application_new (void) {
	return unity_application_construct (UNITY_TYPE_APPLICATION);
}


UniqueResponse unity_application_on_message_received (UnityApplication* self, gint command, UniqueMessageData* data, guint time_) {
	UniqueResponse result = 0;
	GError * _inner_error_;
	UniqueResponse res;
	char* _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (data != NULL, 0);
	_inner_error_ = NULL;
	res = UNIQUE_RESPONSE_OK;
	g_debug ("application.vala:57: Message Received: %d '%s' %d", command, _tmp0_ = unique_message_data_get_text (data), (gint) time_);
	_g_free0 (_tmp0_);
	switch (command) {
		case UNITY_APPLICATION_COMMANDS_SHOW:
		{
			{
				if (UNITY_IS_SHELL (unity_application_get_shell (self))) {
					unity_shell_show_unity (unity_application_get_shell (self));
				}
			}
			break;
		}
		case UNITY_APPLICATION_COMMANDS_MAKE_WEBAPP:
		{
			{
				char* uri;
				char* icon_dirstring;
				GFile* icon_directory;
				char** _tmp2_;
				gint _split_url_size_;
				gint split_url_length1;
				char** _tmp1_;
				char** split_url;
				char* name;
				char* hostname;
				char* _tmp5_;
				UnityWebappChromiumWebApp* _tmp6_;
				UnityWebappChromiumWebApp* webapp;
				UnityWebappWebiconFetcher* _tmp10_;
				char* _tmp9_;
				char* _tmp8_;
				char* _tmp7_;
				uri = unique_message_data_get_text (data);
				icon_dirstring = g_strconcat (g_get_home_dir (), "/.local/share/icons/", NULL);
				icon_directory = g_file_new_for_path (icon_dirstring);
				{
					if (!g_file_query_exists (icon_directory, NULL)) {
						g_file_make_directory_with_parents (icon_directory, NULL, &_inner_error_);
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
						_g_error_free0 (e);
					}
				}
				__finally0:
				if (_inner_error_ != NULL) {
					_g_object_unref0 (icon_directory);
					_g_free0 (icon_dirstring);
					_g_free0 (uri);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return 0;
				}
				split_url = (_tmp2_ = _tmp1_ = g_strsplit (uri, "://", 2), split_url_length1 = _vala_array_length (_tmp1_), _split_url_size_ = split_url_length1, _tmp2_);
				name = g_strdup (split_url[1]);
				{
					GRegex* regex;
					char* _tmp3_;
					char* _tmp4_;
					regex = g_regex_new ("(/)", 0, 0, &_inner_error_);
					if (_inner_error_ != NULL) {
						if (_inner_error_->domain == G_REGEX_ERROR) {
							goto __catch1_g_regex_error;
						}
						_g_free0 (name);
						split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
						_g_object_unref0 (icon_directory);
						_g_free0 (icon_dirstring);
						_g_free0 (uri);
						g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return 0;
					}
					_tmp3_ = g_regex_replace (regex, name, (gssize) (-1), 0, "", 0, &_inner_error_);
					if (_inner_error_ != NULL) {
						_g_regex_unref0 (regex);
						if (_inner_error_->domain == G_REGEX_ERROR) {
							goto __catch1_g_regex_error;
						}
						_g_regex_unref0 (regex);
						_g_free0 (name);
						split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
						_g_object_unref0 (icon_directory);
						_g_free0 (icon_dirstring);
						_g_free0 (uri);
						g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return 0;
					}
					name = (_tmp4_ = _tmp3_, _g_free0 (name), _tmp4_);
					_g_regex_unref0 (regex);
				}
				goto __finally1;
				__catch1_g_regex_error:
				{
					GError * e;
					e = _inner_error_;
					_inner_error_ = NULL;
					{
						g_warning ("application.vala:91: %s", e->message);
						_g_error_free0 (e);
					}
				}
				__finally1:
				if (_inner_error_ != NULL) {
					_g_free0 (name);
					split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
					_g_object_unref0 (icon_directory);
					_g_free0 (icon_dirstring);
					_g_free0 (uri);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return 0;
				}
				hostname = unity_webapp_get_hostname (uri);
				webapp = (_tmp6_ = unity_webapp_chromium_web_app_new (uri, _tmp5_ = g_strconcat (name, ".png", NULL)), _g_free0 (_tmp5_), _tmp6_);
				self->priv->webicon_fetcher = (_tmp10_ = unity_webapp_webicon_fetcher_new (uri, _tmp8_ = g_strconcat (_tmp7_ = g_strconcat (icon_dirstring, hostname, NULL), ".png", NULL), _tmp9_ = unity_webapp_chromium_web_app_desktop_file_path (webapp)), _g_object_unref0 (self->priv->webicon_fetcher), _tmp10_);
				_g_free0 (_tmp9_);
				_g_free0 (_tmp8_);
				_g_free0 (_tmp7_);
				unity_webapp_webicon_fetcher_fetch_webapp_data (self->priv->webicon_fetcher);
				unity_webapp_chromium_web_app_add_to_favorites (webapp);
				_g_object_unref0 (webapp);
				_g_free0 (hostname);
				_g_free0 (name);
				split_url = (_vala_array_free (split_url, split_url_length1, (GDestroyNotify) g_free), NULL);
				_g_object_unref0 (icon_directory);
				_g_free0 (icon_dirstring);
				_g_free0 (uri);
			}
			break;
		}
		default:
		{
			break;
		}
	}
	result = res;
	return result;
}


UnityShell* unity_application_get_shell (UnityApplication* self) {
	UnityShell* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_shell;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void unity_application_set_shell (UnityApplication* self, UnityShell* value) {
	UnityShell* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_shell = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_shell), _tmp0_);
	g_object_notify ((GObject *) self, "shell");
}


static UniqueResponse _unity_application_on_message_received_unique_app_message_received (UniqueApp* _sender, gint command, UniqueMessageData* message_data, guint time_, gpointer self) {
	UniqueResponse result;
	result = unity_application_on_message_received (self, command, message_data, time_);
	return result;
}


static GObject * unity_application_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityApplication * self;
	parent_class = G_OBJECT_CLASS (unity_application_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_APPLICATION (obj);
	{
		unique_app_add_command ((UniqueApp*) self, "show", (gint) UNITY_APPLICATION_COMMANDS_SHOW);
		unique_app_add_command ((UniqueApp*) self, "make webapp", (gint) UNITY_APPLICATION_COMMANDS_MAKE_WEBAPP);
		g_signal_connect_object ((UniqueApp*) self, "message-received", (GCallback) _unity_application_on_message_received_unique_app_message_received, self, 0);
	}
	return obj;
}


static void unity_application_class_init (UnityApplicationClass * klass) {
	unity_application_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityApplicationPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_application_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_application_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_application_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_application_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_APPLICATION_SHELL, g_param_spec_object ("shell", "shell", "shell", UNITY_TYPE_SHELL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void unity_application_instance_init (UnityApplication * self) {
	self->priv = UNITY_APPLICATION_GET_PRIVATE (self);
}


static void unity_application_finalize (GObject* obj) {
	UnityApplication * self;
	self = UNITY_APPLICATION (obj);
	_g_object_unref0 (self->priv->_shell);
	_g_object_unref0 (self->priv->webicon_fetcher);
	G_OBJECT_CLASS (unity_application_parent_class)->finalize (obj);
}


GType unity_application_get_type (void) {
	static volatile gsize unity_application_type_id__volatile = 0;
	if (g_once_init_enter (&unity_application_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityApplicationClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_application_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityApplication), 0, (GInstanceInitFunc) unity_application_instance_init, NULL };
		GType unity_application_type_id;
		unity_application_type_id = g_type_register_static (UNIQUE_TYPE_APP, "UnityApplication", &g_define_type_info, 0);
		g_once_init_leave (&unity_application_type_id__volatile, unity_application_type_id);
	}
	return unity_application_type_id__volatile;
}


static void unity_application_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityApplication * self;
	self = UNITY_APPLICATION (object);
	switch (property_id) {
		case UNITY_APPLICATION_SHELL:
		g_value_set_object (value, unity_application_get_shell (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_application_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityApplication * self;
	self = UNITY_APPLICATION (object);
	switch (property_id) {
		case UNITY_APPLICATION_SHELL:
		unity_application_set_shell (self, g_value_get_object (value));
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




