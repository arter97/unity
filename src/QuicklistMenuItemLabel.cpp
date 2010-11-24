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
 * Authored by: Jay Taoko <jay.taoko@canonical.com>
 */

#include "Nux/Nux.h"
#include "QuicklistMenuItemLabel.h"

#define ITEM_INDENT_ABS        20
#define ITEM_CORNER_RADIUS_ABS 4

QuicklistMenuItemLabel::QuicklistMenuItemLabel (DbusmenuMenuitem* item,
                                                        NUX_FILE_LINE_DECL) :
QuicklistMenuItem (item,
                   NUX_FILE_LINE_PARAM)
{
  Initialize (item);
}

QuicklistMenuItemLabel::QuicklistMenuItemLabel (DbusmenuMenuitem* item,
                                                        bool              debug,
                                                        NUX_FILE_LINE_DECL) :
QuicklistMenuItem (item,
                   debug,
                   NUX_FILE_LINE_PARAM)
{
  Initialize (item);
}

void
QuicklistMenuItemLabel::Initialize (DbusmenuMenuitem* item)
{
  _fontName   = TEXT ("Ubuntu");
  _fontSize   = 12;
  _fontStyle  = FONTSTYLE_NORMAL;
  _fontWeight = FONTWEIGHT_NORMAL;
  _item_type  = MENUITEM_TYPE_LABEL;
  
  if (item)
    _text = dbusmenu_menuitem_property_get (item, DBUSMENU_MENUITEM_PROP_LABEL);
  else
    _text = "Label";
  
  _fontOpts   = cairo_font_options_create ();
  _normalTexture[0]   = NULL;
  _normalTexture[1]   = NULL;
  _prelightTexture[0] = NULL;
  _prelightTexture[1] = NULL;

  // FIXME: hard-coding these for the moment, as we don't have
  // gsettings-support in place right now
  cairo_font_options_set_antialias (_fontOpts, CAIRO_ANTIALIAS_SUBPIXEL);
  cairo_font_options_set_hint_metrics (_fontOpts, CAIRO_HINT_METRICS_ON);
  cairo_font_options_set_hint_style (_fontOpts, CAIRO_HINT_STYLE_SLIGHT);
  cairo_font_options_set_subpixel_order (_fontOpts, CAIRO_SUBPIXEL_ORDER_RGB);

  // make sure _dpiX and _dpiY are initialized correctly
  GetDPI (_dpiX, _dpiY);

  int textWidth = 1;
  int textHeight = 1;
  GetTextExtents (textWidth, textHeight);
  SetMinimumSize (textWidth + ITEM_INDENT_ABS, textHeight);
}

QuicklistMenuItemLabel::~QuicklistMenuItemLabel ()
{
  cairo_font_options_destroy (_fontOpts);

  if (_normalTexture[0])
    _normalTexture[0]->UnReference ();

  if (_normalTexture[1])
    _normalTexture[1]->UnReference ();

  if (_prelightTexture[0])
    _prelightTexture[0]->UnReference ();

  if (_prelightTexture[1])
    _prelightTexture[1]->UnReference ();
}

