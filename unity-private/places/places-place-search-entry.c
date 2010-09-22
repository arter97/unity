/* places-place-search-entry.c generated by valac 0.9.8, the Vala compiler
 * generated from places-place-search-entry.vala, do not modify */

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
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gi18n-lib.h>
#include <config.h>
#include <clutter/clutter.h>
#include <gee.h>
#include <dee.h>
#include <cairo.h>


#define UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY (unity_places_place_search_entry_get_type ())
#define UNITY_PLACES_PLACE_SEARCH_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY, UnityPlacesPlaceSearchEntry))
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY, UnityPlacesPlaceSearchEntryClass))
#define UNITY_PLACES_IS_PLACE_SEARCH_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY))
#define UNITY_PLACES_IS_PLACE_SEARCH_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY))
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY, UnityPlacesPlaceSearchEntryClass))

typedef struct _UnityPlacesPlaceSearchEntry UnityPlacesPlaceSearchEntry;
typedef struct _UnityPlacesPlaceSearchEntryClass UnityPlacesPlaceSearchEntryClass;
typedef struct _UnityPlacesPlaceSearchEntryPrivate UnityPlacesPlaceSearchEntryPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

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

#define UNITY_PLACES_TYPE_PLACE_HOME_ENTRY (unity_places_place_home_entry_get_type ())
#define UNITY_PLACES_PLACE_HOME_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_HOME_ENTRY, UnityPlacesPlaceHomeEntry))
#define UNITY_PLACES_PLACE_HOME_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_HOME_ENTRY, UnityPlacesPlaceHomeEntryClass))
#define UNITY_PLACES_IS_PLACE_HOME_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_HOME_ENTRY))
#define UNITY_PLACES_IS_PLACE_HOME_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_HOME_ENTRY))
#define UNITY_PLACES_PLACE_HOME_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_HOME_ENTRY, UnityPlacesPlaceHomeEntryClass))

typedef struct _UnityPlacesPlaceHomeEntry UnityPlacesPlaceHomeEntry;
typedef struct _UnityPlacesPlaceHomeEntryClass UnityPlacesPlaceHomeEntryClass;

struct _UnityPlacesPlaceSearchEntry {
	CtkBox parent_instance;
	UnityPlacesPlaceSearchEntryPrivate * priv;
	CtkImage* left_icon;
	CtkText* hint_text;
	CtkText* text;
	UnityCairoCanvas* right_icon;
};

struct _UnityPlacesPlaceSearchEntryClass {
	CtkBoxClass parent_class;
};

