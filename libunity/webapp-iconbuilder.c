/* webapp-iconbuilder.c generated by valac, the Vala compiler
 * generated from webapp-iconbuilder.vala, do not modify */

/*
 *      webapp-iconbuilder.vala
 *      Copyright (C) 2010 Canonical Ltd
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 *
 *
 *      Authored by Gordon Allott <gord.allott@canonical.com>
 */

#include <glib.h>
#include <glib-object.h>
#include <cairo-svg.h>
#include <gdk-pixbuf/gdk-pixdata.h>
#include <stdlib.h>
#include <string.h>
#include <cairo.h>
#include <gdk/gdk.h>
#include <float.h>
#include <math.h>


#define UNITY_WEBAPP_TYPE_ICON_BUILDER (unity_webapp_icon_builder_get_type ())
#define UNITY_WEBAPP_ICON_BUILDER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_WEBAPP_TYPE_ICON_BUILDER, UnityWebappIconBuilder))
#define UNITY_WEBAPP_ICON_BUILDER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_WEBAPP_TYPE_ICON_BUILDER, UnityWebappIconBuilderClass))
#define UNITY_WEBAPP_IS_ICON_BUILDER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_WEBAPP_TYPE_ICON_BUILDER))
#define UNITY_WEBAPP_IS_ICON_BUILDER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_WEBAPP_TYPE_ICON_BUILDER))
#define UNITY_WEBAPP_ICON_BUILDER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_WEBAPP_TYPE_ICON_BUILDER, UnityWebappIconBuilderClass))

typedef struct _UnityWebappIconBuilder UnityWebappIconBuilder;
typedef struct _UnityWebappIconBuilderClass UnityWebappIconBuilderClass;
typedef struct _UnityWebappIconBuilderPrivate UnityWebappIconBuilderPrivate;
#define _cairo_surface_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_surface_destroy (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _cairo_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_destroy (var), NULL)))

struct _UnityWebappIconBuilder {
	GObject parent_instance;
	UnityWebappIconBuilderPrivate * priv;
};

struct _UnityWebappIconBuilderClass {
	GObjectClass parent_class;
};

struct _UnityWebappIconBuilderPrivate {
	cairo_surface_t* surf;
	GdkPixbuf* background;
	GdkPixbuf* foreground;
	cairo_surface_t* mask;
	char* _destination;
	GdkPixbuf* _source;
};


static gpointer unity_webapp_icon_builder_parent_class = NULL;

GType unity_webapp_icon_builder_get_type (void);
#define UNITY_WEBAPP_ICON_BUILDER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_WEBAPP_TYPE_ICON_BUILDER, UnityWebappIconBuilderPrivate))
enum  {
	UNITY_WEBAPP_ICON_BUILDER_DUMMY_PROPERTY,
	UNITY_WEBAPP_ICON_BUILDER_DESTINATION,
	UNITY_WEBAPP_ICON_BUILDER_SOURCE
};
UnityWebappIconBuilder* unity_webapp_icon_builder_new (const char* dest, GdkPixbuf* source);
UnityWebappIconBuilder* unity_webapp_icon_builder_construct (GType object_type, const char* dest, GdkPixbuf* source);
void unity_webapp_icon_builder_load_layers (UnityWebappIconBuilder* self);
const char* unity_webapp_icon_builder_get_destination (UnityWebappIconBuilder* self);
GdkPixbuf* unity_webapp_icon_builder_get_source (UnityWebappIconBuilder* self);
void unity_webapp_icon_builder_build_icon (UnityWebappIconBuilder* self);
static void unity_webapp_icon_builder_set_destination (UnityWebappIconBuilder* self, const char* value);
static void unity_webapp_icon_builder_set_source (UnityWebappIconBuilder* self, GdkPixbuf* value);
static GObject * unity_webapp_icon_builder_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_webapp_icon_builder_finalize (GObject* obj);
static void unity_webapp_icon_builder_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_webapp_icon_builder_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



