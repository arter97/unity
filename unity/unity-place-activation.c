/* unity-place-activation.c generated by valac 0.9.8, the Vala compiler
 * generated from unity-place-activation.vala, do not modify */

/*
 * Copyright (C) 2010 Canonical, Ltd.
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License
 * version 3.0 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3.0 for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Authored by Mikkel Kamstrup Erlandsen <mikkel.kamstrup@canonical.com>
 *
 */
/*
 * IMPLEMENTATION NOTE:
 * We want the generatedd C API to be nice and not too Vala-ish. We must
 * anticipate that place daemons consuming libunity will be written in
 * both Vala and C.
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <dbus/dbus.h>


#define UNITY_PLACE_TYPE_ACTIVATION (unity_place_activation_get_type ())
#define UNITY_PLACE_ACTIVATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACE_TYPE_ACTIVATION, UnityPlaceActivation))
#define UNITY_PLACE_IS_ACTIVATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACE_TYPE_ACTIVATION))
#define UNITY_PLACE_ACTIVATION_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_PLACE_TYPE_ACTIVATION, UnityPlaceActivationIface))

typedef struct _UnityPlaceActivation UnityPlaceActivation;
typedef struct _UnityPlaceActivationIface UnityPlaceActivationIface;
typedef struct _DBusObjectVTable _DBusObjectVTable;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _UnityPlaceActivationDBusProxy UnityPlaceActivationDBusProxy;
typedef DBusGProxyClass UnityPlaceActivationDBusProxyClass;
typedef struct _UnityPlaceActivationDBusProxyActivateData UnityPlaceActivationDBusProxyActivateData;

#define UNITY_PLACE_TYPE_ACTIVATION_STATUS (unity_place_activation_status_get_type ())

struct _UnityPlaceActivationIface {
	GTypeInterface parent_iface;
	void (*activate) (UnityPlaceActivation* self, const char* uri, GAsyncReadyCallback _callback_, gpointer _user_data_);
	guint32 (*activate_finish) (UnityPlaceActivation* self, GAsyncResult* _res_, GError** error);
};

struct _DBusObjectVTable {
	void (*register_object) (DBusConnection*, const char*, void*);
};

struct _UnityPlaceActivationDBusProxy {
	DBusGProxy parent_instance;
	gboolean disposed;
};

struct _UnityPlaceActivationDBusProxyActivateData {
	GAsyncReadyCallback _callback_;
	gpointer _user_data_;
	DBusPendingCall* pending;
};

typedef enum  {
	UNITY_PLACE_ACTIVATION_STATUS_NOT_ACTIVATED,
	UNITY_PLACE_ACTIVATION_STATUS_ACTIVATED_SHOW_DASH,
	UNITY_PLACE_ACTIVATION_STATUS_ACTIVATED_HIDE_DASH
} UnityPlaceActivationStatus;



UnityPlaceActivation* unity_place_activation_dbus_proxy_new (DBusGConnection* connection, const char* name, const char* path);
GType unity_place_activation_get_type (void) G_GNUC_CONST;
void unity_place_activation_activate (UnityPlaceActivation* self, const char* uri, GAsyncReadyCallback _callback_, gpointer _user_data_);
guint32 unity_place_activation_activate_finish (UnityPlaceActivation* self, GAsyncResult* _res_, GError** error);
static void _vala_dbus_register_object (DBusConnection* connection, const char* path, void* object);
static void _vala_dbus_unregister_object (gpointer connection, GObject* object);
void unity_place_activation_dbus_register_object (DBusConnection* connection, const char* path, void* object);
void _unity_place_activation_dbus_unregister (DBusConnection* connection, void* _user_data_);
DBusHandlerResult unity_place_activation_dbus_message (DBusConnection* connection, DBusMessage* message, void* object);
static DBusHandlerResult _dbus_unity_place_activation_introspect (UnityPlaceActivation* self, DBusConnection* connection, DBusMessage* message);
static DBusHandlerResult _dbus_unity_place_activation_property_get_all (UnityPlaceActivation* self, DBusConnection* connection, DBusMessage* message);
static DBusHandlerResult _dbus_unity_place_activation_activate (UnityPlaceActivation* self, DBusConnection* connection, DBusMessage* message);
static void _dbus_unity_place_activation_activate_ready (GObject * source_object, GAsyncResult * _res_, gpointer * _user_data_);
GType unity_place_activation_dbus_proxy_get_type (void) G_GNUC_CONST;
DBusHandlerResult unity_place_activation_dbus_proxy_filter (DBusConnection* connection, DBusMessage* message, void* user_data);
enum  {
	UNITY_PLACE_ACTIVATION_DBUS_PROXY_DUMMY_PROPERTY
};
static void unity_place_activation_dbus_proxy_activate_async (UnityPlaceActivation* self, const char* uri, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void unity_place_activation_dbus_proxy_activate_ready (DBusPendingCall* pending, void* user_data);
static guint32 unity_place_activation_dbus_proxy_activate_finish (UnityPlaceActivation* self, GAsyncResult* _res_, GError** error);
static void unity_place_activation_dbus_proxy_unity_place_activation__interface_init (UnityPlaceActivationIface* iface);
static void unity_place_activation_dbus_proxy_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_place_activation_dbus_proxy_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
GType unity_place_activation_status_get_type (void) G_GNUC_CONST;

static const DBusObjectPathVTable _unity_place_activation_dbus_path_vtable = {_unity_place_activation_dbus_unregister, unity_place_activation_dbus_message};
static const _DBusObjectVTable _unity_place_activation_dbus_vtable = {unity_place_activation_dbus_register_object};


void unity_place_activation_activate (UnityPlaceActivation* self, const char* uri, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UNITY_PLACE_ACTIVATION_GET_INTERFACE (self)->activate (self, uri, _callback_, _user_data_);
}


guint32 unity_place_activation_activate_finish (UnityPlaceActivation* self, GAsyncResult* _res_, GError** error) {
	return UNITY_PLACE_ACTIVATION_GET_INTERFACE (self)->activate_finish (self, _res_, error);
}


static void _vala_dbus_register_object (DBusConnection* connection, const char* path, void* object) {
	const _DBusObjectVTable * vtable;
	vtable = g_type_get_qdata (G_TYPE_FROM_INSTANCE (object), g_quark_from_static_string ("DBusObjectVTable"));
	if (vtable) {
		vtable->register_object (connection, path, object);
	} else {
		g_warning ("Object does not implement any D-Bus interface");
	}
}


static void _vala_dbus_unregister_object (gpointer connection, GObject* object) {
	char* path;
	path = g_object_steal_data ((GObject*) object, "dbus_object_path");
	dbus_connection_unregister_object_path (connection, path);
	g_free (path);
}


void _unity_place_activation_dbus_unregister (DBusConnection* connection, void* _user_data_) {
}


static DBusHandlerResult _dbus_unity_place_activation_introspect (UnityPlaceActivation* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessage* reply;
	DBusMessageIter iter;
	GString* xml_data;
	char** children;
	int i;
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &iter);
	xml_data = g_string_new ("<!DOCTYPE node PUBLIC \"-//freedesktop//DTD D-BUS Object Introspection 1.0//EN\" \"http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd\">\n");
	g_string_append (xml_data, "<node>\n<interface name=\"org.freedesktop.DBus.Introspectable\">\n  <method name=\"Introspect\">\n    <arg name=\"data\" direction=\"out\" type=\"s\"/>\n  </method>\n</interface>\n<interface name=\"org.freedesktop.DBus.Properties\">\n  <method name=\"Get\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"propname\" direction=\"in\" type=\"s\"/>\n    <arg name=\"value\" direction=\"out\" type=\"v\"/>\n  </method>\n  <method name=\"Set\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"propname\" direction=\"in\" type=\"s\"/>\n    <arg name=\"value\" direction=\"in\" type=\"v\"/>\n  </method>\n  <method name=\"GetAll\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"props\" direction=\"out\" type=\"a{sv}\"/>\n  </method>\n</interface>\n<interface name=\"com.canonical.Unity.Activation\">\n  <method name=\"Activate\">\n    <arg name=\"uri\" type=\"s\" direction=\"in\"/>\n    <arg name=\"result\" type=\"u\" direction=\"out\"/>\n  </method>\n</interface>\n");
	dbus_connection_list_registered (connection, g_object_get_data ((GObject *) self, "dbus_object_path"), &children);
	for (i = 0; children[i]; i++) {
		g_string_append_printf (xml_data, "<node name=\"%s\"/>\n", children[i]);
	}
	dbus_free_string_array (children);
	g_string_append (xml_data, "</node>\n");
	dbus_message_iter_append_basic (&iter, DBUS_TYPE_STRING, &xml_data->str);
	g_string_free (xml_data, TRUE);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


static DBusHandlerResult _dbus_unity_place_activation_property_get_all (UnityPlaceActivation* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessage* reply;
	DBusMessageIter iter, reply_iter, subiter;
	char* interface_name;
	const char* _tmp0_;
	if (strcmp (dbus_message_get_signature (message), "s")) {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
	dbus_message_iter_init (message, &iter);
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &reply_iter);
	dbus_message_iter_get_basic (&iter, &_tmp0_);
	dbus_message_iter_next (&iter);
	interface_name = g_strdup (_tmp0_);
	if (strcmp (interface_name, "com.canonical.Unity.Activation") == 0) {
		dbus_message_iter_open_container (&reply_iter, DBUS_TYPE_ARRAY, "{sv}", &subiter);
		dbus_message_iter_close_container (&reply_iter, &subiter);
	} else {
		dbus_message_unref (reply);
		reply = NULL;
	}
	g_free (interface_name);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


static DBusHandlerResult _dbus_unity_place_activation_activate (UnityPlaceActivation* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessageIter iter;
	char* uri = NULL;
	const char* _tmp1_;
	gpointer * _user_data_;
	if (strcmp (dbus_message_get_signature (message), "s")) {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
	dbus_message_iter_init (message, &iter);
	dbus_message_iter_get_basic (&iter, &_tmp1_);
	dbus_message_iter_next (&iter);
	uri = g_strdup (_tmp1_);
	_user_data_ = g_new0 (gpointer, 2);
	_user_data_[0] = dbus_connection_ref (connection);
	_user_data_[1] = dbus_message_ref (message);
	unity_place_activation_activate (self, uri, (GAsyncReadyCallback) _dbus_unity_place_activation_activate_ready, _user_data_);
	_g_free0 (uri);
	return DBUS_HANDLER_RESULT_HANDLED;
}


static void _dbus_unity_place_activation_activate_ready (GObject * source_object, GAsyncResult * _res_, gpointer * _user_data_) {
	DBusConnection * connection;
	DBusMessage * message;
	DBusMessageIter iter;
	GError* error;
	guint32 result;
	DBusMessage* reply;
	dbus_uint32_t _tmp2_;
	connection = _user_data_[0];
	message = _user_data_[1];
	error = NULL;
	result = unity_place_activation_activate_finish ((UnityPlaceActivation*) source_object, _res_, &error);
	if (error) {
		if (error->domain == DBUS_GERROR) {
			switch (error->code) {
				case DBUS_GERROR_FAILED:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.Failed", error->message);
				break;
				case DBUS_GERROR_NO_MEMORY:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.NoMemory", error->message);
				break;
				case DBUS_GERROR_SERVICE_UNKNOWN:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.ServiceUnknown", error->message);
				break;
				case DBUS_GERROR_NAME_HAS_NO_OWNER:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.NameHasNoOwner", error->message);
				break;
				case DBUS_GERROR_NO_REPLY:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.NoReply", error->message);
				break;
				case DBUS_GERROR_IO_ERROR:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.IOError", error->message);
				break;
				case DBUS_GERROR_BAD_ADDRESS:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.BadAddress", error->message);
				break;
				case DBUS_GERROR_NOT_SUPPORTED:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.NotSupported", error->message);
				break;
				case DBUS_GERROR_LIMITS_EXCEEDED:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.LimitsExceeded", error->message);
				break;
				case DBUS_GERROR_ACCESS_DENIED:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.AccessDenied", error->message);
				break;
				case DBUS_GERROR_AUTH_FAILED:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.AuthFailed", error->message);
				break;
				case DBUS_GERROR_NO_SERVER:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.NoServer", error->message);
				break;
				case DBUS_GERROR_TIMEOUT:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.Timeout", error->message);
				break;
				case DBUS_GERROR_NO_NETWORK:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.NoNetwork", error->message);
				break;
				case DBUS_GERROR_ADDRESS_IN_USE:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.AddressInUse", error->message);
				break;
				case DBUS_GERROR_DISCONNECTED:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.Disconnected", error->message);
				break;
				case DBUS_GERROR_INVALID_ARGS:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.InvalidArgs", error->message);
				break;
				case DBUS_GERROR_FILE_NOT_FOUND:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.FileNotFound", error->message);
				break;
				case DBUS_GERROR_FILE_EXISTS:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.FileExists", error->message);
				break;
				case DBUS_GERROR_UNKNOWN_METHOD:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.UnknownMethod", error->message);
				break;
				case DBUS_GERROR_TIMED_OUT:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.TimedOut", error->message);
				break;
				case DBUS_GERROR_MATCH_RULE_NOT_FOUND:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.MatchRuleNotFound", error->message);
				break;
				case DBUS_GERROR_MATCH_RULE_INVALID:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.MatchRuleInvalid", error->message);
				break;
				case DBUS_GERROR_SPAWN_EXEC_FAILED:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.Spawn.ExecFailed", error->message);
				break;
				case DBUS_GERROR_SPAWN_FORK_FAILED:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.Spawn.ForkFailed", error->message);
				break;
				case DBUS_GERROR_SPAWN_CHILD_EXITED:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.Spawn.ChildExited", error->message);
				break;
				case DBUS_GERROR_SPAWN_CHILD_SIGNALED:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.Spawn.ChildSignaled", error->message);
				break;
				case DBUS_GERROR_SPAWN_FAILED:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.Spawn.Failed", error->message);
				break;
				case DBUS_GERROR_UNIX_PROCESS_ID_UNKNOWN:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.UnixProcessIdUnknown", error->message);
				break;
				case DBUS_GERROR_INVALID_SIGNATURE:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.InvalidSignature", error->message);
				break;
				case DBUS_GERROR_INVALID_FILE_CONTENT:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.InvalidFileContent", error->message);
				break;
				case DBUS_GERROR_SELINUX_SECURITY_CONTEXT_UNKNOWN:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.SELinuxSecurityContextUnknown", error->message);
				break;
				case DBUS_GERROR_REMOTE_EXCEPTION:
				reply = dbus_message_new_error (message, "org.freedesktop.DBus.Error.RemoteException", error->message);
				break;
			}
		}
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return;
	}
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &iter);
	_tmp2_ = result;
	dbus_message_iter_append_basic (&iter, DBUS_TYPE_UINT32, &_tmp2_);
	dbus_connection_send (connection, reply, NULL);
	dbus_message_unref (reply);
	dbus_connection_unref (connection);
	dbus_message_unref (message);
	g_free (_user_data_);
}


DBusHandlerResult unity_place_activation_dbus_message (DBusConnection* connection, DBusMessage* message, void* object) {
	DBusHandlerResult result;
	result = DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	if (dbus_message_is_method_call (message, "org.freedesktop.DBus.Introspectable", "Introspect")) {
		result = _dbus_unity_place_activation_introspect (object, connection, message);
	} else if (dbus_message_is_method_call (message, "org.freedesktop.DBus.Properties", "GetAll")) {
		result = _dbus_unity_place_activation_property_get_all (object, connection, message);
	} else if (dbus_message_is_method_call (message, "com.canonical.Unity.Activation", "Activate")) {
		result = _dbus_unity_place_activation_activate (object, connection, message);
	}
	if (result == DBUS_HANDLER_RESULT_HANDLED) {
		return result;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


void unity_place_activation_dbus_register_object (DBusConnection* connection, const char* path, void* object) {
	if (!g_object_get_data (object, "dbus_object_path")) {
		g_object_set_data (object, "dbus_object_path", g_strdup (path));
		dbus_connection_register_object_path (connection, path, &_unity_place_activation_dbus_path_vtable, object);
		g_object_weak_ref (object, _vala_dbus_unregister_object, connection);
	}
}


static void unity_place_activation_base_init (UnityPlaceActivationIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
		g_type_set_qdata (UNITY_PLACE_TYPE_ACTIVATION, g_quark_from_static_string ("DBusObjectVTable"), (void*) (&_unity_place_activation_dbus_vtable));
	}
}


/**
   * UnityPlaceActivation:
   *
   * Interface for async launching of URIs. Instances implementing
   * this interface can be registered with a Unity.Place.Controller by
   * calling set_activation (activation) on the controller object.
   */
