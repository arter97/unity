/* background.c generated by valac, the Vala compiler
 * generated from background.vala, do not modify */

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
 * FIXME: wallpaper-slideshows are not yet supported by this class
 */

#include <glib.h>
#include <glib-object.h>
#include <clutk/clutk.h>
#include <stdlib.h>
#include <string.h>
#include <clutter/clutter.h>
#include <libgnomeui/gnome-bg.h>
#include <gconf/gconf-client.h>
#include <gdk/gdk.h>
#include <cairo.h>
#include <float.h>
#include <math.h>
#include <gconf/gconf.h>
#include <unity-utils.h>


#define UNITY_TESTING_TYPE_BACKGROUND (unity_testing_background_get_type ())
#define UNITY_TESTING_BACKGROUND(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTING_TYPE_BACKGROUND, UnityTestingBackground))
#define UNITY_TESTING_BACKGROUND_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTING_TYPE_BACKGROUND, UnityTestingBackgroundClass))
#define UNITY_TESTING_IS_BACKGROUND(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTING_TYPE_BACKGROUND))
#define UNITY_TESTING_IS_BACKGROUND_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTING_TYPE_BACKGROUND))
#define UNITY_TESTING_BACKGROUND_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTING_TYPE_BACKGROUND, UnityTestingBackgroundClass))

typedef struct _UnityTestingBackground UnityTestingBackground;
typedef struct _UnityTestingBackgroundClass UnityTestingBackgroundClass;
typedef struct _UnityTestingBackgroundPrivate UnityTestingBackgroundPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _cairo_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_destroy (var), NULL)))
#define _cairo_pattern_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_pattern_destroy (var), NULL)))

struct _UnityTestingBackground {
	CtkBin parent_instance;
	UnityTestingBackgroundPrivate * priv;
};

struct _UnityTestingBackgroundClass {
	CtkBinClass parent_class;
};

struct _UnityTestingBackgroundPrivate {
	char* BG_DIR;
	char* BG_PIC_OPTS;
	char* BG_SHADE_TYPE;
	char* BG_PRIM_COL;
	char* BG_SEC_COL;
	char* BG_FILENAME;
	char* DEFAULT_PIC_OPTS;
	char* DEFAULT_SHADE_TYPE;
	char* DEFAULT_AMBIANCE_COL;
	char* DEFAULT_FILENAME;
	ClutterCairoTexture* bg_gradient;
	ClutterTexture* bg_image;
	GnomeBG* gbg;
	GConfClient* client;
	char* pic_opts;
	char* shade_type;
	char* prim_col;
	char* sec_col;
	char* filename;
};


static gpointer unity_testing_background_parent_class = NULL;

GType unity_testing_background_get_type (void) G_GNUC_CONST;
#define UNITY_TESTING_BACKGROUND_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TESTING_TYPE_BACKGROUND, UnityTestingBackgroundPrivate))
enum  {
	UNITY_TESTING_BACKGROUND_DUMMY_PROPERTY
};
static void _unity_testing_background_handle_image_placement (UnityTestingBackground* self);
static void _unity_testing_background_update_image (UnityTestingBackground* self);
static void _unity_testing_background_update_gradient (UnityTestingBackground* self);
static gboolean _lambda66_ (UnityTestingBackground* self);
static gboolean __lambda66__gsource_func (gpointer self);
static void _unity_testing_background_on_allocation_changed (UnityTestingBackground* self);
static void _unity_testing_background_on_gconf_changed (UnityTestingBackground* self, GConfClient* client, guint cxnid, GConfEntry* entry);
UnityTestingBackground* unity_testing_background_new (void);
UnityTestingBackground* unity_testing_background_construct (GType object_type);
static void __unity_testing_background_on_gconf_changed_gconf_client_notify_func (GConfClient* client, guint cnxn_id, GConfEntry* entry, gpointer self);
static void __unity_testing_background_handle_image_placement_clutter_texture_load_finished (ClutterTexture* _sender, void* _error_, gpointer self);
static void __unity_testing_background_on_allocation_changed_clutter_actor_allocation_changed (ClutterActor* _sender, const ClutterActorBox* box, ClutterAllocationFlags flags, gpointer self);
static GObject * unity_testing_background_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_testing_background_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



