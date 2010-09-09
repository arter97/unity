/* places-volume-child-controller.c generated by valac, the Vala compiler
 * generated from places-volume-child-controller.vala, do not modify */

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
#include <unity.h>
#include <libdbusmenu-glib/client.h>
#include <libdbusmenu-glib/menuitem-proxy.h>
#include <libdbusmenu-glib/menuitem.h>
#include <libdbusmenu-glib/server.h>
#include <float.h>
#include <math.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <clutk/clutk.h>
#include <gee.h>
#include <glib/gi18n-lib.h>


#define UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER (unity_launcher_scroller_child_controller_get_type ())
#define UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, UnityLauncherScrollerChildController))
#define UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, UnityLauncherScrollerChildControllerClass))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER))
#define UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, UnityLauncherScrollerChildControllerClass))

typedef struct _UnityLauncherScrollerChildController UnityLauncherScrollerChildController;
typedef struct _UnityLauncherScrollerChildControllerClass UnityLauncherScrollerChildControllerClass;
typedef struct _UnityLauncherScrollerChildControllerPrivate UnityLauncherScrollerChildControllerPrivate;

#define UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER (unity_launcher_quicklist_controller_get_type ())
#define UNITY_LAUNCHER_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityLauncherQuicklistController))
#define UNITY_LAUNCHER_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityLauncherQuicklistControllerClass))
#define UNITY_LAUNCHER_IS_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER))
#define UNITY_LAUNCHER_IS_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER))
#define UNITY_LAUNCHER_QUICKLIST_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityLauncherQuicklistControllerClass))

typedef struct _UnityLauncherQuicklistController UnityLauncherQuicklistController;
typedef struct _UnityLauncherQuicklistControllerClass UnityLauncherQuicklistControllerClass;

#define UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER_MENU_STATE (unity_launcher_scroller_child_controller_menu_state_get_type ())

#define UNITY_PLACES_TYPE_VOLUME_CHILD_CONTROLLER (unity_places_volume_child_controller_get_type ())
#define UNITY_PLACES_VOLUME_CHILD_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_VOLUME_CHILD_CONTROLLER, UnityPlacesVolumeChildController))
#define UNITY_PLACES_VOLUME_CHILD_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_VOLUME_CHILD_CONTROLLER, UnityPlacesVolumeChildControllerClass))
#define UNITY_PLACES_IS_VOLUME_CHILD_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_VOLUME_CHILD_CONTROLLER))
#define UNITY_PLACES_IS_VOLUME_CHILD_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_VOLUME_CHILD_CONTROLLER))
#define UNITY_PLACES_VOLUME_CHILD_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_VOLUME_CHILD_CONTROLLER, UnityPlacesVolumeChildControllerClass))

typedef struct _UnityPlacesVolumeChildController UnityPlacesVolumeChildController;
typedef struct _UnityPlacesVolumeChildControllerClass UnityPlacesVolumeChildControllerClass;
typedef struct _UnityPlacesVolumeChildControllerPrivate UnityPlacesVolumeChildControllerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_LAUNCHER_TYPE_SCROLLER_CHILD (unity_launcher_scroller_child_get_type ())
#define UNITY_LAUNCHER_SCROLLER_CHILD(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChild))
#define UNITY_LAUNCHER_SCROLLER_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChildClass))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD))
#define UNITY_LAUNCHER_SCROLLER_CHILD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChildClass))

typedef struct _UnityLauncherScrollerChild UnityLauncherScrollerChild;
typedef struct _UnityLauncherScrollerChildClass UnityLauncherScrollerChildClass;

#define UNITY_LAUNCHER_TYPE_SCROLLER_MODEL (unity_launcher_scroller_model_get_type ())
#define UNITY_LAUNCHER_SCROLLER_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL, UnityLauncherScrollerModel))
#define UNITY_LAUNCHER_SCROLLER_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL, UnityLauncherScrollerModelClass))
#define UNITY_LAUNCHER_IS_SCROLLER_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL))
#define UNITY_LAUNCHER_IS_SCROLLER_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL))
#define UNITY_LAUNCHER_SCROLLER_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_MODEL, UnityLauncherScrollerModelClass))

