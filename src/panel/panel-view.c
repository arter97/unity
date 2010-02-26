/* panel-view.c generated by valac, the Vala compiler
 * generated from panel-view.vala, do not modify */

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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <clutk/clutk.h>
#include <unity.h>
#include <clutter/clutter.h>
#include <gconf/gconf-client.h>
#include <float.h>
#include <math.h>
#include <unity-utils.h>


#define UNITY_PANEL_TYPE_VIEW (unity_panel_view_get_type ())
#define UNITY_PANEL_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_TYPE_VIEW, UnityPanelView))
#define UNITY_PANEL_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_TYPE_VIEW, UnityPanelViewClass))
#define UNITY_PANEL_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_TYPE_VIEW))
#define UNITY_PANEL_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_TYPE_VIEW))
#define UNITY_PANEL_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_TYPE_VIEW, UnityPanelViewClass))

typedef struct _UnityPanelView UnityPanelView;
typedef struct _UnityPanelViewClass UnityPanelViewClass;
typedef struct _UnityPanelViewPrivate UnityPanelViewPrivate;

#define UNITY_PANEL_TRAY_TYPE_VIEW (unity_panel_tray_view_get_type ())
#define UNITY_PANEL_TRAY_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_TRAY_TYPE_VIEW, UnityPanelTrayView))
#define UNITY_PANEL_TRAY_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_TRAY_TYPE_VIEW, UnityPanelTrayViewClass))
#define UNITY_PANEL_TRAY_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_TRAY_TYPE_VIEW))
#define UNITY_PANEL_TRAY_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_TRAY_TYPE_VIEW))
#define UNITY_PANEL_TRAY_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_TRAY_TYPE_VIEW, UnityPanelTrayViewClass))

typedef struct _UnityPanelTrayView UnityPanelTrayView;
typedef struct _UnityPanelTrayViewClass UnityPanelTrayViewClass;

#define UNITY_PANEL_TYPE_HOME_BUTTON (unity_panel_home_button_get_type ())
#define UNITY_PANEL_HOME_BUTTON(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_TYPE_HOME_BUTTON, UnityPanelHomeButton))
#define UNITY_PANEL_HOME_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_TYPE_HOME_BUTTON, UnityPanelHomeButtonClass))
#define UNITY_PANEL_IS_HOME_BUTTON(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_TYPE_HOME_BUTTON))
#define UNITY_PANEL_IS_HOME_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_TYPE_HOME_BUTTON))
#define UNITY_PANEL_HOME_BUTTON_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_TYPE_HOME_BUTTON, UnityPanelHomeButtonClass))

typedef struct _UnityPanelHomeButton UnityPanelHomeButton;
typedef struct _UnityPanelHomeButtonClass UnityPanelHomeButtonClass;

#define UNITY_PANEL_INDICATORS_TYPE_VIEW (unity_panel_indicators_view_get_type ())
#define UNITY_PANEL_INDICATORS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_INDICATORS_TYPE_VIEW, UnityPanelIndicatorsView))
#define UNITY_PANEL_INDICATORS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_INDICATORS_TYPE_VIEW, UnityPanelIndicatorsViewClass))
#define UNITY_PANEL_INDICATORS_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_INDICATORS_TYPE_VIEW))
#define UNITY_PANEL_INDICATORS_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_INDICATORS_TYPE_VIEW))
#define UNITY_PANEL_INDICATORS_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_INDICATORS_TYPE_VIEW, UnityPanelIndicatorsViewClass))

typedef struct _UnityPanelIndicatorsView UnityPanelIndicatorsView;
typedef struct _UnityPanelIndicatorsViewClass UnityPanelIndicatorsViewClass;

#define UNITY_PLACES_CAIRO_DRAWING_TYPE_ENTRY_BACKGROUND (unity_places_cairo_drawing_entry_background_get_type ())
#define UNITY_PLACES_CAIRO_DRAWING_ENTRY_BACKGROUND(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_CAIRO_DRAWING_TYPE_ENTRY_BACKGROUND, UnityPlacesCairoDrawingEntryBackground))
#define UNITY_PLACES_CAIRO_DRAWING_ENTRY_BACKGROUND_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_CAIRO_DRAWING_TYPE_ENTRY_BACKGROUND, UnityPlacesCairoDrawingEntryBackgroundClass))
#define UNITY_PLACES_CAIRO_DRAWING_IS_ENTRY_BACKGROUND(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_CAIRO_DRAWING_TYPE_ENTRY_BACKGROUND))
#define UNITY_PLACES_CAIRO_DRAWING_IS_ENTRY_BACKGROUND_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_CAIRO_DRAWING_TYPE_ENTRY_BACKGROUND))
#define UNITY_PLACES_CAIRO_DRAWING_ENTRY_BACKGROUND_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_CAIRO_DRAWING_TYPE_ENTRY_BACKGROUND, UnityPlacesCairoDrawingEntryBackgroundClass))