static void _unity_testing_background_handle_image_placement (UnityTestingBackground* self) {
	GnomeBGPlacement placement;
	g_return_if_fail (self != NULL);
	placement = gnome_bg_get_placement (self->priv->gbg);
	switch (placement) {
		case GNOME_BG_PLACEMENT_TILED:
		{
			{
				clutter_texture_set_repeat (self->priv->bg_image, TRUE, TRUE);
				clutter_texture_set_sync_size (self->priv->bg_image, TRUE);
				clutter_actor_set_x ((ClutterActor*) self, 0.0f);
				clutter_actor_set_y ((ClutterActor*) self, 0.0f);
			}
			break;
		}
		case GNOME_BG_PLACEMENT_ZOOMED:
		{
			{
				clutter_texture_set_repeat (self->priv->bg_image, FALSE, FALSE);
				clutter_texture_set_sync_size (self->priv->bg_image, FALSE);
				clutter_texture_set_keep_aspect_ratio (self->priv->bg_image, TRUE);
				clutter_actor_set_x ((ClutterActor*) self, 0.0f);
				clutter_actor_set_y ((ClutterActor*) self, 0.0f);
			}
			break;
		}
		case GNOME_BG_PLACEMENT_CENTERED:
		{
			{
				clutter_texture_set_repeat (self->priv->bg_image, FALSE, FALSE);
				clutter_texture_set_sync_size (self->priv->bg_image, FALSE);
				clutter_texture_set_keep_aspect_ratio (self->priv->bg_image, FALSE);
				clutter_actor_set_x ((ClutterActor*) self, 0.0f);
				clutter_actor_set_y ((ClutterActor*) self, 0.0f);
			}
			break;
		}
		case GNOME_BG_PLACEMENT_SCALED:
		{
			{
				clutter_texture_set_keep_aspect_ratio (self->priv->bg_image, TRUE);
				clutter_texture_set_sync_size (self->priv->bg_image, FALSE);
				clutter_actor_set_x ((ClutterActor*) self, 0.0f);
				clutter_actor_set_y ((ClutterActor*) self, 0.0f);
			}
			break;
		}
		case GNOME_BG_PLACEMENT_FILL_SCREEN:
		{
			{
				clutter_texture_set_keep_aspect_ratio (self->priv->bg_image, FALSE);
				clutter_actor_set_x ((ClutterActor*) self, 0.0f);
				clutter_actor_set_y ((ClutterActor*) self, 0.0f);
			}
			break;
		}
		case GNOME_BG_PLACEMENT_SPANNED:
		{
			{
				clutter_texture_set_repeat (self->priv->bg_image, FALSE, FALSE);
				clutter_texture_set_sync_size (self->priv->bg_image, TRUE);
				clutter_texture_set_keep_aspect_ratio (self->priv->bg_image, TRUE);
				clutter_actor_set_x ((ClutterActor*) self, 0.0f);
				clutter_actor_set_y ((ClutterActor*) self, 0.0f);
			}
			break;
		}
	}
}


static gboolean _lambda66_ (UnityTestingBackground* self) {
	gboolean result = FALSE;
	if (_vala_strcmp0 (self->priv->filename, "") != 0) {
		_unity_testing_background_update_image (self);
	} else {
		_unity_testing_background_update_gradient (self);
	}
	result = FALSE;
	return result;
}


static gboolean __lambda66__gsource_func (gpointer self) {
	gboolean result;
	result = _lambda66_ (self);
	return result;
}


static void _unity_testing_background_on_allocation_changed (UnityTestingBackground* self) {
	g_return_if_fail (self != NULL);
	g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 0, __lambda66__gsource_func, g_object_ref (self), g_object_unref);
}