struct _UnityPlacesPlaceSearchEntryPrivate {
	guint _cursor_blink_count;
	gboolean upward;
	float _cursor_opacity;
	guint live_search_timeout;
	char* _static_text;
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


static gpointer unity_places_place_search_entry_parent_class = NULL;

GType unity_places_place_search_entry_get_type (void) G_GNUC_CONST;
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY, UnityPlacesPlaceSearchEntryPrivate))
enum  {
	UNITY_PLACES_PLACE_SEARCH_ENTRY_DUMMY_PROPERTY,
	UNITY_PLACES_PLACE_SEARCH_ENTRY_CURSOR_OPACITY
};
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_SEARCH_ICON_FILE PKGDATADIR "/search_icon.png"
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_SPACING 3
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_PADDING 1.0f
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_LIVE_SEARCH_TIMEOUT 200
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_CURSOR_BLINK_TIMEOUT 1000
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_CLEAR_SIZE 18.0f
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_MAX_CURSOR_BLINK ((guint) 30)
UnityPlacesPlaceSearchEntry* unity_places_place_search_entry_new (void);
UnityPlacesPlaceSearchEntry* unity_places_place_search_entry_construct (GType object_type);
static void unity_places_place_search_entry_real_get_preferred_height (ClutterActor* base, float for_width, float* min_height, float* nat_height);
static void unity_places_place_search_entry_real_get_preferred_width (ClutterActor* base, float for_height, float* min_width, float* nat_width);
static void unity_places_place_search_entry_on_text_changed (UnityPlacesPlaceSearchEntry* self);
static gboolean _lambda39_ (UnityPlacesPlaceSearchEntry* self);
static gboolean __lambda39__gsource_func (gpointer self);
static void unity_places_place_search_entry_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
static void unity_places_place_search_entry_real_paint (ClutterActor* base);
static void unity_places_place_search_entry_real_map (ClutterActor* base);
static void unity_places_place_search_entry_real_unmap (ClutterActor* base);
static void unity_places_place_search_entry_on_key_focus_in (UnityPlacesPlaceSearchEntry* self);
static void unity_places_place_search_entry_on_key_focus_out (UnityPlacesPlaceSearchEntry* self);
void unity_places_place_search_entry_reset (UnityPlacesPlaceSearchEntry* self);
GType unity_places_place_get_type (void) G_GNUC_CONST;
GType unity_places_place_entry_get_type (void) G_GNUC_CONST;
void unity_places_place_search_entry_set_active_entry (UnityPlacesPlaceSearchEntry* self, UnityPlacesPlaceEntry* entry);
GType unity_places_place_home_entry_get_type (void) G_GNUC_CONST;
const char* unity_places_place_entry_get_name (UnityPlacesPlaceEntry* self);
static void unity_places_place_search_entry_paint_right_icon (UnityPlacesPlaceSearchEntry* self, cairo_t* cr, gint width, gint height);
float unity_places_place_search_entry_get_cursor_opacity (UnityPlacesPlaceSearchEntry* self);
void unity_places_place_search_entry_set_cursor_opacity (UnityPlacesPlaceSearchEntry* self, float value);
static void _unity_places_place_search_entry_on_text_changed_clutter_text_text_changed (ClutterText* _sender, gpointer self);
static void _unity_places_place_search_entry_on_key_focus_in_clutter_actor_key_focus_in (ClutterActor* _sender, gpointer self);
static void _unity_places_place_search_entry_on_key_focus_out_clutter_actor_key_focus_out (ClutterActor* _sender, gpointer self);
static void _unity_places_place_search_entry_paint_right_icon_unity_cairo_canvas_cairo_canvas_paint (cairo_t* cr, gint width, gint height, gpointer self);
static gboolean _lambda40_ (UnityPlacesPlaceSearchEntry* self);
static gboolean __lambda40__clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static GObject * unity_places_place_search_entry_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_place_search_entry_finalize (GObject* obj);
static void unity_places_place_search_entry_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_place_search_entry_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static int _vala_strcmp0 (const char * str1, const char * str2);

static const ClutterColor UNITY_PLACES_PLACE_SEARCH_ENTRY_nofocus_color = {(guint8) 0xff, (guint8) 0xff, (guint8) 0xff, (guint8) 0xbb};
static const ClutterColor UNITY_PLACES_PLACE_SEARCH_ENTRY_focus_color = {(guint8) 0xff, (guint8) 0xff, (guint8) 0xff, (guint8) 0xff};


UnityPlacesPlaceSearchEntry* unity_places_place_search_entry_construct (GType object_type) {
	UnityPlacesPlaceSearchEntry * self;
	self = (UnityPlacesPlaceSearchEntry*) g_object_new (object_type, "orientation", CTK_ORIENTATION_HORIZONTAL, "homogeneous", FALSE, "spacing", 0, NULL);
	return self;
}


UnityPlacesPlaceSearchEntry* unity_places_place_search_entry_new (void) {
	return unity_places_place_search_entry_construct (UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY);
}


static void unity_places_place_search_entry_real_get_preferred_height (ClutterActor* base, float for_width, float* min_height, float* nat_height) {
	UnityPlacesPlaceSearchEntry * self;
	float mheight = 0.0F;
	float nheight = 0.0F;
	float _tmp0_ = 0.0F;
	self = (UnityPlacesPlaceSearchEntry*) base;
	clutter_actor_get_preferred_height ((ClutterActor*) self->text, (float) 400, &mheight, &nheight);
	if (mheight > 20.0f) {
		_tmp0_ = mheight;
	} else {
		_tmp0_ = 20.0f;
	}
	*min_height = _tmp0_;
	*min_height = (*min_height) + (UNITY_PLACES_PLACE_SEARCH_ENTRY_PADDING * 2);
	*nat_height = *min_height;
}


