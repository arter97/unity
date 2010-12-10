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
 * Authored by: Jason Smith <jason.smith@canonical.com>
 */

#include "Nux/Nux.h"
#include "Nux/BaseWindow.h"

#include "BamfLauncherIcon.h"
#include "Launcher.h"
#include "PluginAdapter.h"
#include "FavoriteStore.h"

#include <gio/gdesktopappinfo.h>
#include <libindicator/indicator-desktop-shortcuts.h>
#include <core/core.h>
#include <core/atoms.h>

struct _ShortcutData
{
  BamfLauncherIcon *self;
  IndicatorDesktopShortcuts *shortcuts;
  char *nick;
};
typedef struct _ShortcutData ShortcutData;
static void shortcut_data_destroy (ShortcutData *data)
{
  g_object_unref (data->shortcuts);
  g_free (data->nick);
  g_slice_free (ShortcutData, data);
}

static void shortcut_activated (DbusmenuMenuitem* _sender, guint timestamp, gpointer userdata)
{
  ShortcutData *data = (ShortcutData *)userdata;
  indicator_desktop_shortcuts_nick_exec (data->shortcuts, data->nick);
}

BamfLauncherIcon::BamfLauncherIcon (Launcher* IconManager, BamfApplication *app, CompScreen *screen)
:   SimpleLauncherIcon(IconManager)
{
  m_App = app;
  m_Screen = screen;
  _menu_desktop_shortcuts = NULL;
  char *icon_name = bamf_view_get_icon (BAMF_VIEW (m_App));

  SetTooltipText (bamf_view_get_name (BAMF_VIEW (app)));
  SetIconName (icon_name);
  SetIconType (LAUNCHER_ICON_TYPE_APPLICATION);

  if (bamf_view_is_sticky (BAMF_VIEW (m_App)))
    SetQuirk (LAUNCHER_ICON_QUIRK_VISIBLE, true);
  else
    SetQuirk (LAUNCHER_ICON_QUIRK_VISIBLE, bamf_view_user_visible (BAMF_VIEW (m_App)));

  SetQuirk (LAUNCHER_ICON_QUIRK_ACTIVE, bamf_view_is_active (BAMF_VIEW (m_App)));
  SetQuirk (LAUNCHER_ICON_QUIRK_RUNNING, bamf_view_is_running (BAMF_VIEW (m_App)));

  g_free (icon_name);

  g_signal_connect (app, "child-removed", (GCallback) &BamfLauncherIcon::OnChildRemoved, this);
  g_signal_connect (app, "child-added", (GCallback) &BamfLauncherIcon::OnChildAdded, this);
  g_signal_connect (app, "urgent-changed", (GCallback) &BamfLauncherIcon::OnUrgentChanged, this);
  g_signal_connect (app, "running-changed", (GCallback) &BamfLauncherIcon::OnRunningChanged, this);
  g_signal_connect (app, "active-changed", (GCallback) &BamfLauncherIcon::OnActiveChanged, this);
  g_signal_connect (app, "user-visible-changed", (GCallback) &BamfLauncherIcon::OnUserVisibleChanged, this);
  g_signal_connect (app, "closed", (GCallback) &BamfLauncherIcon::OnClosed, this);

  g_object_ref (m_App);

  EnsureWindowState ();
  UpdateMenus ();
}

BamfLauncherIcon::~BamfLauncherIcon()
{
  g_signal_handlers_disconnect_by_func (m_App, (void *) &BamfLauncherIcon::OnChildRemoved,       this);
  g_signal_handlers_disconnect_by_func (m_App, (void *) &BamfLauncherIcon::OnChildAdded,         this);
  g_signal_handlers_disconnect_by_func (m_App, (void *) &BamfLauncherIcon::OnUrgentChanged,      this);
  g_signal_handlers_disconnect_by_func (m_App, (void *) &BamfLauncherIcon::OnRunningChanged,     this);
  g_signal_handlers_disconnect_by_func (m_App, (void *) &BamfLauncherIcon::OnActiveChanged,      this);
  g_signal_handlers_disconnect_by_func (m_App, (void *) &BamfLauncherIcon::OnUserVisibleChanged, this);
  g_signal_handlers_disconnect_by_func (m_App, (void *) &BamfLauncherIcon::OnClosed,             this);

  g_object_unref (m_App);
}

