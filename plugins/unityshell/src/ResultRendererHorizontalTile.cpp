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



#include "ResultRendererHorizontalTile.h"
#include <sstream>
#include <pango/pango.h>
#include <pango/pangocairo.h>
#include <gdk/gdk.h>
#include <gtk/gtk.h>

#include <UnityCore/GLibWrapper.h>

#include "IconLoader.h"
#include "IconTexture.h"
#include "PlacesStyle.h"
#include "TextureCache.h"

//~ namespace
//~ {
//~ nux::logging::Logger logger("unity.dash.ResultRendererHorizontalTile");
//~ }

namespace unity
{
namespace dash
{

ResultRendererHorizontalTile::ResultRendererHorizontalTile(NUX_FILE_LINE_DECL)
  : ResultRenderer(NUX_FILE_LINE_PARAM)
{
  PlacesStyle* style = PlacesStyle::GetDefault();
  width = style->GetTileWidth() * 2;
  height = style->GetTileIconSize() + 4;

  // pre-load the highlight texture
  // try and get a texture from the texture cache
  TextureCache* cache = TextureCache::GetDefault();
  prelight_cache_ = cache->FindTexture("ResultRendererHorizontalTile.PreLightTexture",
                                       style->GetTileIconSize() + 8, style->GetTileIconSize() + 8,
                                       sigc::mem_fun(this, &ResultRendererHorizontalTile::DrawHighlight));
}

ResultRendererHorizontalTile::~ResultRendererHorizontalTile()
{
}

void ResultRendererHorizontalTile::Render(nux::GraphicsEngine& GfxContext,
                                Result& row,
                                ResultRendererState state,
                                nux::Geometry& geometry,
                                int x_offset, int y_offset)
{
  std::string row_text = row.name;
  std::string row_iconhint = row.icon_hint;
  LocalTextureCache::iterator it;
  PlacesStyle* style = PlacesStyle::GetDefault();

  // set up our texture mode
  nux::TexCoordXForm texxform;
  texxform.SetWrap(nux::TEXWRAP_REPEAT, nux::TEXWRAP_REPEAT);
  texxform.SetTexCoordType(nux::TexCoordXForm::OFFSET_COORD);


  // clear what is behind us
  nux::t_u32 alpha = 0, src = 0, dest = 0;

  GfxContext.GetRenderStates().GetBlend(alpha, src, dest);
  GfxContext.GetRenderStates().SetBlend(true, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

  nux::Color col = nux::color::Black;
  col.alpha = 0;
  GfxContext.QRP_Color(geometry.x,
                       geometry.y,
                       geometry.width,
                       geometry.height,
                       col);

  it = blurred_icon_cache_.find(row_iconhint);
  if (it != blurred_icon_cache_.end())
  {
    nux::BaseTexture* icon_texture = it->second;

    GfxContext.QRP_1Tex(geometry.x + 2 - x_offset,
                        geometry.y + ((geometry.height - style->GetTileIconSize()) / 2 - y_offset),
                        style->GetTileIconSize() + 4,
                        style->GetTileIconSize() + 4,
                        icon_texture->GetDeviceTexture(),
                        texxform,
                        nux::Color(0.5f, 0.5f, 0.5f, 0.5f));
  }

  // render highlight if its needed
  if (state != ResultRendererState::RESULT_RENDERER_NORMAL)
  {
    GfxContext.QRP_1Tex(geometry.x,
                        geometry.y + ((geometry.height - style->GetTileIconSize()) / 2) - 4,
                        style->GetTileIconSize() + 8,
                        style->GetTileIconSize() + 8,
                        prelight_cache_->GetDeviceTexture(),
                        texxform,
                        nux::Color(1.0f, 1.0f, 1.0f, 1.0f));
  }

  std::stringstream name;
  std::string rowname = row.name();
  std::string comment = row.comment;
  name  << row.name() << "\n<span size=\"small\">" << comment << "</span>";
  it = text_cache_.find(name.str());

  if (it != text_cache_.end())
  {
    nux::BaseTexture* text_texture = it->second;

    GfxContext.QRP_1Tex(geometry.x + style->GetTileIconSize() + 6,
                        geometry.y + 2,
                        width() - style->GetTileIconSize(),
                        style->GetTileIconSize() - 4,
                        text_texture->GetDeviceTexture(),
                        texxform,
                        nux::Color(1.0f, 1.0f, 1.0f, 1.0f));


  }

  // draw the icon
  it = icon_cache_.find(row_iconhint);
  if (it != icon_cache_.end())
  {
    nux::BaseTexture* icon_texture = it->second;

    GfxContext.QRP_1Tex(geometry.x + 4,
                        geometry.y + ((geometry.height - style->GetTileIconSize()) / 2),
                        style->GetTileIconSize(),
                        style->GetTileIconSize(),
                        icon_texture->GetDeviceTexture(),
                        texxform,
                        nux::Color(1.0f, 1.0f, 1.0f, 1.0f));
  }

  GfxContext.GetRenderStates().SetBlend(alpha, src, dest);

}

void ResultRendererHorizontalTile::DrawHighlight(const char* texid, int width, int height, nux::BaseTexture** texture)
{
  nux::CairoGraphics* cairo_graphics = new nux::CairoGraphics(CAIRO_FORMAT_ARGB32, width, height);
  cairo_t* cr = cairo_graphics->GetContext();

  cairo_scale(cr, 1.0f, 1.0f);

  cairo_set_source_rgba(cr, 1.0, 1.0, 1.0, 0.0);
  cairo_set_operator(cr, CAIRO_OPERATOR_CLEAR);
  cairo_paint(cr);

  int PADDING = 4;
  int BLUR_SIZE = 5;

  int bg_width = width - PADDING - BLUR_SIZE;
  int bg_height = height - PADDING - BLUR_SIZE;
  int bg_x = BLUR_SIZE - 1;
  int bg_y = BLUR_SIZE - 1;

  // draw the glow
  cairo_set_operator(cr, CAIRO_OPERATOR_OVER);
  cairo_set_line_width(cr, 1.0f);
  cairo_set_source_rgba(cr, 1.0f, 1.0f, 1.0f, 0.75f);
  cairo_graphics->DrawRoundedRectangle(cr,
                                       1.0f,
                                       bg_x,
                                       bg_y,
                                       5.0,
                                       bg_width,
                                       bg_height,
                                       true);
  cairo_fill(cr);

  cairo_graphics->BlurSurface(BLUR_SIZE - 2);

  cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
  cairo_graphics->DrawRoundedRectangle(cr,
                                       1.0,
                                       bg_x,
                                       bg_y,
                                       5.0,
                                       bg_width,
                                       bg_height,
                                       true);
  cairo_clip(cr);
  cairo_set_operator(cr, CAIRO_OPERATOR_OVER);

  cairo_graphics->DrawRoundedRectangle(cr,
                                       1.0,
                                       bg_x,
                                       bg_y,
                                       5.0,
                                       bg_width,
                                       bg_height,
                                       true);
  cairo_set_source_rgba(cr, 240 / 255.0f, 240 / 255.0f, 240 / 255.0f, 1.0f);
  cairo_fill_preserve(cr);

  cairo_set_source_rgba(cr, 1.0f, 1.0f, 1.0f, 1.0);
  cairo_stroke(cr);

  cairo_destroy(cr);

  nux::NBitmapData* bitmap =  cairo_graphics->GetBitmap();
  nux::BaseTexture* tex = nux::GetGraphicsDisplay()->GetGpuDevice()->CreateSystemCapableTexture();
  tex->Update(bitmap);
  *texture = tex;

  delete bitmap;
  delete cairo_graphics;
}

void ResultRendererHorizontalTile::Preload(Result& row)
{
  std::string icon_hint = row.icon_hint;
  LoadIcon(icon_hint);

  std::stringstream name;
  std::string rowname = row.name();
  std::string comment = row.comment;
  name  << row.name() << "\n<span size=\"small\">" << comment << "</span>";
  std::string final_string = name.str();

  LoadText(final_string);

 }

void ResultRendererHorizontalTile::Unload(Result& row)
{
  std::string icon = row.icon_hint;
  std::string text = row.name;

  LocalTextureCache::iterator iterator;

  if ((iterator = icon_cache_.find(icon)) != icon_cache_.end())
  {
    iterator->second->UnReference();
  }

  if ((iterator = text_cache_.find(text)) != text_cache_.end())
  {
    iterator->second->UnReference();
  }

  if ((iterator = blurred_icon_cache_.find(icon)) != blurred_icon_cache_.end())
  {
    iterator->second->UnReference();
  }
}

void ResultRendererHorizontalTile::LoadIcon(std::string& icon_hint)
{
#define DEFAULT_GICON ". GThemedIcon text-x-preview"

  std::string icon_name;
  gsize tmp4;
  gchar* tmp5 = (gchar*)g_base64_decode("VU5JVFlfTkVLTw==", &tmp4);
  if (g_getenv(tmp5))
  {
    int tmp1 = 48 + (rand() % 16) - 8;
    gsize tmp3;
    gchar* tmp2 = (gchar*)g_base64_decode("aHR0cDovL3BsYWNla2l0dGVuLmNvbS8laS8laS8=", &tmp3);
    icon_name = g_strdup_printf(tmp2, tmp1, tmp1);
    g_free(tmp2);
  }
  else
  {
    icon_name = !icon_hint.empty() ? icon_hint : DEFAULT_GICON;
  }
  g_free(tmp5);

  if (icon_cache_.find(icon_hint) == icon_cache_.end())
  {
    // if the icon is already loading, just add a note to increase the reference count
    if (currently_loading_icons_.count(icon_name) > 0)
    {
      currently_loading_icons_[icon_name] += 1;
    }
    else
    {
      GIcon*  icon;
      icon = g_icon_new_for_string(icon_name.c_str(), NULL);

      if (g_str_has_prefix(icon_name.c_str(), "http://"))
      {
        IconLoader::GetDefault()->LoadFromURI(icon_name.c_str(), 48,
                                              sigc::bind(sigc::mem_fun(this, &ResultRendererHorizontalTile::IconLoaded), icon_hint));
      }
      else if (G_IS_ICON(icon))
      {
        IconLoader::GetDefault()->LoadFromGIconString(icon_name.c_str(), 48,
                                                      sigc::bind(sigc::mem_fun(this, &ResultRendererHorizontalTile::IconLoaded), icon_name));
        g_object_unref(icon);
      }
      else
      {
        IconLoader::GetDefault()->LoadFromIconName(icon_name.c_str(), 48,
                                                   sigc::bind(sigc::mem_fun(this, &ResultRendererHorizontalTile::IconLoaded), icon_name));
      }

      currently_loading_icons_[icon_name] = 1;
    }
  }
  else
  {
    nux::BaseTexture* texture = icon_cache_.find(icon_name)->second;
    texture->Reference();
  }
}

void
ResultRendererHorizontalTile::CreateTextureCallback(const char* texid,
                                          int width,
                                          int height,
                                          nux::BaseTexture** texture,
                                          GdkPixbuf* pixbuf)
{
  nux::BaseTexture* texture2D = nux::CreateTexture2DFromPixbuf(pixbuf, true);
  *texture = texture2D;
}

void ResultRendererHorizontalTile::CreateBlurredTextureCallback(const char* texid,
                                                      int width,
                                                      int height,
                                                      nux::BaseTexture** texture,
                                                      GdkPixbuf* pixbuf)
{
  nux::CairoGraphics* cairo_graphics = new nux::CairoGraphics(CAIRO_FORMAT_ARGB32, width + 10, height + 10);
  cairo_t* cr = cairo_graphics->GetContext();

  cairo_scale(cr, 1.0f, 1.0f);

  cairo_set_source_rgba(cr, 1.0, 1.0, 1.0, 0.0);
  cairo_set_operator(cr, CAIRO_OPERATOR_CLEAR);
  cairo_translate(cr, 5, 5);
  cairo_paint(cr);

  cairo_set_operator(cr, CAIRO_OPERATOR_OVER);
  gdk_cairo_set_source_pixbuf(cr, pixbuf, 0, 0);
  cairo_translate(cr, 5, 5);
  cairo_paint(cr);

  cairo_graphics->BlurSurface(4);

  nux::NBitmapData* bitmap =  cairo_graphics->GetBitmap();
  nux::BaseTexture* tex = nux::GetGraphicsDisplay()->GetGpuDevice()->CreateSystemCapableTexture();
  tex->Update(bitmap);
  *texture = tex;
}


void
ResultRendererHorizontalTile::IconLoaded(const char* texid, guint size, GdkPixbuf* pixbuf, std::string icon_name)
{
  if (pixbuf)
  {
    TextureCache* cache = TextureCache::GetDefault();
    nux::BaseTexture* texture = cache->FindTexture(icon_name.c_str(), 48, 48,
                                                   sigc::bind(sigc::mem_fun(this, &ResultRendererHorizontalTile::CreateTextureCallback), pixbuf));
    icon_cache_[icon_name] = texture;
    texture->object_destroyed.connect([&icon_cache_, icon_name](Object * obj)
    {
      icon_cache_.erase(icon_cache_.find(icon_name));
    });

    std::string blur_texid = icon_name + "_blurred";

    nux::BaseTexture* texture_blurred = cache->FindTexture(blur_texid.c_str(), 48, 48,
                                                           sigc::bind(sigc::mem_fun(this, &ResultRendererHorizontalTile::CreateBlurredTextureCallback), pixbuf));
    blurred_icon_cache_[icon_name] = texture_blurred;

    texture_blurred->object_destroyed.connect([&blurred_icon_cache_, icon_name](Object * obj)
    {
      blurred_icon_cache_.erase(blurred_icon_cache_.find(icon_name));
    });

    for (uint i = 0; i < currently_loading_icons_[icon_name]; i++)
    {
      texture->Reference();
      texture_blurred->Reference();
    }
    currently_loading_icons_.erase(icon_name);

    NeedsRedraw.emit();
  }
}


void ResultRendererHorizontalTile::LoadText(std::string& text)
{
  if (text_cache_.find(text) == text_cache_.end())
  {
    PlacesStyle*          style      = PlacesStyle::GetDefault();
    nux::CairoGraphics _cairoGraphics(CAIRO_FORMAT_ARGB32,
                                      width() - style->GetTileIconSize(),
                                      height() - 4);

    cairo_t* cr = cairo_reference(_cairoGraphics.GetContext());

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

    pango_layout_set_font_description(layout, desc);
    pango_layout_set_alignment(layout, PANGO_ALIGN_LEFT);

    pango_layout_set_wrap(layout, PANGO_WRAP_WORD_CHAR);
    pango_layout_set_ellipsize(layout, PANGO_ELLIPSIZE_START);
    pango_layout_set_width(layout, (width() - style->GetTileIconSize())* PANGO_SCALE);
    pango_layout_set_height(layout, (height() - 4) * PANGO_SCALE);

    pango_layout_set_markup(layout, text.c_str(), -1);

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

    nux::NBitmapData* bitmap = _cairoGraphics.GetBitmap();

    nux::BaseTexture* texture;

    texture = nux::GetGraphicsDisplay()->GetGpuDevice()->CreateSystemCapableTexture();
    texture->Update(bitmap);

    texture->SinkReference();

    text_cache_[text] = texture;
    texture->object_destroyed.connect([&text_cache_, text](Object * obj)
    {
      text_cache_.erase(text_cache_.find(text));
    });

    delete bitmap;

    cairo_destroy(cr);
  }
  else
  {
    nux::BaseTexture* texture = text_cache_.find(text)->second;
    texture->Reference();
  }
}


}
}
