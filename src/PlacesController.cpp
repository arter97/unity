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

#include "ubus-server.h"
#include "UBusMessages.h"

#include "PlacesController.h"

PlacesController::PlacesController ()
{

  // register interest with ubus so that we get activation messages
  UBusServer *ubus = ubus_server_get_default ();
  ubus_server_register_interest (ubus, UBUS_HOME_BUTTON_ACTIVATED,
                                 (UBusCallback)&PlacesController::ExternalActivation,
                                 this);
  ubus_server_register_interest (ubus, UBUS_PLACE_VIEW_CLOSE_REQUEST,
                                 (UBusCallback)&PlacesController::CloseRequest,
                                 this);

  _factory = new PlaceFactoryFile ();

  _window = new PlacesView ();
  _window->Reference ();
  _window->SetConfigureNotifyCallback(&PlacesController::WindowConfigureCallback, this);
  _window->ShowWindow(false);
  _window->EnableInputWindow(true);
  _window->InputWindowEnableStruts(false);

  _window->OnMouseDownOutsideArea.connect (sigc::mem_fun (this, &PlacesController::RecvMouseDownOutsideOfView));

}

PlacesController::~PlacesController ()
{
  _window->UnReference ();
}

void PlacesController::Show ()
{
  // show called
  _window->Show ();
}

void PlacesController::Hide ()
{
  _window->Hide ();
}

void PlacesController::ToggleShowHide ()
{
  if (_window->IsVisible ())
    Hide ();
  else
    Show ();
}

/* Configure callback for the window */
void
PlacesController::WindowConfigureCallback(int WindowWidth, int WindowHeight, nux::Geometry& geo, void *user_data)
{
  // FIXME: This will be a ratio
  geo = nux::Geometry (66, 24, 938, 500);
}

void
PlacesController::ExternalActivation (GVariant *data, void *val)
{
  PlacesController *self = (PlacesController*)val;
  self->ToggleShowHide ();
}

void
PlacesController::CloseRequest (GVariant *data, void *val)
{
  PlacesController *self = (PlacesController*)val;
  self->Hide ();
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

