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
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 */

#include "UScreen.h"

static UScreen *_default_screen = NULL;

UScreen::UScreen ()
: _refresh_id (0)
{
  GdkScreen *screen;

  screen = gdk_screen_get_default ();
  g_signal_connect (screen, "size-changed",
                    (GCallback)UScreen::Changed, this);
  g_signal_connect (screen, "monitors-changed",
                    (GCallback)UScreen::Changed, this);

  Refresh ();
}

UScreen::~UScreen ()
{
  if (_default_screen == this)
    _default_screen = NULL;

  g_signal_handlers_disconnect_by_func ((gpointer)gdk_screen_get_default (),
                                        (gpointer)UScreen::Changed,
                                        (gpointer)this);
}

UScreen *
UScreen::GetDefault ()
{
  if (G_UNLIKELY (!_default_screen))
    _default_screen = new UScreen ();

  return _default_screen;
}

int
UScreen::GetPrimaryMonitor ()
{
  return gdk_screen_get_primary_monitor (gdk_screen_get_default ());
}

nux::Geometry
UScreen::GetPrimaryMonitorGeometry ()
{
  return _monitors[GetPrimaryMonitor ()];
}

std::vector<nux::Geometry>&
UScreen::GetMonitors ()
{
  return _monitors;
}

void
UScreen::Changed (GdkScreen *screen, UScreen *self)
{
  if (self->_refresh_id)
    return;

  self->_refresh_id = g_idle_add ((GSourceFunc)UScreen::OnIdleChanged, self);
}

gboolean
UScreen::OnIdleChanged (UScreen *self)
{
  self->_refresh_id = 0;
  self->Refresh ();

  return FALSE;
}

void
UScreen::Refresh ()
{
  GdkScreen    *screen;
  int           primary;
  
  screen = gdk_screen_get_default ();
  primary = GetPrimaryMonitor ();

  _monitors.erase (_monitors.begin (), _monitors.end ());

  g_print ("\nScreen geometry changed:\n");

  for (int i = 0; i < gdk_screen_get_n_monitors (screen); i++)
  {
    GdkRectangle rect = { 0 };
    
    gdk_screen_get_monitor_geometry (screen, i, &rect);

    nux::Geometry geo (rect.x, rect.y, rect.width, rect.height);
    _monitors.push_back (geo);

    g_print ("  Monitor %d%s\n", i, i == primary ? "(primary)" : "");
    g_print ("   %dx%dx%dx%d\n", geo.x, geo.y, geo.width, geo.height);
  }
  
  g_print ("\n");

  changed.emit (primary, _monitors);
}