#line 38 "webapp-iconbuilder.vala"
UnityWebappIconBuilder* unity_webapp_icon_builder_construct (GType object_type, const char* dest, GdkPixbuf* source) {
#line 101 "webapp-iconbuilder.c"
	UnityWebappIconBuilder * self;
#line 38 "webapp-iconbuilder.vala"
	g_return_val_if_fail (dest != NULL, NULL);
#line 38 "webapp-iconbuilder.vala"
	g_return_val_if_fail (source != NULL, NULL);
#line 40 "webapp-iconbuilder.vala"
	self = (UnityWebappIconBuilder*) g_object_new (object_type, "destination", dest, "source", source, NULL);
#line 109 "webapp-iconbuilder.c"
	return self;
}


#line 38 "webapp-iconbuilder.vala"
UnityWebappIconBuilder* unity_webapp_icon_builder_new (const char* dest, GdkPixbuf* source) {
#line 38 "webapp-iconbuilder.vala"
	return unity_webapp_icon_builder_construct (UNITY_WEBAPP_TYPE_ICON_BUILDER, dest, source);
#line 118 "webapp-iconbuilder.c"
}


#line 53 "webapp-iconbuilder.vala"
void unity_webapp_icon_builder_load_layers (UnityWebappIconBuilder* self) {
#line 124 "webapp-iconbuilder.c"
	GError * _inner_error_;
	cairo_surface_t* _tmp4_;
#line 53 "webapp-iconbuilder.vala"
	g_return_if_fail (self != NULL);
#line 129 "webapp-iconbuilder.c"
	_inner_error_ = NULL;
	{
		GdkPixbuf* _tmp0_;
		GdkPixbuf* _tmp1_;
		GdkPixbuf* _tmp2_;
		GdkPixbuf* _tmp3_;
#line 56 "webapp-iconbuilder.vala"
		_tmp0_ = gdk_pixbuf_new_from_file_at_scale ("/usr/share/unity/themes/prism_icon_background.png", 48, 48, TRUE, &_inner_error_);
#line 138 "webapp-iconbuilder.c"
		if (_inner_error_ != NULL) {
			goto __catch7_g_error;
		}
#line 56 "webapp-iconbuilder.vala"
		self->priv->background = (_tmp1_ = _tmp0_, _g_object_unref0 (self->priv->background), _tmp1_);
#line 57 "webapp-iconbuilder.vala"
		_tmp2_ = gdk_pixbuf_new_from_file_at_scale ("/usr/share/unity/themes/prism_icon_foreground.png", 48, 48, TRUE, &_inner_error_);
#line 146 "webapp-iconbuilder.c"
		if (_inner_error_ != NULL) {
			goto __catch7_g_error;
		}
#line 57 "webapp-iconbuilder.vala"
		self->priv->foreground = (_tmp3_ = _tmp2_, _g_object_unref0 (self->priv->foreground), _tmp3_);
#line 152 "webapp-iconbuilder.c"
	}
	goto __finally7;
	__catch7_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 59 "webapp-iconbuilder.vala"
			g_warning ("webapp-iconbuilder.vala:59: %s", e->message);
#line 163 "webapp-iconbuilder.c"
			_g_error_free0 (e);
		}
	}
	__finally7:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
#line 62 "webapp-iconbuilder.vala"
	self->priv->mask = (_tmp4_ = cairo_image_surface_create_from_png ("/usr/share/unity/themes/prism_icon_mask.png"), _cairo_surface_destroy0 (self->priv->mask), _tmp4_);
#line 175 "webapp-iconbuilder.c"
}


#line 1045 "glib-2.0.vapi"
static const char* string_to_string (const char* self) {
#line 181 "webapp-iconbuilder.c"
	const char* result;
#line 1045 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 185 "webapp-iconbuilder.c"
	result = self;
#line 1046 "glib-2.0.vapi"
	return result;
#line 189 "webapp-iconbuilder.c"
}


