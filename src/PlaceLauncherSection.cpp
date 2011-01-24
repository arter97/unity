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

#include "PlaceLauncherIcon.h"

#include "PlaceLauncherSection.h"

PlaceLauncherSection::PlaceLauncherSection (Launcher *launcher)
: _launcher (launcher)
{
  _factory = PlaceFactory::GetDefault ();
  _factory->place_added.connect (sigc::mem_fun (this, &PlaceLauncherSection::OnPlaceAdded));
}

PlaceLauncherSection::~PlaceLauncherSection ()
{

}

void
PlaceLauncherSection::OnPlaceAdded (Place *place)
{
  std::vector<PlaceEntry *> entries = place->GetEntries ();
  std::vector<PlaceEntry *>::iterator i;

  for (i = entries.begin (); i != entries.end (); ++i)
  {
    PlaceEntry *entry = static_cast<PlaceEntry *> (*i);
    PlaceLauncherIcon *icon = new PlaceLauncherIcon (_launcher, entry);

    IconAdded.emit (icon);
  }
}