typedef struct _UnityPlacesCairoDrawingEntryBackground UnityPlacesCairoDrawingEntryBackground;
typedef struct _UnityPlacesCairoDrawingEntryBackgroundClass UnityPlacesCairoDrawingEntryBackgroundClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) ((var == NULL) ? NULL : (var = (g_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
typedef struct _UnityPlacesCairoDrawingEntryBackgroundPrivate UnityPlacesCairoDrawingEntryBackgroundPrivate;

struct _UnityPanelView {
	CtkActor parent_instance;
	UnityPanelViewPrivate * priv;
};

struct _UnityPanelViewClass {
	CtkActorClass parent_class;
};

struct _UnityPanelViewPrivate {
	UnityShell* _shell;
	UnityThemeImage* rect;
	UnityPanelTrayView* tray;
	UnityPanelHomeButton* home;
	UnityPanelIndicatorsView* indicators;
	UnityThemeImage* entry_icon;
	UnityEntry* entry;
	UnityPlacesCairoDrawingEntryBackground* entry_background;
	gint indicators_width;
};

struct _UnityPlacesCairoDrawingEntryBackground {
	CtkBin parent_instance;
	UnityPlacesCairoDrawingEntryBackgroundPrivate * priv;
	gint Width;
	gint Height;
	ClutterCairoTexture* cairotxt;
};

struct _UnityPlacesCairoDrawingEntryBackgroundClass {
	CtkBinClass parent_class;
};


extern gboolean* unity_panel_search_entry_has_focus;
gboolean* unity_panel_search_entry_has_focus = NULL;
static gpointer unity_panel_view_parent_class = NULL;

#define UNITY_PANEL_PANEL_HEIGHT 24
#define UNITY_PANEL_SEARCH_TEMPLATE "xdg-open http://search.yahoo.com/search?p=%s&fr=ubuntu&ei=UTF-8"
#define UNITY_PANEL_SEARCH_HINT "Yahoo!"
GType unity_panel_view_get_type (void);
GType unity_panel_tray_view_get_type (void);
GType unity_panel_home_button_get_type (void);
GType unity_panel_indicators_view_get_type (void);
GType unity_places_cairo_drawing_entry_background_get_type (void);
#define UNITY_PANEL_VIEW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PANEL_TYPE_VIEW, UnityPanelViewPrivate))
enum  {
	UNITY_PANEL_VIEW_DUMMY_PROPERTY,
	UNITY_PANEL_VIEW_SHELL
};
void unity_panel_tray_view_manage_stage (UnityPanelTrayView* self, ClutterStage* stage);
UnityShell* unity_panel_view_get_shell (UnityPanelView* self);
UnityPanelView* unity_panel_view_new (UnityShell* shell);
UnityPanelView* unity_panel_view_construct (GType object_type, UnityShell* shell);
static void unity_panel_view_on_home_clicked (UnityPanelView* self);
static gboolean* _bool_dup (gboolean* self);
static void unity_panel_view_on_entry_focus_in (UnityPanelView* self);
static void unity_panel_view_on_entry_focus_out (UnityPanelView* self);
static char* unity_panel_view_get_search_hint (UnityPanelView* self);
static void unity_panel_view_on_entry_activated (UnityPanelView* self);
void unity_places_cairo_drawing_entry_background_create_search_entry_background (UnityPlacesCairoDrawingEntryBackground* self, gint W, gint H);
static void unity_panel_view_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
static void unity_panel_view_real_paint (ClutterActor* base);
static void unity_panel_view_real_pick (ClutterActor* base, const ClutterColor* color);
static void unity_panel_view_real_map (ClutterActor* base);
static void unity_panel_view_real_unmap (ClutterActor* base);
gint unity_panel_view_get_indicators_width (UnityPanelView* self);
void unity_panel_view_set_indicator_mode (UnityPanelView* self, gboolean mode);
static void unity_panel_view_set_shell (UnityPanelView* self, UnityShell* value);
UnityPanelIndicatorsView* unity_panel_indicators_view_new (void);
UnityPanelIndicatorsView* unity_panel_indicators_view_construct (GType object_type);
UnityPanelTrayView* unity_panel_tray_view_new (void);
UnityPanelTrayView* unity_panel_tray_view_construct (GType object_type);
UnityPanelHomeButton* unity_panel_home_button_new (UnityShell* shell);
UnityPanelHomeButton* unity_panel_home_button_construct (GType object_type, UnityShell* shell);
static void _unity_panel_view_on_home_clicked_unity_panel_home_button_clicked (UnityPanelHomeButton* _sender, guint32 time_, gpointer self);
UnityPlacesCairoDrawingEntryBackground* unity_places_cairo_drawing_entry_background_new (void);
UnityPlacesCairoDrawingEntryBackground* unity_places_cairo_drawing_entry_background_construct (GType object_type);
static void _unity_panel_view_on_entry_activated_clutter_text_activate (ClutterText* _sender, gpointer self);
static void _unity_panel_view_on_entry_focus_in_clutter_actor_key_focus_in (ClutterActor* _sender, gpointer self);
static void _unity_panel_view_on_entry_focus_out_clutter_actor_key_focus_out (ClutterActor* _sender, gpointer self);
static GObject * unity_panel_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_panel_view_finalize (GObject* obj);
static void unity_panel_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_panel_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 43 "panel-view.vala"
UnityPanelView* unity_panel_view_construct (GType object_type, UnityShell* shell) {
#line 186 "panel-view.c"
	UnityPanelView * self;
	ClutterStage* _tmp0_;
#line 43 "panel-view.vala"
	g_return_val_if_fail (shell != NULL, NULL);
#line 45 "panel-view.vala"
	self = (UnityPanelView*) g_object_new (object_type, "shell", shell, "reactive", FALSE, NULL);
#line 46 "panel-view.vala"
	unity_panel_tray_view_manage_stage (self->priv->tray, _tmp0_ = unity_shell_get_stage (self->priv->_shell));
#line 195 "panel-view.c"
	_g_object_unref0 (_tmp0_);
	return self;
}


#line 43 "panel-view.vala"
UnityPanelView* unity_panel_view_new (UnityShell* shell) {
#line 43 "panel-view.vala"
	return unity_panel_view_construct (UNITY_PANEL_TYPE_VIEW, shell);
#line 205 "panel-view.c"
}


#line 92 "panel-view.vala"
static void unity_panel_view_on_home_clicked (UnityPanelView* self) {
#line 92 "panel-view.vala"
	g_return_if_fail (self != NULL);
#line 94 "panel-view.vala"
	unity_shell_show_window_picker (unity_global_shell);
#line 215 "panel-view.c"
}


static gboolean* _bool_dup (gboolean* self) {
	gboolean* dup;
	dup = g_new0 (gboolean, 1);
	memcpy (dup, self, sizeof (gboolean));
	return dup;
}


static gpointer __bool_dup0 (gpointer self) {
	return self ? _bool_dup (self) : NULL;
}


#line 97 "panel-view.vala"
static void unity_panel_view_on_entry_focus_in (UnityPanelView* self) {
#line 234 "panel-view.c"
	gboolean* _tmp1_;
	gboolean _tmp0_;
#line 97 "panel-view.vala"
	g_return_if_fail (self != NULL);
#line 99 "panel-view.vala"
	unity_panel_search_entry_has_focus = (_tmp1_ = __bool_dup0 ((_tmp0_ = TRUE, &_tmp0_)), _g_free0 (unity_panel_search_entry_has_focus), _tmp1_);
#line 241 "panel-view.c"
}


#line 102 "panel-view.vala"
static void unity_panel_view_on_entry_focus_out (UnityPanelView* self) {
#line 247 "panel-view.c"
	gboolean* _tmp1_;
	gboolean _tmp0_;
#line 102 "panel-view.vala"
	g_return_if_fail (self != NULL);
#line 104 "panel-view.vala"
	unity_panel_search_entry_has_focus = (_tmp1_ = __bool_dup0 ((_tmp0_ = FALSE, &_tmp0_)), _g_free0 (unity_panel_search_entry_has_focus), _tmp1_);
#line 254 "panel-view.c"
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 107 "panel-view.vala"
static char* unity_panel_view_get_search_hint (UnityPanelView* self) {
#line 265 "panel-view.c"
	char* result;
	GError * _inner_error_;
	char* hint;
	GConfClient* client;
#line 107 "panel-view.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 272 "panel-view.c"
	_inner_error_ = NULL;
#line 109 "panel-view.vala"
	hint = g_strdup ("");
#line 110 "panel-view.vala"
	client = _g_object_ref0 (gconf_client_get_default ());
#line 278 "panel-view.c"
	{
		char* _tmp0_;
		char* _tmp1_;
		gboolean _tmp2_ = FALSE;
#line 114 "panel-view.vala"
		_tmp0_ = gconf_client_get_string (client, "/desktop/unity/panel/search_hint", &_inner_error_);
#line 285 "panel-view.c"
		if (_inner_error_ != NULL) {
			goto __catch7_g_error;
		}
#line 114 "panel-view.vala"
		hint = (_tmp1_ = _tmp0_, _g_free0 (hint), _tmp1_);
#line 116 "panel-view.vala"
		if (_vala_strcmp0 (hint, "") == 0) {
#line 116 "panel-view.vala"
			_tmp2_ = TRUE;
#line 295 "panel-view.c"
		} else {
#line 116 "panel-view.vala"
			_tmp2_ = hint == NULL;
#line 299 "panel-view.c"
		}
#line 116 "panel-view.vala"
		if (_tmp2_) {
#line 303 "panel-view.c"
			char* _tmp3_;
#line 117 "panel-view.vala"
			hint = (_tmp3_ = g_strdup (UNITY_PANEL_SEARCH_HINT), _g_free0 (hint), _tmp3_);
#line 307 "panel-view.c"
		}
	}
	goto __finally7;
	__catch7_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp4_;
#line 121 "panel-view.vala"
			hint = (_tmp4_ = g_strdup (UNITY_PANEL_SEARCH_HINT), _g_free0 (hint), _tmp4_);
#line 320 "panel-view.c"
			_g_error_free0 (e);
		}
	}
	__finally7:
	if (_inner_error_ != NULL) {
		_g_free0 (hint);
		_g_object_unref0 (client);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	result = hint;
	_g_object_unref0 (client);
#line 124 "panel-view.vala"
	return result;
#line 336 "panel-view.c"
}


#line 1025 "glib-2.0.vapi"
static char* string_replace (const char* self, const char* old, const char* replacement) {
#line 342 "panel-view.c"
	char* result;
	GError * _inner_error_;
#line 1025 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1025 "glib-2.0.vapi"
	g_return_val_if_fail (old != NULL, NULL);
#line 1025 "glib-2.0.vapi"
	g_return_val_if_fail (replacement != NULL, NULL);
#line 351 "panel-view.c"
	_inner_error_ = NULL;
	{
		char* _tmp0_;
		GRegex* _tmp1_;
		GRegex* regex;
		char* _tmp2_;
#line 1027 "glib-2.0.vapi"
		regex = (_tmp1_ = g_regex_new (_tmp0_ = g_regex_escape_string (old, -1), 0, 0, &_inner_error_), _g_free0 (_tmp0_), _tmp1_);
#line 360 "panel-view.c"
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch9_g_regex_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
#line 1028 "glib-2.0.vapi"
		_tmp2_ = g_regex_replace_literal (regex, self, (gssize) (-1), 0, replacement, 0, &_inner_error_);
#line 371 "panel-view.c"
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch9_g_regex_error;
			}
			_g_regex_unref0 (regex);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		result = _tmp2_;
		_g_regex_unref0 (regex);
#line 1028 "glib-2.0.vapi"
		return result;
#line 386 "panel-view.c"
	}
	goto __finally9;
	__catch9_g_regex_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 1030 "glib-2.0.vapi"
			g_assert_not_reached ();
#line 397 "panel-view.c"
			_g_error_free0 (e);
		}
	}
	__finally9:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


#line 127 "panel-view.vala"
static void unity_panel_view_on_entry_activated (UnityPanelView* self) {
#line 412 "panel-view.c"
	GError * _inner_error_;
	char* template;
	GConfClient* client;
	char* _tmp5_;
	char* _tmp6_;
	char* command;
#line 127 "panel-view.vala"
	g_return_if_fail (self != NULL);
#line 421 "panel-view.c"
	_inner_error_ = NULL;
#line 129 "panel-view.vala"
	template = g_strdup ("");
#line 131 "panel-view.vala"
	client = _g_object_ref0 (gconf_client_get_default ());
#line 427 "panel-view.c"
	{
		char* _tmp0_;
		char* _tmp1_;
		gboolean _tmp2_ = FALSE;
#line 134 "panel-view.vala"
		_tmp0_ = gconf_client_get_string (client, "/desktop/unity/panel/search_template", &_inner_error_);
#line 434 "panel-view.c"
		if (_inner_error_ != NULL) {
			goto __catch8_g_error;
		}
#line 134 "panel-view.vala"
		template = (_tmp1_ = _tmp0_, _g_free0 (template), _tmp1_);
#line 136 "panel-view.vala"
		if (_vala_strcmp0 (template, "") == 0) {
#line 136 "panel-view.vala"
			_tmp2_ = TRUE;
#line 444 "panel-view.c"
		} else {
#line 136 "panel-view.vala"
			_tmp2_ = template == NULL;
#line 448 "panel-view.c"
		}
#line 136 "panel-view.vala"
		if (_tmp2_) {
#line 452 "panel-view.c"
			char* _tmp3_;
#line 137 "panel-view.vala"
			template = (_tmp3_ = g_strdup (UNITY_PANEL_SEARCH_TEMPLATE), _g_free0 (template), _tmp3_);
#line 456 "panel-view.c"
		}
	}
	goto __finally8;
	__catch8_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp4_;
#line 141 "panel-view.vala"
			template = (_tmp4_ = g_strdup (UNITY_PANEL_SEARCH_TEMPLATE), _g_free0 (template), _tmp4_);
#line 469 "panel-view.c"
			_g_error_free0 (e);
		}
	}
	__finally8:
	if (_inner_error_ != NULL) {
		_g_free0 (template);
		_g_object_unref0 (client);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
#line 144 "panel-view.vala"
	command = (_tmp6_ = string_replace (template, "%s", _tmp5_ = g_uri_escape_string (clutter_text_get_text ((ClutterText*) self->priv->entry), "", TRUE)), _g_free0 (_tmp5_), _tmp6_);
#line 483 "panel-view.c"
	{
#line 149 "panel-view.vala"
		g_spawn_command_line_async (command, &_inner_error_);
#line 487 "panel-view.c"
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
#line 153 "panel-view.vala"
			g_warning ("panel-view.vala:153: Unable to search for '%s': %s", clutter_text_get_text ((ClutterText*) self->priv->entry), e->message);
#line 501 "panel-view.c"
			_g_error_free0 (e);
		}
	}
	__finally10:
	if (_inner_error_ != NULL) {
		_g_free0 (template);
		_g_object_unref0 (client);
		_g_free0 (command);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_free0 (template);
	_g_object_unref0 (client);
	_g_free0 (command);
}


