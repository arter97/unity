/* panel-home-button.c generated by valac, the Vala compiler
 * generated from panel-home-button.vala, do not modify */

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
#include <clutk/clutk.h>
#include <unity.h>
#include <clutter/clutter.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>


#define UNITY_PANEL_TYPE_HOME_BUTTON (unity_panel_home_button_get_type ())
#define UNITY_PANEL_HOME_BUTTON(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_TYPE_HOME_BUTTON, UnityPanelHomeButton))
#define UNITY_PANEL_HOME_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_TYPE_HOME_BUTTON, UnityPanelHomeButtonClass))
#define UNITY_PANEL_IS_HOME_BUTTON(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_TYPE_HOME_BUTTON))
#define UNITY_PANEL_IS_HOME_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_TYPE_HOME_BUTTON))
#define UNITY_PANEL_HOME_BUTTON_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_TYPE_HOME_BUTTON, UnityPanelHomeButtonClass))

typedef struct _UnityPanelHomeButton UnityPanelHomeButton;
typedef struct _UnityPanelHomeButtonClass UnityPanelHomeButtonClass;
typedef struct _UnityPanelHomeButtonPrivate UnityPanelHomeButtonPrivate;
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

#define TYPE_MENU_MANAGER (menu_manager_get_type ())
#define MENU_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MENU_MANAGER, MenuManager))
#define MENU_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MENU_MANAGER, MenuManagerClass))
#define IS_MENU_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MENU_MANAGER))
#define IS_MENU_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MENU_MANAGER))
#define MENU_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MENU_MANAGER, MenuManagerClass))

typedef struct _MenuManager MenuManager;
typedef struct _MenuManagerClass MenuManagerClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _UnityPanelHomeButton {
	CtkButton parent_instance;
	UnityPanelHomeButtonPrivate * priv;
};

struct _UnityPanelHomeButtonClass {
	CtkButtonClass parent_class;
};

struct _UnityPanelHomeButtonPrivate {
	UnityShell* _shell;
	CtkImage* theme_image;
	CtkEffectGlow* glow;
	ClutterTexture* bfb_bg_normal;
	ClutterTexture* bfb_bg_prelight;
	ClutterTexture* bfb_bg_active;
	gboolean search_shown;
};


static gpointer unity_panel_home_button_parent_class = NULL;

GType unity_panel_home_button_get_type (void) G_GNUC_CONST;
#define UNITY_PANEL_HOME_BUTTON_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PANEL_TYPE_HOME_BUTTON, UnityPanelHomeButtonPrivate))
enum  {
	UNITY_PANEL_HOME_BUTTON_DUMMY_PROPERTY,
	UNITY_PANEL_HOME_BUTTON_SHELL
};
gpointer unity_testing_object_registry_ref (gpointer instance);
void unity_testing_object_registry_unref (gpointer instance);
GParamSpec* unity_testing_param_spec_object_registry (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_testing_value_set_object_registry (GValue* value, gpointer v_object);
void unity_testing_value_take_object_registry (GValue* value, gpointer v_object);
gpointer unity_testing_value_get_object_registry (const GValue* value);
GType unity_testing_object_registry_get_type (void) G_GNUC_CONST;
UnityTestingObjectRegistry* unity_testing_object_registry_get_default (void);
void unity_testing_object_registry_register (UnityTestingObjectRegistry* self, const char* name, GObject* object);
UnityPanelHomeButton* unity_panel_home_button_new (UnityShell* shell);
UnityPanelHomeButton* unity_panel_home_button_construct (GType object_type, UnityShell* shell);
UnityShell* unity_panel_home_button_get_shell (UnityPanelHomeButton* self);
static void unity_panel_home_button_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
static void unity_panel_home_button_on_state_changed (UnityPanelHomeButton* self);
static void unity_panel_home_button_real_get_preferred_width (ClutterActor* base, float for_height, float* min_width, float* nat_width);
static void unity_panel_home_button_on_mode_changed (UnityPanelHomeButton* self, UnityShellMode mode);
GType menu_manager_get_type (void) G_GNUC_CONST;
MenuManager* menu_manager_get_default (void);
void menu_manager_popdown_current_menu (MenuManager* self);
static void unity_panel_home_button_on_clicked (UnityPanelHomeButton* self);
static gboolean unity_panel_home_button_on_motion_event (UnityPanelHomeButton* self, ClutterEvent* event);
static void unity_panel_home_button_set_shell (UnityPanelHomeButton* self, UnityShell* value);
static gboolean _unity_panel_home_button_on_motion_event_clutter_actor_motion_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static void _unity_panel_home_button_on_clicked_ctk_button_clicked (CtkButton* _sender, gpointer self);
static void _unity_panel_home_button_on_mode_changed_unity_shell_mode_changed (UnityShell* _sender, UnityShellMode mode, gpointer self);
static void _unity_panel_home_button_on_state_changed_g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self);
static GObject * unity_panel_home_button_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_panel_home_button_finalize (GObject* obj);
static void unity_panel_home_button_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_panel_home_button_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UnityPanelHomeButton* unity_panel_home_button_construct (GType object_type, UnityShell* shell) {
	UnityPanelHomeButton * self;
	UnityTestingObjectRegistry* _tmp0_;
	g_return_val_if_fail (shell != NULL, NULL);
	self = (UnityPanelHomeButton*) g_object_new (object_type, "reactive", TRUE, "shell", shell, NULL);
	unity_testing_object_registry_register (_tmp0_ = unity_testing_object_registry_get_default (), "PanelHomeButton", (GObject*) self);
	_unity_testing_object_registry_unref0 (_tmp0_);
	return self;
}