bool 
BamfLauncherIcon::IsSticky ()
{
  return bamf_view_is_sticky (BAMF_VIEW (m_App));
}

const char* 
BamfLauncherIcon::DesktopFile ()
{
  return bamf_application_get_desktop_file (m_App);
}

void
BamfLauncherIcon::AddProperties (GVariantBuilder *builder)
{
  LauncherIcon::AddProperties (builder);

  g_variant_builder_add (builder, "{sv}", "desktop-file", g_variant_new_string (bamf_application_get_desktop_file (m_App)));
  
  GList *children, *l;
  BamfView *view;
  
  children = bamf_view_get_children (BAMF_VIEW (m_App));
  GVariant* xids[(int) g_list_length (children)];
  
  int i = 0;
  for (l = children; l; l = l->next)
  {
    view = (BamfView *) l->data;
    
    if (BAMF_IS_WINDOW (view))
    {
      xids[i++] = g_variant_new_uint32 (bamf_window_get_xid (BAMF_WINDOW (view)));
    }    
  }
  g_list_free (children);
  g_variant_builder_add (builder, "{sv}", "xids", g_variant_new_array (G_VARIANT_TYPE_UINT32, xids, i));
}

bool
BamfLauncherIcon::IconOwnsWindow (Window w)
{
  GList *children, *l;
  BamfView *view;
  bool owns = false;

  children = bamf_view_get_children (BAMF_VIEW (m_App));

  for (l = children; l; l = l->next)
  {
    view = (BamfView *) l->data;

    if (BAMF_IS_WINDOW (view))
    {
      guint32 xid = bamf_window_get_xid (BAMF_WINDOW (view));

      if (xid == w)
      {
        owns = true;
        break;
      }
    }
  }

  g_list_free (children);
  return owns;
}

void
BamfLauncherIcon::OpenInstance ()
{
  GDesktopAppInfo *appInfo;
  GError *error = NULL;

  appInfo = g_desktop_app_info_new_from_filename (bamf_application_get_desktop_file (BAMF_APPLICATION (m_App)));
  g_app_info_launch (G_APP_INFO (appInfo), NULL, NULL, &error);
  g_object_unref (appInfo);

  if (error)
  {
    g_warning ("%s\n", error->message);
    g_error_free (error);
  }

  UpdateQuirkTime (LAUNCHER_ICON_QUIRK_STARTING);
}

void
BamfLauncherIcon::Focus ()
{
  GList *children, *l;
  BamfView *view;

  children = bamf_view_get_children (BAMF_VIEW (m_App));

  CompWindowList windows;

  /* get the list of windows */
  for (l = children; l; l = l->next)
  {
    view = (BamfView *) l->data;

    if (BAMF_IS_WINDOW (view))
    {
      guint32 xid = bamf_window_get_xid (BAMF_WINDOW (view));

      CompWindow *window = m_Screen->findWindow ((Window) xid);

      if (window)
        windows.push_back (window);
    }
  }

  if (windows.empty ())
    return;

  /* sort the list */
  CompWindowList tmp;
  CompWindowList::iterator it;
  for (it = m_Screen->windows ().begin (); it != m_Screen->windows ().end (); it++)
  {
    if (std::find (windows.begin (), windows.end (), *it) != windows.end ())
      tmp.push_back (*it);
  }
  windows = tmp;


  /* filter based on workspace */
  bool any_on_current = false;

  for (it = windows.begin (); it != windows.end (); it++)
  {
    if ((*it)->defaultViewport () == m_Screen->vp ())
    {
      any_on_current = true;
      break;
    }
  }

  /* activate our windows */

  if (any_on_current)
  {
    for (it = windows.begin (); it != windows.end (); it++)
    {
      if ((*it)->defaultViewport () == m_Screen->vp ())
      {
        (*it)->activate ();
      }
    }
  }
  else
  {
    (*(windows.rbegin ()))->activate ();
  }

  g_list_free (children);
}

void
BamfLauncherIcon::Spread ()
{
  BamfView *view;
  GList *children, *l;
  children = bamf_view_get_children (BAMF_VIEW (m_App));

  std::list<Window> windowList;
  for (l = children; l; l = l->next)
  {
    view = (BamfView *) l->data;

    if (BAMF_IS_WINDOW (view))
    {
      guint32 xid = bamf_window_get_xid (BAMF_WINDOW (view));

      windowList.push_back ((Window) xid);
    }
  }

  if (windowList.size () > 1)
  {
    std::string *match = PluginAdapter::Default ()->MatchStringForXids (&windowList);
    PluginAdapter::Default ()->InitiateScale (match);
    delete match;
  }

  g_list_free (children);
}