void
QuicklistMenuItemLabel::PreLayoutManagement ()
{
  _pre_layout_width = GetBaseWidth ();
  _pre_layout_height = GetBaseHeight ();

  if (_normalTexture[0] == 0)
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
  nux::IntrusiveSP<nux::IOpenGLBaseTexture> texture;

  nux::Geometry base = GetGeometry ();

  gfxContext.PushClippingRectangle (base);

  nux::TexCoordXForm texxform;
  texxform.SetWrap (nux::TEXWRAP_REPEAT, nux::TEXWRAP_REPEAT);
  texxform.SetTexCoordType (nux::TexCoordXForm::OFFSET_COORD);

  gfxContext.GetRenderStates().SetBlend (true,
                                         GL_ONE,
                                         GL_ONE_MINUS_SRC_ALPHA);

//   if (GetActive ())
//   {
//     if (GetEnabled ())
//       texture = _prelightTexture[1]->GetDeviceTexture ();
//     else
//       texture = _prelightTexture[0]->GetDeviceTexture ();
//   }
//   else
//   {
//     if (GetEnabled ())
//       texture = _normalTexture[1]->GetDeviceTexture ();
//     else
//       texture = _normalTexture[0]->GetDeviceTexture ();
//   }
  
  if (_enabled)
  {
    if (_prelight)
    {
      texture = _prelightTexture[0]->GetDeviceTexture ();
    }
    else
    {
      texture = _normalTexture[0]->GetDeviceTexture ();
    }
    _color = nux::Color::White;
  }
  else
  {
    texture = _normalTexture[0]->GetDeviceTexture ();
    _color = nux::Color::DarkGray;
  }
  
  gfxContext.QRP_GLSL_1Tex (base.x,
                            base.y,
                            base.width,
                            base.height,
                            texture,
                            texxform,
                            _color);

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
QuicklistMenuItemLabel::DrawText (cairo_t*   cr,
                                      int        width,
                                      int        height,
                                      nux::Color color)
{
  int                   textWidth  = 0;
  int                   textHeight = 0;
  PangoLayout*          layout     = NULL;
  PangoFontDescription* desc       = NULL;
  PangoContext*         pangoCtx   = NULL;

  nux::NString str = nux::NString::Printf(TEXT("%s %.2f"),
                                          _fontName.GetTCharPtr (),
                                          _fontSize);
  GetTextExtents (str.GetTCharPtr (), textWidth, textHeight);

  cairo_set_font_options (cr, _fontOpts);
  layout = pango_cairo_create_layout (cr);
  //desc = pango_font_description_from_string ((char*) FONT_FACE);
  desc = pango_font_description_from_string (str.GetTCharPtr ());
  pango_font_description_set_weight (desc, (PangoWeight) _fontWeight);
  pango_layout_set_font_description (layout, desc);
  pango_layout_set_wrap (layout, PANGO_WRAP_WORD_CHAR);
  pango_layout_set_ellipsize (layout, PANGO_ELLIPSIZE_END);
  pango_layout_set_markup (layout, _text.GetTCharPtr(), -1);
  pangoCtx = pango_layout_get_context (layout); // is not ref'ed
  pango_cairo_context_set_font_options (pangoCtx, _fontOpts);
  pango_cairo_context_set_resolution (pangoCtx, (double) _dpiX);

  //cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
  //cairo_set_source_rgba (cr, 0.0f, 0.0f, 0.0f, 0.0f);
  //cairo_paint (cr);
  //cairo_set_source_rgba (cr, color.R (),color.G (), color.B (), color.A ());

  pango_layout_context_changed (layout);

  cairo_move_to (cr, ITEM_INDENT_ABS, (float) (height - textHeight) / 2.0f);
  pango_cairo_show_layout (cr, layout);

  // clean up
  pango_font_description_free (desc);
  g_object_unref (layout);
}

void
QuicklistMenuItemLabel::UpdateTexture ()
{
  nux::Color transparent = nux::Color (0.0f, 0.0f, 0.0f, 0.0f);
  int        width       = GetBaseWidth ();
  int        height      = GetBaseHeight ();
  
  _cairoGraphics = new nux::CairoGraphics (CAIRO_FORMAT_ARGB32, width, height);
  cairo_t *cr = _cairoGraphics->GetContext ();

  // draw normal, unchecked version
  cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
  cairo_paint (cr);

  cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
  cairo_scale (cr, 1.0f, 1.0f);
  cairo_set_source_rgba (cr, 1.0f, 1.0f, 1.0f, 1.0f);
  cairo_set_line_width (cr, 1.0f);

  DrawText (cr, width, height, nux::Color::White);

  //cairo_surface_write_to_png (cairo_get_target (cr), "/tmp/normal-unchecked.png");

  nux::NBitmapData* bitmap = _cairoGraphics->GetBitmap ();

  if (_normalTexture[0])
    _normalTexture[0]->UnReference ();

  _normalTexture[0] = nux::GetThreadGLDeviceFactory()->CreateSystemCapableTexture ();
  _normalTexture[0]->Update (bitmap);

  // draw active/prelight, unchecked version
  cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
  cairo_paint (cr);

  cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
  cairo_scale (cr, 1.0f, 1.0f);
  cairo_set_source_rgba (cr, 1.0f, 1.0f, 1.0f, 1.0f);
  cairo_set_line_width (cr, 1.0f);

  DrawRoundedRectangle (cr,
                        1.0f,
                        0.5f,
                        0.5f,
                        ITEM_CORNER_RADIUS_ABS,
                        width - 1.0f,
                        height - 1.0f);
  cairo_fill (cr);

  cairo_set_source_rgba (cr, 0.0f, 0.0f, 0.0f, 0.0f);

  DrawText (cr, width, height, transparent);

  //cairo_surface_write_to_png (cairo_get_target (cr), "/tmp/active-unchecked.png");

  bitmap = _cairoGraphics->GetBitmap ();

  if (_prelightTexture[0])
    _prelightTexture[0]->UnReference ();

  _prelightTexture[0] = nux::GetThreadGLDeviceFactory()->CreateSystemCapableTexture ();
  _prelightTexture[0]->Update (bitmap);

  // finally clean up
  delete _cairoGraphics;
}

void
QuicklistMenuItemLabel::DrawRoundedRectangle (cairo_t* cr,
                                                  double   aspect,
                                                  double   x,
                                                  double   y,
                                                  double   cornerRadius,
                                                  double   width,
                                                  double   height)
{
    double radius = cornerRadius / aspect;

    // top-left, right of the corner
    cairo_move_to (cr, x + radius, y);

    // top-right, left of the corner
    cairo_line_to (cr, x + width - radius, y);

    // top-right, below the corner
    cairo_arc (cr,
               x + width - radius,
               y + radius,
               radius,
               -90.0f * G_PI / 180.0f,
               0.0f * G_PI / 180.0f);

    // bottom-right, above the corner
    cairo_line_to (cr, x + width, y + height - radius);

    // bottom-right, left of the corner
    cairo_arc (cr,
               x + width - radius,
               y + height - radius,
               radius,
               0.0f * G_PI / 180.0f,
               90.0f * G_PI / 180.0f);

    // bottom-left, right of the corner
    cairo_line_to (cr, x + radius, y + height);

    // bottom-left, above the corner
    cairo_arc (cr,
               x + radius,
               y + height - radius,
               radius,
               90.0f * G_PI / 180.0f,
               180.0f * G_PI / 180.0f);

    // top-left, right of the corner
    cairo_arc (cr,
               x + radius,
               y + radius,
               radius,
               180.0f * G_PI / 180.0f,
               270.0f * G_PI / 180.0f);
}

int QuicklistMenuItemLabel::CairoSurfaceWidth ()
{
  if (_normalTexture[0])
    return _normalTexture[0]->GetWidth ();

  return 0;
}
