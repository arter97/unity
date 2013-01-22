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
 */

#include <gmock/gmock.h>
using namespace testing;

#include "shortcuts/BaseWindowRaiser.h"
#include "shortcuts/ShortcutController.h"
#include "unity-shared/UnitySettings.h"
using namespace unity;

#include "test_utils.h"
#include "test_uscreen_mock.h"

#include <NuxCore/AnimationController.h>

namespace
{

struct MockBaseWindowRaiser : public shortcut::BaseWindowRaiser
{
  typedef std::shared_ptr<MockBaseWindowRaiser> Ptr;

  MOCK_METHOD1 (Raise, void(nux::ObjectPtr<nux::BaseWindow> window));
};
}

namespace unity
{
namespace shortcut
{
class TestShortcutController : public Test
{
  struct MockShortcutController : public Controller
  {
    MockShortcutController(BaseWindowRaiser::Ptr const& base_window_raiser,
                           shortcut::Model::Ptr const& model = nullptr)
      : Controller(base_window_raiser, model)
    {}

    MOCK_METHOD1(SetOpacity, void(double));
    using Controller::GetGeometryPerMonitor;
    using Controller::ConstructView;
    using Controller::view_;

    void RealSetOpacity(double value)
    {
      Controller::SetOpacity(value);
    }
  };

public:
  TestShortcutController()
    : base_window_raiser_(std::make_shared<NiceMock<MockBaseWindowRaiser>>())
    , model_(std::make_shared<Model>(std::list<shortcut::AbstractHint::Ptr>()))
    , controller_(base_window_raiser_, model_)
    , animation_controller_(tick_source_)
  {
    ON_CALL(controller_, SetOpacity(_))
      .WillByDefault(Invoke(&controller_, &MockShortcutController::RealSetOpacity));
  }

  MockUScreen uscreen;
  Settings unity_settings;
  MockBaseWindowRaiser::Ptr base_window_raiser_;
  Model::Ptr model_;
  NiceMock<MockShortcutController> controller_;

  nux::animation::TickSource tick_source_;
  nux::animation::AnimationController animation_controller_;
};

TEST_F (TestShortcutController, WindowIsRaisedOnShow)
{
  EXPECT_CALL(*base_window_raiser_, Raise(_))
    .Times(1);

  controller_.Show();
  Utils::WaitForTimeout(1);
}

TEST_F (TestShortcutController, WindowIsNotRaisedOnShowWithNullModel)
{
  EXPECT_CALL(*base_window_raiser_, Raise(_))
    .Times(0);

  controller_.SetModel(nullptr);
  controller_.Show();
  Utils::WaitForTimeout(1);
}

TEST_F (TestShortcutController, HiddeenOnConstruction)
{
  {
    InSequence sequence;
    EXPECT_CALL(controller_, SetOpacity(0.0))
      .Times(1);
    EXPECT_CALL(controller_, SetOpacity(_))
      .Times(0);
  }

  controller_.ConstructView();
  controller_.Hide();
}

TEST_F (TestShortcutController, GetGeometryPerMonitor)
{
  nux::Geometry good_monitor(0, 0, 1366, 768);
  nux::Geometry invalid_monitor(good_monitor.x + good_monitor.width, 0, 1, 1);
  uscreen.SetMonitors({good_monitor, invalid_monitor});

  nux::Point offset(g_random_int_range(0, 100), g_random_int_range(0, 100));
  controller_.SetAdjustment(offset.x, offset.y);
  controller_.ConstructView();

  nux::Geometry expected = controller_.view_->GetAbsoluteGeometry();
  expected.x = good_monitor.x + offset.x + (good_monitor.width - expected.width - offset.x) / 2;
  expected.y = good_monitor.y + offset.y + (good_monitor.height - expected.height - offset.y) / 2;
  EXPECT_EQ(controller_.GetGeometryPerMonitor(0), expected);

  EXPECT_TRUE(controller_.GetGeometryPerMonitor(1).IsNull());
}


}
}
