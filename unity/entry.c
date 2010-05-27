/* entry.c generated by valac, the Vala compiler
 * generated from entry.vala, do not modify */

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
#include <clutter/clutter.h>


#define UNITY_TYPE_ENTRY (unity_entry_get_type ())
#define UNITY_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_ENTRY, UnityEntry))
#define UNITY_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_ENTRY, UnityEntryClass))
#define UNITY_IS_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_ENTRY))
#define UNITY_IS_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_ENTRY))
#define UNITY_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_ENTRY, UnityEntryClass))

typedef struct _UnityEntry UnityEntry;
typedef struct _UnityEntryClass UnityEntryClass;
typedef struct _UnityEntryPrivate UnityEntryPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

#define UNITY_TYPE_SHELL (unity_shell_get_type ())
#define UNITY_SHELL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_SHELL, UnityShell))
#define UNITY_IS_SHELL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_SHELL))
#define UNITY_SHELL_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_TYPE_SHELL, UnityShellIface))

typedef struct _UnityShell UnityShell;
typedef struct _UnityShellIface UnityShellIface;

#define UNITY_TYPE_SHELL_MODE (unity_shell_mode_get_type ())
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _UnityEntry {
	CtkText parent_instance;
	UnityEntryPrivate * priv;
};

struct _UnityEntryClass {
	CtkTextClass parent_class;
};

struct _UnityEntryPrivate {
	char* _static_text;
};

typedef enum  {
	UNITY_SHELL_MODE_UNDERLAY,
	UNITY_SHELL_MODE_OVERLAY
} UnityShellMode;

struct _UnityShellIface {
	GTypeInterface parent_iface;
	UnityShellMode (*get_mode) (UnityShell* self);
	ClutterStage* (*get_stage) (UnityShell* self);
	void (*show_unity) (UnityShell* self);
	gint (*get_indicators_width) (UnityShell* self);
	void (*ensure_input_region) (UnityShell* self);
	void (*add_fullscreen_request) (UnityShell* self, GObject* o);
	gboolean (*remove_fullscreen_request) (UnityShell* self, GObject* o);
	void (*grab_keyboard) (UnityShell* self, gboolean grab, guint32 timestamp);
	void (*show_window_picker) (UnityShell* self);
	void (*close_xids) (UnityShell* self, GArray* xids);
	void (*show_window) (UnityShell* self, guint32 xid);
	void (*expose_xids) (UnityShell* self, GArray* xids);
	void (*stop_expose) (UnityShell* self);
	gboolean (*get_menus_swallow_events) (UnityShell* self);
};


extern UnityShell* unity_global_shell;
static gpointer unity_entry_parent_class = NULL;

GType unity_entry_get_type (void);
#define UNITY_ENTRY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TYPE_ENTRY, UnityEntryPrivate))
enum  {
	UNITY_ENTRY_DUMMY_PROPERTY,
	UNITY_ENTRY_STATIC_TEXT
};
UnityEntry* unity_entry_new (const char* static_text);
UnityEntry* unity_entry_construct (GType object_type, const char* static_text);
static void unity_entry_on_key_focus_in (UnityEntry* self);
GType unity_shell_mode_get_type (void);
GType unity_shell_get_type (void);
void unity_shell_grab_keyboard (UnityShell* self, gboolean grab, guint32 timestamp);
static void unity_entry_on_key_focus_out (UnityEntry* self);
static void unity_entry_on_activate (UnityEntry* self);
static gboolean unity_entry_on_stage_captured_event (UnityEntry* self, ClutterEvent* event);
static gboolean _unity_entry_on_stage_captured_event_clutter_actor_captured_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static gboolean unity_entry_on_button_press_event (UnityEntry* self, ClutterEvent* event);
const char* unity_entry_get_static_text (UnityEntry* self);
void unity_entry_set_static_text (UnityEntry* self, const char* value);
static void _unity_entry_on_key_focus_in_clutter_actor_key_focus_in (ClutterActor* _sender, gpointer self);
static void _unity_entry_on_key_focus_out_clutter_actor_key_focus_out (ClutterActor* _sender, gpointer self);
static gboolean _unity_entry_on_button_press_event_clutter_actor_button_press_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static void _unity_entry_on_activate_clutter_text_activate (ClutterText* _sender, gpointer self);
static GObject * unity_entry_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_entry_finalize (GObject* obj);
static void unity_entry_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_entry_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static int _vala_strcmp0 (const char * str1, const char * str2);

static const ClutterColor UNITY_ENTRY_nofocus_color = {(guint8) 0x88, (guint8) 0x88, (guint8) 0x88, (guint8) 0xff};
static const ClutterColor UNITY_ENTRY_focus_color = {(guint8) 0x00, (guint8) 0x00, (guint8) 0x00, (guint8) 0xff};


