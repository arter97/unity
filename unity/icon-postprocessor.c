/* icon-postprocessor.c generated by valac 0.9.7, the Vala compiler
 * generated from icon-postprocessor.vala, do not modify */

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
 */

#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>
#include <gdk-pixbuf/gdk-pixdata.h>
#include <clutter/clutter.h>
#include <clutk/clutk.h>
#include <cogl/cogl.h>
#include <string.h>
#include <stdlib.h>


#define UNITY_TYPE_UNITY_ICON (unity_unity_icon_get_type ())
#define UNITY_UNITY_ICON(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_UNITY_ICON, UnityUnityIcon))
#define UNITY_UNITY_ICON_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_UNITY_ICON, UnityUnityIconClass))
#define UNITY_IS_UNITY_ICON(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_UNITY_ICON))
#define UNITY_IS_UNITY_ICON_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_UNITY_ICON))
#define UNITY_UNITY_ICON_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_UNITY_ICON, UnityUnityIconClass))

typedef struct _UnityUnityIcon UnityUnityIcon;
typedef struct _UnityUnityIconClass UnityUnityIconClass;
typedef struct _UnityUnityIconPrivate UnityUnityIconPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _cogl_handle_unref0(var) ((var == NULL) ? NULL : (var = (cogl_handle_unref (var), NULL)))

#define UNITY_TYPE_THEME_IMAGE (unity_theme_image_get_type ())
#define UNITY_THEME_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_THEME_IMAGE, UnityThemeImage))
#define UNITY_THEME_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_THEME_IMAGE, UnityThemeImageClass))
#define UNITY_IS_THEME_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_THEME_IMAGE))
#define UNITY_IS_THEME_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_THEME_IMAGE))
#define UNITY_THEME_IMAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_THEME_IMAGE, UnityThemeImageClass))

typedef struct _UnityThemeImage UnityThemeImage;
typedef struct _UnityThemeImageClass UnityThemeImageClass;

struct _UnityUnityIcon {
	CtkActor parent_instance;
	UnityUnityIconPrivate * priv;
	float stored_height;
	float stored_ymod;
};

struct _UnityUnityIconClass {
	CtkActorClass parent_class;
};

struct _UnityUnityIconPrivate {
	ClutterTexture* _icon;
	ClutterTexture* _bg_color;
	CoglHandle* bg_mat;
	CoglHandle* fg_mat;
	CoglHandle* icon_material;
	CoglHandle* bgcol_material;
	float _rotation;
};


extern ClutterTexture* unity_unity_icon_bg_layer;
ClutterTexture* unity_unity_icon_bg_layer = NULL;
extern ClutterTexture* unity_unity_icon_fg_layer;
ClutterTexture* unity_unity_icon_fg_layer = NULL;
extern ClutterTexture* unity_unity_icon_mk_layer;
ClutterTexture* unity_unity_icon_mk_layer = NULL;
static gpointer unity_unity_icon_parent_class = NULL;

void unity_rgb_to_hsv (float r, float g, float b, float* hue, float* sat, float* val);
void unity_hsv_to_rgb (float hue, float sat, float val, float* r, float* g, float* b);
guint unity_pixbuf_check_threshold (GdkPixbuf* source, gint x1, gint y1, gint x2, gint y2, float threshold);
gboolean unity_pixbuf_is_tile (GdkPixbuf* source);
void unity_get_average_color (GdkPixbuf* source, guint* red, guint* green, guint* blue);
GType unity_unity_icon_get_type (void) G_GNUC_CONST;
#define UNITY_UNITY_ICON_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TYPE_UNITY_ICON, UnityUnityIconPrivate))
enum  {
	UNITY_UNITY_ICON_DUMMY_PROPERTY,
	UNITY_UNITY_ICON_ICON,
	UNITY_UNITY_ICON_BG_COLOR,
	UNITY_UNITY_ICON_ROTATION
};
UnityUnityIcon* unity_unity_icon_new (ClutterTexture* icon, ClutterTexture* bg_tex);
UnityUnityIcon* unity_unity_icon_construct (GType object_type, ClutterTexture* icon, ClutterTexture* bg_tex);
static void unity_unity_icon_real_get_preferred_width (ClutterActor* base, float for_height, float* minimum_width, float* natural_width);
static void unity_unity_icon_real_get_preferred_height (ClutterActor* base, float for_width, float* minimum_height, float* natural_height);
static void unity_unity_icon_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
ClutterTexture* unity_unity_icon_get_icon (UnityUnityIcon* self);
ClutterTexture* unity_unity_icon_get_bg_color (UnityUnityIcon* self);
static void unity_unity_icon_real_pick (ClutterActor* base, const ClutterColor* color);
void unity_unity_icon_paint_real (ClutterActor* actor);
float unity_unity_icon_get_rotation (UnityUnityIcon* self);
static void unity_unity_icon_real_paint (ClutterActor* base);
static void _unity_unity_icon_paint_real_ctk_effect_paint_func (ClutterActor* actor);
static void unity_unity_icon_real_map (ClutterActor* base);
static void unity_unity_icon_real_unmap (ClutterActor* base);
static void unity_unity_icon_set_icon (UnityUnityIcon* self, ClutterTexture* value);
static void unity_unity_icon_set_bg_color (UnityUnityIcon* self, ClutterTexture* value);
void unity_unity_icon_set_rotation (UnityUnityIcon* self, float value);
UnityThemeImage* unity_theme_image_new (const char* icon_name);
UnityThemeImage* unity_theme_image_construct (GType object_type, const char* icon_name);
GType unity_theme_image_get_type (void) G_GNUC_CONST;
static void _lambda1_ (UnityUnityIcon* self);
static void __lambda1__g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self);
static GObject * unity_unity_icon_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_unity_icon_finalize (GObject* obj);
static void unity_unity_icon_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_unity_icon_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



