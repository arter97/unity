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
 * Authored by: Jay Taoko <jay.taoko@canonical.com>
 * Authored by: Mirco Müller <mirco.mueller@canonical.com>
 */

#ifndef STATICCAIROTEXT_H
#define STATICCAIROTEXT_H

#include "Nux/Nux.h"
#include "Nux/View.h"
//#include "NuxGraphics/OpenGLEngine.h"
#include "Nux/TextureArea.h"
#include "NuxImage/CairoGraphics.h"

#include <pango/pango.h>
#include <pango/pangocairo.h>

#if defined(NUX_OS_LINUX)
#include <X11/Xlib.h>
#endif

namespace nux
{
  class Validator;

  class StaticCairoText : public View
  {
    public:
      typedef enum
      {
        NUX_ELLIPSIZE_END,
        NUX_ELLIPSIZE_START,
        NUX_ELLIPSIZE_MIDDLE,
        NUX_ELLIPSIZE_NONE,
      } EllipsizeState;

      typedef enum
      {
        NUX_ALIGN_LEFT,
        NUX_ALIGN_CENTRE,
        NUX_ALIGN_RIGHT,
      } AlignState;

      StaticCairoText (const TCHAR* text, NUX_FILE_LINE_PROTO);

      ~StaticCairoText ();

      void PreLayoutManagement ();

      long PostLayoutManagement (long layoutResult);

      long ProcessEvent (IEvent& event,
                         long    traverseInfo,
                         long    processEventInfo);

      void Draw (GraphicsEngine& gfxContext,
                 bool             forceDraw);

      void DrawContent (GraphicsEngine& gfxContext,
                        bool             forceDraw);

      void PostDraw (GraphicsEngine& gfxContext,
                     bool             forceDraw);

      // public API
      void SetText (NString text);
      void SetTextColor (Color textColor);
      void SetTextEllipsize (EllipsizeState state);
      void SetTextAlignment (AlignState state);
      void SetFont (const char *fontstring);

      void GetTextExtents (int &width, int &height);

      sigc::signal<void, StaticCairoText*> sigTextChanged;
      sigc::signal<void, StaticCairoText*> sigTextColorChanged;
      sigc::signal<void, StaticCairoText*> sigFontChanged;

    private:
      int            _cached_extent_width;
      int            _cached_extent_height;
      bool           _need_new_extent_cache;
      
      NString        _text;
      Color          _textColor;
      EllipsizeState _ellipsize;
      AlignState     _align;
      char*           _fontstring;

      CairoGraphics* _cairoGraphics;
      BaseTexture*   _texture2D;

      int            _pre_layout_width;
      int            _pre_layout_height;
      
      void GetTextExtents (const TCHAR* font,
                           int&         width,
                           int&         height);
      void DrawText (cairo_t* cr,
                     int      width,
                     int      height,
                     Color    color);

      void UpdateTexture ();

      static void OnFontChanged (GObject *gobject, GParamSpec *pspec,
                                 gpointer data);
  };
}

#endif // STATICCAIROTEXT_H