#line 159 "panel-view.vala"
static void unity_panel_view_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
#line 522 "panel-view.c"
	UnityPanelView * self;
	ClutterActorBox _tmp0_ = {0};
	ClutterActorBox child_box;
	float width = 0.0F;
	float child_width = 0.0F;
	float i_width = 0.0F;
	gboolean _tmp1_ = FALSE;
	self = (UnityPanelView*) base;
#line 162 "panel-view.vala"
	child_box = (_tmp0_.x1 = (float) 0, _tmp0_.y1 = (float) 0, _tmp0_.x2 = (*box).x2 - (*box).x1, _tmp0_.y2 = (*box).y2 - (*box).y1, _tmp0_);
#line 167 "panel-view.vala"
	CLUTTER_ACTOR_CLASS (unity_panel_view_parent_class)->allocate ((ClutterActor*) CTK_ACTOR (self), box, flags);
#line 169 "panel-view.vala"
	width = (*box).x2 - (*box).x1;
#line 174 "panel-view.vala"
	child_box.y2 = child_box.y2 + 4.0f;
#line 175 "panel-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->rect, &child_box, flags);
#line 178 "panel-view.vala"
	child_box.x1 = (float) 0;
#line 179 "panel-view.vala"
	child_box.x2 = (float) 60;
