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
 * Authored by: Mirco Müller <mirco.mueller@canonical.com>
 */

#ifndef QUICKLISTMENUITEMRADIO_H
#define QUICKLISTMENUITEMRADIO_H

#include <Nux/Nux.h>
#include <Nux/View.h>
#include <NuxImage/CairoGraphics.h>

#include "QuicklistMenuItem.h"

#include <X11/Xlib.h>

class QuicklistMenuItemRadio : public QuicklistMenuItem
{
public:
  QuicklistMenuItemRadio(DbusmenuMenuitem* item,
                         NUX_FILE_LINE_PROTO);

  QuicklistMenuItemRadio(DbusmenuMenuitem* item,
                         bool              debug,
                         NUX_FILE_LINE_PROTO);

  ~QuicklistMenuItemRadio();

protected:
  void PreLayoutManagement();

  long PostLayoutManagement(long layoutResult);

  long ProcessEvent(nux::IEvent& event,
                    long         traverseInfo,
                    long         processEventInfo);

  void Draw(nux::GraphicsEngine& gfxContext,
            bool                 forceDraw);

  void DrawContent(nux::GraphicsEngine& gfxContext,
                   bool                 forceDraw);

  void PostDraw(nux::GraphicsEngine& gfxContext,
                bool                 forceDraw);

  void Initialize(DbusmenuMenuitem* item);

  virtual void UpdateTexture();
  virtual int CairoSurfaceWidth();
};

#endif // QUICKLISTMENUITEMRADIO_H
