#include <glib-object.h>

#include "test_service_scope.h"
#include "test_service_model.h"
#include "test_service_hud.h"
#include "test_service_panel.h"
#include "test_service_gdbus_wrapper.h"

static void on_bus_aquired(GDBusConnection* conn, const gchar* name, gpointer null);
static void handle_method_call(GDBusConnection       *connection,
                               const gchar           *sender,
                               const gchar           *object_path,
                               const gchar           *interface_name,
                               const gchar           *method_name,
                               GVariant              *parameters,
                               GDBusMethodInvocation *invocation,
                               gpointer               user_data);


static GDBusNodeInfo* introspection_data = NULL;
static const gchar introspection_xml[] =
  "<node>"
  "  <interface name='com.canonical.Unity.Test'>"
  ""
  "    <method name='Exit'>"
  "    </method>"
  ""
  "  </interface>"
  "</node>";
static const GDBusInterfaceVTable interface_vtable = 
{
  handle_method_call,
  NULL,
  NULL
};

static gchar* scope_id = "testscope1";

static GOptionEntry entries[] =
{
  { "scope-id", 's', 0, G_OPTION_ARG_STRING, &scope_id, "Test scope id (/com/canonical/unity/scope/SCOPE_NAME)", "SCOPE_NAME" },
  { NULL }
};


static GMainLoop* loop_ = NULL;
static ServiceScope* scope_ = NULL;
static ServiceModel* model_ = NULL;
static ServiceHud* hud_ = NULL;
static ServicePanel* panel_ = NULL;
static ServiceGDBusWrapper* gdbus_wrapper_ = NULL;
gint
main(gint argc, gchar** argv)
{
#if G_ENCODE_VERSION (GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION) <= GLIB_VERSION_2_34
  g_type_init();
#endif

  GError *error = NULL;
  GOptionContext *context;
  context = g_option_context_new ("- DBus tests");
  g_option_context_add_main_entries (context, entries, NULL);
  if (!g_option_context_parse (context, &argc, &argv, &error))
  {
    g_print ("option parsing failed: %s\n", error->message);
    return 1;
  }

  loop_ = g_main_loop_new(NULL, FALSE);

  scope_ = service_scope_new(scope_id);
  model_ = service_model_new();
  hud_ = service_hud_new();
  panel_ = service_panel_new();
  gdbus_wrapper_ = service_gdbus_wrapper_new();

  g_bus_own_name(G_BUS_TYPE_SESSION,
                 "com.canonical.Unity.Test",
                 G_BUS_NAME_OWNER_FLAGS_NONE,
                 on_bus_aquired,
                 NULL,
                 NULL,
                 NULL,
                 NULL);

  g_main_loop_run(loop_);
  g_main_loop_unref(loop_);

  //g_object_unref(model_);
  g_object_unref(hud_);
  g_object_unref(panel_);
  g_object_unref(scope_);
  g_dbus_node_info_unref(introspection_data);

  return 0;
}

static void
on_bus_aquired(GDBusConnection* conn, const gchar* name, gpointer null)
{
  introspection_data = g_dbus_node_info_new_for_xml(introspection_xml, NULL);
  g_dbus_connection_register_object(conn,
                                    "/com/canonical/unity/test/controller",
                                    introspection_data->interfaces[0],
                                    &interface_vtable,
                                    NULL,
                                    NULL,
                                    NULL);
}

static void
handle_method_call(GDBusConnection       *connection,
                   const gchar           *sender,
                   const gchar           *object_path,
                   const gchar           *interface_name,
                   const gchar           *method_name,
                   GVariant              *parameters,
                   GDBusMethodInvocation *invocation,
                   gpointer               user_data)
{
  if (g_strcmp0(method_name, "Exit") == 0)
  {
    g_main_loop_quit(loop_);
  }
}
