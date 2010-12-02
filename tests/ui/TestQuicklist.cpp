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
 * Authored by: Mirco Müller <mirco.mueller@canonical.com>
 */

#include <glib.h>
#include <gtk/gtk.h>
#include <dbus/dbus-glib.h>

#include "Nux/Nux.h"
#include "Nux/VLayout.h"
#include "Nux/WindowThread.h"

#include "QuicklistView.h"
#include "QuicklistMenuItem.h"
#include "QuicklistMenuItemLabel.h"
#include "QuicklistMenuItemSeparator.h"
#include "QuicklistMenuItemCheckmark.h"
#include "QuicklistMenuItemRadio.h"

#include "EventFaker.h"

#define WIN_WIDTH  400
#define WIN_HEIGHT 300

QuicklistMenuItemCheckmark*
createCheckmarkItem ()
{
  DbusmenuMenuitem*           item      = NULL;
  QuicklistMenuItemCheckmark* checkmark = NULL;

  item = dbusmenu_menuitem_new ();

  dbusmenu_menuitem_property_set (item,
                                  DBUSMENU_MENUITEM_PROP_LABEL,
                                  "Unchecked");

  dbusmenu_menuitem_property_set (item,
                                  DBUSMENU_MENUITEM_PROP_TOGGLE_TYPE,
                                  DBUSMENU_MENUITEM_TOGGLE_CHECK);

  dbusmenu_menuitem_property_set_bool (item,
                                       DBUSMENU_MENUITEM_PROP_ENABLED,
                                       true);

  dbusmenu_menuitem_property_set_int (item,
                                      DBUSMENU_MENUITEM_PROP_TOGGLE_STATE,
                                      DBUSMENU_MENUITEM_TOGGLE_STATE_CHECKED);

  checkmark = new QuicklistMenuItemCheckmark (item, true);

  return checkmark;
}

QuicklistMenuItemRadio*
createRadioItem ()
{
  DbusmenuMenuitem*       item  = NULL;
  QuicklistMenuItemRadio* radio = NULL;

  item = dbusmenu_menuitem_new ();

  dbusmenu_menuitem_property_set (item,
                                  DBUSMENU_MENUITEM_PROP_LABEL,
                                  "Radio Active");

  dbusmenu_menuitem_property_set (item,
                                  DBUSMENU_MENUITEM_PROP_TOGGLE_TYPE,
                                  DBUSMENU_MENUITEM_TOGGLE_RADIO);

  dbusmenu_menuitem_property_set_bool (item,
                                       DBUSMENU_MENUITEM_PROP_ENABLED,
                                       true);

  dbusmenu_menuitem_property_set_int (item,
                                      DBUSMENU_MENUITEM_PROP_TOGGLE_STATE,
                                      DBUSMENU_MENUITEM_TOGGLE_STATE_UNCHECKED);

  radio = new QuicklistMenuItemRadio (item, true);
    
  return radio;
}

QuicklistMenuItemLabel*
createLabelItem ()
{
  DbusmenuMenuitem*       item  = NULL;
  QuicklistMenuItemLabel* label = NULL;

  item = dbusmenu_menuitem_new ();

  dbusmenu_menuitem_property_set (item,
                                  DBUSMENU_MENUITEM_PROP_LABEL,
                                  "A Label");

  dbusmenu_menuitem_property_set_bool (item,
                                       DBUSMENU_MENUITEM_PROP_ENABLED,
                                       true);

  label = new QuicklistMenuItemLabel (item, true);

  return label;
}

void
ThreadWidgetInit (nux::NThread* thread,
                  void*         initData)
{
  nux::VLayout*                 layout    = NULL;
  QuicklistView::QuicklistView* quicklist = NULL;

  layout = new nux::VLayout (TEXT(""), NUX_TRACKER_LOCATION);
  quicklist = new QuicklistView::QuicklistView ();

  quicklist->AddMenuItem (createCheckmarkItem ());
  quicklist->AddMenuItem (createRadioItem ());
  quicklist->AddMenuItem (createLabelItem ());

  quicklist->ShowQuicklistWithTipAt (30, 30);
  quicklist->EnableInputWindow (true, 1);
  quicklist->GrabPointer ();
  quicklist->NeedRedraw ();

  layout->AddView (quicklist, 1, nux::eCenter, nux::eFix);
  layout->SetContentDistribution (nux::eStackCenter);

  nux::GetGraphicsThread()->SetLayout (layout);
}

int
main (int argc, char **argv)
{
  g_type_init ();
  g_thread_init (NULL);
  gtk_init (&argc, &argv);

  dbus_g_thread_init ();

  nux::NuxInitialize (0);

  nux::WindowThread* wt = NULL;
  wt = nux::CreateGUIThread (TEXT ("Unity Quicklist"),
                             WIN_WIDTH,
                             WIN_HEIGHT,
                             0,
                             &ThreadWidgetInit,
                             0);
  
  wt->Run (NULL);

  delete wt;

  return 0;
}
