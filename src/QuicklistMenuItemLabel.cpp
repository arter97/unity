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

#include "Nux/Nux.h"
#include "QuicklistMenuItemLabel.h"

QuicklistMenuItemLabel::QuicklistMenuItemLabel (DbusmenuMenuitem* item,
                                                NUX_FILE_LINE_DECL) :
QuicklistMenuItem (item,
                   NUX_FILE_LINE_PARAM)
{
  _fontName   = TEXT ("Ubuntu");
  _fontSize   = 12;
  _fontStyle  = FONTSTYLE_NORMAL;
  _fontWeight = FONTWEIGHT_NORMAL;
  _textColor  = nux::Color(1.0f, 1.0f, 1.0f, 1.0f);
  _text       = TEXT ("");
  _fontOpts   = cairo_font_options_create ();
  _texture2D  = 0;

  // FIXME: hard-coding these for the moment, as we don't have
  // gsettings-support in place right now
  cairo_font_options_set_antialias (_fontOpts, CAIRO_ANTIALIAS_SUBPIXEL);
  cairo_font_options_set_hint_metrics (_fontOpts, CAIRO_HINT_METRICS_ON);
  cairo_font_options_set_hint_style (_fontOpts, CAIRO_HINT_STYLE_SLIGHT);
  cairo_font_options_set_subpixel_order (_fontOpts, CAIRO_SUBPIXEL_ORDER_RGB);

  SetMinimumSize (1, 1);
  // make sure _dpiX and _dpiY are initialized correctly
  GetDPI ();
}

QuicklistMenuItemLabel::QuicklistMenuItemLabel (DbusmenuMenuitem* item,
                                                bool              debug,
                                                NUX_FILE_LINE_DECL) :
QuicklistMenuItem (item,
                   debug,
                   NUX_FILE_LINE_PARAM)
{
}

QuicklistMenuItemLabel::~QuicklistMenuItemLabel ()
{
}

void
QuicklistMenuItemLabel::PreLayoutManagement ()
{
  int textWidth  = 0;
  int textHeight = 0;

  nux::NString str = nux::NString::Printf(TEXT("%s %.2f"), _fontName.GetTCharPtr (), _fontSize);
  GetTextExtents (str.GetTCharPtr (), textWidth, textHeight);

  _pre_layout_width = GetBaseWidth ();
  _pre_layout_height = GetBaseHeight ();

  SetBaseSize (textWidth, textHeight);

  if((_texture2D == 0) )
  {
    UpdateTexture ();
  }

  QuicklistMenuItem::PreLayoutManagement ();
}

long
QuicklistMenuItemLabel::PostLayoutManagement (long layoutResult)
{
  int w = GetBaseWidth();
  int h = GetBaseHeight();

  long result = 0;
  
  if (_pre_layout_width < w)
    result |= nux::eLargerWidth;
  else if (_pre_layout_width > w)
    result |= nux::eSmallerWidth;
  else
    result |= nux::eCompliantWidth;

  if (_pre_layout_height < h)
    result |= nux::eLargerHeight;
  else if (_pre_layout_height > h)
    result |= nux::eSmallerHeight;
  else
    result |= nux::eCompliantHeight;

  return result;
}

long
QuicklistMenuItemLabel::ProcessEvent (nux::IEvent& event,
                                 long         traverseInfo,
                                 long         processEventInfo)
{
  long result = traverseInfo;

  result = nux::View::PostProcessEvent2 (event, result, processEventInfo);
  return result;
}

void
QuicklistMenuItemLabel::Draw (nux::GraphicsEngine& gfxContext,
                         bool                 forceDraw)
{
  nux::Geometry base = GetGeometry ();

  gfxContext.PushClippingRectangle (base);

  nux::TexCoordXForm texxform;
  texxform.SetWrap (nux::TEXWRAP_REPEAT, nux::TEXWRAP_REPEAT);
  texxform.SetTexCoordType (nux::TexCoordXForm::OFFSET_COORD);

  gfxContext.GetRenderStates().SetBlend (true,
                                         GL_ONE,
                                         GL_ONE_MINUS_SRC_ALPHA);

  gfxContext.QRP_GLSL_1Tex (base.x,
                            base.y,
                            base.width,
                            base.height,
                            _texture2D->GetDeviceTexture(),
                            texxform,
                            _textColor);

  gfxContext.GetRenderStates().SetBlend (false);

  gfxContext.PopClippingRectangle ();  
}

void
QuicklistMenuItemLabel::DrawContent (nux::GraphicsEngine& gfxContext,
                                bool                 forceDraw)
{
}