GType unity_place_activation_get_type (void) {
	static volatile gsize unity_place_activation_type_id__volatile = 0;
	if (g_once_init_enter (&unity_place_activation_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlaceActivationIface), (GBaseInitFunc) unity_place_activation_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType unity_place_activation_type_id;
		unity_place_activation_type_id = g_type_register_static (G_TYPE_INTERFACE, "UnityPlaceActivation", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (unity_place_activation_type_id, G_TYPE_OBJECT);
		g_type_set_qdata (unity_place_activation_type_id, g_quark_from_string ("ValaDBusInterfaceProxyType"), &unity_place_activation_dbus_proxy_get_type);
		g_once_init_leave (&unity_place_activation_type_id__volatile, unity_place_activation_type_id);
	}
	return unity_place_activation_type_id__volatile;
}


G_DEFINE_TYPE_EXTENDED (UnityPlaceActivationDBusProxy, unity_place_activation_dbus_proxy, DBUS_TYPE_G_PROXY, 0, G_IMPLEMENT_INTERFACE (UNITY_PLACE_TYPE_ACTIVATION, unity_place_activation_dbus_proxy_unity_place_activation__interface_init) );
UnityPlaceActivation* unity_place_activation_dbus_proxy_new (DBusGConnection* connection, const char* name, const char* path) {
	UnityPlaceActivation* self;
	self = g_object_new (unity_place_activation_dbus_proxy_get_type (), "connection", connection, "name", name, "path", path, "interface", "com.canonical.Unity.Activation", NULL);
	return self;
}


static GObject* unity_place_activation_dbus_proxy_construct (GType gtype, guint n_properties, GObjectConstructParam* properties) {
	GObject* self;
	DBusGConnection *connection;
	char* path;
	char* filter;
	self = G_OBJECT_CLASS (unity_place_activation_dbus_proxy_parent_class)->constructor (gtype, n_properties, properties);
	g_object_get (self, "connection", &connection, NULL);
	g_object_get (self, "path", &path, NULL);
	dbus_connection_add_filter (dbus_g_connection_get_connection (connection), unity_place_activation_dbus_proxy_filter, self, NULL);
	filter = g_strdup_printf ("type='signal',path='%s'", path);
	dbus_bus_add_match (dbus_g_connection_get_connection (connection), filter, NULL);
	dbus_g_connection_unref (connection);
	g_free (path);
	g_free (filter);
	return self;
}


DBusHandlerResult unity_place_activation_dbus_proxy_filter (DBusConnection* connection, DBusMessage* message, void* user_data) {
	if (dbus_message_has_path (message, dbus_g_proxy_get_path (user_data))) {
	}
	return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
}


static void unity_place_activation_dbus_proxy_dispose (GObject* self) {
	DBusGConnection *connection;
	if (((UnityPlaceActivationDBusProxy*) self)->disposed) {
		return;
	}
	((UnityPlaceActivationDBusProxy*) self)->disposed = TRUE;
	g_object_get (self, "connection", &connection, NULL);
	dbus_connection_remove_filter (dbus_g_connection_get_connection (connection), unity_place_activation_dbus_proxy_filter, self);
	G_OBJECT_CLASS (unity_place_activation_dbus_proxy_parent_class)->dispose (self);
}


static void unity_place_activation_dbus_proxy_class_init (UnityPlaceActivationDBusProxyClass* klass) {
	G_OBJECT_CLASS (klass)->constructor = unity_place_activation_dbus_proxy_construct;
	G_OBJECT_CLASS (klass)->dispose = unity_place_activation_dbus_proxy_dispose;
	G_OBJECT_CLASS (klass)->get_property = unity_place_activation_dbus_proxy_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_place_activation_dbus_proxy_set_property;
}


static void unity_place_activation_dbus_proxy_init (UnityPlaceActivationDBusProxy* self) {
}


static void unity_place_activation_dbus_proxy_activate_async (UnityPlaceActivation* self, const char* uri, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	DBusGConnection *_connection;
	DBusMessage *_message;
	DBusPendingCall *_pending;
	DBusMessageIter _iter;
	const char* _tmp135_;
	UnityPlaceActivationDBusProxyActivateData* _data_;
	_message = dbus_message_new_method_call (dbus_g_proxy_get_bus_name ((DBusGProxy*) self), dbus_g_proxy_get_path ((DBusGProxy*) self), "com.canonical.Unity.Activation", "Activate");
	dbus_message_iter_init_append (_message, &_iter);
	_tmp135_ = uri;
	dbus_message_iter_append_basic (&_iter, DBUS_TYPE_STRING, &_tmp135_);
	g_object_get (self, "connection", &_connection, NULL);
	dbus_connection_send_with_reply (dbus_g_connection_get_connection (_connection), _message, &_pending, -1);
	dbus_g_connection_unref (_connection);
	dbus_message_unref (_message);
	_data_ = g_slice_new0 (UnityPlaceActivationDBusProxyActivateData);
	_data_->_callback_ = _callback_;
	_data_->_user_data_ = _user_data_;
	_data_->pending = _pending;
	dbus_pending_call_set_notify (_pending, unity_place_activation_dbus_proxy_activate_ready, _data_, NULL);
}


static void unity_place_activation_dbus_proxy_activate_ready (DBusPendingCall* pending, void* user_data) {
	UnityPlaceActivationDBusProxyActivateData* _data_;
	GObject * _obj_;
	GSimpleAsyncResult * _res_;
	_data_ = user_data;
	_obj_ = g_object_newv (G_TYPE_OBJECT, 0, NULL);
	_res_ = g_simple_async_result_new (_obj_, _data_->_callback_, _data_->_user_data_, _data_);
	g_simple_async_result_complete (_res_);
	g_object_unref (_obj_);
	g_object_unref (_res_);
	g_slice_free (UnityPlaceActivationDBusProxyActivateData, _data_);
	dbus_pending_call_unref (pending);
}


static guint32 unity_place_activation_dbus_proxy_activate_finish (UnityPlaceActivation* self, GAsyncResult* _res_, GError** error) {
	UnityPlaceActivationDBusProxyActivateData* _data_;
	DBusError _dbus_error;
	DBusMessage *_reply;
	DBusMessageIter _iter;
	guint32 _result;
	dbus_uint32_t _tmp139_;
	_data_ = g_simple_async_result_get_source_tag ((GSimpleAsyncResult *) _res_);
	dbus_error_init (&_dbus_error);
	_reply = dbus_pending_call_steal_reply (_data_->pending);
	dbus_set_error_from_message (&_dbus_error, _reply);
	if (dbus_error_is_set (&_dbus_error)) {
		GQuark _edomain;
		gint _ecode;
		if (strstr (_dbus_error.name, "org.freedesktop.DBus.Error") == _dbus_error.name) {
			const char* _tmp137_;
			_edomain = DBUS_GERROR;
			_tmp137_ = _dbus_error.name + 27;
			if (strcmp (_tmp137_, "Failed") == 0) {
				_ecode = DBUS_GERROR_FAILED;
			} else if (strcmp (_tmp137_, "NoMemory") == 0) {
				_ecode = DBUS_GERROR_NO_MEMORY;
			} else if (strcmp (_tmp137_, "ServiceUnknown") == 0) {
				_ecode = DBUS_GERROR_SERVICE_UNKNOWN;
			} else if (strcmp (_tmp137_, "NameHasNoOwner") == 0) {
				_ecode = DBUS_GERROR_NAME_HAS_NO_OWNER;
			} else if (strcmp (_tmp137_, "NoReply") == 0) {
				_ecode = DBUS_GERROR_NO_REPLY;
			} else if (strcmp (_tmp137_, "IOError") == 0) {
				_ecode = DBUS_GERROR_IO_ERROR;
			} else if (strcmp (_tmp137_, "BadAddress") == 0) {
				_ecode = DBUS_GERROR_BAD_ADDRESS;
			} else if (strcmp (_tmp137_, "NotSupported") == 0) {
				_ecode = DBUS_GERROR_NOT_SUPPORTED;
			} else if (strcmp (_tmp137_, "LimitsExceeded") == 0) {
				_ecode = DBUS_GERROR_LIMITS_EXCEEDED;
			} else if (strcmp (_tmp137_, "AccessDenied") == 0) {
				_ecode = DBUS_GERROR_ACCESS_DENIED;
			} else if (strcmp (_tmp137_, "AuthFailed") == 0) {
				_ecode = DBUS_GERROR_AUTH_FAILED;
			} else if (strcmp (_tmp137_, "NoServer") == 0) {
				_ecode = DBUS_GERROR_NO_SERVER;
			} else if (strcmp (_tmp137_, "Timeout") == 0) {
				_ecode = DBUS_GERROR_TIMEOUT;
			} else if (strcmp (_tmp137_, "NoNetwork") == 0) {
				_ecode = DBUS_GERROR_NO_NETWORK;
			} else if (strcmp (_tmp137_, "AddressInUse") == 0) {
				_ecode = DBUS_GERROR_ADDRESS_IN_USE;
			} else if (strcmp (_tmp137_, "Disconnected") == 0) {
				_ecode = DBUS_GERROR_DISCONNECTED;
			} else if (strcmp (_tmp137_, "InvalidArgs") == 0) {
				_ecode = DBUS_GERROR_INVALID_ARGS;
			} else if (strcmp (_tmp137_, "FileNotFound") == 0) {
				_ecode = DBUS_GERROR_FILE_NOT_FOUND;
			} else if (strcmp (_tmp137_, "FileExists") == 0) {
				_ecode = DBUS_GERROR_FILE_EXISTS;
			} else if (strcmp (_tmp137_, "UnknownMethod") == 0) {
				_ecode = DBUS_GERROR_UNKNOWN_METHOD;
			} else if (strcmp (_tmp137_, "TimedOut") == 0) {
				_ecode = DBUS_GERROR_TIMED_OUT;
			} else if (strcmp (_tmp137_, "MatchRuleNotFound") == 0) {
				_ecode = DBUS_GERROR_MATCH_RULE_NOT_FOUND;
			} else if (strcmp (_tmp137_, "MatchRuleInvalid") == 0) {
				_ecode = DBUS_GERROR_MATCH_RULE_INVALID;
			} else if (strcmp (_tmp137_, "Spawn.ExecFailed") == 0) {
				_ecode = DBUS_GERROR_SPAWN_EXEC_FAILED;
			} else if (strcmp (_tmp137_, "Spawn.ForkFailed") == 0) {
				_ecode = DBUS_GERROR_SPAWN_FORK_FAILED;
			} else if (strcmp (_tmp137_, "Spawn.ChildExited") == 0) {
				_ecode = DBUS_GERROR_SPAWN_CHILD_EXITED;
			} else if (strcmp (_tmp137_, "Spawn.ChildSignaled") == 0) {
				_ecode = DBUS_GERROR_SPAWN_CHILD_SIGNALED;
			} else if (strcmp (_tmp137_, "Spawn.Failed") == 0) {
				_ecode = DBUS_GERROR_SPAWN_FAILED;
			} else if (strcmp (_tmp137_, "UnixProcessIdUnknown") == 0) {
				_ecode = DBUS_GERROR_UNIX_PROCESS_ID_UNKNOWN;
			} else if (strcmp (_tmp137_, "InvalidSignature") == 0) {
				_ecode = DBUS_GERROR_INVALID_SIGNATURE;
			} else if (strcmp (_tmp137_, "InvalidFileContent") == 0) {
				_ecode = DBUS_GERROR_INVALID_FILE_CONTENT;
			} else if (strcmp (_tmp137_, "SELinuxSecurityContextUnknown") == 0) {
				_ecode = DBUS_GERROR_SELINUX_SECURITY_CONTEXT_UNKNOWN;
			} else if (strcmp (_tmp137_, "RemoteException") == 0) {
				_ecode = DBUS_GERROR_REMOTE_EXCEPTION;
			}
		}
		g_set_error (error, _edomain, _ecode, "%s", _dbus_error.message);
		dbus_error_free (&_dbus_error);
		return 0U;
	}
	if (strcmp (dbus_message_get_signature (_reply), "u")) {
		g_set_error (error, DBUS_GERROR, DBUS_GERROR_INVALID_SIGNATURE, "Invalid signature, expected \"%s\", got \"%s\"", "u", dbus_message_get_signature (_reply));
		dbus_message_unref (_reply);
		return 0U;
	}
	dbus_message_iter_init (_reply, &_iter);
	dbus_message_iter_get_basic (&_iter, &_tmp139_);
	dbus_message_iter_next (&_iter);
	_result = _tmp139_;
	dbus_message_unref (_reply);
	return _result;
}


static void unity_place_activation_dbus_proxy_unity_place_activation__interface_init (UnityPlaceActivationIface* iface) {
	iface->activate = unity_place_activation_dbus_proxy_activate_async;
	iface->activate_finish = unity_place_activation_dbus_proxy_activate_finish;
}


static void unity_place_activation_dbus_proxy_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
}


