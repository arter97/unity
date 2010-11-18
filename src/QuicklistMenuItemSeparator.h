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
 * Authored by: Mirco Müller <mirco.mueller@canonical.com>
 */

#ifndef QUICKLISTMENUITEMSEPARATOR_H
#define QUICKLISTMENUITEMSEPARATOR_H

#include "Nux/Nux.h"
#include "Nux/View.h"
#include "QuicklistMenuItem.h"

#if defined(NUX_OS_LINUX)
#include <X11/Xlib.h>
#endif

class QuicklistMenuItemSeparator : public QuicklistMenuItem
{
  public:
    QuicklistMenuItemSeparator (DbusmenuMenuitem* item,
                                NUX_FILE_LINE_PROTO);

    QuicklistMenuItemSeparator (DbusmenuMenuitem* item,
                                bool              debug,
                                NUX_FILE_LINE_PROTO);

    ~QuicklistMenuItemSeparator ();

  private:
    nux::BaseTexture* _normalTexture;
    void UpdateTextures ();
};

#endif // QUICKLISTMENUITEMSEPARATOR_H
