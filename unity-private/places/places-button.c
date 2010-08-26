/* places-button.c generated by valac 0.9.7, the Vala compiler
 * generated from places-button.vala, do not modify */

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
#include <cairo.h>
#include <unity.h>
#include <float.h>
#include <math.h>
#include <clutter/clutter.h>


#define UNITY_PLACES_TYPE_BUTTON (unity_places_button_get_type ())
#define UNITY_PLACES_BUTTON(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_BUTTON, UnityPlacesButton))
#define UNITY_PLACES_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_BUTTON, UnityPlacesButtonClass))
#define UNITY_PLACES_IS_BUTTON(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_BUTTON))
#define UNITY_PLACES_IS_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_BUTTON))
#define UNITY_PLACES_BUTTON_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_BUTTON, UnityPlacesButtonClass))

typedef struct _UnityPlacesButton UnityPlacesButton;
typedef struct _UnityPlacesButtonClass UnityPlacesButtonClass;
typedef struct _UnityPlacesButtonPrivate UnityPlacesButtonPrivate;

#define UNITY_PLACES_BUTTON_TYPE_NORMAL_STATE (unity_places_button_normal_state_get_type ())

#define UNITY_PLACES_BUTTON_TYPE_PRELIGHT_STATE (unity_places_button_prelight_state_get_type ())
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _cairo_pattern_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_pattern_destroy (var), NULL)))
#define _cairo_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_destroy (var), NULL)))
#define _cairo_surface_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_surface_destroy (var), NULL)))

typedef void (*UnityPlacesButtonButtonOutlineFunc) (cairo_t* cr, gint width, gint height, void* user_data);
struct _UnityPlacesButton {
	CtkButton parent_instance;
	UnityPlacesButtonPrivate * priv;
	UnityPlacesButtonButtonOutlineFunc outline_func;
	gpointer outline_func_target;
	GDestroyNotify outline_func_target_destroy_notify;
};

struct _UnityPlacesButtonClass {
	CtkButtonClass parent_class;
};

typedef enum  {
	UNITY_PLACES_BUTTON_NORMAL_STATE_NONE,
	UNITY_PLACES_BUTTON_NORMAL_STATE_UNDERLINE
} UnityPlacesButtonNormalState;

typedef enum  {
	UNITY_PLACES_BUTTON_PRELIGHT_STATE_NONE,
	UNITY_PLACES_BUTTON_PRELIGHT_STATE_STRIPED,
	UNITY_PLACES_BUTTON_PRELIGHT_STATE_UNDERLINE
} UnityPlacesButtonPrelightState;

struct _UnityPlacesButtonPrivate {
	UnityPlacesButtonNormalState _normal_state;
	UnityPlacesButtonPrelightState _prelight_state;
	UnityCairoCanvas* bg;
	CtkEffectGlow* glow;
};


static gpointer unity_places_button_parent_class = NULL;

GType unity_places_button_get_type (void) G_GNUC_CONST;
GType unity_places_button_normal_state_get_type (void) G_GNUC_CONST;
GType unity_places_button_prelight_state_get_type (void) G_GNUC_CONST;
#define UNITY_PLACES_BUTTON_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_BUTTON, UnityPlacesButtonPrivate))
enum  {
	UNITY_PLACES_BUTTON_DUMMY_PROPERTY,
	UNITY_PLACES_BUTTON_NORMAL_STATE,
	UNITY_PLACES_BUTTON_PRELIGHT_STATE
};
UnityPlacesButton* unity_places_button_new (void);
UnityPlacesButton* unity_places_button_construct (GType object_type);
void unity_places_button_rounded_rect (UnityPlacesButton* self, cairo_t* cr, gint width, gint height);
static void unity_places_button_paint_bg (UnityPlacesButton* self, cairo_t* cr, gint width, gint height);
UnityPlacesButtonNormalState unity_places_button_get_normal_state (UnityPlacesButton* self);
void unity_places_button_set_normal_state (UnityPlacesButton* self, UnityPlacesButtonNormalState value);
UnityPlacesButtonPrelightState unity_places_button_get_prelight_state (UnityPlacesButton* self);
void unity_places_button_set_prelight_state (UnityPlacesButton* self, UnityPlacesButtonPrelightState value);
static void _unity_places_button_paint_bg_unity_cairo_canvas_cairo_canvas_paint (cairo_t* cr, gint width, gint height, gpointer self);
static void _lambda16_ (UnityPlacesButton* self);
static void __lambda16__g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self);
static void _unity_places_button_rounded_rect_unity_places_button_button_outline_func (cairo_t* cr, gint width, gint height, gpointer self);
static GObject * unity_places_button_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_button_finalize (GObject* obj);
static void unity_places_button_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_button_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



