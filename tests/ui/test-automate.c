/* test-automate.c generated by valac, the Vala compiler
 * generated from test-automate.vala, do not modify */

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
#include <clutter/clutter.h>
#include <unity-private.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


#define UNITY_TESTS_UI_TYPE_AUTOMATION_BASIC_TEST_SUITE (unity_tests_ui_automation_basic_test_suite_get_type ())
#define UNITY_TESTS_UI_AUTOMATION_BASIC_TEST_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UI_TYPE_AUTOMATION_BASIC_TEST_SUITE, UnityTestsUIAutomationBasicTestSuite))
#define UNITY_TESTS_UI_AUTOMATION_BASIC_TEST_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UI_TYPE_AUTOMATION_BASIC_TEST_SUITE, UnityTestsUIAutomationBasicTestSuiteClass))
#define UNITY_TESTS_UI_IS_AUTOMATION_BASIC_TEST_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UI_TYPE_AUTOMATION_BASIC_TEST_SUITE))
#define UNITY_TESTS_UI_IS_AUTOMATION_BASIC_TEST_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UI_TYPE_AUTOMATION_BASIC_TEST_SUITE))
#define UNITY_TESTS_UI_AUTOMATION_BASIC_TEST_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UI_TYPE_AUTOMATION_BASIC_TEST_SUITE, UnityTestsUIAutomationBasicTestSuiteClass))

typedef struct _UnityTestsUIAutomationBasicTestSuite UnityTestsUIAutomationBasicTestSuite;
typedef struct _UnityTestsUIAutomationBasicTestSuiteClass UnityTestsUIAutomationBasicTestSuiteClass;
typedef struct _UnityTestsUIAutomationBasicTestSuitePrivate UnityTestsUIAutomationBasicTestSuitePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _UnityTestsUIAutomationBasicTestSuite {
	GObject parent_instance;
	UnityTestsUIAutomationBasicTestSuitePrivate * priv;
};

struct _UnityTestsUIAutomationBasicTestSuiteClass {
	GObjectClass parent_class;
};

struct _UnityTestsUIAutomationBasicTestSuitePrivate {
	UnityTestingWindow* window;
	ClutterStage* stage;
};


extern GTimer* gTimer;
GTimer* gTimer = NULL;
static gpointer unity_tests_ui_automation_basic_test_suite_parent_class = NULL;

void on_animation_started (ClutterAnimation* anim);
void on_animation_completed (ClutterAnimation* anim);
GType unity_tests_ui_automation_basic_test_suite_get_type (void);
#define UNITY_TESTS_UI_AUTOMATION_BASIC_TEST_SUITE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TESTS_UI_TYPE_AUTOMATION_BASIC_TEST_SUITE, UnityTestsUIAutomationBasicTestSuitePrivate))
enum  {
	UNITY_TESTS_UI_AUTOMATION_BASIC_TEST_SUITE_DUMMY_PROPERTY
};
#define UNITY_TESTS_UI_AUTOMATION_BASIC_TEST_SUITE_DOMAIN "/UI/Quicklist"
static void unity_tests_ui_automation_basic_test_suite_test_automation (UnityTestsUIAutomationBasicTestSuite* self);
static void _unity_tests_ui_automation_basic_test_suite_test_automation_gdata_test_func (gpointer self);
static void unity_tests_ui_automation_basic_test_suite_test_teardown (UnityTestsUIAutomationBasicTestSuite* self);
static void _unity_tests_ui_automation_basic_test_suite_test_teardown_gdata_test_func (gpointer self);
UnityTestsUIAutomationBasicTestSuite* unity_tests_ui_automation_basic_test_suite_new (void);
UnityTestsUIAutomationBasicTestSuite* unity_tests_ui_automation_basic_test_suite_construct (GType object_type);
static void unity_tests_ui_automation_basic_test_suite_finalize (GObject* obj);



void on_animation_started (ClutterAnimation* anim) {
	g_timer_start (gTimer);
}