void unity_rgb_to_hsv (float r, float g, float b, float* hue, float* sat, float* val) {
	float min = 0.0F;
	float max;
	float delta;
	max = 0.0f;
	if (r > g) {
		float _tmp0_ = 0.0F;
		if (r > b) {
			_tmp0_ = r;
		} else {
			_tmp0_ = b;
		}
		max = _tmp0_;
	} else {
		float _tmp1_ = 0.0F;
		if (g > b) {
			_tmp1_ = g;
		} else {
			_tmp1_ = b;
		}
		max = _tmp1_;
	}
	if (r < g) {
		float _tmp2_ = 0.0F;
		if (r < b) {
			_tmp2_ = r;
		} else {
			_tmp2_ = b;
		}
		min = _tmp2_;
	} else {
		float _tmp3_ = 0.0F;
		if (g < b) {
			_tmp3_ = g;
		} else {
			_tmp3_ = b;
		}
		min = _tmp3_;
	}
	*val = max;
	delta = max - min;
	if (delta > 0.000001) {
		*sat = delta / max;
		*hue = 0.0f;
		if (r == max) {
			*hue = (g - b) / delta;
			if ((*hue) < 0.0f) {
				*hue = (*hue) + 6.0f;
			}
		} else {
			if (g == max) {
				*hue = 2.0f + ((b - r) / delta);
			} else {
				if (b == max) {
					*hue = 4.0f + ((r - g) / delta);
				}
			}
		}
		*hue = (*hue) / 6.0f;
	} else {
		*sat = 0.0f;
		*hue = 0.0f;
	}
}


void unity_hsv_to_rgb (float hue, float sat, float val, float* r, float* g, float* b) {
	gint i = 0;
	float f = 0.0F;
	float w = 0.0F;
	float q = 0.0F;
	float t = 0.0F;
	if (sat == 0.0) {
		*r = *g = *b = val;
	} else {
		if (hue == 1.0) {
			hue = 0.0f;
		}
		hue = hue * 6.0f;
		i = (gint) hue;
		f = hue - i;
		w = val * (1.0f - sat);
		q = val * (1.0f - (sat * f));
		t = val * (1.0f - (sat * (1.0f - f)));
		switch (i) {
			case 0:
			{
				*r = val;
				*g = t;
				*b = w;
				break;
			}
			case 1:
			{
				*r = q;
				*g = val;
				*b = w;
				break;
			}
			case 2:
			{
				*r = w;
				*g = val;
				*b = t;
				break;
			}
			case 3:
			{
				*r = w;
				*g = q;
				*b = val;
				break;
			}
			case 4:
			{
				*r = t;
				*g = w;
				*b = val;
				break;
			}
			case 5:
			{
				*r = val;
				*g = w;
				*b = q;
				break;
			}
		}
	}
}


guint unity_pixbuf_check_threshold (GdkPixbuf* source, gint x1, gint y1, gint x2, gint y2, float threshold) {
	guint result = 0U;
	gint num_channels;
	gint width;
	gint rowstride;
	guint total_visible_pixels;
	gint pixels_length1;
	gint _pixels_size_;
	guchar* _tmp0_;
	guchar* pixels;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_ = FALSE;
	guint i;
	g_return_val_if_fail (source != NULL, 0U);
	num_channels = gdk_pixbuf_get_n_channels (source);
	width = gdk_pixbuf_get_width (source);
	rowstride = gdk_pixbuf_get_rowstride (source);
	total_visible_pixels = (guint) 0;
	pixels = (_tmp0_ = gdk_pixbuf_get_pixels (source), pixels_length1 = -1, _pixels_size_ = pixels_length1, _tmp0_);
	if (gdk_pixbuf_get_colorspace (source) != GDK_COLORSPACE_RGB) {
		_tmp3_ = TRUE;
	} else {
		_tmp3_ = gdk_pixbuf_get_bits_per_sample (source) != 8;
	}
	if (_tmp3_) {
		_tmp2_ = TRUE;
	} else {
		_tmp2_ = !gdk_pixbuf_get_has_alpha (source);
	}
	if (_tmp2_) {
		_tmp1_ = TRUE;
	} else {
		_tmp1_ = num_channels != 4;
	}
	if (_tmp1_) {
		g_warning ("icon-postprocessor.vala:144: pixbuf is not in a friendly format, can n" \
"ot work with it");
		result = (guint) 0;
		return result;
	}
	i = (guint) 0;
	{
		gint yi;
		yi = y1;
		{
			gboolean _tmp4_;
			_tmp4_ = TRUE;
			while (TRUE) {
				if (!_tmp4_) {
					yi++;
				}
				_tmp4_ = FALSE;
				if (!(yi < y2)) {
					break;
				}
				{
					gint xi;
					xi = x1;
					{
						gboolean _tmp5_;
						_tmp5_ = TRUE;
						while (TRUE) {
							float pixel;
							if (!_tmp5_) {
								xi++;
							}
							_tmp5_ = FALSE;
							if (!(xi < x2)) {
								break;
							}
							pixel = pixels[(i + (xi * 4)) + 3] / 255.0f;
							if (pixel > threshold) {
								total_visible_pixels = total_visible_pixels + ((guint) 1);
							}
						}
					}
				}
				i = (guint) ((yi * (width * 4)) + rowstride);
			}
		}
	}
	result = total_visible_pixels;
	return result;
}


