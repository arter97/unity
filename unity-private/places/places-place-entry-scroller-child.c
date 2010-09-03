/* places-place-entry-scroller-child.c generated by valac 0.9.7, the Vala compiler
 * generated from places-place-entry-scroller-child.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <dee.h>
#include <clutk/clutk.h>
#include <clutter/clutter.h>


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

#define UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER (unity_places_place_entry_scroller_child_controller_get_type ())
#define UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER, UnityPlacesPlaceEntryScrollerChildController))
#define UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER, UnityPlacesPlaceEntryScrollerChildControllerClass))
#define UNITY_PLACES_IS_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER))
#define UNITY_PLACES_IS_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER))
#define UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER, UnityPlacesPlaceEntryScrollerChildControllerClass))

typedef struct _UnityPlacesPlaceEntryScrollerChildController UnityPlacesPlaceEntryScrollerChildController;
typedef struct _UnityPlacesPlaceEntryScrollerChildControllerClass UnityPlacesPlaceEntryScrollerChildControllerClass;
typedef struct _UnityPlacesPlaceEntryScrollerChildControllerPrivate UnityPlacesPlaceEntryScrollerChildControllerPrivate;

#define UNITY_PLACES_TYPE_PLACE_ENTRY (unity_places_place_entry_get_type ())
#define UNITY_PLACES_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntry))
#define UNITY_PLACES_IS_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY))
#define UNITY_PLACES_PLACE_ENTRY_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntryIface))

typedef struct _UnityPlacesPlaceEntry UnityPlacesPlaceEntry;
typedef struct _UnityPlacesPlaceEntryIface UnityPlacesPlaceEntryIface;

#define UNITY_PLACES_TYPE_PLACE (unity_places_place_get_type ())
#define UNITY_PLACES_PLACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlace))
#define UNITY_PLACES_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))
#define UNITY_PLACES_IS_PLACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_IS_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_PLACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))

typedef struct _UnityPlacesPlace UnityPlacesPlace;
typedef struct _UnityPlacesPlaceClass UnityPlacesPlaceClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_LAUNCHER_TYPE_SCROLLER_CHILD (unity_launcher_scroller_child_get_type ())
#define UNITY_LAUNCHER_SCROLLER_CHILD(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChild))
#define UNITY_LAUNCHER_SCROLLER_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChildClass))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD))
#define UNITY_LAUNCHER_SCROLLER_CHILD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChildClass))

typedef struct _UnityLauncherScrollerChild UnityLauncherScrollerChild;
typedef struct _UnityLauncherScrollerChildClass UnityLauncherScrollerChildClass;

#define UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER (unity_launcher_application_quicklist_controller_get_type ())
#define UNITY_LAUNCHER_APPLICATION_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER, UnityLauncherApplicationQuicklistController))
#define UNITY_LAUNCHER_APPLICATION_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER, UnityLauncherApplicationQuicklistControllerClass))
#define UNITY_LAUNCHER_IS_APPLICATION_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER))
#define UNITY_LAUNCHER_IS_APPLICATION_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER))
#define UNITY_LAUNCHER_APPLICATION_QUICKLIST_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_APPLICATION_QUICKLIST_CONTROLLER, UnityLauncherApplicationQuicklistControllerClass))

typedef struct _UnityLauncherApplicationQuicklistController UnityLauncherApplicationQuicklistController;
typedef struct _UnityLauncherApplicationQuicklistControllerClass UnityLauncherApplicationQuicklistControllerClass;
typedef struct _Block3Data Block3Data;
#define _g_free0(var) (var = (g_free (var), NULL))

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

struct _UnityPlacesPlaceEntryScrollerChildController {
	UnityLauncherScrollerChildController parent_instance;
	UnityPlacesPlaceEntryScrollerChildControllerPrivate * priv;
};

struct _UnityPlacesPlaceEntryScrollerChildControllerClass {
	UnityLauncherScrollerChildControllerClass parent_class;
};

struct _UnityPlacesPlaceEntryIface {
	GTypeInterface parent_iface;
	void (*connect) (UnityPlacesPlaceEntry* self);
	void (*set_search) (UnityPlacesPlaceEntry* self, const char* search, GHashTable* hints);
	void (*set_active_section) (UnityPlacesPlaceEntry* self, guint section_id);
	void (*set_global_search) (UnityPlacesPlaceEntry* self, const char* search, GHashTable* hints);
	const char* (*get_name) (UnityPlacesPlaceEntry* self);
	void (*set_name) (UnityPlacesPlaceEntry* self, const char* value);
	const char* (*get_icon) (UnityPlacesPlaceEntry* self);
	void (*set_icon) (UnityPlacesPlaceEntry* self, const char* value);
	const char* (*get_description) (UnityPlacesPlaceEntry* self);
	void (*set_description) (UnityPlacesPlaceEntry* self, const char* value);
	guint (*get_position) (UnityPlacesPlaceEntry* self);
	void (*set_position) (UnityPlacesPlaceEntry* self, guint value);
	char** (*get_mimetypes) (UnityPlacesPlaceEntry* self, int* result_length1);
	void (*set_mimetypes) (UnityPlacesPlaceEntry* self, char** value, int value_length1);
	gboolean (*get_sensitive) (UnityPlacesPlaceEntry* self);
	void (*set_sensitive) (UnityPlacesPlaceEntry* self, gboolean value);
	GeeHashMap* (*get_hints) (UnityPlacesPlaceEntry* self);
	void (*set_hints) (UnityPlacesPlaceEntry* self, GeeHashMap* value);
	gboolean (*get_online) (UnityPlacesPlaceEntry* self);
	void (*set_online) (UnityPlacesPlaceEntry* self, gboolean value);
	gboolean (*get_active) (UnityPlacesPlaceEntry* self);
	void (*set_active) (UnityPlacesPlaceEntry* self, gboolean value);
	DeeModel* (*get_sections_model) (UnityPlacesPlaceEntry* self);
	void (*set_sections_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	const char* (*get_entry_renderer_name) (UnityPlacesPlaceEntry* self);
	void (*set_entry_renderer_name) (UnityPlacesPlaceEntry* self, const char* value);
	DeeModel* (*get_entry_groups_model) (UnityPlacesPlaceEntry* self);
	void (*set_entry_groups_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	DeeModel* (*get_entry_results_model) (UnityPlacesPlaceEntry* self);
	void (*set_entry_results_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	GeeHashMap* (*get_entry_renderer_hints) (UnityPlacesPlaceEntry* self);
	void (*set_entry_renderer_hints) (UnityPlacesPlaceEntry* self, GeeHashMap* value);
	const char* (*get_global_renderer_name) (UnityPlacesPlaceEntry* self);
	void (*set_global_renderer_name) (UnityPlacesPlaceEntry* self, const char* value);
	DeeModel* (*get_global_groups_model) (UnityPlacesPlaceEntry* self);
	void (*set_global_groups_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	DeeModel* (*get_global_results_model) (UnityPlacesPlaceEntry* self);
	void (*set_global_results_model) (UnityPlacesPlaceEntry* self, DeeModel* value);
	GeeHashMap* (*get_global_renderer_hints) (UnityPlacesPlaceEntry* self);
	void (*set_global_renderer_hints) (UnityPlacesPlaceEntry* self, GeeHashMap* value);
	UnityPlacesPlace* (*get_parent) (UnityPlacesPlaceEntry* self);
	void (*set_parent) (UnityPlacesPlaceEntry* self, UnityPlacesPlace* value);
};

struct _UnityPlacesPlaceEntryScrollerChildControllerPrivate {
	UnityPlacesPlaceEntry* _entry;
};

struct _Block3Data {
	int _ref_count_;
	UnityPlacesPlaceEntryScrollerChildController * self;
	DbusmenuMenuitem* item;
};

typedef enum  {
	UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_APPLICATION,
	UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_PLACE,
	UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_DEVICE,
	UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_SYSTEM
} UnityLauncherScrollerChildGroupType;


static gpointer unity_places_place_entry_scroller_child_controller_parent_class = NULL;

GType unity_launcher_scroller_child_controller_get_type (void) G_GNUC_CONST;
GType unity_launcher_quicklist_controller_get_type (void) G_GNUC_CONST;
GType unity_launcher_scroller_child_controller_menu_state_get_type (void) G_GNUC_CONST;
GType unity_places_place_entry_scroller_child_controller_get_type (void) G_GNUC_CONST;
GType unity_places_place_get_type (void) G_GNUC_CONST;
GType unity_places_place_entry_get_type (void) G_GNUC_CONST;
#define UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER, UnityPlacesPlaceEntryScrollerChildControllerPrivate))
enum  {
	UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER_DUMMY_PROPERTY,
	UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER_ENTRY
};
UnityPlacesPlaceEntryScrollerChildController* unity_places_place_entry_scroller_child_controller_new (UnityPlacesPlaceEntry* entry);
UnityPlacesPlaceEntryScrollerChildController* unity_places_place_entry_scroller_child_controller_construct (GType object_type, UnityPlacesPlaceEntry* entry);
UnityLauncherScrollerChild* unity_launcher_scroller_child_new (void);
UnityLauncherScrollerChild* unity_launcher_scroller_child_construct (GType object_type);
GType unity_launcher_scroller_child_get_type (void) G_GNUC_CONST;
static gboolean unity_places_place_entry_scroller_child_controller_get_sections (UnityPlacesPlaceEntryScrollerChildController* self);
UnityPlacesPlaceEntry* unity_places_place_entry_scroller_child_controller_get_entry (UnityPlacesPlaceEntryScrollerChildController* self);
DeeModel* unity_places_place_entry_get_sections_model (UnityPlacesPlaceEntry* self);
UnityLauncherScrollerChild* unity_launcher_scroller_child_controller_get_child (UnityLauncherScrollerChildController* self);
static gboolean _unity_places_place_entry_scroller_child_controller_get_sections_clutter_actor_motion_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static void unity_places_place_entry_scroller_child_controller_real_activate (UnityLauncherScrollerChildController* base);
static UnityLauncherQuicklistController* unity_places_place_entry_scroller_child_controller_real_get_menu_controller (UnityLauncherScrollerChildController* base);
UnityLauncherApplicationQuicklistController* unity_launcher_application_quicklist_controller_new (UnityLauncherScrollerChildController* scroller_child);
UnityLauncherApplicationQuicklistController* unity_launcher_application_quicklist_controller_construct (GType object_type, UnityLauncherScrollerChildController* scroller_child);
GType unity_launcher_application_quicklist_controller_get_type (void) G_GNUC_CONST;
static void unity_places_place_entry_scroller_child_controller_real_get_menu_actions (UnityLauncherScrollerChildController* base, UnityLauncherScrollerChildControllermenu_cb callback, void* callback_target);
static void _lambda67_ (guint timestamp, Block3Data* _data3_);
static void __lambda67__dbusmenu_menuitem_item_activated (DbusmenuMenuitem* _sender, guint object, gpointer self);
static Block3Data* block3_data_ref (Block3Data* _data3_);
static void block3_data_unref (Block3Data* _data3_);
static gboolean unity_places_place_entry_scroller_child_controller_real_can_drag (UnityLauncherScrollerChildController* base);
static void unity_places_place_entry_scroller_child_controller_set_entry (UnityPlacesPlaceEntryScrollerChildController* self, UnityPlacesPlaceEntry* value);
const char* unity_places_place_entry_get_name (UnityPlacesPlaceEntry* self);
void unity_launcher_scroller_child_controller_set_name (UnityLauncherScrollerChildController* self, const char* value);
void unity_launcher_scroller_child_controller_load_icon_from_icon_name (UnityLauncherScrollerChildController* self, const char* icon_name);
const char* unity_places_place_entry_get_icon (UnityPlacesPlaceEntry* self);
static void _lambda68_ (UnityPlacesPlaceEntryScrollerChildController* self);
gboolean unity_places_place_entry_get_active (UnityPlacesPlaceEntry* self);
void unity_launcher_scroller_child_set_active (UnityLauncherScrollerChild* self, gboolean value);
static void __lambda68__g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self);
GType unity_launcher_scroller_child_group_type_get_type (void) G_GNUC_CONST;
void unity_launcher_scroller_child_set_group_type (UnityLauncherScrollerChild* self, UnityLauncherScrollerChildGroupType value);
static GObject * unity_places_place_entry_scroller_child_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_place_entry_scroller_child_controller_finalize (GObject* obj);
static void unity_places_place_entry_scroller_child_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_place_entry_scroller_child_controller_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UnityPlacesPlaceEntryScrollerChildController* unity_places_place_entry_scroller_child_controller_construct (GType object_type, UnityPlacesPlaceEntry* entry) {
	UnityPlacesPlaceEntryScrollerChildController * self;
	UnityLauncherScrollerChild* _tmp0_;
	g_return_val_if_fail (entry != NULL, NULL);
	self = (UnityPlacesPlaceEntryScrollerChildController*) g_object_new (object_type, "child", _tmp0_ = g_object_ref_sink (g_object_ref_sink (unity_launcher_scroller_child_new ())), "entry", entry, NULL);
	_g_object_unref0 (_tmp0_);
	return self;
}


UnityPlacesPlaceEntryScrollerChildController* unity_places_place_entry_scroller_child_controller_new (UnityPlacesPlaceEntry* entry) {
	return unity_places_place_entry_scroller_child_controller_construct (UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER, entry);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gboolean _unity_places_place_entry_scroller_child_controller_get_sections_clutter_actor_motion_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = unity_places_place_entry_scroller_child_controller_get_sections (self);
	return result;
}


static gboolean unity_places_place_entry_scroller_child_controller_get_sections (UnityPlacesPlaceEntryScrollerChildController* self) {
	gboolean result = FALSE;
	DeeModel* sections;
	DeeModel* _tmp0_;
	guint _tmp1_;
	g_return_val_if_fail (self != NULL, FALSE);
	sections = NULL;
	sections = (_tmp0_ = _g_object_ref0 (unity_places_place_entry_get_sections_model (self->priv->_entry)), _g_object_unref0 (sections), _tmp0_);
	g_signal_parse_name ("motion-event", CLUTTER_TYPE_ACTOR, &_tmp1_, NULL, FALSE);
	g_signal_handlers_disconnect_matched ((ClutterActor*) unity_launcher_scroller_child_controller_get_child ((UnityLauncherScrollerChildController*) self), G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp1_, 0, NULL, (GCallback) _unity_places_place_entry_scroller_child_controller_get_sections_clutter_actor_motion_event, self);
	result = FALSE;
	_g_object_unref0 (sections);
	return result;
}


static void unity_places_place_entry_scroller_child_controller_real_activate (UnityLauncherScrollerChildController* base) {
	UnityPlacesPlaceEntryScrollerChildController * self;
	self = (UnityPlacesPlaceEntryScrollerChildController*) base;
	g_signal_emit_by_name (self, "clicked", (guint) 0);
}


static UnityLauncherQuicklistController* unity_places_place_entry_scroller_child_controller_real_get_menu_controller (UnityLauncherScrollerChildController* base) {
	UnityPlacesPlaceEntryScrollerChildController * self;
	UnityLauncherQuicklistController* result = NULL;
	self = (UnityPlacesPlaceEntryScrollerChildController*) base;
	result = (UnityLauncherQuicklistController*) unity_launcher_application_quicklist_controller_new ((UnityLauncherScrollerChildController*) self);
	return result;
}


static void _lambda67_ (guint timestamp, Block3Data* _data3_) {
	UnityPlacesPlaceEntryScrollerChildController * self;
	self = _data3_->self;
	g_signal_emit_by_name (self, "clicked", (guint) dbusmenu_menuitem_property_get_int (_data3_->item, "section-id"));
}


static void __lambda67__dbusmenu_menuitem_item_activated (DbusmenuMenuitem* _sender, guint object, gpointer self) {
	_lambda67_ (object, self);
}


static Block3Data* block3_data_ref (Block3Data* _data3_) {
	g_atomic_int_inc (&_data3_->_ref_count_);
	return _data3_;
}


static void block3_data_unref (Block3Data* _data3_) {
	if (g_atomic_int_dec_and_test (&_data3_->_ref_count_)) {
		_g_object_unref0 (_data3_->self);
		_g_object_unref0 (_data3_->item);
		g_slice_free (Block3Data, _data3_);
	}
}


static void unity_places_place_entry_scroller_child_controller_real_get_menu_actions (UnityLauncherScrollerChildController* base, UnityLauncherScrollerChildControllermenu_cb callback, void* callback_target) {
	UnityPlacesPlaceEntryScrollerChildController * self;
	DbusmenuMenuitem* root;
	DeeModel* sections;
	DeeModelIter* iter;
	self = (UnityPlacesPlaceEntryScrollerChildController*) base;
	root = dbusmenu_menuitem_new ();
	dbusmenu_menuitem_set_root (root, TRUE);
	sections = _g_object_ref0 (unity_places_place_entry_get_sections_model (self->priv->_entry));
	iter = dee_model_get_first_iter (sections);
	while (TRUE) {
		Block3Data* _data3_;
		gboolean _tmp0_ = FALSE;
		char* name;
		_data3_ = g_slice_new0 (Block3Data);
		_data3_->_ref_count_ = 1;
		_data3_->self = g_object_ref (self);
		if (iter != NULL) {
			_tmp0_ = !dee_model_is_last (sections, iter);
		} else {
			_tmp0_ = FALSE;
		}
		if (!_tmp0_) {
			block3_data_unref (_data3_);
			break;
		}
		name = g_strdup (dee_model_get_string (sections, iter, (guint) 0));
		_data3_->item = dbusmenu_menuitem_new ();
		dbusmenu_menuitem_property_set (_data3_->item, DBUSMENU_MENUITEM_PROP_LABEL, name);
		dbusmenu_menuitem_property_set_bool (_data3_->item, DBUSMENU_MENUITEM_PROP_ENABLED, TRUE);
		dbusmenu_menuitem_property_set_bool (_data3_->item, DBUSMENU_MENUITEM_PROP_VISIBLE, TRUE);
		dbusmenu_menuitem_property_set_int (_data3_->item, "section-id", dee_model_get_position (sections, iter));
		g_signal_connect_data (_data3_->item, "item-activated", (GCallback) __lambda67__dbusmenu_menuitem_item_activated, block3_data_ref (_data3_), (GClosureNotify) block3_data_unref, 0);
		dbusmenu_menuitem_child_append (root, _data3_->item);
		iter = dee_model_next (sections, iter);
		_g_free0 (name);
		block3_data_unref (_data3_);
	}
	callback (root, callback_target);
	_g_object_unref0 (sections);
	_g_object_unref0 (root);
}


static gboolean unity_places_place_entry_scroller_child_controller_real_can_drag (UnityLauncherScrollerChildController* base) {
	UnityPlacesPlaceEntryScrollerChildController * self;
	gboolean result = FALSE;
	self = (UnityPlacesPlaceEntryScrollerChildController*) base;
	result = TRUE;
	return result;
}


UnityPlacesPlaceEntry* unity_places_place_entry_scroller_child_controller_get_entry (UnityPlacesPlaceEntryScrollerChildController* self) {
	UnityPlacesPlaceEntry* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_entry;
	return result;
}


static void unity_places_place_entry_scroller_child_controller_set_entry (UnityPlacesPlaceEntryScrollerChildController* self, UnityPlacesPlaceEntry* value) {
	UnityPlacesPlaceEntry* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_entry = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_entry), _tmp0_);
	g_object_notify ((GObject *) self, "entry");
}


static void _lambda68_ (UnityPlacesPlaceEntryScrollerChildController* self) {
	unity_launcher_scroller_child_set_active (unity_launcher_scroller_child_controller_get_child ((UnityLauncherScrollerChildController*) self), unity_places_place_entry_get_active (self->priv->_entry));
}


static void __lambda68__g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self) {
	_lambda68_ (self);
}


static GObject * unity_places_place_entry_scroller_child_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesPlaceEntryScrollerChildController * self;
	parent_class = G_OBJECT_CLASS (unity_places_place_entry_scroller_child_controller_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER (obj);
	{
		unity_launcher_scroller_child_controller_set_name ((UnityLauncherScrollerChildController*) self, unity_places_place_entry_get_name (self->priv->_entry));
		unity_launcher_scroller_child_controller_load_icon_from_icon_name ((UnityLauncherScrollerChildController*) self, unity_places_place_entry_get_icon (self->priv->_entry));
		g_signal_connect_object ((GObject*) self->priv->_entry, "notify::active", (GCallback) __lambda68__g_object_notify, self, 0);
		unity_launcher_scroller_child_set_group_type (unity_launcher_scroller_child_controller_get_child ((UnityLauncherScrollerChildController*) self), UNITY_LAUNCHER_SCROLLER_CHILD_GROUP_TYPE_PLACE);
		g_signal_connect_object ((ClutterActor*) unity_launcher_scroller_child_controller_get_child ((UnityLauncherScrollerChildController*) self), "motion-event", (GCallback) _unity_places_place_entry_scroller_child_controller_get_sections_clutter_actor_motion_event, self, 0);
	}
	return obj;
}


static void unity_places_place_entry_scroller_child_controller_class_init (UnityPlacesPlaceEntryScrollerChildControllerClass * klass) {
	unity_places_place_entry_scroller_child_controller_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesPlaceEntryScrollerChildControllerPrivate));
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->activate = unity_places_place_entry_scroller_child_controller_real_activate;
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->get_menu_controller = unity_places_place_entry_scroller_child_controller_real_get_menu_controller;
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->get_menu_actions = unity_places_place_entry_scroller_child_controller_real_get_menu_actions;
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->can_drag = unity_places_place_entry_scroller_child_controller_real_can_drag;
	G_OBJECT_CLASS (klass)->get_property = unity_places_place_entry_scroller_child_controller_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_place_entry_scroller_child_controller_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_places_place_entry_scroller_child_controller_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_place_entry_scroller_child_controller_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER_ENTRY, g_param_spec_object ("entry", "entry", "entry", UNITY_PLACES_TYPE_PLACE_ENTRY, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_signal_new ("clicked", UNITY_PLACES_TYPE_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__UINT, G_TYPE_NONE, 1, G_TYPE_UINT);
}


static void unity_places_place_entry_scroller_child_controller_instance_init (UnityPlacesPlaceEntryScrollerChildController * self) {
	self->priv = UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER_GET_PRIVATE (self);
}


static void unity_places_place_entry_scroller_child_controller_finalize (GObject* obj) {
	UnityPlacesPlaceEntryScrollerChildController * self;
	self = UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER (obj);
	_g_object_unref0 (self->priv->_entry);
	G_OBJECT_CLASS (unity_places_place_entry_scroller_child_controller_parent_class)->finalize (obj);
}


GType unity_places_place_entry_scroller_child_controller_get_type (void) {
	static volatile gsize unity_places_place_entry_scroller_child_controller_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_place_entry_scroller_child_controller_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesPlaceEntryScrollerChildControllerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_place_entry_scroller_child_controller_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesPlaceEntryScrollerChildController), 0, (GInstanceInitFunc) unity_places_place_entry_scroller_child_controller_instance_init, NULL };
		GType unity_places_place_entry_scroller_child_controller_type_id;
		unity_places_place_entry_scroller_child_controller_type_id = g_type_register_static (UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, "UnityPlacesPlaceEntryScrollerChildController", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_place_entry_scroller_child_controller_type_id__volatile, unity_places_place_entry_scroller_child_controller_type_id);
	}
	return unity_places_place_entry_scroller_child_controller_type_id__volatile;
}


static void unity_places_place_entry_scroller_child_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesPlaceEntryScrollerChildController * self;
	self = UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER_ENTRY:
		g_value_set_object (value, unity_places_place_entry_scroller_child_controller_get_entry (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_place_entry_scroller_child_controller_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesPlaceEntryScrollerChildController * self;
	self = UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_ENTRY_SCROLLER_CHILD_CONTROLLER_ENTRY:
		unity_places_place_entry_scroller_child_controller_set_entry (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




