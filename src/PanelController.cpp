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

#include "PanelController.h"

#include "UScreen.h"

#include "unitya11y.h"
#include "unity-util-accessible.h"

PanelController::PanelController ()
{
  UScreen *screen = UScreen::GetDefault ();

  screen->changed.connect (sigc::mem_fun (this, &PanelController::OnScreenChanged));

  OnScreenChanged (screen->GetPrimaryMonitor (), screen->GetMonitors ());
}

PanelController::~PanelController ()
{

}

void
PanelController::SetPrimary (nux::BaseWindow *window, bool primary)
{
  nux::Layout *layout = window->GetLayout ();
  std::list<nux::Area *>::iterator it = layout->GetChildren ().begin ();

  static_cast<PanelView *> (*it)->SetPrimary (primary);
}

// We need to put a panel on every monitor, and try and re-use the panels we already have
void
PanelController::OnScreenChanged (int primary_monitor, std::vector<nux::Geometry>& monitors)
{
  std::vector<nux::BaseWindow *>::iterator it, eit = _windows.end ();
  int n_monitors = monitors.size ();
  int i = 0;

  for (it = _windows.begin (); it != eit; ++it)
  {
    if (i < n_monitors)
    {
      nux::Geometry geo = monitors[i];
      geo.height = 24;
      (*it)->SetGeometry (geo);
      SetPrimary (*it, i == primary_monitor);
      i++;
    }
  }

  // Add new ones if needed
  if (i < n_monitors)
  {
    for (i = i; i < n_monitors; i++)
    {
      nux::BaseWindow *window;
      PanelView       *view;
      nux::HLayout    *layout;

      layout = new nux::HLayout();
      
      view = new PanelView ();    
      view->SetMaximumHeight (24);
      AddChild (view);

      layout->AddView (view, 1);
      layout->SetContentDistribution (nux::eStackLeft);
      layout->SetVerticalExternalMargin (0);
      layout->SetHorizontalExternalMargin (0);

      window = new nux::BaseWindow("");
      window->SinkReference ();
      window->SetConfigureNotifyCallback(&PanelController::WindowConfigureCallback, window);
      window->SetLayout(layout);
      window->SetBackgroundColor(nux::Color(0x00000000));
      window->ShowWindow(true);
      window->EnableInputWindow(true, "panel", false, false);
      window->InputWindowEnableStruts(true);

      nux::Geometry geo = monitors[i];
      geo.height = 24;
      window->SetGeometry (geo);
      SetPrimary (window, i == primary_monitor);

      /* FIXME: this should not be manual, should be managed with a
         show/hide callback like in GAIL*/
      if (unity_a11y_initialized () == TRUE)
        unity_util_accessible_add_window (window);

      _windows.push_back (window);
    }
  }

  if ((int)_windows.size () > n_monitors)
  {
    std::vector<nux::BaseWindow*>::iterator sit;
    for (sit = it; sit != eit; ++sit)
    {
      (*sit)->UnReference ();
    }

    _windows.erase (it, _windows.end ());
  }
}

void
PanelController::WindowConfigureCallback (int            window_width,
                                          int            window_height,
                                          nux::Geometry& geo,
                                          void          *user_data)
{
  nux::BaseWindow *window = static_cast<nux::BaseWindow *> (user_data);
  geo = window->GetGeometry ();
}

const gchar *
PanelController::GetName ()
{
  return "PanelController";
}

void
PanelController::AddProperties (GVariantBuilder *builder)
{

}