void
BamfLauncherIcon::OnMouseClick (int button)
{
  if (button != 1)
    return;

  bool active, running;

  active = bamf_view_is_active (BAMF_VIEW (m_App));
  running = bamf_view_is_running (BAMF_VIEW (m_App));
  
  if (!running)
  {
    if (GetQurk (LAUNCHER_ICON_QUIRK_STARTING))
      return;
    SetQuirk (LAUNCHER_ICON_QUIRK_STARTING, true);
    OpenInstance ();
    return;
  }
  else if (active)
    Spread ();
  else
    Focus ();
}

void
BamfLauncherIcon::OnClosed (BamfView *view, gpointer data)
{
  BamfLauncherIcon *self = (BamfLauncherIcon *) data;

  if (!bamf_view_is_sticky (BAMF_VIEW (self->m_App)))
    self->Remove ();
}

void
BamfLauncherIcon::OnUserVisibleChanged (BamfView *view, gboolean visible, gpointer data)
{
  BamfLauncherIcon *self = (BamfLauncherIcon *) data;

  if (!bamf_view_is_sticky (BAMF_VIEW (self->m_App)))
    self->SetQuirk (LAUNCHER_ICON_QUIRK_VISIBLE, visible);
}

void
BamfLauncherIcon::OnRunningChanged (BamfView *view, gboolean running, gpointer data)
{
  BamfLauncherIcon *self = (BamfLauncherIcon *) data;
  self->SetQuirk (LAUNCHER_ICON_QUIRK_RUNNING, running);

  if (running)
  {
    self->EnsureWindowState ();
    self->UpdateIconGeometries (self->GetCenter ());
  }
}

void
BamfLauncherIcon::OnActiveChanged (BamfView *view, gboolean active, gpointer data)
{
  BamfLauncherIcon *self = (BamfLauncherIcon *) data;
  self->SetQuirk (LAUNCHER_ICON_QUIRK_ACTIVE, active);
}

void
BamfLauncherIcon::OnUrgentChanged (BamfView *view, gboolean urgent, gpointer data)
{
  BamfLauncherIcon *self = (BamfLauncherIcon *) data;
  self->SetQuirk (LAUNCHER_ICON_QUIRK_URGENT, urgent);
}

void
BamfLauncherIcon::EnsureWindowState ()
{
  GList *children, *l;
  int count = 0;

  children = bamf_view_get_children (BAMF_VIEW (m_App));
  for (l = children; l; l = l->next)
  {
    if (BAMF_IS_WINDOW (l->data))
      count++;
  }

  SetRelatedWindows (count);

  g_list_free (children);
}

void
BamfLauncherIcon::OnChildAdded (BamfView *view, BamfView *child, gpointer data)
{
  BamfLauncherIcon *self = (BamfLauncherIcon*) data;
  self->EnsureWindowState ();
  self->UpdateMenus ();
  self->UpdateIconGeometries (self->GetCenter ());
}

void
BamfLauncherIcon::OnChildRemoved (BamfView *view, BamfView *child, gpointer data)
{
  BamfLauncherIcon *self = (BamfLauncherIcon*) data;
  self->EnsureWindowState ();
}

