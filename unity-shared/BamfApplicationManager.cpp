// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2012 Canonical Ltd
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
 * Authored by: Tim Penhey <tim.penhey@canonical.com>
 */

#include "unity-shared/BamfApplicationManager.h"

#include <NuxCore/Logger.h>

#include "unity-shared/WindowManager.h"


DECLARE_LOGGER(logger, "unity.appmanager.bamf");


namespace unity
{
// This function is used by the static Default method on the ApplicationManager
// class, and uses link time to make sure there is a function available.
std::shared_ptr<ApplicationManager> create_application_manager()
{
    return std::shared_ptr<ApplicationManager>(new bamf::Manager());
}

namespace bamf
{
namespace
{
const char* UNSEEN_QUARK = "unity-unseen";
}


// Due to the way glib handles object inheritance, we need to cast between pointer types.
// In order to make the up-call for the base class easy, we pass through a void* for the view.
View::View(Manager const& manager, glib::Object<BamfView> const& view)
  : manager_(manager)
  , bamf_view_(view)
{
}

std::string View::title() const
{
  return glib::String(bamf_view_get_name(bamf_view_)).Str();
}

std::string View::icon() const
{
  return glib::String(bamf_view_get_icon(bamf_view_)).Str();
}


AppWindow::AppWindow(Manager const& manager, glib::Object<BamfView> const& window)
  : View(manager, window)
  , bamf_window_(glib::object_cast<BamfWindow>(window))
{
}

std::string AppWindow::title() const
{
  return View::title();
}

std::string AppWindow::icon() const
{
  return View::icon();
}

Window AppWindow::window_id() const
{
  return bamf_window_get_xid(bamf_window_);
}

int AppWindow::monitor() const
{
  return bamf_window_get_monitor(bamf_window_);
}

ApplicationPtr AppWindow::application() const
{
  return manager_.GetApplicationForWindow(bamf_window_);
}


Tab::Tab(Manager const& manager, glib::Object<BamfView> const& tab)
  : View(manager, tab)
  , bamf_tab_(glib::object_cast<BamfTab>(tab))
{}

std::string Tab::title() const
{
  return View::title();
}

std::string Tab::icon() const
{
  return View::icon();
}

Window Tab::window_id() const
{
  return bamf_tab_get_xid(bamf_tab_);
}

int Tab::monitor() const
{
  // TODO, we could find the real window for the window_id, and get the monitor for that.
  return -1;
}

ApplicationPtr Tab::application() const
{
  // TODO, we could find the real window for the window_id, and return the application for that.
  return ApplicationPtr();
}

// Being brutal with this function.
ApplicationWindowPtr create_window(Manager const& manager, glib::Object<BamfView> const& view)
{
  ApplicationWindowPtr result;
  if (view.IsType(BAMF_TYPE_TAB))
    result.reset(new Tab(manager, view));
  else if (view.IsType(BAMF_TYPE_WINDOW))
    result.reset(new AppWindow(manager, view));
  // We don't handle applications nor indicators here.
  return result;
}

Application::Application(Manager const& manager, glib::Object<BamfView> const& app)
  : View(manager, app)
  , bamf_app_(glib::object_cast<BamfApplication>(app))
{
  HookUpEvents();
}

Application::Application(Manager const& manager, glib::Object<BamfApplication> const& app)
  : View(manager, glib::object_cast<BamfView>(app))
  , bamf_app_(app)
{
  HookUpEvents();
}

void Application::HookUpEvents()
{
  // Hook up the property set/get functions
  seen.SetGetterFunction(sigc::mem_fun(this, &Application::GetSeen));
  seen.SetSetterFunction(sigc::mem_fun(this, &Application::SetSeen));
  sticky.SetGetterFunction(sigc::mem_fun(this, &Application::GetSticky));
  sticky.SetSetterFunction(sigc::mem_fun(this, &Application::SetSticky));
  visible.SetGetterFunction(sigc::mem_fun(this, &Application::GetVisible));
  active.SetGetterFunction(sigc::mem_fun(this, &Application::GetActive));
  running.SetGetterFunction(sigc::mem_fun(this, &Application::GetRunning));
  urgent.SetGetterFunction(sigc::mem_fun(this, &Application::GetUrgent));

  glib::SignalBase* sig;
  sig = new glib::Signal<void, BamfView*, gboolean>(bamf_view_, "user-visible-changed",
                          [this] (BamfView*, gboolean visible) {
                            this->visible.changed.emit(visible);
                          });
  signals_.Add(sig);
  sig = new glib::Signal<void, BamfView*, gboolean>(bamf_view_, "active-changed",
                          [this] (BamfView*, gboolean active) {
                            this->active.changed.emit(active);
                          });
  signals_.Add(sig);
  sig = new glib::Signal<void, BamfView*, gboolean>(bamf_view_, "running-changed",
                          [this] (BamfView*, gboolean running) {
                            this->running.changed.emit(running);
                          });
  signals_.Add(sig);
  sig = new glib::Signal<void, BamfView*, gboolean>(bamf_view_, "urgent-changed",
                          [this] (BamfView*, gboolean urgent) {
                            this->urgent.changed.emit(urgent);
                          });
  signals_.Add(sig);
  sig = new glib::Signal<void, BamfView*>(bamf_view_, "closed",
                          [this] (BamfView*) {
                            this->closed.emit();
                          });
  signals_.Add(sig);


  sig = new glib::Signal<void, BamfView*, BamfView*>(bamf_view_, "child-added",
                          [this] (BamfView*, BamfView* child) {
                            // Ownership is not passed on signals
                            glib::Object<BamfView> view(child, glib::AddRef());
                            ApplicationWindowPtr win = create_window(this->manager_, view);
                            if (win)
                              this->window_opened.emit(*win);
                          });
  signals_.Add(sig);

  sig = new glib::Signal<void, BamfView*, BamfView*>(bamf_view_, "child-removed",
                          [this] (BamfView*, BamfView* child) {
                            this->window_closed.emit();
                          });
  signals_.Add(sig);

  sig = new glib::Signal<void, BamfView*, BamfView*>(bamf_view_, "child-moved",
                          [this] (BamfView*, BamfView* child) {
                            // Ownership is not passed on signals
                            glib::Object<BamfView> view(child, glib::AddRef());
                            ApplicationWindowPtr win = create_window(this->manager_, view);
                            if (win)
                              this->window_moved.emit(*win);
                          });
  signals_.Add(sig);
}

Application::~Application()
{
  LOG_DEBUG(logger) << "Application::~Application";
}

std::string Application::title() const
{
  return View::title();
}

std::string Application::icon() const
{
  return View::icon();
}

WindowList Application::get_windows() const
{
  WindowList result;

  if (!bamf_app_)
    return result;

  WindowManager& wm = WindowManager::Default();
  std::shared_ptr<GList> children(bamf_view_get_children(bamf_view_), g_list_free);
  for (GList* l = children.get(); l; l = l->next)
  {
    glib::Object<BamfView> view(BAMF_VIEW(l->data), glib::AddRef());
    ApplicationWindowPtr window(create_window(manager_, view));
    if (!window)
      continue;

    Window window_id = window->window_id();

    if (wm.IsWindowMapped(window_id))
    {
      result.push_back(window);
    }
  }
  return result;
}

bool Application::GetSeen() const
{
  return g_object_get_qdata(G_OBJECT(bamf_app_.RawPtr()),
                            g_quark_from_string(UNSEEN_QUARK));
}

bool Application::SetSeen(bool const& param)
{
  bool is_seen = GetSeen();
  if (param == is_seen)
    return false; // unchanged

  void* data = param ? reinterpret_cast<void*>(1) : nullptr;
  g_object_set_qdata(G_OBJECT(bamf_app_.RawPtr()),
                     g_quark_from_string(UNSEEN_QUARK),
                     data);
  return true; // value updated

}



bool Application::GetSticky() const
{
  return bamf_view_is_sticky(bamf_view_);
}

bool Application::SetSticky(bool const& param)
{
  bool is_sticky = GetSticky();
  if (param == is_sticky)
    return false; // unchanged

  bamf_view_set_sticky(bamf_view_, true);
  return true; // value updated
}

bool Application::GetVisible() const
{
  return bamf_view_is_user_visible(bamf_view_);
}

bool Application::GetActive() const
{
  return bamf_view_is_active(bamf_view_);

}

bool Application::GetRunning() const
{
  return bamf_view_is_running(bamf_view_);
}

bool Application::GetUrgent() const
{
  return bamf_view_is_urgent(bamf_view_);
}


Manager::Manager()
 : matcher_(bamf_matcher_get_default())
{
  LOG_TRACE(logger) << "Create BAMF Application Manager";
  glib::SignalBase* sig;
  sig = new glib::Signal<void, BamfMatcher*, BamfView*>
      (matcher_, "view-opened",
       sigc::mem_fun(this, &Manager::OnViewOpened));
  signals_.Add(sig);

  sig = new glib::Signal<void, BamfMatcher*, BamfView*, BamfView*>
      (matcher_, "active-window-changed",
       [this](BamfMatcher*, BamfView* /* from */, BamfView* to) {
          // Ownership is not passed on signals
          glib::Object<BamfView> view(to, glib::AddRef());
          ApplicationWindowPtr win = create_window(*this, view);
          if (win)
            this->active_window_changed.emit(win);
        });
  signals_.Add(sig);

  sig = new glib::Signal<void, BamfMatcher*, BamfApplication*, BamfApplication*>
      (matcher_, "active-application-changed",
       [this](BamfMatcher*, BamfApplication* /* from */, BamfApplication* to) {
          // Ownership is not passed on signals
          glib::Object<BamfApplication> app(to, glib::AddRef());
          ApplicationPtr active_app;
          if (app) active_app.reset(new Application(*this, app));
          this->active_application_changed.emit(active_app);
       });
  signals_.Add(sig);
}

Manager::~Manager()
{
  LOG_DEBUG(logger) << "Manager::~Manager";
}

ApplicationWindowPtr Manager::GetActiveWindow() const
{
  ApplicationWindowPtr result;
  // No transfer of ownership for bamf_matcher_get_active_window.
  BamfWindow* active_win = bamf_matcher_get_active_window(matcher_);

  // If the active window is a dock type, then we want the first visible, non-dock type.
  if (active_win &&
      bamf_window_get_window_type(active_win) == BAMF_WINDOW_DOCK)
  {
    LOG_DEBUG(logger) << "Is a dock, looking at the window stack.";
    std::shared_ptr<GList> windows(bamf_matcher_get_window_stack_for_monitor(matcher_, -1), g_list_free);
    WindowManager& wm = WindowManager::Default();
    for (GList *l = windows.get(); l; l = l->next)
    {
      if (!BAMF_IS_WINDOW(l->data))
      {
        LOG_DEBUG(logger) << "Window stack returned something not a window, WTF?";
        continue;
      }

      auto win = static_cast<BamfWindow*>(l->data);
      auto view = static_cast<BamfView*>(l->data);
      Window xid = bamf_window_get_xid(win);

      if (bamf_view_is_user_visible(view) &&
          bamf_window_get_window_type(win) != BAMF_WINDOW_DOCK &&
          wm.IsWindowOnCurrentDesktop(xid) &&
          wm.IsWindowVisible(xid))
      {
        active_win = win;
      }
    }
  }

  auto view = reinterpret_cast<BamfView*>(active_win);
  if (active_win)
    result.reset(new AppWindow(*this, glib::Object<BamfView>(view, glib::AddRef())));
  return result;
}


ApplicationPtr Manager::active_application() const
{
    return ApplicationPtr();
}

ApplicationPtr Manager::GetApplicationForDesktopFile(std::string const& desktop_file) const
{
  ApplicationPtr result;
  glib::Object<BamfApplication> app(bamf_matcher_get_application_for_desktop_file(
    matcher_, desktop_file.c_str(), true));

  if (app)
    result.reset(new Application(*this, app));

  return result;
}

ApplicationPtr Manager::GetApplicationForWindow(glib::Object<BamfWindow> const& window) const
{
  ApplicationPtr result;
  glib::Object<BamfApplication> app(bamf_matcher_get_application_for_window(matcher_, window),
                                    glib::AddRef());
  if (app)
    result.reset(new Application(*this, app));
  return result;
}

ApplicationList Manager::running_applications() const
{
  ApplicationList result;
  std::shared_ptr<GList> apps(bamf_matcher_get_applications(matcher_), g_list_free);

  for (GList *l = apps.get(); l; l = l->next)
  {
    if (!BAMF_IS_APPLICATION(l->data))
    {
      LOG_INFO(logger) << "Running apps given something not an app.";
      continue;
    }

    glib::Object<BamfApplication> app(static_cast<BamfApplication*>(l->data));

    result.push_back(ApplicationPtr(new Application(*this, app)));
  }
  return result;
}


void Manager::OnViewOpened(BamfMatcher* matcher, BamfView* view)
{
  LOG_DEBUG_BLOCK(logger);
  if (!BAMF_IS_APPLICATION(view))
  {
    LOG_DEBUG(logger) << "view is not an app";
    return;
  }

  glib::Object<BamfApplication> app(reinterpret_cast<BamfApplication*>(view), glib::AddRef());
  application_started.emit(ApplicationPtr(new Application(*this, app)));
}

} // namespace bamf
} // namespace unity
