/* launcher.c generated by valac 0.10.0, the Vala compiler
 * generated from launcher.vala, do not modify */

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
#include <clutk/clutk.h>
#include <stdlib.h>
#include <string.h>
#include <unity.h>
#include <float.h>
#include <math.h>
#include <clutter/clutter.h>


#define UNITY_LAUNCHER_TYPE_LAUNCHER_CONTAINER (unity_launcher_launcher_container_get_type ())
#define UNITY_LAUNCHER_LAUNCHER_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_LAUNCHER_CONTAINER, UnityLauncherLauncherContainer))
#define UNITY_LAUNCHER_LAUNCHER_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_LAUNCHER_CONTAINER, UnityLauncherLauncherContainerClass))
#define UNITY_LAUNCHER_IS_LAUNCHER_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_LAUNCHER_CONTAINER))
#define UNITY_LAUNCHER_IS_LAUNCHER_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_LAUNCHER_CONTAINER))
#define UNITY_LAUNCHER_LAUNCHER_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_LAUNCHER_CONTAINER, UnityLauncherLauncherContainerClass))

typedef struct _UnityLauncherLauncherContainer UnityLauncherLauncherContainer;
typedef struct _UnityLauncherLauncherContainerClass UnityLauncherLauncherContainerClass;
typedef struct _UnityLauncherLauncherContainerPrivate UnityLauncherLauncherContainerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_LAUNCHER_TYPE_SHORTCUT_ITEM (unity_launcher_shortcut_item_get_type ())
#define UNITY_LAUNCHER_SHORTCUT_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SHORTCUT_ITEM, UnityLauncherShortcutItem))
#define UNITY_LAUNCHER_IS_SHORTCUT_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SHORTCUT_ITEM))
#define UNITY_LAUNCHER_SHORTCUT_ITEM_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_LAUNCHER_TYPE_SHORTCUT_ITEM, UnityLauncherShortcutItemIface))

typedef struct _UnityLauncherShortcutItem UnityLauncherShortcutItem;
typedef struct _UnityLauncherShortcutItemIface UnityLauncherShortcutItemIface;

#define UNITY_LAUNCHER_TYPE_LAUNCHER (unity_launcher_launcher_get_type ())
#define UNITY_LAUNCHER_LAUNCHER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_LAUNCHER, UnityLauncherLauncher))
#define UNITY_LAUNCHER_LAUNCHER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_LAUNCHER, UnityLauncherLauncherClass))
#define UNITY_LAUNCHER_IS_LAUNCHER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_LAUNCHER))
#define UNITY_LAUNCHER_IS_LAUNCHER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_LAUNCHER))
#define UNITY_LAUNCHER_LAUNCHER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_LAUNCHER, UnityLauncherLauncherClass))

typedef struct _UnityLauncherLauncher UnityLauncherLauncher;
typedef struct _UnityLauncherLauncherClass UnityLauncherLauncherClass;
typedef struct _UnityLauncherLauncherPrivate UnityLauncherLauncherPrivate;

#define UNITY_LAUNCHER_TYPE_SCROLLER_MODEL (unity_launcher_scroller_model_get_type ())
#define UNITY_LAUNCHER_SCROLLER_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL, UnityLauncherScrollerModel))
#define UNITY_LAUNCHER_SCROLLER_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL, UnityLauncherScrollerModelClass))
#define UNITY_LAUNCHER_IS_SCROLLER_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL))
#define UNITY_LAUNCHER_IS_SCROLLER_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL))
#define UNITY_LAUNCHER_SCROLLER_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL, UnityLauncherScrollerModelClass))

typedef struct _UnityLauncherScrollerModel UnityLauncherScrollerModel;
typedef struct _UnityLauncherScrollerModelClass UnityLauncherScrollerModelClass;

#define UNITY_LAUNCHER_TYPE_SCROLLER_CONTROLLER (unity_launcher_scroller_controller_get_type ())
#define UNITY_LAUNCHER_SCROLLER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CONTROLLER, UnityLauncherScrollerController))
#define UNITY_LAUNCHER_SCROLLER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CONTROLLER, UnityLauncherScrollerControllerClass))
#define UNITY_LAUNCHER_IS_SCROLLER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CONTROLLER))
#define UNITY_LAUNCHER_IS_SCROLLER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CONTROLLER))
#define UNITY_LAUNCHER_SCROLLER_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CONTROLLER, UnityLauncherScrollerControllerClass))