#line 180 "panel-view.vala"
	child_box.y1 = (float) 0;
#line 181 "panel-view.vala"
	child_box.y2 = (float) UNITY_PANEL_PANEL_HEIGHT;
#line 182 "panel-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->home, &child_box, flags);
#line 185 "panel-view.vala"
	child_box.x1 = floorf (child_box.x2 + 12);
#line 186 "panel-view.vala"
	child_box.x2 = floorf (child_box.x1 + 170);
#line 187 "panel-view.vala"
	child_box.y1 = floorf ((float) 2);
#line 188 "panel-view.vala"
	child_box.y2 = floorf ((float) UNITY_PANEL_PANEL_HEIGHT);
#line 190 "panel-view.vala"
	if (self->priv->entry_background->Width != ((gint) (child_box.x2 - child_box.x1))) {
#line 190 "panel-view.vala"
		_tmp1_ = clutter_actor_get_height ((ClutterActor*) self->priv->entry_background) != ((gint) ((child_box.y2 - child_box.y1) - 2));
#line 563 "panel-view.c"
	} else {
#line 190 "panel-view.vala"
		_tmp1_ = FALSE;
#line 567 "panel-view.c"
	}
#line 190 "panel-view.vala"
	if (_tmp1_) {
#line 192 "panel-view.vala"
		unity_places_cairo_drawing_entry_background_create_search_entry_background (self->priv->entry_background, (gint) (child_box.x2 - child_box.x1), (gint) ((child_box.y2 - child_box.y1) - 2));
#line 573 "panel-view.c"
	}
