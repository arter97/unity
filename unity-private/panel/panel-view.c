/* panel-view.c generated by valac 0.9.8, the Vala compiler
 * generated from panel-view.vala, do not modify */

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
#include <clutk/clutk.h>
#include <unity.h>
#include <clutter/clutter.h>
#include <unity-utils.h>


#define UNITY_PANEL_TYPE_VIEW (unity_panel_view_get_type ())
#define UNITY_PANEL_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_TYPE_VIEW, UnityPanelView))
#define UNITY_PANEL_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_TYPE_VIEW, UnityPanelViewClass))
#define UNITY_PANEL_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_TYPE_VIEW))
#define UNITY_PANEL_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_TYPE_VIEW))
#define UNITY_PANEL_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_TYPE_VIEW, UnityPanelViewClass))

typedef struct _UnityPanelView UnityPanelView;
typedef struct _UnityPanelViewClass UnityPanelViewClass;
typedef struct _UnityPanelViewPrivate UnityPanelViewPrivate;

#define UNITY_PANEL_TYPE_BACKGROUND (unity_panel_background_get_type ())
#define UNITY_PANEL_BACKGROUND(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_TYPE_BACKGROUND, UnityPanelBackground))
#define UNITY_PANEL_BACKGROUND_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_TYPE_BACKGROUND, UnityPanelBackgroundClass))
#define UNITY_PANEL_IS_BACKGROUND(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_TYPE_BACKGROUND))
#define UNITY_PANEL_IS_BACKGROUND_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_TYPE_BACKGROUND))
#define UNITY_PANEL_BACKGROUND_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_TYPE_BACKGROUND, UnityPanelBackgroundClass))

typedef struct _UnityPanelBackground UnityPanelBackground;
typedef struct _UnityPanelBackgroundClass UnityPanelBackgroundClass;

#define UNITY_PANEL_TYPE_HOME_BUTTON (unity_panel_home_button_get_type ())
#define UNITY_PANEL_HOME_BUTTON(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_TYPE_HOME_BUTTON, UnityPanelHomeButton))
#define UNITY_PANEL_HOME_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_TYPE_HOME_BUTTON, UnityPanelHomeButtonClass))
#define UNITY_PANEL_IS_HOME_BUTTON(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_TYPE_HOME_BUTTON))
#define UNITY_PANEL_IS_HOME_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_TYPE_HOME_BUTTON))
#define UNITY_PANEL_HOME_BUTTON_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_TYPE_HOME_BUTTON, UnityPanelHomeButtonClass))

typedef struct _UnityPanelHomeButton UnityPanelHomeButton;
typedef struct _UnityPanelHomeButtonClass UnityPanelHomeButtonClass;

#define UNITY_PANEL_TYPE_DIVIDER (unity_panel_divider_get_type ())
#define UNITY_PANEL_DIVIDER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_TYPE_DIVIDER, UnityPanelDivider))
#define UNITY_PANEL_DIVIDER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_TYPE_DIVIDER, UnityPanelDividerClass))
#define UNITY_PANEL_IS_DIVIDER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_TYPE_DIVIDER))
#define UNITY_PANEL_IS_DIVIDER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_TYPE_DIVIDER))
#define UNITY_PANEL_DIVIDER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_TYPE_DIVIDER, UnityPanelDividerClass))

typedef struct _UnityPanelDivider UnityPanelDivider;
typedef struct _UnityPanelDividerClass UnityPanelDividerClass;

#define UNITY_PANEL_TYPE_WINDOW_BUTTONS (unity_panel_window_buttons_get_type ())
#define UNITY_PANEL_WINDOW_BUTTONS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_TYPE_WINDOW_BUTTONS, UnityPanelWindowButtons))
#define UNITY_PANEL_WINDOW_BUTTONS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_TYPE_WINDOW_BUTTONS, UnityPanelWindowButtonsClass))
#define UNITY_PANEL_IS_WINDOW_BUTTONS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_TYPE_WINDOW_BUTTONS))
#define UNITY_PANEL_IS_WINDOW_BUTTONS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_TYPE_WINDOW_BUTTONS))
#define UNITY_PANEL_WINDOW_BUTTONS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_TYPE_WINDOW_BUTTONS, UnityPanelWindowButtonsClass))

