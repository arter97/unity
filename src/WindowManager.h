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

#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <glib.h>

class WindowManager
{
public:

  static WindowManager * Default ();
  static void            SetDefault (WindowManager *manager);

  virtual bool IsWindowMaximized (guint32 xid) = 0;
};

#endif // WINDOW_MANAGER_H
