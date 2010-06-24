/* unity-cairo-canvas.c generated by valac, the Vala compiler
 * generated from unity-cairo-canvas.vala, do not modify */

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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <clutk/clutk.h>
#include <clutter/clutter.h>
#include <cairo.h>


#define UNITY_TYPE_CAIRO_CANVAS (unity_cairo_canvas_get_type ())
#define UNITY_CAIRO_CANVAS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_CAIRO_CANVAS, UnityCairoCanvas))
#define UNITY_CAIRO_CANVAS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_CAIRO_CANVAS, UnityCairoCanvasClass))
#define UNITY_IS_CAIRO_CANVAS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_CAIRO_CANVAS))
#define UNITY_IS_CAIRO_CANVAS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_CAIRO_CANVAS))
#define UNITY_CAIRO_CANVAS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_CAIRO_CANVAS, UnityCairoCanvasClass))

typedef struct _UnityCairoCanvas UnityCairoCanvas;
typedef struct _UnityCairoCanvasClass UnityCairoCanvasClass;
typedef struct _UnityCairoCanvasPrivate UnityCairoCanvasPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _cairo_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_destroy (var), NULL)))

struct _UnityCairoCanvas {
	CtkBin parent_instance;
	UnityCairoCanvasPrivate * priv;
	ClutterCairoTexture* texture;
};

struct _UnityCairoCanvasClass {
	CtkBinClass parent_class;
};

typedef void (*UnityCairoCanvasCairoCanvasPaint) (cairo_t* cr, gint width, gint height, void* user_data);
struct _UnityCairoCanvasPrivate {
	gint last_width;
	gint last_height;
	UnityCairoCanvasCairoCanvasPaint paint_func;
	gpointer paint_func_target;
	GDestroyNotify paint_func_target_destroy_notify;
};


static gpointer unity_cairo_canvas_parent_class = NULL;

GType unity_cairo_canvas_get_type (void);
#define UNITY_CAIRO_CANVAS_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TYPE_CAIRO_CANVAS, UnityCairoCanvasPrivate))
enum  {
	UNITY_CAIRO_CANVAS_DUMMY_PROPERTY
};
UnityCairoCanvas* unity_cairo_canvas_new (UnityCairoCanvasCairoCanvasPaint _func, void* _func_target);
UnityCairoCanvas* unity_cairo_canvas_construct (GType object_type, UnityCairoCanvasCairoCanvasPaint _func, void* _func_target);
static gboolean unity_cairo_canvas_update_background (UnityCairoCanvas* self);
static gboolean _unity_cairo_canvas_update_background_gsource_func (gpointer self);
static void unity_cairo_canvas_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
void unity_cairo_canvas_update (UnityCairoCanvas* self);
static GObject * unity_cairo_canvas_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_cairo_canvas_finalize (GObject* obj);



UnityCairoCanvas* unity_cairo_canvas_construct (GType object_type, UnityCairoCanvasCairoCanvasPaint _func, void* _func_target) {
	UnityCairoCanvas * self;
	UnityCairoCanvasCairoCanvasPaint _tmp0_;
	self = (UnityCairoCanvas*) g_object_new (object_type, NULL);
	self->priv->paint_func = (_tmp0_ = _func, ((self->priv->paint_func_target_destroy_notify == NULL) ? NULL : (self->priv->paint_func_target_destroy_notify (self->priv->paint_func_target), NULL), self->priv->paint_func = NULL, self->priv->paint_func_target = NULL, self->priv->paint_func_target_destroy_notify = NULL), self->priv->paint_func_target = _func_target, self->priv->paint_func_target_destroy_notify = NULL, _tmp0_);
	return self;
}


UnityCairoCanvas* unity_cairo_canvas_new (UnityCairoCanvasCairoCanvasPaint _func, void* _func_target) {
	return unity_cairo_canvas_construct (UNITY_TYPE_CAIRO_CANVAS, _func, _func_target);
}


static gboolean _unity_cairo_canvas_update_background_gsource_func (gpointer self) {
	gboolean result;
	result = unity_cairo_canvas_update_background (self);
	return result;
}


static void unity_cairo_canvas_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
	UnityCairoCanvas * self;
	gint width;
	gint height;
	gboolean _tmp0_ = FALSE;
	self = (UnityCairoCanvas*) base;
	width = (gint) ((*box).x2 - (*box).x1);
	height = (gint) ((*box).y2 - (*box).y1);
	CLUTTER_ACTOR_CLASS (unity_cairo_canvas_parent_class)->allocate ((ClutterActor*) CTK_BIN (self), box, flags);
	if (width != self->priv->last_width) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = height != self->priv->last_height;
	}
	if (_tmp0_) {
		self->priv->last_width = width;
		self->priv->last_height = height;
		g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 0, _unity_cairo_canvas_update_background_gsource_func, g_object_ref (self), g_object_unref);
	}
}