typedef struct _UnityLauncherScrollerModel UnityLauncherScrollerModel;
typedef struct _UnityLauncherScrollerModelClass UnityLauncherScrollerModelClass;

#define UNITY_TESTING_TYPE_OBJECT_REGISTRY (unity_testing_object_registry_get_type ())
#define UNITY_TESTING_OBJECT_REGISTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistry))
#define UNITY_TESTING_OBJECT_REGISTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistryClass))
#define UNITY_TESTING_IS_OBJECT_REGISTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY))
#define UNITY_TESTING_IS_OBJECT_REGISTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTING_TYPE_OBJECT_REGISTRY))
#define UNITY_TESTING_OBJECT_REGISTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTING_TYPE_OBJECT_REGISTRY, UnityTestingObjectRegistryClass))

typedef struct _UnityTestingObjectRegistry UnityTestingObjectRegistry;
typedef struct _UnityTestingObjectRegistryClass UnityTestingObjectRegistryClass;
#define _unity_testing_object_registry_unref0(var) ((var == NULL) ? NULL : (var = (unity_testing_object_registry_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER (unity_launcher_application_quicklist_controller_get_type ())
#define UNITY_LAUNCHER_APPLICATION_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER, UnityLauncherApplicationQuicklistController))
#define UNITY_LAUNCHER_APPLICATION_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER, UnityLauncherApplicationQuicklistControllerClass))
#define UNITY_LAUNCHER_IS_APPLICATION_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER))
#define UNITY_LAUNCHER_IS_APPLICATION_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER))
#define UNITY_LAUNCHER_APPLICATION_QUICKLIST_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER, UnityLauncherApplicationQuicklistControllerClass))

typedef struct _UnityLauncherApplicationQuicklistController UnityLauncherApplicationQuicklistController;
typedef struct _UnityLauncherApplicationQuicklistControllerClass UnityLauncherApplicationQuicklistControllerClass;

#define UNITY_LAUNCHER_SCROLLER_CHILD_TYPE_GROUP_TYPE (unity_launcher_scroller_child_group_type_get_type ())

typedef void (*UnityLauncherScrollerChildControllermenu_cb) (DbusmenuMenuitem* menu, void* user_data);
typedef enum  {
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_NO_MENU,
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_LABEL,
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_MENU,
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_MENU_CLOSE_WHEN_LEAVE
} UnityLauncherScrollerChildControllerMenuState;

struct _UnityLauncherScrollerChildController {
	GObject parent_instance;
	UnityLauncherScrollerChildControllerPrivate * priv;
	UnityLauncherScrollerChildControllerMenuState menu_state;
	guint32 last_press_time;
	gboolean button_down;
	float click_start_pos_x;
	float click_start_pos_y;
	gint drag_sensitivity;
};

struct _UnityLauncherScrollerChildControllerClass {
	GObjectClass parent_class;
	void (*get_menu_actions) (UnityLauncherScrollerChildController* self, UnityLauncherScrollerChildControllermenu_cb callback, void* callback_target);
	void (*get_menu_navigation) (UnityLauncherScrollerChildController* self, UnityLauncherScrollerChildControllermenu_cb callback, void* callback_target);
	void (*activate) (UnityLauncherScrollerChildController* self);
	UnityLauncherQuicklistController* (*get_menu_controller) (UnityLauncherScrollerChildController* self);
	gboolean (*can_drag) (UnityLauncherScrollerChildController* self);
};

struct _UnityPlacesVolumeChildController {
	UnityLauncherScrollerChildController parent_instance;
	UnityPlacesVolumeChildControllerPrivate * priv;
};

struct _UnityPlacesVolumeChildControllerClass {
	UnityLauncherScrollerChildControllerClass parent_class;
};

struct _UnityPlacesVolumeChildControllerPrivate {
	GVolume* _volume;
};