typedef struct _UnityPanelWindowButtons UnityPanelWindowButtons;
typedef struct _UnityPanelWindowButtonsClass UnityPanelWindowButtonsClass;

#define UNITY_PANEL_INDICATORS_TYPE_MENU_BAR (unity_panel_indicators_menu_bar_get_type ())
#define UNITY_PANEL_INDICATORS_MENU_BAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_INDICATORS_TYPE_MENU_BAR, UnityPanelIndicatorsMenuBar))
#define UNITY_PANEL_INDICATORS_MENU_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_INDICATORS_TYPE_MENU_BAR, UnityPanelIndicatorsMenuBarClass))
#define UNITY_PANEL_INDICATORS_IS_MENU_BAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_INDICATORS_TYPE_MENU_BAR))
#define UNITY_PANEL_INDICATORS_IS_MENU_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_INDICATORS_TYPE_MENU_BAR))
#define UNITY_PANEL_INDICATORS_MENU_BAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_INDICATORS_TYPE_MENU_BAR, UnityPanelIndicatorsMenuBarClass))

typedef struct _UnityPanelIndicatorsMenuBar UnityPanelIndicatorsMenuBar;
typedef struct _UnityPanelIndicatorsMenuBarClass UnityPanelIndicatorsMenuBarClass;

#define UNITY_PANEL_TYPE_SYSTEM_TRAY (unity_panel_system_tray_get_type ())
#define UNITY_PANEL_SYSTEM_TRAY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_TYPE_SYSTEM_TRAY, UnityPanelSystemTray))
#define UNITY_PANEL_SYSTEM_TRAY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_TYPE_SYSTEM_TRAY, UnityPanelSystemTrayClass))
#define UNITY_PANEL_IS_SYSTEM_TRAY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_TYPE_SYSTEM_TRAY))
#define UNITY_PANEL_IS_SYSTEM_TRAY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_TYPE_SYSTEM_TRAY))
#define UNITY_PANEL_SYSTEM_TRAY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_TYPE_SYSTEM_TRAY, UnityPanelSystemTrayClass))

typedef struct _UnityPanelSystemTray UnityPanelSystemTray;
typedef struct _UnityPanelSystemTrayClass UnityPanelSystemTrayClass;

#define UNITY_PANEL_INDICATORS_TYPE_INDICATOR_BAR (unity_panel_indicators_indicator_bar_get_type ())
#define UNITY_PANEL_INDICATORS_INDICATOR_BAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_BAR, UnityPanelIndicatorsIndicatorBar))
#define UNITY_PANEL_INDICATORS_INDICATOR_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_BAR, UnityPanelIndicatorsIndicatorBarClass))
#define UNITY_PANEL_INDICATORS_IS_INDICATOR_BAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_BAR))
#define UNITY_PANEL_INDICATORS_IS_INDICATOR_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_BAR))
#define UNITY_PANEL_INDICATORS_INDICATOR_BAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_BAR, UnityPanelIndicatorsIndicatorBarClass))

typedef struct _UnityPanelIndicatorsIndicatorBar UnityPanelIndicatorsIndicatorBar;
typedef struct _UnityPanelIndicatorsIndicatorBarClass UnityPanelIndicatorsIndicatorBarClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define TYPE_MENU_MANAGER (menu_manager_get_type ())
#define MENU_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MENU_MANAGER, MenuManager))
#define MENU_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MENU_MANAGER, MenuManagerClass))
#define IS_MENU_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MENU_MANAGER))
#define IS_MENU_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MENU_MANAGER))
#define MENU_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MENU_MANAGER, MenuManagerClass))