static void unity_place_activation_dbus_proxy_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
}


/**
   * Enumeration of return values for Activation.activate().
   */
GType unity_place_activation_status_get_type (void) {
	static volatile gsize unity_place_activation_status_type_id__volatile = 0;
	if (g_once_init_enter (&unity_place_activation_status_type_id__volatile)) {
		static const GEnumValue values[] = {{UNITY_PLACE_ACTIVATION_STATUS_NOT_ACTIVATED, "UNITY_PLACE_ACTIVATION_STATUS_NOT_ACTIVATED", "not-activated"}, {UNITY_PLACE_ACTIVATION_STATUS_ACTIVATED_SHOW_DASH, "UNITY_PLACE_ACTIVATION_STATUS_ACTIVATED_SHOW_DASH", "activated-show-dash"}, {UNITY_PLACE_ACTIVATION_STATUS_ACTIVATED_HIDE_DASH, "UNITY_PLACE_ACTIVATION_STATUS_ACTIVATED_HIDE_DASH", "activated-hide-dash"}, {0, NULL, NULL}};
		GType unity_place_activation_status_type_id;
		unity_place_activation_status_type_id = g_enum_register_static ("UnityPlaceActivationStatus", values);
		g_once_init_leave (&unity_place_activation_status_type_id__volatile, unity_place_activation_status_type_id);
	}
	return unity_place_activation_status_type_id__volatile;
}




