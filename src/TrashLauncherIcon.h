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

#ifndef TRASHLAUNCHERICON_H
#define TRASHLAUNCHERICON_H

#include "SimpleLauncherIcon.h"

class TrashLauncherIcon : public SimpleLauncherIcon
{

public:
  TrashLauncherIcon  (Launcher *launcher);
  ~TrashLauncherIcon ();

protected:
  void OnMouseClick (int button);
  void UpdateTrashIcon ();

private:
  static void UpdateTrashIconCb (GObject *source, GAsyncResult *res, gpointer data);

};

#endif // TRASHLAUNCHERICON_H