static void _unity_testing_background_update_image (UnityTestingBackground* self) {
	GError * _inner_error_;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	if (clutter_container_find_child_by_name ((ClutterContainer*) self, "bg_image") != CLUTTER_ACTOR (self->priv->bg_image)) {
		gboolean _tmp0_ = FALSE;
		if (CLUTTER_IS_ACTOR (self->priv->bg_gradient)) {
			_tmp0_ = clutter_actor_get_parent ((ClutterActor*) self->priv->bg_gradient) == CLUTTER_ACTOR (self);
		} else {
			_tmp0_ = FALSE;
		}
		if (_tmp0_) {
			clutter_container_remove_actor ((ClutterContainer*) self, (ClutterActor*) self->priv->bg_gradient);
		}
		clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) self->priv->bg_image);
		clutter_actor_show ((ClutterActor*) self->priv->bg_image);
	}
	{
		clutter_texture_set_from_file (self->priv->bg_image, self->priv->filename, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch46_g_error;
		}
	}
	goto __finally46;
	__catch46_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("background.vala:241: Background: Unable to load background file %s: %s", self->priv->filename, e->message);
			_g_error_free0 (e);
		}
	}
	__finally46:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void _unity_testing_background_update_gradient (UnityTestingBackground* self) {
	GnomeBGColorType type = 0;
	GdkColor primary = {0};
	GdkColor secondary = {0};
	g_return_if_fail (self != NULL);
	if (clutter_container_find_child_by_name ((ClutterContainer*) self, "bg_gradient") != CLUTTER_ACTOR (self->priv->bg_gradient)) {
		gboolean _tmp0_ = FALSE;
		if (CLUTTER_IS_ACTOR (self->priv->bg_image)) {
			_tmp0_ = clutter_actor_get_parent ((ClutterActor*) self->priv->bg_image) == CLUTTER_ACTOR (self);
		} else {
			_tmp0_ = FALSE;
		}
		if (_tmp0_) {
			clutter_container_remove_actor ((ClutterContainer*) self, (ClutterActor*) self->priv->bg_image);
		}
		clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) self->priv->bg_gradient);
		clutter_actor_show ((ClutterActor*) self->priv->bg_gradient);
	}
	clutter_actor_set_x ((ClutterActor*) self, 0.0f);
	clutter_actor_set_y ((ClutterActor*) self, 0.0f);
	gnome_bg_get_color (self->priv->gbg, &type, &primary, &secondary);
	clutter_cairo_texture_set_surface_size (self->priv->bg_gradient, (guint) clutter_actor_get_width ((ClutterActor*) self), (guint) clutter_actor_get_height ((ClutterActor*) self));
	switch (type) {
		case GNOME_BG_COLOR_SOLID:
		{
			{
				cairo_t* cr;
				cr = clutter_cairo_texture_create (self->priv->bg_gradient);
				cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
				cairo_scale (cr, (double) 1.0f, (double) 1.0f);
				cairo_set_source_rgb (cr, ((double) primary.red) / ((double) 0xffff), ((double) primary.green) / ((double) 0xffff), ((double) primary.blue) / ((double) 0xffff));
				cairo_rectangle (cr, (double) 0.0f, (double) 0.0f, (double) clutter_actor_get_width ((ClutterActor*) self), (double) clutter_actor_get_height ((ClutterActor*) self));
				cairo_fill (cr);
				_cairo_destroy0 (cr);
			}
			break;
		}
		case GNOME_BG_COLOR_V_GRADIENT:
		{
			{
				cairo_t* cr;
				cairo_pattern_t* pat;
				cr = clutter_cairo_texture_create (self->priv->bg_gradient);
				pat = cairo_pattern_create_linear ((double) 0.0f, (double) 0.0f, (double) 0.0f, (double) clutter_actor_get_height ((ClutterActor*) self));
				cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
				cairo_scale (cr, (double) 1.0f, (double) 1.0f);
				cairo_pattern_add_color_stop_rgb (pat, (double) 0.0f, ((double) primary.red) / ((double) 0xffff), ((double) primary.green) / ((double) 0xffff), ((double) primary.blue) / ((double) 0xffff));
				cairo_pattern_add_color_stop_rgb (pat, (double) 1.0f, ((double) secondary.red) / ((double) 0xffff), ((double) secondary.green) / ((double) 0xffff), ((double) secondary.blue) / ((double) 0xffff));
				cairo_set_source (cr, pat);
				cairo_rectangle (cr, (double) 0.0f, (double) 0.0f, (double) clutter_actor_get_width ((ClutterActor*) self), (double) clutter_actor_get_height ((ClutterActor*) self));
				cairo_fill (cr);
				_cairo_pattern_destroy0 (pat);
				_cairo_destroy0 (cr);
			}
			break;
		}
		case GNOME_BG_COLOR_H_GRADIENT:
		{
			{
				cairo_t* cr;
				cairo_pattern_t* pat;
				cr = clutter_cairo_texture_create (self->priv->bg_gradient);
				pat = cairo_pattern_create_linear ((double) 0.0f, (double) 0.0f, (double) clutter_actor_get_width ((ClutterActor*) self), (double) 0.0f);
				cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
				cairo_scale (cr, (double) 1.0f, (double) 1.0f);
				cairo_pattern_add_color_stop_rgb (pat, (double) 0.0f, ((double) primary.red) / ((double) 0xffff), ((double) primary.green) / ((double) 0xffff), ((double) primary.blue) / ((double) 0xffff));
				cairo_pattern_add_color_stop_rgb (pat, (double) 1.0f, ((double) secondary.red) / ((double) 0xffff), ((double) secondary.green) / ((double) 0xffff), ((double) secondary.blue) / ((double) 0xffff));
				cairo_set_source (cr, pat);
				cairo_rectangle (cr, (double) 0.0f, (double) 0.0f, (double) clutter_actor_get_width ((ClutterActor*) self), (double) clutter_actor_get_height ((ClutterActor*) self));
				cairo_fill (cr);
				_cairo_pattern_destroy0 (pat);
				_cairo_destroy0 (cr);
			}
			break;
		}
	}
}


