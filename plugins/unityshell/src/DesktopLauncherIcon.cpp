// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2010 Canonical Ltd
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

#include "DesktopLauncherIcon.h"
#include "WindowManager.h"

#include <glib/gi18n-lib.h>

namespace unity
{
namespace launcher
{

DesktopLauncherIcon::DesktopLauncherIcon(Launcher* IconManager)
  :   SimpleLauncherIcon(IconManager)
{
  tooltip_text = _("Show Desktop");
  icon_name = "desktop";
  SetQuirk(QUIRK_VISIBLE, true);
  SetQuirk(QUIRK_RUNNING, true);
  SetIconType(TYPE_BEGIN);
}

DesktopLauncherIcon::~DesktopLauncherIcon()
{
}

nux::Color
DesktopLauncherIcon::BackgroundColor()
{
  return nux::Color(0xFF333333);
}

nux::Color
DesktopLauncherIcon::GlowColor()
{
  return nux::Color(0xFF333333);
}

void
DesktopLauncherIcon::ActivateLauncherIcon(ActionArg arg)
{
  SimpleLauncherIcon::ActivateLauncherIcon(arg);
  WindowManager::Default()->ShowDesktop();
}

} // namespace launcher
} // namespace unity
