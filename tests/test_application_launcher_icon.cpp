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
 * Authored by: Andrea Azzarone <andrea.azzarone@canonical.com>
 *              Brandon Schaefer <brandon.schaefer@canonical.com>
 *              Marco Trevisan <marco.trevisan@canonical.com>
 */

#include <config.h>
#include <gmock/gmock.h>

#include <UnityCore/GLibWrapper.h>
#include <UnityCore/DesktopUtilities.h>

#include "ApplicationLauncherIcon.h"
#include "FavoriteStore.h"
#include "StandaloneWindowManager.h"
#include "mock-application.h"
#include "test_utils.h"

using namespace testing;
using namespace testmocks;
using namespace unity;
using namespace unity::launcher;

namespace
{
const std::string DEFAULT_EMPTY_ICON = "application-default-icon";
const std::string USC_DESKTOP = BUILDDIR"/tests/data/applications/ubuntu-software-center.desktop";
const std::string NO_ICON_DESKTOP = BUILDDIR"/tests/data/applications/no-icon.desktop";

struct MockApplicationLauncherIcon : ApplicationLauncherIcon
{
  typedef nux::ObjectPtr<MockApplicationLauncherIcon> Ptr;

  MockApplicationLauncherIcon(ApplicationPtr const& app)
    : ApplicationLauncherIcon(app)
  {}

  MOCK_METHOD1(ActivateLauncherIcon, void(ActionArg));

  using ApplicationLauncherIcon::IsFileManager;
};

MATCHER_P(AreArgsEqual, a, "")
{
  return arg.source == a.source &&
         arg.button == a.button &&
         arg.timestamp == a.timestamp &&
         arg.target == a.target;
         arg.monitor = a.monitor;
}

struct TestApplicationLauncherIcon : Test
{
  virtual void SetUp()
  {
    WM = dynamic_cast<StandaloneWindowManager*>(&WindowManager::Default());
    usc_app = std::make_shared<MockApplication>(USC_DESKTOP, "softwarecenter");
    usc_icon = new NiceMock<MockApplicationLauncherIcon>(usc_app);
    ASSERT_EQ(usc_icon->DesktopFile(), USC_DESKTOP);

    empty_app = std::make_shared<MockApplication>(NO_ICON_DESKTOP);
    empty_icon = new NiceMock<MockApplicationLauncherIcon>(empty_app);
    ASSERT_EQ(empty_icon->DesktopFile(), NO_ICON_DESKTOP);

    mock_app = std::make_shared<MockApplication>("");
    mock_icon = new NiceMock<MockApplicationLauncherIcon>(mock_app);
    ASSERT_TRUE(mock_icon->DesktopFile().empty());
  }

  void AddMockWindow(Window xid, int monitor, int desktop)
  {
    auto app_window = std::make_shared<MockApplicationWindow>(xid);
    app_window->monitor_ =  monitor;
    mock_app->windows_.push_back(app_window);

    auto standalone_window = std::make_shared<unity::StandaloneWindow>(xid);
    standalone_window->current_desktop = desktop;

    WM->AddStandaloneWindow(standalone_window);
  }

  glib::Object<DbusmenuMenuitem> GetMenuItemWithLabel(AbstractLauncherIcon::MenuItemsVector const& menus,
                                                      std::string const& label)
  {
    auto menu_it = std::find_if(menus.begin(), menus.end(), [label] (glib::Object<DbusmenuMenuitem> it) {
      if (glib::gchar_to_string(dbusmenu_menuitem_property_get(it, DBUSMENU_MENUITEM_PROP_TYPE)) == DBUSMENU_CLIENT_TYPES_SEPARATOR)
        return false;

      auto* menu_label = dbusmenu_menuitem_property_get(it, DBUSMENU_MENUITEM_PROP_LABEL);
      return (glib::gchar_to_string(menu_label) == label);
    });

    return (menu_it != menus.end()) ? *menu_it : glib::Object<DbusmenuMenuitem>();
  }

