/* quicklist-controller.c generated by valac, the Vala compiler
 * generated from quicklist-controller.vala, do not modify */

/* -*- Mode: vala; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
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
 * Authored by Gordon Allott <gord.allott@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <clutk/clutk.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <clutter/clutter.h>
#include <unity.h>
#include <float.h>
#include <math.h>


#define UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER (unity_launcher_quicklist_controller_get_type ())
#define UNITY_LAUNCHER_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityLauncherQuicklistController))
#define UNITY_LAUNCHER_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityLauncherQuicklistControllerClass))
#define UNITY_LAUNCHER_IS_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER))
#define UNITY_LAUNCHER_IS_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER))
#define UNITY_LAUNCHER_QUICKLIST_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityLauncherQuicklistControllerClass))

typedef struct _UnityLauncherQuicklistController UnityLauncherQuicklistController;
typedef struct _UnityLauncherQuicklistControllerClass UnityLauncherQuicklistControllerClass;
typedef struct _UnityLauncherQuicklistControllerPrivate UnityLauncherQuicklistControllerPrivate;

#define UNITY_LAUNCHER_TYPE_SHORTCUT_ITEM (unity_launcher_shortcut_item_get_type ())
#define UNITY_LAUNCHER_SHORTCUT_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SHORTCUT_ITEM, UnityLauncherShortcutItem))
#define UNITY_LAUNCHER_IS_SHORTCUT_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SHORTCUT_ITEM))
#define UNITY_LAUNCHER_SHORTCUT_ITEM_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_LAUNCHER_TYPE_SHORTCUT_ITEM, UnityLauncherShortcutItemIface))

typedef struct _UnityLauncherShortcutItem UnityLauncherShortcutItem;
typedef struct _UnityLauncherShortcutItemIface UnityLauncherShortcutItemIface;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_TESTING_TYPE_OBJECT_REGISTRY (unity_testing_object_registry_get_type ())
#define UNITY_TESTING_OBJECT_REGISTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistry))
#define UNITY_TESTING_OBJECT_REGISTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistryClass))
#define UNITY_TESTING_IS_OBJECT_REGISTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY))
#define UNITY_TESTING_IS_OBJECT_REGISTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTING_TYPE_OBJECT_REGISTRY))
#define UNITY_TESTING_OBJECT_REGISTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistryClass))

typedef struct _UnityTestingObjectRegistry UnityTestingObjectRegistry;
typedef struct _UnityTestingObjectRegistryClass UnityTestingObjectRegistryClass;
#define _unity_testing_object_registry_unref0(var) ((var == NULL) ? NULL : (var = (unity_testing_object_registry_unref (var), NULL)))

#define UNITY_LAUNCHER_TYPE_QUICKLIST_MENU (unity_launcher_quicklist_menu_get_type ())
#define UNITY_LAUNCHER_QUICKLIST_MENU(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU, UnityLauncherQuicklistMenu))
#define UNITY_LAUNCHER_QUICKLIST_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU, UnityLauncherQuicklistMenuClass))
#define UNITY_LAUNCHER_IS_QUICKLIST_MENU(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU))
#define UNITY_LAUNCHER_IS_QUICKLIST_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU))
#define UNITY_LAUNCHER_QUICKLIST_MENU_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU, UnityLauncherQuicklistMenuClass))

typedef struct _UnityLauncherQuicklistMenu UnityLauncherQuicklistMenu;
typedef struct _UnityLauncherQuicklistMenuClass UnityLauncherQuicklistMenuClass;

#define UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM (unity_launcher_quicklist_menu_item_get_type ())
#define UNITY_LAUNCHER_QUICKLIST_MENU_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM, UnityLauncherQuicklistMenuItem))
#define UNITY_LAUNCHER_QUICKLIST_MENU_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM, UnityLauncherQuicklistMenuItemClass))
#define UNITY_LAUNCHER_IS_QUICKLIST_MENU_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM))
#define UNITY_LAUNCHER_IS_QUICKLIST_MENU_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM))
#define UNITY_LAUNCHER_QUICKLIST_MENU_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM, UnityLauncherQuicklistMenuItemClass))

typedef struct _UnityLauncherQuicklistMenuItem UnityLauncherQuicklistMenuItem;
typedef struct _UnityLauncherQuicklistMenuItemClass UnityLauncherQuicklistMenuItemClass;
#define _g_free0(var) (var = (g_free (var), NULL))

#define UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_SEPERATOR (unity_launcher_quicklist_menu_seperator_get_type ())
#define UNITY_LAUNCHER_QUICKLIST_MENU_SEPERATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_SEPERATOR, UnityLauncherQuicklistMenuSeperator))
#define UNITY_LAUNCHER_QUICKLIST_MENU_SEPERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_SEPERATOR, UnityLauncherQuicklistMenuSeperatorClass))
#define UNITY_LAUNCHER_IS_QUICKLIST_MENU_SEPERATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_SEPERATOR))
#define UNITY_LAUNCHER_IS_QUICKLIST_MENU_SEPERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_SEPERATOR))
#define UNITY_LAUNCHER_QUICKLIST_MENU_SEPERATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_SEPERATOR, UnityLauncherQuicklistMenuSeperatorClass))

typedef struct _UnityLauncherQuicklistMenuSeperator UnityLauncherQuicklistMenuSeperator;
typedef struct _UnityLauncherQuicklistMenuSeperatorClass UnityLauncherQuicklistMenuSeperatorClass;

struct _UnityLauncherQuicklistController {
	GObject parent_instance;
	UnityLauncherQuicklistControllerPrivate * priv;
	CtkMenu* menu;
	gboolean is_in_label;
	gboolean is_in_menu;
};

struct _UnityLauncherQuicklistControllerClass {
	GObjectClass parent_class;
};

struct _UnityLauncherShortcutItemIface {
	GTypeInterface parent_iface;
	char* (*get_name) (UnityLauncherShortcutItem* self);
	void (*activated) (UnityLauncherShortcutItem* self);
};

struct _UnityLauncherQuicklistControllerPrivate {
	GeeArrayList* prefix_cache;
	GeeArrayList* affix_cache;
};


extern UnityLauncherQuicklistController* unity_launcher_ql_controler_singleton;
UnityLauncherQuicklistController* unity_launcher_ql_controler_singleton = NULL;
static gpointer unity_launcher_quicklist_controller_parent_class = NULL;

GType unity_launcher_quicklist_controller_get_type (void);
GType unity_launcher_shortcut_item_get_type (void);
#define UNITY_LAUNCHER_QUICKLIST_CONTROLLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityLauncherQuicklistControllerPrivate))
enum  {
	UNITY_LAUNCHER_QUICKLIST_CONTROLLER_DUMMY_PROPERTY
};
UnityLauncherQuicklistController* unity_launcher_quicklist_controller_new (void);
UnityLauncherQuicklistController* unity_launcher_quicklist_controller_construct (GType object_type);
UnityLauncherQuicklistController* unity_launcher_quicklist_controller_get_default (void);
gpointer unity_testing_object_registry_ref (gpointer instance);
void unity_testing_object_registry_unref (gpointer instance);
GParamSpec* unity_testing_param_spec_object_registry (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_testing_value_set_object_registry (GValue* value, gpointer v_object);
void unity_testing_value_take_object_registry (GValue* value, gpointer v_object);
gpointer unity_testing_value_get_object_registry (const GValue* value);
GType unity_testing_object_registry_get_type (void);
UnityTestingObjectRegistry* unity_testing_object_registry_get_default (void);
void unity_testing_object_registry_register (UnityTestingObjectRegistry* self, const char* name, GObject* object);
gboolean unity_launcher_quicklist_controller_menu_is_open (UnityLauncherQuicklistController* self);
static void unity_launcher_quicklist_controller_on_unity_drag_start (UnityLauncherQuicklistController* self, UnityDragModel* model);
UnityLauncherQuicklistMenu* unity_launcher_quicklist_menu_new (void);
UnityLauncherQuicklistMenu* unity_launcher_quicklist_menu_construct (GType object_type);
GType unity_launcher_quicklist_menu_get_type (void);
static void _lambda9_ (UnityLauncherQuicklistController* self);
static void __lambda9__clutter_actor_destroy (ClutterActor* _sender, gpointer self);
static void _lambda10_ (UnityLauncherQuicklistController* self);
static void __lambda10__clutter_actor_destroy (ClutterActor* _sender, gpointer self);
UnityLauncherQuicklistMenuItem* unity_launcher_quicklist_menu_item_new (const char* label);
UnityLauncherQuicklistMenuItem* unity_launcher_quicklist_menu_item_construct (GType object_type, const char* label);
GType unity_launcher_quicklist_menu_item_get_type (void);
void unity_launcher_quicklist_controller_close_menu (UnityLauncherQuicklistController* self);
static void _unity_launcher_quicklist_controller_close_menu_unity_launcher_quicklist_menu_item_activated (UnityLauncherQuicklistMenuItem* _sender, gpointer self);
void unity_launcher_quicklist_controller_show_label (UnityLauncherQuicklistController* self, const char* label, CtkActor* attached_widget);
char* unity_launcher_shortcut_item_get_name (UnityLauncherShortcutItem* self);
void unity_launcher_shortcut_item_activated (UnityLauncherShortcutItem* self);
static void _unity_launcher_shortcut_item_activated_unity_launcher_quicklist_menu_item_activated (UnityLauncherQuicklistMenuItem* _sender, gpointer self);
UnityLauncherQuicklistMenuSeperator* unity_launcher_quicklist_menu_seperator_new (void);
UnityLauncherQuicklistMenuSeperator* unity_launcher_quicklist_menu_seperator_construct (GType object_type);
GType unity_launcher_quicklist_menu_seperator_get_type (void);
void unity_launcher_quicklist_controller_show_menu (UnityLauncherQuicklistController* self, GeeArrayList* prefix_shortcuts, GeeArrayList* affix_shortcuts, gboolean hide_on_leave);
CtkActor* unity_launcher_quicklist_controller_get_attached_actor (UnityLauncherQuicklistController* self);
static void _unity_launcher_quicklist_controller_on_unity_drag_start_unity_drag_controller_drag_start (UnityDragController* _sender, UnityDragModel* model, gpointer self);
static GObject * unity_launcher_quicklist_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_launcher_quicklist_controller_finalize (GObject* obj);



UnityLauncherQuicklistController* unity_launcher_quicklist_controller_get_default (void) {
	UnityLauncherQuicklistController* result = NULL;
	if (unity_launcher_ql_controler_singleton == NULL) {
		UnityLauncherQuicklistController* _tmp0_;
		unity_launcher_ql_controler_singleton = (_tmp0_ = unity_launcher_quicklist_controller_new (), _g_object_unref0 (unity_launcher_ql_controler_singleton), _tmp0_);
	}
	result = unity_launcher_ql_controler_singleton;
	return result;
}


UnityLauncherQuicklistController* unity_launcher_quicklist_controller_construct (GType object_type) {
	UnityLauncherQuicklistController * self;
	UnityTestingObjectRegistry* _tmp0_;
	self = g_object_newv (object_type, 0, NULL);
	unity_testing_object_registry_register (_tmp0_ = unity_testing_object_registry_get_default (), "QuicklistController", (GObject*) self);
	_unity_testing_object_registry_unref0 (_tmp0_);
	return self;
}


UnityLauncherQuicklistController* unity_launcher_quicklist_controller_new (void) {
	return unity_launcher_quicklist_controller_construct (UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER);
}


static void unity_launcher_quicklist_controller_on_unity_drag_start (UnityLauncherQuicklistController* self, UnityDragModel* model) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (model != NULL);
	if (unity_launcher_quicklist_controller_menu_is_open (self)) {
		clutter_actor_destroy ((ClutterActor*) self->menu);
	}
}


static void _lambda9_ (UnityLauncherQuicklistController* self) {
	if (self->is_in_menu) {
		g_signal_emit_by_name (self, "menu-state-changed", FALSE);
	}
}


static void __lambda9__clutter_actor_destroy (ClutterActor* _sender, gpointer self) {
	_lambda9_ (self);
}


static void _lambda10_ (UnityLauncherQuicklistController* self) {
	unity_shell_remove_fullscreen_request (unity_global_shell, (GObject*) self);
}


static void __lambda10__clutter_actor_destroy (ClutterActor* _sender, gpointer self) {
	_lambda10_ (self);
}


static void _unity_launcher_quicklist_controller_close_menu_unity_launcher_quicklist_menu_item_activated (UnityLauncherQuicklistMenuItem* _sender, gpointer self) {
	unity_launcher_quicklist_controller_close_menu (self);
}


void unity_launcher_quicklist_controller_show_label (UnityLauncherQuicklistController* self, const char* label, CtkActor* attached_widget) {
	UnityLauncherQuicklistMenu* _tmp0_;
	CtkMenu* menu;
	UnityLauncherQuicklistMenuItem* menuitem;
	ClutterActor* _tmp1_;
	float x = 0.0F;
	float y = 0.0F;
	g_return_if_fail (self != NULL);
	g_return_if_fail (label != NULL);
	g_return_if_fail (attached_widget != NULL);
	if (unity_launcher_quicklist_controller_menu_is_open (self)) {
		clutter_actor_destroy ((ClutterActor*) self->menu);
	}
	menu = (_tmp0_ = g_object_ref_sink (unity_launcher_quicklist_menu_new ()), CTK_IS_MENU (_tmp0_) ? ((CtkMenu*) _tmp0_) : NULL);
	g_signal_connect_object ((ClutterActor*) menu, "destroy", (GCallback) __lambda9__clutter_actor_destroy, self, 0);
	self->menu = menu;
	g_signal_connect_object ((ClutterActor*) self->menu, "destroy", (GCallback) __lambda10__clutter_actor_destroy, self, 0);
	ctk_menu_set_swallow_clicks (self->menu, unity_shell_get_menus_swallow_events (unity_global_shell));
	ctk_menu_set_detect_clicks (self->menu, FALSE);
	menuitem = g_object_ref_sink (unity_launcher_quicklist_menu_item_new (label));
	g_signal_connect_object (menuitem, "activated", (GCallback) _unity_launcher_quicklist_controller_close_menu_unity_launcher_quicklist_menu_item_activated, self, 0);
	clutter_actor_set_reactive ((ClutterActor*) menuitem, TRUE);
	ctk_menu_append (self->menu, (ClutterActor*) menuitem, TRUE);
	ctk_menu_attach_to_actor (self->menu, attached_widget);
	clutter_container_add_actor ((ClutterContainer*) (_tmp1_ = clutter_actor_get_stage ((ClutterActor*) attached_widget), CLUTTER_IS_STAGE (_tmp1_) ? ((ClutterStage*) _tmp1_) : NULL), (ClutterActor*) self->menu);
	clutter_actor_get_position ((ClutterActor*) self->menu, &x, &y);
	clutter_actor_set_position ((ClutterActor*) self->menu, x - ((float) 22.0f), y - 1.0f);
	self->is_in_label = TRUE;
	_g_object_unref0 (menu);
	_g_object_unref0 (menuitem);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _unity_launcher_shortcut_item_activated_unity_launcher_quicklist_menu_item_activated (UnityLauncherQuicklistMenuItem* _sender, gpointer self) {
	unity_launcher_shortcut_item_activated (self);
}


void unity_launcher_quicklist_controller_show_menu (UnityLauncherQuicklistController* self, GeeArrayList* prefix_shortcuts, GeeArrayList* affix_shortcuts, gboolean hide_on_leave) {
	GeeArrayList* _tmp0_;
	GeeArrayList* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (prefix_shortcuts != NULL);
	g_return_if_fail (affix_shortcuts != NULL);
	self->priv->prefix_cache = (_tmp0_ = _g_object_ref0 (prefix_shortcuts), _g_object_unref0 (self->priv->prefix_cache), _tmp0_);
	self->priv->affix_cache = (_tmp1_ = _g_object_ref0 (affix_shortcuts), _g_object_unref0 (self->priv->affix_cache), _tmp1_);
	self->is_in_label = FALSE;
	unity_shell_add_fullscreen_request (unity_global_shell, (GObject*) self);
	ctk_menu_set_close_on_leave (self->menu, hide_on_leave);
	{
		GeeIterator* _shortcut_it;
		_shortcut_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) prefix_shortcuts);
		while (TRUE) {
			UnityLauncherShortcutItem* shortcut;
			char* label;
			UnityLauncherQuicklistMenuItem* menuitem;
			if (!gee_iterator_next (_shortcut_it)) {
				break;
			}
			shortcut = (UnityLauncherShortcutItem*) gee_iterator_get (_shortcut_it);
			label = unity_launcher_shortcut_item_get_name (shortcut);
			menuitem = g_object_ref_sink (unity_launcher_quicklist_menu_item_new (label));
			ctk_menu_prepend (self->menu, (ClutterActor*) menuitem, FALSE);
			g_signal_connect_object (menuitem, "activated", (GCallback) _unity_launcher_shortcut_item_activated_unity_launcher_quicklist_menu_item_activated, shortcut, 0);
			g_signal_connect_object (menuitem, "activated", (GCallback) _unity_launcher_quicklist_controller_close_menu_unity_launcher_quicklist_menu_item_activated, self, 0);
			_g_object_unref0 (shortcut);
			_g_free0 (label);
			_g_object_unref0 (menuitem);
		}
		_g_object_unref0 (_shortcut_it);
	}
	if (gee_collection_get_size ((GeeCollection*) affix_shortcuts) > 0) {
		UnityLauncherQuicklistMenuSeperator* separator;
		separator = g_object_ref_sink (unity_launcher_quicklist_menu_seperator_new ());
		ctk_menu_append (self->menu, (ClutterActor*) separator, FALSE);
		_g_object_unref0 (separator);
	}
	{
		GeeIterator* _shortcut_it;
		_shortcut_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) affix_shortcuts);
		while (TRUE) {
			UnityLauncherShortcutItem* shortcut;
			char* label;
			UnityLauncherQuicklistMenuItem* menuitem;
			if (!gee_iterator_next (_shortcut_it)) {
				break;
			}
			shortcut = (UnityLauncherShortcutItem*) gee_iterator_get (_shortcut_it);
			label = unity_launcher_shortcut_item_get_name (shortcut);
			menuitem = g_object_ref_sink (unity_launcher_quicklist_menu_item_new (label));
			ctk_menu_append (self->menu, (ClutterActor*) menuitem, FALSE);
			g_signal_connect_object (menuitem, "activated", (GCallback) _unity_launcher_shortcut_item_activated_unity_launcher_quicklist_menu_item_activated, shortcut, 0);
			g_signal_connect_object (menuitem, "activated", (GCallback) _unity_launcher_quicklist_controller_close_menu_unity_launcher_quicklist_menu_item_activated, self, 0);
			_g_object_unref0 (shortcut);
			_g_free0 (label);
			_g_object_unref0 (menuitem);
		}
		_g_object_unref0 (_shortcut_it);
	}
	ctk_menu_set_detect_clicks (self->menu, TRUE);
	g_signal_emit_by_name (self, "menu-state-changed", TRUE);
}


void unity_launcher_quicklist_controller_close_menu (UnityLauncherQuicklistController* self) {
	g_return_if_fail (self != NULL);
	if (CTK_IS_MENU (self->menu)) {
		clutter_actor_destroy ((ClutterActor*) self->menu);
	}
	self->is_in_label = FALSE;
	self->is_in_menu = FALSE;
}


gboolean unity_launcher_quicklist_controller_menu_is_open (UnityLauncherQuicklistController* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	result = CTK_IS_MENU (self->menu);
	return result;
}


CtkActor* unity_launcher_quicklist_controller_get_attached_actor (UnityLauncherQuicklistController* self) {
	CtkActor* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = _g_object_ref0 (ctk_menu_get_attached_actor (self->menu));
	return result;
}


static void _unity_launcher_quicklist_controller_on_unity_drag_start_unity_drag_controller_drag_start (UnityDragController* _sender, UnityDragModel* model, gpointer self) {
	unity_launcher_quicklist_controller_on_unity_drag_start (self, model);
}


static GObject * unity_launcher_quicklist_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityLauncherQuicklistController * self;
	parent_class = G_OBJECT_CLASS (unity_launcher_quicklist_controller_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_LAUNCHER_QUICKLIST_CONTROLLER (obj);
	{
		UnityDragController* drag_controller;
		drag_controller = _g_object_ref0 (unity_drag_controller_get_default ());
		g_signal_connect_object (drag_controller, "drag-start", (GCallback) _unity_launcher_quicklist_controller_on_unity_drag_start_unity_drag_controller_drag_start, self, 0);
		_g_object_unref0 (drag_controller);
	}
	return obj;
}


static void unity_launcher_quicklist_controller_class_init (UnityLauncherQuicklistControllerClass * klass) {
	unity_launcher_quicklist_controller_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityLauncherQuicklistControllerPrivate));
	G_OBJECT_CLASS (klass)->constructor = unity_launcher_quicklist_controller_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_launcher_quicklist_controller_finalize;
	g_signal_new ("menu_state_changed", UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__BOOLEAN, G_TYPE_NONE, 1, G_TYPE_BOOLEAN);
}


static void unity_launcher_quicklist_controller_instance_init (UnityLauncherQuicklistController * self) {
	self->priv = UNITY_LAUNCHER_QUICKLIST_CONTROLLER_GET_PRIVATE (self);
	self->is_in_label = FALSE;
	self->is_in_menu = FALSE;
}


static void unity_launcher_quicklist_controller_finalize (GObject* obj) {
	UnityLauncherQuicklistController * self;
	self = UNITY_LAUNCHER_QUICKLIST_CONTROLLER (obj);
	_g_object_unref0 (self->priv->prefix_cache);
	_g_object_unref0 (self->priv->affix_cache);
	G_OBJECT_CLASS (unity_launcher_quicklist_controller_parent_class)->finalize (obj);
}


GType unity_launcher_quicklist_controller_get_type (void) {
	static volatile gsize unity_launcher_quicklist_controller_type_id__volatile = 0;
	if (g_once_init_enter (&unity_launcher_quicklist_controller_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityLauncherQuicklistControllerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_launcher_quicklist_controller_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityLauncherQuicklistController), 0, (GInstanceInitFunc) unity_launcher_quicklist_controller_instance_init, NULL };
		GType unity_launcher_quicklist_controller_type_id;
		unity_launcher_quicklist_controller_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityLauncherQuicklistController", &g_define_type_info, 0);
		g_once_init_leave (&unity_launcher_quicklist_controller_type_id__volatile, unity_launcher_quicklist_controller_type_id);
	}
	return unity_launcher_quicklist_controller_type_id__volatile;
}




