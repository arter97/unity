/* places-place.c generated by valac, the Vala compiler
 * generated from places-place.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <gee.h>


#define UNITY_PLACES_TYPE_PLACE (unity_places_place_get_type ())
#define UNITY_PLACES_PLACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlace))
#define UNITY_PLACES_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))
#define UNITY_PLACES_IS_PLACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_IS_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_PLACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))

typedef struct _UnityPlacesPlace UnityPlacesPlace;
typedef struct _UnityPlacesPlaceClass UnityPlacesPlaceClass;
typedef struct _UnityPlacesPlacePrivate UnityPlacesPlacePrivate;

#define UNITY_PLACES_TYPE_PLACE_ENTRY (unity_places_place_entry_get_type ())
#define UNITY_PLACES_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntry))
#define UNITY_PLACES_PLACE_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntryClass))
#define UNITY_PLACES_IS_PLACE_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY))
#define UNITY_PLACES_IS_PLACE_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_ENTRY))
#define UNITY_PLACES_PLACE_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_ENTRY, UnityPlacesPlaceEntryClass))

typedef struct _UnityPlacesPlaceEntry UnityPlacesPlaceEntry;
typedef struct _UnityPlacesPlaceEntryClass UnityPlacesPlaceEntryClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _UnityPlacesPlace {
	GObject parent_instance;
	UnityPlacesPlacePrivate * priv;
};

struct _UnityPlacesPlaceClass {
	GObjectClass parent_class;
};

struct _UnityPlacesPlacePrivate {
	char* _dbus_name;
	char* _dbus_path;
	gboolean _online;
	DBusGConnection* connection;
	DBusGProxy* service;
	GeeArrayList* entries_array;
};


static gpointer unity_places_place_parent_class = NULL;

GType unity_places_place_get_type (void);
GType unity_places_place_entry_get_type (void);
#define UNITY_PLACES_PLACE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlacePrivate))
enum  {
	UNITY_PLACES_PLACE_DUMMY_PROPERTY,
	UNITY_PLACES_PLACE_DBUS_NAME,
	UNITY_PLACES_PLACE_DBUS_PATH,
	UNITY_PLACES_PLACE_N_ENTRIES,
	UNITY_PLACES_PLACE_ONLINE
};
#define UNITY_PLACES_PLACE_PLACE_GROUP "Place"
#define UNITY_PLACES_PLACE_ENTRY_PREFIX "Entry:"
UnityPlacesPlace* unity_places_place_new (const char* dbus_name, const char* dbus_path);
UnityPlacesPlace* unity_places_place_construct (GType object_type, const char* dbus_name, const char* dbus_path);
static void unity_places_place_load_keyfile_entries (UnityPlacesPlace* self, GKeyFile* file);
UnityPlacesPlace* unity_places_place_new_from_keyfile (GKeyFile* file, const char* id);
GeeArrayList* unity_places_place_get_entries (UnityPlacesPlace* self);
UnityPlacesPlaceEntry* unity_places_place_get_nth_entry (UnityPlacesPlace* self, gint index);
gboolean unity_places_place_get_online (UnityPlacesPlace* self);
const char* unity_places_place_get_dbus_name (UnityPlacesPlace* self);
const char* unity_places_place_get_dbus_path (UnityPlacesPlace* self);
static void unity_places_place_on_service_entry_added (UnityPlacesPlace* self, DBusGProxy* dbus_object, GValueArray* info);
static void _unity_places_place_on_service_entry_added_dynamic_EntryAdded2_ (DBusGProxy* _sender, GValueArray* info, gpointer self);
void _dynamic_EntryAdded3_connect (gpointer obj, const char * signal_name, GCallback handler, gpointer data);
static void unity_places_place_on_service_entry_removed (UnityPlacesPlace* self, DBusGProxy* dbus_object, const char* entry_path);
static void _unity_places_place_on_service_entry_removed_dynamic_EntryRemoved4_ (DBusGProxy* _sender, const char* entry_path, gpointer self);
void _dynamic_EntryRemoved5_connect (gpointer obj, const char * signal_name, GCallback handler, gpointer data);
static GValueArray** _dynamic_get_entries4 (DBusGProxy* self, int* result_length1, GError** error);
const char* unity_places_place_entry_get_dbus_path (UnityPlacesPlaceEntry* self);
void unity_places_place_entry_update_info (UnityPlacesPlaceEntry* self, GValueArray* value_array);
void unity_places_place_entry_connect (UnityPlacesPlaceEntry* self);
gboolean unity_places_place_entry_get_online (UnityPlacesPlaceEntry* self);
void unity_places_place_set_online (UnityPlacesPlace* self, gboolean value);
void unity_places_place_connect (UnityPlacesPlace* self);
UnityPlacesPlaceEntry* unity_places_place_entry_new (const char* dbus_name, const char* dbus_path);
UnityPlacesPlaceEntry* unity_places_place_entry_construct (GType object_type, const char* dbus_name, const char* dbus_path);
static UnityPlacesPlaceEntry* unity_places_place_load_entry_from_keyfile (UnityPlacesPlace* self, GKeyFile* file, const char* group);
UnityPlacesPlaceEntry* unity_places_place_entry_new_with_info (const char* dbus_name, const char* dbus_path, const char* name, const char* icon, const char* description, gboolean show_global, gboolean show_entry);
UnityPlacesPlaceEntry* unity_places_place_entry_construct_with_info (GType object_type, const char* dbus_name, const char* dbus_path, const char* name, const char* icon, const char* description, gboolean show_global, gboolean show_entry);
static void unity_places_place_set_dbus_name (UnityPlacesPlace* self, const char* value);
static void unity_places_place_set_dbus_path (UnityPlacesPlace* self, const char* value);
gint unity_places_place_get_n_entries (UnityPlacesPlace* self);
static GObject * unity_places_place_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_place_finalize (GObject* obj);
static void unity_places_place_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_place_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static int _vala_strcmp0 (const char * str1, const char * str2);


static void g_cclosure_user_marshal_VOID__BOXED (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);

UnityPlacesPlace* unity_places_place_construct (GType object_type, const char* dbus_name, const char* dbus_path) {
	UnityPlacesPlace * self;
	g_return_val_if_fail (dbus_name != NULL, NULL);
	g_return_val_if_fail (dbus_path != NULL, NULL);
	self = (UnityPlacesPlace*) g_object_new (object_type, "dbus-name", dbus_name, "dbus-path", dbus_path, NULL);
	return self;
}


UnityPlacesPlace* unity_places_place_new (const char* dbus_name, const char* dbus_path) {
	return unity_places_place_construct (UNITY_PLACES_TYPE_PLACE, dbus_name, dbus_path);
}


static const char* string_to_string (const char* self) {
	const char* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


UnityPlacesPlace* unity_places_place_new_from_keyfile (GKeyFile* file, const char* id) {
	UnityPlacesPlace* result = NULL;
	GError * _inner_error_;
	char* errmsg;
	g_return_val_if_fail (file != NULL, NULL);
	g_return_val_if_fail (id != NULL, NULL);
	_inner_error_ = NULL;
	errmsg = g_strconcat ("Unable to load place '", string_to_string (id), "': %s", NULL);
	if (g_key_file_has_group (file, UNITY_PLACES_PLACE_PLACE_GROUP) == FALSE) {
		g_warning (errmsg, "Does not contain 'Place' group");
		result = NULL;
		_g_free0 (errmsg);
		return result;
	}
	{
		char* dbus_name;
		char* dbus_path;
		UnityPlacesPlace* place;
		dbus_name = g_key_file_get_string (file, UNITY_PLACES_PLACE_PLACE_GROUP, "DBusName", &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch13_g_error;
		}
		dbus_path = g_key_file_get_string (file, UNITY_PLACES_PLACE_PLACE_GROUP, "DBusObjectPath", &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_free0 (dbus_name);
			goto __catch13_g_error;
		}
		place = unity_places_place_new (dbus_name, dbus_path);
		unity_places_place_load_keyfile_entries (place, file);
		result = place;
		_g_free0 (dbus_name);
		_g_free0 (dbus_path);
		_g_free0 (errmsg);
		return result;
	}
	goto __finally13;
	__catch13_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning (errmsg, e->message);
			result = NULL;
			_g_error_free0 (e);
			_g_free0 (errmsg);
			return result;
		}
	}
	__finally13:
	{
		_g_free0 (errmsg);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	_g_free0 (errmsg);
}


GeeArrayList* unity_places_place_get_entries (UnityPlacesPlace* self) {
	GeeArrayList* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->entries_array;
	return result;
}


UnityPlacesPlaceEntry* unity_places_place_get_nth_entry (UnityPlacesPlace* self, gint index) {
	UnityPlacesPlaceEntry* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = (UnityPlacesPlaceEntry*) gee_abstract_list_get ((GeeAbstractList*) self->priv->entries_array, index);
	return result;
}


static void _unity_places_place_on_service_entry_added_dynamic_EntryAdded2_ (DBusGProxy* _sender, GValueArray* info, gpointer self) {
	unity_places_place_on_service_entry_added (self, _sender, info);
}


void _dynamic_EntryAdded3_connect (gpointer obj, const char * signal_name, GCallback handler, gpointer data) {
	dbus_g_object_register_marshaller (g_cclosure_user_marshal_VOID__BOXED, G_TYPE_NONE, G_TYPE_VALUE_ARRAY, G_TYPE_INVALID);
	dbus_g_proxy_add_signal (obj, "EntryAdded", G_TYPE_VALUE_ARRAY, G_TYPE_INVALID);
	dbus_g_proxy_connect_signal (obj, signal_name, handler, data, NULL);
}


static void _unity_places_place_on_service_entry_removed_dynamic_EntryRemoved4_ (DBusGProxy* _sender, const char* entry_path, gpointer self) {
	unity_places_place_on_service_entry_removed (self, _sender, entry_path);
}


void _dynamic_EntryRemoved5_connect (gpointer obj, const char * signal_name, GCallback handler, gpointer data) {
	dbus_g_object_register_marshaller (g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, G_TYPE_STRING, G_TYPE_INVALID);
	dbus_g_proxy_add_signal (obj, "EntryRemoved", G_TYPE_STRING, G_TYPE_INVALID);
	dbus_g_proxy_connect_signal (obj, signal_name, handler, data, NULL);
}


static GValueArray** _dynamic_get_entries4 (DBusGProxy* self, int* result_length1, GError** error) {
	GPtrArray* result;
	dbus_g_proxy_call (self, "GetEntries", error, G_TYPE_INVALID, dbus_g_type_get_collection ("GPtrArray", G_TYPE_VALUE_ARRAY), &result, G_TYPE_INVALID);
	if (*error) {
		return NULL;
	}
	*result_length1 = result->len;
	return (GValueArray**) result->pdata;
}


void unity_places_place_connect (UnityPlacesPlace* self) {
	GError * _inner_error_;
	GValueArray** _tmp5_;
	gint _entries_size_;
	gint entries_length1;
	gint _tmp4_;
	GValueArray** entries;
	GeeArrayList* old;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	if (self->priv->_online) {
		return;
	}
	{
		DBusGConnection* _tmp0_;
		DBusGConnection* _tmp1_;
		DBusGProxy* _tmp2_;
		_tmp0_ = dbus_g_bus_get (DBUS_BUS_SESSION, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch14_g_error;
		}
		self->priv->connection = (_tmp1_ = _tmp0_, _dbus_g_connection_unref0 (self->priv->connection), _tmp1_);
		self->priv->service = (_tmp2_ = dbus_g_proxy_new_for_name (self->priv->connection, self->priv->_dbus_name, self->priv->_dbus_path, "com.canonical.Unity.Place"), _g_object_unref0 (self->priv->service), _tmp2_);
	}
	goto __finally14;
	__catch14_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp3_;
			g_warning (_tmp3_ = g_strconcat ("Unable to connect to ", string_to_string (self->priv->_dbus_path), " on ", string_to_string (self->priv->_dbus_name), ": %s", NULL), e->message);
			_g_free0 (_tmp3_);
			_g_error_free0 (e);
			return;
		}
	}
	__finally14:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_dynamic_EntryAdded3_connect (self->priv->service, "EntryAdded", (GCallback) _unity_places_place_on_service_entry_added_dynamic_EntryAdded2_, self);
	_dynamic_EntryRemoved5_connect (self->priv->service, "EntryRemoved", (GCallback) _unity_places_place_on_service_entry_removed_dynamic_EntryRemoved4_, self);
	entries = (_tmp5_ = _dynamic_get_entries4 (self->priv->service, &_tmp4_, &_inner_error_), entries_length1 = _tmp4_, _entries_size_ = entries_length1, _tmp5_);
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	{
		gint i;
		i = 0;
		{
			gboolean _tmp6_;
			_tmp6_ = TRUE;
			while (TRUE) {
				GValueArray* array;
				char* path;
				gboolean existing;
				if (!_tmp6_) {
					i++;
				}
				_tmp6_ = FALSE;
				if (!(i < entries_length1)) {
					break;
				}
				array = entries[i];
				path = g_strdup (g_value_get_string (g_value_array_get_nth (array, (guint) 0)));
				existing = FALSE;
				{
					GeeIterator* _entry_it;
					_entry_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->entries_array);
					while (TRUE) {
						UnityPlacesPlaceEntry* entry;
						if (!gee_iterator_next (_entry_it)) {
							break;
						}
						entry = (UnityPlacesPlaceEntry*) gee_iterator_get (_entry_it);
						if (_vala_strcmp0 (unity_places_place_entry_get_dbus_path (entry), path) == 0) {
							unity_places_place_entry_update_info (entry, array);
							unity_places_place_entry_connect (entry);
							existing = TRUE;
						}
						_g_object_unref0 (entry);
					}
					_g_object_unref0 (_entry_it);
				}
				if (existing == FALSE) {
					unity_places_place_on_service_entry_added (self, self->priv->service, array);
				}
				_g_free0 (path);
			}
		}
	}
	old = gee_array_list_new (UNITY_PLACES_TYPE_PLACE_ENTRY, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL);
	{
		GeeIterator* _entry_it;
		_entry_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->entries_array);
		while (TRUE) {
			UnityPlacesPlaceEntry* entry;
			if (!gee_iterator_next (_entry_it)) {
				break;
			}
			entry = (UnityPlacesPlaceEntry*) gee_iterator_get (_entry_it);
			if (unity_places_place_entry_get_online (entry) == FALSE) {
				gee_abstract_collection_add ((GeeAbstractCollection*) old, entry);
			}
			_g_object_unref0 (entry);
		}
		_g_object_unref0 (_entry_it);
	}
	{
		GeeIterator* _entry_it;
		_entry_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) old);
		while (TRUE) {
			UnityPlacesPlaceEntry* entry;
			if (!gee_iterator_next (_entry_it)) {
				break;
			}
			entry = (UnityPlacesPlaceEntry*) gee_iterator_get (_entry_it);
			g_signal_emit_by_name (self, "entry-removed", entry);
			gee_abstract_collection_remove ((GeeAbstractCollection*) self->priv->entries_array, entry);
			_g_object_unref0 (entry);
		}
		_g_object_unref0 (_entry_it);
	}
	unity_places_place_set_online (self, TRUE);
	entries = (_vala_array_free (entries, entries_length1, (GDestroyNotify) g_value_array_free), NULL);
	_g_object_unref0 (old);
}


static void unity_places_place_on_service_entry_added (UnityPlacesPlace* self, DBusGProxy* dbus_object, GValueArray* info) {
	UnityPlacesPlaceEntry* entry;
	g_return_if_fail (self != NULL);
	g_return_if_fail (dbus_object != NULL);
	g_return_if_fail (info != NULL);
	g_debug ("places-place.vala:177: EntryAdded %s", g_value_get_string (g_value_array_get_nth (info, (guint) 0)));
	entry = unity_places_place_entry_new (self->priv->_dbus_name, g_value_get_string (g_value_array_get_nth (info, (guint) 0)));
	unity_places_place_entry_update_info (entry, info);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->entries_array, entry);
	unity_places_place_entry_connect (entry);
	g_signal_emit_by_name (self, "entry-added", entry);
	_g_object_unref0 (entry);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_places_place_on_service_entry_removed (UnityPlacesPlace* self, DBusGProxy* dbus_object, const char* entry_path) {
	char* _tmp0_;
	UnityPlacesPlaceEntry* entry;
	g_return_if_fail (self != NULL);
	g_return_if_fail (dbus_object != NULL);
	g_return_if_fail (entry_path != NULL);
	g_debug ("places-place.vala:190: %s", _tmp0_ = g_strconcat ("EntryRemoved: ", string_to_string (entry_path), NULL));
	_g_free0 (_tmp0_);
	entry = NULL;
	{
		GeeIterator* _e_it;
		_e_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) self->priv->entries_array);
		while (TRUE) {
			UnityPlacesPlaceEntry* e;
			if (!gee_iterator_next (_e_it)) {
				break;
			}
			e = (UnityPlacesPlaceEntry*) gee_iterator_get (_e_it);
			if (_vala_strcmp0 (unity_places_place_entry_get_dbus_path (e), entry_path) == 0) {
				UnityPlacesPlaceEntry* _tmp1_;
				entry = (_tmp1_ = _g_object_ref0 (e), _g_object_unref0 (entry), _tmp1_);
				_g_object_unref0 (e);
				break;
			}
			_g_object_unref0 (e);
		}
		_g_object_unref0 (_e_it);
	}
	if (UNITY_PLACES_IS_PLACE_ENTRY (entry)) {
		g_signal_emit_by_name (self, "entry-removed", entry);
		gee_abstract_collection_remove ((GeeAbstractCollection*) self->priv->entries_array, entry);
	}
	_g_object_unref0 (entry);
}


static void unity_places_place_load_keyfile_entries (UnityPlacesPlace* self, GKeyFile* file) {
	char** _tmp1_;
	gint _groups_size_;
	gint groups_length1;
	gsize _tmp0_;
	char** groups;
	g_return_if_fail (self != NULL);
	g_return_if_fail (file != NULL);
	groups = (_tmp1_ = g_key_file_get_groups (file, &_tmp0_), groups_length1 = _tmp0_, _groups_size_ = groups_length1, _tmp1_);
	{
		char** group_collection;
		int group_collection_length1;
		int group_it;
		group_collection = groups;
		group_collection_length1 = groups_length1;
		for (group_it = 0; group_it < groups_length1; group_it = group_it + 1) {
			char* group;
			group = g_strdup (group_collection[group_it]);
			{
				if (g_str_has_prefix (group, UNITY_PLACES_PLACE_ENTRY_PREFIX)) {
					UnityPlacesPlaceEntry* entry;
					entry = unity_places_place_load_entry_from_keyfile (self, file, group);
					if (UNITY_PLACES_IS_PLACE_ENTRY (entry)) {
						gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->entries_array, entry);
						g_signal_emit_by_name (self, "entry-added", entry);
					}
					_g_object_unref0 (entry);
				}
				_g_free0 (group);
			}
		}
	}
	groups = (_vala_array_free (groups, groups_length1, (GDestroyNotify) g_free), NULL);
}


static UnityPlacesPlaceEntry* unity_places_place_load_entry_from_keyfile (UnityPlacesPlace* self, GKeyFile* file, const char* group) {
	UnityPlacesPlaceEntry* result = NULL;
	GError * _inner_error_;
	char* path;
	char* name;
	char* icon;
	char* desc;
	gboolean show_global;
	gboolean show_entry;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (file != NULL, NULL);
	g_return_val_if_fail (group != NULL, NULL);
	_inner_error_ = NULL;
	path = g_strdup ("");
	name = g_strdup ("");
	icon = g_strdup ("");
	desc = g_strdup ("");
	show_global = FALSE;
	show_entry = FALSE;
	{
		char* _tmp0_;
		char* _tmp1_;
		gboolean _tmp2_ = FALSE;
		gboolean _tmp3_ = FALSE;
		char* _tmp5_;
		char* _tmp6_;
		char* _tmp7_;
		char* _tmp8_;
		char* _tmp9_;
		char* _tmp10_;
		_tmp0_ = g_key_file_get_string (file, group, "DBusObjectPath", &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch15_g_error;
		}
		path = (_tmp1_ = _tmp0_, _g_free0 (path), _tmp1_);
		if (path == NULL) {
			_tmp3_ = TRUE;
		} else {
			_tmp3_ = _vala_strcmp0 (path, "") == 0;
		}
		if (_tmp3_) {
			_tmp2_ = TRUE;
		} else {
			_tmp2_ = g_utf8_get_char (g_utf8_offset_to_pointer (path, 0)) != '/';
		}
		if (_tmp2_) {
			char* _tmp4_;
			g_warning ("places-place.vala:245: %s", _tmp4_ = g_strconcat ("Cannot load entry '", string_to_string (group), "': Does not contain valid DBusObjectPath: ", string_to_string (path), NULL));
			_g_free0 (_tmp4_);
			result = NULL;
			_g_free0 (path);
			_g_free0 (name);
			_g_free0 (icon);
			_g_free0 (desc);
			return result;
		}
		_tmp5_ = g_key_file_get_string (file, group, "Name", &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch15_g_error;
		}
		name = (_tmp6_ = _tmp5_, _g_free0 (name), _tmp6_);
		_tmp7_ = g_key_file_get_string (file, group, "Icon", &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch15_g_error;
		}
		icon = (_tmp8_ = _tmp7_, _g_free0 (icon), _tmp8_);
		_tmp9_ = g_key_file_get_string (file, group, "Description", &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch15_g_error;
		}
		desc = (_tmp10_ = _tmp9_, _g_free0 (desc), _tmp10_);
	}
	goto __finally15;
	__catch15_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp11_;
			g_warning (_tmp11_ = g_strconcat ("Cannot load entry '", string_to_string (group), "': %s", NULL), e->message);
			_g_free0 (_tmp11_);
			result = NULL;
			_g_error_free0 (e);
			_g_free0 (path);
			_g_free0 (name);
			_g_free0 (icon);
			_g_free0 (desc);
			return result;
		}
	}
	__finally15:
	if (_inner_error_ != NULL) {
		_g_free0 (path);
		_g_free0 (name);
		_g_free0 (icon);
		_g_free0 (desc);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	{
		gboolean _tmp12_;
		gboolean _tmp13_;
		_tmp12_ = g_key_file_get_boolean (file, group, "ShowGlobal", &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch16_g_error;
		}
		show_global = _tmp12_;
		_tmp13_ = g_key_file_get_boolean (file, group, "ShowEntry", &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch16_g_error;
		}
		show_entry = _tmp13_;
	}
	goto __finally16;
	__catch16_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			show_global = TRUE;
			show_entry = TRUE;
			_g_error_free0 (e);
		}
	}
	__finally16:
	if (_inner_error_ != NULL) {
		_g_free0 (path);
		_g_free0 (name);
		_g_free0 (icon);
		_g_free0 (desc);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	result = unity_places_place_entry_new_with_info (self->priv->_dbus_name, path, name, icon, desc, show_global, show_entry);
	_g_free0 (path);
	_g_free0 (name);
	_g_free0 (icon);
	_g_free0 (desc);
	return result;
}


const char* unity_places_place_get_dbus_name (UnityPlacesPlace* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_dbus_name;
	return result;
}


static void unity_places_place_set_dbus_name (UnityPlacesPlace* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_dbus_name = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_dbus_name), _tmp0_);
	g_object_notify ((GObject *) self, "dbus-name");
}


const char* unity_places_place_get_dbus_path (UnityPlacesPlace* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_dbus_path;
	return result;
}


static void unity_places_place_set_dbus_path (UnityPlacesPlace* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_dbus_path = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_dbus_path), _tmp0_);
	g_object_notify ((GObject *) self, "dbus-path");
}


gint unity_places_place_get_n_entries (UnityPlacesPlace* self) {
	gint result;
	g_return_val_if_fail (self != NULL, 0);
	result = gee_collection_get_size ((GeeCollection*) self->priv->entries_array);
	return result;
}


gboolean unity_places_place_get_online (UnityPlacesPlace* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_online;
	return result;
}


void unity_places_place_set_online (UnityPlacesPlace* self, gboolean value) {
	g_return_if_fail (self != NULL);
	self->priv->_online = value;
	g_object_notify ((GObject *) self, "online");
}


static GObject * unity_places_place_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesPlace * self;
	parent_class = G_OBJECT_CLASS (unity_places_place_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_PLACE (obj);
	{
		GeeArrayList* _tmp0_;
		unity_places_place_set_online (self, FALSE);
		self->priv->entries_array = (_tmp0_ = gee_array_list_new (UNITY_PLACES_TYPE_PLACE_ENTRY, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL), _g_object_unref0 (self->priv->entries_array), _tmp0_);
	}
	return obj;
}


static void unity_places_place_class_init (UnityPlacesPlaceClass * klass) {
	unity_places_place_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesPlacePrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_places_place_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_place_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_places_place_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_place_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_DBUS_NAME, g_param_spec_string ("dbus-name", "dbus-name", "dbus-name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_DBUS_PATH, g_param_spec_string ("dbus-path", "dbus-path", "dbus-path", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_N_ENTRIES, g_param_spec_int ("n-entries", "n-entries", "n-entries", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_ONLINE, g_param_spec_boolean ("online", "online", "online", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_signal_new ("entry_added", UNITY_PLACES_TYPE_PLACE, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, UNITY_PLACES_TYPE_PLACE_ENTRY);
	g_signal_new ("entry_removed", UNITY_PLACES_TYPE_PLACE, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, UNITY_PLACES_TYPE_PLACE_ENTRY);
}


static void unity_places_place_instance_init (UnityPlacesPlace * self) {
	self->priv = UNITY_PLACES_PLACE_GET_PRIVATE (self);
}


static void unity_places_place_finalize (GObject* obj) {
	UnityPlacesPlace * self;
	self = UNITY_PLACES_PLACE (obj);
	_g_free0 (self->priv->_dbus_name);
	_g_free0 (self->priv->_dbus_path);
	_dbus_g_connection_unref0 (self->priv->connection);
	_g_object_unref0 (self->priv->service);
	_g_object_unref0 (self->priv->entries_array);
	G_OBJECT_CLASS (unity_places_place_parent_class)->finalize (obj);
}


GType unity_places_place_get_type (void) {
	static volatile gsize unity_places_place_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_place_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesPlaceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_place_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesPlace), 0, (GInstanceInitFunc) unity_places_place_instance_init, NULL };
		GType unity_places_place_type_id;
		unity_places_place_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityPlacesPlace", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_place_type_id__volatile, unity_places_place_type_id);
	}
	return unity_places_place_type_id__volatile;
}


static void unity_places_place_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesPlace * self;
	self = UNITY_PLACES_PLACE (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_DBUS_NAME:
		g_value_set_string (value, unity_places_place_get_dbus_name (self));
		break;
		case UNITY_PLACES_PLACE_DBUS_PATH:
		g_value_set_string (value, unity_places_place_get_dbus_path (self));
		break;
		case UNITY_PLACES_PLACE_N_ENTRIES:
		g_value_set_int (value, unity_places_place_get_n_entries (self));
		break;
		case UNITY_PLACES_PLACE_ONLINE:
		g_value_set_boolean (value, unity_places_place_get_online (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_place_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesPlace * self;
	self = UNITY_PLACES_PLACE (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_DBUS_NAME:
		unity_places_place_set_dbus_name (self, g_value_get_string (value));
		break;
		case UNITY_PLACES_PLACE_DBUS_PATH:
		unity_places_place_set_dbus_path (self, g_value_get_string (value));
		break;
		case UNITY_PLACES_PLACE_ONLINE:
		unity_places_place_set_online (self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
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



static void g_cclosure_user_marshal_VOID__BOXED (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__BOXED) (gpointer data1, gpointer arg_1, gpointer data2);
	register GMarshalFunc_VOID__BOXED callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 2);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__BOXED) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_boxed (param_values + 1), data2);
}