  glib::Object<DbusmenuMenuitem> GetMenuItemWithLabel(MockApplicationLauncherIcon::Ptr const& icon,
                                                      std::string const& label)
  {
    return GetMenuItemWithLabel(icon->Menus(), label);
  }

  bool HasMenuItemWithLabel(AbstractLauncherIcon::MenuItemsVector const& menus,
                            std::string const& label)
  {
    return GetMenuItemWithLabel(menus, label) != nullptr;
  }

  bool HasMenuItemWithLabel(MockApplicationLauncherIcon::Ptr const& icon, std::string const& label)
  {
    return HasMenuItemWithLabel(icon->Menus(), label);
  }

  StandaloneWindowManager* WM;
  std::shared_ptr<MockApplication> usc_app;
  std::shared_ptr<MockApplication> empty_app;
  std::shared_ptr<MockApplication> mock_app;
  MockApplicationLauncherIcon::Ptr usc_icon;
  MockApplicationLauncherIcon::Ptr empty_icon;
  MockApplicationLauncherIcon::Ptr mock_icon;
};

TEST_F(TestApplicationLauncherIcon, ApplicationSignalDisconnection)
{
  std::shared_ptr<MockApplication> app = std::make_shared<MockApplication>(USC_DESKTOP);
  {
    MockApplicationLauncherIcon::Ptr icon(new NiceMock<MockApplicationLauncherIcon>(app));
    EXPECT_FALSE(app->closed.empty());
  }

  EXPECT_TRUE(app->closed.empty());
}

TEST_F(TestApplicationLauncherIcon, Position)
{
  EXPECT_EQ(usc_icon->position(), AbstractLauncherIcon::Position::FLOATING);
}

TEST_F(TestApplicationLauncherIcon, TestCustomBackgroundColor)
{
  nux::Color const& color = usc_icon->BackgroundColor();

  EXPECT_EQ(color.red, 0xaa / 255.0f);
  EXPECT_EQ(color.green, 0xbb / 255.0f);
  EXPECT_EQ(color.blue, 0xcc / 255.0f);
  EXPECT_EQ(color.alpha, 0xff / 255.0f);
}

TEST_F(TestApplicationLauncherIcon, TestDefaultIcon)
{
  EXPECT_EQ(usc_icon->icon_name(), "softwarecenter");
  EXPECT_EQ(empty_icon->icon_name(), DEFAULT_EMPTY_ICON);
  EXPECT_EQ(mock_icon->icon_name(), DEFAULT_EMPTY_ICON);
}

TEST_F(TestApplicationLauncherIcon, Stick)
{
  bool saved = false;
  usc_icon->position_saved.connect([&saved] {saved = true;});

  usc_icon->Stick(false);
  EXPECT_TRUE(usc_app->sticky());
  EXPECT_TRUE(usc_icon->IsSticky());
  EXPECT_TRUE(usc_icon->IsVisible());
  EXPECT_FALSE(saved);

  usc_icon->Stick(true);
  EXPECT_FALSE(saved);
}

TEST_F(TestApplicationLauncherIcon, StickAndSave)
{
  bool saved = false;
  mock_icon->position_saved.connect([&saved] {saved = true;});

  mock_icon->Stick(true);
  EXPECT_TRUE(mock_app->sticky());
  EXPECT_TRUE(mock_icon->IsSticky());
  EXPECT_TRUE(mock_icon->IsVisible());
  EXPECT_TRUE(saved);
}

TEST_F(TestApplicationLauncherIcon, UnstickNotRunning)
{
  bool forgot = false;
  mock_app->running_ = false;
  mock_icon->position_forgot.connect([&forgot] {forgot = true;});

  mock_icon->Stick();
  mock_icon->UnStick();
  EXPECT_FALSE(mock_app->sticky());
  EXPECT_FALSE(mock_icon->IsSticky());
  EXPECT_FALSE(mock_icon->IsVisible());
  EXPECT_TRUE(forgot);
}

TEST_F(TestApplicationLauncherIcon, UnstickRunning)
{
  bool forgot = false;
  mock_app->running_ = true;
  mock_icon->position_forgot.connect([&forgot] {forgot = true;});

  mock_icon->Stick();
  mock_icon->UnStick();
  EXPECT_FALSE(mock_app->sticky());
  EXPECT_FALSE(mock_icon->IsSticky());
  EXPECT_TRUE(mock_icon->IsVisible());
  EXPECT_TRUE(forgot);
}

TEST_F(TestApplicationLauncherIcon, RemoteUri)
{
  EXPECT_EQ(usc_icon->RemoteUri(), FavoriteStore::URI_PREFIX_APP + DesktopUtilities::GetDesktopID(USC_DESKTOP));
  EXPECT_TRUE(mock_icon->RemoteUri().empty());
}

TEST_F(TestApplicationLauncherIcon, TooltipUpdates)
{
  ASSERT_TRUE(mock_icon->tooltip_text().empty());
  mock_app->title_ = "Got Name";
  ASSERT_TRUE(mock_icon->tooltip_text().empty());

  mock_app->title.changed.emit(mock_app->title_);
  EXPECT_EQ(mock_icon->tooltip_text(), "Got Name");

  mock_app->SetTitle("New Name");
  EXPECT_EQ(mock_icon->tooltip_text(), "New Name");
}

TEST_F(TestApplicationLauncherIcon, IconUpdates)
{
  ASSERT_EQ(mock_icon->icon_name(), DEFAULT_EMPTY_ICON);
  mock_app->icon_ = "icon-name";

  ASSERT_EQ(mock_icon->icon_name(), DEFAULT_EMPTY_ICON);

  mock_app->icon.changed.emit(mock_app->icon_);
  EXPECT_EQ(mock_icon->icon_name(), "icon-name");

  mock_app->SetIcon("new-icon-name");
  EXPECT_EQ(mock_icon->icon_name(), "new-icon-name");
}

TEST_F(TestApplicationLauncherIcon, PerformScrollTowardsTheUser)
{
  AddMockWindow(7, 1, 1);
  AddMockWindow(6, 0, 1);
  AddMockWindow(5, 0, 0);
  AddMockWindow(4, 0, 0);
  AddMockWindow(3, 1, 0);
  AddMockWindow(2, 0, 0);
  AddMockWindow(1, 0, 0);

  mock_icon->SetQuirk(AbstractLauncherIcon::Quirk::ACTIVE, true);
  
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 3, 2, 1));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::DOWN, 200);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 3, 1, 2));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::DOWN, 400);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 2, 1, 3));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::DOWN, 600);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 3, 2, 1, 4));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::DOWN, 800);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 4, 3, 2, 1, 5));

  // Make sure it wraps
  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::DOWN, 1000);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 3, 2, 1));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::DOWN, 1200);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 3, 1, 2));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::DOWN, 1400);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 2, 1, 3));

  // Much later...
  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::DOWN, 100000);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 2, 3, 1));
}

