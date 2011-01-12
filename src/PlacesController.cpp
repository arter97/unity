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
 * Authored by: Gordon Allott <gord.allott@canonical.com>
 */

#include "config.h"

#include "Nux/Nux.h"
#include "Nux/HLayout.h"

#include "NuxGraphics/GLThread.h"
#include <glib.h>
#include <pango/pangocairo.h>
#include <gtk/gtk.h>

#include "../libunity/ubus-server.h"
#include "UBusMessages.h"

#include "PlacesController.h"

PlacesController::PlacesController ()
{

  // register interest with ubus so that we get activation messages
  UBusServer *ubus = ubus_server_get_default ();
  ubus_server_register_interest (ubus, UBUS_HOME_BUTTON_ACTIVATED,
                                 (UBusCallback)&PlacesController::ExternalActivation,
                                 this);

  _Window = new PlacesView ();
  _Window->Reference ();
  _Window->SetConfigureNotifyCallback(&PlacesController::WindowConfigureCallback, this);
  //_Window->SetBlurredBackground(true);
  _Window->ShowWindow(false);
  //_Window->EnableInputWindow(false);
  //_Window->InputWindowEnableStruts(false);

  _Window->OnMouseDownOutsideArea.connect (sigc::mem_fun (this, &PlacesController::RecvMouseDownOutsideOfView));

}

PlacesController::~PlacesController ()
{
  _Window->UnReference ();
}

void PlacesController::Show ()
{
  // show called
  _Window->Show ();
}

void PlacesController::Hide ()
{
  _Window->Hide ();
}

void PlacesController::ToggleShowHide ()
{
  if (_Window->IsVisible ())
    Hide ();
  else
    Show ();
}

/* Configure callback for the window */
void
PlacesController::WindowConfigureCallback(int WindowWidth, int WindowHeight, nux::Geometry& geo, void *user_data)
{
  GdkScreen *screen = gdk_screen_get_default ();
  int height = gdk_screen_get_height (screen) - 12;
  geo = nux::Geometry(32, 12, 1024, height);
}

void
PlacesController::ExternalActivation (GVariant *data, void *val)
{
  PlacesController *self = (PlacesController*)val;
  self->ToggleShowHide ();
}

void
PlacesController::RecvMouseDownOutsideOfView  (int x, int y, unsigned long button_flags, unsigned long key_flags)
{
  Hide ();
}

/* Introspection */
const gchar *
PlacesController::GetName ()
{
  return "PlacesController";
}

void
PlacesController::AddProperties (GVariantBuilder *builder)
{
}