UnityPanelHomeButton* unity_panel_home_button_new (UnityShell* shell) {
	return unity_panel_home_button_construct (UNITY_PANEL_TYPE_HOME_BUTTON, shell);
}


static void unity_panel_home_button_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
	UnityPanelHomeButton * self;
	float cwidth = 0.0F;
	float cheight = 0.0F;
	float lwidth = 0.0F;
	float pheight = 0.0F;
	CtkPadding _tmp0_ = {0};
	CtkPadding pad;
	self = (UnityPanelHomeButton*) base;
	pad = (_tmp0_.top = (float) 0, _tmp0_);
	lwidth = (float) unity_shell_get_launcher_width_foobar (self->priv->_shell);
	pheight = (float) unity_shell_get_panel_height_foobar (self->priv->_shell);
	clutter_actor_get_preferred_size ((ClutterActor*) self->priv->theme_image, &cwidth, &cheight, &cwidth, &cheight);
	if ((lwidth - cwidth) <= 0.0f) {
		pad.left = 0.0f;
		pad.right = pad.left;
	} else {
		pad.left = (((*box).x2 - (*box).x1) - cwidth) / 2.0f;
		pad.right = pad.left;
	}
	if ((pheight - cheight) <= 0.0f) {
		pad.top = 0.0f;
		pad.bottom = pad.top;
	} else {
		pad.top = (((*box).y2 - (*box).y1) - cheight) / 2.0f;
		pad.bottom = pad.top;
	}
	ctk_actor_set_padding ((CtkActor*) self, &pad);
	CLUTTER_ACTOR_CLASS (unity_panel_home_button_parent_class)->allocate ((ClutterActor*) CTK_BUTTON (self), box, flags);
}


static void unity_panel_home_button_on_state_changed (UnityPanelHomeButton* self) {
	g_return_if_fail (self != NULL);
	switch (ctk_actor_get_state ((CtkActor*) self)) {
		case CTK_STATE_NORMAL:
		{
			ctk_effect_glow_set_factor (self->priv->glow, 0.0f);
			ctk_effect_set_invalidate_effect_cache ((CtkEffect*) self->priv->glow, TRUE);
			clutter_actor_queue_redraw ((ClutterActor*) self);
			break;
		}
		case CTK_STATE_PRELIGHT:
		{
			ctk_effect_glow_set_factor (self->priv->glow, 0.8f);
			ctk_effect_set_invalidate_effect_cache ((CtkEffect*) self->priv->glow, TRUE);
			clutter_actor_queue_redraw ((ClutterActor*) self);
			break;
		}
		case CTK_STATE_ACTIVE:
		{
			ctk_effect_glow_set_factor (self->priv->glow, 1.0f);
			ctk_effect_set_invalidate_effect_cache ((CtkEffect*) self->priv->glow, TRUE);
			clutter_actor_queue_redraw ((ClutterActor*) self);
			break;
		}
	}
}


static void unity_panel_home_button_real_get_preferred_width (ClutterActor* base, float for_height, float* min_width, float* nat_width) {
	UnityPanelHomeButton * self;
	self = (UnityPanelHomeButton*) base;
	*min_width = (float) unity_shell_get_launcher_width_foobar (self->priv->_shell);
	*nat_width = (float) unity_shell_get_launcher_width_foobar (self->priv->_shell);
}


static void unity_panel_home_button_on_mode_changed (UnityPanelHomeButton* self, UnityShellMode mode) {
	g_return_if_fail (self != NULL);
	if (mode == UNITY_SHELL_MODE_MINIMIZED) {
		ctk_actor_set_background_for_state ((CtkActor*) self, CTK_STATE_ACTIVE, (ClutterActor*) self->priv->bfb_bg_active);
		self->priv->search_shown = FALSE;
	} else {
		ctk_actor_set_background_for_state ((CtkActor*) self, CTK_STATE_NORMAL, NULL);
		ctk_actor_set_background_for_state ((CtkActor*) self, CTK_STATE_PRELIGHT, NULL);
		ctk_actor_set_background_for_state ((CtkActor*) self, CTK_STATE_ACTIVE, NULL);
		self->priv->search_shown = TRUE;
	}
	clutter_actor_queue_redraw ((ClutterActor*) self);
}