typedef enum  {
	UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_APPLICATION,
	UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_PLACE,
	UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_DEVICE,
	UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_SYSTEM
} UnityLauncherScrollerChildGroupType;


static gpointer unity_places_volume_child_controller_parent_class = NULL;

GType unity_launcher_scroller_child_controller_get_type (void) G_GNUC_CONST;
GType unity_launcher_quicklist_controller_get_type (void) G_GNUC_CONST;
GType unity_launcher_scroller_child_controller_menu_state_get_type (void) G_GNUC_CONST;
GType unity_places_volume_child_controller_get_type (void) G_GNUC_CONST;
#define UNITY_PLACES_VOLUME_CHILD_CONTROLLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_VOLUME_CHILD_CONTROLLER, UnityPlacesVolumeChildControllerPrivate))
enum  {
	UNITY_PLACES_VOLUME_CHILD_CONTROLLER_DUMMY_PROPERTY,
	UNITY_PLACES_VOLUME_CHILD_CONTROLLER_VOLUME
};
#define UNITY_PLACES_VOLUME_CHILD_CONTROLLER_ICON "/usr/share/unity/devices.png"
UnityLauncherScrollerChild* unity_launcher_scroller_child_new (void);
UnityLauncherScrollerChild* unity_launcher_scroller_child_construct (GType object_type);
GType unity_launcher_scroller_child_get_type (void) G_GNUC_CONST;
UnityPlacesVolumeChildController* unity_places_volume_child_controller_new (GVolume* volume);
UnityPlacesVolumeChildController* unity_places_volume_child_controller_construct (GType object_type, GVolume* volume);
GType unity_launcher_scroller_model_get_type (void) G_GNUC_CONST;
gpointer unity_testing_object_registry_ref (gpointer instance);
void unity_testing_object_registry_unref (gpointer instance);
GParamSpec* unity_testing_param_spec_object_registry (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_testing_value_set_object_registry (GValue* value, gpointer v_object);
void unity_testing_value_take_object_registry (GValue* value, gpointer v_object);
gpointer unity_testing_value_get_object_registry (const GValue* value);
GType unity_testing_object_registry_get_type (void) G_GNUC_CONST;
UnityTestingObjectRegistry* unity_testing_object_registry_get_default (void);
GeeArrayList* unity_testing_object_registry_lookup (UnityTestingObjectRegistry* self, const char* name);
void unity_launcher_scroller_model_remove (UnityLauncherScrollerModel* self, UnityLauncherScrollerChild* child);
UnityLauncherScrollerChild* unity_launcher_scroller_child_controller_get_child (UnityLauncherScrollerChildController* self);
static void unity_places_volume_child_controller_on_volume_removed (UnityPlacesVolumeChildController* self);
GVolume* unity_places_volume_child_controller_get_volume (UnityPlacesVolumeChildController* self);
static void unity_places_volume_child_controller_open_volume (UnityPlacesVolumeChildController* self);
void utils_volume_eject (GVolume* volume);
static void unity_places_volume_child_controller_eject_volume (UnityPlacesVolumeChildController* self);
static void unity_places_volume_child_controller_real_activate (UnityLauncherScrollerChildController* base);
UnityLauncherApplicationQuicklistController* unity_launcher_application_quicklist_controller_new (UnityLauncherScrollerChildController* scroller_child);
UnityLauncherApplicationQuicklistController* unity_launcher_application_quicklist_controller_construct (GType object_type, UnityLauncherScrollerChildController* scroller_child);
GType unity_launcher_application_quicklist_controller_get_type (void) G_GNUC_CONST;
static UnityLauncherQuicklistController* unity_places_volume_child_controller_real_get_menu_controller (UnityLauncherScrollerChildController* base);
static void _unity_places_volume_child_controller_open_volume_dbusmenu_menuitem_item_activated (DbusmenuMenuitem* _sender, guint object, gpointer self);
static void unity_places_volume_child_controller_real_get_menu_actions (UnityLauncherScrollerChildController* base, UnityLauncherScrollerChildControllermenu_cb callback, void* callback_target);
static void _unity_places_volume_child_controller_eject_volume_dbusmenu_menuitem_item_activated (DbusmenuMenuitem* _sender, guint object, gpointer self);
static void unity_places_volume_child_controller_real_get_menu_navigation (UnityLauncherScrollerChildController* base, UnityLauncherScrollerChildControllermenu_cb callback, void* callback_target);
static gboolean unity_places_volume_child_controller_real_can_drag (UnityLauncherScrollerChildController* base);
static void unity_places_volume_child_controller_set_volume (UnityPlacesVolumeChildController* self, GVolume* value);
void unity_launcher_scroller_child_controller_set_name (UnityLauncherScrollerChildController* self, const char* value);
void unity_launcher_scroller_child_controller_load_icon_from_icon_name (UnityLauncherScrollerChildController* self, const char* icon_name);
GType unity_launcher_scroller_child_group_type_get_type (void) G_GNUC_CONST;
void unity_launcher_scroller_child_set_group_type (UnityLauncherScrollerChild* self, UnityLauncherScrollerChildGroupType value);
static void _unity_places_volume_child_controller_eject_volume_unity_launcher_scroller_child_drag_removed (UnityLauncherScrollerChild* _sender, gpointer self);
static void _unity_places_volume_child_controller_on_volume_removed_g_volume_removed (GVolume* _sender, gpointer self);
static GObject * unity_places_volume_child_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_volume_child_controller_finalize (GObject* obj);
static void unity_places_volume_child_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_volume_child_controller_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UnityPlacesVolumeChildController* unity_places_volume_child_controller_construct (GType object_type, GVolume* volume) {
	UnityPlacesVolumeChildController * self;
	UnityLauncherScrollerChild* _tmp0_;
	g_return_val_if_fail (volume != NULL, NULL);
	self = (UnityPlacesVolumeChildController*) g_object_new (object_type, "child", _tmp0_ = g_object_ref_sink (g_object_ref_sink (unity_launcher_scroller_child_new ())), "volume", volume, NULL);
	_g_object_unref0 (_tmp0_);
	return self;
}


UnityPlacesVolumeChildController* unity_places_volume_child_controller_new (GVolume* volume) {
	return unity_places_volume_child_controller_construct (UNITY_PLACES_TYPE_VOLUME_CHILD_CONTROLLER, volume);
}


static void unity_places_volume_child_controller_on_volume_removed (UnityPlacesVolumeChildController* self) {
	UnityLauncherScrollerModel* s;
	UnityLauncherScrollerModel* _tmp3_;
	GeeArrayList* _tmp1_;
	UnityTestingObjectRegistry* _tmp0_;
	GObject* _tmp2_;
	g_return_if_fail (self != NULL);
	s = NULL;
	s = (_tmp3_ = (_tmp2_ = (GObject*) gee_abstract_list_get ((GeeAbstractList*) (_tmp1_ = unity_testing_object_registry_lookup (_tmp0_ = unity_testing_object_registry_get_default (), "UnityScrollerModel")), 0), UNITY_LAUNCHER_IS_SCROLLER_MODEL (_tmp2_) ? ((UnityLauncherScrollerModel*) _tmp2_) : NULL), _g_object_unref0 (s), _tmp3_);
	_g_object_unref0 (_tmp1_);
	_unity_testing_object_registry_unref0 (_tmp0_);
	unity_launcher_scroller_model_remove (s, unity_launcher_scroller_child_controller_get_child ((UnityLauncherScrollerChildController*) self));
	g_object_unref ((GObject*) self);
	_g_object_unref0 (s);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static const char* string_to_string (const char* self) {
	const char* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void unity_places_volume_child_controller_open_volume (UnityPlacesVolumeChildController* self) {
	GError * _inner_error_;
	GMount* mount;
	char* error_msg;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	mount = _g_object_ref0 (g_volume_get_mount (self->priv->_volume));
	error_msg = g_strconcat ("Cannot open volume '", string_to_string (g_volume_get_name (self->priv->_volume)), "': ", NULL);
	if (G_IS_MOUNT (mount)) {
		GFile* loc;
		loc = _g_object_ref0 (g_mount_get_root (mount));
		{
			char* _tmp0_;
			g_app_info_launch_default_for_uri (_tmp0_ = g_file_get_uri (loc), NULL, &_inner_error_);
			_g_free0 (_tmp0_);
			if (_inner_error_ != NULL) {
				goto __catch42_g_error;
			}
		}
		goto __finally42;
		__catch42_g_error:
		{
			GError * err;
			err = _inner_error_;
			_inner_error_ = NULL;
			{
				char* _tmp1_;
				g_warning ("places-volume-child-controller.vala:69: %s", _tmp1_ = g_strconcat (error_msg, err->message, NULL));
				_g_free0 (_tmp1_);
				_g_error_free0 (err);
			}
		}
		__finally42:
		if (_inner_error_ != NULL) {
			_g_object_unref0 (loc);
			_g_free0 (error_msg);
			_g_object_unref0 (mount);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		_g_object_unref0 (loc);
	} else {
		if (g_volume_can_mount (self->priv->_volume) == FALSE) {
			char* _tmp2_;
			g_warning ("places-volume-child-controller.vala:76: %s", _tmp2_ = g_strconcat (error_msg, "Cannot be mounted", NULL));
			_g_free0 (_tmp2_);
			_g_free0 (error_msg);
			_g_object_unref0 (mount);
			return;
		}
		{
			GMount* _tmp3_;
			g_volume_mount (self->priv->_volume, 0, NULL, NULL, NULL, NULL);
			mount = (_tmp3_ = _g_object_ref0 (g_volume_get_mount (self->priv->_volume)), _g_object_unref0 (mount), _tmp3_);
			if (G_IS_MOUNT (mount)) {
				char* _tmp4_;
				g_app_info_launch_default_for_uri (_tmp4_ = g_file_get_uri (g_mount_get_root (mount)), NULL, &_inner_error_);
				_g_free0 (_tmp4_);
				if (_inner_error_ != NULL) {
					goto __catch43_g_error;
				}
			} else {
				char* _tmp5_;
				g_warning ("places-volume-child-controller.vala:86: %s", _tmp5_ = g_strconcat (error_msg, "Unable to mount", NULL));
				_g_free0 (_tmp5_);
			}
		}
		goto __finally43;
		__catch43_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				char* _tmp6_;
				g_warning ("places-volume-child-controller.vala:89: %s", _tmp6_ = g_strconcat (error_msg, e->message, NULL));
				_g_free0 (_tmp6_);
				_g_error_free0 (e);
			}
		}
		__finally43:
		if (_inner_error_ != NULL) {
			_g_free0 (error_msg);
			_g_object_unref0 (mount);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	_g_free0 (error_msg);
	_g_object_unref0 (mount);
}


static void unity_places_volume_child_controller_eject_volume (UnityPlacesVolumeChildController* self) {
	g_return_if_fail (self != NULL);
	utils_volume_eject (self->priv->_volume);
}


static void unity_places_volume_child_controller_real_activate (UnityLauncherScrollerChildController* base) {
	UnityPlacesVolumeChildController * self;
	self = (UnityPlacesVolumeChildController*) base;
	unity_places_volume_child_controller_open_volume (self);
}


static UnityLauncherQuicklistController* unity_places_volume_child_controller_real_get_menu_controller (UnityLauncherScrollerChildController* base) {
	UnityPlacesVolumeChildController * self;
	UnityLauncherQuicklistController* result = NULL;
	self = (UnityPlacesVolumeChildController*) base;
	result = (UnityLauncherQuicklistController*) unity_launcher_application_quicklist_controller_new ((UnityLauncherScrollerChildController*) self);
	return result;
}


static void _unity_places_volume_child_controller_open_volume_dbusmenu_menuitem_item_activated (DbusmenuMenuitem* _sender, guint object, gpointer self) {
	unity_places_volume_child_controller_open_volume (self);
}


static void unity_places_volume_child_controller_real_get_menu_actions (UnityLauncherScrollerChildController* base, UnityLauncherScrollerChildControllermenu_cb callback, void* callback_target) {
	UnityPlacesVolumeChildController * self;
	DbusmenuMenuitem* root;
	DbusmenuMenuitem* item;
	DbusmenuMenuitem* _tmp0_;
	self = (UnityPlacesVolumeChildController*) base;
	root = dbusmenu_menuitem_new ();
	dbusmenu_menuitem_set_root (root, TRUE);
	item = NULL;
	item = (_tmp0_ = dbusmenu_menuitem_new (), _g_object_unref0 (item), _tmp0_);
	dbusmenu_menuitem_property_set (item, DBUSMENU_MENUITEM_PROP_LABEL, _ ("Open"));
	dbusmenu_menuitem_property_set_bool (item, DBUSMENU_MENUITEM_PROP_ENABLED, TRUE);
	dbusmenu_menuitem_property_set_bool (item, DBUSMENU_MENUITEM_PROP_VISIBLE, TRUE);
	g_signal_connect_object (item, "item-activated", (GCallback) _unity_places_volume_child_controller_open_volume_dbusmenu_menuitem_item_activated, self, 0);
	dbusmenu_menuitem_child_append (root, item);
	callback (root, callback_target);
	_g_object_unref0 (item);
	_g_object_unref0 (root);
}


static void _unity_places_volume_child_controller_eject_volume_dbusmenu_menuitem_item_activated (DbusmenuMenuitem* _sender, guint object, gpointer self) {
	unity_places_volume_child_controller_eject_volume (self);
}


static void unity_places_volume_child_controller_real_get_menu_navigation (UnityLauncherScrollerChildController* base, UnityLauncherScrollerChildControllermenu_cb callback, void* callback_target) {
	UnityPlacesVolumeChildController * self;
	DbusmenuMenuitem* root;
	self = (UnityPlacesVolumeChildController*) base;
	root = dbusmenu_menuitem_new ();
	dbusmenu_menuitem_set_root (root, TRUE);
	if (g_volume_get_mount (self->priv->_volume) != NULL) {
		DbusmenuMenuitem* item;
		DbusmenuMenuitem* _tmp0_;
		item = NULL;
		item = (_tmp0_ = dbusmenu_menuitem_new (), _g_object_unref0 (item), _tmp0_);
		dbusmenu_menuitem_property_set (item, DBUSMENU_MENUITEM_PROP_LABEL, _ ("Eject"));
		dbusmenu_menuitem_property_set_bool (item, DBUSMENU_MENUITEM_PROP_ENABLED, TRUE);
		dbusmenu_menuitem_property_set_bool (item, DBUSMENU_MENUITEM_PROP_VISIBLE, TRUE);
		dbusmenu_menuitem_child_append (root, item);
		g_signal_connect_object (item, "item-activated", (GCallback) _unity_places_volume_child_controller_eject_volume_dbusmenu_menuitem_item_activated, self, 0);
		_g_object_unref0 (item);
	}
	callback (root, callback_target);
	_g_object_unref0 (root);
}


static gboolean unity_places_volume_child_controller_real_can_drag (UnityLauncherScrollerChildController* base) {
	UnityPlacesVolumeChildController * self;
	gboolean result = FALSE;
	self = (UnityPlacesVolumeChildController*) base;
	result = TRUE;
	return result;
}


GVolume* unity_places_volume_child_controller_get_volume (UnityPlacesVolumeChildController* self) {
	GVolume* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_volume;
	return result;
}


static void unity_places_volume_child_controller_set_volume (UnityPlacesVolumeChildController* self, GVolume* value) {
	GVolume* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_volume = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_volume), _tmp0_);
	g_object_notify ((GObject *) self, "volume");
}


static void _unity_places_volume_child_controller_eject_volume_unity_launcher_scroller_child_drag_removed (UnityLauncherScrollerChild* _sender, gpointer self) {
	unity_places_volume_child_controller_eject_volume (self);
}


static void _unity_places_volume_child_controller_on_volume_removed_g_volume_removed (GVolume* _sender, gpointer self) {
	unity_places_volume_child_controller_on_volume_removed (self);
}


static GObject * unity_places_volume_child_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesVolumeChildController * self;
	parent_class = G_OBJECT_CLASS (unity_places_volume_child_controller_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_VOLUME_CHILD_CONTROLLER (obj);
	{
		unity_launcher_scroller_child_controller_set_name ((UnityLauncherScrollerChildController*) self, g_volume_get_name (self->priv->_volume));
		unity_launcher_scroller_child_controller_load_icon_from_icon_name ((UnityLauncherScrollerChildController*) self, UNITY_PLACES_VOLUME_CHILD_CONTROLLER_ICON);
		unity_launcher_scroller_child_set_group_type (unity_launcher_scroller_child_controller_get_child ((UnityLauncherScrollerChildController*) self), UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_DEVICE);
		g_signal_connect_object (unity_launcher_scroller_child_controller_get_child ((UnityLauncherScrollerChildController*) self), "drag-removed", (GCallback) _unity_places_volume_child_controller_eject_volume_unity_launcher_scroller_child_drag_removed, self, 0);
		g_signal_connect_object (self->priv->_volume, "removed", (GCallback) _unity_places_volume_child_controller_on_volume_removed_g_volume_removed, self, 0);
	}
	return obj;
}


static void unity_places_volume_child_controller_class_init (UnityPlacesVolumeChildControllerClass * klass) {
	unity_places_volume_child_controller_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesVolumeChildControllerPrivate));
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->activate = unity_places_volume_child_controller_real_activate;
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->get_menu_controller = unity_places_volume_child_controller_real_get_menu_controller;
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->get_menu_actions = unity_places_volume_child_controller_real_get_menu_actions;
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->get_menu_navigation = unity_places_volume_child_controller_real_get_menu_navigation;
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->can_drag = unity_places_volume_child_controller_real_can_drag;
	G_OBJECT_CLASS (klass)->get_property = unity_places_volume_child_controller_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_volume_child_controller_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_places_volume_child_controller_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_volume_child_controller_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_VOLUME_CHILD_CONTROLLER_VOLUME, g_param_spec_object ("volume", "volume", "volume", G_TYPE_VOLUME, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_places_volume_child_controller_instance_init (UnityPlacesVolumeChildController * self) {
	self->priv = UNITY_PLACES_VOLUME_CHILD_CONTROLLER_GET_PRIVATE (self);
}


static void unity_places_volume_child_controller_finalize (GObject* obj) {
	UnityPlacesVolumeChildController * self;
	self = UNITY_PLACES_VOLUME_CHILD_CONTROLLER (obj);
	_g_object_unref0 (self->priv->_volume);
	G_OBJECT_CLASS (unity_places_volume_child_controller_parent_class)->finalize (obj);
}


GType unity_places_volume_child_controller_get_type (void) {
	static volatile gsize unity_places_volume_child_controller_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_volume_child_controller_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesVolumeChildControllerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_volume_child_controller_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesVolumeChildController), 0, (GInstanceInitFunc) unity_places_volume_child_controller_instance_init, NULL };
		GType unity_places_volume_child_controller_type_id;
		unity_places_volume_child_controller_type_id = g_type_register_static (UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, "UnityPlacesVolumeChildController", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_volume_child_controller_type_id__volatile, unity_places_volume_child_controller_type_id);
	}
	return unity_places_volume_child_controller_type_id__volatile;
}


static void unity_places_volume_child_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesVolumeChildController * self;
	self = UNITY_PLACES_VOLUME_CHILD_CONTROLLER (object);
	switch (property_id) {
		case UNITY_PLACES_VOLUME_CHILD_CONTROLLER_VOLUME:
		g_value_set_object (value, unity_places_volume_child_controller_get_volume (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_volume_child_controller_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesVolumeChildController * self;
	self = UNITY_PLACES_VOLUME_CHILD_CONTROLLER (object);
	switch (property_id) {
		case UNITY_PLACES_VOLUME_CHILD_CONTROLLER_VOLUME:
		unity_places_volume_child_controller_set_volume (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