typedef struct _UnityLauncherScrollerController UnityLauncherScrollerController;
typedef struct _UnityLauncherScrollerControllerClass UnityLauncherScrollerControllerClass;

#define UNITY_LAUNCHER_TYPE_SCROLLER_VIEW (unity_launcher_scroller_view_get_type ())
#define UNITY_LAUNCHER_SCROLLER_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_VIEW, UnityLauncherScrollerView))
#define UNITY_LAUNCHER_SCROLLER_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_VIEW, UnityLauncherScrollerViewClass))
#define UNITY_LAUNCHER_IS_SCROLLER_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_VIEW))
#define UNITY_LAUNCHER_IS_SCROLLER_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_VIEW))
#define UNITY_LAUNCHER_SCROLLER_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_VIEW, UnityLauncherScrollerViewClass))

typedef struct _UnityLauncherScrollerView UnityLauncherScrollerView;
typedef struct _UnityLauncherScrollerViewClass UnityLauncherScrollerViewClass;
typedef struct _UnityLauncherScrollerViewPrivate UnityLauncherScrollerViewPrivate;

struct _UnityLauncherLauncherContainer {
	CtkBin parent_instance;
	UnityLauncherLauncherContainerPrivate * priv;
	CtkEffectCache* cache;
};

struct _UnityLauncherLauncherContainerClass {
	CtkBinClass parent_class;
};

struct _UnityLauncherShortcutItemIface {
	GTypeInterface parent_iface;
	char* (*get_name) (UnityLauncherShortcutItem* self);
	void (*activated) (UnityLauncherShortcutItem* self);
};

struct _UnityLauncherLauncher {
	GObject parent_instance;
	UnityLauncherLauncherPrivate * priv;
};

struct _UnityLauncherLauncherClass {
	GObjectClass parent_class;
};

struct _UnityLauncherLauncherPrivate {
	UnityShell* _shell;
	UnityLauncherScrollerModel* _model;
	UnityLauncherScrollerController* controller;
	UnityLauncherScrollerView* view;
	UnityLauncherLauncherContainer* launcher_container;
};

struct _UnityLauncherScrollerView {
	CtkActor parent_instance;
	UnityLauncherScrollerViewPrivate * priv;
	gint spacing;
	gint drag_sensitivity;
	float friction;
	gboolean is_animating;
	ClutterTimeline* fling_timeline;
	ClutterTimeline* autoscroll_timeline;
};

struct _UnityLauncherScrollerViewClass {
	CtkActorClass parent_class;
};


static gpointer unity_launcher_launcher_container_parent_class = NULL;
static gpointer unity_launcher_launcher_parent_class = NULL;

