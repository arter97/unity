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
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 */

#include "config.h"

#include "IndicatorObjectFactoryRemote.h"

#include "IndicatorObjectProxyRemote.h"
#include "IndicatorObjectEntryProxyRemote.h"
#include "IndicatorObjectEntryProxy.h"

#define S_NAME  "com.canonical.Unity.Panel.Service"
#define S_PATH  "/com/canonical/Unity/Panel/Service"
#define S_IFACE "com.canonical.Unity.Panel.Service"


// Enums

// Forwards
static void on_proxy_ready_cb (GObject      *source,
                               GAsyncResult *res,
                               gpointer      data);

static void on_proxy_signal_received (GDBusProxy *proxy,
                                      gchar      *sender_name,
                                      gchar      *signal_name,
                                      GVariant   *parameters,
                                      IndicatorObjectFactoryRemote *remote);

static void on_sync_ready_cb (GObject      *source,
                              GAsyncResult *res,
                              gpointer      data);

// Public Methods
IndicatorObjectFactoryRemote::IndicatorObjectFactoryRemote ()
{
  // We want to grab the Panel Service object. This is async, which is fine
  g_dbus_proxy_new_for_bus (G_BUS_TYPE_SESSION,
                            G_DBUS_PROXY_FLAGS_DO_NOT_LOAD_PROPERTIES,
                            NULL,
                            S_NAME,
                            S_PATH,
                            S_IFACE,
                            NULL,
                            on_proxy_ready_cb,
                            this);
}

IndicatorObjectFactoryRemote::~IndicatorObjectFactoryRemote ()
{
  if (G_IS_OBJECT (_proxy))
    g_object_unref (_proxy);
  _proxy = NULL;

  std::vector<IndicatorObjectProxy*>::iterator it;
  
  for (it = _indicators.begin(); it != _indicators.end(); it++)
  {
    IndicatorObjectProxyRemote *remote = static_cast<IndicatorObjectProxyRemote *> (*it);
    delete remote;
  }

  _indicators.erase (_indicators.begin (), _indicators.end ());
}

std::vector<IndicatorObjectProxy *>&
IndicatorObjectFactoryRemote::GetIndicatorObjects ()
{
  return _indicators;
}

void
IndicatorObjectFactoryRemote::ForceRefresh ()
{
}

void
IndicatorObjectFactoryRemote::OnRemoteProxyReady (GDBusProxy *proxy)
{
  _proxy = proxy;

  // Connect to interesting signals
  // FIXME: Add autorestarting bits here
 g_signal_connect (_proxy, "g-signal",
                   G_CALLBACK (on_proxy_signal_received), this);

  g_dbus_proxy_call (_proxy,
                     "Sync",
                     NULL,
                     G_DBUS_CALL_FLAGS_NONE,
                     -1,
                     NULL,
                     on_sync_ready_cb,
                     this);
}

void
IndicatorObjectFactoryRemote::OnShowMenuRequestReceived (const char *id, int x, int y, guint timestamp)
{
  // FIXME: Why doesn't this work if timestamp is valid?
  timestamp = 0;

  g_dbus_proxy_call (_proxy,
                     "ShowEntry",
                     g_variant_new ("(suiii)",
                                    id,
                                    timestamp,
                                    x,
                                    y,
                                    0),
                     G_DBUS_CALL_FLAGS_NONE,
                     -1,
                     NULL,
                     NULL,
                     NULL);
}

#if 0
void
IndicatorObjectFactoryRemote::OnRowAdded (DeeModelIter *iter)
{
  IndicatorObjectProxyRemote *remote;
  const gchar *name;
  const gchar *model_name;

  name = dee_model_get_string (_model, iter, COL_NAME);
  model_name = dee_model_get_string (_model, iter, COL_MODEL_NAME);

  remote = new IndicatorObjectProxyRemote (name, model_name);
  remote->OnShowMenuRequest.connect (sigc::mem_fun (this, &IndicatorObjectFactoryRemote::OnShowMenuRequestReceived));

  _indicators.push_back (remote);

  OnObjectAdded.emit (remote);
}
#endif