static void unity_places_place_search_entry_real_get_preferred_width (ClutterActor* base, float for_height, float* min_width, float* nat_width) {
	UnityPlacesPlaceSearchEntry * self;
	self = (UnityPlacesPlaceSearchEntry*) base;
	*min_width = 270.0f;
	*nat_width = 270.0f;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gboolean _lambda39_ (UnityPlacesPlaceSearchEntry* self) {
	gboolean result = FALSE;
	g_signal_emit_by_name (self, "text-changed", clutter_text_get_text ((ClutterText*) self->text));
	self->priv->live_search_timeout = (guint) 0;
	result = FALSE;
	return result;
}


static gboolean __lambda39__gsource_func (gpointer self) {
	gboolean result;
	result = _lambda39_ (self);
	return result;
}


static void unity_places_place_search_entry_on_text_changed (UnityPlacesPlaceSearchEntry* self) {
	gint _tmp0_ = 0;
	gboolean _tmp1_ = FALSE;
	g_return_if_fail (self != NULL);
	if (_vala_strcmp0 (clutter_text_get_text ((ClutterText*) self->text), "") == 0) {
		_tmp0_ = 255;
	} else {
		_tmp0_ = 0;
	}
	clutter_actor_animate ((ClutterActor*) self->hint_text, (gulong) CLUTTER_EASE_OUT_QUAD, (guint) 100, "opacity", _tmp0_, NULL);
	if (clutter_text_get_cursor_visible ((ClutterText*) self->text) == TRUE) {
		_tmp1_ = self->priv->_cursor_blink_count == 0;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		ClutterAnimation* anim;
		anim = _g_object_ref0 (clutter_actor_animate ((ClutterActor*) self, (gulong) CLUTTER_EASE_IN_OUT_QUAD, (guint) UNITY_PLACES_PLACE_SEARCH_ENTRY_CURSOR_BLINK_TIMEOUT, "cursor-opacity", 1.0, NULL));
		clutter_animation_set_loop (anim, TRUE);
		_g_object_unref0 (anim);
	}
	self->priv->_cursor_blink_count = (guint) 0;
	if (self->priv->live_search_timeout != 0) {
		g_source_remove (self->priv->live_search_timeout);
	}
	self->priv->live_search_timeout = g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) UNITY_PLACES_PLACE_SEARCH_ENTRY_LIVE_SEARCH_TIMEOUT, __lambda39__gsource_func, g_object_ref (self), g_object_unref);
}


static void unity_places_place_search_entry_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
	UnityPlacesPlaceSearchEntry * self;
	ClutterActorBox child_box = {0};
	self = (UnityPlacesPlaceSearchEntry*) base;
	CLUTTER_ACTOR_CLASS (unity_places_place_search_entry_parent_class)->allocate ((ClutterActor*) CTK_BOX (self), box, flags);
	memset (&child_box, 0, sizeof (ClutterActorBox));
	child_box.x1 = clutter_actor_get_x ((ClutterActor*) self->text) + (UNITY_PLACES_PLACE_SEARCH_ENTRY_SPACING * 2);
	child_box.x2 = clutter_actor_get_x ((ClutterActor*) self->text) + clutter_actor_get_width ((ClutterActor*) self->text);
	child_box.y1 = clutter_actor_get_y ((ClutterActor*) self->text);
	child_box.y2 = clutter_actor_get_y ((ClutterActor*) self->text) + clutter_actor_get_height ((ClutterActor*) self->text);
	clutter_actor_allocate ((ClutterActor*) self->hint_text, &child_box, flags);
	child_box.x1 = ((*box).x2 - (*box).x1) - UNITY_PLACES_PLACE_SEARCH_ENTRY_CLEAR_SIZE;
	child_box.x2 = child_box.x1 + UNITY_PLACES_PLACE_SEARCH_ENTRY_CLEAR_SIZE;
	child_box.y1 = (((*box).y2 - (*box).y1) / 2.0f) - (UNITY_PLACES_PLACE_SEARCH_ENTRY_CLEAR_SIZE / 2.0f);
	child_box.y2 = child_box.y1 + UNITY_PLACES_PLACE_SEARCH_ENTRY_CLEAR_SIZE;
	clutter_actor_allocate ((ClutterActor*) self->right_icon, &child_box, flags);
}


static void unity_places_place_search_entry_real_paint (ClutterActor* base) {
	UnityPlacesPlaceSearchEntry * self;
	self = (UnityPlacesPlaceSearchEntry*) base;
	clutter_actor_paint ((ClutterActor*) self->hint_text);
	CLUTTER_ACTOR_CLASS (unity_places_place_search_entry_parent_class)->paint ((ClutterActor*) CTK_BOX (self));
}