UnityEntry* unity_entry_construct (GType object_type, const char* static_text) {
	UnityEntry * self;
	g_return_val_if_fail (static_text != NULL, NULL);
	self = (UnityEntry*) g_object_new (object_type, "static-text", static_text, NULL);
	return self;
}


UnityEntry* unity_entry_new (const char* static_text) {
	return unity_entry_construct (UNITY_TYPE_ENTRY, static_text);
}


static void unity_entry_on_key_focus_in (UnityEntry* self) {
	g_return_if_fail (self != NULL);
	if (_vala_strcmp0 (clutter_text_get_text ((ClutterText*) self), self->priv->_static_text) == 0) {
		ClutterColor _tmp0_;
		clutter_text_set_text ((ClutterText*) self, "");
		clutter_text_set_cursor_visible ((ClutterText*) self, TRUE);
		clutter_text_set_selection ((ClutterText*) self, (gssize) 0, (gssize) (-1));
		clutter_text_set_color ((ClutterText*) self, (_tmp0_ = UNITY_ENTRY_focus_color, &_tmp0_));
	}
}


static void unity_entry_on_key_focus_out (UnityEntry* self) {
	ClutterColor _tmp0_;
	g_return_if_fail (self != NULL);
	clutter_text_set_cursor_visible ((ClutterText*) self, FALSE);
	clutter_text_set_text ((ClutterText*) self, self->priv->_static_text);
	clutter_text_set_color ((ClutterText*) self, (_tmp0_ = UNITY_ENTRY_nofocus_color, &_tmp0_));
	;
	unity_shell_grab_keyboard (unity_global_shell, FALSE, clutter_get_current_event_time ());
}


static void unity_entry_on_activate (UnityEntry* self) {
	g_return_if_fail (self != NULL);
	unity_shell_grab_keyboard (unity_global_shell, FALSE, clutter_get_current_event_time ());
	clutter_ungrab_keyboard ();
}


static gboolean _unity_entry_on_stage_captured_event_clutter_actor_captured_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	return unity_entry_on_stage_captured_event (self, event);
}


static gboolean unity_entry_on_button_press_event (UnityEntry* self, ClutterEvent* event) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	unity_shell_grab_keyboard (unity_global_shell, TRUE, (*event).button.time);
	g_signal_connect_object (clutter_actor_get_stage ((ClutterActor*) self), "captured-event", (GCallback) _unity_entry_on_stage_captured_event_clutter_actor_captured_event, self, 0);
	result = FALSE;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gboolean unity_entry_on_stage_captured_event (UnityEntry* self, ClutterEvent* event) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	if ((*event).type == CLUTTER_BUTTON_PRESS) {
		ClutterActor* _tmp0_;
		ClutterStage* stage;
		ClutterActor* actor;
		stage = _g_object_ref0 ((_tmp0_ = clutter_actor_get_stage ((ClutterActor*) self), CLUTTER_IS_STAGE (_tmp0_) ? ((ClutterStage*) _tmp0_) : NULL));
		actor = _g_object_ref0 (clutter_stage_get_actor_at_pos (stage, CLUTTER_PICK_REACTIVE, (gint) (*event).button.x, (gint) (*event).button.y));
		if (actor != CLUTTER_ACTOR (self)) {
			guint _tmp1_;
			unity_shell_grab_keyboard (unity_global_shell, FALSE, (*event).button.time);
			g_signal_parse_name ("captured-event", CLUTTER_TYPE_ACTOR, &_tmp1_, NULL, FALSE);
			g_signal_handlers_disconnect_matched ((ClutterActor*) stage, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp1_, 0, NULL, (GCallback) _unity_entry_on_stage_captured_event_clutter_actor_captured_event, self);
			clutter_ungrab_keyboard ();
		}
		_g_object_unref0 (stage);
		_g_object_unref0 (actor);
	}
	result = FALSE;
	return result;
}


const char* unity_entry_get_static_text (UnityEntry* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_static_text;
	return result;
}


void unity_entry_set_static_text (UnityEntry* self, const char* value) {
	char* _tmp0_;
	ClutterColor _tmp1_;
	g_return_if_fail (self != NULL);
	self->priv->_static_text = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_static_text), _tmp0_);
	clutter_text_set_color ((ClutterText*) self, (_tmp1_ = UNITY_ENTRY_nofocus_color, &_tmp1_));
	clutter_text_set_text ((ClutterText*) self, self->priv->_static_text);
	g_object_notify ((GObject *) self, "static-text");
}


