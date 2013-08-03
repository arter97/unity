// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2011-13 Canonical Ltd
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
 *              Andrea Azzarone <andrea.azzarone@canonical.com>
 */

#include "PanelController.h"

#include <vector>
#include <NuxCore/Logger.h>
#include <Nux/BaseWindow.h>
#include <UnityCore/Variant.h>

#include "unity-shared/UScreen.h"
#include "PanelView.h"
#include "unity-shared/PanelStyle.h"

namespace unity
{
namespace panel
{
DECLARE_LOGGER(logger, "unity.panel.controller");

const char* window_title = "unity-panel";

class Controller::Impl
{
public:
  Impl();
  ~Impl();

  void FirstMenuShow();
  void QueueRedraw();

  std::vector<nux::Geometry> GetGeometries() const;

  // NOTE: nux::Property maybe?
  void SetLauncherWidth(int width);
  void SetOpacity(float opacity);
  void SetOpacityMaximizedToggle(bool enabled);

  float opacity() const;

  void SetMenuShowTimings(int fadein, int fadeout, int discovery,
                          int discovery_fadein, int discovery_fadeout);

  nux::ObjectPtr<PanelView> CreatePanel(Introspectable *iobj);
  void OnScreenChanged(unsigned int primary_monitor, std::vector<nux::Geometry>& monitors, Introspectable *iobj);

  typedef nux::ObjectPtr<nux::BaseWindow> BaseWindowPtr;

  unity::PanelView* ViewForWindow(BaseWindowPtr const& window) const;