static void unity_places_place_search_entry_real_map (ClutterActor* base) {
	UnityPlacesPlaceSearchEntry * self;
	self = (UnityPlacesPlaceSearchEntry*) base;
	CLUTTER_ACTOR_CLASS (unity_places_place_search_entry_parent_class)->map ((ClutterActor*) CTK_BOX (self));
	clutter_actor_map ((ClutterActor*) self->hint_text);
}


static void unity_places_place_search_entry_real_unmap (ClutterActor* base) {
	UnityPlacesPlaceSearchEntry * self;
	self = (UnityPlacesPlaceSearchEntry*) base;
	CLUTTER_ACTOR_CLASS (unity_places_place_search_entry_parent_class)->unmap ((ClutterActor*) CTK_BOX (self));
	clutter_actor_unmap ((ClutterActor*) self->hint_text);
}


static void unity_places_place_search_entry_on_key_focus_in (UnityPlacesPlaceSearchEntry* self) {
	ClutterColor _tmp0_ = {0};
	ClutterColor _tmp1_;
	ClutterAnimation* anim;
	g_return_if_fail (self != NULL);
	clutter_text_set_cursor_color ((ClutterText*) self->text, (_tmp1_ = (_tmp0_.red = (guint8) 255, _tmp0_.green = (guint8) 255, _tmp0_.blue = (guint8) 255, _tmp0_.alpha = (guint8) 0, _tmp0_), &_tmp1_));
	self->priv->_cursor_opacity = 0.0f;
	anim = _g_object_ref0 (clutter_actor_animate ((ClutterActor*) self, (gulong) CLUTTER_EASE_IN_OUT_QUAD, (guint) UNITY_PLACES_PLACE_SEARCH_ENTRY_CURSOR_BLINK_TIMEOUT, "cursor-opacity", 1.0, NULL));
	clutter_animation_set_loop (anim, TRUE);
	clutter_text_set_cursor_visible ((ClutterText*) self->text, TRUE);
	_g_object_unref0 (anim);
}


static void unity_places_place_search_entry_on_key_focus_out (UnityPlacesPlaceSearchEntry* self) {
	g_return_if_fail (self != NULL);
	clutter_animation_set_loop (clutter_actor_get_animation ((ClutterActor*) self), FALSE);
	clutter_animation_completed (clutter_actor_get_animation ((ClutterActor*) self));
	clutter_text_set_cursor_visible ((ClutterText*) self->text, FALSE);
}


void unity_places_place_search_entry_reset (UnityPlacesPlaceSearchEntry* self) {
	g_return_if_fail (self != NULL);
	clutter_text_set_cursor_visible ((ClutterText*) self->text, FALSE);
	clutter_text_set_text ((ClutterText*) self->text, "");
}


void unity_places_place_search_entry_set_active_entry (UnityPlacesPlaceSearchEntry* self, UnityPlacesPlaceEntry* entry) {
	char* name;
	char* _tmp1_;
	char* _tmp2_;
	char* _tmp3_;
	char* _tmp4_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (entry != NULL);
	name = g_strdup ("");
	if (UNITY_PLACES_IS_PLACE_HOME_ENTRY (entry) == FALSE) {
		char* _tmp0_;
		name = (_tmp0_ = g_strdup (unity_places_place_entry_get_name (entry)), _g_free0 (name), _tmp0_);
	}
	clutter_text_set_markup ((ClutterText*) self->hint_text, _tmp4_ = g_strconcat (_tmp3_ = g_strconcat ("<i>", _tmp2_ = g_markup_escape_text (_tmp1_ = g_strdup_printf (self->priv->_static_text, name), -1), NULL), "</i>", NULL));
	_g_free0 (_tmp4_);
	_g_free0 (_tmp3_);
	_g_free0 (_tmp2_);
	_g_free0 (_tmp1_);
	_g_free0 (name);
}


