/* unity-place-renderer.c generated by valac 0.9.5, the Vala compiler
 * generated from unity-place-renderer.vala, do not modify */

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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <clutk/clutk.h>
#include <dee.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>


#define UNITY_PLACE_TYPE_RENDERER (unity_place_renderer_get_type ())
#define UNITY_PLACE_RENDERER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACE_TYPE_RENDERER, UnityPlaceRenderer))
#define UNITY_PLACE_IS_RENDERER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACE_TYPE_RENDERER))
#define UNITY_PLACE_RENDERER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_PLACE_TYPE_RENDERER, UnityPlaceRendererIface))

typedef struct _UnityPlaceRenderer UnityPlaceRenderer;
typedef struct _UnityPlaceRendererIface UnityPlaceRendererIface;

struct _UnityPlaceRendererIface {
	GTypeInterface parent_iface;
	void (*set_models) (UnityPlaceRenderer* self, DeeModel* groups, DeeModel* results, GeeHashMap* hints);
};



GType unity_place_renderer_get_type (void) G_GNUC_CONST;
void unity_place_renderer_set_models (UnityPlaceRenderer* self, DeeModel* groups, DeeModel* results, GeeHashMap* hints);


static void g_cclosure_user_marshal_VOID__STRING_STRING (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);

void unity_place_renderer_set_models (UnityPlaceRenderer* self, DeeModel* groups, DeeModel* results, GeeHashMap* hints) {
	UNITY_PLACE_RENDERER_GET_INTERFACE (self)->set_models (self, groups, results, hints);
}


static void unity_place_renderer_base_init (UnityPlaceRendererIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
		g_signal_new ("activated", UNITY_PLACE_TYPE_RENDERER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__STRING_STRING, G_TYPE_NONE, 2, G_TYPE_STRING, G_TYPE_STRING);
	}
}


GType unity_place_renderer_get_type (void) {
	static volatile gsize unity_place_renderer_type_id__volatile = 0;
	if (g_once_init_enter (&unity_place_renderer_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlaceRendererIface), (GBaseInitFunc) unity_place_renderer_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType unity_place_renderer_type_id;
		unity_place_renderer_type_id = g_type_register_static (G_TYPE_INTERFACE, "UnityPlaceRenderer", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (unity_place_renderer_type_id, CTK_TYPE_ACTOR);
		g_once_init_leave (&unity_place_renderer_type_id__volatile, unity_place_renderer_type_id);
	}
	return unity_place_renderer_type_id__volatile;
}



static void g_cclosure_user_marshal_VOID__STRING_STRING (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__STRING_STRING) (gpointer data1, const char* arg_1, const char* arg_2, gpointer data2);
	register GMarshalFunc_VOID__STRING_STRING callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__STRING_STRING) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_string (param_values + 1), g_value_get_string (param_values + 2), data2);
}