#line 194 "panel-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->entry_background, &child_box, flags);
#line 196 "panel-view.vala"
	child_box.x1 = child_box.x1 + ((float) 6);
#line 197 "panel-view.vala"
	child_box.x2 = child_box.x1 + 16;
#line 198 "panel-view.vala"
	child_box.y1 = floorf ((UNITY_PANEL_PANEL_HEIGHT - 16) / 2.0f);
#line 199 "panel-view.vala"
	child_box.y2 = child_box.y1 + 16;
#line 200 "panel-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->entry_icon, &child_box, flags);
#line 202 "panel-view.vala"
	child_box.x1 = child_box.x2 + 4;
#line 203 "panel-view.vala"
	child_box.x2 = (child_box.x1 + 150) - 16;
#line 204 "panel-view.vala"
	child_box.y1 = (float) 9;
#line 205 "panel-view.vala"
	child_box.y2 = (float) 15;
#line 206 "panel-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->entry, &child_box, flags);
#line 208 "panel-view.vala"
	child_box.y1 = (float) 0;
#line 209 "panel-view.vala"
	child_box.y2 = (float) UNITY_PANEL_PANEL_HEIGHT;
#line 212 "panel-view.vala"
	clutter_actor_get_preferred_width ((ClutterActor*) self->priv->indicators, (float) UNITY_PANEL_PANEL_HEIGHT, &child_width, &child_width);
#line 215 "panel-view.vala"
	child_box.x1 = width - child_width;
#line 216 "panel-view.vala"
	child_box.x2 = width;
#line 217 "panel-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->indicators, &child_box, flags);
#line 219 "panel-view.vala"
	width = width - (child_width + 12);
#line 222 "panel-view.vala"
	clutter_actor_get_preferred_width ((ClutterActor*) self->priv->tray, (float) UNITY_PANEL_PANEL_HEIGHT, &child_width, &child_width);
#line 225 "panel-view.vala"
	child_box.x1 = width - child_width;
#line 226 "panel-view.vala"
	child_box.x2 = width;
#line 227 "panel-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->tray, &child_box, flags);
#line 229 "panel-view.vala"
	width = width - (child_box.x2 - child_box.x1);
#line 230 "panel-view.vala"
	i_width = ((*box).x2 - (*box).x1) - width;
#line 231 "panel-view.vala"
	if (self->priv->indicators_width != ((gint) i_width)) {
#line 233 "panel-view.vala"
		self->priv->indicators_width = (gint) i_width;
#line 234 "panel-view.vala"
		g_signal_emit_by_name (self->priv->_shell, "indicators-changed", self->priv->indicators_width);
#line 629 "panel-view.c"
	}
}


