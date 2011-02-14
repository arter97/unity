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
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 */

#include "PanelTray.h"

PanelTray::PanelTray ()
: _n_children (0),
  _last_x (0),
  _last_y (0)
{
  _window = gtk_window_new (GTK_WINDOW_POPUP);
  gtk_window_set_type_hint (GTK_WINDOW (_window), GDK_WINDOW_TYPE_HINT_DOCK);
  gtk_window_set_keep_above (GTK_WINDOW (_window), TRUE);
  gtk_window_set_skip_pager_hint (GTK_WINDOW (_window), TRUE);
  gtk_window_set_skip_taskbar_hint (GTK_WINDOW (_window), TRUE);
  gtk_window_resize (GTK_WINDOW (_window), 1, 24);
  gtk_window_move (GTK_WINDOW (_window), 200, 12);
  gtk_widget_set_name (_window, "UnityPanelApplet");
  gtk_widget_set_colormap (_window, gdk_screen_get_rgba_colormap (gdk_screen_get_default ())); 
  gtk_widget_realize (_window);
  gdk_window_set_back_pixmap (_window->window, NULL, FALSE);
  gtk_widget_set_app_paintable (_window, TRUE);
  g_signal_connect (_window, "expose-event", G_CALLBACK (PanelTray::OnTrayExpose), this);

  if (!g_getenv ("UNITY_PANEL_TRAY_DISABLE"))
  {
    _tray = na_tray_new_for_screen (gdk_screen_get_default (),
                                    GTK_ORIENTATION_HORIZONTAL,
                                    (NaTrayFilterCallback)FilterTrayCallback,
                                    this);
    g_signal_connect (na_tray_get_manager (_tray), "tray_icon_removed",
                      G_CALLBACK (PanelTray::OnTrayIconRemoved), this);

    gtk_container_add (GTK_CONTAINER (_window), GTK_WIDGET (_tray));
    gtk_widget_show (GTK_WIDGET (_tray));

    gtk_widget_show_all (_window);
  }
}

PanelTray::~PanelTray ()
{
}

void
PanelTray::Draw (nux::GraphicsEngine& gfx_content, bool force_draw)
{
  nux::Geometry geo = GetGeometry ();

  if (geo.x != _last_x || geo.y != _last_y)
  {
    _last_x = geo.x;
    _last_y = geo.y;

    gtk_window_move (GTK_WINDOW (_window), geo.x, geo.y + 24);
  }
}

Window
PanelTray::GetTrayWindow ()
{
  return GDK_WINDOW_XWINDOW (_window->window);
}

void
PanelTray::Sync ()
{
  SetMinMaxSize (_n_children * 24, 24);
  ComputeChildLayout ();

  QueueDraw ();
}

gboolean
PanelTray::FilterTrayCallback (NaTray *tray, NaTrayChild *icon, PanelTray *self)
{
  char *res_name = NULL;
  char *res_class = NULL;

  na_tray_child_get_wm_class (icon, &res_name, &res_class);
  if (na_tray_child_has_alpha (icon))
    na_tray_child_set_composited (icon, TRUE);

  g_debug ("TrayChild %s: %s %s", na_tray_child_get_title (icon), res_name, res_class);
  
  g_free (res_name);
  g_free (res_class);

  self->_n_children++;  

  g_idle_add ((GSourceFunc)IdleSync, self);
  return TRUE;
}

void
PanelTray::OnTrayIconRemoved (NaTrayManager *manager, NaTrayChild *child, PanelTray *self)
{
  g_idle_add ((GSourceFunc)IdleSync, self);
  self->_n_children--;
}

gboolean
PanelTray::IdleSync (PanelTray *self)
{
  self->Sync ();
  return FALSE;
}

gboolean
PanelTray::OnTrayExpose (GtkWidget *widget, GdkEventExpose *ev, PanelTray *tray)
{
  cairo_t *cr = gdk_cairo_create (widget->window);
  GtkAllocation alloc;

  gtk_widget_get_allocation (widget, &alloc);

  gdk_cairo_region (cr, ev->region);
  cairo_clip (cr);

  cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
  cairo_paint (cr);

  cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
  cairo_set_source_rgba (cr, 0.0f, 0.0f, 0.0f, 0.0f);
  cairo_rectangle (cr, 0, 0, alloc.width, alloc.height);
  cairo_fill (cr);

  cairo_destroy (cr);

  gtk_container_propagate_expose (GTK_CONTAINER (widget),
                                  gtk_bin_get_child (GTK_BIN (widget)),
                                  ev);

  return FALSE;
}

//
// We don't use these
//
void
PanelTray::OnEntryAdded (IndicatorObjectEntryProxy *proxy)
{

}

void
PanelTray::OnEntryMoved (IndicatorObjectEntryProxy *proxy)
{

}

void
PanelTray::OnEntryRemoved (IndicatorObjectEntryProxy *proxy)
{

}

const gchar *
PanelTray::GetName ()
{
  return "PanelTray";
}

const gchar *
PanelTray::GetChildsName ()
{
  return "";
}

void
PanelTray::AddProperties (GVariantBuilder *builder)
{

}