static void _unity_testing_background_on_gconf_changed (UnityTestingBackground* self, GConfClient* client, guint cxnid, GConfEntry* entry) {
	GError * _inner_error_;
	gboolean needs_update;
	char* new_value;
	g_return_if_fail (self != NULL);
	g_return_if_fail (client != NULL);
	g_return_if_fail (entry != NULL);
	_inner_error_ = NULL;
	needs_update = FALSE;
	new_value = NULL;
	gnome_bg_load_from_preferences (self->priv->gbg, client);
	{
		char* _tmp0_;
		char* _tmp1_;
		_tmp0_ = gconf_client_get_string (self->priv->client, self->priv->BG_PIC_OPTS, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch47_g_error;
		}
		new_value = (_tmp1_ = _tmp0_, _g_free0 (new_value), _tmp1_);
	}
	goto __finally47;
	__catch47_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp2_;
			new_value = (_tmp2_ = g_strdup (self->priv->DEFAULT_PIC_OPTS), _g_free0 (new_value), _tmp2_);
			_g_error_free0 (e);
		}
	}
	__finally47:
	if (_inner_error_ != NULL) {
		_g_free0 (new_value);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	if (_vala_strcmp0 (new_value, self->priv->pic_opts) != 0) {
		char* _tmp3_;
		self->priv->pic_opts = (_tmp3_ = g_strdup (new_value), _g_free0 (self->priv->pic_opts), _tmp3_);
		needs_update = TRUE;
	}
	{
		char* _tmp4_;
		char* _tmp5_;
		_tmp4_ = gconf_client_get_string (self->priv->client, self->priv->BG_SHADE_TYPE, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch48_g_error;
		}
		new_value = (_tmp5_ = _tmp4_, _g_free0 (new_value), _tmp5_);
	}
	goto __finally48;
	__catch48_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp6_;
			new_value = (_tmp6_ = g_strdup (self->priv->DEFAULT_SHADE_TYPE), _g_free0 (new_value), _tmp6_);
			_g_error_free0 (e);
		}
	}
	__finally48:
	if (_inner_error_ != NULL) {
		_g_free0 (new_value);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	if (_vala_strcmp0 (new_value, self->priv->shade_type) != 0) {
		char* _tmp7_;
		self->priv->shade_type = (_tmp7_ = g_strdup (new_value), _g_free0 (self->priv->shade_type), _tmp7_);
		needs_update = TRUE;
	}
	{
		char* _tmp8_;
		char* _tmp9_;
		_tmp8_ = gconf_client_get_string (self->priv->client, self->priv->BG_PRIM_COL, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch49_g_error;
		}
		new_value = (_tmp9_ = _tmp8_, _g_free0 (new_value), _tmp9_);
	}
	goto __finally49;
	__catch49_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp10_;
			new_value = (_tmp10_ = g_strdup (self->priv->DEFAULT_AMBIANCE_COL), _g_free0 (new_value), _tmp10_);
			_g_error_free0 (e);
		}
	}
	__finally49:
	if (_inner_error_ != NULL) {
		_g_free0 (new_value);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	if (_vala_strcmp0 (new_value, self->priv->prim_col) != 0) {
		char* _tmp11_;
		self->priv->prim_col = (_tmp11_ = g_strdup (new_value), _g_free0 (self->priv->prim_col), _tmp11_);
		needs_update = TRUE;
	}
	{
		char* _tmp12_;
		char* _tmp13_;
		_tmp12_ = gconf_client_get_string (self->priv->client, self->priv->BG_SEC_COL, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch50_g_error;
		}
		new_value = (_tmp13_ = _tmp12_, _g_free0 (new_value), _tmp13_);
	}
	goto __finally50;
	__catch50_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp14_;
			new_value = (_tmp14_ = g_strdup (self->priv->DEFAULT_AMBIANCE_COL), _g_free0 (new_value), _tmp14_);
			_g_error_free0 (e);
		}
	}
	__finally50:
	if (_inner_error_ != NULL) {
		_g_free0 (new_value);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	if (_vala_strcmp0 (new_value, self->priv->sec_col) != 0) {
		char* _tmp15_;
		self->priv->sec_col = (_tmp15_ = g_strdup (new_value), _g_free0 (self->priv->sec_col), _tmp15_);
		needs_update = TRUE;
	}
	{
		char* _tmp16_;
		char* _tmp17_;
		_tmp16_ = gconf_client_get_string (self->priv->client, self->priv->BG_FILENAME, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch51_g_error;
		}
		new_value = (_tmp17_ = _tmp16_, _g_free0 (new_value), _tmp17_);
	}
	goto __finally51;
	__catch51_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp18_;
			new_value = (_tmp18_ = g_strdup (self->priv->DEFAULT_FILENAME), _g_free0 (new_value), _tmp18_);
			_g_error_free0 (e);
		}
	}
	__finally51:
	if (_inner_error_ != NULL) {
		_g_free0 (new_value);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	if (_vala_strcmp0 (new_value, self->priv->filename) != 0) {
		char* _tmp19_;
		self->priv->filename = (_tmp19_ = g_strdup (new_value), _g_free0 (self->priv->filename), _tmp19_);
		needs_update = TRUE;
	}
	if (needs_update) {
		if (_vala_strcmp0 (self->priv->filename, "") != 0) {
			_unity_testing_background_update_image (self);
		} else {
			_unity_testing_background_update_gradient (self);
		}
	}
	_g_free0 (new_value);
}