#line 238 "panel-view.vala"
static void unity_panel_view_real_paint (ClutterActor* base) {
#line 636 "panel-view.c"
	UnityPanelView * self;
	self = (UnityPanelView*) base;
#line 240 "panel-view.vala"
	CLUTTER_ACTOR_CLASS (unity_panel_view_parent_class)->paint ((ClutterActor*) CTK_ACTOR (self));
#line 241 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->rect);
#line 242 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->tray);
#line 243 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->home);
#line 244 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->indicators);
#line 245 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->entry_background);
#line 246 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->entry_icon);
#line 247 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->entry);
#line 655 "panel-view.c"
}


#line 250 "panel-view.vala"
static void unity_panel_view_real_pick (ClutterActor* base, const ClutterColor* color) {
#line 661 "panel-view.c"
	UnityPanelView * self;
	self = (UnityPanelView*) base;
#line 252 "panel-view.vala"
	CLUTTER_ACTOR_CLASS (unity_panel_view_parent_class)->pick ((ClutterActor*) CTK_ACTOR (self), color);
#line 253 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->tray);
#line 254 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->home);
#line 255 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->indicators);
#line 256 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->entry_background);
#line 257 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->entry_icon);
#line 258 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->entry);
#line 678 "panel-view.c"
}


#line 261 "panel-view.vala"
static void unity_panel_view_real_map (ClutterActor* base) {
#line 684 "panel-view.c"
	UnityPanelView * self;
	self = (UnityPanelView*) base;
#line 263 "panel-view.vala"
	CLUTTER_ACTOR_CLASS (unity_panel_view_parent_class)->map ((ClutterActor*) CTK_ACTOR (self));
#line 264 "panel-view.vala"
	clutter_actor_map ((ClutterActor*) self->priv->rect);
#line 265 "panel-view.vala"
	clutter_actor_map ((ClutterActor*) self->priv->tray);
#line 266 "panel-view.vala"
	clutter_actor_map ((ClutterActor*) self->priv->home);
#line 267 "panel-view.vala"
	clutter_actor_map ((ClutterActor*) self->priv->indicators);
#line 268 "panel-view.vala"
	clutter_actor_map ((ClutterActor*) self->priv->entry_background);
#line 269 "panel-view.vala"
	clutter_actor_map ((ClutterActor*) self->priv->entry_icon);
#line 270 "panel-view.vala"
	clutter_actor_map ((ClutterActor*) self->priv->entry);
#line 703 "panel-view.c"
}


#line 273 "panel-view.vala"
static void unity_panel_view_real_unmap (ClutterActor* base) {
#line 709 "panel-view.c"
	UnityPanelView * self;
	self = (UnityPanelView*) base;
#line 275 "panel-view.vala"
	CLUTTER_ACTOR_CLASS (unity_panel_view_parent_class)->unmap ((ClutterActor*) CTK_ACTOR (self));
#line 276 "panel-view.vala"
	clutter_actor_unmap ((ClutterActor*) self->priv->rect);
#line 277 "panel-view.vala"
	clutter_actor_unmap ((ClutterActor*) self->priv->tray);
#line 278 "panel-view.vala"
	clutter_actor_unmap ((ClutterActor*) self->priv->home);
#line 279 "panel-view.vala"
	clutter_actor_unmap ((ClutterActor*) self->priv->indicators);
#line 280 "panel-view.vala"
	clutter_actor_unmap ((ClutterActor*) self->priv->entry_background);
#line 281 "panel-view.vala"
	clutter_actor_unmap ((ClutterActor*) self->priv->entry_icon);
#line 282 "panel-view.vala"
	clutter_actor_unmap ((ClutterActor*) self->priv->entry);
#line 728 "panel-view.c"
}


#line 285 "panel-view.vala"
gint unity_panel_view_get_indicators_width (UnityPanelView* self) {
#line 734 "panel-view.c"
	gint result;
#line 285 "panel-view.vala"
	g_return_val_if_fail (self != NULL, 0);
#line 738 "panel-view.c"
	result = (gint) self->priv->indicators_width;
#line 287 "panel-view.vala"
	return result;
#line 742 "panel-view.c"
}


#line 290 "panel-view.vala"
void unity_panel_view_set_indicator_mode (UnityPanelView* self, gboolean mode) {
#line 748 "panel-view.c"
	float x = 0.0F;
	float _tmp0_ = 0.0F;
	float _tmp1_ = 0.0F;
	gint _tmp2_ = 0;
#line 290 "panel-view.vala"
	g_return_if_fail (self != NULL);
#line 294 "panel-view.vala"
	if (mode) {
#line 294 "panel-view.vala"
		_tmp0_ = clutter_actor_get_width ((ClutterActor*) self) - unity_panel_view_get_indicators_width (self);
#line 759 "panel-view.c"
	} else {
#line 294 "panel-view.vala"
		_tmp0_ = (float) 0;
#line 763 "panel-view.c"
	}
#line 294 "panel-view.vala"
	x = _tmp0_;
#line 298 "panel-view.vala"
	if (mode) {
#line 298 "panel-view.vala"
		_tmp1_ = (float) unity_panel_view_get_indicators_width (self);
#line 771 "panel-view.c"
	} else {
#line 298 "panel-view.vala"
		_tmp1_ = clutter_actor_get_width ((ClutterActor*) self);
#line 775 "panel-view.c"
	}
#line 299 "panel-view.vala"
	if (mode) {
#line 299 "panel-view.vala"
		_tmp2_ = UNITY_PANEL_PANEL_HEIGHT - 1;
#line 781 "panel-view.c"
	} else {
#line 299 "panel-view.vala"
		_tmp2_ = UNITY_PANEL_PANEL_HEIGHT;
#line 785 "panel-view.c"
	}
#line 296 "panel-view.vala"
	clutter_actor_set_clip ((ClutterActor*) self->priv->rect, x, (float) 0, _tmp1_, (float) _tmp2_);
#line 789 "panel-view.c"
}


