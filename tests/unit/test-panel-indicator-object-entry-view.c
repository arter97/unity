/* test-panel-indicator-object-entry-view.c generated by valac 0.10.0, the Vala compiler
 * generated from test-panel-indicator-object-entry-view.vala, do not modify */

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
#include <gtk/gtk.h>
#include <libindicator/indicator.h>
#include <libindicator/indicator-object.h>
#include <libindicator/indicator-service.h>
#include <libindicator/indicator-service-manager.h>
#include <stdlib.h>
#include <string.h>
#include <unity-private.h>
#include <clutter/clutter.h>
#include <clutk/clutk.h>
#include <gdk-pixbuf/gdk-pixdata.h>


#define UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE (unity_tests_unit_panel_indicator_object_entry_view_suite_get_type ())
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE, UnityTestsUnitPanelIndicatorObjectEntryViewSuite))
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE, UnityTestsUnitPanelIndicatorObjectEntryViewSuiteClass))
#define UNITY_TESTS_UNIT_IS_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE))
#define UNITY_TESTS_UNIT_IS_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE))
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE, UnityTestsUnitPanelIndicatorObjectEntryViewSuiteClass))

typedef struct _UnityTestsUnitPanelIndicatorObjectEntryViewSuite UnityTestsUnitPanelIndicatorObjectEntryViewSuite;
typedef struct _UnityTestsUnitPanelIndicatorObjectEntryViewSuiteClass UnityTestsUnitPanelIndicatorObjectEntryViewSuiteClass;
typedef struct _UnityTestsUnitPanelIndicatorObjectEntryViewSuitePrivate UnityTestsUnitPanelIndicatorObjectEntryViewSuitePrivate;
#define _indicator_object_entry_free0(var) ((var == NULL) ? NULL : (var = (indicator_object_entry_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _UnityTestsUnitPanelIndicatorObjectEntryViewSuite {
	GObject parent_instance;
	UnityTestsUnitPanelIndicatorObjectEntryViewSuitePrivate * priv;
};

struct _UnityTestsUnitPanelIndicatorObjectEntryViewSuiteClass {
	GObjectClass parent_class;
};

struct _UnityTestsUnitPanelIndicatorObjectEntryViewSuitePrivate {
	IndicatorObjectEntry* entry;
	GtkMenu* menu;
	GtkLabel* label;
	GtkImage* image;
};


static gpointer unity_tests_unit_panel_indicator_object_entry_view_suite_parent_class = NULL;

GType unity_tests_unit_panel_indicator_object_entry_view_suite_get_type (void) G_GNUC_CONST;
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE, UnityTestsUnitPanelIndicatorObjectEntryViewSuitePrivate))
enum  {
	UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE_DUMMY_PROPERTY
};
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE_DOMAIN "/Unit/Panel/Indicator/ObjectEntry"
UnityTestsUnitPanelIndicatorObjectEntryViewSuite* unity_tests_unit_panel_indicator_object_entry_view_suite_new (void);
UnityTestsUnitPanelIndicatorObjectEntryViewSuite* unity_tests_unit_panel_indicator_object_entry_view_suite_construct (GType object_type);
static void unity_tests_unit_panel_indicator_object_entry_view_suite_test_allocation (UnityTestsUnitPanelIndicatorObjectEntryViewSuite* self);
static void _unity_tests_unit_panel_indicator_object_entry_view_suite_test_allocation_gdata_test_func (gpointer self);
static void unity_tests_unit_panel_indicator_object_entry_view_suite_test_label_sync (UnityTestsUnitPanelIndicatorObjectEntryViewSuite* self);
static void _unity_tests_unit_panel_indicator_object_entry_view_suite_test_label_sync_gdata_test_func (gpointer self);
static void unity_tests_unit_panel_indicator_object_entry_view_suite_test_image_sync (UnityTestsUnitPanelIndicatorObjectEntryViewSuite* self);
static void _unity_tests_unit_panel_indicator_object_entry_view_suite_test_image_sync_gdata_test_func (gpointer self);
static void unity_tests_unit_panel_indicator_object_entry_view_suite_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



static void _unity_tests_unit_panel_indicator_object_entry_view_suite_test_allocation_gdata_test_func (gpointer self) {
	unity_tests_unit_panel_indicator_object_entry_view_suite_test_allocation (self);
}


static void _unity_tests_unit_panel_indicator_object_entry_view_suite_test_label_sync_gdata_test_func (gpointer self) {
	unity_tests_unit_panel_indicator_object_entry_view_suite_test_label_sync (self);
}