GType unity_places_button_normal_state_get_type (void) {
	static volatile gsize unity_places_button_normal_state_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_button_normal_state_type_id__volatile)) {
		static const GEnumValue values[] = {{UNITY_PLACES_BUTTON_NORMAL_STATE_NONE, "UNITY_PLACES_BUTTON_NORMAL_STATE_NONE", "none"}, {UNITY_PLACES_BUTTON_NORMAL_STATE_UNDERLINE, "UNITY_PLACES_BUTTON_NORMAL_STATE_UNDERLINE", "underline"}, {0, NULL, NULL}};
		GType unity_places_button_normal_state_type_id;
		unity_places_button_normal_state_type_id = g_enum_register_static ("UnityPlacesButtonNormalState", values);
		g_once_init_leave (&unity_places_button_normal_state_type_id__volatile, unity_places_button_normal_state_type_id);
	}
	return unity_places_button_normal_state_type_id__volatile;
}


GType unity_places_button_prelight_state_get_type (void) {
	static volatile gsize unity_places_button_prelight_state_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_button_prelight_state_type_id__volatile)) {
		static const GEnumValue values[] = {{UNITY_PLACES_BUTTON_PRELIGHT_STATE_NONE, "UNITY_PLACES_BUTTON_PRELIGHT_STATE_NONE", "none"}, {UNITY_PLACES_BUTTON_PRELIGHT_STATE_STRIPED, "UNITY_PLACES_BUTTON_PRELIGHT_STATE_STRIPED", "striped"}, {UNITY_PLACES_BUTTON_PRELIGHT_STATE_UNDERLINE, "UNITY_PLACES_BUTTON_PRELIGHT_STATE_UNDERLINE", "underline"}, {0, NULL, NULL}};
		GType unity_places_button_prelight_state_type_id;
		unity_places_button_prelight_state_type_id = g_enum_register_static ("UnityPlacesButtonPrelightState", values);
		g_once_init_leave (&unity_places_button_prelight_state_type_id__volatile, unity_places_button_prelight_state_type_id);
	}
	return unity_places_button_prelight_state_type_id__volatile;
}


UnityPlacesButton* unity_places_button_construct (GType object_type) {
	UnityPlacesButton * self;
	self = (UnityPlacesButton*) g_object_new (object_type, NULL);
	return self;
}


UnityPlacesButton* unity_places_button_new (void) {
	return unity_places_button_construct (UNITY_PLACES_TYPE_BUTTON);
}


void unity_places_button_rounded_rect (UnityPlacesButton* self, cairo_t* cr, gint width, gint height) {
	gint padding;
	gint x;
	gint y;
	gint radius;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cr != NULL);
	padding = 1;
	x = padding;
	y = padding;
	radius = 7;
	width = width - (padding * 2);
	height = height - (padding * 2);
	cairo_move_to (cr, (double) x, (double) (y + radius));
	cairo_curve_to (cr, (double) x, (double) y, (double) x, (double) y, (double) (x + radius), (double) y);
	cairo_line_to (cr, (double) (width - radius), (double) y);
	cairo_curve_to (cr, (double) width, (double) y, (double) width, (double) y, (double) width, (double) (y + radius));
	cairo_line_to (cr, (double) width, (double) (height - radius));
	cairo_curve_to (cr, (double) width, (double) height, (double) width, (double) height, (double) (width - radius), (double) height);
	cairo_line_to (cr, (double) (x + radius), (double) height);
	cairo_curve_to (cr, (double) x, (double) height, (double) x, (double) height, (double) x, (double) (height - radius));
	cairo_close_path (cr);
}


