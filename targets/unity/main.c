/* main.c generated by valac, the Vala compiler
 * generated from main.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <unity-private.h>
#include <glib/gi18n-lib.h>
#include <config.h>
#include <unity-utils.h>
#include <gtk/gtk.h>
#include <clutk/clutk.h>
#include <unique/unique.h>
#include <unity.h>
#include <libwnck/libwnck.h>
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
#define _g_option_context_free0(var) ((var == NULL) ? NULL : (var = (g_option_context_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _unique_message_data_free0(var) ((var == NULL) ? NULL : (var = (unique_message_data_free (var), NULL)))
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


extern gboolean show_unity;
gboolean show_unity = FALSE;
extern gboolean popup_mode;
gboolean popup_mode = FALSE;
extern gint popup_width;
gint popup_width = 1024;
extern gint popup_height;
gint popup_height = 600;
extern gboolean show_version;
gboolean show_version = FALSE;
extern char* webapp_uri;
char* webapp_uri = NULL;
extern char* boot_logging_filename;
char* boot_logging_filename = NULL;
static gpointer main_parent_class = NULL;

gpointer main_ref (gpointer instance);
void main_unref (gpointer instance);
GParamSpec* param_spec_main (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_main (GValue* value, gpointer v_object);
void value_take_main (GValue* value, gpointer v_object);
gpointer value_get_main (const GValue* value);
GType main_get_type (void);
enum  {
	MAIN_DUMMY_PROPERTY
};
static gboolean _lambda0_ (void);
static gboolean __lambda0__gsource_func (gpointer self);
gint main_main (char** args, int args_length1);
Main* main_new (void);
Main* main_construct (GType object_type);
static void main_finalize (Main* obj);

const GOptionEntry options[7] = {{"show", 's', 0, G_OPTION_ARG_NONE, &show_unity, "Show Unity to the user", NULL}, {"popup", 'p', 0, G_OPTION_ARG_NONE, &popup_mode, "Popup the Unity window (for debugging)", NULL}, {"width", 'w', 0, G_OPTION_ARG_INT, &popup_width, "Width of Unity window (use with --popup/-p). Default: 1024", NULL}, {"height", 'h', 0, G_OPTION_ARG_INT, &popup_height, "Height of Unity window (use with --popup/-p). Default: 600", NULL}, {"version", 'v', 0, G_OPTION_ARG_NONE, &show_version, "Show the version and exit", NULL}, {"webapp", 'b', 0, G_OPTION_ARG_STRING, &webapp_uri, "Supply a webapp url to have unity load the webapp into your favorites", NULL}, {NULL}};


#line 188 "main.vala"
static gboolean _lambda0_ (void) {
#line 111 "main.c"
	gboolean result = FALSE;
#line 189 "main.vala"
	unity_timeline_logger_write_log (unity_timeline_logger_get_default (), boot_logging_filename);
#line 115 "main.c"
	result = FALSE;
#line 190 "main.vala"
	return result;
#line 119 "main.c"
}


#line 188 "main.vala"
static gboolean __lambda0__gsource_func (gpointer self) {
#line 125 "main.c"
	return _lambda0_ ();
}


#line 91 "main.vala"
gint main_main (char** args, int args_length1) {
#line 132 "main.c"
	gint result = 0;
	GError * _inner_error_;
	UnityApplication* app;
	UnityTestingWindow* window;
	char* _tmp0_;
	UnityApplication* _tmp1_;
	char* disable_unique;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_;
	char* cur_tray_envvar;
	UnityTestingWindow* _tmp5_;
	_inner_error_ = NULL;
	app = NULL;
	window = NULL;
#line 95 "main.vala"
	unity_timeline_logger_get_default ();
#line 97 "main.vala"
	textdomain (GETTEXT_PACKAGE);
#line 98 "main.vala"
	bindtextdomain (GETTEXT_PACKAGE, LOCALE_DIR);
#line 99 "main.vala"
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
#line 155 "main.c"
	{
		GOptionContext* opt_context;
#line 103 "main.vala"
		opt_context = g_option_context_new ("-- Unity");
#line 104 "main.vala"
		g_option_context_set_help_enabled (opt_context, TRUE);
#line 105 "main.vala"
		g_option_context_add_main_entries (opt_context, options, NULL);
#line 106 "main.vala"
		g_option_context_parse (opt_context, &args_length1, &args, &_inner_error_);
#line 166 "main.c"
		if (_inner_error_ != NULL) {
			_g_option_context_free0 (opt_context);
			if (_inner_error_->domain == G_OPTION_ERROR) {
				goto __catch0_g_option_error;
			}
			_g_option_context_free0 (opt_context);
			_g_object_unref0 (app);
			_g_object_unref0 (window);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return 0;
		}
		_g_option_context_free0 (opt_context);
	}
	goto __finally0;
	__catch0_g_option_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 110 "main.vala"
			g_warning ("main.vala:110: Unable to parse arguments: %s", e->message);
#line 111 "main.vala"
			g_warning ("main.vala:111: Run '%s --help' to see a full list of available command" \
" line options", args[0]);
#line 192 "main.c"
			result = 1;
			_g_error_free0 (e);
			_g_object_unref0 (app);
			_g_object_unref0 (window);
#line 113 "main.vala"
			return result;
#line 199 "main.c"
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (app);
		_g_object_unref0 (window);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
#line 116 "main.vala"
	if (show_version) {
#line 118 "main.vala"
		g_print ("\nUnity %s\n", VERSION);
#line 214 "main.c"
		result = 0;
		_g_object_unref0 (app);
		_g_object_unref0 (window);
#line 119 "main.vala"
		return result;
#line 220 "main.c"
	}
#line 122 "main.vala"
	boot_logging_filename = (_tmp0_ = g_strdup (g_getenv ("UNITY_BOOTLOG_FILENAME")), _g_free0 (boot_logging_filename), _tmp0_);
#line 123 "main.vala"
	if (boot_logging_filename != NULL) {
#line 125 "main.vala"
		unity_is_logging = TRUE;
#line 228 "main.c"
	} else {
#line 129 "main.vala"
		unity_is_logging = FALSE;
#line 232 "main.c"
	}
#line 131 "main.vala"
	START_FUNCTION ();
#line 134 "main.vala"
	LOGGER_START_PROCESS ("gtk_init");
#line 135 "main.vala"
	gtk_init (&args_length1, &args);
#line 136 "main.vala"
	LOGGER_END_PROCESS ("gtk_init");
#line 137 "main.vala"
	LOGGER_START_PROCESS ("ctk_init");
#line 138 "main.vala"
	ctk_init (&args_length1, &args);
#line 139 "main.vala"
	LOGGER_END_PROCESS ("ctk_init");
#line 141 "main.vala"
	g_object_set (gtk_settings_get_default (), "gtk-icon-theme-name", "ubuntu-mono-dark", NULL);
#line 144 "main.vala"
	LOGGER_START_PROCESS ("unity_application_constructor");
#line 145 "main.vala"
	app = (_tmp1_ = unity_application_new (), _g_object_unref0 (app), _tmp1_);
#line 146 "main.vala"
	LOGGER_END_PROCESS ("unity_application_constructor");
#line 148 "main.vala"
	disable_unique = g_strdup (g_getenv ("UNITY_NO_UNIQUE"));
#line 149 "main.vala"
	if ((g_object_get ((UniqueApp*) app, "is-running", &_tmp3_, NULL), _tmp3_)) {
#line 149 "main.vala"
		_tmp2_ = disable_unique == NULL;
#line 262 "main.c"
	} else {
#line 149 "main.vala"
		_tmp2_ = FALSE;
#line 266 "main.c"
	}
#line 149 "main.vala"
	if (_tmp2_) {
#line 270 "main.c"
		UniqueResponse response;
		gint _tmp4_ = 0;
#line 151 "main.vala"
		response = UNIQUE_RESPONSE_OK;
#line 153 "main.vala"
		if (show_unity) {
#line 155 "main.vala"
			g_print ("Showing Unity window\n");
#line 156 "main.vala"
			response = unique_app_send_message ((UniqueApp*) app, (gint) UNITY_APPLICATION_COMMANDS_SHOW, NULL);
#line 281 "main.c"
		} else {
#line 158 "main.vala"
			if (webapp_uri != NULL) {
#line 285 "main.c"
				UniqueMessageData* message;
#line 160 "main.vala"
				g_print ("building webapp\n");
#line 161 "main.vala"
				message = unique_message_data_new ();
#line 162 "main.vala"
				unique_message_data_set_text (message, webapp_uri, (gssize) g_utf8_strlen);
#line 163 "main.vala"
				response = unique_app_send_message ((UniqueApp*) app, (gint) UNITY_APPLICATION_COMMANDS_MAKE_WEBAPP, message);
#line 295 "main.c"
				_unique_message_data_free0 (message);
			} else {
#line 167 "main.vala"
				g_print ("There already another instance of Unity running\n");
#line 300 "main.c"
			}
		}
#line 170 "main.vala"
		if (response == UNIQUE_RESPONSE_OK) {
#line 170 "main.vala"
			_tmp4_ = 0;
#line 307 "main.c"
		} else {
#line 170 "main.vala"
			_tmp4_ = 1;
#line 311 "main.c"
		}
		result = _tmp4_;
		_g_object_unref0 (app);
		_g_object_unref0 (window);
		_g_free0 (disable_unique);
#line 170 "main.vala"
		return result;
#line 319 "main.c"
	}
#line 174 "main.vala"
	cur_tray_envvar = g_strdup (g_getenv ("UNITY_DISABLE_TRAY"));
#line 175 "main.vala"
	g_setenv ("UNITY_DISABLE_TRAY", "1", TRUE);
#line 178 "main.vala"
	window = (_tmp5_ = g_object_ref_sink (unity_testing_window_new (popup_mode, popup_width, popup_height)), _g_object_unref0 (window), _tmp5_);
#line 179 "main.vala"
	unity_application_set_shell (app, (UnityShell*) window);
#line 180 "main.vala"
	LOGGER_START_PROCESS ("unity_underlay_window_show");
#line 181 "main.vala"
	gtk_widget_show ((GtkWidget*) window);
#line 182 "main.vala"
	LOGGER_END_PROCESS ("unity_underlay_window_show");
#line 184 "main.vala"
	END_FUNCTION ();
#line 186 "main.vala"
	if (boot_logging_filename != NULL) {
#line 188 "main.vala"
		g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) 1, __lambda0__gsource_func, NULL, NULL);
#line 341 "main.c"
	}
#line 194 "main.vala"
	wnck_set_client_type (WNCK_CLIENT_TYPE_PAGER);
#line 195 "main.vala"
	gtk_main ();
#line 198 "main.vala"
	g_setenv ("UNITY_DISABLE_TRAY", cur_tray_envvar, TRUE);
#line 349 "main.c"
	result = 0;
	_g_object_unref0 (app);
	_g_object_unref0 (window);
	_g_free0 (disable_unique);
	_g_free0 (cur_tray_envvar);
#line 200 "main.vala"
	return result;
#line 357 "main.c"
}


#line 91 "main.vala"
int main (int argc, char ** argv) {
#line 363 "main.c"
	g_thread_init (NULL);
#line 91 "main.vala"
	g_type_init ();
#line 91 "main.vala"
	return main_main (argv, argc);
#line 369 "main.c"
}


#line 89 "main.vala"
Main* main_construct (GType object_type) {
#line 375 "main.c"
	Main* self;
	self = (Main*) g_type_create_instance (object_type);
	return self;
}


#line 89 "main.vala"
Main* main_new (void) {
#line 89 "main.vala"
	return main_construct (TYPE_MAIN);
#line 386 "main.c"
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




