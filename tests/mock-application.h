/*
 * Copyright 2012 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the  Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 3 along with this program.  If not, see
 * <http://www.gnu.org/licenses/>
 *
 * Authored by: Tim Penhey  <tim.penhey@canonical.com>
 *              Marco Trevisan <marco.trevisan@canonical.com>
 */
#ifndef TESTS_MOCK_APPLICATION_H
#define TESTS_MOCK_APPLICATION_H

#include <map>
#include <gmock/gmock.h>

#include "unity-shared/ApplicationManager.h"
#include "unity-shared/WindowManager.h"

using namespace testing;

namespace testmocks
{
struct MockApplicationWindow : unity::ApplicationWindow
{
  MockApplicationWindow(Window xid)
    : xid_(xid)
    , monitor_(0)
    , title_("MockApplicationWindow "+std::to_string(xid_))
    , type_("window")
    , visible_(true)
    , active_(false)
    , urgent_(false)
  {
    visible.SetGetterFunction([this] { return visible_; });
    active.SetGetterFunction([this] { return active_; });
    urgent.SetGetterFunction([this] { return urgent_; });
    title.SetGetterFunction([this] { return title_; });
    icon.SetGetterFunction([this] { return icon_; });
  }

  Window xid_;
  int monitor_;
  std::string title_;
  std::string icon_;
  std::string type_;

  bool visible_;
  bool active_;
  bool urgent_;

  virtual std::string type() const { return type_; }

  virtual Window window_id() const { return xid_; }
  virtual int monitor() const { return monitor_; }

  virtual unity::ApplicationPtr application() const { return unity::ApplicationPtr(); }
  virtual bool Focus() const
  {
    auto& wm = unity::WindowManager::Default();
    wm.Raise(xid_);
    wm.Activate(xid_);
    return true;
  }
  virtual void Quit() const {}

  void SetTitle(std::string const& new_title)
  {
    if (new_title == title())
      return;

    title_ = new_title;
    title.changed(title_);
  }

  void SetIcon(std::string const& new_icon)
  {
    if (new_icon == icon())
      return;

    icon_ = new_icon;
    icon.changed(icon_);
  }
};

struct MockApplication : unity::Application
{
  MockApplication(std::string const& desktop_file,
                  std::string const& icon_name = "",
                  std::string const& title_str = "")
    : desktop_file_(desktop_file)
    , icon_(icon_name)
    , title_(title_str)
    , seen_(false)
    , sticky_(false)
    , visible_(false)
    , active_(false)
    , running_(false)
    , urgent_(false)
    , type_("mock")
    {
      seen.SetSetterFunction(sigc::mem_fun(this, &MockApplication::SetSeen));
      sticky.SetSetterFunction(sigc::mem_fun(this, &MockApplication::SetSticky));

      seen.SetGetterFunction([this] { return seen_; });
      sticky.SetGetterFunction([this] { return sticky_; });
      visible.SetGetterFunction([this] { return visible_; });
      active.SetGetterFunction([this] { return active_; });
      running.SetGetterFunction([this] { return running_; });
      urgent.SetGetterFunction([this] { return urgent_; });
      title.SetGetterFunction([this] { return title_; });
      icon.SetGetterFunction([this] { return icon_; });
    }

  std::string desktop_file_;
  std::string icon_;
  std::string title_;
  bool seen_;
  bool sticky_;
  bool visible_;
  bool active_;
  bool running_;
  bool urgent_;
  unity::WindowList windows_;
  std::string type_;

  virtual std::string desktop_file() const { return desktop_file_; }
  virtual std::string type() const { return type_; }
  virtual std::string repr() const { return "MockApplication"; }

  virtual unity::WindowList GetWindows() const { return windows_; }
  virtual bool OwnsWindow(Window window_id) const {
    auto end = std::end(windows_);
    return std::find_if(std::begin(windows_), end, [window_id] (unity::ApplicationWindowPtr window) {
      return window->window_id() == window_id;
    }) != end;
  }

  virtual std::vector<std::string> GetSupportedMimeTypes() const { return {}; }

  virtual unity::ApplicationWindowPtr GetFocusableWindow() const { return unity::ApplicationWindowPtr(); }
  virtual void Focus(bool show_on_visible, int monitor) const  {}
  virtual void Quit() const {}
  void SetRunState(bool state) {
    running_ = state;
    running.changed.emit(state);
    }

  bool SetSeen(bool const& param) {
    if (param != seen_) {
      seen_ = param;
      return true;
    }
    return false;
  }

  bool SetSticky(bool const& param) {
    if (param != sticky_) {
      sticky_ = param;
      return true;
    }
    return false;
  }

  void SetActiveState(bool state)
  {
    if (active_ == state)
      return;
    active_ = state;
    active.changed.emit(state);
  }

  void SetTitle(std::string const& new_title)
  {
    if (new_title == title())
      return;

    title_ = new_title;
    title.changed(title_);
  }

  void SetIcon(std::string const& new_icon)
  {
    if (new_icon == icon())
      return;

    icon_ = new_icon;
    icon.changed(icon_);
  }
};

struct MockApplicationManager : public unity::ApplicationManager
{
  MockApplicationManager()
  {
    ON_CALL(*this, GetApplicationForDesktopFile(_)).WillByDefault(Invoke(this, &MockApplicationManager::RealGetApplicationForDesktopFile));
  }

  static void StartApp(std::string const& desktop_file)
  {
    // We know the application manager is a mock one so we can cast it.
    auto& app_manager = unity::ApplicationManager::Default();
    auto self = dynamic_cast<MockApplicationManager*>(&app_manager);
    auto app = self->RealGetApplicationForDesktopFile(desktop_file);
    app_manager.application_started.emit(app);
  }

  MOCK_METHOD0(GetActiveWindow, unity::ApplicationWindowPtr());
  MOCK_METHOD1(GetApplicationForDesktopFile, unity::ApplicationPtr(std::string const&));
  MOCK_METHOD0(GetRunningApplications, unity::ApplicationList());
  MOCK_METHOD1(GetApplicationForWindow, unity::ApplicationPtr(Window));

  unity::ApplicationPtr RealGetApplicationForDesktopFile(std::string const& desktop_file)
  {
    AppMap::iterator iter = app_map_.find(desktop_file);
    if (iter == app_map_.end())
    {
      unity::ApplicationPtr app(new MockApplication(desktop_file));
      app_map_.insert(AppMap::value_type(desktop_file, app));
      return app;
    }
    else
    {
      return iter->second;
    }
  }

private:
  typedef std::map<std::string, unity::ApplicationPtr> AppMap;
  AppMap app_map_;
};

}

#endif