UnityTestingBackground* unity_testing_background_construct (GType object_type) {
	UnityTestingBackground * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


UnityTestingBackground* unity_testing_background_new (void) {
	return unity_testing_background_construct (UNITY_TESTING_TYPE_BACKGROUND);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void __unity_testing_background_on_gconf_changed_gconf_client_notify_func (GConfClient* client, guint cnxn_id, GConfEntry* entry, gpointer self) {
	_unity_testing_background_on_gconf_changed (self, client, cnxn_id, entry);
}


static void __unity_testing_background_handle_image_placement_clutter_texture_load_finished (ClutterTexture* _sender, void* _error_, gpointer self) {
	_unity_testing_background_handle_image_placement (self);
}


static void __unity_testing_background_on_allocation_changed_clutter_actor_allocation_changed (ClutterActor* _sender, const ClutterActorBox* box, ClutterAllocationFlags flags, gpointer self) {
	_unity_testing_background_on_allocation_changed (self);
}


static GObject * unity_testing_background_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityTestingBackground * self;
	GError * _inner_error_;
	parent_class = G_OBJECT_CLASS (unity_testing_background_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_TESTING_BACKGROUND (obj);
	_inner_error_ = NULL;
	{
		GnomeBG* _tmp0_;
		GConfClient* _tmp1_;
		ClutterCairoTexture* _tmp17_;
		ClutterTexture* _tmp18_;
		START_FUNCTION ();
		self->priv->gbg = (_tmp0_ = gnome_bg_new (), _g_object_unref0 (self->priv->gbg), _tmp0_);
		self->priv->client = (_tmp1_ = _g_object_ref0 (gconf_client_get_default ()), _g_object_unref0 (self->priv->client), _tmp1_);
		{
			gconf_client_add_dir (self->priv->client, self->priv->BG_DIR, GCONF_CLIENT_PRELOAD_NONE, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch52_g_error;
			}
		}
		goto __finally52;
		__catch52_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("background.vala:62: Background: Unable to monitor background-settings:" \
" %s", e->message);
				_g_error_free0 (e);
			}
		}
		__finally52:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		{
			char* _tmp2_;
			char* _tmp3_;
			_tmp2_ = gconf_client_get_string (self->priv->client, self->priv->BG_PIC_OPTS, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch53_g_error;
			}
			self->priv->pic_opts = (_tmp3_ = _tmp2_, _g_free0 (self->priv->pic_opts), _tmp3_);
		}
		goto __finally53;
		__catch53_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				char* _tmp4_;
				self->priv->pic_opts = (_tmp4_ = g_strdup (self->priv->DEFAULT_PIC_OPTS), _g_free0 (self->priv->pic_opts), _tmp4_);
				_g_error_free0 (e);
			}
		}
		__finally53:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		{
			char* _tmp5_;
			char* _tmp6_;
			_tmp5_ = gconf_client_get_string (self->priv->client, self->priv->BG_SHADE_TYPE, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch54_g_error;
			}
			self->priv->shade_type = (_tmp6_ = _tmp5_, _g_free0 (self->priv->shade_type), _tmp6_);
		}
		goto __finally54;
		__catch54_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				char* _tmp7_;
				self->priv->shade_type = (_tmp7_ = g_strdup (self->priv->DEFAULT_SHADE_TYPE), _g_free0 (self->priv->shade_type), _tmp7_);
				_g_error_free0 (e);
			}
		}
		__finally54:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		{
			char* _tmp8_;
			char* _tmp9_;
			_tmp8_ = gconf_client_get_string (self->priv->client, self->priv->BG_PRIM_COL, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch55_g_error;
			}
			self->priv->prim_col = (_tmp9_ = _tmp8_, _g_free0 (self->priv->prim_col), _tmp9_);
		}
		goto __finally55;
		__catch55_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				char* _tmp10_;
				self->priv->prim_col = (_tmp10_ = g_strdup (self->priv->DEFAULT_AMBIANCE_COL), _g_free0 (self->priv->prim_col), _tmp10_);
				_g_error_free0 (e);
			}
		}
		__finally55:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		{
			char* _tmp11_;
			char* _tmp12_;
			_tmp11_ = gconf_client_get_string (self->priv->client, self->priv->BG_SEC_COL, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch56_g_error;
			}
			self->priv->sec_col = (_tmp12_ = _tmp11_, _g_free0 (self->priv->sec_col), _tmp12_);
		}
		goto __finally56;
		__catch56_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				char* _tmp13_;
				self->priv->sec_col = (_tmp13_ = g_strdup (self->priv->DEFAULT_AMBIANCE_COL), _g_free0 (self->priv->sec_col), _tmp13_);
				_g_error_free0 (e);
			}
		}
		__finally56:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		{
			char* _tmp14_;
			char* _tmp15_;
			_tmp14_ = gconf_client_get_string (self->priv->client, self->priv->BG_FILENAME, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch57_g_error;
			}
			self->priv->filename = (_tmp15_ = _tmp14_, _g_free0 (self->priv->filename), _tmp15_);
		}
		goto __finally57;
		__catch57_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				char* _tmp16_;
				self->priv->filename = (_tmp16_ = g_strdup (self->priv->DEFAULT_FILENAME), _g_free0 (self->priv->filename), _tmp16_);
				_g_error_free0 (e);
			}
		}
		__finally57:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		{
			gconf_client_notify_add (self->priv->client, self->priv->BG_DIR, __unity_testing_background_on_gconf_changed_gconf_client_notify_func, g_object_ref (self), g_object_unref, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch58_g_error;
			}
		}
		goto __finally58;
		__catch58_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("background.vala:119: Background: Unable to monitor background: %s", e->message);
				_g_error_free0 (e);
			}
		}
		__finally58:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		self->priv->bg_gradient = (_tmp17_ = g_object_ref_sink ((ClutterCairoTexture*) clutter_cairo_texture_new ((guint) 1, (guint) 1)), _g_object_unref0 (self->priv->bg_gradient), _tmp17_);
		clutter_actor_set_name ((ClutterActor*) self->priv->bg_gradient, "bg_gradient");
		self->priv->bg_image = (_tmp18_ = g_object_ref_sink ((ClutterTexture*) clutter_texture_new ()), _g_object_unref0 (self->priv->bg_image), _tmp18_);
		clutter_actor_set_name ((ClutterActor*) self->priv->bg_image, "bg_image");
		clutter_texture_set_load_async (self->priv->bg_image, TRUE);
		g_signal_connect_object (self->priv->bg_image, "load-finished", (GCallback) __unity_testing_background_handle_image_placement_clutter_texture_load_finished, self, 0);
		gnome_bg_load_from_preferences (self->priv->gbg, self->priv->client);
		g_signal_connect_object ((ClutterActor*) self, "allocation-changed", (GCallback) __unity_testing_background_on_allocation_changed_clutter_actor_allocation_changed, self, 0);
		END_FUNCTION ();
	}
	return obj;
}


