/*
 * Copyright (C) 2011 Canonical Ltd
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
 * Authored by: Jason Smith <jason.smith@canonical.com>
 */

#include "config.h"

#include "SwitcherView.h"
#include "IconRenderer.h"

#include <NuxCore/Object.h>
#include <Nux/Nux.h>
#include <Nux/WindowCompositor.h>

using namespace unity::ui;

namespace unity {
namespace switcher {

NUX_IMPLEMENT_OBJECT_TYPE (SwitcherView);

SwitcherView::SwitcherView(NUX_FILE_LINE_DECL) 
: View (NUX_FILE_LINE_PARAM)
, target_sizes_set_ (false)
{
  icon_renderer_ = AbstractIconRenderer::Ptr (new IconRenderer ());
  border_size = 80;
  flat_spacing = 8;
  icon_size = 128;
  minimum_spacing = 20;
  tile_size = 170;

  background_texture_ = nux::CreateTexture2DFromFile (PKGDATADIR"/switcher_background.png", -1, true);
}

SwitcherView::~SwitcherView()
{
  
}

static int
DeltaTTime (struct timespec const *x, struct timespec const *y)
{
  return ((x->tv_sec - y->tv_sec) * 1000) + ((x->tv_nsec - y->tv_nsec) / 1000000);
}

void SwitcherView::SetModel (SwitcherModel::Ptr model)
{
  model_ = model;
  model->selection_changed.connect (sigc::mem_fun (this, &SwitcherView::OnSelectionChanged));
}

void SwitcherView::OnSelectionChanged (AbstractLauncherIcon *selection)
{
  QueueDraw ();
}

SwitcherModel::Ptr SwitcherView::GetModel ()
{
  return model_;
}

long SwitcherView::ProcessEvent (nux::IEvent &ievent, long TraverseInfo, long ProcessEventInfo)
{
  return TraverseInfo;
}

void SwitcherView::Draw (nux::GraphicsEngine& GfxContext, bool force_draw)
{
  return;
}

RenderArg SwitcherView::CreateBaseArgForIcon (AbstractLauncherIcon *icon)
{
  RenderArg arg;
  arg.icon = icon;
  arg.alpha = 0.95f;

  arg.backlight_intensity = 1.0f;
  if (icon == model_->Selection ())
    arg.keyboard_nav_hl = true;

  return arg;
}

RenderArg SwitcherView::InterpolateRenderArgs (RenderArg const& start, RenderArg const& end, float progress)
{
  RenderArg result = end;

  result.x_rotation = start.x_rotation + (end.x_rotation - start.x_rotation) * progress;
  result.y_rotation = start.y_rotation + (end.y_rotation - start.y_rotation) * progress;
  result.z_rotation = start.z_rotation + (end.z_rotation - start.z_rotation) * progress;

  result.render_center.x = start.render_center.x + (end.render_center.x - start.render_center.x) * progress;
  result.render_center.y = start.render_center.y + (end.render_center.y - start.render_center.y) * progress;
  result.render_center.z = start.render_center.z + (end.render_center.z - start.render_center.z) * progress;

  result.logical_center = result.render_center;

  return result;
}

std::list<RenderArg> SwitcherView::RenderArgs (nux::Geometry& background_geo, AbstractLauncherIcon *selection, timespec const& current)
{
  std::list<RenderArg> results;
  nux::Geometry base = GetGeometry ();

  background_geo.y = base.y + base.height / 2 - 150;
  background_geo.height = 300;

  if (model_)
  {
    int size = model_->Size ();
    int max_width = base.width - border_size * 2;
    int padded_tile_size = tile_size + flat_spacing * 2;
    int flat_width = size * padded_tile_size;
    float x = 0;

    int overflow = flat_width - max_width;

    if (overflow < 0)
    {
      background_geo.x = base.x - overflow / 2;
      background_geo.width = base.width + overflow;

      x -= overflow / 2;
      overflow = 0;
    }
    else
    {
      background_geo.x = base.x;
      background_geo.width = base.width;
    }

    float partial_overflow = (float) overflow / (float) (model_->Size () - 1);
    float partial_overflow_scalar = (float) (padded_tile_size - partial_overflow) / (float) (padded_tile_size); 

    SwitcherModel::iterator it;
    int i = 0;
    int y = base.y + base.height / 2;
    x += border_size;
    bool seen_selected = false;
    for (it = model_->begin (); it != model_->end (); ++it)
    {
      RenderArg arg = CreateBaseArgForIcon (*it);

      float scalar = partial_overflow_scalar;
      bool is_selection = arg.icon == selection;
      if (is_selection)
      {
        seen_selected = true;
        scalar = 1.0f;
      }

      x += flat_spacing * scalar;
      
      x += (tile_size / 2) * scalar;

      if (is_selection)
        arg.render_center = nux::Point3 ((int) x, y, 0);
      else
        arg.render_center = nux::Point3 (x, y, 0);

      x += (tile_size / 2 + flat_spacing) * scalar;

      arg.y_rotation = (1.0f - scalar) * 0.75f;
      
      if (!is_selection && overflow > 0)
      {
        if (seen_selected)
        {
          arg.render_center.x -= 20;
        }
        else
        {
          arg.render_center.x += 20;
          arg.y_rotation = -arg.y_rotation;
        }
      }

      arg.render_center.z = abs (60.0f * arg.y_rotation);

      arg.logical_center = arg.render_center;
      results.push_back (arg);
      ++i;
    }

    timespec last_change_time = model_->SelectionChangeTime ();
    int ms_since_change = DeltaTTime (&current, &last_change_time);
    if (overflow > 0 && selection == model_->Selection () && selection != model_->LastSelection () && ms_since_change < 150)
    {
      float progress = (float) ms_since_change / 150.0f;

      nux::Geometry last_geo;
      std::list<RenderArg> start = RenderArgs (last_geo, model_->LastSelection (), current);
      std::list<RenderArg> end = results;

      results.clear ();

      std::list<RenderArg>::iterator start_it, end_it;
      for (start_it = start.begin (), end_it = end.begin (); start_it != start.end (); ++start_it, ++end_it)
      {
        results.push_back (InterpolateRenderArgs (*start_it, *end_it, progress));
      }
    }
  }

  return results;
}

static gboolean on_draw_queue_timeout (gpointer data)
{
  SwitcherView *self = (SwitcherView *) data;

  self->QueueDraw ();
  return false;
}

void SwitcherView::DrawContent (nux::GraphicsEngine &GfxContext, bool force_draw)
{
  timespec current;
  clock_gettime (CLOCK_MONOTONIC, &current);

  if (!target_sizes_set_)
  {
    icon_renderer_->SetTargetSize (tile_size, icon_size, 10);
    target_sizes_set_ = true;
  }

  nux::Geometry base = GetGeometry ();
  GfxContext.PushClippingRectangle (base);

  nux::ROPConfig ROP;
  ROP.Blend = false;
  ROP.SrcBlend = GL_ONE;
  ROP.DstBlend = GL_ONE_MINUS_SRC_ALPHA;

  // clear region
  gPainter.PushDrawColorLayer(GfxContext, base, nux::Color(0x00000000), true, ROP);

  nux::Geometry background_geo;
  std::list<RenderArg> args = RenderArgs (background_geo, model_->Selection (), current);

  //nux::Geometry background_geo (base.x, base.y + base.height / 2 - 150, base.width, 300);
  gPainter.PaintTextureShape (GfxContext, background_geo, background_texture_, 30, 30, 30, 30, false);

  icon_renderer_->PreprocessIcons (args, base);

  GfxContext.GetRenderStates ().SetPremultipliedBlend (nux::SRC_OVER);
  std::list<RenderArg>::iterator it;
  for (it = args.begin (); it != args.end (); ++it)
  {
    if (it->y_rotation < 0)
      icon_renderer_->RenderIcon (GfxContext, *it, base, base);
  }

  std::list<RenderArg>::reverse_iterator rit;
  for (rit = args.rbegin (); rit != args.rend (); ++rit)
  {
    if (rit->y_rotation >= 0)
      icon_renderer_->RenderIcon (GfxContext, *rit, base, base);
  }

  GfxContext.PopClippingRectangle();

  timespec last_change_time = model_->SelectionChangeTime ();
  int ms_since_change = DeltaTTime (&current, &last_change_time);

  if (ms_since_change < 150)
    g_timeout_add (0, on_draw_queue_timeout, this);
}



}
}