static void _unity_tests_unit_panel_indicator_object_entry_view_suite_test_image_sync_gdata_test_func (gpointer self) {
	unity_tests_unit_panel_indicator_object_entry_view_suite_test_image_sync (self);
}


UnityTestsUnitPanelIndicatorObjectEntryViewSuite* unity_tests_unit_panel_indicator_object_entry_view_suite_construct (GType object_type) {
	UnityTestsUnitPanelIndicatorObjectEntryViewSuite * self;
	IndicatorObjectEntry* _tmp0_;
	GtkMenu* _tmp1_;
	GtkLabel* _tmp2_;
	GtkImage* _tmp3_;
	self = (UnityTestsUnitPanelIndicatorObjectEntryViewSuite*) g_object_new (object_type, NULL);
	unity_testing_logging_init_fatal_handler ();
	self->priv->entry = (_tmp0_ = indicator_object_entry_new (), _indicator_object_entry_free0 (self->priv->entry), _tmp0_);
	self->priv->menu = (_tmp1_ = g_object_ref_sink ((GtkMenu*) gtk_menu_new ()), _g_object_unref0 (self->priv->menu), _tmp1_);
	self->priv->entry->menu = self->priv->menu;
	self->priv->label = (_tmp2_ = g_object_ref_sink ((GtkLabel*) gtk_label_new ("Test Label")), _g_object_unref0 (self->priv->label), _tmp2_);
	self->priv->entry->label = self->priv->label;
	self->priv->image = (_tmp3_ = g_object_ref_sink ((GtkImage*) gtk_image_new_from_icon_name ("gtk-apply", GTK_ICON_SIZE_MENU)), _g_object_unref0 (self->priv->image), _tmp3_);
	self->priv->entry->image = self->priv->image;
	g_test_add_data_func (UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE_DOMAIN "/Allocation", self, _unity_tests_unit_panel_indicator_object_entry_view_suite_test_allocation_gdata_test_func);
	g_test_add_data_func (UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE_DOMAIN "/LabelSync", self, _unity_tests_unit_panel_indicator_object_entry_view_suite_test_label_sync_gdata_test_func);
	g_test_add_data_func (UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE_DOMAIN "/ImageSync", self, _unity_tests_unit_panel_indicator_object_entry_view_suite_test_image_sync_gdata_test_func);
	return self;
}


UnityTestsUnitPanelIndicatorObjectEntryViewSuite* unity_tests_unit_panel_indicator_object_entry_view_suite_new (void) {
	return unity_tests_unit_panel_indicator_object_entry_view_suite_construct (UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE);
}


static void unity_tests_unit_panel_indicator_object_entry_view_suite_test_allocation (UnityTestsUnitPanelIndicatorObjectEntryViewSuite* self) {
	UnityPanelIndicatorsIndicatorObjectEntryView* e;
	g_return_if_fail (self != NULL);
	e = g_object_ref_sink (unity_panel_indicators_indicator_object_entry_view_new (self->priv->entry));
	g_assert (UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_ENTRY_VIEW (e));
	_g_object_unref0 (e);
}


static void unity_tests_unit_panel_indicator_object_entry_view_suite_test_label_sync (UnityTestsUnitPanelIndicatorObjectEntryViewSuite* self) {
	UnityPanelIndicatorsIndicatorObjectEntryView* e;
	g_return_if_fail (self != NULL);
	e = g_object_ref_sink (unity_panel_indicators_indicator_object_entry_view_new (self->priv->entry));
	g_assert (UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_ENTRY_VIEW (e));
	g_assert (_vala_strcmp0 (clutter_text_get_text ((ClutterText*) e->text), gtk_label_get_label (self->priv->label)) == 0);
	gtk_label_set_label (self->priv->label, "Test Label 2");
	g_assert (_vala_strcmp0 (clutter_text_get_text ((ClutterText*) e->text), gtk_label_get_label (self->priv->label)) == 0);
	gtk_label_set_label (self->priv->label, "Test Label");
	_g_object_unref0 (e);
}