void
QuicklistMenuItemLabel::PostDraw (nux::GraphicsEngine& gfxContext,
                                  bool                 forceDraw)
{
}

void
QuicklistMenuItemLabel::DrawText ()
{
}

void QuicklistMenuItemLabel::GetTextExtents (int &width, int &height)
{
  nux::NString str = nux::NString::Printf(TEXT("%s %.2f"), _fontName.GetTCharPtr (), _fontSize);
  GetTextExtents (str.GetTCharPtr (), width, height);
}

void QuicklistMenuItemLabel::GetTextExtents (const TCHAR* font,
                                      int&  width,
                                      int&  height)
{
  cairo_surface_t*      surface  = NULL;
  cairo_t*              cr       = NULL;
  PangoLayout*          layout   = NULL;
  PangoFontDescription* desc     = NULL;
  PangoContext*         pangoCtx = NULL;
  PangoRectangle        logRect  = {0, 0, 0, 0};

  // sanity check
  if (!font)
    return;

  surface = cairo_image_surface_create (CAIRO_FORMAT_A1, 1, 1);
  cr = cairo_create (surface);
  layout = pango_cairo_create_layout (cr);
  desc = pango_font_description_from_string (font);
  pango_font_description_set_weight (desc, PANGO_WEIGHT_NORMAL);
  pango_layout_set_font_description (layout, desc);
  pango_layout_set_wrap (layout, PANGO_WRAP_WORD_CHAR);
  pango_layout_set_ellipsize (layout, PANGO_ELLIPSIZE_END);
  pango_layout_set_markup (layout, _text.GetTCharPtr(), -1);
  pangoCtx = pango_layout_get_context (layout); // is not ref'ed
  pango_cairo_context_set_font_options (pangoCtx, _fontOpts);
  pango_cairo_context_set_resolution (pangoCtx, _dpiX);
  pango_layout_context_changed (layout);
  pango_layout_get_extents (layout, NULL, &logRect);

  width  = logRect.width / PANGO_SCALE;
  height = logRect.height / PANGO_SCALE;

  // clean up
  pango_font_description_free (desc);
  g_object_unref (layout);
  cairo_destroy (cr);
  cairo_surface_destroy (surface);
}

void
QuicklistMenuItemLabel::UpdateTexture ()
{
  int width = 0;
  int height = 0;
  GetTextExtents(width, height);

  SetBaseSize(width, height);

  _cairoGraphics = new nux::CairoGraphics (CAIRO_FORMAT_ARGB32,
                                      GetBaseWidth (),
                                      GetBaseHeight ());
  cairo_t *cr = _cairoGraphics->GetContext ();

  DrawText (cr, GetBaseWidth (), GetBaseHeight (), _textColor);

  nux::NBitmapData* bitmap = _cairoGraphics->GetBitmap ();

  // NTexture2D is the high level representation of an image that is backed by
  // an actual opengl texture.

  if (_texture2D)
    _texture2D->UnReference ();

  _texture2D = nux::GetThreadGLDeviceFactory()->CreateSystemCapableTexture ();
  _texture2D->Update (bitmap);

  delete _cairoGraphics;
}

void
QuicklistMenuItemLabel::DrawRoundedRectangle ()
{
}

void
QuicklistMenuItemLabel::SetText (nux::NString text)
{
  if (_text != text)
  {
    _text = text;
    UpdateTexture ();
    sigTextChanged.emit (this);
  }
}

void
QuicklistMenuItemLabel::SetFontName (nux::NString fontName)
{
  if (_fontName != fontName)
  {
    _fontName = fontName;
    UpdateTexture ();
    sigTextChanged.emit (this);
  }
}

void
QuicklistMenuItemLabel::SetFontSize (float fontSize)
{
  if (_fontSize != fontSize)
  {
    _fontSize = fontSize;
    UpdateTexture ();
    sigTextChanged.emit (this);
  }
}

void
QuicklistMenuItemLabel::SetFontWeight (FontWeight fontWeight)
{
  if (_fontWeight != fontWeight)
  {
    _fontWeight = fontWeight;
    UpdateTexture ();
    sigTextChanged.emit (this);
  }
}

void
QuicklistMenuItemLabel::SetFontStyle (FontStyle fontStyle)
{
  if (_fontStyle != fontStyle)
  {
    _fontStyle = fontStyle;
    UpdateTexture ();
    sigTextChanged.emit (this);
  }
}

void
QuicklistMenuItemLabel::SetTextColor (nux::Color textColor)
{
  if (_textColor != textColor)
  {
    _textColor = textColor;
    sigTextColorChanged.emit (this);
  }
}