  PanelVector panels_;
  std::vector<Window> tray_xids_;
  float opacity_;
  bool opacity_maximized_toggle_;
  int menus_fadein_;
  int menus_fadeout_;
  int menus_discovery_;
  int menus_discovery_fadein_;
  int menus_discovery_fadeout_;
  indicator::DBusIndicators::Ptr dbus_indicators_;
};


Controller::Impl::Impl()
  : opacity_(1.0f)
  , opacity_maximized_toggle_(false)
  , menus_fadein_(0)
  , menus_fadeout_(0)
  , menus_discovery_(0)
  , menus_discovery_fadein_(0)
  , menus_discovery_fadeout_(0)
  , dbus_indicators_(std::make_shared<indicator::DBusIndicators>())
{}

Controller::Impl::~Impl()
{
  // Since the panels are in a window which adds a reference to the
  // panel, we need to make sure the base windows are unreferenced
  // otherwise the pnales never die.
  for (auto const& panel_ptr : panels_)
  {
    if (panel_ptr)
      panel_ptr->GetParent()->UnReference();
  }
}

std::vector<nux::Geometry> Controller::Impl::GetGeometries() const
{
  std::vector<nux::Geometry> geometries;

  for (auto const& panel : panels_)
  {
    geometries.push_back(panel->GetAbsoluteGeometry());
  }

  return geometries;
}

void Controller::Impl::FirstMenuShow()
{
  for (auto const& panel: panels_)
  {
    if (panel->FirstMenuShow())
      break;
  }
}

void Controller::Impl::SetOpacity(float opacity)
{
  opacity_ = opacity;

  for (auto const& panel: panels_)
  {
    panel->SetOpacity(opacity_);
  }
}

void Controller::Impl::SetLauncherWidth(int width)
{
  for (auto const& panel: panels_)
  {
    panel->SetLauncherWidth(width);
  }
}

void Controller::Impl::SetOpacityMaximizedToggle(bool enabled)
{
  opacity_maximized_toggle_ = enabled;

  for (auto const& panel: panels_)
  {
    panel->SetOpacityMaximizedToggle(opacity_maximized_toggle_);
  }
}

void Controller::Impl::SetMenuShowTimings(int fadein, int fadeout, int discovery,
                                          int discovery_fadein, int discovery_fadeout)
{
  menus_fadein_ = fadein;
  menus_fadeout_ = fadeout;
  menus_discovery_ = discovery;
  menus_discovery_fadein_ = discovery_fadein;
  menus_discovery_fadeout_ = discovery_fadeout;

  for (auto const& panel: panels_)
  {
    panel->SetMenuShowTimings(fadein, fadeout, discovery,
                              discovery_fadein, discovery_fadeout);
  }
}

void Controller::Impl::QueueRedraw()
{
  for (auto const& panel: panels_)
  {
    panel->QueueDraw();
  }
}

PanelView* Controller::Impl::ViewForWindow(BaseWindowPtr const& window) const
{
  nux::Layout* layout = window->GetLayout();
  auto it = layout->GetChildren().begin();

  return static_cast<PanelView*>(*it);
}

// We need to put a panel on every monitor, and try and re-use the panels we already have
void Controller::Impl::OnScreenChanged(unsigned int primary_monitor,
                                       std::vector<nux::Geometry>& monitors,
                                       Introspectable *iobj)
{
  unsigned int num_monitors = monitors.size();
  unsigned int num_panels = num_monitors;
  unsigned int panels_size = panels_.size();
  unsigned int last_panel = 0;

  tray_xids_.resize(num_panels);

  for (unsigned int i = 0; i < num_panels; ++i, ++last_panel)
  {
    if (i >= panels_size)
    {
      panels_.push_back(CreatePanel(iobj));
    }
    else if (!panels_[i])
    {
      panels_[i] = CreatePanel(iobj);
    }

    panels_[i]->SetMonitor(i);
    tray_xids_[i] = panels_[i]->GetTrayXid();
  }
    
  for (unsigned int i = last_panel; i < panels_size; ++i)
  {
    auto const& panel = panels_[i];
    if (panel)
    {
      iobj->RemoveChild(panel.GetPointer());
      panel->GetParent()->UnReference();
    }
  }

  panels_.resize(num_panels);
}


nux::ObjectPtr<PanelView> Controller::Impl::CreatePanel(Introspectable *iobj)
{
  auto* panel_window = new MockableBaseWindow(TEXT("PanelWindow"));

  nux::HLayout* layout = new nux::HLayout(NUX_TRACKER_LOCATION);

  PanelView* view = new PanelView(panel_window, dbus_indicators_);
  view->SetMaximumHeight(panel::Style::Instance().panel_height);
  view->SetOpacity(opacity_);
  view->SetOpacityMaximizedToggle(opacity_maximized_toggle_);
  view->SetMenuShowTimings(menus_fadein_, menus_fadeout_, menus_discovery_,
                         menus_discovery_fadein_, menus_discovery_fadeout_);

  layout->AddView(view, 1);
  layout->SetContentDistribution(nux::MAJOR_POSITION_START);
  layout->SetVerticalExternalMargin(0);
  layout->SetHorizontalExternalMargin(0);

  panel_window->SetLayout(layout);
  panel_window->SetBackgroundColor(nux::color::Transparent);
  panel_window->ShowWindow(true);

  if (nux::GetWindowThread()->IsEmbeddedWindow())
    panel_window->EnableInputWindow(true, panel::window_title, false, false);

  panel_window->InputWindowEnableStruts(true);
  iobj->AddChild(view);

  return nux::ObjectPtr<PanelView>(view);
}

bool Controller::IsMouseInsideIndicator(nux::Point const& mouse_position) const
{
  for (auto panel : pimpl->panels_)
  {
    if (panel->IsMouseInsideIndicator(mouse_position))
      return true;
  }

  return false;
}

float Controller::Impl::opacity() const
{
  return opacity_;
}

Controller::Controller()
  : launcher_width(64)
  , pimpl(new Impl())
{
  UScreen* screen = UScreen::GetDefault();
  screen->changed.connect(sigc::mem_fun(this, &Controller::OnScreenChanged));
  OnScreenChanged(screen->GetPrimaryMonitor(), screen->GetMonitors());

  launcher_width.changed.connect([&] (int width)
  {
    pimpl->SetLauncherWidth(width);
  });
}

Controller::~Controller()
{
  delete pimpl;
}

void Controller::FirstMenuShow()
{
  pimpl->FirstMenuShow();
}

void Controller::SetOpacity(float opacity)
{
  pimpl->SetOpacity(opacity);
}

void Controller::SetOpacityMaximizedToggle(bool enabled)
{
  pimpl->SetOpacityMaximizedToggle(enabled);
}

void Controller::SetMenuShowTimings(int fadein, int fadeout, int discovery,
                                    int discovery_fadein, int discovery_fadeout)
{
  pimpl->SetMenuShowTimings(fadein, fadeout, discovery, discovery_fadein, discovery_fadeout);
}

void Controller::QueueRedraw()
{
  pimpl->QueueRedraw();
}

std::vector<Window> const& Controller::GetTrayXids() const
{
  return pimpl->tray_xids_;
}

Controller::PanelVector& Controller::panels() const
{
  return pimpl->panels_;
}

std::vector<nux::Geometry> Controller::GetGeometries() const
{
  return pimpl->GetGeometries();
}

float Controller::opacity() const
{
  return pimpl->opacity();
}

std::string Controller::GetName() const
{
  return "PanelController";
}

void Controller::AddProperties(GVariantBuilder* builder)
{
  variant::BuilderWrapper(builder)
    .add("opacity", pimpl->opacity());
}

void Controller::OnScreenChanged(int primary_monitor, std::vector<nux::Geometry>& monitors)
{
  pimpl->OnScreenChanged(primary_monitor, monitors, this);
}

} // namespace panel
} // namespace unity