gboolean unity_pixbuf_is_tile (GdkPixbuf* source) {
	gboolean result = FALSE;
	gboolean is_tile;
	gint num_channels;
	gint width;
	gint height;
	guint total_visible_pixels;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	gint height_3;
	gint width_3;
	gint max_pixels;
	g_return_val_if_fail (source != NULL, FALSE);
	is_tile = FALSE;
	num_channels = gdk_pixbuf_get_n_channels (source);
	width = gdk_pixbuf_get_width (source);
	height = gdk_pixbuf_get_height (source);
	total_visible_pixels = (guint) 0;
	if (gdk_pixbuf_get_colorspace (source) != GDK_COLORSPACE_RGB) {
		_tmp2_ = TRUE;
	} else {
		_tmp2_ = gdk_pixbuf_get_bits_per_sample (source) != 8;
	}
	if (_tmp2_) {
		_tmp1_ = TRUE;
	} else {
		_tmp1_ = !gdk_pixbuf_get_has_alpha (source);
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = num_channels != 4;
	}
	if (_tmp0_) {
		g_warning ("icon-postprocessor.vala:176: pixbuf is not in a friendly format, can n" \
"ot work with it");
		result = FALSE;
		return result;
	}
	height_3 = height / 3;
	width_3 = width / 3;
	total_visible_pixels = unity_pixbuf_check_threshold (source, width_3, 0, width_3 * 2, 3, 0.1f);
	total_visible_pixels = total_visible_pixels + unity_pixbuf_check_threshold (source, width_3, height - 3, width_3 * 2, 3, 0.1f);
	total_visible_pixels = total_visible_pixels + unity_pixbuf_check_threshold (source, 0, height_3, 3, height_3 * 2, 0.1f);
	total_visible_pixels = total_visible_pixels + unity_pixbuf_check_threshold (source, width - 3, height_3, 3, height_3 * 2, 0.1f);
	max_pixels = ((width_3 * 6) + (height_3 * 6)) / 3;
	if ((total_visible_pixels / max_pixels) > 0.33333) {
		is_tile = TRUE;
	}
	result = is_tile;
	return result;
}


void unity_get_average_color (GdkPixbuf* source, guint* red, guint* green, guint* blue) {
	gint num_channels;
	gint width;
	gint height;
	gint rowstride;
	float r = 0.0F;
	float g = 0.0F;
	float b = 0.0F;
	float a = 0.0F;
	float hue = 0.0F;
	float sat = 0.0F;
	float val = 0.0F;
	gint pixels_length1;
	gint _pixels_size_;
	guchar* _tmp0_;
	guchar* pixels;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_ = FALSE;
	double r_total = 0.0;
	double g_total = 0.0;
	double b_total = 0.0;
	double rs_total = 0.0;
	double gs_total = 0.0;
	double bs_total = 0.0;
	gint i;
	guint total_caught_pixels;
	g_return_if_fail (source != NULL);
	num_channels = gdk_pixbuf_get_n_channels (source);
	width = gdk_pixbuf_get_width (source);
	height = gdk_pixbuf_get_height (source);
	rowstride = gdk_pixbuf_get_rowstride (source);
	pixels = (_tmp0_ = gdk_pixbuf_get_pixels (source), pixels_length1 = -1, _pixels_size_ = pixels_length1, _tmp0_);
	if (gdk_pixbuf_get_colorspace (source) != GDK_COLORSPACE_RGB) {
		_tmp3_ = TRUE;
	} else {
		_tmp3_ = gdk_pixbuf_get_bits_per_sample (source) != 8;
	}
	if (_tmp3_) {
		_tmp2_ = TRUE;
	} else {
		_tmp2_ = !gdk_pixbuf_get_has_alpha (source);
	}
	if (_tmp2_) {
		_tmp1_ = TRUE;
	} else {
		_tmp1_ = num_channels != 4;
	}
	if (_tmp1_) {
		*red = (guint) 255;
		*green = (guint) 255;
		*blue = (guint) 255;
		return;
	}
	r_total = g_total = b_total = 0.0;
	rs_total = gs_total = bs_total = 0.0;
	i = 0;
	total_caught_pixels = (guint) 1;
	{
		gint y;
		y = 0;
		{
			gboolean _tmp4_;
			_tmp4_ = TRUE;
			while (TRUE) {
				if (!_tmp4_) {
					y++;
				}
				_tmp4_ = FALSE;
				if (!(y < height)) {
					break;
				}
				{
					gint x;
					x = 0;
					{
						gboolean _tmp5_;
						_tmp5_ = TRUE;
						while (TRUE) {
							gint pix_index;
							if (!_tmp5_) {
								x++;
							}
							_tmp5_ = FALSE;
							if (!(x < width)) {
								break;
							}
							pix_index = i + (x * 4);
							r = pixels[pix_index + 0] / 255.0f;
							g = pixels[pix_index + 1] / 255.0f;
							b = pixels[pix_index + 2] / 255.0f;
							a = pixels[pix_index + 3] / 255.0f;
							if (a < 0.5) {
								continue;
							}
							unity_rgb_to_hsv (r, g, b, &hue, &sat, &val);
							rs_total = rs_total + ((double) r);
							gs_total = gs_total + ((double) g);
							bs_total = bs_total + ((double) b);
							if (sat <= 0.33) {
								continue;
							}
							r_total = r_total + ((double) r);
							g_total = g_total + ((double) g);
							b_total = b_total + ((double) b);
							total_caught_pixels = total_caught_pixels + ((guint) 1);
						}
					}
				}
				i = (y * (width * 4)) + rowstride;
			}
		}
	}
	r_total = r_total / MAX (total_caught_pixels, (guint) 1);
	g_total = g_total / MAX (total_caught_pixels, (guint) 1);
	b_total = b_total / MAX (total_caught_pixels, (guint) 1);
	rs_total = rs_total / (width * height);
	gs_total = gs_total / (width * height);
	bs_total = bs_total / (width * height);
	if (total_caught_pixels <= 20) {
		unity_rgb_to_hsv ((float) rs_total, (float) gs_total, (float) bs_total, &hue, &sat, &val);
		sat = 0.0f;
	} else {
		unity_rgb_to_hsv ((float) r_total, (float) g_total, (float) b_total, &hue, &sat, &val);
		sat = fminf (sat * 0.7f, 1.0f);
		val = fminf (val * 1.4f, 1.0f);
	}
	unity_hsv_to_rgb (hue, sat, val, &r, &g, &b);
	*red = (guint) (r * 255);
	*green = (guint) (g * 255);
	*blue = (guint) (b * 255);
}


UnityUnityIcon* unity_unity_icon_construct (GType object_type, ClutterTexture* icon, ClutterTexture* bg_tex) {
	UnityUnityIcon * self;
	self = (UnityUnityIcon*) g_object_new (object_type, "icon", icon, "bg-color", bg_tex, NULL);
	return self;
}


