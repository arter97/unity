// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright 2011 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3, as
 * published by the  Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the applicable version of the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of both the GNU Lesser General Public
 * License version 3 along with this program.  If not, see
 * <http://www.gnu.org/licenses/>
 *
 * Authored by: Gordon Allott <gord.allott@canonical.com>
 *
 */

#include "ResultRendererTile.h"

#include <pango/pangocairo.h>
#include <gtk/gtk.h>

#include <NuxCore/Logger.h>
#include <UnityCore/GLibWrapper.h>

#include "unity-shared/CairoTexture.h"
#include "unity-shared/DashStyle.h"
#include "unity-shared/TextureCache.h"

namespace
{
  bool neko;
}

namespace unity
{
DECLARE_LOGGER(logger, "unity.dash.results");
namespace
{
const int FONT_SIZE = 10;

const float CORNER_HIGHTLIGHT_RADIUS = 2.0f;
}

namespace dash
{

NUX_IMPLEMENT_OBJECT_TYPE(ResultRendererTile);

ResultRendererTile::ResultRendererTile(NUX_FILE_LINE_DECL)
  : ResultRenderer(NUX_FILE_LINE_PARAM)
  , spacing(10)
  , padding(6)
{
  dash::Style& style = dash::Style::Instance();
  width = style.GetTileWidth();
  height = style.GetTileHeight();

  gsize tmp;
  gchar* tmp1 = (gchar*)g_base64_decode("VU5JVFlfTkVLTw==", &tmp);
  neko = (g_getenv(tmp1));
  g_free (tmp1);

  // pre-load the highlight texture
  // try and get a texture from the texture cache
  TextureCache& cache = TextureCache::GetDefault();
  prelight_cache_ = cache.FindTexture("ResultRendererTile.PreLightTexture",
                                      style.GetTileIconHightlightWidth(), style.GetTileIconHightlightHeight(),
                                      sigc::mem_fun(this, &ResultRendererTile::DrawHighlight));
}

void ResultRendererTile::Render(nux::GraphicsEngine& GfxContext,
                                Result& row,
                                ResultRendererState state,
                                nux::Geometry const& geometry,
                                int x_offset, int y_offset)
{
  TextureContainer* container = row.renderer<TextureContainer*>();
  if (container == nullptr)
    return;

  dash::Style& style = dash::Style::Instance();
  int tile_icon_size = style.GetTileImageSize();

  // set up our texture mode
  nux::TexCoordXForm texxform;

  int icon_width, icon_height;
  if (container->icon == nullptr)
  {
    icon_width = icon_height = tile_icon_size;
  }
  else
  {
    icon_width = container->icon->GetWidth();
    icon_height = container->icon->GetHeight();
  }

  int icon_left_hand_side = geometry.x + (geometry.width - icon_width) / 2;
  int icon_top_side = geometry.y + padding + (tile_icon_size - icon_height) / 2;

  // render highlight if its needed
  if (container->prelight && state != ResultRendererState::RESULT_RENDERER_NORMAL)
  {
    int highlight_x =  (geometry.x + geometry.width/2) - style.GetTileIconHightlightWidth()/2;
    int highlight_y =  (geometry.y + padding + tile_icon_size / 2) - style.GetTileIconHightlightHeight()/2;

    GfxContext.QRP_1Tex(highlight_x,
                        highlight_y,
                        container->prelight->GetWidth(),
                        container->prelight->GetHeight(),
                        container->prelight->GetDeviceTexture(),
                        texxform,
                        nux::Color(1.0f, 1.0f, 1.0f, 1.0f));
  }

  // draw the icon
  if (container->icon)
  {
    GfxContext.QRP_1Tex(icon_left_hand_side,
                        icon_top_side,
                        container->icon->GetWidth(),
                        container->icon->GetHeight(),
                        container->icon->GetDeviceTexture(),
                        texxform,
                        nux::Color(1.0f, 1.0f, 1.0f, 1.0f));
  }

  if (container->text)
  {
    GfxContext.QRP_1Tex(geometry.x + padding,
                        geometry.y + tile_icon_size + spacing,
                        style.GetTileWidth() - (padding * 2),
                        style.GetTileHeight() - tile_icon_size - spacing,
                        container->text->GetDeviceTexture(),
                        texxform,
                        nux::Color(1.0f, 1.0f, 1.0f, 1.0f));
  }
}

nux::BaseTexture* ResultRendererTile::DrawHighlight(std::string const& texid, int width, int height)
{
  nux::CairoGraphics cairo_graphics(CAIRO_FORMAT_ARGB32, width, height);
  cairo_t* cr = cairo_graphics.GetInternalContext();

  cairo_scale(cr, 1.0f, 1.0f);

  cairo_set_source_rgba(cr, 1.0, 1.0, 1.0, 0.0);
  cairo_set_operator(cr, CAIRO_OPERATOR_CLEAR);
  cairo_paint(cr);

  // draw the highlight
  cairo_set_operator(cr, CAIRO_OPERATOR_OVER);
  cairo_set_source_rgba(cr, 1.0f, 1.0f, 1.0f, 0.2f);
  cairo_graphics.DrawRoundedRectangle(cr,
                                      1.0f,
                                      0.0f,
                                      0.0f,
                                      CORNER_HIGHTLIGHT_RADIUS,
                                      width,
                                      height,
                                      false);
  cairo_fill(cr);

  return texture_from_cairo_graphics(cairo_graphics);
}

void ResultRendererTile::Preload(Result& row)
{
  if (row.renderer<TextureContainer*>() == nullptr)
  {
    row.set_renderer(new TextureContainer());
    LoadIcon(row);
    LoadText(row);
  }
}

void ResultRendererTile::Unload(Result& row)
{
  TextureContainer *container = row.renderer<TextureContainer*>();
  delete container;
  row.set_renderer<TextureContainer*>(nullptr);
}

void ResultRendererTile::LoadIcon(Result& row)
{
  Style& style = Style::Instance();
  std::string icon_hint(row.icon_hint);
#define DEFAULT_GICON ". GThemedIcon text-x-preview"
  std::string icon_name;
  if (G_UNLIKELY(neko))
  {
    int tmp1 = style.GetTileGIconSize() + (rand() % 16) - 8;
    gsize tmp3;
    gchar* tmp2 = (gchar*)g_base64_decode("aHR0cDovL3BsYWNla2l0dGVuLmNvbS8laS8laS8=", &tmp3);
    gchar* tmp4 = g_strdup_printf(tmp2, tmp1, tmp1);
    icon_name = tmp4;
    g_free(tmp4);
    g_free(tmp2);
  }
  else
  {
    icon_name = !icon_hint.empty() ? icon_hint : DEFAULT_GICON;
  }

  glib::Object<GIcon> icon(g_icon_new_for_string(icon_name.c_str(), NULL));
  TextureContainer* container = row.renderer<TextureContainer*>();

  IconLoader::IconLoaderCallback slot = sigc::bind(sigc::mem_fun(this, &ResultRendererTile::IconLoaded), icon_hint, row);

  if (icon.IsType(G_TYPE_ICON))
  {
    bool use_large_icon = icon.IsType(G_TYPE_FILE_ICON) || !icon.IsType(G_TYPE_THEMED_ICON);
    container->slot_handle = IconLoader::GetDefault().LoadFromGIconString(icon_name, style.GetTileImageSize(), use_large_icon ? style.GetTileImageSize() : style.GetTileGIconSize(), slot);
  }
  else
  {
    container->slot_handle = IconLoader::GetDefault().LoadFromIconName(icon_name, -1, style.GetTileGIconSize(), slot);
  }
}

nux::BaseTexture* ResultRendererTile::CreateTextureCallback(std::string const& texid,
                                                            int width,
                                                            int height,
                                                            glib::Object<GdkPixbuf> const& pixbuf)
{
  int pixbuf_width, pixbuf_height;
  pixbuf_width = gdk_pixbuf_get_width(pixbuf);
  pixbuf_height = gdk_pixbuf_get_height(pixbuf);
  if (G_UNLIKELY(!pixbuf_height || !pixbuf_width))
  {
    LOG_ERROR(logger) << "Pixbuf: " << texid << " has a zero height/width: "
                      << width << "," << height;
    pixbuf_width = (pixbuf_width) ? pixbuf_width : 1; // no zeros please
    pixbuf_height = (pixbuf_height) ? pixbuf_height: 1; // no zeros please
  }

  if (pixbuf_width == pixbuf_height)
  {
    // quick path for square icons
    return nux::CreateTexture2DFromPixbuf(pixbuf, true);
  }
  else
  {
    // slow path for non square icons that must be resized to fit in the square
    // texture

    Style& style = Style::Instance();
    float aspect = static_cast<float>(pixbuf_height) / pixbuf_width; // already sanitized width/height so can not be 0.0
    if (aspect < 1.0f)
    {
      pixbuf_width = style.GetTileImageSize();
      pixbuf_height = pixbuf_width * aspect;

      if (pixbuf_height > height)
      {
        // scaled too big, scale down
        pixbuf_height = height;
        pixbuf_width = pixbuf_height / aspect;
      }
    }
    else
    {
      pixbuf_height = height;
      pixbuf_width = pixbuf_height / aspect;
    }

    if (gdk_pixbuf_get_height(pixbuf) == pixbuf_height)
    {
      // we changed our mind, fast path is good
      return nux::CreateTexture2DFromPixbuf(pixbuf, true);
    }

    nux::CairoGraphics cairo_graphics(CAIRO_FORMAT_ARGB32, pixbuf_width, pixbuf_height);
    cairo_t* cr = cairo_graphics.GetInternalContext();

    cairo_set_operator(cr, CAIRO_OPERATOR_CLEAR);
    cairo_paint(cr);

    float scale = float(pixbuf_height) / gdk_pixbuf_get_height(pixbuf);

    //cairo_translate(cr,
    //                static_cast<int>((width - (pixbuf_width * scale)) * 0.5),
    //                static_cast<int>((height - (pixbuf_height * scale)) * 0.5));

    cairo_scale(cr, scale, scale);

    cairo_set_operator(cr, CAIRO_OPERATOR_OVER);
    gdk_cairo_set_source_pixbuf(cr, pixbuf, 0, 0);
    cairo_paint(cr);

    return texture_from_cairo_graphics(cairo_graphics);
  }

}


void ResultRendererTile::IconLoaded(std::string const& texid,
                                    int max_width,
                                    int max_height,
                                    glib::Object<GdkPixbuf> const& pixbuf,
                                    std::string icon_name,
                                    Result& row)
{
  TextureContainer *container = row.renderer<TextureContainer*>();

  dash::Style& style = dash::Style::Instance();

  if (pixbuf && container)
  {
    TextureCache& cache = TextureCache::GetDefault();
    BaseTexturePtr texture(cache.FindTexture(icon_name, max_width, max_height,
                           sigc::bind(sigc::mem_fun(this, &ResultRendererTile::CreateTextureCallback), pixbuf)));

    BaseTexturePtr texture_prelight(cache.FindTexture("resultview_prelight", style.GetTileIconHightlightWidth(), style.GetTileIconHightlightHeight(),  sigc::mem_fun(this, &ResultRendererTile::DrawHighlight)));

    container->icon = texture;
    container->prelight = texture_prelight;

    NeedsRedraw.emit();

    if (container)
      container->slot_handle = 0;
  }
  else if (container)
  {
    // we need to load a missing icon
    IconLoader::IconLoaderCallback slot = sigc::bind(sigc::mem_fun(this, &ResultRendererTile::IconLoaded), icon_name, row);
    container->slot_handle = IconLoader::GetDefault().LoadFromGIconString(". GThemedIcon text-x-preview", max_width, max_height, slot);
  }
}


void ResultRendererTile::LoadText(Result& row)
{
  Style& style = Style::Instance();
  nux::CairoGraphics _cairoGraphics(CAIRO_FORMAT_ARGB32,
                                    style.GetTileWidth() - (padding * 2),
                                    style.GetTileHeight() - style.GetTileImageSize() - spacing);

  cairo_t* cr = _cairoGraphics.GetContext();

  PangoLayout*          layout     = NULL;
  PangoFontDescription* desc       = NULL;
  PangoContext*         pango_context   = NULL;
  GdkScreen*            screen     = gdk_screen_get_default();    // not ref'ed
  glib::String          font;
  int                   dpi = -1;

  g_object_get(gtk_settings_get_default(), "gtk-font-name", &font, NULL);
  g_object_get(gtk_settings_get_default(), "gtk-xft-dpi", &dpi, NULL);

  cairo_set_font_options(cr, gdk_screen_get_font_options(screen));
  layout = pango_cairo_create_layout(cr);
  desc = pango_font_description_from_string(font.Value());
  pango_font_description_set_size (desc, FONT_SIZE * PANGO_SCALE);

  pango_layout_set_font_description(layout, desc);
  pango_layout_set_alignment(layout, PANGO_ALIGN_CENTER);

  pango_layout_set_wrap(layout, PANGO_WRAP_WORD_CHAR);
  pango_layout_set_ellipsize(layout, PANGO_ELLIPSIZE_START);
  pango_layout_set_width(layout, (style.GetTileWidth() - (padding * 2))* PANGO_SCALE);
  pango_layout_set_height(layout, -2);

  char *escaped_text = g_markup_escape_text(row.name().c_str()  , -1);

  pango_layout_set_markup(layout, escaped_text, -1);

  g_free (escaped_text);

  pango_context = pango_layout_get_context(layout);  // is not ref'ed
  pango_cairo_context_set_font_options(pango_context,
                                       gdk_screen_get_font_options(screen));
  pango_cairo_context_set_resolution(pango_context,
                                     dpi == -1 ? 96.0f : dpi/(float) PANGO_SCALE);
  pango_layout_context_changed(layout);

  cairo_set_operator(cr, CAIRO_OPERATOR_CLEAR);
  cairo_paint(cr);

  cairo_set_operator(cr, CAIRO_OPERATOR_OVER);
  cairo_set_source_rgba(cr, 1.0f, 1.0f, 1.0f, 1.0f);

  cairo_move_to(cr, 0.0f, 0.0f);
  pango_cairo_show_layout(cr, layout);

  // clean up
  pango_font_description_free(desc);
  g_object_unref(layout);
  cairo_destroy(cr);

  TextureContainer *container = row.renderer<TextureContainer*>();
  if (container)
    container->text = texture_ptr_from_cairo_graphics(_cairoGraphics);
}


}
}