static void unity_panel_home_button_on_clicked (UnityPanelHomeButton* self) {
	MenuManager* manager;
	g_return_if_fail (self != NULL);
	unity_shell_show_unity (self->priv->_shell);
	manager = menu_manager_get_default ();
	menu_manager_popdown_current_menu (manager);
	unity_panel_home_button_on_mode_changed (self, unity_shell_get_mode (self->priv->_shell));
	_g_object_unref0 (manager);
}


static gboolean unity_panel_home_button_on_motion_event (UnityPanelHomeButton* self, ClutterEvent* event) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	unity_shell_about_to_show_places (self->priv->_shell);
	result = TRUE;
	return result;
}


UnityShell* unity_panel_home_button_get_shell (UnityPanelHomeButton* self) {
	UnityShell* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_shell;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_panel_home_button_set_shell (UnityPanelHomeButton* self, UnityShell* value) {
	UnityShell* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_shell = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_shell), _tmp0_);
	g_object_notify ((GObject *) self, "shell");
}


static gboolean _unity_panel_home_button_on_motion_event_clutter_actor_motion_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = unity_panel_home_button_on_motion_event (self, event);
	return result;
}


static void _unity_panel_home_button_on_clicked_ctk_button_clicked (CtkButton* _sender, gpointer self) {
	unity_panel_home_button_on_clicked (self);
}


static void _unity_panel_home_button_on_mode_changed_unity_shell_mode_changed (UnityShell* _sender, UnityShellMode mode, gpointer self) {
	unity_panel_home_button_on_mode_changed (self, mode);
}


static void _unity_panel_home_button_on_state_changed_g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self) {
	unity_panel_home_button_on_state_changed (self);
}


static GObject * unity_panel_home_button_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPanelHomeButton * self;
	GError * _inner_error_;
	parent_class = G_OBJECT_CLASS (unity_panel_home_button_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PANEL_HOME_BUTTON (obj);
	_inner_error_ = NULL;
	{
		CtkImage* _tmp0_;
		CtkEffectGlow* _tmp1_;
		ClutterColor _tmp3_;
		ClutterColor _tmp2_ = {0};
		self->priv->theme_image = (_tmp0_ = g_object_ref_sink ((CtkImage*) ctk_image_new_from_filename ((guint) 22, "/usr/share/icons/unity-icon-theme/places/22/distributor-logo.png")), _g_object_unref0 (self->priv->theme_image), _tmp0_);
		clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) self->priv->theme_image);
		clutter_actor_show ((ClutterActor*) self->priv->theme_image);
		g_signal_connect_object ((ClutterActor*) self, "motion-event", (GCallback) _unity_panel_home_button_on_motion_event_clutter_actor_motion_event, self, 0);
		g_signal_connect_object ((CtkButton*) self, "clicked", (GCallback) _unity_panel_home_button_on_clicked_ctk_button_clicked, self, 0);
		g_signal_connect_object (self->priv->_shell, "mode-changed", (GCallback) _unity_panel_home_button_on_mode_changed_unity_shell_mode_changed, self, 0);
		g_signal_connect_object ((GObject*) self, "notify::state", (GCallback) _unity_panel_home_button_on_state_changed_g_object_notify, self, 0);
		clutter_actor_set_width ((ClutterActor*) self, clutter_actor_get_width ((ClutterActor*) self) + 3.0f);
		self->priv->glow = (_tmp1_ = g_object_ref_sink ((CtkEffectGlow*) ctk_effect_glow_new ()), _g_object_unref0 (self->priv->glow), _tmp1_);
		ctk_effect_glow_set_color (self->priv->glow, (_tmp3_ = (_tmp2_.red = (guint8) 255, _tmp2_.green = (guint8) 255, _tmp2_.blue = (guint8) 255, _tmp2_.alpha = (guint8) 255, _tmp2_), &_tmp3_));
		ctk_effect_glow_set_factor (self->priv->glow, 0.0f);
		ctk_effect_set_margin ((CtkEffect*) self->priv->glow, 5);
		{
			ClutterTexture* _tmp4_;
			ClutterTexture* _tmp5_;
			_tmp4_ = g_object_ref_sink ((ClutterTexture*) clutter_texture_new_from_file ("/usr/share/unity/themes/bfb_bg_normal.png", &_inner_error_));
			if (_inner_error_ != NULL) {
				goto __catch6_g_error;
			}
			self->priv->bfb_bg_normal = (_tmp5_ = g_object_ref_sink (_tmp4_), _g_object_unref0 (self->priv->bfb_bg_normal), _tmp5_);
		}
		goto __finally6;
		__catch6_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("panel-home-button.vala:75: Could not load normal-state bg-texture: %s", e->message);
				_g_error_free0 (e);
			}
		}
		__finally6:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		{
			ClutterTexture* _tmp6_;
			ClutterTexture* _tmp7_;
			_tmp6_ = g_object_ref_sink ((ClutterTexture*) clutter_texture_new_from_file ("/usr/share/unity/themes/bfb_bg_prelight.png", &_inner_error_));
			if (_inner_error_ != NULL) {
				goto __catch7_g_error;
			}
			self->priv->bfb_bg_prelight = (_tmp7_ = g_object_ref_sink (_tmp6_), _g_object_unref0 (self->priv->bfb_bg_prelight), _tmp7_);
		}
		goto __finally7;
		__catch7_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("panel-home-button.vala:85: Could not load prelight-state bg-texture: %" \
"s", e->message);
				_g_error_free0 (e);
			}
		}
		__finally7:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		{
			ClutterTexture* _tmp8_;
			ClutterTexture* _tmp9_;
			_tmp8_ = g_object_ref_sink ((ClutterTexture*) clutter_texture_new_from_file ("/usr/share/unity/themes/bfb_bg_active.png", &_inner_error_));
			if (_inner_error_ != NULL) {
				goto __catch8_g_error;
			}
			self->priv->bfb_bg_active = (_tmp9_ = g_object_ref_sink (_tmp8_), _g_object_unref0 (self->priv->bfb_bg_active), _tmp9_);
		}
		goto __finally8;
		__catch8_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("panel-home-button.vala:95: Could not load active-state bg-texture: %s", e->message);
				_g_error_free0 (e);
			}
		}
		__finally8:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		ctk_actor_set_background_for_state ((CtkActor*) self, CTK_STATE_ACTIVE, (ClutterActor*) self->priv->bfb_bg_active);
		self->priv->search_shown = FALSE;
	}
	return obj;
}