void
BamfLauncherIcon::UpdateMenus ()
{
  GList *children, *l;
  IndicatorDesktopShortcuts *desktop_shortcuts;

  children = bamf_view_get_children (BAMF_VIEW (m_App));
  for (l = children; l; l = l->next)
  {
    if (!BAMF_IS_INDICATOR (l->data))
      continue;

    BamfIndicator *indicator = BAMF_INDICATOR (l->data);
    std::string path = bamf_indicator_get_dbus_menu_path (indicator);

    // we already have this
    if (_menu_clients.find (path) != _menu_clients.end ())
      continue;

    DbusmenuClient *client = dbusmenu_client_new (bamf_indicator_get_remote_address (indicator), path.c_str ());
    _menu_clients[path] = client;
  }

  g_list_free (children);

  // make a client for desktop file actions
  if (!DBUSMENU_IS_MENUITEM (_menu_desktop_shortcuts) &&
      bamf_application_get_desktop_file (m_App) != NULL)
  {

    DbusmenuMenuitem *root = dbusmenu_menuitem_new ();
    dbusmenu_menuitem_set_root (root, TRUE);
    desktop_shortcuts = indicator_desktop_shortcuts_new (bamf_application_get_desktop_file (m_App),
                                                         "Unity");
    const gchar **nicks = indicator_desktop_shortcuts_get_nicks (desktop_shortcuts);

    int index = 0;
    if (nicks) {
      while (((gpointer*) nicks)[index]) {
        const char* name;
        DbusmenuMenuitem *item;
        name = g_strdup (indicator_desktop_shortcuts_nick_get_name (desktop_shortcuts,
                                                                    nicks[index]));
        ShortcutData *data = g_slice_new0 (ShortcutData);
        data->self = this;
        data->shortcuts = INDICATOR_DESKTOP_SHORTCUTS (g_object_ref (desktop_shortcuts));
        data->nick = g_strdup (nicks[index]);

        item = dbusmenu_menuitem_new ();
        dbusmenu_menuitem_property_set (item, DBUSMENU_MENUITEM_PROP_LABEL, name);
        dbusmenu_menuitem_property_set_bool (item, DBUSMENU_MENUITEM_PROP_ENABLED, TRUE);
        dbusmenu_menuitem_property_set_bool (item, DBUSMENU_MENUITEM_PROP_VISIBLE, TRUE);
        g_signal_connect_data (item, "item-activated",
                              (GCallback) shortcut_activated, (gpointer) data,
                              (GClosureNotify) shortcut_data_destroy, (GConnectFlags)0);

        dbusmenu_menuitem_child_append (root, item);

        index++;

        g_free ((void *)name);
      }
    }

    _menu_desktop_shortcuts = root;
  }

}

void
BamfLauncherIcon::OnLaunch (DbusmenuMenuitem *item, int time, BamfLauncherIcon *self)
{
  self->OpenInstance ();
}

void
BamfLauncherIcon::OnQuit (DbusmenuMenuitem *item, int time, BamfLauncherIcon *self)
{
  GList *children, *l;
  BamfView *view;

  children = bamf_view_get_children (BAMF_VIEW (self->m_App));

  for (l = children; l; l = l->next)
  {
    view = (BamfView *) l->data;

    if (BAMF_IS_WINDOW (view))
    {
      guint32 xid = bamf_window_get_xid (BAMF_WINDOW (view));
      CompWindow *window = self->m_Screen->findWindow ((Window) xid);

      if (window)
        window->close (self->m_Screen->getCurrentTime ());
    }
  }

  g_list_free (children);
}

void
BamfLauncherIcon::OnTogglePin (DbusmenuMenuitem *item, int time, BamfLauncherIcon *self)
{
  BamfView *view = BAMF_VIEW (self->m_App);
  bool sticky = bamf_view_is_sticky (view);
  const gchar *desktop_file = bamf_application_get_desktop_file (self->m_App);

  if (sticky)
  {
    bamf_view_set_sticky (view, false);
    if (bamf_view_is_closed (view))
      self->Remove ();

    if (desktop_file && strlen (desktop_file) > 0)
      FavoriteStore::GetDefault ()->RemoveFavorite (desktop_file);
  }
  else
  {
    bamf_view_set_sticky (view, true);

    if (desktop_file && strlen (desktop_file) > 0)
      FavoriteStore::GetDefault ()->AddFavorite (desktop_file, -1); //self->SortPriority ());
  }
}