static void _unity_entry_on_key_focus_in_clutter_actor_key_focus_in (ClutterActor* _sender, gpointer self) {
	unity_entry_on_key_focus_in (self);
}


static void _unity_entry_on_key_focus_out_clutter_actor_key_focus_out (ClutterActor* _sender, gpointer self) {
	unity_entry_on_key_focus_out (self);
}


static gboolean _unity_entry_on_button_press_event_clutter_actor_button_press_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	return unity_entry_on_button_press_event (self, event);
}


static void _unity_entry_on_activate_clutter_text_activate (ClutterText* _sender, gpointer self) {
	unity_entry_on_activate (self);
}


static GObject * unity_entry_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityEntry * self;
	parent_class = G_OBJECT_CLASS (unity_entry_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_ENTRY (obj);
	{
		ClutterColor _tmp0_ = {0};
		ClutterColor _tmp1_;
		ClutterColor _tmp2_ = {0};
		ClutterColor _tmp3_;
		ClutterColor _tmp4_;
		clutter_actor_set_reactive ((ClutterActor*) self, TRUE);
		clutter_text_set_editable ((ClutterText*) self, TRUE);
		clutter_text_set_selectable ((ClutterText*) self, TRUE);
		clutter_text_set_activatable ((ClutterText*) self, TRUE);
		clutter_text_set_single_line_mode ((ClutterText*) self, TRUE);
		clutter_text_set_cursor_visible ((ClutterText*) self, FALSE);
		clutter_text_set_cursor_color ((ClutterText*) self, (_tmp1_ = (_tmp0_.red = (guint8) 0x22, _tmp0_.green = (guint8) 0x22, _tmp0_.blue = (guint8) 0x22, _tmp0_.alpha = (guint8) 0xff, _tmp0_), &_tmp1_));
		clutter_text_set_selection_color ((ClutterText*) self, (_tmp3_ = (_tmp2_.red = (guint8) 0x4d, _tmp2_.green = (guint8) 0x4d, _tmp2_.blue = (guint8) 0x4d, _tmp2_.alpha = (guint8) 0xff, _tmp2_), &_tmp3_));
		clutter_text_set_color ((ClutterText*) self, (_tmp4_ = UNITY_ENTRY_nofocus_color, &_tmp4_));
		g_signal_connect_object ((ClutterActor*) self, "key-focus-in", (GCallback) _unity_entry_on_key_focus_in_clutter_actor_key_focus_in, self, 0);
		g_signal_connect_object ((ClutterActor*) self, "key-focus-out", (GCallback) _unity_entry_on_key_focus_out_clutter_actor_key_focus_out, self, 0);
		g_signal_connect_object ((ClutterActor*) self, "button-press-event", (GCallback) _unity_entry_on_button_press_event_clutter_actor_button_press_event, self, 0);
		g_signal_connect_object ((ClutterText*) self, "activate", (GCallback) _unity_entry_on_activate_clutter_text_activate, self, 0);
		clutter_actor_queue_redraw ((ClutterActor*) self);
	}
	return obj;
}


static void unity_entry_class_init (UnityEntryClass * klass) {
	unity_entry_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityEntryPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_entry_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_entry_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_entry_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_entry_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_ENTRY_STATIC_TEXT, g_param_spec_string ("static-text", "static-text", "static-text", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT));
}


static void unity_entry_instance_init (UnityEntry * self) {
	self->priv = UNITY_ENTRY_GET_PRIVATE (self);
}


static void unity_entry_finalize (GObject* obj) {
	UnityEntry * self;
	self = UNITY_ENTRY (obj);
	_g_free0 (self->priv->_static_text);
	G_OBJECT_CLASS (unity_entry_parent_class)->finalize (obj);
}


GType unity_entry_get_type (void) {
	static volatile gsize unity_entry_type_id__volatile = 0;
	if (g_once_init_enter (&unity_entry_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityEntryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_entry_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityEntry), 0, (GInstanceInitFunc) unity_entry_instance_init, NULL };
		GType unity_entry_type_id;
		unity_entry_type_id = g_type_register_static (CTK_TYPE_TEXT, "UnityEntry", &g_define_type_info, 0);
		g_once_init_leave (&unity_entry_type_id__volatile, unity_entry_type_id);
	}
	return unity_entry_type_id__volatile;
}


static void unity_entry_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityEntry * self;
	self = UNITY_ENTRY (object);
	switch (property_id) {
		case UNITY_ENTRY_STATIC_TEXT:
		g_value_set_string (value, unity_entry_get_static_text (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_entry_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityEntry * self;
	self = UNITY_ENTRY (object);
	switch (property_id) {
		case UNITY_ENTRY_STATIC_TEXT:
		unity_entry_set_static_text (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
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