typedef struct _MenuManager MenuManager;
typedef struct _MenuManagerClass MenuManagerClass;
typedef struct _UnityPanelIndicatorsMenuBarPrivate UnityPanelIndicatorsMenuBarPrivate;

#define UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW (unity_panel_indicators_indicator_object_view_get_type ())
#define UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW, UnityPanelIndicatorsIndicatorObjectView))
#define UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW, UnityPanelIndicatorsIndicatorObjectViewClass))
#define UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW))
#define UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW))
#define UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW, UnityPanelIndicatorsIndicatorObjectViewClass))

typedef struct _UnityPanelIndicatorsIndicatorObjectView UnityPanelIndicatorsIndicatorObjectView;
typedef struct _UnityPanelIndicatorsIndicatorObjectViewClass UnityPanelIndicatorsIndicatorObjectViewClass;

#define UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL (unity_panel_indicators_indicators_model_get_type ())
#define UNITY_PANEL_INDICATORS_INDICATORS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL, UnityPanelIndicatorsIndicatorsModel))
#define UNITY_PANEL_INDICATORS_INDICATORS_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL, UnityPanelIndicatorsIndicatorsModelClass))
#define UNITY_PANEL_INDICATORS_IS_INDICATORS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL))
#define UNITY_PANEL_INDICATORS_IS_INDICATORS_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL))
#define UNITY_PANEL_INDICATORS_INDICATORS_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL, UnityPanelIndicatorsIndicatorsModelClass))

typedef struct _UnityPanelIndicatorsIndicatorsModel UnityPanelIndicatorsIndicatorsModel;
typedef struct _UnityPanelIndicatorsIndicatorsModelClass UnityPanelIndicatorsIndicatorsModelClass;

struct _UnityPanelView {
	CtkBin parent_instance;
	UnityPanelViewPrivate * priv;
	CtkEffectCache* cache;
	gboolean expanded;
};

struct _UnityPanelViewClass {
	CtkBinClass parent_class;
};

struct _UnityPanelViewPrivate {
	UnityShell* _shell;
	CtkHBox* hbox;
	UnityPanelBackground* bground;
	UnityPanelHomeButton* home_button;
	UnityPanelDivider* divider;
	UnityPanelWindowButtons* window_buttons;
	UnityPanelIndicatorsMenuBar* menu_bar;
	UnityPanelSystemTray* system_tray;
	UnityPanelIndicatorsIndicatorBar* indicator_bar;
};

struct _UnityPanelIndicatorsMenuBar {
	CtkBox parent_instance;
	UnityPanelIndicatorsMenuBarPrivate * priv;
	UnityPanelIndicatorsIndicatorObjectView* indicator_object_view;
};

struct _UnityPanelIndicatorsMenuBarClass {
	CtkBoxClass parent_class;
};


static gpointer unity_panel_view_parent_class = NULL;