#define UNITY_LAUNCHER_SHORT_DELAY ((guint) 400)
#define UNITY_LAUNCHER_MEDIUM_DELAY ((guint) 800)
#define UNITY_LAUNCHER_LONG_DELAY ((guint) 1600)
GType unity_launcher_launcher_container_get_type (void) G_GNUC_CONST;
enum  {
	UNITY_LAUNCHER_LAUNCHER_CONTAINER_DUMMY_PROPERTY
};
UnityLauncherLauncherContainer* unity_launcher_launcher_container_new (void);
UnityLauncherLauncherContainer* unity_launcher_launcher_container_construct (GType object_type);
static GObject * unity_launcher_launcher_container_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_launcher_launcher_container_finalize (GObject* obj);
GType unity_launcher_shortcut_item_get_type (void) G_GNUC_CONST;
char* unity_launcher_shortcut_item_get_name (UnityLauncherShortcutItem* self);
void unity_launcher_shortcut_item_activated (UnityLauncherShortcutItem* self);
GType unity_launcher_launcher_get_type (void) G_GNUC_CONST;
GType unity_launcher_scroller_model_get_type (void) G_GNUC_CONST;
GType unity_launcher_scroller_controller_get_type (void) G_GNUC_CONST;
GType unity_launcher_scroller_view_get_type (void) G_GNUC_CONST;
#define UNITY_LAUNCHER_LAUNCHER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_LAUNCHER_TYPE_LAUNCHER, UnityLauncherLauncherPrivate))
enum  {
	UNITY_LAUNCHER_LAUNCHER_DUMMY_PROPERTY,
	UNITY_LAUNCHER_LAUNCHER_SHELL,
	UNITY_LAUNCHER_LAUNCHER_MODEL
};
UnityLauncherLauncher* unity_launcher_launcher_new (UnityShell* shell);
UnityLauncherLauncher* unity_launcher_launcher_construct (GType object_type, UnityShell* shell);
float unity_launcher_launcher_get_width (UnityLauncherLauncher* self);
ClutterActor* unity_launcher_launcher_get_view (UnityLauncherLauncher* self);
ClutterActor* unity_launcher_launcher_get_container (UnityLauncherLauncher* self);
CtkEffectCache* unity_launcher_launcher_get_actor_cache (UnityLauncherLauncher* self);
UnityShell* unity_launcher_launcher_get_shell (UnityLauncherLauncher* self);
static void unity_launcher_launcher_set_shell (UnityLauncherLauncher* self, UnityShell* value);
UnityLauncherScrollerModel* unity_launcher_launcher_get_model (UnityLauncherLauncher* self);
static void unity_launcher_launcher_set_model (UnityLauncherLauncher* self, UnityLauncherScrollerModel* value);
UnityLauncherScrollerModel* unity_launcher_scroller_model_new (void);
UnityLauncherScrollerModel* unity_launcher_scroller_model_construct (GType object_type);
UnityLauncherScrollerView* unity_launcher_scroller_view_new (UnityLauncherScrollerModel* _model, CtkEffectCache* _cache);
UnityLauncherScrollerView* unity_launcher_scroller_view_construct (GType object_type, UnityLauncherScrollerModel* _model, CtkEffectCache* _cache);
UnityLauncherScrollerController* unity_launcher_scroller_controller_new (UnityLauncherScrollerModel* _model, UnityLauncherScrollerView* _view);
UnityLauncherScrollerController* unity_launcher_scroller_controller_construct (GType object_type, UnityLauncherScrollerModel* _model, UnityLauncherScrollerView* _view);
static void _lambda99_ (UnityLauncherLauncher* self);
static void __lambda99__clutter_actor_queue_redraw (ClutterActor* _sender, ClutterActor* origin, gpointer self);
static GObject * unity_launcher_launcher_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_launcher_launcher_finalize (GObject* obj);
static void unity_launcher_launcher_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_launcher_launcher_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UnityLauncherLauncherContainer* unity_launcher_launcher_container_construct (GType object_type) {
	UnityLauncherLauncherContainer * self;
	CtkEffectCache* _tmp0_;
	self = (UnityLauncherLauncherContainer*) g_object_new (object_type, NULL);
	self->cache = (_tmp0_ = g_object_ref_sink ((CtkEffectCache*) ctk_effect_cache_new ()), _g_object_unref0 (self->cache), _tmp0_);
	ctk_actor_add_effect ((CtkActor*) self, (CtkEffect*) self->cache);
	ctk_effect_cache_update_texture_cache (self->cache);
	return self;
}


UnityLauncherLauncherContainer* unity_launcher_launcher_container_new (void) {
	return unity_launcher_launcher_container_construct (UNITY_LAUNCHER_TYPE_LAUNCHER_CONTAINER);
}


static GObject * unity_launcher_launcher_container_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityLauncherLauncherContainer * self;
	parent_class = G_OBJECT_CLASS (unity_launcher_launcher_container_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_LAUNCHER_LAUNCHER_CONTAINER (obj);
	{
	}
	return obj;
}


static void unity_launcher_launcher_container_class_init (UnityLauncherLauncherContainerClass * klass) {
	unity_launcher_launcher_container_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->constructor = unity_launcher_launcher_container_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_launcher_launcher_container_finalize;
}


static void unity_launcher_launcher_container_instance_init (UnityLauncherLauncherContainer * self) {
}


static void unity_launcher_launcher_container_finalize (GObject* obj) {
	UnityLauncherLauncherContainer * self;
	self = UNITY_LAUNCHER_LAUNCHER_CONTAINER (obj);
	_g_object_unref0 (self->cache);
	G_OBJECT_CLASS (unity_launcher_launcher_container_parent_class)->finalize (obj);
}


GType unity_launcher_launcher_container_get_type (void) {
	static volatile gsize unity_launcher_launcher_container_type_id__volatile = 0;
	if (g_once_init_enter (&unity_launcher_launcher_container_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityLauncherLauncherContainerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_launcher_launcher_container_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityLauncherLauncherContainer), 0, (GInstanceInitFunc) unity_launcher_launcher_container_instance_init, NULL };
		GType unity_launcher_launcher_container_type_id;
		unity_launcher_launcher_container_type_id = g_type_register_static (CTK_TYPE_BIN, "UnityLauncherLauncherContainer", &g_define_type_info, 0);
		g_once_init_leave (&unity_launcher_launcher_container_type_id__volatile, unity_launcher_launcher_container_type_id);
	}
	return unity_launcher_launcher_container_type_id__volatile;
}