TEST_F(TestApplicationLauncherIcon, PerformScrollAwayFromTheUser)
{
  AddMockWindow(7, 1, 1);
  AddMockWindow(6, 0, 1);
  AddMockWindow(5, 0, 0);
  AddMockWindow(4, 0, 0);
  AddMockWindow(3, 1, 0);
  AddMockWindow(2, 0, 0);
  AddMockWindow(1, 0, 0);

  mock_icon->SetQuirk(AbstractLauncherIcon::Quirk::ACTIVE, true);

  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 3, 2, 1));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::UP, 200);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 4, 3, 2, 1, 5));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::UP, 400);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 3, 2, 1, 4));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::UP, 600);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 2, 1, 3));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::UP, 800);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 3, 1, 2));

  // Make sure it wraps
  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::UP, 1000);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 3, 2, 1));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::UP, 1200);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 4, 3, 2, 1, 5));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::UP, 1400);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 3, 2, 1, 4));

  // Much later...
  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::UP, 100000);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 3, 2, 1, 4, 5));
}

TEST_F(TestApplicationLauncherIcon, PerformScrollSwitchDirection)
{
  AddMockWindow(7, 1, 1);
  AddMockWindow(6, 0, 1);
  AddMockWindow(5, 0, 0);
  AddMockWindow(4, 0, 0);
  AddMockWindow(3, 1, 0);
  AddMockWindow(2, 0, 0);
  AddMockWindow(1, 0, 0);
  
  mock_icon->SetQuirk(AbstractLauncherIcon::Quirk::ACTIVE, true);

  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 3, 2, 1));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::DOWN, 200);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 3, 1, 2));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::UP, 400);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 4, 3, 1, 2, 5));
}

