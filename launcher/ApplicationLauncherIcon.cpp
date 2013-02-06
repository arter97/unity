// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2010-2012 Canonical Ltd
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
 *              Marco Trevisan (Treviño) <3v1n0@ubuntu.com>
 */

#include <boost/algorithm/string.hpp>

#include <Nux/Nux.h>
#include <Nux/BaseWindow.h>
#include <NuxCore/Logger.h>

#include <UnityCore/Variant.h>
#include <UnityCore/GLibWrapper.h>
#include <UnityCore/DesktopUtilities.h>

#include "ApplicationLauncherIcon.h"
#include "FavoriteStore.h"
#include "Launcher.h"
#include "MultiMonitor.h"
#include "unity-shared/UBusMessages.h"

#include <glib/gi18n-lib.h>
#include <gio/gdesktopappinfo.h>

#include <libbamf/bamf-tab.h>

namespace unity
{
namespace launcher
{
DECLARE_LOGGER(logger, "unity.launcher.icon.application");
namespace
{
// We use the "bamf-" prefix since the manager is protected, to avoid name clash
const std::string WINDOW_MOVE_TIMEOUT = "bamf-window-move";
const std::string ICON_REMOVE_TIMEOUT = "bamf-icon-remove";
//const std::string ICON_DND_OVER_TIMEOUT = "bamf-icon-dnd-over";
const std::string DEFAULT_ICON = "application-default-icon";
const int MAXIMUM_QUICKLIST_WIDTH = 300;
}

NUX_IMPLEMENT_OBJECT_TYPE(ApplicationLauncherIcon);

ApplicationLauncherIcon::ApplicationLauncherIcon(ApplicationPtr const& app)
  : SimpleLauncherIcon(IconType::APPLICATION)
  , app_(app)
  , _startup_notification_timestamp(0)
  , use_custom_bg_color_(false)
  , bg_color_(nux::color::White)
{
  app->seen = true;

  tooltip_text = app->title();
  std::string icon = app->icon();
  icon_name = (icon.empty() ? DEFAULT_ICON : icon);

  SetQuirk(Quirk::VISIBLE, app->visible());
  SetQuirk(Quirk::ACTIVE, app->active());
  SetQuirk(Quirk::RUNNING, app->running());
  // Make sure we set the LauncherIcon stick bit too...
  if (app->sticky())
    SimpleLauncherIcon::Stick(false); // don't emit the signal

  LOG_INFO(logger) << "Created ApplicationLauncherIcon: "
    << tooltip_text()
    << ", icon: " << icon_name()
    << ", sticky: " << (app->sticky() ? "yes" : "no")
    << ", visible: " << (app->visible() ? "yes" : "no")
    << ", active: " << (app->active() ? "yes" : "no")
    << ", running: " << (app->running() ? "yes" : "no");

  // Lambda functions should be fine here because when the application the icon
  // is only ever removed when the application is closed.
  app->window_opened.connect([this](ApplicationWindow const&) {
                               EnsureWindowState();
                               UpdateMenus();
                               UpdateIconGeometries(GetCenters());
                             });
  app->window_closed.connect([this]() { EnsureWindowState(); });
  app->window_moved.connect([this](ApplicationWindow const&) { EnsureWindowState(); });

  app->urgent.changed.connect([this](bool const& urgent) {
                            LOG_DEBUG(logger) << tooltip_text() << " urgent now " << (urgent ? "true" : "false");
                            SetQuirk(Quirk::URGENT, urgent);
                          });
  app->active.changed.connect([this](bool const& active) {
                            LOG_DEBUG(logger) << tooltip_text() << " active now " << (active ? "true" : "false");
                            SetQuirk(Quirk::ACTIVE, active);
                          });
  app->running.changed.connect([this](bool const& running) {
                            LOG_DEBUG(logger) << tooltip_text() << " running now " << (running ? "true" : "false");
                            SetQuirk(Quirk::RUNNING, running);

                            if (running)
                            {
                              _source_manager.Remove(ICON_REMOVE_TIMEOUT);

                              /* It can happen that these values are not set
                               * during initialization if the view is closed
                               * very early, so we need to make sure that they
                               * are updated as soon as the view is re-opened. */
                              if (tooltip_text().empty())
                                tooltip_text = app_->title();

                              if (icon_name == DEFAULT_ICON)
                              {
                                std::string icon = app_->icon();
                                icon_name = (icon.empty() ? DEFAULT_ICON : icon);
                              }

                              EnsureWindowState();
                              UpdateIconGeometries(GetCenters());
                            }
                          });
  app->visible.changed.connect([this](bool const& visible) {
                            if (!IsSticky())
                              SetQuirk(Quirk::VISIBLE, visible);
                          });

  app->closed.connect([this]() {
                            if (!IsSticky())
                            {
                              SetQuirk(Quirk::VISIBLE, false);

                              /* Use a timeout to remove the icon, this avoids
                               * that we remove an application that is going
                               * to be reopened soon. So applications that
                               * have a splash screen won't be removed from
                               * the launcher while the splash is closed and
                               * a new window is opened. */
                              _source_manager.AddTimeoutSeconds(1, [&] {
                                Remove();
                                return false;
                              }, ICON_REMOVE_TIMEOUT);
                            }
                          });

  WindowManager& wm = WindowManager::Default();
  wm.window_minimized.connect(sigc::mem_fun(this, &ApplicationLauncherIcon::OnWindowMinimized));
  wm.window_moved.connect(sigc::mem_fun(this, &ApplicationLauncherIcon::OnWindowMoved));
  wm.screen_viewport_switch_ended.connect(sigc::mem_fun(this, &ApplicationLauncherIcon::EnsureWindowState));
  wm.terminate_expo.connect(sigc::mem_fun(this, &ApplicationLauncherIcon::EnsureWindowState));

  EnsureWindowState();
  UpdateMenus();
  UpdateDesktopFile();
  UpdateBackgroundColor();

  // hack
  SetProgress(0.0f);
}

ApplicationLauncherIcon::~ApplicationLauncherIcon()
{
  if (app_)
  {
    app_->sticky = false;
    app_->seen = false;
  }
}

bool ApplicationLauncherIcon::GetQuirk(AbstractLauncherIcon::Quirk quirk) const
{
  if (quirk == Quirk::ACTIVE)
  {
    if (!SimpleLauncherIcon::GetQuirk(Quirk::ACTIVE))
      return false;

    if (app_->type() == "webapp")
      return true;

    // Sometimes BAMF is not fast enough to update the active application
    // while quickly switching between apps, so we double check that the
    // real active window is part of the selection (see bug #1111620)
    Window active = WindowManager::Default().GetActiveWindow();

    for (auto& window : app_->GetWindows())
      if (window->window_id() == active)
        return true;

    return false;
  }

  return SimpleLauncherIcon::GetQuirk(quirk);
}

void ApplicationLauncherIcon::Remove()
{
  /* Removing the unity-seen flag to the wrapped bamf application, on remove
   * request we make sure that if the application is re-opened while the
   * removal process is still ongoing, the application will be shown on the
   * launcher. Disconnecting from signals we make sure that this icon won't be
   * reused (no duplicated icon). */
  app_->seen = false;
  // Disconnect all our callbacks.
  notify_callbacks(); // This is from sigc++::trackable
  SimpleLauncherIcon::Remove();
}

bool ApplicationLauncherIcon::IsSticky() const
{
  if (app_)
    return app_->sticky();
  return false;
}

bool ApplicationLauncherIcon::IsActive() const
{
  return GetQuirk(Quirk::ACTIVE);
}

bool ApplicationLauncherIcon::IsRunning() const
{
  return GetQuirk(Quirk::RUNNING);
}

bool ApplicationLauncherIcon::IsUrgent() const
{
  return GetQuirk(Quirk::URGENT);
}

void ApplicationLauncherIcon::ActivateLauncherIcon(ActionArg arg)
{
  SimpleLauncherIcon::ActivateLauncherIcon(arg);
  WindowManager& wm = WindowManager::Default();

  // This is a little awkward as the target is only set from the switcher.
  if (arg.target)
  {
    // thumper: should we Raise too? should the WM raise?
    wm.Activate(arg.target);
    return;
  }

  bool scaleWasActive = wm.IsScaleActive();
  if (scaleWasActive)
  {
    wm.TerminateScale();
  }

  bool active = IsActive();
  bool user_visible = IsRunning();
  /* We should check each child to see if there is
   * an unmapped (!= minimized) window around and
   * if so force "Focus" behaviour */

  if (arg.source != ActionArg::SWITCHER)
  {
    user_visible = app_->visible();

    if (active)
    {
      bool any_visible = false;
      bool any_mapped = false;
      bool any_on_top = false;
      bool any_on_monitor = (arg.monitor < 0);
      int active_monitor = arg.monitor;

      for (auto& window : app_->GetWindows())
      {
        Window xid = window->window_id();

        if (!any_visible && wm.IsWindowOnCurrentDesktop(xid))
        {
          any_visible = true;
        }

        if (!any_mapped && wm.IsWindowMapped(xid))
        {
          any_mapped = true;
        }

        if (!any_on_top && wm.IsWindowOnTop(xid))
        {
          any_on_top = true;
        }

        if (!any_on_monitor && window->monitor() == arg.monitor &&
            wm.IsWindowMapped(xid) && wm.IsWindowVisible(xid))
        {
          any_on_monitor = true;
        }

        if (window->active())
        {
          active_monitor = window->monitor();
        }
      }

      if (!any_visible || !any_mapped || !any_on_top)
        active = false;

      if (any_on_monitor && arg.monitor >= 0 && active_monitor != arg.monitor)
        active = false;
    }
  }

  /* Behaviour:
   * 1) Nothing running, or nothing visible -> launch application
   * 2) Running and active -> spread application
   * 3) Running and not active -> focus application
   * 4) Spread is active and different icon pressed -> change spread
   * 5) Spread is active -> Spread de-activated, and fall through
   */

  if (!IsRunning() || (IsRunning() && !user_visible)) // #1 above
  {
    if (GetQuirk(Quirk::STARTING))
      return;

    SetQuirk(Quirk::STARTING, true);
    OpenInstanceLauncherIcon();
  }
  else // app is running
  {
    if (active)
    {
      if (scaleWasActive) // #5 above
      {
        Focus(arg);
      }
      else // #2 above
      {
        if (arg.source != ActionArg::SWITCHER)
        {
          Spread(true, 0, false);
        }
      }
    }
    else
    {
      if (scaleWasActive) // #4 above
      {
        Focus(arg);
        if (arg.source != ActionArg::SWITCHER)
          Spread(true, 0, false);
      }
      else // #3 above
      {
        Focus(arg);
      }
    }
  }
}

WindowList ApplicationLauncherIcon::GetWindows(WindowFilterMask filter, int monitor)
{
  WindowManager& wm = WindowManager::Default();
  WindowList results;

  monitor = (filter & WindowFilter::ON_ALL_MONITORS) ? -1 : monitor;
  bool mapped = (filter & WindowFilter::MAPPED);
  bool user_visible = (filter & WindowFilter::USER_VISIBLE);
  bool current_desktop = (filter & WindowFilter::ON_CURRENT_DESKTOP);

  for (auto& window : app_->GetWindows())
  {
    if ((monitor >= 0 && window->monitor() == monitor) || monitor < 0)
    {
      if ((user_visible && window->visible()) || !user_visible)
      {
        Window xid = window->window_id();

        if ((mapped && wm.IsWindowMapped(xid)) || !mapped)
        {
          if ((current_desktop && wm.IsWindowOnCurrentDesktop(xid)) || !current_desktop)
          {
            results.push_back(window);
          }
        }
      }
    }
  }

  return results;
}

WindowList ApplicationLauncherIcon::Windows()
{
  return GetWindows(WindowFilter::MAPPED|WindowFilter::ON_ALL_MONITORS);
}

std::vector<Window> ApplicationLauncherIcon::WindowsOnViewport()
{
  WindowFilterMask filter = 0;
  filter |= WindowFilter::MAPPED;
  filter |= WindowFilter::USER_VISIBLE;
  filter |= WindowFilter::ON_CURRENT_DESKTOP;
  filter |= WindowFilter::ON_ALL_MONITORS;

  std::vector<Window> windows;
  for (auto& window : GetWindows(filter))
  {
    windows.push_back(window->window_id());
  }
  return windows;
}

std::vector<Window> ApplicationLauncherIcon::WindowsForMonitor(int monitor)
{
  WindowFilterMask filter = 0;
  filter |= WindowFilter::MAPPED;
  filter |= WindowFilter::USER_VISIBLE;
  filter |= WindowFilter::ON_CURRENT_DESKTOP;

  std::vector<Window> windows;
  for (auto& window : GetWindows(filter, monitor))
  {
    windows.push_back(window->window_id());
  }
  return windows;
}

void ApplicationLauncherIcon::OnWindowMinimized(guint32 xid)
{
  if (!app_->OwnsWindow(xid))
    return;

  Present(0.5f, 600);
  UpdateQuirkTimeDelayed(300, Quirk::SHIMMER);
}

void ApplicationLauncherIcon::OnWindowMoved(guint32 moved_win)
{
  if (!app_->OwnsWindow(moved_win))
    return;

  _source_manager.AddTimeout(250, [&] {
    EnsureWindowState();
    UpdateIconGeometries(GetCenters());

    return false;
  }, WINDOW_MOVE_TIMEOUT);
}

void ApplicationLauncherIcon::UpdateDesktopFile()
{
  std::string filename = app_->desktop_file();

  if (!filename.empty() && _desktop_file != filename)
  {
    _desktop_file = filename;

    // add a file watch to the desktop file so that if/when the app is removed
    // we can remove ourself from the launcher and when it's changed
    // we can update the quicklist.
    if (_desktop_file_monitor)
      _gsignals.Disconnect(_desktop_file_monitor, "changed");

    glib::Object<GFile> desktop_file(g_file_new_for_path(_desktop_file.c_str()));
    _desktop_file_monitor = g_file_monitor_file(desktop_file, G_FILE_MONITOR_NONE,
                                                nullptr, nullptr);
    g_file_monitor_set_rate_limit(_desktop_file_monitor, 1000);

    auto sig = new glib::Signal<void, GFileMonitor*, GFile*, GFile*, GFileMonitorEvent>(_desktop_file_monitor, "changed",
                                [&] (GFileMonitor*, GFile*, GFile*, GFileMonitorEvent event_type) {
                                  switch (event_type)
                                  {
                                    case G_FILE_MONITOR_EVENT_DELETED:
                                      UnStick();
                                      break;
                                    case G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT:
                                      UpdateDesktopQuickList();
                                      UpdateBackgroundColor();
                                      break;
                                    default:
                                      break;
                                  }
                                });
    _gsignals.Add(sig);
  }
}

std::string ApplicationLauncherIcon::DesktopFile()
{
  UpdateDesktopFile();
  return _desktop_file;
}

void ApplicationLauncherIcon::AddProperties(GVariantBuilder* builder)
{
  SimpleLauncherIcon::AddProperties(builder);

  GVariantBuilder xids_builder;
  g_variant_builder_init(&xids_builder, G_VARIANT_TYPE ("au"));

  for (auto& window : GetWindows())
    g_variant_builder_add(&xids_builder, "u", window->window_id());

  variant::BuilderWrapper(builder)
    .add("desktop_file", DesktopFile())
    .add("desktop_id", GetDesktopID())
    .add("xids", g_variant_builder_end(&xids_builder))
    .add("sticky", IsSticky())
    .add("startup_notification_timestamp", _startup_notification_timestamp);
}

void ApplicationLauncherIcon::OpenInstanceWithUris(std::set<std::string> const& uris)
{
  glib::Error error;
  glib::Object<GDesktopAppInfo> desktopInfo(g_desktop_app_info_new_from_filename(DesktopFile().c_str()));
  auto appInfo = glib::object_cast<GAppInfo>(desktopInfo);

  GdkDisplay* display = gdk_display_get_default();
  glib::Object<GdkAppLaunchContext> app_launch_context(gdk_display_get_app_launch_context(display));

  _startup_notification_timestamp = nux::GetWindowThread()->GetGraphicsDisplay().GetCurrentEvent().x11_timestamp;
  gdk_app_launch_context_set_timestamp(app_launch_context, _startup_notification_timestamp);

  if (g_app_info_supports_uris(appInfo))
  {
    GList* list = nullptr;

    for (auto  it : uris)
      list = g_list_prepend(list, g_strdup(it.c_str()));

    g_app_info_launch_uris(appInfo, list, glib::object_cast<GAppLaunchContext>(app_launch_context), &error);
    g_list_free_full(list, g_free);
  }
  else if (g_app_info_supports_files(appInfo))
  {
    GList* list = nullptr;

    for (auto it : uris)
    {
      GFile* file = g_file_new_for_uri(it.c_str());
      list = g_list_prepend(list, file);
    }

    g_app_info_launch(appInfo, list, glib::object_cast<GAppLaunchContext>(app_launch_context), &error);
    g_list_free_full(list, g_object_unref);
  }
  else
  {
    g_app_info_launch(appInfo, nullptr, glib::object_cast<GAppLaunchContext>(app_launch_context), &error);
  }

  if (error)
  {
    LOG_WARN(logger) << error;
  }

  UpdateQuirkTime(Quirk::STARTING);
}

void ApplicationLauncherIcon::OpenInstanceLauncherIcon()
{
  std::set<std::string> empty;
  OpenInstanceWithUris(empty);
}

void ApplicationLauncherIcon::Focus(ActionArg arg)
{
  ApplicationWindowPtr window = app_->GetFocusableWindow();
  if (window)
  {
    // If we have a window, try to focus it.
    if (window->Focus())
      return;
  }
  else if (app_->type() == "webapp")
  {
    // Webapps are again special.
    OpenInstanceLauncherIcon();
    return;
  }

  bool show_only_visible = arg.source == ActionArg::SWITCHER;
  app_->Focus(show_only_visible, arg.monitor);
}

bool ApplicationLauncherIcon::Spread(bool current_desktop, int state, bool force)
{
  std::vector<Window> windows;
  for (auto& window : GetWindows(current_desktop ? WindowFilter::ON_CURRENT_DESKTOP : 0))
  {
    windows.push_back(window->window_id());
  }
  return WindowManager::Default().ScaleWindowGroup(windows, state, force);
}

void ApplicationLauncherIcon::EnsureWindowState()
{
  std::vector<bool> monitors;
  monitors.resize(max_num_monitors);

  for (auto& window: app_->GetWindows())
  {
    int monitor = window->monitor();
    Window window_id = window->window_id();

    if (WindowManager::Default().IsWindowOnCurrentDesktop(window_id))
    {
      // If monitor is -1 (or negative), show on all monitors.
      if (monitor < 0)
      {
        for (int j = 0; j < max_num_monitors; j++)
          monitors[j] = true;
      }
      else
        monitors[monitor] = true;
    }
  }

  for (int i = 0; i < max_num_monitors; i++)
    SetWindowVisibleOnMonitor(monitors[i], i);

  EmitNeedsRedraw();
}

void ApplicationLauncherIcon::UpdateDesktopQuickList()
{
  std::string const& desktop_file = DesktopFile();

  if (desktop_file.empty())
    return;

  if (_menu_desktop_shortcuts)
  {
    for (GList *l = dbusmenu_menuitem_get_children(_menu_desktop_shortcuts); l; l = l->next)
    {
      _gsignals.Disconnect(l->data, "item-activated");
    }
  }

  _menu_desktop_shortcuts = dbusmenu_menuitem_new();
  dbusmenu_menuitem_set_root(_menu_desktop_shortcuts, TRUE);

  // Build a desktop shortcuts object and tell it that our
  // environment is Unity to handle the filtering
  _desktop_shortcuts = indicator_desktop_shortcuts_new(desktop_file.c_str(), "Unity");
  // This will get us a list of the nicks available, it should
  // always be at least one entry of NULL if there either aren't
  // any or they're filtered for the environment we're in
  const gchar** nicks = indicator_desktop_shortcuts_get_nicks(_desktop_shortcuts);

  int index = 0;
  while (nicks[index])
  {
    // Build a dbusmenu item for each nick that is the desktop
    // file that is built from it's name and includes a callback
    // to the desktop shortcuts object to execute the nick
    glib::String name(indicator_desktop_shortcuts_nick_get_name(_desktop_shortcuts,
                                                                nicks[index]));
    glib::Object<DbusmenuMenuitem> item(dbusmenu_menuitem_new());
    dbusmenu_menuitem_property_set(item, DBUSMENU_MENUITEM_PROP_LABEL, name);
    dbusmenu_menuitem_property_set_bool(item, DBUSMENU_MENUITEM_PROP_ENABLED, TRUE);
    dbusmenu_menuitem_property_set_bool(item, DBUSMENU_MENUITEM_PROP_VISIBLE, TRUE);
    dbusmenu_menuitem_property_set(item, "shortcut-nick", nicks[index]);

    auto sig = new glib::Signal<void, DbusmenuMenuitem*, gint>(item, "item-activated",
                                [&] (DbusmenuMenuitem* item, gint) {
                                  const gchar *nick;
                                  nick = dbusmenu_menuitem_property_get(item, "shortcut-nick");
                                  indicator_desktop_shortcuts_nick_exec(_desktop_shortcuts, nick);
                                });
    _gsignals.Add(sig);

    dbusmenu_menuitem_child_append(_menu_desktop_shortcuts, item);
    index++;
  }
}

void ApplicationLauncherIcon::UpdateBackgroundColor()
{
  bool last_use_custom_bg_color = use_custom_bg_color_;
  nux::Color last_bg_color(bg_color_);

  std::string const& color = DesktopUtilities::GetBackgroundColor(DesktopFile());

  use_custom_bg_color_ = !color.empty();

  if (use_custom_bg_color_)
    bg_color_ = nux::Color(color);

  if (last_use_custom_bg_color != use_custom_bg_color_ ||
      last_bg_color != bg_color_)
    EmitNeedsRedraw();
}

void ApplicationLauncherIcon::EnsureMenuItemsWindowsReady()
{
  // delete all menu items for windows
  _menu_items_windows.clear();
  // add menu items for all open windows
  for ( auto const& w: Windows() )
  {
    glib::Object<DbusmenuMenuitem> menu_item;
    menu_item = dbusmenu_menuitem_new();
    dbusmenu_menuitem_property_set_bool(menu_item, DBUSMENU_MENUITEM_PROP_ENABLED, true);
    dbusmenu_menuitem_property_set_bool(menu_item, DBUSMENU_MENUITEM_PROP_VISIBLE, true);
    Window xid = w->window_id();
    _gsignals.Add<void, DbusmenuMenuitem*, int>(menu_item, DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED,
      [xid] (DbusmenuMenuitem*,int) {
        WindowManager& wm = WindowManager::Default();
        wm.Activate(xid);
        wm.Raise(xid);
    } );
    dbusmenu_menuitem_property_set(menu_item, DBUSMENU_MENUITEM_PROP_LABEL, w->title().c_str() );
    dbusmenu_menuitem_property_set_int(menu_item, QuicklistMenuItem::MAXIMUM_LABEL_WIDTH_PROPERTY, MAXIMUM_QUICKLIST_WIDTH); 
    _menu_items_windows.push_back( menu_item );
  }
}

void ApplicationLauncherIcon::UpdateMenus()
{
  // add dynamic quicklist
  if (_menuclient_dynamic_quicklist && _menuclient_dynamic_quicklist.IsType(DBUSMENU_TYPE_CLIENT))
  {
    if (_menu_clients["dynamicquicklist"] != _menuclient_dynamic_quicklist)
    {
      _menu_clients["dynamicquicklist"] = _menuclient_dynamic_quicklist;
    }
  }
  else if (_menu_clients["dynamicquicklist"])
  {
    _menu_clients.erase("dynamicquicklist");
    _menuclient_dynamic_quicklist = nullptr;
  }

  // make a client for desktop file actions
  if (!_menu_desktop_shortcuts.IsType(DBUSMENU_TYPE_MENUITEM))
  {
    UpdateDesktopQuickList();
  }
}

void ApplicationLauncherIcon::Quit()
{
  app_->Quit();
}

void ApplicationLauncherIcon::AboutToRemove()
{
  UnStick();
  Quit();
}

void ApplicationLauncherIcon::Stick(bool save)
{
  if (IsSticky())
    return;

  app_->sticky = true;
  SimpleLauncherIcon::Stick(save);
}

void ApplicationLauncherIcon::UnStick()
{
  SimpleLauncherIcon::UnStick();

  if (!IsSticky())
    return;

  app_->sticky = false;
  if (!app_->running())
    Remove();
}

void ApplicationLauncherIcon::ToggleSticky()
{
  if (IsSticky())
  {
    UnStick();
  }
  else
  {
    Stick();
  }
}

void ApplicationLauncherIcon::EnsureMenuItemsReady()
{
  glib::Object<DbusmenuMenuitem> menu_item;

  /* Pin */
  if (_menu_items.find("Pin") == _menu_items.end())
  {
    menu_item = dbusmenu_menuitem_new();
    dbusmenu_menuitem_property_set_bool(menu_item, DBUSMENU_MENUITEM_PROP_ENABLED, true);
    dbusmenu_menuitem_property_set_bool(menu_item, DBUSMENU_MENUITEM_PROP_VISIBLE, true);

    _gsignals.Add<void, DbusmenuMenuitem*, int>(menu_item, DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED,
      [&] (DbusmenuMenuitem*, int) {
        ToggleSticky();
    });

    _menu_items["Pin"] = menu_item;
  }

  const char* label = !IsSticky() ? _("Lock to Launcher") : _("Unlock from Launcher");

  dbusmenu_menuitem_property_set(_menu_items["Pin"], DBUSMENU_MENUITEM_PROP_LABEL, label);


  /* Quit */
  if (_menu_items.find("Quit") == _menu_items.end())
  {
    menu_item = dbusmenu_menuitem_new();
    dbusmenu_menuitem_property_set(menu_item, DBUSMENU_MENUITEM_PROP_LABEL, _("Quit"));
    dbusmenu_menuitem_property_set_bool(menu_item, DBUSMENU_MENUITEM_PROP_ENABLED, true);
    dbusmenu_menuitem_property_set_bool(menu_item, DBUSMENU_MENUITEM_PROP_VISIBLE, true);

    _gsignals.Add<void, DbusmenuMenuitem*, int>(menu_item, DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED,
      [&] (DbusmenuMenuitem*, int) {
        Quit();
    });

    _menu_items["Quit"] = menu_item;
  }
}

AbstractLauncherIcon::MenuItemsVector ApplicationLauncherIcon::GetMenus()
{
  MenuItemsVector result;
  bool first_separator_needed = false;

  // FIXME for O: hack around the wrong abstraction
  UpdateMenus();

  for (auto const& cli : _menu_clients)
  {
    GList* child = nullptr;
    auto const& client = cli.second;

    if (!client || !client.IsType(DBUSMENU_TYPE_CLIENT))
      continue;

    DbusmenuMenuitem* root = dbusmenu_client_get_root(client);

    if (!root || !dbusmenu_menuitem_property_get_bool(root, DBUSMENU_MENUITEM_PROP_VISIBLE))
      continue;

    for (child = dbusmenu_menuitem_get_children(root); child; child = child->next)
    {
      glib::Object<DbusmenuMenuitem> item(static_cast<DbusmenuMenuitem*>(child->data), glib::AddRef());

      if (!item || !item.IsType(DBUSMENU_TYPE_MENUITEM))
        continue;

      if (dbusmenu_menuitem_property_get_bool(item, DBUSMENU_MENUITEM_PROP_VISIBLE))
      {
        first_separator_needed = true;
        dbusmenu_menuitem_property_set_bool(item, QuicklistMenuItem::MARKUP_ENABLED_PROPERTY, FALSE);

        result.push_back(item);
      }
    }
  }

  // FIXME: this should totally be added as a _menu_client
  if (DBUSMENU_IS_MENUITEM(_menu_desktop_shortcuts.RawPtr()))
  {
    GList* child = nullptr;

    for (child = dbusmenu_menuitem_get_children(_menu_desktop_shortcuts); child; child = child->next)
    {
      glib::Object<DbusmenuMenuitem> item(static_cast<DbusmenuMenuitem*>(child->data), glib::AddRef());

      if (!item || !item.IsType(DBUSMENU_TYPE_MENUITEM))
        continue;

      first_separator_needed = true;

      result.push_back(item);
    }
  }

  glib::Object<DbusmenuMenuitem> item;

  if (first_separator_needed)
  {
    auto first_sep = _menu_items_extra.find("FirstSeparator");

    if (first_sep != _menu_items_extra.end())
    {
      item = first_sep->second;
    }
    else
    {
      item = dbusmenu_menuitem_new();
      dbusmenu_menuitem_property_set(item,
                                     DBUSMENU_MENUITEM_PROP_TYPE,
                                     DBUSMENU_CLIENT_TYPES_SEPARATOR);
      _menu_items_extra["FirstSeparator"] = item;
    }
    result.push_back(item);
  }

  auto app_name_item = _menu_items_extra.find("AppName");
  if (app_name_item != _menu_items_extra.end())
  {
    item = app_name_item->second;
  }
  else
  {
    glib::String app_name(g_markup_escape_text(app_->title().c_str(), -1));
    std::ostringstream bold_app_name;
    bold_app_name << "<b>" << app_name << "</b>";

    item = dbusmenu_menuitem_new();
    dbusmenu_menuitem_property_set(item,
                                   DBUSMENU_MENUITEM_PROP_LABEL,
                                   bold_app_name.str().c_str());
    dbusmenu_menuitem_property_set_bool(item,
                                        DBUSMENU_MENUITEM_PROP_ENABLED,
                                        true);
    dbusmenu_menuitem_property_set_bool(item,
                                        QuicklistMenuItem::MARKUP_ENABLED_PROPERTY,
                                        true);

    _gsignals.Add<void, DbusmenuMenuitem*, int>(item, DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED,
      [&] (DbusmenuMenuitem*, int) {
        _source_manager.AddIdle([&] {
          ActivateLauncherIcon(ActionArg());
          return false;
        });
    });

    _menu_items_extra["AppName"] = glib::Object<DbusmenuMenuitem>(item);
  }
  result.push_back(item);

  auto second_sep = _menu_items_extra.find("SecondSeparator");
  if (second_sep != _menu_items_extra.end())
  {
    item = second_sep->second;
  }
  else
  {
    item = dbusmenu_menuitem_new();
    dbusmenu_menuitem_property_set(item,
                                   DBUSMENU_MENUITEM_PROP_TYPE,
                                   DBUSMENU_CLIENT_TYPES_SEPARATOR);
    _menu_items_extra["SecondSeparator"] = glib::Object<DbusmenuMenuitem>(item);
  }
  result.push_back(item);

  // add windows menu items
  if (Windows().size() > 1) {
    EnsureMenuItemsWindowsReady();
    for (auto it: _menu_items_windows )
    {
      result.push_back( it );
    }

    auto third_sep = _menu_items_extra.find("ThirdSeparator");
    if (third_sep != _menu_items_extra.end())
    {
      item = third_sep->second;
    }
    else
    {
      item = dbusmenu_menuitem_new();
      dbusmenu_menuitem_property_set(item,
          DBUSMENU_MENUITEM_PROP_TYPE,
          DBUSMENU_CLIENT_TYPES_SEPARATOR);
      _menu_items_extra["ThirdSeparator"] = glib::Object<DbusmenuMenuitem>(item);
    }
    result.push_back(item);
  }

  EnsureMenuItemsReady();

  for (auto it : _menu_items)
  {
    if (!IsRunning() && it.first == "Quit")
      continue;

    bool exists = false;
    std::string label_default(dbusmenu_menuitem_property_get(it.second, DBUSMENU_MENUITEM_PROP_LABEL));

    for (auto menu_item : result)
    {
      const gchar* type = dbusmenu_menuitem_property_get(menu_item, DBUSMENU_MENUITEM_PROP_TYPE);

      if (!type)//(g_strcmp0 (type, DBUSMENU_MENUITEM_PROP_LABEL) == 0)
      {
        const gchar* label = dbusmenu_menuitem_property_get(menu_item, DBUSMENU_MENUITEM_PROP_LABEL);

        if (label && std::string(label) == label_default)
        {
          exists = true;
          break;
        }
      }
    }

    if (!exists)
      result.push_back(it.second);
  }

  return result;
}

void ApplicationLauncherIcon::UpdateIconGeometries(std::vector<nux::Point3> center)
{
  nux::Geometry geo;
  geo.width = 48;
  geo.height = 48;

  for (auto& window : app_->GetWindows())
  {
    // We don't deal with tabs.
    if (window->type() == "tab")
      continue;

    Window xid = window->window_id();
    int monitor = window->monitor();
    monitor = std::max<int>(0, std::min<int>(center.size() - 1, monitor));

    // TODO: replace 24 with icon_size / 2;
    geo.x = center[monitor].x - 24;
    geo.y = center[monitor].y - 24;
    WindowManager::Default().SetWindowIconGeometry(xid, geo);
  }
}

void ApplicationLauncherIcon::OnCenterStabilized(std::vector<nux::Point3> center)
{
  UpdateIconGeometries(center);
}

std::string ApplicationLauncherIcon::GetDesktopID()
{
  std::string const& desktop_file = DesktopFile();

  return DesktopUtilities::GetDesktopID(desktop_file);
}

void ApplicationLauncherIcon::UpdateRemoteUri()
{
    std::string const& desktop_id = GetDesktopID();

    if (!desktop_id.empty())
    {
      _remote_uri = FavoriteStore::URI_PREFIX_APP + desktop_id;
    }
}

std::string ApplicationLauncherIcon::GetRemoteUri()
{
  if (_remote_uri.empty())
  {
     UpdateRemoteUri();
  }

  return _remote_uri;
}

std::set<std::string> ApplicationLauncherIcon::ValidateUrisForLaunch(DndData const& uris)
{
  std::set<std::string> result;

  for (auto uri : uris.Uris())
    result.insert(uri);

  return result;
}

void ApplicationLauncherIcon::OnDndHovered()
{
  // for now, let's not do this, it turns out to be quite buggy
  //if (IsRunning())
  //  Spread(CompAction::StateInitEdgeDnd, true);
}

void ApplicationLauncherIcon::OnDndEnter()
{
  /* Disabled, since the DND code is currently disabled as well.
  _source_manager.AddTimeout(1000, [&] {
    OnDndHovered();
    return false;
  }, ICON_DND_OVER_TIMEOUT);
  */
}

void ApplicationLauncherIcon::OnDndLeave()
{
  /* Disabled, since the DND code is currently disabled as well.
  _source_manager.Remove(ICON_DND_OVER_TIMEOUT);
  */
}

bool ApplicationLauncherIcon::OnShouldHighlightOnDrag(DndData const& dnd_data)
{
  bool is_home_launcher = boost::algorithm::ends_with(DesktopFile(), "nautilus-home.desktop") ||
                          boost::algorithm::ends_with(DesktopFile(), "nautilus.desktop");

  if (is_home_launcher)
  {
    return true;
  }

  for (auto type : dnd_data.Types())
  {
    for (auto supported_type : GetSupportedTypes())
    {
      if (g_content_type_is_a(type.c_str(), supported_type.c_str()))
      {
        if (!dnd_data.UrisByType(type).empty())
          return true;
      }
    }
  }

  return false;
}

nux::DndAction ApplicationLauncherIcon::OnQueryAcceptDrop(DndData const& dnd_data)
{
#ifdef USE_X11
  return ValidateUrisForLaunch(dnd_data).empty() ? nux::DNDACTION_NONE : nux::DNDACTION_COPY;
#else
  return nux::DNDACTION_NONE;
#endif
}

void ApplicationLauncherIcon::OnAcceptDrop(DndData const& dnd_data)
{
  OpenInstanceWithUris(ValidateUrisForLaunch(dnd_data));
}

bool ApplicationLauncherIcon::ShowInSwitcher(bool current)
{
  bool result = false;

  if (IsRunning() && IsVisible())
  {
    // If current is true, we only want to show the current workspace.
    if (!current)
    {
      result = true;
    }
    else
    {
      for (int i = 0; i < max_num_monitors; i++)
      {
        if (WindowVisibleOnMonitor(i))
        {
          result = true;
          break;
        }
      }
    }
  }

  return result;
}

unsigned long long ApplicationLauncherIcon::SwitcherPriority()
{
  unsigned long long result = 0;
  // Webapps always go at the back.
  if (app_->type() == "webapp")
    return result;

  for (auto& window : app_->GetWindows())
  {
    Window xid = window->window_id();
    result = std::max(result, WindowManager::Default().GetWindowActiveNumber(xid));
  }

  return result;
}

nux::Color ApplicationLauncherIcon::BackgroundColor() const
{
  if (use_custom_bg_color_)
    return bg_color_;

  return SimpleLauncherIcon::BackgroundColor();
}

const std::set<std::string> ApplicationLauncherIcon::GetSupportedTypes()
{
  std::set<std::string> supported_types;

  for (auto& type : app_->GetSupportedMimeTypes())
  {
    unity::glib::String super_type(g_content_type_from_mime_type(type.c_str()));
    supported_types.insert(super_type.Str());
  }

  return supported_types;
}

std::string ApplicationLauncherIcon::GetName() const
{
  return "ApplicationLauncherIcon";
}

} // namespace launcher
} // namespace unity