#define UNITY_PANEL_PANEL_HEIGHT 24
#define UNITY_PANEL_search_entry_has_focus FALSE
GType unity_panel_view_get_type (void) G_GNUC_CONST;
GType unity_panel_background_get_type (void) G_GNUC_CONST;
GType unity_panel_home_button_get_type (void) G_GNUC_CONST;
GType unity_panel_divider_get_type (void) G_GNUC_CONST;
GType unity_panel_window_buttons_get_type (void) G_GNUC_CONST;
GType unity_panel_indicators_menu_bar_get_type (void) G_GNUC_CONST;
GType unity_panel_system_tray_get_type (void) G_GNUC_CONST;
GType unity_panel_indicators_indicator_bar_get_type (void) G_GNUC_CONST;
#define UNITY_PANEL_VIEW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PANEL_TYPE_VIEW, UnityPanelViewPrivate))
enum  {
	UNITY_PANEL_VIEW_DUMMY_PROPERTY,
	UNITY_PANEL_VIEW_SHELL
};
UnityPanelView* unity_panel_view_new (UnityShell* shell);
UnityPanelView* unity_panel_view_construct (GType object_type, UnityShell* shell);
void unity_panel_system_tray_manage_stage (UnityPanelSystemTray* self, ClutterStage* stage);
static gboolean unity_panel_view_on_button_release_event (UnityPanelView* self, ClutterEvent* e);
GType menu_manager_get_type (void) G_GNUC_CONST;
MenuManager* menu_manager_get_default (void);
void menu_manager_popdown_current_menu (MenuManager* self);
gint unity_panel_view_get_indicators_width (UnityPanelView* self);
void unity_panel_view_set_expanded (UnityPanelView* self, gboolean _expanded);
gint unity_panel_view_get_panel_height (UnityPanelView* self);
void unity_panel_view_set_indicator_mode (UnityPanelView* self, gboolean mode);
static gboolean _lambda15_ (UnityPanelView* self);
static gboolean __lambda15__gsource_func (gpointer self);
GType unity_panel_indicators_indicator_object_view_get_type (void) G_GNUC_CONST;
static gboolean _lambda16_ (UnityPanelView* self);
static gboolean __lambda16__gsource_func (gpointer self);
UnityShell* unity_panel_view_get_shell (UnityPanelView* self);
static void unity_panel_view_set_shell (UnityPanelView* self, UnityShell* value);
GType unity_panel_indicators_indicators_model_get_type (void) G_GNUC_CONST;
UnityPanelIndicatorsIndicatorsModel* unity_panel_indicators_indicators_model_get_default (void);
UnityPanelBackground* unity_panel_background_new (void);
UnityPanelBackground* unity_panel_background_construct (GType object_type);
UnityPanelHomeButton* unity_panel_home_button_new (UnityShell* shell);
UnityPanelHomeButton* unity_panel_home_button_construct (GType object_type, UnityShell* shell);
UnityPanelDivider* unity_panel_divider_new (UnityShell* shell);
UnityPanelDivider* unity_panel_divider_construct (GType object_type, UnityShell* shell);
UnityPanelWindowButtons* unity_panel_window_buttons_new (void);
UnityPanelWindowButtons* unity_panel_window_buttons_construct (GType object_type);
UnityPanelIndicatorsMenuBar* unity_panel_indicators_menu_bar_new (void);
UnityPanelIndicatorsMenuBar* unity_panel_indicators_menu_bar_construct (GType object_type);
UnityPanelSystemTray* unity_panel_system_tray_new (void);
UnityPanelSystemTray* unity_panel_system_tray_construct (GType object_type);
UnityPanelIndicatorsIndicatorBar* unity_panel_indicators_indicator_bar_new (void);
UnityPanelIndicatorsIndicatorBar* unity_panel_indicators_indicator_bar_construct (GType object_type);
static gboolean _unity_panel_view_on_button_release_event_clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static void _lambda17_ (UnityPanelView* self);
static void __lambda17__clutter_actor_queue_redraw (ClutterActor* _sender, ClutterActor* origin, gpointer self);
static GObject * unity_panel_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_panel_view_finalize (GObject* obj);
static void unity_panel_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_panel_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UnityPanelView* unity_panel_view_construct (GType object_type, UnityShell* shell) {
	UnityPanelView * self;
	ClutterStage* _tmp0_;
	g_return_val_if_fail (shell != NULL, NULL);
	self = (UnityPanelView*) g_object_new (object_type, "shell", shell, "reactive", TRUE, NULL);
	unity_panel_system_tray_manage_stage (self->priv->system_tray, _tmp0_ = unity_shell_get_stage (shell));
	_g_object_unref0 (_tmp0_);
	return self;
}