static void unity_places_place_search_entry_paint_right_icon (UnityPlacesPlaceSearchEntry* self, cairo_t* cr, gint width, gint height) {
	gint padding;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cr != NULL);
	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	cairo_paint (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
	cairo_set_line_width (cr, 3.0);
	cairo_set_source_rgba (cr, 1.0, 1.0, 1.0, 1.0);
	padding = 5;
	cairo_move_to (cr, (double) padding, (double) padding);
	cairo_line_to (cr, (double) (width - padding), (double) (height - padding));
	cairo_move_to (cr, (double) (width - padding), (double) padding);
	cairo_line_to (cr, (double) padding, (double) (height - padding));
	cairo_stroke (cr);
}


float unity_places_place_search_entry_get_cursor_opacity (UnityPlacesPlaceSearchEntry* self) {
	float result;
	g_return_val_if_fail (self != NULL, 0.0F);
	result = self->priv->_cursor_opacity;
	return result;
}


void unity_places_place_search_entry_set_cursor_opacity (UnityPlacesPlaceSearchEntry* self, float value) {
	g_return_if_fail (self != NULL);
	if (self->priv->_cursor_opacity != value) {
		float _tmp0_ = 0.0F;
		float factor;
		ClutterColor _tmp1_ = {0};
		ClutterColor _tmp2_;
		gboolean _tmp3_ = FALSE;
		self->priv->_cursor_opacity = value;
		if (self->priv->upward) {
			_tmp0_ = self->priv->_cursor_opacity;
		} else {
			_tmp0_ = 1.0f - self->priv->_cursor_opacity;
		}
		factor = _tmp0_;
		clutter_text_set_cursor_color ((ClutterText*) self->text, (_tmp2_ = (_tmp1_.red = (guint8) 255, _tmp1_.green = (guint8) 255, _tmp1_.blue = (guint8) 255, _tmp1_.alpha = (guint8) (255 * factor), _tmp1_), &_tmp2_));
		if (self->priv->upward) {
			_tmp3_ = self->priv->_cursor_opacity == 1.0f;
		} else {
			_tmp3_ = FALSE;
		}
		if (_tmp3_) {
			self->priv->upward = FALSE;
			self->priv->_cursor_blink_count++;
		} else {
			gboolean _tmp4_ = FALSE;
			if (self->priv->upward == FALSE) {
				_tmp4_ = self->priv->_cursor_opacity == 1.0f;
			} else {
				_tmp4_ = FALSE;
			}
			if (_tmp4_) {
				self->priv->upward = TRUE;
				self->priv->_cursor_blink_count++;
			}
		}
		if (self->priv->_cursor_blink_count == UNITY_PLACES_PLACE_SEARCH_ENTRY_MAX_CURSOR_BLINK) {
			ClutterColor _tmp5_ = {0};
			ClutterColor _tmp6_;
			clutter_animation_set_loop (clutter_actor_get_animation ((ClutterActor*) self), FALSE);
			clutter_animation_completed (clutter_actor_get_animation ((ClutterActor*) self));
			self->priv->_cursor_blink_count = (guint) 0;
			clutter_text_set_cursor_color ((ClutterText*) self->text, (_tmp6_ = (_tmp5_.red = (guint8) 255, _tmp5_.green = (guint8) 255, _tmp5_.blue = (guint8) 255, _tmp5_.alpha = (guint8) 255, _tmp5_), &_tmp6_));
			self->priv->_cursor_opacity = 0.0f;
		}
	}
	g_object_notify ((GObject *) self, "cursor-opacity");
}


static void _unity_places_place_search_entry_on_text_changed_clutter_text_text_changed (ClutterText* _sender, gpointer self) {
	unity_places_place_search_entry_on_text_changed (self);
}


static void _unity_places_place_search_entry_on_key_focus_in_clutter_actor_key_focus_in (ClutterActor* _sender, gpointer self) {
	unity_places_place_search_entry_on_key_focus_in (self);
}


static void _unity_places_place_search_entry_on_key_focus_out_clutter_actor_key_focus_out (ClutterActor* _sender, gpointer self) {
	unity_places_place_search_entry_on_key_focus_out (self);
}


static void _unity_places_place_search_entry_paint_right_icon_unity_cairo_canvas_cairo_canvas_paint (cairo_t* cr, gint width, gint height, gpointer self) {
	unity_places_place_search_entry_paint_right_icon (self, cr, width, height);
}


