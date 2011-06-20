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

#include "config.h"
#include "Nux/Nux.h"

#include "FilterRatingsWidget.h"

namespace unity {

  FilterRatings::FilterRatings (NUX_FILE_LINE_DECL)
      : nux::Button (NUX_FILE_LINE_PARAM)
      , rating (this, "rating") {
    InitTheme();

    OnMouseDown.connect (sigc::mem_fun (this, &FilterRatings::RecvMouseDown) );
    rating.changed.connect (sigc::mem_fun (this, &FilterRatings::OnRatingsChanged) );
  }

  FilterRatings::~FilterRatings() {
    delete _full_normal;
    delete _full_prelight;
    delete _half_normal;
    delete _half_prelight;
    delete _empty_normal;
    delete _empty_prelight;
  }

  void FilterRatings::SetFilter(void *filter)
  {
    _filter = filter;
    //FIXME - we need to get detail from the filter,
    //such as name and link to its signals
    rating = 5;
  }

  std::string FilterRatings::GetFilterType ()
  {
    return "FilterBasicButton";
  }


  void FilterRatings::InitTheme()
  {
    g_debug ("init theme");
    //FIXME - build theme here - store images, cache them, fun fun fun
    // ratings bar requires us to store/create three states for stares, half open, selected/unselected

    //these should be cached and shared between widgets if at all possible
    _full_prelight = new nux::ColorLayer (nux::Color (1.0, 1.0, 1.0, 1.0));
    _full_normal = new nux::ColorLayer (nux::Color (0.8, 0.8, 0.8, 1.0));

    _empty_prelight = new nux::ColorLayer (nux::Color (0.7, 0.0, 0.0, 1.0));
    _empty_normal = new nux::ColorLayer (nux::Color (0.5, 0.0, 0.0, 1.0));

    _half_prelight = new nux::ColorLayer (nux::Color (0.0, 0.0, 0.7, 1.0));
    _half_normal = new nux::ColorLayer (nux::Color (0.0, 0.0, 0.5, 1.0));
  }


  long int FilterRatings::ProcessEvent(nux::IEvent& ievent, long int TraverseInfo, long int ProcessEventInfo) {
    return nux::Button::ProcessEvent(ievent, TraverseInfo, ProcessEventInfo);
  }

  void FilterRatings::Draw(nux::GraphicsEngine& GfxContext, bool force_draw) {

    //FIXME - i disabled the crappy drawing i was doing,
    //should just draw five sliced textures,
    //int total_full_stars = rating / 2;
    //int total_half_stars = rating % 2;

    nux::Geometry geometry = GetGeometry ();
    /*g_debug ("widget geometry is %i, %i - %ix%i",geometry.x, geometry.y, geometry.width, geometry.height);
    geometry.width = geometry.width / 5;

    g_debug ("doing draw");

    for (int index = 0; index < 5; index++) {
      g_debug ("drawing star");
      geometry.x += index * geometry.width;

      g_debug ("drawing at %i,%i - %ix%i", geometry.x, geometry.y, geometry.width, geometry.height);

      nux::AbstractPaintLayer *render_layer;
      if (index < total_full_stars) {
        render_layer = _full_normal;
      }
      else if (index < total_full_stars + total_half_stars) {
        render_layer = _half_normal;
      }
      else {
        render_layer = _empty_normal;
      }
      */

      //nux::GetPainter().PushDrawSliceScaledTextureLayer (GfxContext, GetGeometry (), nux::eBUTTON_FOCUS, nux::color::White, nux::eAllCorners);
      g_debug ("drawing a texture layer");
      nux::ROPConfig blend = nux::ROPConfig();
      blend.Blend = true;

      nux::ColorLayer *layer = new nux::ColorLayer (nux::Color (1.0, 1.0, 1.0, 0.0), true, blend);
      //layer->Renderlayer (GfxContext);
      nux::GetPainter ().RenderSinglePaintLayer (GfxContext, GetGeometry (), layer);

      //GfxContext.QRP_Color (GetGeometry ().x, GetGeometry ().y, GetGeometry ().GetWidth(), GetGeometry ().GetHeight(), nux::Color (1.0, 1.0, 1.0, 1.0));
    //}
  }

  void FilterRatings::DrawContent(nux::GraphicsEngine& GfxContext, bool force_draw) {
    //FIXME - i swear i didn't change anything, but suddenly nux stopped drawing the contents of the button
    nux::Button::DrawContent(GfxContext, force_draw);
  }

  void FilterRatings::PostDraw(nux::GraphicsEngine& GfxContext, bool force_draw) {
    nux::Button::PostDraw(GfxContext, force_draw);
  }

  void FilterRatings::RecvMouseDown (int x, int y, unsigned long button_flags, unsigned long key_flags) {
    //FIXME - ripped out the code that detected which star you clicked on, it was awful and hacky
    //FIXME - set the rating based on which star was clicked on
  }


  void FilterRatings::OnRatingsChanged (int rating) {
    QueueDraw(); // make sure the view reflects whatever the latest rating is
    // FIXME - once we have shared library objects, update those too
  }

};