TEST_F(TestApplicationLauncherIcon, PerformScrollNoWindows)
{
  // Just to make sure it does not crash.
  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::DOWN, 200);
  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::UP, 400);
}

TEST_F(TestApplicationLauncherIcon, PerformScrollTooFast)
{
  AddMockWindow(7, 1, 1);
  AddMockWindow(6, 0, 1);
  AddMockWindow(5, 0, 0);
  AddMockWindow(4, 0, 0);
  AddMockWindow(3, 1, 0);
  AddMockWindow(2, 0, 0);
  AddMockWindow(1, 0, 0);

  mock_icon->SetQuirk(AbstractLauncherIcon::Quirk::ACTIVE, true);
  
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 3, 2, 1));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::DOWN, 200);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 3, 1, 2));

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::DOWN, 205); /* Too fast! */
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 3, 1, 2));
}

TEST_F(TestApplicationLauncherIcon, PerformScrollInitiallyUnfocusedWindow)
{
  AddMockWindow(7, 1, 1);
  AddMockWindow(6, 0, 1);
  AddMockWindow(5, 0, 0);
  AddMockWindow(4, 0, 0);
  AddMockWindow(3, 1, 0);
  AddMockWindow(2, 0, 0);
  AddMockWindow(1, 0, 0);
  
  auto external_window = std::make_shared<unity::StandaloneWindow>(8);
  WM->AddStandaloneWindow(external_window);
  mock_icon->SetQuirk(AbstractLauncherIcon::Quirk::ACTIVE, false);

  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 3, 2, 1, 8));
  ASSERT_EQ(WM->GetActiveWindow(), 8);

  mock_icon->PerformScroll(AbstractLauncherIcon::ScrollDirection::DOWN, 200);
  EXPECT_THAT(WM->GetWindowsInStackingOrder(), testing::ElementsAre(7, 6, 5, 4, 3, 2, 8, 1));
  ASSERT_EQ(WM->GetActiveWindow(), 1);
}

TEST_F(TestApplicationLauncherIcon, ActiveQuirkWMCrossCheck)
{
  auto win = std::make_shared<MockApplicationWindow>(g_random_int());
  mock_app->windows_ = { win };
  ASSERT_FALSE(mock_icon->IsActive());

  mock_app->SetActiveState(true);
  ASSERT_FALSE(mock_icon->IsActive());

  WM->AddStandaloneWindow(std::make_shared<StandaloneWindow>(win->window_id()));
  EXPECT_TRUE(mock_icon->IsActive());
}

TEST_F(TestApplicationLauncherIcon, NoWindowListMenusWithOneWindow)
{
  auto win = std::make_shared<MockApplicationWindow>(g_random_int());
  mock_app->windows_ = { win };
  EXPECT_FALSE(HasMenuItemWithLabel(mock_icon, win->title()));
}

