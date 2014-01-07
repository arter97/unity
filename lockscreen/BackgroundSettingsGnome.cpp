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
* Authored by: Andrea Azzarone <andrea.azzarone@canonical.com>
*/

#include "BackgroundSettingsGnome.h"

#include <libgnome-desktop/gnome-bg.h>

#include "unity-shared/GtkTexture.h"

namespace unity 
{
namespace lockscreen
{
namespace
{
const std::string SETTINGS_NAME = "org.gnome.desktop.background";
const int GRID_SIZE = 40;
}

BackgroundSettingsGnome::BackgroundSettingsGnome()
  : gnome_bg_(gnome_bg_new())
  , settings_(g_settings_new(SETTINGS_NAME.c_str()))
{
  gnome_bg_load_from_preferences(gnome_bg_, settings_);

  // FIXME: does not work. Investigate!
  bg_changed_.Connect(gnome_bg_, "changed", [this] (GnomeBG*) {
    bg_changed.emit();
  });
}

int get_grid_offset (int size)
{
    return (size % GRID_SIZE) / 2;
}


BaseTexturePtr BackgroundSettingsGnome::GetBackgroundTexture(nux::Size const& size, bool draw_grid)
{
  cairo_surface_t* cairo_surface = gnome_bg_create_surface(gnome_bg_, gdk_get_default_root_window(),
                                                           size.width, size.height, FALSE);
  cairo_t* c = cairo_create(cairo_surface);

  if (draw_grid)
  {
    int width = size.width;
    int height = size.height;
    int grid_x_offset = get_grid_offset(width);
    int grid_y_offset = get_grid_offset(height);

    // overlay grid
    cairo_surface_t* overlay_surface = cairo_surface_create_similar(cairo_surface,
                                                                    CAIRO_CONTENT_COLOR_ALPHA,
                                                                    GRID_SIZE,
                                                                    GRID_SIZE);

    cairo_t* oc = cairo_create(overlay_surface);
    cairo_rectangle(oc, 0, 0, 1, 1);
    cairo_rectangle(oc, GRID_SIZE - 1, 0, 1, 1);
    cairo_rectangle(oc, 0, GRID_SIZE - 1, 1, 1);
    cairo_rectangle(oc, GRID_SIZE - 1, GRID_SIZE - 1, 1, 1);
    cairo_set_source_rgba(oc, 1.0, 1.0, 1.0, 0.25);
    cairo_fill(oc);

    cairo_pattern_t* overlay = cairo_pattern_create_for_surface(overlay_surface);

    cairo_matrix_t matrix;
    cairo_matrix_init_identity(&matrix);
    cairo_matrix_translate(&matrix, -grid_x_offset, -grid_y_offset);

    cairo_pattern_set_matrix(overlay, &matrix);
    cairo_pattern_set_extend(overlay, CAIRO_EXTEND_REPEAT);

    cairo_save(c);
    cairo_set_source(c, overlay);
    cairo_rectangle(c, 0, 0, width, height);
    cairo_fill(c);
    cairo_restore(c);

    cairo_pattern_destroy(overlay);
    cairo_surface_destroy(overlay_surface);
    cairo_destroy(oc);
  }

  GdkPixbuf* gdk_pixbuf = gdk_pixbuf_get_from_surface(cairo_surface, 0, 0, 
                                                      size.width, size.height);

  cairo_destroy(c);
  cairo_surface_destroy(cairo_surface);

  return texture_ptr_from_gdk_graphics(nux::GdkGraphics(gdk_pixbuf));
}

        /*overlay.set_matrix (matrix);
        overlay.set_extend (Cairo.Extend.REPEAT);

        // Draw overlay
        c.save ();
        c.set_source (overlay);
        c.rectangle (0, 0, width, height);
        c.fill ();
        c.restore ();
    }
    */

} // lockscreen
} // unity