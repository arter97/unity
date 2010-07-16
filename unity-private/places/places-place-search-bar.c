/* places-place-search-bar.c generated by valac, the Vala compiler
 * generated from places-place-search-bar.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <dee.h>
#include <clutter/clutter.h>
#include <unity.h>
#include <float.h>
#include <math.h>
#include <gdk-pixbuf/gdk-pixdata.h>
#include <cairo.h>
#include <gdk/gdk.h>


#define UNITY_PLACES_TYPE_PLACE_SEARCH_BAR (unity_places_place_search_bar_get_type ())
#define UNITY_PLACES_PLACE_SEARCH_BAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR, UnityPlacesPlaceSearchBar))
#define UNITY_PLACES_PLACE_SEARCH_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR, UnityPlacesPlaceSearchBarClass))
#define UNITY_PLACES_IS_PLACE_SEARCH_BAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR))
#define UNITY_PLACES_IS_PLACE_SEARCH_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR))
#define UNITY_PLACES_PLACE_SEARCH_BAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR, UnityPlacesPlaceSearchBarClass))

typedef struct _UnityPlacesPlaceSearchBar UnityPlacesPlaceSearchBar;
typedef struct _UnityPlacesPlaceSearchBarClass UnityPlacesPlaceSearchBarClass;
typedef struct _UnityPlacesPlaceSearchBarPrivate UnityPlacesPlaceSearchBarPrivate;

#define UNITY_PLACES_TYPE_PLACE_ENTRY (unity_places_place_entry_get_type ())
#define UNITY_PLACES_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntry))
#define UNITY_PLACES_IS_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY))
#define UNITY_PLACES_PLACE_ENTRY_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntryIface))

typedef struct _UnityPlacesPlaceEntry UnityPlacesPlaceEntry;
typedef struct _UnityPlacesPlaceEntryIface UnityPlacesPlaceEntryIface;

#define UNITY_PLACES_TYPE_PLACE_SEARCH_BAR_BACKGROUND (unity_places_place_search_bar_background_get_type ())
#define UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR_BACKGROUND, UnityPlacesPlaceSearchBarBackground))
#define UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR_BACKGROUND, UnityPlacesPlaceSearchBarBackgroundClass))
#define UNITY_PLACES_IS_PLACE_SEARCH_BAR_BACKGROUND(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR_BACKGROUND))
#define UNITY_PLACES_IS_PLACE_SEARCH_BAR_BACKGROUND_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR_BACKGROUND))
#define UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR_BACKGROUND, UnityPlacesPlaceSearchBarBackgroundClass))

typedef struct _UnityPlacesPlaceSearchBarBackground UnityPlacesPlaceSearchBarBackground;
typedef struct _UnityPlacesPlaceSearchBarBackgroundClass UnityPlacesPlaceSearchBarBackgroundClass;

#define UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY (unity_places_place_search_entry_get_type ())
#define UNITY_PLACES_PLACE_SEARCH_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY, UnityPlacesPlaceSearchEntry))
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY, UnityPlacesPlaceSearchEntryClass))
#define UNITY_PLACES_IS_PLACE_SEARCH_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY))
#define UNITY_PLACES_IS_PLACE_SEARCH_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY))
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY, UnityPlacesPlaceSearchEntryClass))

typedef struct _UnityPlacesPlaceSearchEntry UnityPlacesPlaceSearchEntry;
typedef struct _UnityPlacesPlaceSearchEntryClass UnityPlacesPlaceSearchEntryClass;

#define UNITY_PLACES_TYPE_PLACE_SEARCH_SECTIONS_BAR (unity_places_place_search_sections_bar_get_type ())
#define UNITY_PLACES_PLACE_SEARCH_SECTIONS_BAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_SECTIONS_BAR, UnityPlacesPlaceSearchSectionsBar))
#define UNITY_PLACES_PLACE_SEARCH_SECTIONS_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_SEARCH_SECTIONS_BAR, UnityPlacesPlaceSearchSectionsBarClass))
#define UNITY_PLACES_IS_PLACE_SEARCH_SECTIONS_BAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_SECTIONS_BAR))
#define UNITY_PLACES_IS_PLACE_SEARCH_SECTIONS_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_SEARCH_SECTIONS_BAR))
#define UNITY_PLACES_PLACE_SEARCH_SECTIONS_BAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_SEARCH_SECTIONS_BAR, UnityPlacesPlaceSearchSectionsBarClass))

typedef struct _UnityPlacesPlaceSearchSectionsBar UnityPlacesPlaceSearchSectionsBar;
typedef struct _UnityPlacesPlaceSearchSectionsBarClass UnityPlacesPlaceSearchSectionsBarClass;
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
typedef struct _UnityPlacesPlaceSearchEntryPrivate UnityPlacesPlaceSearchEntryPrivate;
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))
typedef struct _UnityPlacesPlaceSearchBarBackgroundPrivate UnityPlacesPlaceSearchBarBackgroundPrivate;
#define _cairo_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_destroy (var), NULL)))
#define _cairo_pattern_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_pattern_destroy (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _UnityPlacesPlaceSearchBar {
	CtkBox parent_instance;
	UnityPlacesPlaceSearchBarPrivate * priv;
};

struct _UnityPlacesPlaceSearchBarClass {
	CtkBoxClass parent_class;
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
};

struct _UnityPlacesPlaceSearchBarPrivate {
	UnityPlacesPlaceEntry* active_entry;
	UnityPlacesPlaceSearchBarBackground* bg;
	UnityPlacesPlaceSearchEntry* entry;
	UnityPlacesPlaceSearchSectionsBar* sections;
};

struct _UnityPlacesPlaceSearchEntry {
	CtkBox parent_instance;
	UnityPlacesPlaceSearchEntryPrivate * priv;
	CtkImage* left_icon;
	CtkText* text;
	UnityThemeImage* right_icon;
};

struct _UnityPlacesPlaceSearchEntryClass {
	CtkBoxClass parent_class;
};

struct _UnityPlacesPlaceSearchBarBackground {
	CtkBin parent_instance;
	UnityPlacesPlaceSearchBarBackgroundPrivate * priv;
};

struct _UnityPlacesPlaceSearchBarBackgroundClass {
	CtkBinClass parent_class;
};

struct _UnityPlacesPlaceSearchBarBackgroundPrivate {
	gint last_width;
	gint last_height;
	GdkPixbuf* tile;
	gint _entry_position;
	ClutterCairoTexture* texture;
	CtkEffectGlow* glow;
	UnityPlacesPlaceSearchEntry* _search_entry;
};


static gpointer unity_places_place_search_bar_parent_class = NULL;
static gpointer unity_places_place_search_bar_background_parent_class = NULL;

GType unity_places_place_search_bar_get_type (void);
GType unity_places_place_entry_get_type (void);
GType unity_places_place_search_bar_background_get_type (void);
GType unity_places_place_search_entry_get_type (void);
GType unity_places_place_search_sections_bar_get_type (void);
#define UNITY_PLACES_PLACE_SEARCH_BAR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR, UnityPlacesPlaceSearchBarPrivate))
enum  {
	UNITY_PLACES_PLACE_SEARCH_BAR_DUMMY_PROPERTY
};
#define UNITY_PLACES_PLACE_SEARCH_BAR_SPACING 10
#define UNITY_PLACES_PLACE_SEARCH_BAR_RANDOM_TEXT_WIDTH 400
gpointer unity_testing_object_registry_ref (gpointer instance);
void unity_testing_object_registry_unref (gpointer instance);
GParamSpec* unity_testing_param_spec_object_registry (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_testing_value_set_object_registry (GValue* value, gpointer v_object);
void unity_testing_value_take_object_registry (GValue* value, gpointer v_object);
gpointer unity_testing_value_get_object_registry (const GValue* value);
GType unity_testing_object_registry_get_type (void);
UnityTestingObjectRegistry* unity_testing_object_registry_get_default (void);
void unity_testing_object_registry_register (UnityTestingObjectRegistry* self, const char* name, GObject* object);
UnityPlacesPlaceSearchBar* unity_places_place_search_bar_new (void);
UnityPlacesPlaceSearchBar* unity_places_place_search_bar_construct (GType object_type);
void unity_places_place_search_entry_reset (UnityPlacesPlaceSearchEntry* self);
void unity_places_place_search_bar_reset (UnityPlacesPlaceSearchBar* self);
static void unity_places_place_search_bar_on_search_text_changed (UnityPlacesPlaceSearchBar* self, const char* text);
void unity_places_place_search_bar_search (UnityPlacesPlaceSearchBar* self, const char* text);
char* unity_places_place_search_bar_get_search_text (UnityPlacesPlaceSearchBar* self);
gboolean unity_places_place_search_bar_background_update_background (UnityPlacesPlaceSearchBarBackground* self);
static gboolean _unity_places_place_search_bar_background_update_background_gsource_func (gpointer self);
static void unity_places_place_search_bar_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
static void unity_places_place_search_bar_real_get_preferred_height (ClutterActor* base, float for_width, float* min_height, float* nat_height);
void unity_places_place_entry_set_search (UnityPlacesPlaceEntry* self, const char* search, GHashTable* hints);
void unity_places_place_search_bar_background_set_entry_position (UnityPlacesPlaceSearchBarBackground* self, gint value);
void unity_places_place_search_sections_bar_set_active_entry (UnityPlacesPlaceSearchSectionsBar* self, UnityPlacesPlaceEntry* entry);
void unity_places_place_search_bar_set_active_entry_view (UnityPlacesPlaceSearchBar* self, UnityPlacesPlaceEntry* entry, gint x);
UnityPlacesPlaceSearchEntry* unity_places_place_search_entry_new (void);
UnityPlacesPlaceSearchEntry* unity_places_place_search_entry_construct (GType object_type);
static void _unity_places_place_search_bar_on_search_text_changed_unity_places_place_search_entry_text_changed (UnityPlacesPlaceSearchEntry* _sender, const char* text, gpointer self);
UnityPlacesPlaceSearchSectionsBar* unity_places_place_search_sections_bar_new (void);
UnityPlacesPlaceSearchSectionsBar* unity_places_place_search_sections_bar_construct (GType object_type);
UnityPlacesPlaceSearchBarBackground* unity_places_place_search_bar_background_new (UnityPlacesPlaceSearchEntry* search_entry);
UnityPlacesPlaceSearchBarBackground* unity_places_place_search_bar_background_construct (GType object_type, UnityPlacesPlaceSearchEntry* search_entry);
static GObject * unity_places_place_search_bar_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_place_search_bar_finalize (GObject* obj);
#define UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_PLACE_SEARCH_BAR_BACKGROUND, UnityPlacesPlaceSearchBarBackgroundPrivate))
enum  {
	UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_DUMMY_PROPERTY,
	UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_ENTRY_POSITION,
	UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_SEARCH_ENTRY
};
#define UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_BG "/usr/share/unity/dash_background.png"
static void unity_places_place_search_bar_background_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
gint unity_places_place_search_bar_background_get_entry_position (UnityPlacesPlaceSearchBarBackground* self);
UnityPlacesPlaceSearchEntry* unity_places_place_search_bar_background_get_search_entry (UnityPlacesPlaceSearchBarBackground* self);
static void unity_places_place_search_bar_background_set_search_entry (UnityPlacesPlaceSearchBarBackground* self, UnityPlacesPlaceSearchEntry* value);
static GObject * unity_places_place_search_bar_background_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_place_search_bar_background_finalize (GObject* obj);
static void unity_places_place_search_bar_background_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_place_search_bar_background_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UnityPlacesPlaceSearchBar* unity_places_place_search_bar_construct (GType object_type) {
	UnityPlacesPlaceSearchBar * self;
	UnityTestingObjectRegistry* _tmp0_;
	self = (UnityPlacesPlaceSearchBar*) g_object_new (object_type, "orientation", CTK_ORIENTATION_HORIZONTAL, "homogeneous", FALSE, "spacing", 8, NULL);
	unity_testing_object_registry_register (_tmp0_ = unity_testing_object_registry_get_default (), "UnityPlacesSearchBar", (GObject*) self);
	_unity_testing_object_registry_unref0 (_tmp0_);
	return self;
}


UnityPlacesPlaceSearchBar* unity_places_place_search_bar_new (void) {
	return unity_places_place_search_bar_construct (UNITY_PLACES_TYPE_PLACE_SEARCH_BAR);
}


void unity_places_place_search_bar_reset (UnityPlacesPlaceSearchBar* self) {
	g_return_if_fail (self != NULL);
	unity_places_place_search_entry_reset (self->priv->entry);
}


void unity_places_place_search_bar_search (UnityPlacesPlaceSearchBar* self, const char* text) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	clutter_text_set_text ((ClutterText*) self->priv->entry->text, text);
	unity_places_place_search_bar_on_search_text_changed (self, text);
}


char* unity_places_place_search_bar_get_search_text (UnityPlacesPlaceSearchBar* self) {
	char* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = g_strdup (clutter_text_get_text ((ClutterText*) self->priv->entry->text));
	return result;
}


static gboolean _unity_places_place_search_bar_background_update_background_gsource_func (gpointer self) {
	gboolean result;
	result = unity_places_place_search_bar_background_update_background (self);
	return result;
}


static void unity_places_place_search_bar_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
	UnityPlacesPlaceSearchBar * self;
	float ex;
	float ewidth;
	gboolean _tmp0_ = FALSE;
	self = (UnityPlacesPlaceSearchBar*) base;
	ex = clutter_actor_get_x ((ClutterActor*) self->priv->entry);
	ewidth = clutter_actor_get_width ((ClutterActor*) self->priv->entry);
	CLUTTER_ACTOR_CLASS (unity_places_place_search_bar_parent_class)->allocate ((ClutterActor*) CTK_BOX (self), box, flags);
	if (clutter_actor_get_x ((ClutterActor*) self->priv->entry) != ex) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = clutter_actor_get_width ((ClutterActor*) self->priv->entry) != ewidth;
	}
	if (_tmp0_) {
		g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 0, _unity_places_place_search_bar_background_update_background_gsource_func, g_object_ref (self->priv->bg), g_object_unref);
	}
}


static void unity_places_place_search_bar_real_get_preferred_height (ClutterActor* base, float for_width, float* min_height, float* nat_height) {
	UnityPlacesPlaceSearchBar * self;
	float mheight = 0.0F;
	float nheight = 0.0F;
	self = (UnityPlacesPlaceSearchBar*) base;
	clutter_actor_get_preferred_height ((ClutterActor*) self->priv->entry, (float) UNITY_PLACES_PLACE_SEARCH_BAR_RANDOM_TEXT_WIDTH, &mheight, &nheight);
	*min_height = mheight + (UNITY_PLACES_PLACE_SEARCH_BAR_SPACING * 3);
	*nat_height = nheight + (UNITY_PLACES_PLACE_SEARCH_BAR_SPACING * 3);
}


static void unity_places_place_search_bar_on_search_text_changed (UnityPlacesPlaceSearchBar* self, const char* text) {
	g_return_if_fail (self != NULL);
	if (UNITY_PLACES_IS_PLACE_ENTRY (self->priv->active_entry)) {
		GHashTable* hints;
		hints = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
		unity_places_place_entry_set_search (self->priv->active_entry, text, hints);
		_g_hash_table_unref0 (hints);
	}
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void unity_places_place_search_bar_set_active_entry_view (UnityPlacesPlaceSearchBar* self, UnityPlacesPlaceEntry* entry, gint x) {
	UnityPlacesPlaceEntry* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (entry != NULL);
	self->priv->active_entry = (_tmp0_ = _g_object_ref0 (entry), _g_object_unref0 (self->priv->active_entry), _tmp0_);
	unity_places_place_search_bar_background_set_entry_position (self->priv->bg, x);
	unity_places_place_search_sections_bar_set_active_entry (self->priv->sections, entry);
	clutter_actor_grab_key_focus ((ClutterActor*) self->priv->entry->text);
}


static void _unity_places_place_search_bar_on_search_text_changed_unity_places_place_search_entry_text_changed (UnityPlacesPlaceSearchEntry* _sender, const char* text, gpointer self) {
	unity_places_place_search_bar_on_search_text_changed (self, text);
}


static GObject * unity_places_place_search_bar_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesPlaceSearchBar * self;
	parent_class = G_OBJECT_CLASS (unity_places_place_search_bar_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_PLACE_SEARCH_BAR (obj);
	{
		CtkPadding _tmp0_ = {0};
		CtkPadding _tmp1_;
		UnityPlacesPlaceSearchEntry* _tmp2_;
		UnityPlacesPlaceSearchSectionsBar* _tmp3_;
		UnityPlacesPlaceSearchBarBackground* _tmp4_;
		ctk_actor_set_padding ((CtkActor*) self, (_tmp1_ = (_tmp0_.top = UNITY_PLACES_PLACE_SEARCH_BAR_SPACING * 2.0f, _tmp0_.right = UNITY_PLACES_PLACE_SEARCH_BAR_SPACING * 1.0f, _tmp0_.bottom = UNITY_PLACES_PLACE_SEARCH_BAR_SPACING * 1.0f, _tmp0_.left = UNITY_PLACES_PLACE_SEARCH_BAR_SPACING * 1.0f, _tmp0_), &_tmp1_));
		self->priv->entry = (_tmp2_ = g_object_ref_sink (unity_places_place_search_entry_new ()), _g_object_unref0 (self->priv->entry), _tmp2_);
		ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->priv->entry, TRUE, TRUE);
		clutter_actor_show ((ClutterActor*) self->priv->entry);
		g_signal_connect_object (self->priv->entry, "text-changed", (GCallback) _unity_places_place_search_bar_on_search_text_changed_unity_places_place_search_entry_text_changed, self, 0);
		self->priv->sections = (_tmp3_ = g_object_ref_sink (unity_places_place_search_sections_bar_new ()), _g_object_unref0 (self->priv->sections), _tmp3_);
		ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->priv->sections, FALSE, TRUE);
		clutter_actor_show ((ClutterActor*) self->priv->entry);
		self->priv->bg = (_tmp4_ = g_object_ref_sink (unity_places_place_search_bar_background_new (self->priv->entry)), _g_object_unref0 (self->priv->bg), _tmp4_);
		ctk_actor_set_background ((CtkActor*) self, (ClutterActor*) self->priv->bg);
		clutter_actor_show ((ClutterActor*) self->priv->bg);
	}
	return obj;
}


static void unity_places_place_search_bar_class_init (UnityPlacesPlaceSearchBarClass * klass) {
	unity_places_place_search_bar_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesPlaceSearchBarPrivate));
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_places_place_search_bar_real_allocate;
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_height = unity_places_place_search_bar_real_get_preferred_height;
	G_OBJECT_CLASS (klass)->constructor = unity_places_place_search_bar_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_place_search_bar_finalize;
}


static void unity_places_place_search_bar_instance_init (UnityPlacesPlaceSearchBar * self) {
	self->priv = UNITY_PLACES_PLACE_SEARCH_BAR_GET_PRIVATE (self);
	self->priv->active_entry = NULL;
}


static void unity_places_place_search_bar_finalize (GObject* obj) {
	UnityPlacesPlaceSearchBar * self;
	self = UNITY_PLACES_PLACE_SEARCH_BAR (obj);
	_g_object_unref0 (self->priv->active_entry);
	_g_object_unref0 (self->priv->bg);
	_g_object_unref0 (self->priv->entry);
	_g_object_unref0 (self->priv->sections);
	G_OBJECT_CLASS (unity_places_place_search_bar_parent_class)->finalize (obj);
}


GType unity_places_place_search_bar_get_type (void) {
	static volatile gsize unity_places_place_search_bar_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_place_search_bar_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesPlaceSearchBarClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_place_search_bar_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesPlaceSearchBar), 0, (GInstanceInitFunc) unity_places_place_search_bar_instance_init, NULL };
		GType unity_places_place_search_bar_type_id;
		unity_places_place_search_bar_type_id = g_type_register_static (CTK_TYPE_BOX, "UnityPlacesPlaceSearchBar", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_place_search_bar_type_id__volatile, unity_places_place_search_bar_type_id);
	}
	return unity_places_place_search_bar_type_id__volatile;
}


UnityPlacesPlaceSearchBarBackground* unity_places_place_search_bar_background_construct (GType object_type, UnityPlacesPlaceSearchEntry* search_entry) {
	UnityPlacesPlaceSearchBarBackground * self;
	g_return_val_if_fail (search_entry != NULL, NULL);
	self = (UnityPlacesPlaceSearchBarBackground*) g_object_new (object_type, "search-entry", search_entry, NULL);
	return self;
}


UnityPlacesPlaceSearchBarBackground* unity_places_place_search_bar_background_new (UnityPlacesPlaceSearchEntry* search_entry) {
	return unity_places_place_search_bar_background_construct (UNITY_PLACES_TYPE_PLACE_SEARCH_BAR_BACKGROUND, search_entry);
}


static void unity_places_place_search_bar_background_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
	UnityPlacesPlaceSearchBarBackground * self;
	gint width;
	gint height;
	gboolean _tmp0_ = FALSE;
	self = (UnityPlacesPlaceSearchBarBackground*) base;
	width = (gint) ((*box).x2 - (*box).x1);
	height = (gint) ((*box).y2 - (*box).y1);
	CLUTTER_ACTOR_CLASS (unity_places_place_search_bar_background_parent_class)->allocate ((ClutterActor*) CTK_BIN (self), box, flags);
	if (width != self->priv->last_width) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = height != self->priv->last_height;
	}
	if (_tmp0_) {
		self->priv->last_width = width;
		self->priv->last_height = height;
		g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 0, _unity_places_place_search_bar_background_update_background_gsource_func, g_object_ref (self), g_object_unref);
	}
}


static gpointer _cairo_pattern_reference0 (gpointer self) {
	return self ? cairo_pattern_reference (self) : NULL;
}


gboolean unity_places_place_search_bar_background_update_background (UnityPlacesPlaceSearchBarBackground* self) {
	gboolean result = FALSE;
	cairo_t* cr;
	cairo_t* _tmp0_;
	gint x;
	gint y;
	gint width;
	gint height;
	gint radius;
	g_return_val_if_fail (self != NULL, FALSE);
	cr = NULL;
	clutter_cairo_texture_set_surface_size (self->priv->texture, (guint) self->priv->last_width, (guint) self->priv->last_height);
	cr = (_tmp0_ = clutter_cairo_texture_create (self->priv->texture), _cairo_destroy0 (cr), _tmp0_);
	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	cairo_paint (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
	cairo_set_line_width (cr, 1.5);
	cairo_set_source_rgba (cr, 1.0, 1.0, 1.0, 0.0);
	cairo_translate (cr, 0.5, 0.5);
	x = 0;
	y = UNITY_PLACES_PLACE_SEARCH_BAR_SPACING;
	width = self->priv->last_width - 2;
	height = self->priv->last_height - 2;
	radius = 10;
	cairo_move_to (cr, (double) x, (double) (y + radius));
	cairo_curve_to (cr, (double) x, (double) y, (double) x, (double) y, (double) (x + radius), (double) y);
	if (unity_places_place_search_bar_background_get_entry_position (self) != 0) {
		cairo_line_to (cr, (double) (unity_places_place_search_bar_background_get_entry_position (self) - y), (double) y);
		cairo_line_to (cr, (double) unity_places_place_search_bar_background_get_entry_position (self), (double) (y - y));
		cairo_line_to (cr, (double) (unity_places_place_search_bar_background_get_entry_position (self) + y), (double) y);
	}
	cairo_line_to (cr, (double) (width - radius), (double) y);
	cairo_curve_to (cr, (double) width, (double) y, (double) width, (double) y, (double) width, (double) (y + radius));
	cairo_line_to (cr, (double) width, (double) (height - radius));
	cairo_curve_to (cr, (double) width, (double) height, (double) width, (double) height, (double) (width - radius), (double) height);
	cairo_line_to (cr, (double) (x + radius), (double) height);
	cairo_curve_to (cr, (double) x, (double) height, (double) x, (double) height, (double) x, (double) (height - radius));
	cairo_close_path (cr);
	cairo_stroke_preserve (cr);
	cairo_clip_preserve (cr);
	if (GDK_IS_PIXBUF (self->priv->tile)) {
		cairo_pattern_t* pat;
		gdk_cairo_set_source_pixbuf (cr, self->priv->tile, (double) 0, (double) 0);
		pat = _cairo_pattern_reference0 (cairo_get_source (cr));
		cairo_pattern_set_extend (pat, CAIRO_EXTEND_REPEAT);
		cairo_paint_with_alpha (cr, 0.25);
		_cairo_pattern_destroy0 (pat);
	}
	cairo_reset_clip (cr);
	cairo_set_source_rgba (cr, 1.0, 1.0, 1.0, 0.6);
	cairo_stroke (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
	x = (gint) clutter_actor_get_x ((ClutterActor*) self->priv->_search_entry);
	y = ((gint) clutter_actor_get_y ((ClutterActor*) self->priv->_search_entry)) - 1;
	width = x + ((gint) clutter_actor_get_width ((ClutterActor*) self->priv->_search_entry));
	height = (y + ((gint) clutter_actor_get_height ((ClutterActor*) self->priv->_search_entry))) + 1;
	cairo_move_to (cr, (double) x, (double) (y + radius));
	cairo_curve_to (cr, (double) x, (double) y, (double) x, (double) y, (double) (x + radius), (double) y);
	cairo_line_to (cr, (double) (width - radius), (double) y);
	cairo_curve_to (cr, (double) width, (double) y, (double) width, (double) y, (double) width, (double) (y + radius));
	cairo_line_to (cr, (double) width, (double) (height - radius));
	cairo_curve_to (cr, (double) width, (double) height, (double) width, (double) height, (double) (width - radius), (double) height);
	cairo_line_to (cr, (double) (x + radius), (double) height);
	cairo_curve_to (cr, (double) x, (double) height, (double) x, (double) height, (double) x, (double) (height - radius));
	cairo_close_path (cr);
	cairo_fill_preserve (cr);
	cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
	cairo_set_source_rgba (cr, (double) 1.0f, (double) 1.0f, (double) 1.0f, (double) 0.6f);
	cairo_stroke (cr);
	ctk_effect_set_invalidate_effect_cache ((CtkEffect*) self->priv->glow, TRUE);
	result = FALSE;
	_cairo_destroy0 (cr);
	return result;
}


gint unity_places_place_search_bar_background_get_entry_position (UnityPlacesPlaceSearchBarBackground* self) {
	gint result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->priv->_entry_position;
	return result;
}


void unity_places_place_search_bar_background_set_entry_position (UnityPlacesPlaceSearchBarBackground* self, gint value) {
	g_return_if_fail (self != NULL);
	if (self->priv->_entry_position != value) {
		self->priv->_entry_position = value;
		unity_places_place_search_bar_background_update_background (self);
	}
	g_object_notify ((GObject *) self, "entry-position");
}


UnityPlacesPlaceSearchEntry* unity_places_place_search_bar_background_get_search_entry (UnityPlacesPlaceSearchBarBackground* self) {
	UnityPlacesPlaceSearchEntry* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_search_entry;
	return result;
}


static void unity_places_place_search_bar_background_set_search_entry (UnityPlacesPlaceSearchBarBackground* self, UnityPlacesPlaceSearchEntry* value) {
	UnityPlacesPlaceSearchEntry* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_search_entry = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_search_entry), _tmp0_);
	g_object_notify ((GObject *) self, "search-entry");
}


static GObject * unity_places_place_search_bar_background_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesPlaceSearchBarBackground * self;
	GError * _inner_error_;
	parent_class = G_OBJECT_CLASS (unity_places_place_search_bar_background_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND (obj);
	_inner_error_ = NULL;
	{
		ClutterCairoTexture* _tmp7_;
		CtkEffectGlow* _tmp8_;
		ClutterColor _tmp10_;
		ClutterColor _tmp9_ = {0};
		{
			GdkPixbuf* _tmp5_;
			GdkPixbuf* _tmp6_;
			_tmp5_ = gdk_pixbuf_new_from_file (UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_BG, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch17_g_error;
			}
			self->priv->tile = (_tmp6_ = _tmp5_, _g_object_unref0 (self->priv->tile), _tmp6_);
		}
		goto __finally17;
		__catch17_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("places-place-search-bar.vala:184: Unable to load dash background");
				_g_error_free0 (e);
			}
		}
		__finally17:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		self->priv->texture = (_tmp7_ = g_object_ref_sink ((ClutterCairoTexture*) clutter_cairo_texture_new ((guint) 10, (guint) 10)), _g_object_unref0 (self->priv->texture), _tmp7_);
		clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) self->priv->texture);
		clutter_actor_show ((ClutterActor*) self->priv->texture);
		self->priv->glow = (_tmp8_ = g_object_ref_sink ((CtkEffectGlow*) ctk_effect_glow_new ()), _g_object_unref0 (self->priv->glow), _tmp8_);
		ctk_effect_glow_set_color (self->priv->glow, (_tmp10_ = (_tmp9_.red = (guint8) 255, _tmp9_.green = (guint8) 255, _tmp9_.blue = (guint8) 255, _tmp9_.alpha = (guint8) 255, _tmp9_), &_tmp10_));
		ctk_effect_glow_set_factor (self->priv->glow, 1.0f);
		ctk_effect_set_margin ((CtkEffect*) self->priv->glow, 5);
		ctk_actor_add_effect ((CtkActor*) self, (CtkEffect*) self->priv->glow);
	}
	return obj;
}


static void unity_places_place_search_bar_background_class_init (UnityPlacesPlaceSearchBarBackgroundClass * klass) {
	unity_places_place_search_bar_background_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesPlaceSearchBarBackgroundPrivate));
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_places_place_search_bar_background_real_allocate;
	G_OBJECT_CLASS (klass)->get_property = unity_places_place_search_bar_background_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_place_search_bar_background_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_places_place_search_bar_background_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_place_search_bar_background_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_ENTRY_POSITION, g_param_spec_int ("entry-position", "entry-position", "entry-position", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_SEARCH_ENTRY, g_param_spec_object ("search-entry", "search-entry", "search-entry", UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_places_place_search_bar_background_instance_init (UnityPlacesPlaceSearchBarBackground * self) {
	self->priv = UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_GET_PRIVATE (self);
	self->priv->last_width = 0;
	self->priv->last_height = 0;
	self->priv->tile = NULL;
	self->priv->_entry_position = 0;
}


static void unity_places_place_search_bar_background_finalize (GObject* obj) {
	UnityPlacesPlaceSearchBarBackground * self;
	self = UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND (obj);
	_g_object_unref0 (self->priv->tile);
	_g_object_unref0 (self->priv->texture);
	_g_object_unref0 (self->priv->glow);
	_g_object_unref0 (self->priv->_search_entry);
	G_OBJECT_CLASS (unity_places_place_search_bar_background_parent_class)->finalize (obj);
}


GType unity_places_place_search_bar_background_get_type (void) {
	static volatile gsize unity_places_place_search_bar_background_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_place_search_bar_background_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesPlaceSearchBarBackgroundClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_place_search_bar_background_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesPlaceSearchBarBackground), 0, (GInstanceInitFunc) unity_places_place_search_bar_background_instance_init, NULL };
		GType unity_places_place_search_bar_background_type_id;
		unity_places_place_search_bar_background_type_id = g_type_register_static (CTK_TYPE_BIN, "UnityPlacesPlaceSearchBarBackground", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_place_search_bar_background_type_id__volatile, unity_places_place_search_bar_background_type_id);
	}
	return unity_places_place_search_bar_background_type_id__volatile;
}


static void unity_places_place_search_bar_background_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesPlaceSearchBarBackground * self;
	self = UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_ENTRY_POSITION:
		g_value_set_int (value, unity_places_place_search_bar_background_get_entry_position (self));
		break;
		case UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_SEARCH_ENTRY:
		g_value_set_object (value, unity_places_place_search_bar_background_get_search_entry (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_place_search_bar_background_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesPlaceSearchBarBackground * self;
	self = UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_ENTRY_POSITION:
		unity_places_place_search_bar_background_set_entry_position (self, g_value_get_int (value));
		break;
		case UNITY_PLACES_PLACE_SEARCH_BAR_BACKGROUND_SEARCH_ENTRY:
		unity_places_place_search_bar_background_set_search_entry (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