static void unity_testing_background_class_init (UnityTestingBackgroundClass * klass) {
	unity_testing_background_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityTestingBackgroundPrivate));
	G_OBJECT_CLASS (klass)->constructor = unity_testing_background_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_testing_background_finalize;
}


static void unity_testing_background_instance_init (UnityTestingBackground * self) {
	self->priv = UNITY_TESTING_BACKGROUND_GET_PRIVATE (self);
	self->priv->BG_DIR = g_strdup ("/desktop/gnome/background");
	self->priv->BG_PIC_OPTS = g_strdup ("/desktop/gnome/background/picture_options");
	self->priv->BG_SHADE_TYPE = g_strdup ("/desktop/gnome/background/color_shading_type");
	self->priv->BG_PRIM_COL = g_strdup ("/desktop/gnome/background/primary_color");
	self->priv->BG_SEC_COL = g_strdup ("/desktop/gnome/background/secondary_color");
	self->priv->BG_FILENAME = g_strdup ("/desktop/gnome/background/picture_filename");
	self->priv->DEFAULT_PIC_OPTS = g_strdup ("none");
	self->priv->DEFAULT_SHADE_TYPE = g_strdup ("solid");
	self->priv->DEFAULT_AMBIANCE_COL = g_strdup ("#2C2C00001E1E");
	self->priv->DEFAULT_FILENAME = g_strdup ("/usr/share/backgrounds/warty-final.png");
}


