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
#include <clutk/clutk.h>
#include <unity.h>
#include <clutter/clutter.h>
#include <float.h>
#include <math.h>
#include <unity-utils.h>
#include <stdlib.h>
#include <string.h>


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
typedef struct _UnityPlacesCairoDrawingEntryBackgroundPrivate UnityPlacesCairoDrawingEntryBackgroundPrivate;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _UnityPanelView {
	CtkActor parent_instance;
	UnityPanelViewPrivate * priv;
};

struct _UnityPanelViewClass {
	CtkActorClass parent_class;
};

struct _UnityPanelViewPrivate {
	UnityShell* _shell;
	ClutterRectangle* rect;
	UnityPanelTrayView* tray;
	UnityPanelHomeButton* home;
	UnityPanelIndicatorsView* indicators;
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


static gpointer unity_panel_view_parent_class = NULL;

#define UNITY_PANEL_PANEL_HEIGHT 24
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
UnityPlacesCairoDrawingEntryBackground* unity_places_cairo_drawing_entry_background_new (void);
UnityPlacesCairoDrawingEntryBackground* unity_places_cairo_drawing_entry_background_construct (GType object_type);
static void _lambda3_ (UnityPanelView* self);
static void __lambda3__clutter_text_activate (ClutterText* _sender, gpointer self);
static GObject * unity_panel_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_panel_view_finalize (GObject* obj);
static void unity_panel_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_panel_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



#line 39 "panel-view.vala"
UnityPanelView* unity_panel_view_construct (GType object_type, UnityShell* shell) {
#line 170 "panel-view.c"
	UnityPanelView * self;
	ClutterStage* _tmp0_;
#line 39 "panel-view.vala"
	g_return_val_if_fail (shell != NULL, NULL);
#line 41 "panel-view.vala"
	self = (UnityPanelView*) g_object_new (object_type, "shell", shell, NULL);
#line 42 "panel-view.vala"
	unity_panel_tray_view_manage_stage (self->priv->tray, _tmp0_ = unity_shell_get_stage (self->priv->_shell));
#line 179 "panel-view.c"
	_g_object_unref0 (_tmp0_);
	return self;
}


#line 39 "panel-view.vala"
UnityPanelView* unity_panel_view_new (UnityShell* shell) {
#line 39 "panel-view.vala"
	return unity_panel_view_construct (UNITY_PANEL_TYPE_VIEW, shell);
#line 189 "panel-view.c"
}


#line 93 "panel-view.vala"
static void unity_panel_view_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
#line 195 "panel-view.c"
	UnityPanelView * self;
	ClutterActorBox _tmp0_ = {0};
	ClutterActorBox child_box;
	float width = 0.0F;
	float child_width = 0.0F;
	float i_width = 0.0F;
	gboolean _tmp1_ = FALSE;
	self = (UnityPanelView*) base;
#line 96 "panel-view.vala"
	child_box = (_tmp0_.x1 = (float) 0, _tmp0_.y1 = (float) 0, _tmp0_.x2 = (*box).x2 - (*box).x1, _tmp0_.y2 = (*box).y2 - (*box).y1, _tmp0_);
#line 101 "panel-view.vala"
	width = (*box).x2 - (*box).x1;
#line 104 "panel-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->rect, &child_box, flags);
#line 107 "panel-view.vala"
	child_box.x1 = (float) 17;
#line 108 "panel-view.vala"
	child_box.x2 = child_box.x1 + UNITY_PANEL_PANEL_HEIGHT;
#line 109 "panel-view.vala"
	child_box.y1 = (float) 0;
#line 110 "panel-view.vala"
	child_box.y2 = (float) UNITY_PANEL_PANEL_HEIGHT;
#line 111 "panel-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->home, &child_box, flags);
#line 114 "panel-view.vala"
	child_box.x1 = child_box.x2 + 56;
#line 115 "panel-view.vala"
	child_box.x2 = child_box.x1 + 150;
#line 117 "panel-view.vala"
	if (self->priv->entry_background->Width != ((gint) (child_box.x2 - child_box.x1))) {
#line 117 "panel-view.vala"
		_tmp1_ = clutter_actor_get_height ((ClutterActor*) self->priv->entry_background) != ((gint) (child_box.y2 - child_box.y1));
#line 228 "panel-view.c"
	} else {
#line 117 "panel-view.vala"
		_tmp1_ = FALSE;
#line 232 "panel-view.c"
	}
#line 117 "panel-view.vala"
	if (_tmp1_) {
#line 119 "panel-view.vala"
		unity_places_cairo_drawing_entry_background_create_search_entry_background (self->priv->entry_background, (gint) (child_box.x2 - child_box.x1), (gint) (child_box.y2 - child_box.y1));
#line 238 "panel-view.c"
	}
#line 121 "panel-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->entry_background, &child_box, flags);
#line 123 "panel-view.vala"
	child_box.x1 = child_box.x1 + ((float) 12);
#line 124 "panel-view.vala"
	child_box.x2 = child_box.x2 - ((float) 12);
#line 125 "panel-view.vala"
	child_box.y1 = child_box.y1 + ((float) 4);
#line 126 "panel-view.vala"
	child_box.y2 = child_box.y2 - ((float) 4);
#line 127 "panel-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->entry, &child_box, flags);
#line 129 "panel-view.vala"
	child_box.y1 = (float) 0;
#line 130 "panel-view.vala"
	child_box.y2 = (float) UNITY_PANEL_PANEL_HEIGHT;
#line 133 "panel-view.vala"
	clutter_actor_get_preferred_width ((ClutterActor*) self->priv->indicators, (float) UNITY_PANEL_PANEL_HEIGHT, &child_width, &child_width);
#line 136 "panel-view.vala"
	child_box.x1 = width - child_width;
#line 137 "panel-view.vala"
	child_box.x2 = width;
#line 138 "panel-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->indicators, &child_box, flags);
#line 140 "panel-view.vala"
	width = width - (child_width + 12);
#line 143 "panel-view.vala"
	clutter_actor_get_preferred_width ((ClutterActor*) self->priv->tray, (float) UNITY_PANEL_PANEL_HEIGHT, &child_width, &child_width);
#line 146 "panel-view.vala"
	child_box.x1 = width - child_width;
#line 147 "panel-view.vala"
	child_box.x2 = width;
#line 148 "panel-view.vala"
	clutter_actor_allocate ((ClutterActor*) self->priv->tray, &child_box, flags);
#line 150 "panel-view.vala"
	width = width - (child_box.x2 - child_box.x1);
#line 151 "panel-view.vala"
	i_width = ((*box).x2 - (*box).x1) - width;
#line 152 "panel-view.vala"
	if (self->priv->indicators_width != ((gint) i_width)) {
#line 154 "panel-view.vala"
		self->priv->indicators_width = (gint) i_width;
#line 155 "panel-view.vala"
		g_signal_emit_by_name (self->priv->_shell, "indicators-changed", self->priv->indicators_width);
#line 284 "panel-view.c"
	}
}


