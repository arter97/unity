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

#include <gdk/gdk.h>
#include <gtk/gtk.h>

#include "Nux/Nux.h"
#include "QuicklistMenuItem.h"

#include <X11/Xlib.h>

static void
OnPropertyChanged (gchar*             property,
                   GValue*            value,
                   QuicklistMenuItem* self);

static void
OnItemActivated (guint              timestamp,
                 QuicklistMenuItem* self);

QuicklistMenuItem::QuicklistMenuItem (DbusmenuMenuitem* item,
                                      NUX_FILE_LINE_DECL) :
View (NUX_FILE_LINE_PARAM)
{
  if (item == 0)
  {
    g_warning ("Invalid DbusmenuMenuitem in file %s at line %s.", G_STRFUNC, G_STRLOC);
  }
  
  _name       = 0;
  _text       = 0;
  _color      = nux::Color (1.0f, 1.0f, 1.0f, 1.0f);
  _menuItem   = item;
  _debug      = false;
  _item_type  = MENUITEM_TYPE_UNKNOWN;
  
  _normalTexture[0]   = NULL;
  _normalTexture[1]   = NULL;
  _prelightTexture[0] = NULL;
  _prelightTexture[1] = NULL;
  
  if (_menuItem)
  {
    g_signal_connect (_menuItem,
                    "property-changed",
                    G_CALLBACK (OnPropertyChanged),
                    this);
    g_signal_connect (_menuItem,
                    "item-activated",
                    G_CALLBACK (OnItemActivated),
                    this);
  }
  
  OnMouseDown.connect (sigc::mem_fun (this, &QuicklistMenuItem::RecvMouseDown));
  OnMouseUp.connect (sigc::mem_fun (this, &QuicklistMenuItem::RecvMouseUp));
  OnMouseClick.connect (sigc::mem_fun (this, &QuicklistMenuItem::RecvMouseClick));
  OnMouseMove.connect (sigc::mem_fun (this, &QuicklistMenuItem::RecvMouseMove));
  OnMouseDrag.connect (sigc::mem_fun (this, &QuicklistMenuItem::RecvMouseDrag));
  OnMouseEnter.connect (sigc::mem_fun (this, &QuicklistMenuItem::RecvMouseEnter));
  OnMouseLeave.connect (sigc::mem_fun (this, &QuicklistMenuItem::RecvMouseLeave));

  _prelight = false;
}

QuicklistMenuItem::QuicklistMenuItem (DbusmenuMenuitem* item,
                                      bool              debug,
                                      NUX_FILE_LINE_DECL) :
View (NUX_FILE_LINE_PARAM)
{
  _text       = 0;
  _color      = nux::Color (1.0f, 1.0f, 1.0f, 1.0f);
  _menuItem   = item;
  _debug      = debug;
  _item_type  = MENUITEM_TYPE_UNKNOWN;
  
  _normalTexture[0]   = NULL;
  _normalTexture[1]   = NULL;
  _prelightTexture[0] = NULL;
  _prelightTexture[1] = NULL;
  
  if (_menuItem)
  {
    g_signal_connect (_menuItem,
                    "property-changed",
                    G_CALLBACK (OnPropertyChanged),
                    this);
    g_signal_connect (_menuItem,
                    "item-activated",
                    G_CALLBACK (OnItemActivated),
                    this);
  }
  
  OnMouseDown.connect (sigc::mem_fun (this, &QuicklistMenuItem::RecvMouseDown));
  OnMouseUp.connect (sigc::mem_fun (this, &QuicklistMenuItem::RecvMouseUp));
  OnMouseClick.connect (sigc::mem_fun (this, &QuicklistMenuItem::RecvMouseClick));
  OnMouseMove.connect (sigc::mem_fun (this, &QuicklistMenuItem::RecvMouseMove));
  OnMouseDrag.connect (sigc::mem_fun (this, &QuicklistMenuItem::RecvMouseDrag));
  OnMouseEnter.connect (sigc::mem_fun (this, &QuicklistMenuItem::RecvMouseEnter));
  OnMouseLeave.connect (sigc::mem_fun (this, &QuicklistMenuItem::RecvMouseLeave));

  _prelight = false;
}

QuicklistMenuItem::~QuicklistMenuItem ()
{
  if (_name)
    g_free (_name);
  
  if (_text)
    g_free (_text);
}

QuicklistMenuItemType QuicklistMenuItem::GetItemType ()
{
  return _item_type;
}

void
QuicklistMenuItem::PreLayoutManagement ()
{
  View::PreLayoutManagement ();
}