static void unity_testing_background_finalize (GObject* obj) {
	UnityTestingBackground * self;
	self = UNITY_TESTING_BACKGROUND (obj);
	_g_free0 (self->priv->BG_DIR);
	_g_free0 (self->priv->BG_PIC_OPTS);
	_g_free0 (self->priv->BG_SHADE_TYPE);
	_g_free0 (self->priv->BG_PRIM_COL);
	_g_free0 (self->priv->BG_SEC_COL);
	_g_free0 (self->priv->BG_FILENAME);
	_g_free0 (self->priv->DEFAULT_PIC_OPTS);
	_g_free0 (self->priv->DEFAULT_SHADE_TYPE);
	_g_free0 (self->priv->DEFAULT_AMBIANCE_COL);
	_g_free0 (self->priv->DEFAULT_FILENAME);
	_g_object_unref0 (self->priv->bg_gradient);
	_g_object_unref0 (self->priv->bg_image);
	_g_object_unref0 (self->priv->gbg);
	_g_object_unref0 (self->priv->client);
	_g_free0 (self->priv->pic_opts);
	_g_free0 (self->priv->shade_type);
	_g_free0 (self->priv->prim_col);
	_g_free0 (self->priv->sec_col);
	_g_free0 (self->priv->filename);
	G_OBJECT_CLASS (unity_testing_background_parent_class)->finalize (obj);
}


GType unity_testing_background_get_type (void) {
	static volatile gsize unity_testing_background_type_id__volatile = 0;
	if (g_once_init_enter (&unity_testing_background_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestingBackgroundClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_testing_background_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestingBackground), 0, (GInstanceInitFunc) unity_testing_background_instance_init, NULL };
		GType unity_testing_background_type_id;
		unity_testing_background_type_id = g_type_register_static (CTK_TYPE_BIN, "UnityTestingBackground", &g_define_type_info, 0);
		g_once_init_leave (&unity_testing_background_type_id__volatile, unity_testing_background_type_id);
	}
	return unity_testing_background_type_id__volatile;
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




