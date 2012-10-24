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
 */

#ifndef UNITYSHARED_PLUGINADAPTER_H
#define UNITYSHARED_PLUGINADAPTER_H

/* Compiz */
#include <core/core.h>
#include <core/atoms.h>

#include <NuxCore/Property.h>

#include "XWindowManager.h"

namespace unity
{

typedef struct
{
  unsigned long flags;
  unsigned long functions;
  unsigned long decorations;
  long input_mode;
  unsigned long status;
} MotifWmHints, MwmHints;

class MultiActionList
{
public:
  MultiActionList() :
    primary_action_(nullptr)
  {}

  void Initiate(std::string const& name, CompOption::Vector const& extra_args = CompOption::Vector(), int state = 0) const;
  void InitiateAll(CompOption::Vector const& extra_args = CompOption::Vector(), int state = 0) const;
  void TerminateAll(CompOption::Vector const& extra_args = CompOption::Vector()) const;

  void AddNewAction(std::string const& name, CompAction*, bool primary);
  void RemoveAction(std::string const& name);
  bool HasPrimary() const;

private:
  CompAction* GetAction(std::string const& name) const;

  CompAction* primary_action_;
  std::map<std::string, CompAction*> actions_;
};


class PluginAdapter : public sigc::trackable, public XWindowManager
{
public:
  // You shouldn't get the PluginAdapter if you really want a WindowManager.
  // The PluginAdapter::Default should really only be called from within unityshell plugin.
  static PluginAdapter& Default();
  static void Initialize(CompScreen* screen);

  nux::Property<bool> bias_active_to_viewport;

  ~PluginAdapter();

  void SetScaleAction(MultiActionList& scale);
  void SetExpoAction(MultiActionList& expo);

  void SetShowHandlesAction(CompAction* action)
  {
    _grab_show_action = action;
  }
  void SetHideHandlesAction(CompAction* action)
  {
    _grab_hide_action = action;
  }
  void SetToggleHandlesAction(CompAction* action)
  {
    _grab_toggle_action = action;
  }

  void OnWindowClosed (CompWindow *);
  void OnScreenGrabbed();
  void OnScreenUngrabbed();

  void OnShowDesktop ();
  void OnLeaveDesktop ();

  void TerminateScale();
  bool IsScaleActive() const;
  bool IsScaleActiveForGroup() const;

  void InitiateExpo();
  void TerminateExpo();
  bool IsExpoActive() const;

  bool IsWallActive() const;

  void ShowGrabHandles(CompWindow* window, bool use_timer);
  void HideGrabHandles(CompWindow* window);
  void ToggleGrabHandles(CompWindow* window);

  void Notify(CompWindow* window, CompWindowNotify notify);
  void NotifyMoved(CompWindow* window, int x, int y);
  void NotifyResized(CompWindow* window, int x, int y, int w, int h);
  void NotifyStateChange(CompWindow* window, unsigned int state, unsigned int last_state);
  void NotifyCompizEvent(const char* plugin, const char* event, CompOption::Vector& option);
  void NotifyNewDecorationState(Window xid);

  Window GetActiveWindow() const;

  void Decorate(Window xid) const;
  void Undecorate(Window xid) const;

  // WindowManager implementation
  bool IsWindowMaximized(Window window_id) const;
  bool IsWindowDecorated(Window window_id) const;
  bool IsWindowOnCurrentDesktop(Window window_id) const;
  bool IsWindowObscured(Window window_id) const;
  bool IsWindowMapped(Window window_id) const;
  bool IsWindowVisible(Window window_id) const;
  bool IsWindowOnTop(Window window_id) const;
  bool IsWindowClosable(Window window_id) const;
  bool IsWindowMinimizable(Window window_id) const;
  bool IsWindowMaximizable(Window window_id) const;

  void Restore(Window window_id);
  void RestoreAt(Window window_id, int x, int y);
  void Minimize(Window window_id);
  void Close(Window window_id);
  void Activate(Window window_id);
  void Raise(Window window_id);
  void Lower(Window window_id);

  void ShowDesktop();
  bool InShowDesktop() const;

  void SetWindowIconGeometry(Window window, nux::Geometry const& geo);

  void FocusWindowGroup(std::vector<Window> const& windows,
                        FocusVisibility, int monitor = -1, bool only_top_win = true);
  bool ScaleWindowGroup(std::vector<Window> const& windows,
                        int state, bool force);

  bool IsScreenGrabbed() const;
  bool IsViewPortSwitchStarted() const;

  unsigned long long GetWindowActiveNumber(Window window_id) const;

  bool MaximizeIfBigEnough(CompWindow* window) const;

  int GetWindowMonitor(Window window_id) const;
  nux::Geometry GetWindowGeometry(Window window_id) const;
  nux::Geometry GetWindowSavedGeometry(Window window_id) const;
  nux::Geometry GetScreenGeometry() const;
  nux::Geometry GetWorkAreaGeometry(Window window_id = 0) const;
  nux::Size GetWindowDecorationSize(Window window_id, Edge) const;
  std::string GetWindowName(Window window_id) const;

  void CheckWindowIntersections(nux::Geometry const& region, bool &active, bool &any);

  int WorkspaceCount() const;

  void SetCoverageAreaBeforeAutomaximize(float area);

  bool SaveInputFocus();
  bool RestoreInputFocus();

  void MoveResizeWindow(Window window_id, nux::Geometry geometry);

  Window GetTopWindowAbove(Window xid) const;

protected:
  PluginAdapter(CompScreen* screen);
  void AddProperties(GVariantBuilder* builder);

private:
  std::string MatchStringForXids(std::vector<Window> const& windows);
  void InitiateScale(std::string const& match, int state = 0);

  bool CheckWindowIntersection(nux::Geometry const& region, CompWindow* window) const;
  void SetMwmWindowHints(Window xid, MotifWmHints* new_hints) const;

  Window GetTopMostValidWindowInViewport() const;

  std::string GetTextProperty(Window xid, Atom atom) const;
  std::string GetUtf8Property(Window xid, Atom atom) const;

  CompScreen* m_Screen;
  MultiActionList m_ExpoActionList;
  MultiActionList m_ScaleActionList;

  bool _spread_state;
  bool _spread_windows_state;
  bool _expo_state;
  bool _vp_switch_started;

  CompAction* _grab_show_action;
  CompAction* _grab_hide_action;
  CompAction* _grab_toggle_action;

  float _coverage_area_before_automaximize;

  bool _in_show_desktop;
  CompWindow* _last_focused_window;

  std::map<Window, unsigned int> _window_decoration_state;
};

}

#endif