TEST_F(TestApplicationLauncherIcon, WindowListMenusWithTwoWindows)
{
  auto win1 = std::make_shared<MockApplicationWindow>(1);
  auto wm_win1 = std::make_shared<StandaloneWindow>(win1->window_id());
  auto win2 = std::make_shared<MockApplicationWindow>(2);
  auto wm_win2 = std::make_shared<StandaloneWindow>(win2->window_id());

  mock_app->windows_ = { win1, win2 };
  WM->AddStandaloneWindow(wm_win1);
  WM->AddStandaloneWindow(wm_win2);
  ASSERT_TRUE(wm_win2->active());

  auto const& menus = mock_icon->Menus();
  auto const& menu1 = GetMenuItemWithLabel(menus, win1->title());
  ASSERT_NE(menu1, nullptr);

  EXPECT_TRUE(dbusmenu_menuitem_property_get_bool(menu1, DBUSMENU_MENUITEM_PROP_ENABLED));
  EXPECT_TRUE(dbusmenu_menuitem_property_get_bool(menu1, DBUSMENU_MENUITEM_PROP_VISIBLE));
  ASSERT_STREQ(NULL, dbusmenu_menuitem_property_get(menu1, DBUSMENU_MENUITEM_PROP_TOGGLE_TYPE));
  EXPECT_EQ(dbusmenu_menuitem_property_get_int(menu1, DBUSMENU_MENUITEM_PROP_TOGGLE_STATE),
  	DBUSMENU_MENUITEM_TOGGLE_STATE_UNCHECKED);
  EXPECT_TRUE(dbusmenu_menuitem_property_get_bool(menu1, QuicklistMenuItem::MARKUP_ACCEL_DISABLED_PROPERTY));
  EXPECT_EQ(dbusmenu_menuitem_property_get_int(menu1, QuicklistMenuItem::MAXIMUM_LABEL_WIDTH_PROPERTY), 300);

  auto const& menu2 = GetMenuItemWithLabel(menus, win2->title());
  ASSERT_NE(menu2, nullptr);

  EXPECT_TRUE(dbusmenu_menuitem_property_get_bool(menu2, DBUSMENU_MENUITEM_PROP_ENABLED));
  EXPECT_TRUE(dbusmenu_menuitem_property_get_bool(menu2, DBUSMENU_MENUITEM_PROP_VISIBLE));
  ASSERT_STREQ(DBUSMENU_MENUITEM_TOGGLE_RADIO, dbusmenu_menuitem_property_get(menu2, DBUSMENU_MENUITEM_PROP_TOGGLE_TYPE));
  EXPECT_EQ(dbusmenu_menuitem_property_get_int(menu2, DBUSMENU_MENUITEM_PROP_TOGGLE_STATE),
  	DBUSMENU_MENUITEM_TOGGLE_STATE_CHECKED);
  EXPECT_TRUE(dbusmenu_menuitem_property_get_bool(menu2, QuicklistMenuItem::MARKUP_ACCEL_DISABLED_PROPERTY));
  EXPECT_EQ(dbusmenu_menuitem_property_get_int(menu2, QuicklistMenuItem::MAXIMUM_LABEL_WIDTH_PROPERTY), 300);

  bool activated = false;
  wm_win1->active.changed.connect([&activated] (bool a) { activated = a; });
  g_signal_emit_by_name(menu1, DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED, 0);

  EXPECT_TRUE(wm_win1->active());
  EXPECT_TRUE(activated);

  activated = false;
  wm_win2->active.changed.connect([&activated] (bool a) { activated = a; });
  g_signal_emit_by_name(menu2, DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED, 0);

  EXPECT_TRUE(wm_win2->active());
  EXPECT_TRUE(activated);
}

TEST_F(TestApplicationLauncherIcon, WindowListMenusWithEmptyTitles)
{
  auto win1 = std::make_shared<MockApplicationWindow>(1);
  auto win2 = std::make_shared<MockApplicationWindow>(2);
  win1->SetTitle("");

  mock_app->windows_ = { win1, win2 };

  EXPECT_FALSE(HasMenuItemWithLabel(mock_icon, win1->title()));
}

TEST_F(TestApplicationLauncherIcon, QuicklistMenuHasAppName)
{
  mock_app->SetTitle("MockApplicationTitle");
  EXPECT_TRUE(HasMenuItemWithLabel(mock_icon, "<b>"+mock_app->title()+"</b>"));
}