static void unity_panel_home_button_class_init (UnityPanelHomeButtonClass * klass) {
	unity_panel_home_button_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPanelHomeButtonPrivate));
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_panel_home_button_real_allocate;
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_width = unity_panel_home_button_real_get_preferred_width;
	G_OBJECT_CLASS (klass)->get_property = unity_panel_home_button_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_panel_home_button_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_panel_home_button_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_panel_home_button_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PANEL_HOME_BUTTON_SHELL, g_param_spec_object ("shell", "shell", "shell", UNITY_TYPE_SHELL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_panel_home_button_instance_init (UnityPanelHomeButton * self) {
	self->priv = UNITY_PANEL_HOME_BUTTON_GET_PRIVATE (self);
}


static void unity_panel_home_button_finalize (GObject* obj) {
	UnityPanelHomeButton * self;
	self = UNITY_PANEL_HOME_BUTTON (obj);
	_g_object_unref0 (self->priv->_shell);
	_g_object_unref0 (self->priv->theme_image);
	_g_object_unref0 (self->priv->glow);
	_g_object_unref0 (self->priv->bfb_bg_normal);
	_g_object_unref0 (self->priv->bfb_bg_prelight);
	_g_object_unref0 (self->priv->bfb_bg_active);
	G_OBJECT_CLASS (unity_panel_home_button_parent_class)->finalize (obj);
}


GType unity_panel_home_button_get_type (void) {
	static volatile gsize unity_panel_home_button_type_id__volatile = 0;
	if (g_once_init_enter (&unity_panel_home_button_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPanelHomeButtonClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_panel_home_button_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPanelHomeButton), 0, (GInstanceInitFunc) unity_panel_home_button_instance_init, NULL };
		GType unity_panel_home_button_type_id;
		unity_panel_home_button_type_id = g_type_register_static (CTK_TYPE_BUTTON, "UnityPanelHomeButton", &g_define_type_info, 0);
		g_once_init_leave (&unity_panel_home_button_type_id__volatile, unity_panel_home_button_type_id);
	}
	return unity_panel_home_button_type_id__volatile;
}


static void unity_panel_home_button_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPanelHomeButton * self;
	self = UNITY_PANEL_HOME_BUTTON (object);
	switch (property_id) {
		case UNITY_PANEL_HOME_BUTTON_SHELL:
		g_value_set_object (value, unity_panel_home_button_get_shell (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_panel_home_button_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPanelHomeButton * self;
	self = UNITY_PANEL_HOME_BUTTON (object);
	switch (property_id) {
		case UNITY_PANEL_HOME_BUTTON_SHELL:
		unity_panel_home_button_set_shell (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