static void unity_places_button_paint_bg (UnityPlacesButton* self, cairo_t* cr, gint width, gint height) {
	gint x;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cr != NULL);
	x = 1;
	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	cairo_paint (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
	cairo_set_line_width (cr, 1.5);
	cairo_translate (cr, 0.5, 0.5);
	if (ctk_actor_get_state ((CtkActor*) self) == CTK_STATE_NORMAL) {
		if (self->priv->_normal_state == UNITY_PLACES_BUTTON_NORMAL_STATE_UNDERLINE) {
			cairo_move_to (cr, (double) x, (double) (height - 1));
			cairo_line_to (cr, (double) (x + width), (double) (height - 1));
			cairo_set_source_rgba (cr, 1.0, 1.0, 1.0, 0.3);
			cairo_stroke (cr);
		}
		return;
	} else {
		gboolean _tmp0_ = FALSE;
		if (ctk_actor_get_state ((CtkActor*) self) == CTK_STATE_PRELIGHT) {
			_tmp0_ = self->priv->_prelight_state == UNITY_PLACES_BUTTON_PRELIGHT_STATE_UNDERLINE;
		} else {
			_tmp0_ = FALSE;
		}
		if (_tmp0_) {
			cairo_move_to (cr, (double) x, (double) (height - 1));
			cairo_line_to (cr, (double) (x + width), (double) (height - 1));
			cairo_set_source_rgba (cr, 1.0, 1.0, 1.0, 0.3);
			cairo_stroke (cr);
			return;
		}
	}
	self->outline_func (cr, width, height, self->outline_func_target);
	if (ctk_actor_get_state ((CtkActor*) self) == CTK_STATE_NORMAL) {
		cairo_set_source_rgba (cr, 1.0, 1.0, 1.0, 0.0);
	} else {
		if (ctk_actor_get_state ((CtkActor*) self) == CTK_STATE_PRELIGHT) {
			cairo_surface_t* pattern;
			cairo_t* context;
			cairo_pattern_t* pat;
			pattern = cairo_surface_create_similar (cairo_get_target (cr), CAIRO_CONTENT_COLOR_ALPHA, 4, 4);
			context = cairo_create (pattern);
			cairo_set_operator (context, CAIRO_OPERATOR_CLEAR);
			cairo_paint (context);
			cairo_set_line_width (context, 0.2);
			cairo_set_operator (context, CAIRO_OPERATOR_OVER);
			cairo_set_source_rgba (context, 1.0, 1.0, 1.0, 0.85);
			cairo_move_to (context, (double) 0, (double) 0);
			cairo_line_to (context, (double) 4, (double) 4);
			cairo_stroke (context);
			pat = cairo_pattern_create_for_surface (pattern);
			cairo_pattern_set_extend (pat, CAIRO_EXTEND_REPEAT);
			cairo_set_source (cr, pat);
			_cairo_pattern_destroy0 (pat);
			_cairo_destroy0 (context);
			_cairo_surface_destroy0 (pattern);
		} else {
			cairo_set_source_rgba (cr, 1.0, 1.0, 1.0, 1.0);
		}
	}
	cairo_fill_preserve (cr);
	cairo_set_source_rgba (cr, 1.0, 1.0, 1.0, 0.5);
	cairo_stroke (cr);
}


UnityPlacesButtonNormalState unity_places_button_get_normal_state (UnityPlacesButton* self) {
	UnityPlacesButtonNormalState result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->priv->_normal_state;
	return result;
}


void unity_places_button_set_normal_state (UnityPlacesButton* self, UnityPlacesButtonNormalState value) {
	g_return_if_fail (self != NULL);
	if (self->priv->_normal_state != value) {
		self->priv->_normal_state = value;
		unity_cairo_canvas_update (self->priv->bg);
	}
	g_object_notify ((GObject *) self, "normal-state");
}


UnityPlacesButtonPrelightState unity_places_button_get_prelight_state (UnityPlacesButton* self) {
	UnityPlacesButtonPrelightState result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->priv->_prelight_state;
	return result;
}


void unity_places_button_set_prelight_state (UnityPlacesButton* self, UnityPlacesButtonPrelightState value) {
	g_return_if_fail (self != NULL);
	if (self->priv->_prelight_state != value) {
		self->priv->_prelight_state = value;
		unity_cairo_canvas_update (self->priv->bg);
	}
	g_object_notify ((GObject *) self, "prelight-state");
}


static void _unity_places_button_paint_bg_unity_cairo_canvas_cairo_canvas_paint (cairo_t* cr, gint width, gint height, gpointer self) {
	unity_places_button_paint_bg (self, cr, width, height);
}


static void _lambda16_ (UnityPlacesButton* self) {
	unity_cairo_canvas_update (self->priv->bg);
	if (CTK_IS_TEXT (ctk_button_get_text ((CtkButton*) self))) {
		gboolean _tmp0_ = FALSE;
		if (ctk_actor_get_state ((CtkActor*) self) == CTK_STATE_NORMAL) {
			_tmp0_ = TRUE;
		} else {
			_tmp0_ = ctk_actor_get_state ((CtkActor*) self) == CTK_STATE_PRELIGHT;
		}
		if (_tmp0_) {
			ClutterColor _tmp1_ = {0};
			ClutterColor _tmp2_;
			clutter_text_set_color ((ClutterText*) ctk_button_get_text ((CtkButton*) self), (_tmp2_ = (_tmp1_.red = (guint8) 255, _tmp1_.green = (guint8) 255, _tmp1_.blue = (guint8) 255, _tmp1_.alpha = (guint8) 255, _tmp1_), &_tmp2_));
		} else {
			ClutterColor _tmp3_ = {0};
			ClutterColor _tmp4_;
			clutter_text_set_color ((ClutterText*) ctk_button_get_text ((CtkButton*) self), (_tmp4_ = (_tmp3_.red = (guint8) 50, _tmp3_.green = (guint8) 50, _tmp3_.blue = (guint8) 50, _tmp3_.alpha = (guint8) 200, _tmp3_), &_tmp4_));
		}
	}
	if (CTK_IS_EFFECT_GLOW (self->priv->glow)) {
		ctk_effect_set_invalidate_effect_cache ((CtkEffect*) self->priv->glow, TRUE);
	}
}


