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
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 */

#ifndef _PLACE_LAUNCHER_ICON_H__H
#define _PLACE_LAUNCHER_ICON_H__H

#include "PlaceEntry.h"

#include "SimpleLauncherIcon.h"


class PlaceLauncherIcon : public SimpleLauncherIcon
{

public:
  PlaceLauncherIcon  (Launcher *launcher, PlaceEntry *entry);
  ~PlaceLauncherIcon ();
  
  virtual nux::Color BackgroundColor ();
  virtual nux::Color GlowColor ();

protected:
  void OnMouseClick (int button);
  void UpdatePlaceIcon ();
  std::list<DbusmenuMenuitem *> GetMenus ();

private:
  void Activate (guint section_id, const char *search_string);
  void OnActiveChanged (bool is_active);
  static void OnOpen (DbusmenuMenuitem *item, int time, PlaceLauncherIcon *self);

private:
  PlaceEntry *_entry;
};

#endif // _PLACE_LAUNCHER_ICON_H__H