long
QuicklistMenuItem::PostLayoutManagement (long layoutResult)
{
  long result = View::PostLayoutManagement (layoutResult);

  return result;
}

long
QuicklistMenuItem::ProcessEvent (nux::IEvent& event,
                                 long         traverseInfo,
                                 long         processEventInfo)
{
  long result = traverseInfo;

  result = nux::View::PostProcessEvent2 (event, result, processEventInfo);
  return result;

}

void
QuicklistMenuItem::Draw (nux::GraphicsEngine& gfxContext,
                         bool                 forceDraw)
{
}

void
QuicklistMenuItem::DrawContent (nux::GraphicsEngine& gfxContext,
                                bool                 forceDraw)
{
}

void
QuicklistMenuItem::PostDraw (nux::GraphicsEngine& gfxContext,
                             bool                 forceDraw)
{
}

const gchar*
QuicklistMenuItem::GetLabel ()
{
  if (_menuItem == 0)
    return 0;
  return dbusmenu_menuitem_property_get (_menuItem,
                                         DBUSMENU_MENUITEM_PROP_LABEL);
}

bool
QuicklistMenuItem::GetEnabled ()
{
  if (_menuItem == 0)
    return false;
  return dbusmenu_menuitem_property_get_bool (_menuItem,
                                              DBUSMENU_MENUITEM_PROP_ENABLED);
}

bool
QuicklistMenuItem::GetActive ()
{
  if (_menuItem == 0)
    return false;
  return dbusmenu_menuitem_property_get_bool (_menuItem,
                                              DBUSMENU_MENUITEM_PROP_TOGGLE_STATE) == DBUSMENU_MENUITEM_TOGGLE_STATE_CHECKED;
}

void QuicklistMenuItem::ItemActivated ()
{
  if (_debug)
    sigChanged.emit (*this);

  std::cout << "ItemActivated() called" << std::endl;
}

void QuicklistMenuItem::GetTextExtents (int &width, int &height)
{
  GtkSettings* settings = gtk_settings_get_default (); // not ref'ed
  gchar*       fontName = NULL;

  g_object_get (settings, "gtk-font-name", &fontName, NULL);
  GetTextExtents (fontName, width, height);
  g_free (fontName);
}

