/* scrollerchild.c generated by valac, the Vala compiler
 * generated from scrollerchild.vala, do not modify */

/*
 *      scrollerchild.vala.vala
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
#include <clutk/clutk.h>
#include <float.h>
#include <math.h>
#include <gdk-pixbuf/gdk-pixdata.h>
#include <stdlib.h>
#include <string.h>
#include <clutter/clutter.h>


#define UNITY_LAUNCHER_TYPE_PIN_TYPE (unity_launcher_pin_type_get_type ())

#define UNITY_LAUNCHER_TYPE_SCROLLER_CHILD (unity_launcher_scroller_child_get_type ())
#define UNITY_LAUNCHER_SCROLLER_CHILD(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChild))
#define UNITY_LAUNCHER_SCROLLER_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChildClass))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD))
#define UNITY_LAUNCHER_SCROLLER_CHILD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChildClass))

typedef struct _UnityLauncherScrollerChild UnityLauncherScrollerChild;
typedef struct _UnityLauncherScrollerChildClass UnityLauncherScrollerChildClass;
typedef struct _UnityLauncherScrollerChildPrivate UnityLauncherScrollerChildPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

typedef enum  {
	UNITY_LAUNCHER_PIN_TYPE_UNPINNED,
	UNITY_LAUNCHER_PIN_TYPE_PINNED,
	UNITY_LAUNCHER_PIN_TYPE_ALWAYS,
	UNITY_LAUNCHER_PIN_TYPE_NEVER
} UnityLauncherPinType;

struct _UnityLauncherScrollerChild {
	CtkActor parent_instance;
	UnityLauncherScrollerChildPrivate * priv;
	UnityLauncherPinType pin_type;
};

struct _UnityLauncherScrollerChildClass {
	CtkActorClass parent_class;
	void (*force_rotation_jump) (UnityLauncherScrollerChild* self, float degrees);
};

struct _UnityLauncherScrollerChildPrivate {
	GdkPixbuf* _icon;
	float _position;
	gboolean _running;
	gboolean _active;
	gboolean _needs_attention;
	gboolean _activating;
	float _rotation;
};


static gpointer unity_launcher_scroller_child_parent_class = NULL;

GType unity_launcher_pin_type_get_type (void);
GType unity_launcher_scroller_child_get_type (void);
#define UNITY_LAUNCHER_SCROLLER_CHILD_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChildPrivate))
enum  {
	UNITY_LAUNCHER_SCROLLER_CHILD_DUMMY_PROPERTY,
	UNITY_LAUNCHER_SCROLLER_CHILD_ICON,
	UNITY_LAUNCHER_SCROLLER_CHILD_POSITION,
	UNITY_LAUNCHER_SCROLLER_CHILD_RUNNING,
	UNITY_LAUNCHER_SCROLLER_CHILD_ACTIVE,
	UNITY_LAUNCHER_SCROLLER_CHILD_NEEDS_ATTENTION,
	UNITY_LAUNCHER_SCROLLER_CHILD_ACTIVATING,
	UNITY_LAUNCHER_SCROLLER_CHILD_ROTATION
};
void unity_launcher_scroller_child_force_rotation_jump (UnityLauncherScrollerChild* self, float degrees);
static void unity_launcher_scroller_child_real_force_rotation_jump (UnityLauncherScrollerChild* self, float degrees);
gboolean unity_launcher_scroller_child_get_running (UnityLauncherScrollerChild* self);
gboolean unity_launcher_scroller_child_get_active (UnityLauncherScrollerChild* self);
float unity_launcher_scroller_child_get_position (UnityLauncherScrollerChild* self);
char* unity_launcher_scroller_child_to_string (UnityLauncherScrollerChild* self);
UnityLauncherScrollerChild* unity_launcher_scroller_child_construct (GType object_type);
GdkPixbuf* unity_launcher_scroller_child_get_icon (UnityLauncherScrollerChild* self);
void unity_launcher_scroller_child_set_icon (UnityLauncherScrollerChild* self, GdkPixbuf* value);
void unity_launcher_scroller_child_set_position (UnityLauncherScrollerChild* self, float value);
void unity_launcher_scroller_child_set_running (UnityLauncherScrollerChild* self, gboolean value);
void unity_launcher_scroller_child_set_active (UnityLauncherScrollerChild* self, gboolean value);
gboolean unity_launcher_scroller_child_get_needs_attention (UnityLauncherScrollerChild* self);
void unity_launcher_scroller_child_set_needs_attention (UnityLauncherScrollerChild* self, gboolean value);
gboolean unity_launcher_scroller_child_get_activating (UnityLauncherScrollerChild* self);
void unity_launcher_scroller_child_set_activating (UnityLauncherScrollerChild* self, gboolean value);
float unity_launcher_scroller_child_get_rotation (UnityLauncherScrollerChild* self);
void unity_launcher_scroller_child_set_rotation (UnityLauncherScrollerChild* self, float value);
static GObject * unity_launcher_scroller_child_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_launcher_scroller_child_finalize (GObject* obj);
static void unity_launcher_scroller_child_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_launcher_scroller_child_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



GType unity_launcher_pin_type_get_type (void) {
	static volatile gsize unity_launcher_pin_type_type_id__volatile = 0;
	if (g_once_init_enter (&unity_launcher_pin_type_type_id__volatile)) {
		static const GEnumValue values[] = {{UNITY_LAUNCHER_PIN_TYPE_UNPINNED, "UNITY_LAUNCHER_PIN_TYPE_UNPINNED", "unpinned"}, {UNITY_LAUNCHER_PIN_TYPE_PINNED, "UNITY_LAUNCHER_PIN_TYPE_PINNED", "pinned"}, {UNITY_LAUNCHER_PIN_TYPE_ALWAYS, "UNITY_LAUNCHER_PIN_TYPE_ALWAYS", "always"}, {UNITY_LAUNCHER_PIN_TYPE_NEVER, "UNITY_LAUNCHER_PIN_TYPE_NEVER", "never"}, {0, NULL, NULL}};
		GType unity_launcher_pin_type_type_id;
		unity_launcher_pin_type_type_id = g_enum_register_static ("UnityLauncherPinType", values);
		g_once_init_leave (&unity_launcher_pin_type_type_id__volatile, unity_launcher_pin_type_type_id);
	}
	return unity_launcher_pin_type_type_id__volatile;
}


static void unity_launcher_scroller_child_real_force_rotation_jump (UnityLauncherScrollerChild* self, float degrees) {
	g_return_if_fail (self != NULL);
	g_critical ("Type `%s' does not implement abstract method `unity_launcher_scroller_child_force_rotation_jump'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return;
}


void unity_launcher_scroller_child_force_rotation_jump (UnityLauncherScrollerChild* self, float degrees) {
	UNITY_LAUNCHER_SCROLLER_CHILD_GET_CLASS (self)->force_rotation_jump (self, degrees);
}


char* unity_launcher_scroller_child_to_string (UnityLauncherScrollerChild* self) {
	char* result = NULL;
	const char* _tmp0_;
	const char* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = NULL;
	if (self->priv->_running) {
		_tmp0_ = "yes";
	} else {
		_tmp0_ = "no";
	}
	_tmp1_ = NULL;
	if (self->priv->_active) {
		_tmp1_ = "yes";
	} else {
		_tmp1_ = "no";
	}
	result = g_strdup_printf ("A scroller child; running: %s, active: %s, position: %f, opacity %f", _tmp0_, _tmp1_, (double) self->priv->_position, (double) clutter_actor_get_opacity ((ClutterActor*) self));
	return result;
}


UnityLauncherScrollerChild* unity_launcher_scroller_child_construct (GType object_type) {
	UnityLauncherScrollerChild * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


GdkPixbuf* unity_launcher_scroller_child_get_icon (UnityLauncherScrollerChild* self) {
	GdkPixbuf* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_icon;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void unity_launcher_scroller_child_set_icon (UnityLauncherScrollerChild* self, GdkPixbuf* value) {
	GdkPixbuf* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_icon = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_icon), _tmp0_);
	g_object_notify ((GObject *) self, "icon");
}


float unity_launcher_scroller_child_get_position (UnityLauncherScrollerChild* self) {
	float result;
	g_return_val_if_fail (self != NULL, 0.0F);
	result = self->priv->_position;
	return result;
}


void unity_launcher_scroller_child_set_position (UnityLauncherScrollerChild* self, float value) {
	g_return_if_fail (self != NULL);
	self->priv->_position = value;
	g_object_notify ((GObject *) self, "position");
}


gboolean unity_launcher_scroller_child_get_running (UnityLauncherScrollerChild* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_running;
	return result;
}


void unity_launcher_scroller_child_set_running (UnityLauncherScrollerChild* self, gboolean value) {
	g_return_if_fail (self != NULL);
	self->priv->_running = value;
	g_object_notify ((GObject *) self, "running");
}


gboolean unity_launcher_scroller_child_get_active (UnityLauncherScrollerChild* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_active;
	return result;
}


void unity_launcher_scroller_child_set_active (UnityLauncherScrollerChild* self, gboolean value) {
	g_return_if_fail (self != NULL);
	self->priv->_active = value;
	g_object_notify ((GObject *) self, "active");
}


gboolean unity_launcher_scroller_child_get_needs_attention (UnityLauncherScrollerChild* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_needs_attention;
	return result;
}


void unity_launcher_scroller_child_set_needs_attention (UnityLauncherScrollerChild* self, gboolean value) {
	g_return_if_fail (self != NULL);
	self->priv->_needs_attention = value;
	g_object_notify ((GObject *) self, "needs-attention");
}


gboolean unity_launcher_scroller_child_get_activating (UnityLauncherScrollerChild* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_activating;
	return result;
}


void unity_launcher_scroller_child_set_activating (UnityLauncherScrollerChild* self, gboolean value) {
	g_return_if_fail (self != NULL);
	self->priv->_activating = value;
	g_object_notify ((GObject *) self, "activating");
}


float unity_launcher_scroller_child_get_rotation (UnityLauncherScrollerChild* self) {
	float result;
	g_return_val_if_fail (self != NULL, 0.0F);
	result = self->priv->_rotation;
	return result;
}


void unity_launcher_scroller_child_set_rotation (UnityLauncherScrollerChild* self, float value) {
	g_return_if_fail (self != NULL);
	self->priv->_rotation = value;
	g_object_notify ((GObject *) self, "rotation");
}


static GObject * unity_launcher_scroller_child_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityLauncherScrollerChild * self;
	parent_class = G_OBJECT_CLASS (unity_launcher_scroller_child_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_LAUNCHER_SCROLLER_CHILD (obj);
	{
	}
	return obj;
}


static void unity_launcher_scroller_child_class_init (UnityLauncherScrollerChildClass * klass) {
	unity_launcher_scroller_child_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityLauncherScrollerChildPrivate));
	UNITY_LAUNCHER_SCROLLER_CHILD_CLASS (klass)->force_rotation_jump = unity_launcher_scroller_child_real_force_rotation_jump;
	G_OBJECT_CLASS (klass)->get_property = unity_launcher_scroller_child_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_launcher_scroller_child_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_launcher_scroller_child_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_launcher_scroller_child_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_LAUNCHER_SCROLLER_CHILD_ICON, g_param_spec_object ("icon", "icon", "icon", GDK_TYPE_PIXBUF, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_LAUNCHER_SCROLLER_CHILD_POSITION, g_param_spec_float ("position", "position", "position", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_LAUNCHER_SCROLLER_CHILD_RUNNING, g_param_spec_boolean ("running", "running", "running", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_LAUNCHER_SCROLLER_CHILD_ACTIVE, g_param_spec_boolean ("active", "active", "active", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_LAUNCHER_SCROLLER_CHILD_NEEDS_ATTENTION, g_param_spec_boolean ("needs-attention", "needs-attention", "needs-attention", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_LAUNCHER_SCROLLER_CHILD_ACTIVATING, g_param_spec_boolean ("activating", "activating", "activating", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_LAUNCHER_SCROLLER_CHILD_ROTATION, g_param_spec_float ("rotation", "rotation", "rotation", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void unity_launcher_scroller_child_instance_init (UnityLauncherScrollerChild * self) {
	self->priv = UNITY_LAUNCHER_SCROLLER_CHILD_GET_PRIVATE (self);
}


static void unity_launcher_scroller_child_finalize (GObject* obj) {
	UnityLauncherScrollerChild * self;
	self = UNITY_LAUNCHER_SCROLLER_CHILD (obj);
	_g_object_unref0 (self->priv->_icon);
	G_OBJECT_CLASS (unity_launcher_scroller_child_parent_class)->finalize (obj);
}


GType unity_launcher_scroller_child_get_type (void) {
	static volatile gsize unity_launcher_scroller_child_type_id__volatile = 0;
	if (g_once_init_enter (&unity_launcher_scroller_child_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityLauncherScrollerChildClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_launcher_scroller_child_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityLauncherScrollerChild), 0, (GInstanceInitFunc) unity_launcher_scroller_child_instance_init, NULL };
		GType unity_launcher_scroller_child_type_id;
		unity_launcher_scroller_child_type_id = g_type_register_static (CTK_TYPE_ACTOR, "UnityLauncherScrollerChild", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&unity_launcher_scroller_child_type_id__volatile, unity_launcher_scroller_child_type_id);
	}
	return unity_launcher_scroller_child_type_id__volatile;
}


static void unity_launcher_scroller_child_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityLauncherScrollerChild * self;
	self = UNITY_LAUNCHER_SCROLLER_CHILD (object);
	switch (property_id) {
		case UNITY_LAUNCHER_SCROLLER_CHILD_ICON:
		g_value_set_object (value, unity_launcher_scroller_child_get_icon (self));
		break;
		case UNITY_LAUNCHER_SCROLLER_CHILD_POSITION:
		g_value_set_float (value, unity_launcher_scroller_child_get_position (self));
		break;
		case UNITY_LAUNCHER_SCROLLER_CHILD_RUNNING:
		g_value_set_boolean (value, unity_launcher_scroller_child_get_running (self));
		break;
		case UNITY_LAUNCHER_SCROLLER_CHILD_ACTIVE:
		g_value_set_boolean (value, unity_launcher_scroller_child_get_active (self));
		break;
		case UNITY_LAUNCHER_SCROLLER_CHILD_NEEDS_ATTENTION:
		g_value_set_boolean (value, unity_launcher_scroller_child_get_needs_attention (self));
		break;
		case UNITY_LAUNCHER_SCROLLER_CHILD_ACTIVATING:
		g_value_set_boolean (value, unity_launcher_scroller_child_get_activating (self));
		break;
		case UNITY_LAUNCHER_SCROLLER_CHILD_ROTATION:
		g_value_set_float (value, unity_launcher_scroller_child_get_rotation (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_launcher_scroller_child_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityLauncherScrollerChild * self;
	self = UNITY_LAUNCHER_SCROLLER_CHILD (object);
	switch (property_id) {
		case UNITY_LAUNCHER_SCROLLER_CHILD_ICON:
		unity_launcher_scroller_child_set_icon (self, g_value_get_object (value));
		break;
		case UNITY_LAUNCHER_SCROLLER_CHILD_POSITION:
		unity_launcher_scroller_child_set_position (self, g_value_get_float (value));
		break;
		case UNITY_LAUNCHER_SCROLLER_CHILD_RUNNING:
		unity_launcher_scroller_child_set_running (self, g_value_get_boolean (value));
		break;
		case UNITY_LAUNCHER_SCROLLER_CHILD_ACTIVE:
		unity_launcher_scroller_child_set_active (self, g_value_get_boolean (value));
		break;
		case UNITY_LAUNCHER_SCROLLER_CHILD_NEEDS_ATTENTION:
		unity_launcher_scroller_child_set_needs_attention (self, g_value_get_boolean (value));
		break;
		case UNITY_LAUNCHER_SCROLLER_CHILD_ACTIVATING:
		unity_launcher_scroller_child_set_activating (self, g_value_get_boolean (value));
		break;
		case UNITY_LAUNCHER_SCROLLER_CHILD_ROTATION:
		unity_launcher_scroller_child_set_rotation (self, g_value_get_float (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