UnityUnityIcon* unity_unity_icon_new (ClutterTexture* icon, ClutterTexture* bg_tex) {
	return unity_unity_icon_construct (UNITY_TYPE_UNITY_ICON, icon, bg_tex);
}


static void unity_unity_icon_real_get_preferred_width (ClutterActor* base, float for_height, float* minimum_width, float* natural_width) {
	UnityUnityIcon * self;
	self = (UnityUnityIcon*) base;
	*natural_width = *minimum_width = (float) 50;
}


static void unity_unity_icon_real_get_preferred_height (ClutterActor* base, float for_width, float* minimum_height, float* natural_height) {
	UnityUnityIcon * self;
	self = (UnityUnityIcon*) base;
	*natural_height = *minimum_height = (float) 50;
}


static void unity_unity_icon_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
	UnityUnityIcon * self;
	self = (UnityUnityIcon*) base;
	CLUTTER_ACTOR_CLASS (unity_unity_icon_parent_class)->allocate ((ClutterActor*) CTK_ACTOR (self), box, flags);
	if (CLUTTER_IS_TEXTURE (self->priv->_icon)) {
		clutter_actor_allocate ((ClutterActor*) self->priv->_icon, box, flags);
	}
	if (CLUTTER_IS_TEXTURE (self->priv->_bg_color)) {
		clutter_actor_allocate ((ClutterActor*) self->priv->_bg_color, box, flags);
	}
}


