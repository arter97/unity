
#include <glib.h>
#include <gio/gio.h>
#include <gtk/gtk.h>

#include "panel-service.h"

static GDBusNodeInfo *introspection_data = NULL;

/*
 * typedef struct {
 *   gchar *indicator_id
 *   gchar *entry_id;
 *   gchar *label;
 *   bool   label_sensitive;
 *   bool   label_visible;
 *   uint32 icon_hint;
 *   gchar *icon_data;
 *   bool   icon_sensitive;
 *   bool   icon_visible;
 *
 * } EntryInfo;
 */

static const gchar introspection_xml[] =
  "<node>"
  "  <interface name='com.canonical.Unity.Panel.Service'>"
  ""
  "    <method name='Sync'>"
  "      <arg type='a(sssbbusbb)' name='state' direction='out'/>"
  "    </method>"
  ""
  "    <method name='SyncOne'>"
  "      <arg type='s' name='indicator_id' direction='in'/>"
  "      <arg type='a(sssbbusbb)' name='state' direction='out'/>"
  "    </method>"
  ""
  "    <method name='ShowEntry'>"
  "      <arg type='s' name='entry_id' direction='in'/>"
  "      <arg type='u' name='timestamp' direction='in'/>"
  "      <arg type='i' name='x' direction='in'/>"
  "      <arg type='i' name='y' direction='in'/>"
  "      <arg type='i' name='button' direction='in'/>"
  "    </method>"
  ""
  "    <signal name='EntryActivated'>"
  "     <arg type='s' name='entry_id' />"
  "    </signal>"
  ""
  "    <signal name='ReSync'>"
  "     <arg type='s' name='indicator_id' />"
  "    </signal>"
  ""
  "  </interface>"
  "</node>";

#define S_NAME  "com.canonical.Unity.Panel.Service"
#define S_PATH  "/com/canonical/Unity/Panel/Service"
#define S_IFACE "com.canonical.Unity.Panel.Service"

/* Forwards */
static void
handle_method_call (GDBusConnection       *connection,
                    const gchar           *sender,
                    const gchar           *object_path,
                    const gchar           *interface_name,
                    const gchar           *method_name,
                    GVariant              *parameters,
                    GDBusMethodInvocation *invocation,
                    gpointer               user_data);


static const GDBusInterfaceVTable interface_vtable =
{
  handle_method_call,
  NULL,
  NULL
};


/* Methods */

static void
handle_method_call (GDBusConnection       *connection,
                    const gchar           *sender,
                    const gchar           *object_path,
                    const gchar           *interface_name,
                    const gchar           *method_name,
                    GVariant              *parameters,
                    GDBusMethodInvocation *invocation,
                    gpointer               user_data)
{
  PanelService *service = PANEL_SERVICE (user_data);

  if (g_strcmp0 (method_name, "Sync") == 0)
    {
      g_dbus_method_invocation_return_value (invocation,
                                             panel_service_sync (service));
    }
  else if (g_strcmp0 (method_name, "SyncOne") == 0)
    {
      gchar *id;
      g_variant_get (parameters, "(s)", &id, NULL);
      g_dbus_method_invocation_return_value (invocation,
                                             panel_service_sync_one (service,
                                                                     id));
      g_free (id);
    }
  else if (g_strcmp0 (method_name, "ShowEntry") == 0)
    {
      gchar  *entry_id;
      guint32 timestamp;
      gint32  x;
      gint32  y;
      gint32  button;
      g_variant_get (parameters, "(suiii)", &entry_id, &timestamp, &x, &y, &button, NULL);

      g_debug ("button: %u", button);

      panel_service_show_entry (service, entry_id, timestamp, x, y, button);

      g_dbus_method_invocation_return_value (invocation, NULL);
      g_free (entry_id);
    }
}

static void
on_service_resync (PanelService *service, const gchar *indicator_id, GDBusConnection *connection)
{
  GError *error = NULL;
  g_dbus_connection_emit_signal (connection,
                                 S_NAME,
                                 S_PATH,
                                 S_IFACE,
                                 "ReSync",
                                 g_variant_new ("(s)", indicator_id),
                                 &error);

  if (error)
    {
      g_warning ("Unable to emit ReSync signal: %s", error->message);
      g_error_free (error);
    }
}

static void
on_service_entry_activated (PanelService    *service,
                            const gchar     *entry_id,
                            GDBusConnection *connection)
{
  GError *error = NULL;
  g_dbus_connection_emit_signal (connection,
                                 S_NAME,
                                 S_PATH,
                                 S_IFACE,
                                 "EntryActivated",
                                 g_variant_new ("(s)", entry_id),
                                 &error);

  if (error)
    {
      g_warning ("Unable to emit EntryActivated signal: %s", error->message);
      g_error_free (error);
    }
}
static void
on_bus_acquired (GDBusConnection *connection,
                 const gchar     *name,
                 gpointer         user_data)
{
  PanelService *service = PANEL_SERVICE (user_data);
  guint         reg_id;

  reg_id = g_dbus_connection_register_object (connection,
                                              S_PATH,
                                              introspection_data->interfaces[0],
                                              &interface_vtable,
                                              service,
                                              NULL,
                                              NULL);
  g_signal_connect (service, "re-sync",
                    G_CALLBACK (on_service_resync), connection);
  g_signal_connect (service, "entry-activated",
                    G_CALLBACK (on_service_entry_activated), connection);

  g_debug ("%s", G_STRFUNC);
  g_assert (reg_id > 0);
}

static void
on_name_acquired (GDBusConnection *connection,
                  const gchar     *name,
                  gpointer         user_data)
{
  g_debug ("Name Acquired");
}

static void
on_name_lost (GDBusConnection *connection,
              const gchar     *name,
              gpointer         user_data)
{
  g_debug ("%s", G_STRFUNC);
  gtk_main_quit ();
}

gint
main (gint argc, gchar **argv)
{
  PanelService *service;
  guint         owner_id;

  gtk_init (&argc, &argv);
	gtk_icon_theme_append_search_path (gtk_icon_theme_get_default(),
	                                   INDICATORICONDIR);

  introspection_data = g_dbus_node_info_new_for_xml (introspection_xml, NULL);
  g_assert (introspection_data != NULL);

  service = panel_service_get_default ();
  
  owner_id = g_bus_own_name (G_BUS_TYPE_SESSION,
                             S_NAME,
                             G_BUS_NAME_OWNER_FLAGS_NONE,
                             on_bus_acquired,
                             on_name_acquired,
                             on_name_lost,
                             service,
                             NULL);
  gtk_main ();

  g_bus_unown_name (owner_id);
  g_dbus_node_info_unref (introspection_data);
  g_object_unref (service);

  return 0;
}