#line 159 "panel-view.vala"
static void unity_panel_view_real_paint (ClutterActor* base) {
#line 291 "panel-view.c"
	UnityPanelView * self;
	self = (UnityPanelView*) base;
#line 161 "panel-view.vala"
	CLUTTER_ACTOR_CLASS (unity_panel_view_parent_class)->paint ((ClutterActor*) CTK_ACTOR (self));
#line 162 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->rect);
#line 163 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->tray);
#line 164 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->home);
#line 165 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->indicators);
#line 166 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->entry_background);
#line 167 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->entry);
#line 308 "panel-view.c"
}


#line 170 "panel-view.vala"
static void unity_panel_view_real_pick (ClutterActor* base, const ClutterColor* color) {
#line 314 "panel-view.c"
	UnityPanelView * self;
	self = (UnityPanelView*) base;
#line 172 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->tray);
#line 173 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->home);
#line 174 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->indicators);
#line 175 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->entry_background);
#line 176 "panel-view.vala"
	clutter_actor_paint ((ClutterActor*) self->priv->entry);
#line 327 "panel-view.c"
}


#line 179 "panel-view.vala"
static void unity_panel_view_real_map (ClutterActor* base) {
#line 333 "panel-view.c"
	UnityPanelView * self;
	self = (UnityPanelView*) base;
#line 181 "panel-view.vala"
	CLUTTER_ACTOR_CLASS (unity_panel_view_parent_class)->map ((ClutterActor*) CTK_ACTOR (self));
#line 182 "panel-view.vala"
	clutter_actor_map ((ClutterActor*) self->priv->rect);
#line 183 "panel-view.vala"
	clutter_actor_map ((ClutterActor*) self->priv->tray);
#line 184 "panel-view.vala"
	clutter_actor_map ((ClutterActor*) self->priv->home);
#line 185 "panel-view.vala"
	clutter_actor_map ((ClutterActor*) self->priv->indicators);
#line 186 "panel-view.vala"
	clutter_actor_map ((ClutterActor*) self->priv->entry_background);
#line 187 "panel-view.vala"
	clutter_actor_map ((ClutterActor*) self->priv->entry);
#line 350 "panel-view.c"
}


