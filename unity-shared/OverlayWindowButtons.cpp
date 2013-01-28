/*
 * Copyright (C) 2013 Canonical Ltd
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
 * Authored by: Brandon Schaefer <brandon.schaefer@canonical.com>
 *
 */

#include "OverlayWindowButtons.h"
#include "PanelStyle.h"
#include "UScreen.h"

const int MAIN_LEFT_PADDING = 4;
const int MENUBAR_PADDING = 4;

namespace unity
{

OverlayWindowButtons::OverlayWindowButtons()
  : nux::BaseWindow("OverlayWindowButtons")
  , window_buttons_(new WindowButtons())
{
  UpdateGeometry();
  SetBackgroundColor(nux::color::Transparent);
}

void OverlayWindowButtons::UpdateGeometry()
{
  int monitor = unity::UScreen::GetDefault()->GetMonitorWithMouse();
  nux::Geometry const& geo = unity::UScreen::GetDefault()->GetMonitorGeometry(monitor);

  SetX(geo.x + MAIN_LEFT_PADDING);
  SetY(geo.y + MENUBAR_PADDING);
  SetHeight(panel::Style::Instance().panel_height);

  window_buttons_->monitor = monitor;
}

void OverlayWindowButtons::AboutToShow()
{
  UpdateGeometry();
  ShowWindow(true);
  PushToFront();
  QueueDraw();
}

void OverlayWindowButtons::AboutToHide()
{
  ShowWindow(false);
  PushToBack();
  QueueDraw();
}

nux::Area* OverlayWindowButtons::FindAreaUnderMouse(nux::Point const& mouse_position,
                                                 nux::NuxEventType event_type)
{
  return window_buttons_->FindAreaUnderMouse(mouse_position, event_type);
}

void OverlayWindowButtons::Draw(nux::GraphicsEngine& gfx_context, bool force_draw)
{
  window_buttons_->ProcessDraw(gfx_context, true);
}

} // namespace unity