UnityPanelView* unity_panel_view_new (UnityShell* shell) {
	return unity_panel_view_construct (UNITY_PANEL_TYPE_VIEW, shell);
}


static gboolean unity_panel_view_on_button_release_event (UnityPanelView* self, ClutterEvent* e) {
	gboolean result = FALSE;
	MenuManager* manager;
	g_return_val_if_fail (self != NULL, FALSE);
	manager = menu_manager_get_default ();
	menu_manager_popdown_current_menu (manager);
	result = FALSE;
	_g_object_unref0 (manager);
	return result;
}


gint unity_panel_view_get_indicators_width (UnityPanelView* self) {
	gint result = 0;
	g_return_val_if_fail (self != NULL, 0);
	result = (gint) clutter_actor_get_width ((ClutterActor*) self->priv->indicator_bar);
	return result;
}


void unity_panel_view_set_expanded (UnityPanelView* self, gboolean _expanded) {
	g_return_if_fail (self != NULL);
	self->expanded = _expanded;
}


gint unity_panel_view_get_panel_height (UnityPanelView* self) {
	gint result = 0;
	g_return_val_if_fail (self != NULL, 0);
	result = UNITY_PANEL_PANEL_HEIGHT;
	return result;
}


static gboolean _lambda15_ (UnityPanelView* self) {
	gboolean result = FALSE;
	ctk_effect_cache_invalidate_texture_cache (self->cache);
	clutter_actor_queue_redraw ((ClutterActor*) self);
	result = FALSE;
	return result;
}


static gboolean __lambda15__gsource_func (gpointer self) {
	gboolean result;
	result = _lambda15_ (self);
	return result;
}


static gboolean _lambda16_ (UnityPanelView* self) {
	gboolean result = FALSE;
	ctk_effect_cache_update_texture_cache (self->cache);
	clutter_actor_queue_redraw ((ClutterActor*) self);
	result = FALSE;
	return result;
}


static gboolean __lambda16__gsource_func (gpointer self) {
	gboolean result;
	result = _lambda16_ (self);
	return result;
}


void unity_panel_view_set_indicator_mode (UnityPanelView* self, gboolean mode) {
	g_return_if_fail (self != NULL);
	if (mode) {
		g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 0, __lambda15__gsource_func, g_object_ref (self), g_object_unref);
		if (CLUTTER_IS_ACTOR (self->priv->menu_bar->indicator_object_view)) {
			clutter_actor_hide ((ClutterActor*) self->priv->menu_bar->indicator_object_view);
		}
		clutter_actor_hide ((ClutterActor*) self->priv->window_buttons);
		clutter_actor_hide ((ClutterActor*) self->priv->bground);
		clutter_actor_hide ((ClutterActor*) self->priv->system_tray);
		clutter_actor_set_reactive ((ClutterActor*) self, FALSE);
		clutter_actor_queue_redraw ((ClutterActor*) self);
	} else {
		if (CLUTTER_IS_ACTOR (self->priv->menu_bar->indicator_object_view)) {
			clutter_actor_show ((ClutterActor*) self->priv->menu_bar->indicator_object_view);
		}
		clutter_actor_show ((ClutterActor*) self->priv->window_buttons);
		clutter_actor_show ((ClutterActor*) self->priv->bground);
		clutter_actor_show ((ClutterActor*) self->priv->system_tray);
		clutter_actor_set_reactive ((ClutterActor*) self, TRUE);
		ctk_actor_remove_all_effects ((CtkActor*) self->priv->indicator_bar);
		g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 0, __lambda16__gsource_func, g_object_ref (self), g_object_unref);
	}
}


UnityShell* unity_panel_view_get_shell (UnityPanelView* self) {
	UnityShell* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_shell;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_panel_view_set_shell (UnityPanelView* self, UnityShell* value) {
	UnityShell* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_shell = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_shell), _tmp0_);
	g_object_notify ((GObject *) self, "shell");
}


