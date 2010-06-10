/* places-view.c generated by valac, the Vala compiler
 * generated from places-view.vala, do not modify */

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
 * Authored by Mirco "MacSlow" Müller <mirco.mueller@canonical.com>
 *             Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <clutk/clutk.h>
#include <unity.h>
#include <clutter/clutter.h>
#include <float.h>
#include <math.h>


#define UNITY_PLACES_TYPE_VIEW (unity_places_view_get_type ())
#define UNITY_PLACES_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_VIEW, UnityPlacesView))
#define UNITY_PLACES_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_VIEW, UnityPlacesViewClass))
#define UNITY_PLACES_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_VIEW))
#define UNITY_PLACES_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_VIEW))
#define UNITY_PLACES_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_VIEW, UnityPlacesViewClass))

typedef struct _UnityPlacesView UnityPlacesView;
typedef struct _UnityPlacesViewClass UnityPlacesViewClass;
typedef struct _UnityPlacesViewPrivate UnityPlacesViewPrivate;

#define UNITY_PLACES_TYPE_MODEL (unity_places_model_get_type ())
#define UNITY_PLACES_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_MODEL, UnityPlacesModel))
#define UNITY_PLACES_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_MODEL, UnityPlacesModelClass))
#define UNITY_PLACES_IS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_MODEL))
#define UNITY_PLACES_IS_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_MODEL))
#define UNITY_PLACES_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_MODEL, UnityPlacesModelClass))

typedef struct _UnityPlacesModel UnityPlacesModel;
typedef struct _UnityPlacesModelClass UnityPlacesModelClass;

#define UNITY_PLACES_BAR_TYPE_VIEW (unity_places_bar_view_get_type ())
#define UNITY_PLACES_BAR_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_BAR_TYPE_VIEW, UnityPlacesBarView))
#define UNITY_PLACES_BAR_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_BAR_TYPE_VIEW, UnityPlacesBarViewClass))
#define UNITY_PLACES_BAR_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_BAR_TYPE_VIEW))
#define UNITY_PLACES_BAR_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_BAR_TYPE_VIEW))
#define UNITY_PLACES_BAR_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_BAR_TYPE_VIEW, UnityPlacesBarViewClass))

typedef struct _UnityPlacesBarView UnityPlacesBarView;
typedef struct _UnityPlacesBarViewClass UnityPlacesBarViewClass;

#define UNITY_PLACES_SEARCH_FIELD_TYPE_VIEW (unity_places_search_field_view_get_type ())
#define UNITY_PLACES_SEARCH_FIELD_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_SEARCH_FIELD_TYPE_VIEW, UnityPlacesSearchFieldView))
#define UNITY_PLACES_SEARCH_FIELD_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_SEARCH_FIELD_TYPE_VIEW, UnityPlacesSearchFieldViewClass))
#define UNITY_PLACES_SEARCH_FIELD_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_SEARCH_FIELD_TYPE_VIEW))
#define UNITY_PLACES_SEARCH_FIELD_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_SEARCH_FIELD_TYPE_VIEW))
#define UNITY_PLACES_SEARCH_FIELD_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_SEARCH_FIELD_TYPE_VIEW, UnityPlacesSearchFieldViewClass))

typedef struct _UnityPlacesSearchFieldView UnityPlacesSearchFieldView;
typedef struct _UnityPlacesSearchFieldViewClass UnityPlacesSearchFieldViewClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _UnityPlacesView {
	CtkBox parent_instance;
	UnityPlacesViewPrivate * priv;
};

struct _UnityPlacesViewClass {
	CtkBoxClass parent_class;
};

struct _UnityPlacesViewPrivate {
	UnityPlacesModel* _model;
	UnityShell* _shell;
	UnityPlacesBarView* bar_view;
	ClutterActor* content_view;
	UnityPlacesSearchFieldView* search_view;
};


static gpointer unity_places_view_parent_class = NULL;