UnityShell* unity_panel_view_get_shell (UnityPanelView* self) {
	UnityShell* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_shell;
#line 30 "panel-view.vala"
	return result;
#line 799 "panel-view.c"
}


static void unity_panel_view_set_shell (UnityPanelView* self, UnityShell* value) {
	UnityShell* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_shell = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_shell), _tmp0_);
	g_object_notify ((GObject *) self, "shell");
}


#line 92 "panel-view.vala"
static void _unity_panel_view_on_home_clicked_unity_panel_home_button_clicked (UnityPanelHomeButton* _sender, guint32 time_, gpointer self) {
#line 813 "panel-view.c"
	unity_panel_view_on_home_clicked (self);
}


#line 127 "panel-view.vala"
static void _unity_panel_view_on_entry_activated_clutter_text_activate (ClutterText* _sender, gpointer self) {
#line 820 "panel-view.c"
	unity_panel_view_on_entry_activated (self);
}


#line 97 "panel-view.vala"
static void _unity_panel_view_on_entry_focus_in_clutter_actor_key_focus_in (ClutterActor* _sender, gpointer self) {
#line 827 "panel-view.c"
	unity_panel_view_on_entry_focus_in (self);
}


#line 102 "panel-view.vala"
static void _unity_panel_view_on_entry_focus_out_clutter_actor_key_focus_out (ClutterActor* _sender, gpointer self) {
#line 834 "panel-view.c"
	unity_panel_view_on_entry_focus_out (self);
}


static GObject * unity_panel_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPanelView * self;
	parent_class = G_OBJECT_CLASS (unity_panel_view_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PANEL_VIEW (obj);
	{
		UnityThemeImage* _tmp0_;
		UnityPanelIndicatorsView* _tmp1_;
		UnityPanelTrayView* _tmp2_;
		UnityPanelHomeButton* _tmp3_;
		UnityPlacesCairoDrawingEntryBackground* _tmp4_;
		UnityThemeImage* _tmp5_;
		UnityEntry* _tmp6_;
		char* _tmp7_;
		gboolean* _tmp9_;
		gboolean _tmp8_;
#line 51 "panel-view.vala"
		START_FUNCTION ();
#line 53 "panel-view.vala"
		self->priv->rect = (_tmp0_ = g_object_ref_sink (unity_theme_image_new ("panel_background")), _g_object_unref0 (self->priv->rect), _tmp0_);
#line 54 "panel-view.vala"
		clutter_texture_set_repeat ((ClutterTexture*) self->priv->rect, TRUE, FALSE);
#line 55 "panel-view.vala"
		clutter_actor_set_parent ((ClutterActor*) self->priv->rect, (ClutterActor*) self);
#line 56 "panel-view.vala"
		clutter_actor_show ((ClutterActor*) self->priv->rect);
#line 58 "panel-view.vala"
		self->priv->indicators = (_tmp1_ = g_object_ref_sink (unity_panel_indicators_view_new ()), _g_object_unref0 (self->priv->indicators), _tmp1_);
#line 59 "panel-view.vala"
		clutter_actor_set_parent ((ClutterActor*) self->priv->indicators, (ClutterActor*) self);
#line 60 "panel-view.vala"
		clutter_actor_show ((ClutterActor*) self->priv->indicators);
#line 62 "panel-view.vala"
		self->priv->tray = (_tmp2_ = g_object_ref_sink (unity_panel_tray_view_new ()), _g_object_unref0 (self->priv->tray), _tmp2_);
#line 63 "panel-view.vala"
		clutter_actor_set_parent ((ClutterActor*) self->priv->tray, (ClutterActor*) self);
#line 64 "panel-view.vala"
		clutter_actor_show ((ClutterActor*) self->priv->tray);
#line 66 "panel-view.vala"
		self->priv->home = (_tmp3_ = g_object_ref_sink (unity_panel_home_button_new (self->priv->_shell)), _g_object_unref0 (self->priv->home), _tmp3_);
#line 67 "panel-view.vala"
		clutter_actor_set_parent ((ClutterActor*) self->priv->home, (ClutterActor*) self);
#line 68 "panel-view.vala"
		clutter_actor_show ((ClutterActor*) self->priv->home);
#line 69 "panel-view.vala"
		g_signal_connect_object (self->priv->home, "clicked", (GCallback) _unity_panel_view_on_home_clicked_unity_panel_home_button_clicked, self, 0);
#line 71 "panel-view.vala"
		self->priv->entry_background = (_tmp4_ = g_object_ref_sink (unity_places_cairo_drawing_entry_background_new ()), _g_object_unref0 (self->priv->entry_background), _tmp4_);
#line 72 "panel-view.vala"
		clutter_actor_set_parent ((ClutterActor*) self->priv->entry_background, (ClutterActor*) self);
#line 73 "panel-view.vala"
		clutter_actor_show ((ClutterActor*) self->priv->entry_background);
#line 75 "panel-view.vala"
		self->priv->entry_icon = (_tmp5_ = g_object_ref_sink (unity_theme_image_new ("search_field")), _g_object_unref0 (self->priv->entry_icon), _tmp5_);
#line 76 "panel-view.vala"
		clutter_actor_set_parent ((ClutterActor*) self->priv->entry_icon, (ClutterActor*) self);
#line 77 "panel-view.vala"
		clutter_actor_show ((ClutterActor*) self->priv->entry_icon);
#line 79 "panel-view.vala"
		self->priv->entry = (_tmp6_ = g_object_ref_sink (unity_entry_new ("")), _g_object_unref0 (self->priv->entry), _tmp6_);
#line 80 "panel-view.vala"
		unity_entry_set_static_text (self->priv->entry, _tmp7_ = unity_panel_view_get_search_hint (self));
#line 903 "panel-view.c"
		_g_free0 (_tmp7_);
#line 81 "panel-view.vala"
		clutter_actor_set_parent ((ClutterActor*) self->priv->entry, (ClutterActor*) self);
#line 82 "panel-view.vala"
		clutter_actor_show ((ClutterActor*) self->priv->entry);
#line 83 "panel-view.vala"
		g_signal_connect_object ((ClutterText*) self->priv->entry, "activate", (GCallback) _unity_panel_view_on_entry_activated_clutter_text_activate, self, 0);
#line 85 "panel-view.vala"
		g_signal_connect_object ((ClutterActor*) self->priv->entry, "key-focus-in", (GCallback) _unity_panel_view_on_entry_focus_in_clutter_actor_key_focus_in, self, 0);
#line 86 "panel-view.vala"
		g_signal_connect_object ((ClutterActor*) self->priv->entry, "key-focus-out", (GCallback) _unity_panel_view_on_entry_focus_out_clutter_actor_key_focus_out, self, 0);
#line 87 "panel-view.vala"
		unity_panel_search_entry_has_focus = (_tmp9_ = __bool_dup0 ((_tmp8_ = FALSE, &_tmp8_)), _g_free0 (unity_panel_search_entry_has_focus), _tmp9_);
#line 89 "panel-view.vala"
		END_FUNCTION ();
#line 919 "panel-view.c"
	}
	return obj;
}


