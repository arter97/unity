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
 *              Tim Penhey <tim.penhey@canonical.com>
 *              Marco Trevisan (Treviño) <marco.trevisan@canonical.com>
 */

#include <glib.h>
#include <sstream>
#include "StandaloneWindowManager.h"
#include "UScreen.h"

#include <NuxCore/Logger.h>
#include <UnityCore/Variant.h>

// Entirely stubs for now, unless we need this functionality at some point

namespace unity
{
DECLARE_LOGGER(logger, "unity.wm");

StandaloneWindow::StandaloneWindow(Window xid)
  : xid(xid)
  , name("StandaloneWindow " + std::to_string(xid))
  , geo(0, 0, 10, 10)
  , current_desktop(0)
  , monitor(0)
  , active(true)
  , mapped(true)
  , visible(true)
  , maximized(false)
  , minimized(false)
  , decorated(true)
  , has_decorations(true)
  , on_top(false)
  , closable(true)
  , minimizable(false)
  , maximizable(false)
{}

WindowManagerPtr create_window_manager()
{
  return WindowManagerPtr(new StandaloneWindowManager);
}

StandaloneWindowManager::StandaloneWindowManager()
  : expo_state_(false)
  , in_show_desktop_(false)
  , scale_active_(false)
  , scale_active_for_group_(false)
  , current_desktop_(0)
{}

Window StandaloneWindowManager::GetActiveWindow() const
{
  for (auto const& it : standalone_windows_)
    if (it.second->active)
      return it.second->Xid();

  return 0;
}

bool StandaloneWindowManager::IsWindowMaximized(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return it->second->maximized;

  return false;
}

bool StandaloneWindowManager::IsWindowDecorated(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end() && it->second->has_decorations)
    return it->second->decorated;

  return false;
}

bool StandaloneWindowManager::IsWindowOnCurrentDesktop(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return (it->second->current_desktop == current_desktop_);

  return false;
}

bool StandaloneWindowManager::IsWindowObscured(Window window_id) const
{
  return false;
}

bool StandaloneWindowManager::IsWindowMapped(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return it->second->mapped;

  return false;
}

bool StandaloneWindowManager::IsWindowVisible(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return it->second->visible;

  return false;
}

bool StandaloneWindowManager::IsWindowOnTop(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return it->second->on_top;

  return false;
}

bool StandaloneWindowManager::IsWindowClosable(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return it->second->closable;

  return false;
}

bool StandaloneWindowManager::IsWindowMinimized(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return it->second->minimized;

  return false;
}

bool StandaloneWindowManager::IsWindowMinimizable(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return it->second->minimizable;

  return false;
}

bool StandaloneWindowManager::IsWindowMaximizable(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return it->second->maximizable;

  return false;
}

bool StandaloneWindowManager::HasWindowDecorations(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return it->second->has_decorations;

  return false;
}

void StandaloneWindowManager::ShowDesktop()
{
  in_show_desktop_ = !in_show_desktop_;
}

bool StandaloneWindowManager::InShowDesktop() const
{
  return in_show_desktop_;
}

void StandaloneWindowManager::Decorate(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
  {
    it->second->decorated = it->second->has_decorations;
  }
}

void StandaloneWindowManager::Undecorate(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
  {
    it->second->decorated = false;
  }
}

void StandaloneWindowManager::Maximize(Window window_id)
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
  {
    it->second->maximized = true;
    Undecorate(window_id);
  }
}

void StandaloneWindowManager::Restore(Window window_id)
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
  {
    it->second->maximized = false;
    Decorate(window_id);
  }
}

void StandaloneWindowManager::RestoreAt(Window window_id, int x, int y)
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
  {
    Restore(window_id);
    it->second->geo.x = x;
    it->second->geo.y = y;
  }
}

void StandaloneWindowManager::UnMinimize(Window window_id)
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
  {
    it->second->minimized = false;

    if (it->second->maximized)
    {
      Undecorate(window_id);
    }
  }
}

void StandaloneWindowManager::Minimize(Window window_id)
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
  {
    it->second->minimized = true;

    if (it->second->maximized)
    {
      Decorate(window_id);
    }
  }
}

void StandaloneWindowManager::Close(Window window_id)
{
  standalone_windows_.erase(window_id);
}

void StandaloneWindowManager::Activate(Window window_id)
{
  auto old = std::find_if(standalone_windows_.begin(), standalone_windows_.end(),
                          [this] (std::pair<Window, StandaloneWindow::Ptr> const& it)
                            { return it.second->active; });

  if (old != standalone_windows_.end())
    old->second->active = false;

  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    it->second->active = true;
}

void StandaloneWindowManager::Raise(Window window_id)
{}