GType unity_places_view_get_type (void);
GType unity_places_model_get_type (void);
GType unity_places_bar_view_get_type (void);
GType unity_places_search_field_view_get_type (void);
#define UNITY_PLACES_VIEW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_VIEW, UnityPlacesViewPrivate))
enum  {
	UNITY_PLACES_VIEW_DUMMY_PROPERTY,
	UNITY_PLACES_VIEW_MODEL,
	UNITY_PLACES_VIEW_SHELL
};
UnityPlacesModel* unity_places_view_get_model (UnityPlacesView* self);
UnityShell* unity_places_view_get_shell (UnityPlacesView* self);
UnityPlacesBarView* unity_places_bar_view_new (UnityPlacesModel* model, UnityShell* shell);
UnityPlacesBarView* unity_places_bar_view_construct (GType object_type, UnityPlacesModel* model, UnityShell* shell);
UnityPlacesSearchFieldView* unity_places_search_field_view_new (void);
UnityPlacesSearchFieldView* unity_places_search_field_view_construct (GType object_type);
UnityPlacesView* unity_places_view_new (UnityPlacesModel* model, UnityShell* shell);
UnityPlacesView* unity_places_view_construct (GType object_type, UnityPlacesModel* model, UnityShell* shell);
static void unity_places_view_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
static void unity_places_view_on_fade_out_done (ClutterAnimation* anim, ClutterActor* actor);
void unity_places_view_set_content_view (UnityPlacesView* self, ClutterActor* actor);
static void unity_places_view_set_model (UnityPlacesView* self, UnityPlacesModel* value);
static void unity_places_view_set_shell (UnityPlacesView* self, UnityShell* value);
static void unity_places_view_finalize (GObject* obj);
static void unity_places_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UnityPlacesView* unity_places_view_construct (GType object_type, UnityPlacesModel* model, UnityShell* shell) {
	UnityPlacesView * self;
	CtkPadding _tmp0_ = {0};
	CtkPadding padding;
	UnityPlacesBarView* _tmp1_;
	UnityPlacesSearchFieldView* _tmp2_;
	g_return_val_if_fail (model != NULL, NULL);
	g_return_val_if_fail (shell != NULL, NULL);
	padding = (_tmp0_.top = 0.0f, _tmp0_.right = 0.0f, _tmp0_.bottom = 0.0f, _tmp0_.left = 68.0f, _tmp0_);
	self = (UnityPlacesView*) g_object_new (object_type, "model", model, "shell", shell, NULL);
	ctk_box_set_orientation ((CtkBox*) self, (gint) CTK_ORIENTATION_VERTICAL);
	self->priv->bar_view = (_tmp1_ = g_object_ref_sink (unity_places_bar_view_new (self->priv->_model, self->priv->_shell)), _g_object_unref0 (self->priv->bar_view), _tmp1_);
	ctk_actor_set_padding ((CtkActor*) self->priv->bar_view, &padding);
	clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) self->priv->bar_view);
	self->priv->search_view = (_tmp2_ = g_object_ref_sink (unity_places_search_field_view_new ()), _g_object_unref0 (self->priv->search_view), _tmp2_);
	clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) self->priv->search_view);
	return self;
}


UnityPlacesView* unity_places_view_new (UnityPlacesModel* model, UnityShell* shell) {
	return unity_places_view_construct (UNITY_PLACES_TYPE_VIEW, model, shell);
}


static void unity_places_view_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
	UnityPlacesView * self;
	ClutterActorBox _tmp0_ = {0};
	ClutterActorBox child_box;
	self = (UnityPlacesView*) base;
	child_box = (_tmp0_.x1 = 0.0f, _tmp0_.y1 = 0.0f, _tmp0_.x2 = 0.0f, _tmp0_.y2 = 0.0f, _tmp0_);
	child_box.x1 = (float) 0;
	child_box.x2 = (*box).x2 - (*box).x1;
	child_box.y1 = (float) 0;
	child_box.y2 = (float) 62;
	clutter_actor_allocate ((ClutterActor*) self->priv->bar_view, &child_box, flags);
	child_box.x1 = (float) 58;
	child_box.x2 = (*box).x2 - (*box).x1;
	child_box.y1 = (*box).y1 + 62;
	child_box.y2 = (*box).y2 - (*box).y1;
	if (CLUTTER_IS_ACTOR (self->priv->content_view)) {
		clutter_actor_allocate (self->priv->content_view, &child_box, flags);
	}
	child_box.x1 = (child_box.x2 - unity_shell_get_indicators_width (self->priv->_shell)) + 8;
	child_box.x2 = (child_box.x1 + unity_shell_get_indicators_width (self->priv->_shell)) - 8;
	child_box.y1 = (float) 32;
	child_box.y2 = child_box.y1 + 22;
	clutter_actor_allocate ((ClutterActor*) self->priv->search_view, &child_box, flags);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void unity_places_view_set_content_view (UnityPlacesView* self, ClutterActor* actor) {
	ClutterActor* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (actor != NULL);
	if (CLUTTER_IS_ACTOR (self->priv->content_view)) {
		clutter_actor_animate (self->priv->content_view, (gulong) CLUTTER_EASE_OUT_QUAD, (guint) 300, "opacity", 0, "signal::completed", unity_places_view_on_fade_out_done, self->priv->content_view, NULL);
	}
	self->priv->content_view = (_tmp0_ = _g_object_ref0 (actor), _g_object_unref0 (self->priv->content_view), _tmp0_);
	clutter_container_add_actor ((ClutterContainer*) self, self->priv->content_view);
	clutter_actor_show (self->priv->content_view);
	clutter_actor_set_opacity (actor, (guint8) 0);
	clutter_actor_animate (actor, (gulong) CLUTTER_EASE_IN_QUAD, (guint) 300, "opacity", 255, NULL);
}