#line 65 "webapp-iconbuilder.vala"
void unity_webapp_icon_builder_build_icon (UnityWebappIconBuilder* self) {
#line 195 "webapp-iconbuilder.c"
	char* _tmp0_;
	cairo_t* cr;
	float pad_left;
	float pad_top;
#line 65 "webapp-iconbuilder.vala"
	g_return_if_fail (self != NULL);
#line 67 "webapp-iconbuilder.vala"
	g_debug ("webapp-iconbuilder.vala:67: %s", _tmp0_ = g_strconcat ("building icon ", string_to_string (self->priv->_destination), NULL));
#line 204 "webapp-iconbuilder.c"
	_g_free0 (_tmp0_);
#line 68 "webapp-iconbuilder.vala"
	cr = cairo_create (self->priv->surf);
#line 69 "webapp-iconbuilder.vala"
	gdk_cairo_set_source_pixbuf (cr, self->priv->background, (double) 0, (double) 0);
#line 70 "webapp-iconbuilder.vala"
	cairo_paint (cr);
#line 71 "webapp-iconbuilder.vala"
	cairo_stroke (cr);
#line 73 "webapp-iconbuilder.vala"
	pad_left = (float) 0;
#line 74 "webapp-iconbuilder.vala"
	pad_top = (float) 0;
#line 75 "webapp-iconbuilder.vala"
	if (gdk_pixbuf_get_width (self->priv->_source) < 48) {
#line 77 "webapp-iconbuilder.vala"
		pad_left = (48 - gdk_pixbuf_get_width (self->priv->_source)) / 2.0f;
#line 222 "webapp-iconbuilder.c"
	}
#line 79 "webapp-iconbuilder.vala"
	if (gdk_pixbuf_get_height (self->priv->_source) < 48) {
#line 81 "webapp-iconbuilder.vala"
		pad_top = (48 - gdk_pixbuf_get_height (self->priv->_source)) / 2.0f;
#line 228 "webapp-iconbuilder.c"
	}
#line 83 "webapp-iconbuilder.vala"
	gdk_cairo_set_source_pixbuf (cr, self->priv->_source, (double) pad_left, (double) pad_top);
#line 84 "webapp-iconbuilder.vala"
	cairo_mask_surface (cr, self->priv->mask, (double) 0, (double) 0);
#line 86 "webapp-iconbuilder.vala"
	gdk_cairo_set_source_pixbuf (cr, self->priv->foreground, (double) 0, (double) 0);
#line 87 "webapp-iconbuilder.vala"
	cairo_paint (cr);
#line 88 "webapp-iconbuilder.vala"
	cairo_stroke (cr);
#line 240 "webapp-iconbuilder.c"
	_cairo_destroy0 (cr);
}


const char* unity_webapp_icon_builder_get_destination (UnityWebappIconBuilder* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_destination;
#line 34 "webapp-iconbuilder.vala"
	return result;
#line 251 "webapp-iconbuilder.c"
}


static void unity_webapp_icon_builder_set_destination (UnityWebappIconBuilder* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_destination = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_destination), _tmp0_);
	g_object_notify ((GObject *) self, "destination");
}


GdkPixbuf* unity_webapp_icon_builder_get_source (UnityWebappIconBuilder* self) {
	GdkPixbuf* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_source;
#line 35 "webapp-iconbuilder.vala"
	return result;
#line 269 "webapp-iconbuilder.c"
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_webapp_icon_builder_set_source (UnityWebappIconBuilder* self, GdkPixbuf* value) {
	GdkPixbuf* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_source = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_source), _tmp0_);
	g_object_notify ((GObject *) self, "source");
}