static void unity_unity_icon_real_pick (ClutterActor* base, const ClutterColor* color) {
	UnityUnityIcon * self;
	CoglHandle* mat;
	self = (UnityUnityIcon*) base;
	ctk_actor_set_effects_painting ((CtkActor*) self, TRUE);
	mat = cogl_material_new ();
	CLUTTER_ACTOR_CLASS (unity_unity_icon_parent_class)->pick ((ClutterActor*) CTK_ACTOR (self), color);
	ctk_actor_set_effects_painting ((CtkActor*) self, FALSE);
	_cogl_handle_unref0 (mat);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void unity_unity_icon_paint_real (ClutterActor* actor) {
	ClutterActor* _tmp0_;
	UnityUnityIcon* _self_;
	float p1_x = 0.0F;
	float p1_y = 0.0F;
	float p2_x = 0.0F;
	float p2_y = 0.0F;
	float p3_x = 0.0F;
	float p3_y = 0.0F;
	float p4_x = 0.0F;
	float p4_y = 0.0F;
	float z = 0.0F;
	float w = 0.0F;
	ClutterActorBox box = {0};
	CoglMatrix modelview = {0};
	CoglMatrix projection = {0};
	CoglMatrix viewmatrix = {0};
	float base_z;
	gint points_length1;
	gint _points_size_;
	CoglTextureVertex* _tmp10_;
	CoglColor _tmp1_ = {0};
	CoglTextureVertex _tmp2_ = {0};
	CoglColor _tmp3_ = {0};
	CoglTextureVertex _tmp4_ = {0};
	CoglColor _tmp5_ = {0};
	CoglTextureVertex _tmp6_ = {0};
	CoglColor _tmp7_ = {0};
	CoglTextureVertex _tmp8_ = {0};
	CoglTextureVertex* _tmp9_ = NULL;
	CoglTextureVertex* points;
	guchar opacity;
	g_return_if_fail (actor != NULL);
	_self_ = _g_object_ref0 ((_tmp0_ = actor, UNITY_IS_UNITY_ICON (_tmp0_) ? ((UnityUnityIcon*) _tmp0_) : NULL));
	memset (&box, 0, sizeof (ClutterActorBox));
	ctk_actor_get_stored_allocation ((CtkActor*) _self_, &box);
	cogl_matrix_init_identity (&modelview);
	cogl_matrix_init_identity (&projection);
	cogl_matrix_perspective (&projection, 45.0f, 1.0f, 0.1f, 100.0f);
	cogl_matrix_translate (&modelview, 0.0f, 0.0f, (-59.5f) - (fabsf (_self_->priv->_rotation / 360.0f) * 100));
	cogl_matrix_rotate (&modelview, _self_->priv->_rotation, 1.0f, 0.0f, 0.0f);
	cogl_matrix_multiply (&viewmatrix, &projection, &modelview);
	base_z = -((fabsf (_self_->priv->_rotation) / 90.0f) * 15.0f);
	p1_x = -25.0f;
	p1_y = -25.0f;
	p2_x = 25.0f;
	p2_y = -25.0f;
	p3_x = 25.0f;
	p3_y = 25.0f;
	p4_x = -25.0f;
	p4_y = 25.0f;
	z = base_z;
	w = 1.0f;
	cogl_matrix_transform_point (&viewmatrix, &p1_x, &p1_y, &z, &w);
	p1_x = p1_x / w;
	p1_y = p1_y / w;
	z = base_z;
	w = 1.0f;
	cogl_matrix_transform_point (&viewmatrix, &p2_x, &p2_y, &z, &w);
	p2_x = p2_x / w;
	p2_y = p2_y / w;
	z = base_z;
	w = 1.0f;
	cogl_matrix_transform_point (&viewmatrix, &p3_x, &p3_y, &z, &w);
	p3_x = p3_x / w;
	p3_y = p3_y / w;
	z = base_z;
	w = 1.0f;
	cogl_matrix_transform_point (&viewmatrix, &p4_x, &p4_y, &z, &w);
	p4_x = p4_x / w;
	p4_y = p4_y / w;
	z = base_z;
	w = 1.0f;
	p1_x = (50 * (p1_x + 1)) / 2;
	p1_y = 48 + ((50 * (p1_y - 1)) / 2);
	p2_x = (50 * (p2_x + 1)) / 2;
	p2_y = 48 + ((50 * (p2_y - 1)) / 2);
	p3_x = (50 * (p3_x + 1)) / 2;
	p3_y = 48 + ((50 * (p3_y - 1)) / 2);
	p4_x = (50 * (p4_x + 1)) / 2;
	p4_y = 48 + ((50 * (p4_y - 1)) / 2);
	if (fabsf (_self_->priv->_rotation) <= 1.0) {
		p1_x = ceilf (p1_x);
		p1_y = ceilf (p1_y);
		p2_x = floorf (p2_x);
		p2_y = ceilf (p2_y);
		p3_x = floorf (p3_x);
		p3_y = floorf (p3_y);
		p4_x = ceilf (p4_x);
		p4_y = floorf (p4_y);
	}
	_self_->stored_height = p3_y - p1_y;
	_self_->stored_ymod = (50 - _self_->stored_height) / 2.0f;
	points = (_tmp10_ = (_tmp9_ = g_new0 (CoglTextureVertex, 4), _tmp9_[0] = (memset (&_tmp2_, 0, sizeof (CoglTextureVertex)), _tmp2_.x = p1_x, _tmp2_.y = p1_y, _tmp2_.z = 0.0f, _tmp2_.tx = 0.0f, _tmp2_.ty = 0.0f, _tmp2_.color = (memset (&_tmp1_, 0, sizeof (CoglColor)), _tmp1_.red = (guchar) 0xff, _tmp1_.green = (guchar) 0xff, _tmp1_.blue = (guchar) 0xff, _tmp1_.alpha = (guchar) 0xff, _tmp1_), _tmp2_), _tmp9_[1] = (memset (&_tmp4_, 0, sizeof (CoglTextureVertex)), _tmp4_.x = p2_x, _tmp4_.y = p2_y, _tmp4_.z = 0.0f, _tmp4_.tx = 1.0f, _tmp4_.ty = 0.0f, _tmp4_.color = (memset (&_tmp3_, 0, sizeof (CoglColor)), _tmp3_.red = (guchar) 0xff, _tmp3_.green = (guchar) 0xff, _tmp3_.blue = (guchar) 0xff, _tmp3_.alpha = (guchar) 0xff, _tmp3_), _tmp4_), _tmp9_[2] = (memset (&_tmp6_, 0, sizeof (CoglTextureVertex)), _tmp6_.x = p3_x, _tmp6_.y = p3_y, _tmp6_.z = 0.0f, _tmp6_.tx = 1.0f, _tmp6_.ty = 1.0f, _tmp6_.color = (memset (&_tmp5_, 0, sizeof (CoglColor)), _tmp5_.red = (guchar) 0xff, _tmp5_.green = (guchar) 0xff, _tmp5_.blue = (guchar) 0xff, _tmp5_.alpha = (guchar) 0xff, _tmp5_), _tmp6_), _tmp9_[3] = (memset (&_tmp8_, 0, sizeof (CoglTextureVertex)), _tmp8_.x = p4_x, _tmp8_.y = p4_y, _tmp8_.z = 0.0f, _tmp8_.tx = 0.0f, _tmp8_.ty = 1.0f, _tmp8_.color = (memset (&_tmp7_, 0, sizeof (CoglColor)), _tmp7_.red = (guchar) 0xff, _tmp7_.green = (guchar) 0xff, _tmp7_.blue = (guchar) 0xff, _tmp7_.alpha = (guchar) 0xff, _tmp7_), _tmp8_), _tmp9_), points_length1 = 4, _points_size_ = points_length1, _tmp10_);
	opacity = (guchar) clutter_actor_get_opacity ((ClutterActor*) _self_);
	cogl_material_set_color4ub (_self_->priv->bg_mat, opacity, opacity, opacity, opacity);
	cogl_material_set_color4ub (_self_->priv->bgcol_material, opacity, opacity, opacity, opacity);
	cogl_material_set_color4ub (_self_->priv->icon_material, opacity, opacity, opacity, opacity);
	cogl_material_set_color4ub (_self_->priv->fg_mat, opacity, opacity, opacity, opacity);
	if (CLUTTER_IS_TEXTURE (_self_->priv->_bg_color)) {
		cogl_set_source (_self_->priv->bgcol_material);
		cogl_polygon (points, points_length1, TRUE);
	} else {
		cogl_set_source (_self_->priv->bg_mat);
		cogl_polygon (points, points_length1, TRUE);
	}
	if (CLUTTER_IS_TEXTURE (_self_->priv->_icon)) {
		gint base_width = 0;
		gint base_height = 0;
		float xpad = 0.0F;
		float ypad = 0.0F;
		gint icon_points_length1;
		gint _icon_points_size_;
		CoglTextureVertex* _tmp20_;
		CoglColor _tmp11_ = {0};
		CoglTextureVertex _tmp12_ = {0};
		CoglColor _tmp13_ = {0};
		CoglTextureVertex _tmp14_ = {0};
		CoglColor _tmp15_ = {0};
		CoglTextureVertex _tmp16_ = {0};
		CoglColor _tmp17_ = {0};
		CoglTextureVertex _tmp18_ = {0};
		CoglTextureVertex* _tmp19_ = NULL;
		CoglTextureVertex* icon_points;
		gint width = 0;
		gint height = 0;
		clutter_texture_get_base_size (_self_->priv->_icon, &base_width, &base_height);
		xpad = 1 + ((clutter_actor_box_get_width (&box) - base_width) / 2.0f);
		ypad = ((clutter_actor_box_get_height (&box) - base_height) / 2.0f) - 1;
		p1_x = -25.0f;
		p1_y = -25.0f;
		p2_x = 25.0f;
		p2_y = -25.0f;
		p3_x = 25.0f;
		p3_y = 25.0f;
		p4_x = -25.0f;
		p4_y = 25.0f;
		z = base_z;
		w = 1.0f;
		cogl_matrix_transform_point (&viewmatrix, &p1_x, &p1_y, &z, &w);
		p1_x = p1_x / w;
		p1_y = p1_y / w;
		z = base_z;
		w = 1.0f;
		cogl_matrix_transform_point (&viewmatrix, &p2_x, &p2_y, &z, &w);
		p2_x = p2_x / w;
		p2_y = p2_y / w;
		z = base_z;
		w = 1.0f;
		cogl_matrix_transform_point (&viewmatrix, &p3_x, &p3_y, &z, &w);
		p3_x = p3_x / w;
		p3_y = p3_y / w;
		z = base_z;
		w = 1.0f;
		cogl_matrix_transform_point (&viewmatrix, &p4_x, &p4_y, &z, &w);
		p4_x = p4_x / w;
		p4_y = p4_y / w;
		z = base_z;
		w = 1.0f;
		p1_x = xpad + ((base_width * (p1_x + 1)) / 2);
		p1_y = (48 - ypad) + ((base_height * (p1_y - 1)) / 2);
		p2_x = xpad + ((base_width * (p2_x + 1)) / 2);
		p2_y = (48 - ypad) + ((base_height * (p2_y - 1)) / 2);
		p3_x = xpad + ((base_width * (p3_x + 1)) / 2);
		p3_y = (48 - ypad) + ((base_height * (p3_y - 1)) / 2);
		p4_x = xpad + ((base_width * (p4_x + 1)) / 2);
		p4_y = (48 - ypad) + ((base_height * (p4_y - 1)) / 2);
		if (fabsf (_self_->priv->_rotation) <= 1.0) {
			p1_x = ceilf (p1_x);
			p1_y = ceilf (p1_y);
			p2_x = floorf (p2_x);
			p2_y = ceilf (p2_y);
			p3_x = floorf (p3_x);
			p3_y = floorf (p3_y);
			p4_x = ceilf (p4_x);
			p4_y = floorf (p4_y);
		}
		icon_points = (_tmp20_ = (_tmp19_ = g_new0 (CoglTextureVertex, 4), _tmp19_[0] = (memset (&_tmp12_, 0, sizeof (CoglTextureVertex)), _tmp12_.x = p1_x, _tmp12_.y = p1_y, _tmp12_.z = 0.0f, _tmp12_.tx = 0.0f, _tmp12_.ty = 0.0f, _tmp12_.color = (memset (&_tmp11_, 0, sizeof (CoglColor)), _tmp11_.red = (guchar) 0xff, _tmp11_.green = (guchar) 0xff, _tmp11_.blue = (guchar) 0xff, _tmp11_.alpha = (guchar) 0xff, _tmp11_), _tmp12_), _tmp19_[1] = (memset (&_tmp14_, 0, sizeof (CoglTextureVertex)), _tmp14_.x = p2_x, _tmp14_.y = p2_y, _tmp14_.z = 0.0f, _tmp14_.tx = 1.0f, _tmp14_.ty = 0.0f, _tmp14_.color = (memset (&_tmp13_, 0, sizeof (CoglColor)), _tmp13_.red = (guchar) 0xff, _tmp13_.green = (guchar) 0xff, _tmp13_.blue = (guchar) 0xff, _tmp13_.alpha = (guchar) 0xff, _tmp13_), _tmp14_), _tmp19_[2] = (memset (&_tmp16_, 0, sizeof (CoglTextureVertex)), _tmp16_.x = p3_x, _tmp16_.y = p3_y, _tmp16_.z = 0.0f, _tmp16_.tx = 1.0f, _tmp16_.ty = 1.0f, _tmp16_.color = (memset (&_tmp15_, 0, sizeof (CoglColor)), _tmp15_.red = (guchar) 0xff, _tmp15_.green = (guchar) 0xff, _tmp15_.blue = (guchar) 0xff, _tmp15_.alpha = (guchar) 0xff, _tmp15_), _tmp16_), _tmp19_[3] = (memset (&_tmp18_, 0, sizeof (CoglTextureVertex)), _tmp18_.x = p4_x, _tmp18_.y = p4_y, _tmp18_.z = 0.0f, _tmp18_.tx = 0.0f, _tmp18_.ty = 1.0f, _tmp18_.color = (memset (&_tmp17_, 0, sizeof (CoglColor)), _tmp17_.red = (guchar) 0xff, _tmp17_.green = (guchar) 0xff, _tmp17_.blue = (guchar) 0xff, _tmp17_.alpha = (guchar) 0xff, _tmp17_), _tmp18_), _tmp19_), icon_points_length1 = 4, _icon_points_size_ = icon_points_length1, _tmp20_);
		clutter_texture_get_base_size (_self_->priv->_icon, &width, &height);
		xpad = (clutter_actor_box_get_width (&box) - width) / 2.0f;
		ypad = (clutter_actor_box_get_height (&box) - height) / 2.0f;
		cogl_set_source (_self_->priv->icon_material);
		cogl_polygon (icon_points, icon_points_length1, TRUE);
		icon_points = (g_free (icon_points), NULL);
	}
	cogl_set_source (_self_->priv->fg_mat);
	cogl_polygon (points, points_length1, TRUE);
	points = (g_free (points), NULL);
	_g_object_unref0 (_self_);
}


static void _unity_unity_icon_paint_real_ctk_effect_paint_func (ClutterActor* actor) {
	unity_unity_icon_paint_real (actor);
}


static void unity_unity_icon_real_paint (ClutterActor* base) {
	UnityUnityIcon * self;
	GSList* effects;
	gboolean _tmp0_ = FALSE;
	self = (UnityUnityIcon*) base;
	effects = ctk_actor_get_effects ((CtkActor*) self);
	if (!ctk_actor_get_effects_painting ((CtkActor*) self)) {
		_tmp0_ = effects != NULL;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		GSList* e;
		e = NULL;
		ctk_actor_set_effects_painting ((CtkActor*) self, TRUE);
		{
			gboolean _tmp1_;
			e = effects;
			_tmp1_ = TRUE;
			while (TRUE) {
				CtkEffect* effect;
				gboolean _tmp2_ = FALSE;
				gboolean last_effect;
				if (!_tmp1_) {
					e = e->next;
				}
				_tmp1_ = FALSE;
				if (!(e != NULL)) {
					break;
				}
				effect = _g_object_ref0 ((CtkEffect*) e->data);
				if (e->next != NULL) {
					_tmp2_ = FALSE;
				} else {
					_tmp2_ = TRUE;
				}
				last_effect = _tmp2_;
				ctk_effect_paint (effect, _unity_unity_icon_paint_real_ctk_effect_paint_func, last_effect);
				_g_object_unref0 (effect);
			}
		}
		ctk_actor_set_effects_painting ((CtkActor*) self, FALSE);
	} else {
		unity_unity_icon_paint_real ((ClutterActor*) self);
	}
}


static void unity_unity_icon_real_map (ClutterActor* base) {
	UnityUnityIcon * self;
	self = (UnityUnityIcon*) base;
	CLUTTER_ACTOR_CLASS (unity_unity_icon_parent_class)->map ((ClutterActor*) CTK_ACTOR (self));
	if (CLUTTER_IS_ACTOR (self->priv->_icon)) {
		clutter_actor_map ((ClutterActor*) self->priv->_icon);
	}
}


static void unity_unity_icon_real_unmap (ClutterActor* base) {
	UnityUnityIcon * self;
	self = (UnityUnityIcon*) base;
	CLUTTER_ACTOR_CLASS (unity_unity_icon_parent_class)->unmap ((ClutterActor*) CTK_ACTOR (self));
	clutter_actor_unmap ((ClutterActor*) self->priv->_icon);
}


ClutterTexture* unity_unity_icon_get_icon (UnityUnityIcon* self) {
	ClutterTexture* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_icon;
	return result;
}


static void unity_unity_icon_set_icon (UnityUnityIcon* self, ClutterTexture* value) {
	ClutterTexture* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_icon = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_icon), _tmp0_);
	g_object_notify ((GObject *) self, "icon");
}