TEST_F(TestApplicationLauncherIcon, QuicklistMenuHasLockToLauncher)
{
  mock_app->sticky = false;
  EXPECT_TRUE(HasMenuItemWithLabel(mock_icon, "Lock to Launcher"));
  EXPECT_FALSE(HasMenuItemWithLabel(mock_icon, "Unlock from Launcher"));
}

TEST_F(TestApplicationLauncherIcon, QuicklistMenuHasUnLockToLauncher)
{
  mock_app->sticky = true;
  EXPECT_TRUE(HasMenuItemWithLabel(mock_icon, "Unlock from Launcher"));
  EXPECT_FALSE(HasMenuItemWithLabel(mock_icon, "Lock to Launcher"));
}

TEST_F(TestApplicationLauncherIcon, QuicklistMenuHasNotQuit)
{
  mock_app->SetRunState(false);
  EXPECT_FALSE(HasMenuItemWithLabel(mock_icon, "Quit"));
}

TEST_F(TestApplicationLauncherIcon, QuicklistMenuHasQuit)
{
  mock_app->SetRunState(true);
  EXPECT_TRUE(HasMenuItemWithLabel(mock_icon, "Quit"));
}

TEST_F(TestApplicationLauncherIcon, QuicklistMenuItemUpdatesWithAppName)
{
  mock_app->SetTitle("MockApplicationTitle");
  ASSERT_TRUE(HasMenuItemWithLabel(mock_icon, "<b>"+mock_app->title()+"</b>"));

  mock_app->SetTitle("MockApplicationNewTitle");
  EXPECT_TRUE(HasMenuItemWithLabel(mock_icon, "<b>"+mock_app->title()+"</b>"));
}

TEST_F(TestApplicationLauncherIcon, QuicklistMenuItemForAppName)
{
  mock_app->SetTitle("MockApplicationTitle");
  auto app_menu = GetMenuItemWithLabel(mock_icon, "<b>"+mock_app->title_+"</b>");
  ASSERT_NE(app_menu, nullptr);

  bool method_called = false;
  ON_CALL(*mock_icon, ActivateLauncherIcon(_)).WillByDefault(Invoke([&method_called] (ActionArg arg) {
    method_called = true;
  }));

  unsigned time = g_random_int();
  EXPECT_CALL(*mock_icon, ActivateLauncherIcon(AreArgsEqual(ActionArg(ActionArg::Source::LAUNCHER, 0, time))));
  dbusmenu_menuitem_handle_event(app_menu, DBUSMENU_MENUITEM_EVENT_ACTIVATED, nullptr, time);

  Utils::WaitUntilMSec(method_called);
  EXPECT_TRUE(method_called);
}

TEST_F(TestApplicationLauncherIcon, IsFileManager)
{
  EXPECT_FALSE(usc_icon->IsFileManager());
  EXPECT_FALSE(empty_icon->IsFileManager());
  EXPECT_FALSE(mock_icon->IsFileManager());

  auto app = std::make_shared<MockApplication>("/any/path/nautilus.desktop", "Nautilus");
  MockApplicationLauncherIcon::Ptr icon(new NiceMock<MockApplicationLauncherIcon>(app));
  EXPECT_TRUE(icon->IsFileManager());

  app = std::make_shared<MockApplication>("/any/path/nautilus-folder-handler.desktop", "Nautilus");
  icon = new NiceMock<MockApplicationLauncherIcon>(app);
  EXPECT_TRUE(icon->IsFileManager());

  app = std::make_shared<MockApplication>("/any/path/nautilus-home.desktop", "Nautilus");
  icon = new NiceMock<MockApplicationLauncherIcon>(app);
  EXPECT_TRUE(icon->IsFileManager());
}

TEST_F(TestApplicationLauncherIcon, AllowDetailViewInSwitcher)
{
  mock_app->type_ = "mock";
  EXPECT_TRUE(mock_icon->AllowDetailViewInSwitcher());

  mock_app->type_ = "webapp";
  EXPECT_FALSE(mock_icon->AllowDetailViewInSwitcher());
}

}
