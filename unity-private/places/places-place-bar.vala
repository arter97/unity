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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

namespace Unity.Places
{
  public class PlaceBar : Ctk.Box
  {
    /* Properties */
    public Shell      shell { get; construct; }
    public PlaceModel model { get; set construct; }

    public PlaceBar (Shell shell, PlaceModel model)
    {
      Object (shell:shell,
              model:model,
              orientation:Ctk.Orientation.HORIZONTAL,
              homogeneous:false,
              spacing:0);
    }

    construct
    {
      foreach (Place place in model)
        {
          var view = new PlaceView (place);
          pack (view, false, true);
          view.show ();
        }
    }

    private override void allocate (Clutter.ActorBox        box,
                                    Clutter.AllocationFlags flags)
    {
      padding = {
        0.0f,
        (float)shell.get_indicators_width (),
        0.0f,
        (float)shell.get_launcher_width_foobar ()};

      base.allocate (box, flags);
    }

    private override void get_preferred_height (float     for_width,
                                                out float min_height,
                                                out float nat_height)
    {
      min_height = 56.0f;
      nat_height = 56.0f;
    }
  }
}