ClutterTexture* unity_unity_icon_get_bg_color (UnityUnityIcon* self) {
	ClutterTexture* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_bg_color;
	return result;
}


static void unity_unity_icon_set_bg_color (UnityUnityIcon* self, ClutterTexture* value) {
	ClutterTexture* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_bg_color = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_bg_color), _tmp0_);
	g_object_notify ((GObject *) self, "bg-color");
}


float unity_unity_icon_get_rotation (UnityUnityIcon* self) {
	float result;
	g_return_val_if_fail (self != NULL, 0.0F);
	result = self->priv->_rotation;
	return result;
}


void unity_unity_icon_set_rotation (UnityUnityIcon* self, float value) {
	g_return_if_fail (self != NULL);
	self->priv->_rotation = value;
	g_object_notify ((GObject *) self, "rotation");
}


static gpointer _cogl_handle_ref0 (gpointer self) {
	return self ? cogl_handle_ref (self) : NULL;
}


static void _lambda1_ (UnityUnityIcon* self) {
	clutter_actor_queue_relayout ((ClutterActor*) self);
}


static void __lambda1__g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self) {
	_lambda1_ (self);
}


static GObject * unity_unity_icon_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityUnityIcon * self;
	parent_class = G_OBJECT_CLASS (unity_unity_icon_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_UNITY_ICON (obj);
	{
		CoglHandle* _tmp0_;
		CoglHandle* _tmp1_;
		CoglHandle* mat;
		CoglHandle* tex;
		CoglHandle* _tmp7_;
		CoglHandle* _tmp8_;
		CoglHandle* _tmp9_;
		CoglHandle* _tmp10_;
		self->priv->icon_material = (_tmp0_ = cogl_material_new (), _cogl_handle_unref0 (self->priv->icon_material), _tmp0_);
		self->priv->bgcol_material = (_tmp1_ = cogl_material_new (), _cogl_handle_unref0 (self->priv->bgcol_material), _tmp1_);
		if (!CLUTTER_IS_TEXTURE (unity_unity_icon_bg_layer)) {
			ClutterTexture* _tmp2_;
			ClutterTexture* _tmp3_;
			ClutterTexture* _tmp4_;
			unity_unity_icon_bg_layer = (_tmp2_ = (ClutterTexture*) g_object_ref_sink (unity_theme_image_new ("prism_icon_background")), _g_object_unref0 (unity_unity_icon_bg_layer), _tmp2_);
			unity_unity_icon_fg_layer = (_tmp3_ = (ClutterTexture*) g_object_ref_sink (unity_theme_image_new ("prism_icon_foreground")), _g_object_unref0 (unity_unity_icon_fg_layer), _tmp3_);
			unity_unity_icon_mk_layer = (_tmp4_ = (ClutterTexture*) g_object_ref_sink (unity_theme_image_new ("prism_icon_mask")), _g_object_unref0 (unity_unity_icon_mk_layer), _tmp4_);
		}
		if (CLUTTER_IS_TEXTURE (self->priv->_icon)) {
			CoglHandle* icon_mat;
			CoglHandle* icon_tex;
			CoglHandle* mask_tex;
			CoglHandle* _tmp5_;
			clutter_actor_set_parent ((ClutterActor*) self->priv->_icon, (ClutterActor*) self);
			icon_mat = cogl_material_new ();
			icon_tex = (CoglHandle*) clutter_texture_get_cogl_texture (self->priv->_icon);
			mask_tex = (CoglHandle*) clutter_texture_get_cogl_texture (unity_unity_icon_mk_layer);
			cogl_material_set_layer (icon_mat, 0, icon_tex);
			cogl_material_set_layer_filters (icon_mat, 1, COGL_MATERIAL_FILTER_LINEAR, COGL_MATERIAL_FILTER_LINEAR);
			cogl_material_set_layer (icon_mat, 1, mask_tex);
			self->priv->icon_material = (_tmp5_ = _cogl_handle_ref0 (icon_mat), _cogl_handle_unref0 (self->priv->icon_material), _tmp5_);
			_cogl_handle_unref0 (mask_tex);
			_cogl_handle_unref0 (icon_tex);
			_cogl_handle_unref0 (icon_mat);
		}
		if (CLUTTER_IS_TEXTURE (self->priv->_bg_color)) {
			CoglHandle* _tmp6_;
			CoglHandle* color;
			CoglHandle* mask_tex;
			clutter_actor_set_parent ((ClutterActor*) self->priv->_bg_color, (ClutterActor*) self);
			self->priv->bgcol_material = (_tmp6_ = cogl_material_new (), _cogl_handle_unref0 (self->priv->bgcol_material), _tmp6_);
			color = (CoglHandle*) clutter_texture_get_cogl_texture (self->priv->_bg_color);
			mask_tex = (CoglHandle*) clutter_texture_get_cogl_texture (unity_unity_icon_mk_layer);
			cogl_material_set_layer (self->priv->bgcol_material, 0, color);
			cogl_material_set_layer_filters (self->priv->bgcol_material, 1, COGL_MATERIAL_FILTER_LINEAR, COGL_MATERIAL_FILTER_LINEAR);
			cogl_material_set_layer (self->priv->bgcol_material, 1, mask_tex);
			_cogl_handle_unref0 (mask_tex);
			_cogl_handle_unref0 (color);
		}
		mat = cogl_material_new ();
		tex = (CoglHandle*) clutter_texture_get_cogl_texture (unity_unity_icon_bg_layer);
		cogl_material_set_layer (mat, 0, tex);
		self->priv->bg_mat = (_tmp7_ = _cogl_handle_ref0 (mat), _cogl_handle_unref0 (self->priv->bg_mat), _tmp7_);
		mat = (_tmp8_ = cogl_material_new (), _cogl_handle_unref0 (mat), _tmp8_);
		tex = (_tmp9_ = (CoglHandle*) clutter_texture_get_cogl_texture (unity_unity_icon_fg_layer), _cogl_handle_unref0 (tex), _tmp9_);
		cogl_material_set_layer (mat, 0, tex);
		self->priv->fg_mat = (_tmp10_ = _cogl_handle_ref0 (mat), _cogl_handle_unref0 (self->priv->fg_mat), _tmp10_);
		g_signal_connect_object ((GObject*) self, "notify::rotation", (GCallback) __lambda1__g_object_notify, self, 0);
		self->stored_height = (float) 48;
		_cogl_handle_unref0 (tex);
		_cogl_handle_unref0 (mat);
	}
	return obj;
}


