// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2013 Canonical Ltd
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
 * Authored by: Marco Trevisan <marco.trevisan@canonical.com>
 */

#include <NuxCore/Logger.h>
#include <X11/cursorfont.h>
#include <sigc++/adaptors/hide.h>
#include "glow_texture.h"
#include "DecorationsDataPool.h"

namespace unity
{
namespace decoration
{
namespace
{
DECLARE_LOGGER(logger, "unity.decoration.datapool");
const std::string PLUGIN_NAME = "unityshell";
const int BUTTONS_SIZE = 16;
const int BUTTONS_PADDING = 1;
const cu::SimpleTexture::Ptr EMPTY_BUTTON;
Display* dpy = nullptr;

unsigned EdgeTypeToCursorShape(Edge::Type type)
{
  switch (type)
  {
    case Edge::Type::TOP:
      return XC_top_side;
    case Edge::Type::TOP_LEFT:
      return XC_top_left_corner;
    case Edge::Type::TOP_RIGHT:
      return XC_top_right_corner;
    case Edge::Type::LEFT:
      return XC_left_side;
    case Edge::Type::RIGHT:
      return XC_right_side;
    case Edge::Type::BOTTOM:
      return XC_bottom_side;
    case Edge::Type::BOTTOM_LEFT:
      return XC_bottom_left_corner;
    case Edge::Type::BOTTOM_RIGHT:
      return XC_bottom_right_corner;
    default:
      return XC_left_ptr;
  }
}

}

DataPool::DataPool()
{
  dpy = screen->dpy();
  SetupCursors();
  SetupTextures();

  auto cb = sigc::hide(sigc::mem_fun(this, &DataPool::SetupTextures));
  Style::Get()->theme.changed.connect(cb);
}

DataPool::~DataPool()
{
  for (auto cursor : edge_cursors_)
    XFreeCursor(dpy, cursor);
}

DataPool::Ptr const& DataPool::Get()
{
  static DataPool::Ptr data_pool(new DataPool());
  return data_pool;
}

void DataPool::SetupCursors()
{
  for (unsigned c = 0; c < edge_cursors_.size(); ++c)
    edge_cursors_[c] = XCreateFontCursor(dpy, EdgeTypeToCursorShape(Edge::Type(c)));
}

Cursor DataPool::EdgeCursor(Edge::Type type) const
{
  return edge_cursors_[unsigned(type)];
}

void DataPool::SetupTextures()
{
  CompSize size;
  CompString plugin_name(PLUGIN_NAME);
  auto const& style = Style::Get();

  for (unsigned button = 0; button < window_buttons_.size(); ++button)
  {
    for (unsigned state = 0; state < window_buttons_[button].size(); ++state)
    {
      auto file = style->WindowButtonFile(WindowButtonType(button), WidgetState(state));
      auto const& tex_list = GLTexture::readImageToTexture(file, plugin_name, size);

      if (!tex_list.empty())
      {
        LOG_DEBUG(logger) << "Loading texture " << file;
        window_buttons_[button][state] = std::make_shared<cu::SimpleTexture>(tex_list);
      }
      else
      {
        LOG_WARN(logger) << "Impossible to load local button texture file; "
                         << "falling back to cairo generated one";

        cu::CairoContext ctx(BUTTONS_SIZE + BUTTONS_PADDING*2, BUTTONS_SIZE + BUTTONS_PADDING*2);
        cairo_translate(ctx, BUTTONS_PADDING, BUTTONS_PADDING);
        style->DrawWindowButton(WindowButtonType(button), WidgetState(state), ctx, BUTTONS_SIZE, BUTTONS_SIZE);
        window_buttons_[button][state] = ctx;
      }
    }
  }

  CompSize glow_size(texture::GLOW_SIZE, texture::GLOW_SIZE);
  glow_texture_ = std::make_shared<cu::SimpleTexture>(GLTexture::imageDataToTexture(texture::GLOW, glow_size, GL_RGBA, GL_UNSIGNED_BYTE));
}

cu::SimpleTexture::Ptr const& DataPool::GlowTexture() const
{
  return glow_texture_;
}

cu::SimpleTexture::Ptr const& DataPool::ButtonTexture(WindowButtonType wbt, WidgetState ws) const
{
  if (wbt >= WindowButtonType::Size || ws >= WidgetState::Size)
  {
    LOG_ERROR(logger) << "It has been requested an invalid button texture "
                      << "WindowButtonType: " << unsigned(wbt) << ", WidgetState: "
                      << unsigned(ws);
    return EMPTY_BUTTON;
  }

  return window_buttons_[unsigned(wbt)][unsigned(ws)];
}

} // decoration namespace
} // unity namespace
