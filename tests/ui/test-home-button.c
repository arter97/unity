/* test-home-button.c generated by valac 0.9.5, the Vala compiler
 * generated from test-home-button.vala, do not modify */

/* -*- Mode: vala; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
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
 * Authored by Mirco Müller <mirco.mueller@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <unity.h>
#include <unity-private.h>
#include <clutter/clutter.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


#define UNITY_TESTS_UI_TYPE_HOME_BUTTON_SUITE (unity_tests_ui_home_button_suite_get_type ())
#define UNITY_TESTS_UI_HOME_BUTTON_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UI_TYPE_HOME_BUTTON_SUITE, UnityTestsUIHomeButtonSuite))
#define UNITY_TESTS_UI_HOME_BUTTON_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UI_TYPE_HOME_BUTTON_SUITE, UnityTestsUIHomeButtonSuiteClass))
#define UNITY_TESTS_UI_IS_HOME_BUTTON_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UI_TYPE_HOME_BUTTON_SUITE))
#define UNITY_TESTS_UI_IS_HOME_BUTTON_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UI_TYPE_HOME_BUTTON_SUITE))
#define UNITY_TESTS_UI_HOME_BUTTON_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UI_TYPE_HOME_BUTTON_SUITE, UnityTestsUIHomeButtonSuiteClass))

typedef struct _UnityTestsUIHomeButtonSuite UnityTestsUIHomeButtonSuite;
typedef struct _UnityTestsUIHomeButtonSuiteClass UnityTestsUIHomeButtonSuiteClass;
typedef struct _UnityTestsUIHomeButtonSuitePrivate UnityTestsUIHomeButtonSuitePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _UnityTestsUIHomeButtonSuite {
	GObject parent_instance;
	UnityTestsUIHomeButtonSuitePrivate * priv;
};

struct _UnityTestsUIHomeButtonSuiteClass {
	GObjectClass parent_class;
};

struct _UnityTestsUIHomeButtonSuitePrivate {
	UnityTestingWindow* window;
	ClutterStage* stage;
	UnityTestingDirector* director;
	UnityPanelHomeButton* home_button;
	gboolean _super_key_active;
};


extern gboolean g_flag;
gboolean g_flag = FALSE;
static gpointer unity_tests_ui_home_button_suite_parent_class = NULL;
static UnityShellIface* unity_tests_ui_home_button_suite_unity_shell_parent_iface = NULL;

GType unity_tests_ui_home_button_suite_get_type (void) G_GNUC_CONST;
#define UNITY_TESTS_UI_HOME_BUTTON_SUITE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TESTS_UI_TYPE_HOME_BUTTON_SUITE, UnityTestsUIHomeButtonSuitePrivate))
enum  {
	UNITY_TESTS_UI_HOME_BUTTON_SUITE_DUMMY_PROPERTY,
	UNITY_TESTS_UI_HOME_BUTTON_SUITE_SUPER_KEY_ACTIVE,
	UNITY_TESTS_UI_HOME_BUTTON_SUITE_MENUS_SWALLOW_EVENTS
};
#define UNITY_TESTS_UI_HOME_BUTTON_SUITE_DOMAIN "/UI/HomeButton"
static void unity_tests_ui_home_button_suite_test_click_home_button (UnityTestsUIHomeButtonSuite* self);
static void _unity_tests_ui_home_button_suite_test_click_home_button_gdata_test_func (gpointer self);
UnityTestsUIHomeButtonSuite* unity_tests_ui_home_button_suite_new (void);
UnityTestsUIHomeButtonSuite* unity_tests_ui_home_button_suite_construct (GType object_type);
static void unity_tests_ui_home_button_suite_real_get_window_details (UnityShell* base, guint32 xid, gboolean* a, gboolean* b);
static void unity_tests_ui_home_button_suite_real_do_window_action (UnityShell* base, guint32 xid, UnityWindowAction action);
static UnityShellMode unity_tests_ui_home_button_suite_real_get_mode (UnityShell* base);
static ClutterStage* unity_tests_ui_home_button_suite_real_get_stage (UnityShell* base);
static void unity_tests_ui_home_button_suite_real_show_unity (UnityShell* base);
static void unity_tests_ui_home_button_suite_real_hide_unity (UnityShell* base);
static gint unity_tests_ui_home_button_suite_real_get_indicators_width (UnityShell* base);
static gint unity_tests_ui_home_button_suite_real_get_launcher_width_foobar (UnityShell* base);
static gint unity_tests_ui_home_button_suite_real_get_panel_height_foobar (UnityShell* base);
static void unity_tests_ui_home_button_suite_real_ensure_input_region (UnityShell* base);
static void unity_tests_ui_home_button_suite_real_add_fullscreen_request (UnityShell* base, GObject* o);
static gboolean unity_tests_ui_home_button_suite_real_remove_fullscreen_request (UnityShell* base, GObject* o);
static void unity_tests_ui_home_button_suite_real_grab_keyboard (UnityShell* base, gboolean grab, guint32 timestamp);
static void unity_tests_ui_home_button_suite_real_about_to_show_places (UnityShell* base);
static void unity_tests_ui_home_button_suite_real_close_xids (UnityShell* base, GArray* xids);
static void unity_tests_ui_home_button_suite_real_show_window (UnityShell* base, guint32 xid);
static void unity_tests_ui_home_button_suite_real_expose_xids (UnityShell* base, GArray* xids);
static void unity_tests_ui_home_button_suite_real_stop_expose (UnityShell* base);
static guint32 unity_tests_ui_home_button_suite_real_get_current_time (UnityShell* base);
static void unity_tests_ui_home_button_suite_finalize (GObject* obj);
static void unity_tests_ui_home_button_suite_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_tests_ui_home_button_suite_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _unity_tests_ui_home_button_suite_test_click_home_button_gdata_test_func (gpointer self) {
	unity_tests_ui_home_button_suite_test_click_home_button (self);
}


UnityTestsUIHomeButtonSuite* unity_tests_ui_home_button_suite_construct (GType object_type) {
	UnityTestsUIHomeButtonSuite * self;
	UnityTestingWindow* _tmp0_;
	ClutterStage* _tmp1_;
	UnityPanelHomeButton* _tmp2_;
	UnityTestingDirector* _tmp3_;
	self = (UnityTestsUIHomeButtonSuite*) g_object_new (object_type, NULL);
	unity_testing_logging_init_fatal_handler ();
	self->priv->window = (_tmp0_ = g_object_ref_sink (unity_testing_window_new (TRUE, 1024, 600)), _g_object_unref0 (self->priv->window), _tmp0_);
	unity_testing_window_init_test_mode (self->priv->window);
	self->priv->stage = (_tmp1_ = _g_object_ref0 (self->priv->window->stage), _g_object_unref0 (self->priv->stage), _tmp1_);
	gtk_window_set_title ((GtkWindow*) self->priv->window, "HomeButton Test");
	gtk_widget_show_all ((GtkWidget*) self->priv->window);
	self->priv->home_button = (_tmp2_ = g_object_ref_sink (unity_panel_home_button_new ((UnityShell*) self)), _g_object_unref0 (self->priv->home_button), _tmp2_);
	self->priv->director = (_tmp3_ = unity_testing_director_new (self->priv->stage), _g_object_unref0 (self->priv->director), _tmp3_);
	g_test_add_data_func (UNITY_TESTS_UI_HOME_BUTTON_SUITE_DOMAIN "/HomeButton", self, _unity_tests_ui_home_button_suite_test_click_home_button_gdata_test_func);
	return self;
}


UnityTestsUIHomeButtonSuite* unity_tests_ui_home_button_suite_new (void) {
	return unity_tests_ui_home_button_suite_construct (UNITY_TESTS_UI_TYPE_HOME_BUTTON_SUITE);
}


static void unity_tests_ui_home_button_suite_test_click_home_button (UnityTestsUIHomeButtonSuite* self) {
	g_return_if_fail (self != NULL);
	unity_testing_director_button_press (self->priv->director, (ClutterActor*) self->priv->home_button, (guint32) 1, TRUE, 1.0f, 1.0f, FALSE);
	unity_testing_logging_init_fatal_handler ();
	g_assert (g_flag == TRUE);
}


static void unity_tests_ui_home_button_suite_real_get_window_details (UnityShell* base, guint32 xid, gboolean* a, gboolean* b) {
	UnityTestsUIHomeButtonSuite * self;
	self = (UnityTestsUIHomeButtonSuite*) base;
}


static void unity_tests_ui_home_button_suite_real_do_window_action (UnityShell* base, guint32 xid, UnityWindowAction action) {
	UnityTestsUIHomeButtonSuite * self;
	self = (UnityTestsUIHomeButtonSuite*) base;
}


static UnityShellMode unity_tests_ui_home_button_suite_real_get_mode (UnityShell* base) {
	UnityTestsUIHomeButtonSuite * self;
	UnityShellMode result = 0;
	self = (UnityTestsUIHomeButtonSuite*) base;
	result = UNITY_SHELL_MODE_MINIMIZED;
	return result;
}


static ClutterStage* unity_tests_ui_home_button_suite_real_get_stage (UnityShell* base) {
	UnityTestsUIHomeButtonSuite * self;
	ClutterStage* result = NULL;
	self = (UnityTestsUIHomeButtonSuite*) base;
	result = _g_object_ref0 (self->priv->stage);
	return result;
}


static void unity_tests_ui_home_button_suite_real_show_unity (UnityShell* base) {
	UnityTestsUIHomeButtonSuite * self;
	self = (UnityTestsUIHomeButtonSuite*) base;
	g_flag = TRUE;
}


static void unity_tests_ui_home_button_suite_real_hide_unity (UnityShell* base) {
	UnityTestsUIHomeButtonSuite * self;
	self = (UnityTestsUIHomeButtonSuite*) base;
}


static gint unity_tests_ui_home_button_suite_real_get_indicators_width (UnityShell* base) {
	UnityTestsUIHomeButtonSuite * self;
	gint result = 0;
	self = (UnityTestsUIHomeButtonSuite*) base;
	result = 0;
	return result;
}


static gint unity_tests_ui_home_button_suite_real_get_launcher_width_foobar (UnityShell* base) {
	UnityTestsUIHomeButtonSuite * self;
	gint result = 0;
	self = (UnityTestsUIHomeButtonSuite*) base;
	result = 0;
	return result;
}


static gint unity_tests_ui_home_button_suite_real_get_panel_height_foobar (UnityShell* base) {
	UnityTestsUIHomeButtonSuite * self;
	gint result = 0;
	self = (UnityTestsUIHomeButtonSuite*) base;
	result = 0;
	return result;
}


static void unity_tests_ui_home_button_suite_real_ensure_input_region (UnityShell* base) {
	UnityTestsUIHomeButtonSuite * self;
	self = (UnityTestsUIHomeButtonSuite*) base;
}


static void unity_tests_ui_home_button_suite_real_add_fullscreen_request (UnityShell* base, GObject* o) {
	UnityTestsUIHomeButtonSuite * self;
	self = (UnityTestsUIHomeButtonSuite*) base;
	g_return_if_fail (o != NULL);
}


static gboolean unity_tests_ui_home_button_suite_real_remove_fullscreen_request (UnityShell* base, GObject* o) {
	UnityTestsUIHomeButtonSuite * self;
	gboolean result = FALSE;
	self = (UnityTestsUIHomeButtonSuite*) base;
	g_return_val_if_fail (o != NULL, FALSE);
	result = FALSE;
	return result;
}


static void unity_tests_ui_home_button_suite_real_grab_keyboard (UnityShell* base, gboolean grab, guint32 timestamp) {
	UnityTestsUIHomeButtonSuite * self;
	self = (UnityTestsUIHomeButtonSuite*) base;
}


static void unity_tests_ui_home_button_suite_real_about_to_show_places (UnityShell* base) {
	UnityTestsUIHomeButtonSuite * self;
	self = (UnityTestsUIHomeButtonSuite*) base;
}


static void unity_tests_ui_home_button_suite_real_close_xids (UnityShell* base, GArray* xids) {
	UnityTestsUIHomeButtonSuite * self;
	self = (UnityTestsUIHomeButtonSuite*) base;
	g_return_if_fail (xids != NULL);
}


static void unity_tests_ui_home_button_suite_real_show_window (UnityShell* base, guint32 xid) {
	UnityTestsUIHomeButtonSuite * self;
	self = (UnityTestsUIHomeButtonSuite*) base;
}


static void unity_tests_ui_home_button_suite_real_expose_xids (UnityShell* base, GArray* xids) {
	UnityTestsUIHomeButtonSuite * self;
	self = (UnityTestsUIHomeButtonSuite*) base;
	g_return_if_fail (xids != NULL);
}


static void unity_tests_ui_home_button_suite_real_stop_expose (UnityShell* base) {
	UnityTestsUIHomeButtonSuite * self;
	self = (UnityTestsUIHomeButtonSuite*) base;
}


static guint32 unity_tests_ui_home_button_suite_real_get_current_time (UnityShell* base) {
	UnityTestsUIHomeButtonSuite * self;
	guint32 result = 0U;
	self = (UnityTestsUIHomeButtonSuite*) base;
	result = clutter_get_current_event_time ();
	return result;
}


static gboolean unity_tests_ui_home_button_suite_real_get_super_key_active (UnityShell* base) {
	gboolean result;
	UnityTestsUIHomeButtonSuite* self;
	self = (UnityTestsUIHomeButtonSuite*) base;
	result = self->priv->_super_key_active;
	return result;
}


static void unity_tests_ui_home_button_suite_real_set_super_key_active (UnityShell* base, gboolean value) {
	UnityTestsUIHomeButtonSuite* self;
	self = (UnityTestsUIHomeButtonSuite*) base;
	self->priv->_super_key_active = value;
	g_object_notify ((GObject *) self, "super-key-active");
}


static gboolean unity_tests_ui_home_button_suite_real_get_menus_swallow_events (UnityShell* base) {
	gboolean result;
	UnityTestsUIHomeButtonSuite* self;
	self = (UnityTestsUIHomeButtonSuite*) base;
	result = TRUE;
	return result;
}


static void unity_tests_ui_home_button_suite_class_init (UnityTestsUIHomeButtonSuiteClass * klass) {
	unity_tests_ui_home_button_suite_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityTestsUIHomeButtonSuitePrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_tests_ui_home_button_suite_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_tests_ui_home_button_suite_set_property;
	G_OBJECT_CLASS (klass)->finalize = unity_tests_ui_home_button_suite_finalize;
	g_object_class_override_property (G_OBJECT_CLASS (klass), UNITY_TESTS_UI_HOME_BUTTON_SUITE_SUPER_KEY_ACTIVE, "super-key-active");
	g_object_class_override_property (G_OBJECT_CLASS (klass), UNITY_TESTS_UI_HOME_BUTTON_SUITE_MENUS_SWALLOW_EVENTS, "menus-swallow-events");
}


static void unity_tests_ui_home_button_suite_unity_shell_interface_init (UnityShellIface * iface) {
	unity_tests_ui_home_button_suite_unity_shell_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_window_details = unity_tests_ui_home_button_suite_real_get_window_details;
	iface->do_window_action = unity_tests_ui_home_button_suite_real_do_window_action;
	iface->get_mode = unity_tests_ui_home_button_suite_real_get_mode;
	iface->get_stage = unity_tests_ui_home_button_suite_real_get_stage;
	iface->show_unity = unity_tests_ui_home_button_suite_real_show_unity;
	iface->hide_unity = unity_tests_ui_home_button_suite_real_hide_unity;
	iface->get_indicators_width = unity_tests_ui_home_button_suite_real_get_indicators_width;
	iface->get_launcher_width_foobar = unity_tests_ui_home_button_suite_real_get_launcher_width_foobar;
	iface->get_panel_height_foobar = unity_tests_ui_home_button_suite_real_get_panel_height_foobar;
	iface->ensure_input_region = unity_tests_ui_home_button_suite_real_ensure_input_region;
	iface->add_fullscreen_request = unity_tests_ui_home_button_suite_real_add_fullscreen_request;
	iface->remove_fullscreen_request = unity_tests_ui_home_button_suite_real_remove_fullscreen_request;
	iface->grab_keyboard = unity_tests_ui_home_button_suite_real_grab_keyboard;
	iface->about_to_show_places = unity_tests_ui_home_button_suite_real_about_to_show_places;
	iface->close_xids = unity_tests_ui_home_button_suite_real_close_xids;
	iface->show_window = unity_tests_ui_home_button_suite_real_show_window;
	iface->expose_xids = unity_tests_ui_home_button_suite_real_expose_xids;
	iface->stop_expose = unity_tests_ui_home_button_suite_real_stop_expose;
	iface->get_current_time = unity_tests_ui_home_button_suite_real_get_current_time;
	iface->get_super_key_active = unity_tests_ui_home_button_suite_real_get_super_key_active;
	iface->set_super_key_active = unity_tests_ui_home_button_suite_real_set_super_key_active;
	iface->get_menus_swallow_events = unity_tests_ui_home_button_suite_real_get_menus_swallow_events;
}


static void unity_tests_ui_home_button_suite_instance_init (UnityTestsUIHomeButtonSuite * self) {
	self->priv = UNITY_TESTS_UI_HOME_BUTTON_SUITE_GET_PRIVATE (self);
}


static void unity_tests_ui_home_button_suite_finalize (GObject* obj) {
	UnityTestsUIHomeButtonSuite * self;
	self = UNITY_TESTS_UI_HOME_BUTTON_SUITE (obj);
	_g_object_unref0 (self->priv->window);
	_g_object_unref0 (self->priv->stage);
	_g_object_unref0 (self->priv->director);
	_g_object_unref0 (self->priv->home_button);
	G_OBJECT_CLASS (unity_tests_ui_home_button_suite_parent_class)->finalize (obj);
}


GType unity_tests_ui_home_button_suite_get_type (void) {
	static volatile gsize unity_tests_ui_home_button_suite_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_ui_home_button_suite_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUIHomeButtonSuiteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_ui_home_button_suite_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUIHomeButtonSuite), 0, (GInstanceInitFunc) unity_tests_ui_home_button_suite_instance_init, NULL };
		static const GInterfaceInfo unity_shell_info = { (GInterfaceInitFunc) unity_tests_ui_home_button_suite_unity_shell_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType unity_tests_ui_home_button_suite_type_id;
		unity_tests_ui_home_button_suite_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityTestsUIHomeButtonSuite", &g_define_type_info, 0);
		g_type_add_interface_static (unity_tests_ui_home_button_suite_type_id, UNITY_TYPE_SHELL, &unity_shell_info);
		g_once_init_leave (&unity_tests_ui_home_button_suite_type_id__volatile, unity_tests_ui_home_button_suite_type_id);
	}
	return unity_tests_ui_home_button_suite_type_id__volatile;
}


static void unity_tests_ui_home_button_suite_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityTestsUIHomeButtonSuite * self;
	self = UNITY_TESTS_UI_HOME_BUTTON_SUITE (object);
	switch (property_id) {
		case UNITY_TESTS_UI_HOME_BUTTON_SUITE_SUPER_KEY_ACTIVE:
		g_value_set_boolean (value, unity_shell_get_super_key_active ((UnityShell*) self));
		break;
		case UNITY_TESTS_UI_HOME_BUTTON_SUITE_MENUS_SWALLOW_EVENTS:
		g_value_set_boolean (value, unity_shell_get_menus_swallow_events ((UnityShell*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_tests_ui_home_button_suite_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityTestsUIHomeButtonSuite * self;
	self = UNITY_TESTS_UI_HOME_BUTTON_SUITE (object);
	switch (property_id) {
		case UNITY_TESTS_UI_HOME_BUTTON_SUITE_SUPER_KEY_ACTIVE:
		unity_shell_set_super_key_active ((UnityShell*) self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