static gboolean unity_cairo_canvas_update_background (UnityCairoCanvas* self) {
	gboolean result = FALSE;
	cairo_t* cr;
	gboolean _tmp0_ = FALSE;
	cairo_t* _tmp1_;
	GSList* effects;
	g_return_val_if_fail (self != NULL, FALSE);
	cr = NULL;
	if (self->priv->last_width < 1) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = self->priv->last_height < 1;
	}
	if (_tmp0_) {
		result = FALSE;
		_cairo_destroy0 (cr);
		return result;
	}
	clutter_cairo_texture_set_surface_size (self->texture, (guint) self->priv->last_width, (guint) self->priv->last_height);
	cr = (_tmp1_ = clutter_cairo_texture_create (self->texture), _cairo_destroy0 (cr), _tmp1_);
	self->priv->paint_func (cr, self->priv->last_width, self->priv->last_height, self->priv->paint_func_target);
	effects = ctk_actor_get_effects ((CtkActor*) self);
	{
		GSList* effect_collection;
		GSList* effect_it;
		effect_collection = effects;
		for (effect_it = effect_collection; effect_it != NULL; effect_it = effect_it->next) {
			CtkEffect* effect;
			effect = (CtkEffect*) effect_it->data;
			{
				ctk_effect_set_invalidate_effect_cache (effect, TRUE);
			}
		}
	}
	result = FALSE;
	_cairo_destroy0 (cr);
	return result;
}


void unity_cairo_canvas_update (UnityCairoCanvas* self) {
	g_return_if_fail (self != NULL);
	unity_cairo_canvas_update_background (self);
}


static GObject * unity_cairo_canvas_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityCairoCanvas * self;
	parent_class = G_OBJECT_CLASS (unity_cairo_canvas_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_CAIRO_CANVAS (obj);
	{
		ClutterCairoTexture* _tmp0_;
		self->texture = (_tmp0_ = g_object_ref_sink ((ClutterCairoTexture*) clutter_cairo_texture_new ((guint) 10, (guint) 10)), _g_object_unref0 (self->texture), _tmp0_);
		clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) self->texture);
		clutter_actor_show ((ClutterActor*) self->texture);
	}
	return obj;
}


static void unity_cairo_canvas_class_init (UnityCairoCanvasClass * klass) {
	unity_cairo_canvas_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityCairoCanvasPrivate));
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_cairo_canvas_real_allocate;
	G_OBJECT_CLASS (klass)->constructor = unity_cairo_canvas_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_cairo_canvas_finalize;
}


static void unity_cairo_canvas_instance_init (UnityCairoCanvas * self) {
	self->priv = UNITY_CAIRO_CANVAS_GET_PRIVATE (self);
	self->priv->last_width = 0;
	self->priv->last_height = 0;
}


static void unity_cairo_canvas_finalize (GObject* obj) {
	UnityCairoCanvas * self;
	self = UNITY_CAIRO_CANVAS (obj);
	_g_object_unref0 (self->texture);
	(self->priv->paint_func_target_destroy_notify == NULL) ? NULL : (self->priv->paint_func_target_destroy_notify (self->priv->paint_func_target), NULL);
	self->priv->paint_func = NULL;
	self->priv->paint_func_target = NULL;
	self->priv->paint_func_target_destroy_notify = NULL;
	G_OBJECT_CLASS (unity_cairo_canvas_parent_class)->finalize (obj);
}


GType unity_cairo_canvas_get_type (void) {
	static volatile gsize unity_cairo_canvas_type_id__volatile = 0;
	if (g_once_init_enter (&unity_cairo_canvas_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityCairoCanvasClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_cairo_canvas_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityCairoCanvas), 0, (GInstanceInitFunc) unity_cairo_canvas_instance_init, NULL };
		GType unity_cairo_canvas_type_id;
		unity_cairo_canvas_type_id = g_type_register_static (CTK_TYPE_BIN, "UnityCairoCanvas", &g_define_type_info, 0);
		g_once_init_leave (&unity_cairo_canvas_type_id__volatile, unity_cairo_canvas_type_id);
	}
	return unity_cairo_canvas_type_id__volatile;
}