static gboolean _unity_panel_view_on_button_release_event_clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = unity_panel_view_on_button_release_event (self, event);
	return result;
}


static void _lambda17_ (UnityPanelView* self) {
	if (clutter_actor_get_reactive ((ClutterActor*) self) == TRUE) {
		ctk_effect_cache_update_texture_cache (self->cache);
	}
}


static void __lambda17__clutter_actor_queue_redraw (ClutterActor* _sender, ClutterActor* origin, gpointer self) {
	_lambda17_ (self);
}


static GObject * unity_panel_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPanelView * self;
	parent_class = G_OBJECT_CLASS (unity_panel_view_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PANEL_VIEW (obj);
	{
		UnityPanelIndicatorsIndicatorsModel* _tmp0_;
		CtkHBox* _tmp1_;
		UnityPanelBackground* _tmp2_;
		UnityPanelHomeButton* _tmp3_;
		UnityPanelDivider* _tmp4_;
		UnityPanelWindowButtons* _tmp5_;
		UnityPanelIndicatorsMenuBar* _tmp6_;
		UnityPanelSystemTray* _tmp7_;
		UnityPanelIndicatorsIndicatorBar* _tmp8_;
		CtkEffectCache* _tmp9_;
		START_FUNCTION ();
		_tmp0_ = unity_panel_indicators_indicators_model_get_default ();
		_g_object_unref0 (_tmp0_);
		self->priv->hbox = (_tmp1_ = g_object_ref_sink ((CtkHBox*) ctk_hbox_new ((guint) 0)), _g_object_unref0 (self->priv->hbox), _tmp1_);
		ctk_box_set_homogeneous ((CtkBox*) self->priv->hbox, FALSE);
		clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) self->priv->hbox);
		clutter_actor_show ((ClutterActor*) self->priv->hbox);
		self->priv->bground = (_tmp2_ = g_object_ref_sink (unity_panel_background_new ()), _g_object_unref0 (self->priv->bground), _tmp2_);
		ctk_actor_set_background ((CtkActor*) self, (ClutterActor*) self->priv->bground);
		clutter_actor_show ((ClutterActor*) self->priv->bground);
		self->priv->home_button = (_tmp3_ = g_object_ref_sink (unity_panel_home_button_new (self->priv->_shell)), _g_object_unref0 (self->priv->home_button), _tmp3_);
		ctk_box_pack ((CtkBox*) self->priv->hbox, (ClutterActor*) self->priv->home_button, FALSE, TRUE);
		clutter_actor_show ((ClutterActor*) self->priv->home_button);
		self->priv->divider = (_tmp4_ = g_object_ref_sink (unity_panel_divider_new (self->priv->_shell)), _g_object_unref0 (self->priv->divider), _tmp4_);
		ctk_box_pack ((CtkBox*) self->priv->hbox, (ClutterActor*) self->priv->divider, FALSE, FALSE);
		clutter_actor_show ((ClutterActor*) self->priv->divider);
		self->priv->window_buttons = (_tmp5_ = g_object_ref_sink (unity_panel_window_buttons_new ()), _g_object_unref0 (self->priv->window_buttons), _tmp5_);
		ctk_box_pack ((CtkBox*) self->priv->hbox, (ClutterActor*) self->priv->window_buttons, FALSE, TRUE);
		clutter_actor_show ((ClutterActor*) self->priv->window_buttons);
		self->priv->menu_bar = (_tmp6_ = g_object_ref_sink (unity_panel_indicators_menu_bar_new ()), _g_object_unref0 (self->priv->menu_bar), _tmp6_);
		ctk_box_pack ((CtkBox*) self->priv->hbox, (ClutterActor*) self->priv->menu_bar, TRUE, TRUE);
		clutter_actor_show ((ClutterActor*) self->priv->menu_bar);
		self->priv->system_tray = (_tmp7_ = g_object_ref_sink (unity_panel_system_tray_new ()), _g_object_unref0 (self->priv->system_tray), _tmp7_);
		ctk_box_pack ((CtkBox*) self->priv->hbox, (ClutterActor*) self->priv->system_tray, FALSE, TRUE);
		clutter_actor_show ((ClutterActor*) self->priv->system_tray);
		self->priv->indicator_bar = (_tmp8_ = g_object_ref_sink (unity_panel_indicators_indicator_bar_new ()), _g_object_unref0 (self->priv->indicator_bar), _tmp8_);
		ctk_box_pack ((CtkBox*) self->priv->hbox, (ClutterActor*) self->priv->indicator_bar, FALSE, TRUE);
		clutter_actor_show ((ClutterActor*) self->priv->indicator_bar);
		g_signal_connect_object ((ClutterActor*) self, "button-release-event", (GCallback) _unity_panel_view_on_button_release_event_clutter_actor_button_release_event, self, 0);
		self->cache = (_tmp9_ = g_object_ref_sink ((CtkEffectCache*) ctk_effect_cache_new ()), _g_object_unref0 (self->cache), _tmp9_);
		ctk_actor_add_effect ((CtkActor*) self, (CtkEffect*) self->cache);
		ctk_effect_cache_update_texture_cache (self->cache);
		g_signal_connect_object ((ClutterActor*) self->priv->hbox, "queue-redraw", (GCallback) __lambda17__clutter_actor_queue_redraw, self, 0);
		END_FUNCTION ();
	}
	return obj;
}