void
BamfLauncherIcon::EnsureMenuItemsReady ()
{
  DbusmenuMenuitem *menu_item;

  /* Launch */
  if (_menu_items.find ("Launch") == _menu_items.end ())
  {
    menu_item = dbusmenu_menuitem_new ();
    g_object_ref (menu_item);

    dbusmenu_menuitem_property_set (menu_item, DBUSMENU_MENUITEM_PROP_LABEL, "Open New Window");
    dbusmenu_menuitem_property_set_bool (menu_item, DBUSMENU_MENUITEM_PROP_ENABLED, true);

    g_signal_connect (menu_item, DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED, (GCallback) &BamfLauncherIcon::OnLaunch, this);

    _menu_items["Launch"] = menu_item;
  }

  /* Pin */
  if (_menu_items.find ("Pin") == _menu_items.end ())
  {
    menu_item = dbusmenu_menuitem_new ();
    g_object_ref (menu_item);

    dbusmenu_menuitem_property_set (menu_item, DBUSMENU_MENUITEM_PROP_TOGGLE_TYPE, DBUSMENU_MENUITEM_TOGGLE_CHECK);
    dbusmenu_menuitem_property_set (menu_item, DBUSMENU_MENUITEM_PROP_LABEL, "Keep In Launcher");
    dbusmenu_menuitem_property_set_bool (menu_item, DBUSMENU_MENUITEM_PROP_ENABLED, true);

    g_signal_connect (menu_item, DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED, (GCallback) &BamfLauncherIcon::OnTogglePin, this);

    _menu_items["Pin"] = menu_item;
  }
  int checked = !bamf_view_is_sticky (BAMF_VIEW (m_App)) ?
                 DBUSMENU_MENUITEM_TOGGLE_STATE_CHECKED : DBUSMENU_MENUITEM_TOGGLE_STATE_UNCHECKED;

  dbusmenu_menuitem_property_set_int (_menu_items["Pin"],
                                      DBUSMENU_MENUITEM_PROP_TOGGLE_STATE,
                                      checked);


  /* Quit */
  if (_menu_items.find ("Quit") == _menu_items.end ())
  {
    menu_item = dbusmenu_menuitem_new ();
    g_object_ref (menu_item);

    dbusmenu_menuitem_property_set (menu_item, DBUSMENU_MENUITEM_PROP_LABEL, "Quit");
    dbusmenu_menuitem_property_set_bool (menu_item, DBUSMENU_MENUITEM_PROP_ENABLED, true);

    g_signal_connect (menu_item, DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED, (GCallback) &BamfLauncherIcon::OnQuit, this);

    _menu_items["Quit"] = menu_item;
  }
}

std::list<DbusmenuMenuitem *>
BamfLauncherIcon::GetMenus ()
{
  std::map<std::string, DbusmenuClient *>::iterator it;
  std::list<DbusmenuMenuitem *> result;

  for (it = _menu_clients.begin (); it != _menu_clients.end (); it++)
  {
    GList * child = NULL;
    DbusmenuClient *client = (*it).second;
    DbusmenuMenuitem *root = dbusmenu_client_get_root (client);

    for (child = dbusmenu_menuitem_get_children(root); child != NULL; child = g_list_next(child))
    {
      DbusmenuMenuitem *item = (DbusmenuMenuitem *) child->data;

      if (!item)
        continue;

      result.push_back (item);
    }
  }

  if (DBUSMENU_IS_MENUITEM (_menu_desktop_shortcuts))
  {
    GList * child = NULL;
    DbusmenuMenuitem *root = _menu_desktop_shortcuts;

    for (child = dbusmenu_menuitem_get_children(root); child != NULL; child = g_list_next(child))
    {
      DbusmenuMenuitem *item = (DbusmenuMenuitem *) child->data;

      if (!item)
        continue;

      result.push_back (item);
    }

  }

  EnsureMenuItemsReady ();

  result.push_back (_menu_items["Launch"]);
  result.push_back (_menu_items["Pin"]);

  if (bamf_view_is_running (BAMF_VIEW (m_App)))
    result.push_back (_menu_items["Quit"]);

  return result;
}


void
BamfLauncherIcon::UpdateIconGeometries (nux::Point3 center)
{
  GList *children, *l;
  BamfView *view;
  long data[4];

  data[0] = center.x - 24;
  data[1] = center.y - 24;
  data[2] = 48;
  data[3] = 48;

  children = bamf_view_get_children (BAMF_VIEW (m_App));

  for (l = children; l; l = l->next)
  {
    view = (BamfView *) l->data;

    if (BAMF_IS_WINDOW (view))
    {
      guint32 xid = bamf_window_get_xid (BAMF_WINDOW (view));

      XChangeProperty (m_Screen->dpy (), xid, Atoms::wmIconGeometry,
                       XA_CARDINAL, 32, PropModeReplace,
                       (unsigned char *) data, 4);
    }
  }

  g_list_free (children);
}

void
BamfLauncherIcon::OnCenterStabilized (nux::Point3 center)
{
  UpdateIconGeometries (center);
}