char* unity_launcher_shortcut_item_get_name (UnityLauncherShortcutItem* self) {
	return UNITY_LAUNCHER_SHORTCUT_ITEM_GET_INTERFACE (self)->get_name (self);
}


void unity_launcher_shortcut_item_activated (UnityLauncherShortcutItem* self) {
	UNITY_LAUNCHER_SHORTCUT_ITEM_GET_INTERFACE (self)->activated (self);
}


static void unity_launcher_shortcut_item_base_init (UnityLauncherShortcutItemIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType unity_launcher_shortcut_item_get_type (void) {
	static volatile gsize unity_launcher_shortcut_item_type_id__volatile = 0;
	if (g_once_init_enter (&unity_launcher_shortcut_item_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityLauncherShortcutItemIface), (GBaseInitFunc) unity_launcher_shortcut_item_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType unity_launcher_shortcut_item_type_id;
		unity_launcher_shortcut_item_type_id = g_type_register_static (G_TYPE_INTERFACE, "UnityLauncherShortcutItem", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (unity_launcher_shortcut_item_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&unity_launcher_shortcut_item_type_id__volatile, unity_launcher_shortcut_item_type_id);
	}
	return unity_launcher_shortcut_item_type_id__volatile;
}


UnityLauncherLauncher* unity_launcher_launcher_construct (GType object_type, UnityShell* shell) {
	UnityLauncherLauncher * self;
	g_return_val_if_fail (shell != NULL, NULL);
	self = (UnityLauncherLauncher*) g_object_new (object_type, "shell", shell, NULL);
	return self;
}


UnityLauncherLauncher* unity_launcher_launcher_new (UnityShell* shell) {
	return unity_launcher_launcher_construct (UNITY_LAUNCHER_TYPE_LAUNCHER, shell);
}


float unity_launcher_launcher_get_width (UnityLauncherLauncher* self) {
	float result = 0.0F;
	g_return_val_if_fail (self != NULL, 0.0F);
	result = (float) 60;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


ClutterActor* unity_launcher_launcher_get_view (UnityLauncherLauncher* self) {
	ClutterActor* result = NULL;
	UnityLauncherScrollerView* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	result = _g_object_ref0 ((_tmp0_ = self->priv->view, CLUTTER_IS_ACTOR (_tmp0_) ? ((ClutterActor*) _tmp0_) : NULL));
	return result;
}


ClutterActor* unity_launcher_launcher_get_container (UnityLauncherLauncher* self) {
	ClutterActor* result = NULL;
	UnityLauncherLauncherContainer* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	result = _g_object_ref0 ((_tmp0_ = self->priv->launcher_container, CLUTTER_IS_ACTOR (_tmp0_) ? ((ClutterActor*) _tmp0_) : NULL));
	return result;
}


CtkEffectCache* unity_launcher_launcher_get_actor_cache (UnityLauncherLauncher* self) {
	CtkEffectCache* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = _g_object_ref0 (self->priv->launcher_container->cache);
	return result;
}


UnityShell* unity_launcher_launcher_get_shell (UnityLauncherLauncher* self) {
	UnityShell* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_shell;
	return result;
}


static void unity_launcher_launcher_set_shell (UnityLauncherLauncher* self, UnityShell* value) {
	UnityShell* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_shell = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_shell), _tmp0_);
	g_object_notify ((GObject *) self, "shell");
}


UnityLauncherScrollerModel* unity_launcher_launcher_get_model (UnityLauncherLauncher* self) {
	UnityLauncherScrollerModel* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_model;
	return result;
}


static void unity_launcher_launcher_set_model (UnityLauncherLauncher* self, UnityLauncherScrollerModel* value) {
	UnityLauncherScrollerModel* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_model = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_model), _tmp0_);
	g_object_notify ((GObject *) self, "model");
}


static void _lambda99_ (UnityLauncherLauncher* self) {
	if (clutter_timeline_is_playing (self->priv->view->fling_timeline) == FALSE) {
		ctk_effect_cache_update_texture_cache (self->priv->launcher_container->cache);
	}
}