static void unity_panel_view_class_init (UnityPanelViewClass * klass) {
	unity_panel_view_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPanelViewPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_panel_view_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_panel_view_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_panel_view_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_panel_view_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PANEL_VIEW_SHELL, g_param_spec_object ("shell", "shell", "shell", UNITY_TYPE_SHELL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_panel_view_instance_init (UnityPanelView * self) {
	self->priv = UNITY_PANEL_VIEW_GET_PRIVATE (self);
	self->expanded = TRUE;
}


static void unity_panel_view_finalize (GObject* obj) {
	UnityPanelView * self;
	self = UNITY_PANEL_VIEW (obj);
	_g_object_unref0 (self->cache);
	_g_object_unref0 (self->priv->_shell);
	_g_object_unref0 (self->priv->hbox);
	_g_object_unref0 (self->priv->bground);
	_g_object_unref0 (self->priv->home_button);
	_g_object_unref0 (self->priv->divider);
	_g_object_unref0 (self->priv->window_buttons);
	_g_object_unref0 (self->priv->menu_bar);
	_g_object_unref0 (self->priv->system_tray);
	_g_object_unref0 (self->priv->indicator_bar);
	G_OBJECT_CLASS (unity_panel_view_parent_class)->finalize (obj);
}


GType unity_panel_view_get_type (void) {
	static volatile gsize unity_panel_view_type_id__volatile = 0;
	if (g_once_init_enter (&unity_panel_view_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPanelViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_panel_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPanelView), 0, (GInstanceInitFunc) unity_panel_view_instance_init, NULL };
		GType unity_panel_view_type_id;
		unity_panel_view_type_id = g_type_register_static (CTK_TYPE_BIN, "UnityPanelView", &g_define_type_info, 0);
		g_once_init_leave (&unity_panel_view_type_id__volatile, unity_panel_view_type_id);
	}
	return unity_panel_view_type_id__volatile;
}


static void unity_panel_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPanelView * self;
	self = UNITY_PANEL_VIEW (object);
	switch (property_id) {
		case UNITY_PANEL_VIEW_SHELL:
		g_value_set_object (value, unity_panel_view_get_shell (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_panel_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPanelView * self;
	self = UNITY_PANEL_VIEW (object);
	switch (property_id) {
		case UNITY_PANEL_VIEW_SHELL:
		unity_panel_view_set_shell (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