#line 190 "panel-view.vala"
static void unity_panel_view_real_unmap (ClutterActor* base) {
#line 356 "panel-view.c"
	UnityPanelView * self;
	self = (UnityPanelView*) base;
#line 192 "panel-view.vala"
	CLUTTER_ACTOR_CLASS (unity_panel_view_parent_class)->unmap ((ClutterActor*) CTK_ACTOR (self));
#line 193 "panel-view.vala"
	clutter_actor_unmap ((ClutterActor*) self->priv->rect);
#line 194 "panel-view.vala"
	clutter_actor_unmap ((ClutterActor*) self->priv->tray);
#line 195 "panel-view.vala"
	clutter_actor_unmap ((ClutterActor*) self->priv->home);
#line 196 "panel-view.vala"
	clutter_actor_unmap ((ClutterActor*) self->priv->indicators);
#line 197 "panel-view.vala"
	clutter_actor_unmap ((ClutterActor*) self->priv->entry_background);
#line 198 "panel-view.vala"
	clutter_actor_unmap ((ClutterActor*) self->priv->entry);
#line 373 "panel-view.c"
}


#line 201 "panel-view.vala"
gint unity_panel_view_get_indicators_width (UnityPanelView* self) {
#line 379 "panel-view.c"
	gint result;
#line 201 "panel-view.vala"
	g_return_val_if_fail (self != NULL, 0);
#line 383 "panel-view.c"
	result = (gint) self->priv->indicators_width;
#line 203 "panel-view.vala"
	return result;
#line 387 "panel-view.c"
}


#line 206 "panel-view.vala"
void unity_panel_view_set_indicator_mode (UnityPanelView* self, gboolean mode) {
#line 393 "panel-view.c"
	float x = 0.0F;
	float _tmp0_ = 0.0F;
	float _tmp1_ = 0.0F;
	gint _tmp2_ = 0;
#line 206 "panel-view.vala"
	g_return_if_fail (self != NULL);
#line 210 "panel-view.vala"
	if (mode) {
#line 210 "panel-view.vala"
		_tmp0_ = clutter_actor_get_width ((ClutterActor*) self) - unity_panel_view_get_indicators_width (self);
#line 404 "panel-view.c"
	} else {
#line 210 "panel-view.vala"
		_tmp0_ = (float) 0;
#line 408 "panel-view.c"
	}
#line 210 "panel-view.vala"
	x = _tmp0_;
#line 214 "panel-view.vala"
	if (mode) {
#line 214 "panel-view.vala"
		_tmp1_ = (float) unity_panel_view_get_indicators_width (self);
#line 416 "panel-view.c"
	} else {
#line 214 "panel-view.vala"
		_tmp1_ = clutter_actor_get_width ((ClutterActor*) self);
#line 420 "panel-view.c"
	}
#line 215 "panel-view.vala"
	if (mode) {
#line 215 "panel-view.vala"
		_tmp2_ = UNITY_PANEL_PANEL_HEIGHT - 1;
#line 426 "panel-view.c"
	} else {
#line 215 "panel-view.vala"
		_tmp2_ = UNITY_PANEL_PANEL_HEIGHT;
#line 430 "panel-view.c"
	}
#line 212 "panel-view.vala"
	clutter_actor_set_clip ((ClutterActor*) self->priv->rect, x, (float) 0, _tmp1_, (float) _tmp2_);
#line 434 "panel-view.c"
}


UnityShell* unity_panel_view_get_shell (UnityPanelView* self) {
	UnityShell* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_shell;
#line 27 "panel-view.vala"
	return result;
#line 444 "panel-view.c"
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_panel_view_set_shell (UnityPanelView* self, UnityShell* value) {
	UnityShell* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_shell = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_shell), _tmp0_);
	g_object_notify ((GObject *) self, "shell");
}


static void _lambda3_ (UnityPanelView* self) {
	GError * _inner_error_;
	char* text;
	char* command;
	_inner_error_ = NULL;
#line 76 "panel-view.vala"
	text = g_uri_escape_string (clutter_text_get_text ((ClutterText*) self->priv->entry), "", TRUE);
#line 78 "panel-view.vala"
	command = g_strdup_printf ("xdg-open http://www.google.com/search?ie=UTF-8&q=%s", text);
#line 470 "panel-view.c"
	{
#line 82 "panel-view.vala"
		g_spawn_command_line_async (command, &_inner_error_);
#line 474 "panel-view.c"
		if (_inner_error_ != NULL) {
			goto __catch7_g_error;
			goto __finally7;
		}
	}
	goto __finally7;
	__catch7_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 86 "panel-view.vala"
			g_warning ("panel-view.vala:86: Unable to search for '$text': %s", e->message);
#line 489 "panel-view.c"
			_g_error_free0 (e);
		}
	}
	__finally7:
	if (_inner_error_ != NULL) {
		_g_free0 (text);
		_g_free0 (command);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_free0 (text);
	_g_free0 (command);
}