static void unity_panel_view_class_init (UnityPanelViewClass * klass) {
	unity_panel_view_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPanelViewPrivate));
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_panel_view_real_allocate;
	CLUTTER_ACTOR_CLASS (klass)->paint = unity_panel_view_real_paint;
	CLUTTER_ACTOR_CLASS (klass)->pick = unity_panel_view_real_pick;
	CLUTTER_ACTOR_CLASS (klass)->map = unity_panel_view_real_map;
	CLUTTER_ACTOR_CLASS (klass)->unmap = unity_panel_view_real_unmap;
	G_OBJECT_CLASS (klass)->get_property = unity_panel_view_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_panel_view_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_panel_view_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_panel_view_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PANEL_VIEW_SHELL, g_param_spec_object ("shell", "shell", "shell", UNITY_TYPE_SHELL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_panel_view_instance_init (UnityPanelView * self) {
	self->priv = UNITY_PANEL_VIEW_GET_PRIVATE (self);
	self->priv->indicators_width = 0;
}


static void unity_panel_view_finalize (GObject* obj) {
	UnityPanelView * self;
	self = UNITY_PANEL_VIEW (obj);
	_g_object_unref0 (self->priv->_shell);
	_g_object_unref0 (self->priv->rect);
	_g_object_unref0 (self->priv->tray);
	_g_object_unref0 (self->priv->home);
	_g_object_unref0 (self->priv->indicators);
	_g_object_unref0 (self->priv->entry_icon);
	_g_object_unref0 (self->priv->entry);
	_g_object_unref0 (self->priv->entry_background);
	G_OBJECT_CLASS (unity_panel_view_parent_class)->finalize (obj);
}


GType unity_panel_view_get_type (void) {
	static GType unity_panel_view_type_id = 0;
	if (unity_panel_view_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPanelViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_panel_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPanelView), 0, (GInstanceInitFunc) unity_panel_view_instance_init, NULL };
		unity_panel_view_type_id = g_type_register_static (CTK_TYPE_ACTOR, "UnityPanelView", &g_define_type_info, 0);
	}
	return unity_panel_view_type_id;
}


static void unity_panel_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPanelView * self;
	self = UNITY_PANEL_VIEW (object);
	switch (property_id) {
		case UNITY_PANEL_VIEW_SHELL:
		g_value_set_object (value, unity_panel_view_get_shell (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_panel_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPanelView * self;
	self = UNITY_PANEL_VIEW (object);
	switch (property_id) {
		case UNITY_PANEL_VIEW_SHELL:
		unity_panel_view_set_shell (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
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