void QuicklistMenuItem::GetTextExtents (const gchar* font,
                                        int&         width,
                                        int&         height)
{
  cairo_surface_t*      surface  = NULL;
  cairo_t*              cr       = NULL;
  PangoLayout*          layout   = NULL;
  PangoFontDescription* desc     = NULL;
  PangoContext*         pangoCtx = NULL;
  PangoRectangle        logRect  = {0, 0, 0, 0};
  int                   dpi      = 0;
  GdkScreen*            screen   = gdk_screen_get_default ();   // is not ref'ed
  GtkSettings*          settings = gtk_settings_get_default (); // is not ref'ed

  // sanity check
  if (!font)
    return;

  if (_text == NULL)
    return;
  
  surface = cairo_image_surface_create (CAIRO_FORMAT_A1, 1, 1);
  cr = cairo_create (surface);
  cairo_set_font_options (cr, gdk_screen_get_font_options (screen));
  layout = pango_cairo_create_layout (cr);
  desc = pango_font_description_from_string (font);
  pango_font_description_set_weight (desc, PANGO_WEIGHT_NORMAL);
  pango_layout_set_font_description (layout, desc);
  pango_layout_set_wrap (layout, PANGO_WRAP_WORD_CHAR);
  pango_layout_set_ellipsize (layout, PANGO_ELLIPSIZE_END);
  pango_layout_set_markup_with_accel (layout, _text, -1, '_', NULL);
  pangoCtx = pango_layout_get_context (layout); // is not ref'ed
  pango_cairo_context_set_font_options (pangoCtx,
                                        gdk_screen_get_font_options (screen));
  g_object_get (settings, "gtk-xft-dpi", &dpi, NULL);
  if (dpi == -1)
  {
    // use some default DPI-value
    pango_cairo_context_set_resolution (pangoCtx, 96.0f);
  }
  else
  {
    pango_cairo_context_set_resolution (pangoCtx,
                                        (float) dpi / (float) PANGO_SCALE);
  }
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

static void
OnPropertyChanged (gchar*             property,
                   GValue*            value,
                   QuicklistMenuItem* self)
{
  //todo
  //self->UpdateTexture ();
}

static void
OnItemActivated (guint              timestamp,
                 QuicklistMenuItem* self)
{
  //todo:
  //self->ItemActivated ();
}

void QuicklistMenuItem::RecvMouseDown (int x, int y, unsigned long button_flags, unsigned long key_flags)
{

}

void QuicklistMenuItem::RecvMouseUp (int x, int y, unsigned long button_flags, unsigned long key_flags)
{
  sigMouseReleased.emit (this, x, y);
}

void QuicklistMenuItem::RecvMouseClick (int x, int y, unsigned long button_flags, unsigned long key_flags)
{
  if (!GetEnabled ())
  {
    return;
  }
  sigMouseClick.emit (this, x, y);
}

void QuicklistMenuItem::RecvMouseMove (int x, int y, int dx, int dy, unsigned long button_flags, unsigned long key_flags)
{
  
}

void QuicklistMenuItem::RecvMouseDrag (int x, int y, int dx, int dy, unsigned long button_flags, unsigned long key_flags)
{
    sigMouseDrag.emit (this, x, y);
}

void QuicklistMenuItem::RecvMouseEnter (int x, int y, unsigned long button_flags, unsigned long key_flags)
{
  _prelight = true;
  sigMouseEnter.emit (this);
}

void QuicklistMenuItem::RecvMouseLeave (int x, int y, unsigned long button_flags, unsigned long key_flags)
{
  _prelight = false;
  sigMouseLeave.emit (this);
}

void
QuicklistMenuItem::DrawRoundedRectangle (cairo_t* cr,
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

void
QuicklistMenuItem::DrawText (cairo_t*   cr,
                             int        width,
                             int        height,
                             nux::Color color)
{
  if (_text == NULL)
    return;
  
  int                   textWidth  = 0;
  int                   textHeight = 0;
  PangoLayout*          layout     = NULL;
  PangoFontDescription* desc       = NULL;
  PangoContext*         pangoCtx   = NULL;
  int                   dpi        = 0;
  GdkScreen*            screen     = gdk_screen_get_default ();   // not ref'ed
  GtkSettings*          settings   = gtk_settings_get_default (); // not ref'ed
  gchar*                fontName   = NULL;

  g_object_get (settings, "gtk-font-name", &fontName, NULL);
  GetTextExtents (fontName, textWidth, textHeight);

  cairo_set_font_options (cr, gdk_screen_get_font_options (screen));
  layout = pango_cairo_create_layout (cr);
  desc = pango_font_description_from_string (fontName);
  pango_layout_set_font_description (layout, desc);
  pango_layout_set_wrap (layout, PANGO_WRAP_WORD_CHAR);
  pango_layout_set_ellipsize (layout, PANGO_ELLIPSIZE_END);
  pango_layout_set_markup_with_accel (layout, _text, -1, '_', NULL);
  pangoCtx = pango_layout_get_context (layout); // is not ref'ed
  pango_cairo_context_set_font_options (pangoCtx,
                                        gdk_screen_get_font_options (screen));
  g_object_get (settings, "gtk-xft-dpi", &dpi, NULL);
  if (dpi == -1)
  {
    // use some default DPI-value
    pango_cairo_context_set_resolution (pangoCtx, 96.0f);
  }
  else
  {
    pango_cairo_context_set_resolution (pangoCtx,
                                        (float) dpi / (float) PANGO_SCALE);
  }

  pango_layout_context_changed (layout);

  cairo_move_to (cr,
                 2 * ITEM_MARGIN + ITEM_INDENT_ABS,
                 (float) (height - textHeight) / 2.0f);
  pango_cairo_show_layout (cr, layout);

  // clean up
  pango_font_description_free (desc);
  g_free (fontName);
  g_object_unref (layout);
}

// Introspection

const gchar* QuicklistMenuItem::GetName ()
{
  return g_strdup (_name);
}

void QuicklistMenuItem::AddProperties (GVariantBuilder *builder)
{
  g_variant_builder_add (builder, "{sv}", "text", g_variant_new_string (_text));
  g_variant_builder_add (builder, "{sv}", "x", g_variant_new_int32  (GetBaseX ()));
  g_variant_builder_add (builder, "{sv}", "y", g_variant_new_int32  (GetBaseY ()));
  g_variant_builder_add (builder, "{sv}", "width", g_variant_new_int32 (GetBaseWidth ()));
  g_variant_builder_add (builder, "{sv}", "height", g_variant_new_int32 (GetBaseHeight ()));
  g_variant_builder_add (builder, "{sv}", "enabled", g_variant_new_boolean (GetEnabled ()));
  g_variant_builder_add (builder, "{sv}", "active", g_variant_new_boolean (GetActive ()));
  
}
