/* gesture-dispatcher.c generated by valac 0.9.8, the Vala compiler
 * generated from gesture-dispatcher.vala, do not modify */

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


#define UNITY_GESTURE_TYPE_DISPATCHER (unity_gesture_dispatcher_get_type ())
#define UNITY_GESTURE_DISPATCHER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_GESTURE_TYPE_DISPATCHER, UnityGestureDispatcher))
#define UNITY_GESTURE_DISPATCHER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_GESTURE_TYPE_DISPATCHER, UnityGestureDispatcherClass))
#define UNITY_GESTURE_IS_DISPATCHER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_GESTURE_TYPE_DISPATCHER))
#define UNITY_GESTURE_IS_DISPATCHER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_GESTURE_TYPE_DISPATCHER))
#define UNITY_GESTURE_DISPATCHER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_GESTURE_TYPE_DISPATCHER, UnityGestureDispatcherClass))

typedef struct _UnityGestureDispatcher UnityGestureDispatcher;
typedef struct _UnityGestureDispatcherClass UnityGestureDispatcherClass;
typedef struct _UnityGestureDispatcherPrivate UnityGestureDispatcherPrivate;

#define UNITY_GESTURE_TYPE_EVENT (unity_gesture_event_get_type ())
#define UNITY_GESTURE_EVENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_GESTURE_TYPE_EVENT, UnityGestureEvent))
#define UNITY_GESTURE_EVENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_GESTURE_TYPE_EVENT, UnityGestureEventClass))
#define UNITY_GESTURE_IS_EVENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_GESTURE_TYPE_EVENT))
#define UNITY_GESTURE_IS_EVENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_GESTURE_TYPE_EVENT))
#define UNITY_GESTURE_EVENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_GESTURE_TYPE_EVENT, UnityGestureEventClass))

typedef struct _UnityGestureEvent UnityGestureEvent;
typedef struct _UnityGestureEventClass UnityGestureEventClass;

struct _UnityGestureDispatcher {
	GObject parent_instance;
	UnityGestureDispatcherPrivate * priv;
};

struct _UnityGestureDispatcherClass {
	GObjectClass parent_class;
};


static gpointer unity_gesture_dispatcher_parent_class = NULL;

GType unity_gesture_dispatcher_get_type (void) G_GNUC_CONST;
enum  {
	UNITY_GESTURE_DISPATCHER_DUMMY_PROPERTY
};
UnityGestureDispatcher* unity_gesture_dispatcher_construct (GType object_type);
gpointer unity_gesture_event_ref (gpointer instance);
void unity_gesture_event_unref (gpointer instance);
GParamSpec* unity_gesture_param_spec_event (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_gesture_value_set_event (GValue* value, gpointer v_object);
void unity_gesture_value_take_event (GValue* value, gpointer v_object);
gpointer unity_gesture_value_get_event (const GValue* value);
GType unity_gesture_event_get_type (void) G_GNUC_CONST;


static void g_cclosure_user_marshal_VOID__UNITY_GESTURE_EVENT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);

UnityGestureDispatcher* unity_gesture_dispatcher_construct (GType object_type) {
	UnityGestureDispatcher * self;
	self = (UnityGestureDispatcher*) g_object_new (object_type, NULL);
	return self;
}


static void unity_gesture_dispatcher_class_init (UnityGestureDispatcherClass * klass) {
	unity_gesture_dispatcher_parent_class = g_type_class_peek_parent (klass);
	g_signal_new ("gesture", UNITY_GESTURE_TYPE_DISPATCHER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__UNITY_GESTURE_EVENT, G_TYPE_NONE, 1, UNITY_GESTURE_TYPE_EVENT);
}


static void unity_gesture_dispatcher_instance_init (UnityGestureDispatcher * self) {
}


GType unity_gesture_dispatcher_get_type (void) {
	static volatile gsize unity_gesture_dispatcher_type_id__volatile = 0;
	if (g_once_init_enter (&unity_gesture_dispatcher_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityGestureDispatcherClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_gesture_dispatcher_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityGestureDispatcher), 0, (GInstanceInitFunc) unity_gesture_dispatcher_instance_init, NULL };
		GType unity_gesture_dispatcher_type_id;
		unity_gesture_dispatcher_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityGestureDispatcher", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&unity_gesture_dispatcher_type_id__volatile, unity_gesture_dispatcher_type_id);
	}
	return unity_gesture_dispatcher_type_id__volatile;
}



static void g_cclosure_user_marshal_VOID__UNITY_GESTURE_EVENT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__UNITY_GESTURE_EVENT) (gpointer data1, gpointer arg_1, gpointer data2);
	register GMarshalFunc_VOID__UNITY_GESTURE_EVENT callback;
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
	callback = (GMarshalFunc_VOID__UNITY_GESTURE_EVENT) (marshal_data ? marshal_data : cc->callback);
	callback (data1, unity_gesture_value_get_event (param_values + 1), data2);
}