static void unity_tests_unit_panel_indicator_object_entry_view_suite_test_image_sync (UnityTestsUnitPanelIndicatorObjectEntryViewSuite* self) {
	UnityPanelIndicatorsIndicatorObjectEntryView* e;
	char* _tmp0_ = NULL;
	char* _tmp1_;
	char* _tmp2_ = NULL;
	char* _tmp3_;
	char* _tmp4_ = NULL;
	char* _tmp5_;
	char* _tmp6_ = NULL;
	char* _tmp7_;
	GdkPixbuf* p;
	GdkPixbuf* _tmp8_ = NULL;
	GdkPixbuf* _tmp9_;
	GdkPixbuf* _tmp10_ = NULL;
	GdkPixbuf* _tmp11_;
	g_return_if_fail (self != NULL);
	e = g_object_ref_sink (unity_panel_indicators_indicator_object_entry_view_new (self->priv->entry));
	g_assert (UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_ENTRY_VIEW (e));
	g_assert (_vala_strcmp0 (_tmp1_ = (g_object_get (e->image, "stock-id", &_tmp0_, NULL), _tmp0_), _tmp3_ = (g_object_get (self->priv->image, "icon-name", &_tmp2_, NULL), _tmp2_)) == 0);
	_g_free0 (_tmp3_);
	_g_free0 (_tmp1_);
	g_object_set (self->priv->image, "icon-name", "gtk-close", NULL);
	g_assert (_vala_strcmp0 (_tmp5_ = (g_object_get (e->image, "stock-id", &_tmp4_, NULL), _tmp4_), _tmp7_ = (g_object_get (self->priv->image, "icon-name", &_tmp6_, NULL), _tmp6_)) == 0);
	_g_free0 (_tmp7_);
	_g_free0 (_tmp5_);
	p = gdk_pixbuf_new (GDK_COLORSPACE_RGB, TRUE, 8, 100, 100);
	g_object_set (self->priv->image, "pixbuf", p, NULL);
	g_assert ((_tmp9_ = (g_object_get (e->image, "pixbuf", &_tmp8_, NULL), _tmp8_)) == (_tmp11_ = (g_object_get (self->priv->image, "pixbuf", &_tmp10_, NULL), _tmp10_)));
	_g_object_unref0 (_tmp11_);
	_g_object_unref0 (_tmp9_);
	g_object_set (self->priv->image, "icon-name", "gtk-apply", NULL);
	_g_object_unref0 (p);
	_g_object_unref0 (e);
}


static void unity_tests_unit_panel_indicator_object_entry_view_suite_class_init (UnityTestsUnitPanelIndicatorObjectEntryViewSuiteClass * klass) {
	unity_tests_unit_panel_indicator_object_entry_view_suite_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityTestsUnitPanelIndicatorObjectEntryViewSuitePrivate));
	G_OBJECT_CLASS (klass)->finalize = unity_tests_unit_panel_indicator_object_entry_view_suite_finalize;
}


static void unity_tests_unit_panel_indicator_object_entry_view_suite_instance_init (UnityTestsUnitPanelIndicatorObjectEntryViewSuite * self) {
	self->priv = UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE_GET_PRIVATE (self);
}


static void unity_tests_unit_panel_indicator_object_entry_view_suite_finalize (GObject* obj) {
	UnityTestsUnitPanelIndicatorObjectEntryViewSuite * self;
	self = UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_ENTRY_VIEW_SUITE (obj);
	_indicator_object_entry_free0 (self->priv->entry);
	_g_object_unref0 (self->priv->menu);
	_g_object_unref0 (self->priv->label);
	_g_object_unref0 (self->priv->image);
	G_OBJECT_CLASS (unity_tests_unit_panel_indicator_object_entry_view_suite_parent_class)->finalize (obj);
}


GType unity_tests_unit_panel_indicator_object_entry_view_suite_get_type (void) {
	static volatile gsize unity_tests_unit_panel_indicator_object_entry_view_suite_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_unit_panel_indicator_object_entry_view_suite_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUnitPanelIndicatorObjectEntryViewSuiteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_unit_panel_indicator_object_entry_view_suite_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUnitPanelIndicatorObjectEntryViewSuite), 0, (GInstanceInitFunc) unity_tests_unit_panel_indicator_object_entry_view_suite_instance_init, NULL };
		GType unity_tests_unit_panel_indicator_object_entry_view_suite_type_id;
		unity_tests_unit_panel_indicator_object_entry_view_suite_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityTestsUnitPanelIndicatorObjectEntryViewSuite", &g_define_type_info, 0);
		g_once_init_leave (&unity_tests_unit_panel_indicator_object_entry_view_suite_type_id__volatile, unity_tests_unit_panel_indicator_object_entry_view_suite_type_id);
	}
	return unity_tests_unit_panel_indicator_object_entry_view_suite_type_id__volatile;
}


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