static void unity_unity_icon_class_init (UnityUnityIconClass * klass) {
	unity_unity_icon_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityUnityIconPrivate));
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_width = unity_unity_icon_real_get_preferred_width;
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_height = unity_unity_icon_real_get_preferred_height;
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_unity_icon_real_allocate;
	CLUTTER_ACTOR_CLASS (klass)->pick = unity_unity_icon_real_pick;
	CLUTTER_ACTOR_CLASS (klass)->paint = unity_unity_icon_real_paint;
	CLUTTER_ACTOR_CLASS (klass)->map = unity_unity_icon_real_map;
	CLUTTER_ACTOR_CLASS (klass)->unmap = unity_unity_icon_real_unmap;
	G_OBJECT_CLASS (klass)->get_property = unity_unity_icon_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_unity_icon_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_unity_icon_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_unity_icon_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_UNITY_ICON_ICON, g_param_spec_object ("icon", "icon", "icon", CLUTTER_TYPE_TEXTURE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_UNITY_ICON_BG_COLOR, g_param_spec_object ("bg-color", "bg-color", "bg-color", CLUTTER_TYPE_TEXTURE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_UNITY_ICON_ROTATION, g_param_spec_float ("rotation", "rotation", "rotation", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void unity_unity_icon_instance_init (UnityUnityIcon * self) {
	self->priv = UNITY_UNITY_ICON_GET_PRIVATE (self);
	self->stored_height = (float) 0;
	self->stored_ymod = (float) 0;
}


static void unity_unity_icon_finalize (GObject* obj) {
	UnityUnityIcon * self;
	self = UNITY_UNITY_ICON (obj);
	_g_object_unref0 (self->priv->_icon);
	_g_object_unref0 (self->priv->_bg_color);
	_cogl_handle_unref0 (self->priv->bg_mat);
	_cogl_handle_unref0 (self->priv->fg_mat);
	_cogl_handle_unref0 (self->priv->icon_material);
	_cogl_handle_unref0 (self->priv->bgcol_material);
	G_OBJECT_CLASS (unity_unity_icon_parent_class)->finalize (obj);
}


GType unity_unity_icon_get_type (void) {
	static volatile gsize unity_unity_icon_type_id__volatile = 0;
	if (g_once_init_enter (&unity_unity_icon_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityUnityIconClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_unity_icon_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityUnityIcon), 0, (GInstanceInitFunc) unity_unity_icon_instance_init, NULL };
		GType unity_unity_icon_type_id;
		unity_unity_icon_type_id = g_type_register_static (CTK_TYPE_ACTOR, "UnityUnityIcon", &g_define_type_info, 0);
		g_once_init_leave (&unity_unity_icon_type_id__volatile, unity_unity_icon_type_id);
	}
	return unity_unity_icon_type_id__volatile;
}


static void unity_unity_icon_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityUnityIcon * self;
	self = UNITY_UNITY_ICON (object);
	switch (property_id) {
		case UNITY_UNITY_ICON_ICON:
		g_value_set_object (value, unity_unity_icon_get_icon (self));
		break;
		case UNITY_UNITY_ICON_BG_COLOR:
		g_value_set_object (value, unity_unity_icon_get_bg_color (self));
		break;
		case UNITY_UNITY_ICON_ROTATION:
		g_value_set_float (value, unity_unity_icon_get_rotation (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_unity_icon_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityUnityIcon * self;
	self = UNITY_UNITY_ICON (object);
	switch (property_id) {
		case UNITY_UNITY_ICON_ICON:
		unity_unity_icon_set_icon (self, g_value_get_object (value));
		break;
		case UNITY_UNITY_ICON_BG_COLOR:
		unity_unity_icon_set_bg_color (self, g_value_get_object (value));
		break;
		case UNITY_UNITY_ICON_ROTATION:
		unity_unity_icon_set_rotation (self, g_value_get_float (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




