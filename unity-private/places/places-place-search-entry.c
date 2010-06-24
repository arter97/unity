/* places-place-search-entry.c generated by valac, the Vala compiler
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
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <clutter/clutter.h>


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

struct _UnityPlacesPlaceSearchEntryPrivate {
	guint live_search_timeout;
};


static gpointer unity_places_place_search_entry_parent_class = NULL;

GType unity_places_place_search_entry_get_type (void);
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY, UnityPlacesPlaceSearchEntryPrivate))
enum  {
	UNITY_PLACES_PLACE_SEARCH_ENTRY_DUMMY_PROPERTY
};
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_SEARCH_ICON_FILE PKGDATADIR "/search_icon.png"
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_PADDING 1.0f
#define UNITY_PLACES_PLACE_SEARCH_ENTRY_LIVE_SEARCH_TIMEOUT 300
UnityPlacesPlaceSearchEntry* unity_places_place_search_entry_new (void);
UnityPlacesPlaceSearchEntry* unity_places_place_search_entry_construct (GType object_type);
static void unity_places_place_search_entry_real_get_preferred_height (ClutterActor* base, float for_width, float* min_height, float* nat_height);
static gboolean _lambda7_ (UnityPlacesPlaceSearchEntry* self);
static gboolean __lambda7__gsource_func (gpointer self);
static void unity_places_place_search_entry_on_text_changed (UnityPlacesPlaceSearchEntry* self);
static void _unity_places_place_search_entry_on_text_changed_clutter_text_text_changed (ClutterText* _sender, gpointer self);
static GObject * unity_places_place_search_entry_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_place_search_entry_finalize (GObject* obj);



UnityPlacesPlaceSearchEntry* unity_places_place_search_entry_construct (GType object_type) {
	UnityPlacesPlaceSearchEntry * self;
	self = (UnityPlacesPlaceSearchEntry*) g_object_new (object_type, "orientation", CTK_ORIENTATION_HORIZONTAL, "homogeneous", FALSE, "spacing", 6, NULL);
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
	if (mheight > 22.0f) {
		_tmp0_ = mheight;
	} else {
		_tmp0_ = 22.0f;
	}
	*min_height = _tmp0_;
	*min_height = (*min_height) + (UNITY_PLACES_PLACE_SEARCH_ENTRY_PADDING * 2);
	*nat_height = *min_height;
}


static gboolean _lambda7_ (UnityPlacesPlaceSearchEntry* self) {
	gboolean result = FALSE;
	g_signal_emit_by_name (self, "text-changed", clutter_text_get_text ((ClutterText*) self->text));
	self->priv->live_search_timeout = (guint) 0;
	result = FALSE;
	return result;
}


static gboolean __lambda7__gsource_func (gpointer self) {
	gboolean result;
	result = _lambda7_ (self);
	return result;
}


static void unity_places_place_search_entry_on_text_changed (UnityPlacesPlaceSearchEntry* self) {
	g_return_if_fail (self != NULL);
	if (self->priv->live_search_timeout != 0) {
		g_source_remove (self->priv->live_search_timeout);
	}
	self->priv->live_search_timeout = g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) UNITY_PLACES_PLACE_SEARCH_ENTRY_LIVE_SEARCH_TIMEOUT, __lambda7__gsource_func, g_object_ref (self), g_object_unref);
}


static void _unity_places_place_search_entry_on_text_changed_clutter_text_text_changed (ClutterText* _sender, gpointer self) {
	unity_places_place_search_entry_on_text_changed (self);
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
		CtkText* _tmp3_;
		UnityThemeImage* _tmp4_;
		ctk_actor_set_padding ((CtkActor*) self, (_tmp1_ = (_tmp0_.top = UNITY_PLACES_PLACE_SEARCH_ENTRY_PADDING, _tmp0_.right = UNITY_PLACES_PLACE_SEARCH_ENTRY_PADDING * 4, _tmp0_.bottom = UNITY_PLACES_PLACE_SEARCH_ENTRY_PADDING, _tmp0_.left = UNITY_PLACES_PLACE_SEARCH_ENTRY_PADDING * 4, _tmp0_), &_tmp1_));
		self->left_icon = (_tmp2_ = g_object_ref_sink ((CtkImage*) ctk_image_new_from_filename ((guint) 18, UNITY_PLACES_PLACE_SEARCH_ENTRY_SEARCH_ICON_FILE)), _g_object_unref0 (self->left_icon), _tmp2_);
		ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->left_icon, FALSE, TRUE);
		clutter_actor_show ((ClutterActor*) self->left_icon);
		self->text = (_tmp3_ = g_object_ref_sink ((CtkText*) ctk_text_new ("Search")), _g_object_unref0 (self->text), _tmp3_);
		clutter_actor_set_reactive ((ClutterActor*) self->text, TRUE);
		clutter_text_set_selectable ((ClutterText*) self->text, TRUE);
		clutter_text_set_editable ((ClutterText*) self->text, TRUE);
		clutter_text_set_activatable ((ClutterText*) self->text, TRUE);
		clutter_text_set_single_line_mode ((ClutterText*) self->text, TRUE);
		ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->text, TRUE, TRUE);
		clutter_actor_show ((ClutterActor*) self->text);
		g_signal_connect_object ((ClutterText*) self->text, "text-changed", (GCallback) _unity_places_place_search_entry_on_text_changed_clutter_text_text_changed, self, 0);
		self->right_icon = (_tmp4_ = g_object_ref_sink (unity_theme_image_new ("gtk-close")), _g_object_unref0 (self->right_icon), _tmp4_);
		ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->right_icon, FALSE, TRUE);
		clutter_actor_show ((ClutterActor*) self->right_icon);
	}
	return obj;
}


static void unity_places_place_search_entry_class_init (UnityPlacesPlaceSearchEntryClass * klass) {
	unity_places_place_search_entry_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesPlaceSearchEntryPrivate));
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_height = unity_places_place_search_entry_real_get_preferred_height;
	G_OBJECT_CLASS (klass)->constructor = unity_places_place_search_entry_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_place_search_entry_finalize;
	g_signal_new ("text_changed", UNITY_PLACES_TYPE_PLACE_SEARCH_ENTRY, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, 1, G_TYPE_STRING);
}


static void unity_places_place_search_entry_instance_init (UnityPlacesPlaceSearchEntry * self) {
	self->priv = UNITY_PLACES_PLACE_SEARCH_ENTRY_GET_PRIVATE (self);
	self->priv->live_search_timeout = (guint) 0;
}


static void unity_places_place_search_entry_finalize (GObject* obj) {
	UnityPlacesPlaceSearchEntry * self;
	self = UNITY_PLACES_PLACE_SEARCH_ENTRY (obj);
	_g_object_unref0 (self->left_icon);
	_g_object_unref0 (self->text);
	_g_object_unref0 (self->right_icon);
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




