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



#include "ResultRenderer.h"

namespace unity
{
namespace dash
{

ResultRenderer::ResultRenderer(NUX_FILE_LINE_DECL)
  : Object(false, NUX_FILE_LINE_PARAM),
    width(50),
    height(50)
{
}

ResultRenderer::~ResultRenderer()
{
}

void ResultRenderer::Render (nux::GraphicsEngine& GfxContext,
                             Result& row,
                             ResultRendererState state,
                             nux::Geometry& geometry)
{
  nux::GetPainter().PushDrawSliceScaledTextureLayer (GfxContext, geometry, nux::eBUTTON_NORMAL, nux::color::White, nux::eAllCorners);
}

void ResultRenderer::Preload (Result& row)
{
  // pre-load the given row
}

void ResultRenderer::Unload (Result& row)
{
  // unload any resources
}


}
}