static void __lambda3__clutter_text_activate (ClutterText* _sender, gpointer self) {
	_lambda3_ (self);
}


static GObject * unity_panel_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPanelView * self;
	parent_class = G_OBJECT_CLASS (unity_panel_view_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PANEL_VIEW (obj);
	{
		ClutterColor _tmp0_ = {0};
		ClutterColor color;
		ClutterRectangle* _tmp1_;
		UnityPanelIndicatorsView* _tmp2_;
		UnityPanelTrayView* _tmp3_;
		UnityPanelHomeButton* _tmp4_;
		UnityPlacesCairoDrawingEntryBackground* _tmp5_;
		UnityEntry* _tmp6_;
#line 47 "panel-view.vala"
		START_FUNCTION ();
#line 49 "panel-view.vala"
		color = (_tmp0_.red = (guint8) 25, _tmp0_.green = (guint8) 25, _tmp0_.blue = (guint8) 25, _tmp0_.alpha = (guint8) 255, _tmp0_);
#line 51 "panel-view.vala"
		self->priv->rect = (_tmp1_ = g_object_ref_sink ((ClutterRectangle*) clutter_rectangle_new_with_color (&color)), _g_object_unref0 (self->priv->rect), _tmp1_);
#line 52 "panel-view.vala"
		clutter_actor_set_parent ((ClutterActor*) self->priv->rect, (ClutterActor*) self);
#line 53 "panel-view.vala"
		clutter_actor_show ((ClutterActor*) self->priv->rect);
#line 55 "panel-view.vala"
		self->priv->indicators = (_tmp2_ = g_object_ref_sink (unity_panel_indicators_view_new ()), _g_object_unref0 (self->priv->indicators), _tmp2_);
#line 56 "panel-view.vala"
		clutter_actor_set_parent ((ClutterActor*) self->priv->indicators, (ClutterActor*) self);
#line 57 "panel-view.vala"
		clutter_actor_show ((ClutterActor*) self->priv->indicators);
#line 59 "panel-view.vala"
		self->priv->tray = (_tmp3_ = g_object_ref_sink (unity_panel_tray_view_new ()), _g_object_unref0 (self->priv->tray), _tmp3_);
#line 60 "panel-view.vala"
		clutter_actor_set_parent ((ClutterActor*) self->priv->tray, (ClutterActor*) self);
#line 61 "panel-view.vala"
		clutter_actor_show ((ClutterActor*) self->priv->tray);
#line 63 "panel-view.vala"
		self->priv->home = (_tmp4_ = g_object_ref_sink (unity_panel_home_button_new (self->priv->_shell)), _g_object_unref0 (self->priv->home), _tmp4_);
#line 64 "panel-view.vala"
		clutter_actor_set_parent ((ClutterActor*) self->priv->home, (ClutterActor*) self);
#line 65 "panel-view.vala"
		clutter_actor_show ((ClutterActor*) self->priv->home);
#line 67 "panel-view.vala"
		self->priv->entry_background = (_tmp5_ = g_object_ref_sink (unity_places_cairo_drawing_entry_background_new ()), _g_object_unref0 (self->priv->entry_background), _tmp5_);
#line 68 "panel-view.vala"
		clutter_actor_set_parent ((ClutterActor*) self->priv->entry_background, (ClutterActor*) self);
#line 69 "panel-view.vala"
		clutter_actor_show ((ClutterActor*) self->priv->entry_background);
#line 71 "panel-view.vala"
		self->priv->entry = (_tmp6_ = g_object_ref_sink (unity_entry_new ("Search")), _g_object_unref0 (self->priv->entry), _tmp6_);
#line 72 "panel-view.vala"
		clutter_actor_set_parent ((ClutterActor*) self->priv->entry, (ClutterActor*) self);
#line 73 "panel-view.vala"
		clutter_actor_show ((ClutterActor*) self->priv->entry);
#line 74 "panel-view.vala"
		g_signal_connect_object ((ClutterText*) self->priv->entry, "activate", (GCallback) __lambda3__clutter_text_activate, self, 0);
#line 90 "panel-view.vala"
		END_FUNCTION ();
#line 571 "panel-view.c"
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