void on_animation_completed (ClutterAnimation* anim) {
	g_timer_stop (gTimer);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _unity_tests_ui_automation_basic_test_suite_test_automation_gdata_test_func (gpointer self) {
	unity_tests_ui_automation_basic_test_suite_test_automation (self);
}


static void _unity_tests_ui_automation_basic_test_suite_test_teardown_gdata_test_func (gpointer self) {
	unity_tests_ui_automation_basic_test_suite_test_teardown (self);
}


UnityTestsUIAutomationBasicTestSuite* unity_tests_ui_automation_basic_test_suite_construct (GType object_type) {
	UnityTestsUIAutomationBasicTestSuite * self;
	UnityTestingWindow* _tmp0_;
	ClutterStage* _tmp1_;
	self = (UnityTestsUIAutomationBasicTestSuite*) g_object_new (object_type, NULL);
	unity_testing_logging_init_fatal_handler ();
	self->priv->window = (_tmp0_ = g_object_ref_sink (unity_testing_window_new (TRUE, 1024, 600)), _g_object_unref0 (self->priv->window), _tmp0_);
	unity_testing_window_init_test_mode (self->priv->window);
	self->priv->stage = (_tmp1_ = _g_object_ref0 (self->priv->window->stage), _g_object_unref0 (self->priv->stage), _tmp1_);
	gtk_window_set_title ((GtkWindow*) self->priv->window, "Automation Tests");
	gtk_widget_show_all ((GtkWidget*) self->priv->window);
	g_test_add_data_func (UNITY_TESTS_UI_AUTOMATION_BASIC_TEST_SUITE_DOMAIN "/Automation", self, _unity_tests_ui_automation_basic_test_suite_test_automation_gdata_test_func);
	g_test_add_data_func (UNITY_TESTS_UI_AUTOMATION_BASIC_TEST_SUITE_DOMAIN "/Teardown", self, _unity_tests_ui_automation_basic_test_suite_test_teardown_gdata_test_func);
	return self;
}


UnityTestsUIAutomationBasicTestSuite* unity_tests_ui_automation_basic_test_suite_new (void) {
	return unity_tests_ui_automation_basic_test_suite_construct (UNITY_TESTS_UI_TYPE_AUTOMATION_BASIC_TEST_SUITE);
}


static void unity_tests_ui_automation_basic_test_suite_test_teardown (UnityTestsUIAutomationBasicTestSuite* self) {
	ClutterStage* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->stage = (_tmp0_ = NULL, _g_object_unref0 (self->priv->stage), _tmp0_);
}


static void unity_tests_ui_automation_basic_test_suite_test_automation (UnityTestsUIAutomationBasicTestSuite* self) {
	g_return_if_fail (self != NULL);
}


static void unity_tests_ui_automation_basic_test_suite_class_init (UnityTestsUIAutomationBasicTestSuiteClass * klass) {
	unity_tests_ui_automation_basic_test_suite_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityTestsUIAutomationBasicTestSuitePrivate));
	G_OBJECT_CLASS (klass)->finalize = unity_tests_ui_automation_basic_test_suite_finalize;
}


static void unity_tests_ui_automation_basic_test_suite_instance_init (UnityTestsUIAutomationBasicTestSuite * self) {
	self->priv = UNITY_TESTS_UI_AUTOMATION_BASIC_TEST_SUITE_GET_PRIVATE (self);
}


static void unity_tests_ui_automation_basic_test_suite_finalize (GObject* obj) {
	UnityTestsUIAutomationBasicTestSuite * self;
	self = UNITY_TESTS_UI_AUTOMATION_BASIC_TEST_SUITE (obj);
	_g_object_unref0 (self->priv->window);
	_g_object_unref0 (self->priv->stage);
	G_OBJECT_CLASS (unity_tests_ui_automation_basic_test_suite_parent_class)->finalize (obj);
}


GType unity_tests_ui_automation_basic_test_suite_get_type (void) {
	static volatile gsize unity_tests_ui_automation_basic_test_suite_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_ui_automation_basic_test_suite_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUIAutomationBasicTestSuiteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_ui_automation_basic_test_suite_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUIAutomationBasicTestSuite), 0, (GInstanceInitFunc) unity_tests_ui_automation_basic_test_suite_instance_init, NULL };
		GType unity_tests_ui_automation_basic_test_suite_type_id;
		unity_tests_ui_automation_basic_test_suite_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityTestsUIAutomationBasicTestSuite", &g_define_type_info, 0);
		g_once_init_leave (&unity_tests_ui_automation_basic_test_suite_type_id__volatile, unity_tests_ui_automation_basic_test_suite_type_id);
	}
	return unity_tests_ui_automation_basic_test_suite_type_id__volatile;
}




