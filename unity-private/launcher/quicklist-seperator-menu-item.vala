/* -*- Mode: vala; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
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
 * Authored by Gordon Allott <gord.allott@canonical.com>,
 *             Mirco "MacSlow" Müller <mirco.mueller@canonical.com>
 *
 */

namespace Unity.Launcher
{
  // we subclass Ctk.MenuSeperator here because we need to adapt it's appearance
  public class QuicklistMenuSeperator : Ctk.MenuSeperator
  {
    Ctk.LayerActor seperator_background;
    int            old_width;
    int            old_height;

    private override void
    paint ()
    {
      this.seperator_background.paint ();
    }

    public override void
    get_preferred_height (float     for_width,
                          out float min_height_p,
                          out float natural_height_p)
    {
      min_height_p = (float) Ctk.em_to_pixel (GAP);
      natural_height_p = min_height_p;
    }

    public override void
    get_preferred_width (float for_height,
                         out float min_width_p,
                         out float natural_width_p)
    {
      min_width_p = (float) Ctk.em_to_pixel (2 * MARGIN);
      natural_width_p = min_width_p;
    }

    private override void
    allocate (Clutter.ActorBox        box,
              Clutter.AllocationFlags flags)
    {
      int w;
      int h;

      base.allocate (box, flags);
      w = (int) (box.x2 - box.x1);
      h = (int) (box.y2 - box.y1);

      // exit early if the allocation-width/height didn't change, this is needed
      // because clutter triggers calling allocate even if nothing changed
      if ((old_width == w) && (old_height == h))
        return;

      // before creating a new CtkLayerActor make sure we don't leak any memory
      if (this.seperator_background is Ctk.LayerActor)
        this.seperator_background.destroy ();

      this.seperator_background = new Ctk.LayerActor (w, h);

      Ctk.Layer layer = new Ctk.Layer (w,
                                       h,
                                       Ctk.LayerRepeatMode.NONE,
                                       Ctk.LayerRepeatMode.NONE);
      Cairo.Surface fill_surf = new Cairo.ImageSurface (Cairo.Format.ARGB32,
                                                        w,
                                                        h);
      Cairo.Surface image_surf = new Cairo.ImageSurface (Cairo.Format.ARGB32,
                                                         w,
                                                         h);
      Cairo.Context fill_cr = new Cairo.Context (fill_surf);
      Cairo.Context image_cr = new Cairo.Context (image_surf);

      Unity.QuicklistRendering.Seperator.fill_mask (fill_cr);
      Unity.QuicklistRendering.Seperator.image_background (image_cr, w, h);

      layer.set_mask_from_surface (fill_surf);
      layer.set_image_from_surface (image_surf);
      layer.set_opacity (255);

      this.seperator_background.add_layer (layer);

      //this.set_background (this.seperator_background);
      this.seperator_background.set_opacity (255);

      this.seperator_background.set_parent (this);
      this.seperator_background.map ();
      this.seperator_background.show ();
    }

    construct
    {
      Ctk.Padding padding = Ctk.Padding () {
        left   = (int) Ctk.em_to_pixel (MARGIN),
        right  = (int) Ctk.em_to_pixel (MARGIN),
        top    = (int) Ctk.em_to_pixel (MARGIN),
        bottom = (int) Ctk.em_to_pixel (MARGIN)
      };
      this.set_padding (padding);

      old_width  = 0;
      old_height = 0;
    }
  }
}