static void __lambda99__clutter_actor_queue_redraw (ClutterActor* _sender, ClutterActor* origin, gpointer self) {
	_lambda99_ (self);
}


static GObject * unity_launcher_launcher_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityLauncherLauncher * self;
	parent_class = G_OBJECT_CLASS (unity_launcher_launcher_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_LAUNCHER_LAUNCHER (obj);
	{
		UnityLauncherScrollerModel* _tmp0_;
		UnityLauncherLauncherContainer* _tmp1_;
		UnityLauncherScrollerView* _tmp2_;
		UnityLauncherScrollerController* _tmp3_;
		unity_launcher_launcher_set_model (self, _tmp0_ = unity_launcher_scroller_model_new ());
		_g_object_unref0 (_tmp0_);
		self->priv->launcher_container = (_tmp1_ = g_object_ref_sink (unity_launcher_launcher_container_new ()), _g_object_unref0 (self->priv->launcher_container), _tmp1_);
		self->priv->view = (_tmp2_ = g_object_ref_sink (unity_launcher_scroller_view_new (self->priv->_model, self->priv->launcher_container->cache)), _g_object_unref0 (self->priv->view), _tmp2_);
		self->priv->controller = (_tmp3_ = unity_launcher_scroller_controller_new (self->priv->_model, self->priv->view), _g_object_unref0 (self->priv->controller), _tmp3_);
		g_signal_connect_object ((ClutterActor*) self->priv->view, "queue-redraw", (GCallback) __lambda99__clutter_actor_queue_redraw, self, 0);
	}
	return obj;
}


static void unity_launcher_launcher_class_init (UnityLauncherLauncherClass * klass) {
	unity_launcher_launcher_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityLauncherLauncherPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_launcher_launcher_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_launcher_launcher_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_launcher_launcher_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_launcher_launcher_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_LAUNCHER_LAUNCHER_SHELL, g_param_spec_object ("shell", "shell", "shell", UNITY_TYPE_SHELL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_LAUNCHER_LAUNCHER_MODEL, g_param_spec_object ("model", "model", "model", UNITY_LAUNCHER_TYPE_SCROLLER_MODEL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void unity_launcher_launcher_instance_init (UnityLauncherLauncher * self) {
	self->priv = UNITY_LAUNCHER_LAUNCHER_GET_PRIVATE (self);
}


static void unity_launcher_launcher_finalize (GObject* obj) {
	UnityLauncherLauncher * self;
	self = UNITY_LAUNCHER_LAUNCHER (obj);
	_g_object_unref0 (self->priv->_shell);
	_g_object_unref0 (self->priv->_model);
	_g_object_unref0 (self->priv->controller);
	_g_object_unref0 (self->priv->view);
	_g_object_unref0 (self->priv->launcher_container);
	G_OBJECT_CLASS (unity_launcher_launcher_parent_class)->finalize (obj);
}


GType unity_launcher_launcher_get_type (void) {
	static volatile gsize unity_launcher_launcher_type_id__volatile = 0;
	if (g_once_init_enter (&unity_launcher_launcher_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityLauncherLauncherClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_launcher_launcher_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityLauncherLauncher), 0, (GInstanceInitFunc) unity_launcher_launcher_instance_init, NULL };
		GType unity_launcher_launcher_type_id;
		unity_launcher_launcher_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityLauncherLauncher", &g_define_type_info, 0);
		g_once_init_leave (&unity_launcher_launcher_type_id__volatile, unity_launcher_launcher_type_id);
	}
	return unity_launcher_launcher_type_id__volatile;
}


static void unity_launcher_launcher_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityLauncherLauncher * self;
	self = UNITY_LAUNCHER_LAUNCHER (object);
	switch (property_id) {
		case UNITY_LAUNCHER_LAUNCHER_SHELL:
		g_value_set_object (value, unity_launcher_launcher_get_shell (self));
		break;
		case UNITY_LAUNCHER_LAUNCHER_MODEL:
		g_value_set_object (value, unity_launcher_launcher_get_model (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_launcher_launcher_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityLauncherLauncher * self;
	self = UNITY_LAUNCHER_LAUNCHER (object);
	switch (property_id) {
		case UNITY_LAUNCHER_LAUNCHER_SHELL:
		unity_launcher_launcher_set_shell (self, g_value_get_object (value));
		break;
		case UNITY_LAUNCHER_LAUNCHER_MODEL:
		unity_launcher_launcher_set_model (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