void StandaloneWindowManager::Lower(Window window_id)
{}

void StandaloneWindowManager::TerminateScale()
{}

void StandaloneWindowManager::SetScaleActive(bool scale_active)
{
  scale_active_ = scale_active;
}

bool StandaloneWindowManager::IsScaleActive() const
{
  return scale_active_;
}

void StandaloneWindowManager::SetScaleActiveForGroup(bool scale_active_for_group)
{
  scale_active_for_group_ = scale_active_for_group;
}

bool StandaloneWindowManager::IsScaleActiveForGroup() const
{
  return scale_active_for_group_;
}

void StandaloneWindowManager::InitiateExpo()
{
  expo_state_ = !expo_state_;
}

void StandaloneWindowManager::TerminateExpo()
{
  expo_state_ = false;
}

bool StandaloneWindowManager::IsExpoActive() const
{
  return expo_state_;
}

bool StandaloneWindowManager::IsWallActive() const
{
  return false;
}

void StandaloneWindowManager::FocusWindowGroup(std::vector<Window> const& windows,
                                               FocusVisibility,
                                               int monitor,
                                               bool only_top_win)
{}

bool StandaloneWindowManager::ScaleWindowGroup(std::vector<Window> const& windows,
                                               int state, bool force)
{
  return false;
}

bool StandaloneWindowManager::IsScreenGrabbed() const
{
  return false;
}

bool StandaloneWindowManager::IsViewPortSwitchStarted() const
{
  return false;
}

void StandaloneWindowManager::MoveResizeWindow(Window window_id, nux::Geometry geometry)
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    it->second->geo = geometry;
}

void StandaloneWindowManager::StartMove(Window window_id, int x, int y)
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
  {
    it->second->geo.x = x;
    it->second->geo.y = y;
  }
}

int StandaloneWindowManager::GetWindowMonitor(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return it->second->monitor;

  return -1;
}

nux::Geometry StandaloneWindowManager::GetWindowGeometry(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return it->second->geo;

  return nux::Geometry(0, 0, 1, 1);
}

nux::Geometry StandaloneWindowManager::GetWindowSavedGeometry(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return it->second->geo;

  return nux::Geometry();
}

nux::Geometry StandaloneWindowManager::GetScreenGeometry() const
{
  return nux::Geometry(0, 0, 1024, 768);
}

nux::Geometry StandaloneWindowManager::GetWorkAreaGeometry(Window window_id) const
{
  nux::Geometry geo(0, 0, 1, 1);
  return geo;
}

nux::Size StandaloneWindowManager::GetWindowDecorationSize(Window window_id, WindowManager::Edge edge) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return it->second->deco_sizes[unsigned(edge)];

  return nux::Size();
}

unsigned long long StandaloneWindowManager::GetWindowActiveNumber(Window window_id) const
{
  return 0;
}

void StandaloneWindowManager::SetWindowIconGeometry(Window window, nux::Geometry const& geo)
{
}

void StandaloneWindowManager::CheckWindowIntersections(nux::Geometry const& region,
                                                       bool &active, bool &any)
{
}

int StandaloneWindowManager::WorkspaceCount() const
{
  return 4;
}

bool StandaloneWindowManager::SaveInputFocus()
{
  return false;
}

bool StandaloneWindowManager::RestoreInputFocus()
{
  return false;
}

std::string StandaloneWindowManager::GetWindowName(Window window_id) const
{
  auto it = standalone_windows_.find(window_id);
  if (it != standalone_windows_.end())
    return it->second->name;

  return "";
}

// Mock functions

void StandaloneWindowManager::SetCurrentDesktop(unsigned desktop_id)
{
  current_desktop_ = desktop_id;
}

void StandaloneWindowManager::AddStandaloneWindow(StandaloneWindow::Ptr const& window)
{
  if (!window)
    return;

  if (standalone_windows_.empty())
    window->active = true;

  standalone_windows_[window->Xid()] = window;
}

std::map<Window, StandaloneWindow::Ptr> StandaloneWindowManager::GetStandaloneWindows() const
{
  return standalone_windows_;
}


void StandaloneWindowManager::AddProperties(GVariantBuilder* builder)
{
  unity::variant::BuilderWrapper wrapper(builder);
  wrapper.add(GetScreenGeometry())
         .add("workspace_count", WorkspaceCount())
         .add("active_window", GetActiveWindow())
         .add("screen_grabbed", IsScreenGrabbed())
         .add("scale_active", IsScaleActive())
         .add("scale_active_for_group", IsScaleActiveForGroup())
         .add("expo_active", IsExpoActive())
         .add("viewport_switch_running", IsViewPortSwitchStarted())
         .add("showdesktop_active", in_show_desktop_);
}

} // namespace unity