static void unity_places_view_on_fade_out_done (ClutterAnimation* anim, ClutterActor* actor) {
	g_return_if_fail (anim != NULL);
	g_return_if_fail (actor != NULL);
	clutter_actor_destroy (actor);
}


UnityPlacesModel* unity_places_view_get_model (UnityPlacesView* self) {
	UnityPlacesModel* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_model;
	return result;
}


static void unity_places_view_set_model (UnityPlacesView* self, UnityPlacesModel* value) {
	UnityPlacesModel* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_model = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_model), _tmp0_);
	g_object_notify ((GObject *) self, "model");
}


UnityShell* unity_places_view_get_shell (UnityPlacesView* self) {
	UnityShell* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_shell;
	return result;
}


static void unity_places_view_set_shell (UnityPlacesView* self, UnityShell* value) {
	UnityShell* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_shell = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_shell), _tmp0_);
	g_object_notify ((GObject *) self, "shell");
}


static void unity_places_view_class_init (UnityPlacesViewClass * klass) {
	unity_places_view_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesViewPrivate));
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_places_view_real_allocate;
	G_OBJECT_CLASS (klass)->get_property = unity_places_view_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_view_set_property;
	G_OBJECT_CLASS (klass)->finalize = unity_places_view_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_VIEW_MODEL, g_param_spec_object ("model", "model", "model", UNITY_PLACES_TYPE_MODEL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_VIEW_SHELL, g_param_spec_object ("shell", "shell", "shell", UNITY_TYPE_SHELL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_places_view_instance_init (UnityPlacesView * self) {
	self->priv = UNITY_PLACES_VIEW_GET_PRIVATE (self);
}


static void unity_places_view_finalize (GObject* obj) {
	UnityPlacesView * self;
	self = UNITY_PLACES_VIEW (obj);
	_g_object_unref0 (self->priv->_model);
	_g_object_unref0 (self->priv->_shell);
	_g_object_unref0 (self->priv->bar_view);
	_g_object_unref0 (self->priv->content_view);
	_g_object_unref0 (self->priv->search_view);
	G_OBJECT_CLASS (unity_places_view_parent_class)->finalize (obj);
}


GType unity_places_view_get_type (void) {
	static volatile gsize unity_places_view_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_view_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesView), 0, (GInstanceInitFunc) unity_places_view_instance_init, NULL };
		GType unity_places_view_type_id;
		unity_places_view_type_id = g_type_register_static (CTK_TYPE_BOX, "UnityPlacesView", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_view_type_id__volatile, unity_places_view_type_id);
	}
	return unity_places_view_type_id__volatile;
}


static void unity_places_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesView * self;
	self = UNITY_PLACES_VIEW (object);
	switch (property_id) {
		case UNITY_PLACES_VIEW_MODEL:
		g_value_set_object (value, unity_places_view_get_model (self));
		break;
		case UNITY_PLACES_VIEW_SHELL:
		g_value_set_object (value, unity_places_view_get_shell (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesView * self;
	self = UNITY_PLACES_VIEW (object);
	switch (property_id) {
		case UNITY_PLACES_VIEW_MODEL:
		unity_places_view_set_model (self, g_value_get_object (value));
		break;
		case UNITY_PLACES_VIEW_SHELL:
		unity_places_view_set_shell (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