static void __lambda16__g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self) {
	_lambda16_ (self);
}


static void _unity_places_button_rounded_rect_unity_places_button_button_outline_func (cairo_t* cr, gint width, gint height, gpointer self) {
	unity_places_button_rounded_rect (self, cr, width, height);
}


static GObject * unity_places_button_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesButton * self;
	parent_class = G_OBJECT_CLASS (unity_places_button_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_BUTTON (obj);
	{
		UnityCairoCanvas* _tmp0_;
		UnityPlacesButtonButtonOutlineFunc _tmp1_;
		self->priv->bg = (_tmp0_ = g_object_ref_sink (unity_cairo_canvas_new (_unity_places_button_paint_bg_unity_cairo_canvas_cairo_canvas_paint, self)), _g_object_unref0 (self->priv->bg), _tmp0_);
		ctk_actor_set_background ((CtkActor*) self, (ClutterActor*) self->priv->bg);
		clutter_actor_show ((ClutterActor*) self->priv->bg);
		g_signal_connect_object ((GObject*) self, "notify::state", (GCallback) __lambda16__g_object_notify, self, 0);
		self->outline_func = (_tmp1_ = _unity_places_button_rounded_rect_unity_places_button_button_outline_func, ((self->outline_func_target_destroy_notify == NULL) ? NULL : (self->outline_func_target_destroy_notify (self->outline_func_target), NULL), self->outline_func = NULL, self->outline_func_target = NULL, self->outline_func_target_destroy_notify = NULL), self->outline_func_target = g_object_ref (self), self->outline_func_target_destroy_notify = g_object_unref, _tmp1_);
	}
	return obj;
}


static void unity_places_button_class_init (UnityPlacesButtonClass * klass) {
	unity_places_button_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesButtonPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_places_button_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_button_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_places_button_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_button_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_BUTTON_NORMAL_STATE, g_param_spec_enum ("normal-state", "normal-state", "normal-state", UNITY_PLACES_BUTTON_TYPE_NORMAL_STATE, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_BUTTON_PRELIGHT_STATE, g_param_spec_enum ("prelight-state", "prelight-state", "prelight-state", UNITY_PLACES_BUTTON_TYPE_PRELIGHT_STATE, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void unity_places_button_instance_init (UnityPlacesButton * self) {
	self->priv = UNITY_PLACES_BUTTON_GET_PRIVATE (self);
	self->priv->_normal_state = UNITY_PLACES_BUTTON_NORMAL_STATE_NONE;
	self->priv->_prelight_state = UNITY_PLACES_BUTTON_PRELIGHT_STATE_NONE;
}


static void unity_places_button_finalize (GObject* obj) {
	UnityPlacesButton * self;
	self = UNITY_PLACES_BUTTON (obj);
	(self->outline_func_target_destroy_notify == NULL) ? NULL : (self->outline_func_target_destroy_notify (self->outline_func_target), NULL);
	self->outline_func = NULL;
	self->outline_func_target = NULL;
	self->outline_func_target_destroy_notify = NULL;
	_g_object_unref0 (self->priv->bg);
	_g_object_unref0 (self->priv->glow);
	G_OBJECT_CLASS (unity_places_button_parent_class)->finalize (obj);
}


GType unity_places_button_get_type (void) {
	static volatile gsize unity_places_button_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_button_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesButtonClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_button_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesButton), 0, (GInstanceInitFunc) unity_places_button_instance_init, NULL };
		GType unity_places_button_type_id;
		unity_places_button_type_id = g_type_register_static (CTK_TYPE_BUTTON, "UnityPlacesButton", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_button_type_id__volatile, unity_places_button_type_id);
	}
	return unity_places_button_type_id__volatile;
}


static void unity_places_button_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesButton * self;
	self = UNITY_PLACES_BUTTON (object);
	switch (property_id) {
		case UNITY_PLACES_BUTTON_NORMAL_STATE:
		g_value_set_enum (value, unity_places_button_get_normal_state (self));
		break;
		case UNITY_PLACES_BUTTON_PRELIGHT_STATE:
		g_value_set_enum (value, unity_places_button_get_prelight_state (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_button_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesButton * self;
	self = UNITY_PLACES_BUTTON (object);
	switch (property_id) {
		case UNITY_PLACES_BUTTON_NORMAL_STATE:
		unity_places_button_set_normal_state (self, g_value_get_enum (value));
		break;
		case UNITY_PLACES_BUTTON_PRELIGHT_STATE:
		unity_places_button_set_prelight_state (self, g_value_get_enum (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




