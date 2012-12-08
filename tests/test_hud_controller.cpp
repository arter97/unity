/*
 * Copyright 2012 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3, as
 * published by the  Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the applicable version of the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of both the GNU Lesser General Public
 * License version 3 along with this program.  If not, see
 * <http://www.gnu.org/licenses/>
 *
 * Authored by: Andrea Azzarone <azzaronea@gmail.com>
 *
 */

#include <gmock/gmock.h>
using namespace testing;

#include "HudController.h"
#include "mock-base-window.h"
#include "unity-shared/DashStyle.h"
#include "unity-shared/PanelStyle.h"
#include "unity-shared/UnitySettings.h"
#include "test_utils.h"
using namespace unity;

namespace
{

class MockHudView : public hud::AbstractView
{
public:
  typedef nux::ObjectPtr<MockHudView> Ptr;

  MOCK_METHOD0(AboutToShow, void());
  MOCK_METHOD0(AboutToHide, void());
  MOCK_METHOD0(Relayout, void());
  MOCK_METHOD0(ResetToDefault, void());
  MOCK_METHOD0(SearchFinished, void());
  MOCK_METHOD4(SetIcon, void(std::string const&, unsigned int tile_size, unsigned int size, unsigned int padding));
  MOCK_METHOD1(SetQueries, void(hud::Hud::Queries queries));
  MOCK_METHOD2(SetMonitorOffset, void(int x, int y));
  MOCK_METHOD1(ShowEmbeddedIcon, void(bool show));
  MOCK_CONST_METHOD0(default_focus, nux::View*());
  MOCK_CONST_METHOD0(GetName, std::string());
  MOCK_METHOD1(AddProperties, void(GVariantBuilder*));
  MOCK_METHOD2(Draw, void(nux::GraphicsEngine&, bool));
  nux::Geometry GetContentGeometry()
  {
    return nux::Geometry();
  }
};


class TestHudController : public Test
{
public:
  TestHudController()
  : view_(new NiceMock<MockHudView>)
  , base_window_(new testmocks::MockBaseWindow([](nux::Geometry const& geo)
                                               { return geo; }))
  { }

  virtual void SetUp()
  {
    // Set expectations for creating the controller
    EXPECT_CALL(*base_window_, SetOpacity(0.0f))
      .WillOnce(Invoke(base_window_.GetPointer(),
                       &testmocks::MockBaseWindow::RealSetOpacity));

    controller_.reset(new hud::Controller([&](){ return view_.GetPointer(); },
                                          [&](){ return base_window_.GetPointer();}));
    Mock::VerifyAndClearExpectations(view_.GetPointer());
    Mock::VerifyAndClearExpectations(base_window_.GetPointer());
  }

protected:
  hud::Controller::Ptr controller_;
  MockHudView::Ptr view_;
  testmocks::MockBaseWindow::Ptr base_window_;

  // required to create hidden secret global variables
  Settings unity_settings_;
  dash::Style dash_style_;
  panel::Style panel_style_;
};


TEST_F(TestHudController, TestShowAndHideHud)
{
  // Set expectations for showing the HUD
  EXPECT_CALL(*view_, AboutToShow()).Times(1);
  EXPECT_CALL(*view_, ResetToDefault()).Times(1);
  EXPECT_CALL(*base_window_, SetOpacity(_))
      .WillRepeatedly(Invoke(base_window_.GetPointer(),
                             &testmocks::MockBaseWindow::RealSetOpacity));
  EXPECT_CALL(*base_window_, SetOpacity(Eq(1.0f))).Times(1);

  controller_->ShowHud();
  Utils::WaitForTimeout(2);
  Mock::VerifyAndClearExpectations(view_.GetPointer());
  Mock::VerifyAndClearExpectations(base_window_.GetPointer());

  // Set expectations for hiding the HUD
  EXPECT_CALL(*view_, AboutToHide()).Times(1);
  EXPECT_CALL(*view_, ResetToDefault()).Times(1);
  EXPECT_CALL(*base_window_, SetOpacity(_)).Times(AnyNumber());
  EXPECT_CALL(*base_window_, SetOpacity(Eq(0.0f))).Times(1);

  controller_->HideHud();
  Utils::WaitForTimeout(2);
}

}