static gboolean _lambda40_ (UnityPlacesPlaceSearchEntry* self) {
	gboolean result = FALSE;
	clutter_text_set_text ((ClutterText*) self->text, "");
	g_signal_emit_by_name (self, "text-changed", "");
	result = TRUE;
	return result;
}


static gboolean __lambda40__clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = _lambda40_ (self);
	return result;
}


static GObject * unity_places_place_search_entry_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesPlaceSearchEntry * self;
	parent_class = G_OBJECT_CLASS (unity_places_place_search_entry_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_PLACE_SEARCH_ENTRY (obj);
	{
		CtkPadding _tmp0_ = {0};
		CtkPadding _tmp1_;
		CtkImage* _tmp2_;
		char* _tmp3_;
		CtkText* _tmp4_;
		ClutterColor _tmp5_;
		CtkText* _tmp6_;
		ClutterColor _tmp7_;
		UnityCairoCanvas* _tmp8_;
		ctk_actor_set_padding ((CtkActor*) self, (_tmp1_ = (_tmp0_.top = UNITY_PLACES_PLACE_SEARCH_ENTRY_PADDING, _tmp0_.right = UNITY_PLACES_PLACE_SEARCH_ENTRY_PADDING * 4, _tmp0_.bottom = UNITY_PLACES_PLACE_SEARCH_ENTRY_PADDING, _tmp0_.left = UNITY_PLACES_PLACE_SEARCH_ENTRY_PADDING * 4, _tmp0_), &_tmp1_));
		self->left_icon = (_tmp2_ = g_object_ref_sink ((CtkImage*) ctk_image_new_from_filename ((guint) 18, UNITY_PLACES_PLACE_SEARCH_ENTRY_SEARCH_ICON_FILE)), _g_object_unref0 (self->left_icon), _tmp2_);
		ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->left_icon, FALSE, TRUE);
		clutter_actor_show ((ClutterActor*) self->left_icon);
		self->hint_text = (_tmp4_ = g_object_ref_sink ((CtkText*) ctk_text_new (_tmp3_ = g_strdup_printf (self->priv->_static_text, ""))), _g_object_unref0 (self->hint_text), _tmp4_);
		_g_free0 (_tmp3_);
		clutter_actor_set_reactive ((ClutterActor*) self->hint_text, FALSE);
		clutter_text_set_selectable ((ClutterText*) self->hint_text, FALSE);
		clutter_text_set_editable ((ClutterText*) self->hint_text, FALSE);
		clutter_text_set_activatable ((ClutterText*) self->hint_text, FALSE);
		clutter_text_set_single_line_mode ((ClutterText*) self->hint_text, TRUE);
		clutter_text_set_cursor_visible ((ClutterText*) self->hint_text, FALSE);
		clutter_text_set_color ((ClutterText*) self->hint_text, (_tmp5_ = UNITY_PLACES_PLACE_SEARCH_ENTRY_nofocus_color, &_tmp5_));
		clutter_actor_set_parent ((ClutterActor*) self->hint_text, (ClutterActor*) self);
		self->text = (_tmp6_ = g_object_ref_sink ((CtkText*) ctk_text_new ("")), _g_object_unref0 (self->text), _tmp6_);
		clutter_actor_set_reactive ((ClutterActor*) self->text, TRUE);
		clutter_text_set_selectable ((ClutterText*) self->text, TRUE);
		clutter_text_set_editable ((ClutterText*) self->text, TRUE);
		clutter_text_set_activatable ((ClutterText*) self->text, TRUE);
		clutter_text_set_single_line_mode ((ClutterText*) self->text, TRUE);
		clutter_text_set_cursor_visible ((ClutterText*) self->text, FALSE);
		clutter_text_set_color ((ClutterText*) self->text, (_tmp7_ = UNITY_PLACES_PLACE_SEARCH_ENTRY_focus_color, &_tmp7_));
		ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->text, TRUE, TRUE);
		clutter_actor_show ((ClutterActor*) self->text);
		g_signal_connect_object ((ClutterText*) self->text, "text-changed", (GCallback) _unity_places_place_search_entry_on_text_changed_clutter_text_text_changed, self, 0);
		g_signal_connect_object ((ClutterActor*) self->text, "key-focus-in", (GCallback) _unity_places_place_search_entry_on_key_focus_in_clutter_actor_key_focus_in, self, 0);
		g_signal_connect_object ((ClutterActor*) self->text, "key-focus-out", (GCallback) _unity_places_place_search_entry_on_key_focus_out_clutter_actor_key_focus_out, self, 0);
		self->right_icon = (_tmp8_ = g_object_ref_sink (unity_cairo_canvas_new (_unity_places_place_search_entry_paint_right_icon_unity_cairo_canvas_cairo_canvas_paint, self)), _g_object_unref0 (self->right_icon), _tmp8_);
		ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->right_icon, FALSE, TRUE);
		clutter_actor_show ((ClutterActor*) self->right_icon);
		clutter_actor_set_reactive ((ClutterActor*) self->right_icon, TRUE);
		g_signal_connect_object ((ClutterActor*) self->right_icon, "button-release-event", (GCallback) __lambda40__clutter_actor_button_release_event, self, 0);
	}
	return obj;
}