// We need to unset the last active entry and set the new one as active
void
IndicatorObjectFactoryRemote::OnEntryActivated (const char *entry_id)
{
  g_debug ("ENTRY ACTIVATED: %s", entry_id);
#if 0
  std::vector<IndicatorObjectProxy*>::iterator it;
  
  for (it = _indicators.begin(); it != _indicators.end(); it++)
  {
    IndicatorObjectProxyRemote *object = static_cast<IndicatorObjectProxyRemote *> (*it);
    std::vector<IndicatorObjectEntryProxy*>::iterator it;
  
    for (it = object->GetEntries ().begin(); it != object->GetEntries ().end(); it++)
    {
      IndicatorObjectEntryProxyRemote *entry = static_cast<IndicatorObjectEntryProxyRemote *> (*it);

      entry->SetActive (g_strcmp0 (entry_id, entry->GetId ()) == 0);
    }
  } 
#endif
}

void
IndicatorObjectFactoryRemote::Sync (GVariant *args)
{
  GVariantIter *iter;
  gchar        *indicator_id;
  gchar        *entry_id;
  gchar        *label;
  gboolean      label_sensitive;
  gboolean      label_visible;
  guint32       image_type;
  gchar        *image_data;
  gboolean      image_sensitive;
  gboolean      image_visible;

  g_variant_get (args, "(a(sssbbusbb))", &iter);
  while (g_variant_iter_loop (iter, "(sssbbusbb)",
                              &indicator_id,
                              &entry_id,
                              &label,
                              &label_sensitive,
                              &label_visible,
                              &image_type,
                              &image_data,
                              &image_sensitive,
                              &image_visible))
    {
      g_message ("%s: %s", indicator_id, entry_id);
    }

  g_variant_iter_free (iter);
}

//
// C callbacks, they just link to class methods and aren't interesting
//

static bool
reconnect_to_service (gpointer data)
{
  g_dbus_proxy_new_for_bus (G_BUS_TYPE_SESSION,
                            G_DBUS_PROXY_FLAGS_DO_NOT_LOAD_PROPERTIES,
                            NULL,
                            S_NAME,
                            S_PATH,
                            S_IFACE,
                            NULL,
                            on_proxy_ready_cb,
                            data);

  return false;
}

static void
on_proxy_ready_cb (GObject      *source,
                   GAsyncResult *res,
                   gpointer      data)
{
  IndicatorObjectFactoryRemote *remote = static_cast<IndicatorObjectFactoryRemote *> (data);
  GDBusProxy *proxy;
  GError     *error = NULL;
  static bool force_tried = false;
  char       *name_owner;

  proxy = g_dbus_proxy_new_for_bus_finish (res, &error);
  name_owner = g_dbus_proxy_get_name_owner (proxy);

  if (G_IS_DBUS_PROXY (proxy) && name_owner)
  {
    remote->OnRemoteProxyReady (G_DBUS_PROXY (proxy));
    g_free (name_owner);
    return;
  }
  else
  {
    if (force_tried)
    {
      printf ("\nWARNING: Unable to connect to the unity-panel-service %s\n",
              error ? error->message : "Unknown");
      if (error)
        g_error_free (error);
    }
    else
    {
      force_tried = true;
      GError *error = NULL;
      
      // Let's attempt to run it from where we expect it to be
      char *cmd = g_strdup_printf ("%s/lib/unity/unity-panel-service", PREFIXDIR);
      printf ("\nWARNING: Couldn't load panel from installed services, so trying to load panel from known location: %s\n", cmd);

      g_spawn_command_line_async (cmd, &error);
      if (error)
      {
        printf ("\nWARNING: Unable to launch remote service manually: %s\n", error->message);
        g_error_free (error);
        return;
      }

      // This is obviously hackish, but this part of the code is mostly hackish...
      g_timeout_add_seconds (2, (GSourceFunc)reconnect_to_service, remote);
      g_free (cmd);
    }
  }

  g_object_unref (proxy);
}

static void
on_proxy_signal_received (GDBusProxy *proxy,
                          gchar      *sender_name,
                          gchar      *signal_name,
                          GVariant   *parameters,
                          IndicatorObjectFactoryRemote *remote)
{
  if (g_strcmp0 (signal_name, "EntryActivated") == 0)
  {
    remote->OnEntryActivated (g_variant_get_string (g_variant_get_child_value (parameters, 0), NULL));
  }
}

static void
on_sync_ready_cb (GObject      *source,
                  GAsyncResult *res,
                  gpointer      data)
{
  IndicatorObjectFactoryRemote *remote = static_cast<IndicatorObjectFactoryRemote *> (data);
  GVariant     *args;
  GError       *error = NULL;

  args = g_dbus_proxy_call_finish ((GDBusProxy*)source, res, &error);

  if (args == NULL)
    {
      g_warning ("Unable to perform Sync() on panel service: %s", error->message);
      g_error_free (error);
      return;
    }

  remote->Sync (args);

  g_variant_unref (args);
}