static GObject * unity_webapp_icon_builder_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityWebappIconBuilder * self;
	parent_class = G_OBJECT_CLASS (unity_webapp_icon_builder_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_WEBAPP_ICON_BUILDER (obj);
	{
		cairo_surface_t* _tmp0_;
		gboolean _tmp1_ = FALSE;
#line 45 "webapp-iconbuilder.vala"
		self->priv->surf = (_tmp0_ = cairo_svg_surface_create (self->priv->_destination, (double) 48, (double) 48), _cairo_surface_destroy0 (self->priv->surf), _tmp0_);
#line 46 "webapp-iconbuilder.vala"
		unity_webapp_icon_builder_load_layers (self);
#line 47 "webapp-iconbuilder.vala"
		if (gdk_pixbuf_get_width (self->priv->_source) > 48) {
#line 47 "webapp-iconbuilder.vala"
			_tmp1_ = TRUE;
#line 304 "webapp-iconbuilder.c"
		} else {
#line 47 "webapp-iconbuilder.vala"
			_tmp1_ = gdk_pixbuf_get_height (self->priv->_source) > 48;
#line 308 "webapp-iconbuilder.c"
		}
#line 47 "webapp-iconbuilder.vala"
		if (_tmp1_) {
#line 312 "webapp-iconbuilder.c"
			GdkPixbuf* _tmp2_;
#line 49 "webapp-iconbuilder.vala"
			unity_webapp_icon_builder_set_source (self, _tmp2_ = gdk_pixbuf_scale_simple (self->priv->_source, 48, 48, GDK_INTERP_HYPER));
#line 316 "webapp-iconbuilder.c"
			_g_object_unref0 (_tmp2_);
		}
	}
	return obj;
}


static void unity_webapp_icon_builder_class_init (UnityWebappIconBuilderClass * klass) {
	unity_webapp_icon_builder_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityWebappIconBuilderPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_webapp_icon_builder_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_webapp_icon_builder_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_webapp_icon_builder_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_webapp_icon_builder_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_WEBAPP_ICON_BUILDER_DESTINATION, g_param_spec_string ("destination", "destination", "destination", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_WEBAPP_ICON_BUILDER_SOURCE, g_param_spec_object ("source", "source", "source", GDK_TYPE_PIXBUF, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_webapp_icon_builder_instance_init (UnityWebappIconBuilder * self) {
	self->priv = UNITY_WEBAPP_ICON_BUILDER_GET_PRIVATE (self);
}


static void unity_webapp_icon_builder_finalize (GObject* obj) {
	UnityWebappIconBuilder * self;
	self = UNITY_WEBAPP_ICON_BUILDER (obj);
	_cairo_surface_destroy0 (self->priv->surf);
	_g_object_unref0 (self->priv->background);
	_g_object_unref0 (self->priv->foreground);
	_cairo_surface_destroy0 (self->priv->mask);
	_g_free0 (self->priv->_destination);
	_g_object_unref0 (self->priv->_source);
	G_OBJECT_CLASS (unity_webapp_icon_builder_parent_class)->finalize (obj);
}


GType unity_webapp_icon_builder_get_type (void) {
	static GType unity_webapp_icon_builder_type_id = 0;
	if (unity_webapp_icon_builder_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityWebappIconBuilderClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_webapp_icon_builder_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityWebappIconBuilder), 0, (GInstanceInitFunc) unity_webapp_icon_builder_instance_init, NULL };
		unity_webapp_icon_builder_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityWebappIconBuilder", &g_define_type_info, 0);
	}
	return unity_webapp_icon_builder_type_id;
}


static void unity_webapp_icon_builder_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityWebappIconBuilder * self;
	self = UNITY_WEBAPP_ICON_BUILDER (object);
	switch (property_id) {
		case UNITY_WEBAPP_ICON_BUILDER_DESTINATION:
		g_value_set_string (value, unity_webapp_icon_builder_get_destination (self));
		break;
		case UNITY_WEBAPP_ICON_BUILDER_SOURCE:
		g_value_set_object (value, unity_webapp_icon_builder_get_source (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_webapp_icon_builder_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityWebappIconBuilder * self;
	self = UNITY_WEBAPP_ICON_BUILDER (object);
	switch (property_id) {
		case UNITY_WEBAPP_ICON_BUILDER_DESTINATION:
		unity_webapp_icon_builder_set_destination (self, g_value_get_string (value));
		break;
		case UNITY_WEBAPP_ICON_BUILDER_SOURCE:
		unity_webapp_icon_builder_set_source (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