static void unity_places_place_search_entry_class_init (UnityPlacesPlaceSearchEntryClass * klass) {
	unity_places_place_search_entry_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesPlaceSearchEntryPrivate));
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_height = unity_places_place_search_entry_real_get_preferred_height;
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_width = unity_places_place_search_entry_real_get_preferred_width;
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_places_place_search_entry_real_allocate;
	CLUTTER_ACTOR_CLASS (klass)->paint = unity_places_place_search_entry_real_paint;
	CLUTTER_ACTOR_CLASS (klass)->map = unity_places_place_search_entry_real_map;
	CLUTTER_ACTOR_CLASS (klass)->unmap = unity_places_place_search_entry_real_unmap;
	G_OBJECT_CLASS (klass)->get_property = unity_places_place_search_entry_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_place_search_entry_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_places_place_search_entry_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_place_search_entry_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_SEARCH_ENTRY_CURSOR_OPACITY, g_param_spec_float ("cursor-opacity", "cursor-opacity", "cursor-opacity", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_signal_new ("text_changed", UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, 1, G_TYPE_STRING);
}


static void unity_places_place_search_entry_instance_init (UnityPlacesPlaceSearchEntry * self) {
	self->priv = UNITY_PLACES_PLACE_SEARCH_ENTRY_GET_PRIVATE (self);
	self->priv->_cursor_blink_count = (guint) 0;
	self->priv->upward = TRUE;
	self->priv->_cursor_opacity = 0.0f;
	self->priv->live_search_timeout = (guint) 0;
	self->priv->_static_text = g_strdup (_ ("Search %s"));
}


static void unity_places_place_search_entry_finalize (GObject* obj) {
	UnityPlacesPlaceSearchEntry * self;
	self = UNITY_PLACES_PLACE_SEARCH_ENTRY (obj);
	{
		clutter_actor_unparent ((ClutterActor*) self->hint_text);
	}
	_g_object_unref0 (self->left_icon);
	_g_object_unref0 (self->hint_text);
	_g_object_unref0 (self->text);
	_g_object_unref0 (self->right_icon);
	_g_free0 (self->priv->_static_text);
	G_OBJECT_CLASS (unity_places_place_search_entry_parent_class)->finalize (obj);
}


GType unity_places_place_search_entry_get_type (void) {
	static volatile gsize unity_places_place_search_entry_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_place_search_entry_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesPlaceSearchEntryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_place_search_entry_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesPlaceSearchEntry), 0, (GInstanceInitFunc) unity_places_place_search_entry_instance_init, NULL };
		GType unity_places_place_search_entry_type_id;
		unity_places_place_search_entry_type_id = g_type_register_static (CTK_TYPE_BOX, "UnityPlacesPlaceSearchEntry", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_place_search_entry_type_id__volatile, unity_places_place_search_entry_type_id);
	}
	return unity_places_place_search_entry_type_id__volatile;
}


static void unity_places_place_search_entry_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesPlaceSearchEntry * self;
	self = UNITY_PLACES_PLACE_SEARCH_ENTRY (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_SEARCH_ENTRY_CURSOR_OPACITY:
		g_value_set_float (value, unity_places_place_search_entry_get_cursor_opacity (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_place_search_entry_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesPlaceSearchEntry * self;
	self = UNITY_PLACES_PLACE_SEARCH_ENTRY (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_SEARCH_ENTRY_CURSOR_OPACITY:
		unity_places_place_search_entry_set_cursor_opacity (self, g_value_get_float (value));
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




