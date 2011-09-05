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

#ifndef PANEL_TRAY_H
#define PANEL_TRAY_H

#include <Nux/Nux.h>
#include <gtk/gtk.h>

#include <gdk/gdkx.h>

#include "Introspectable.h"
#include "PanelIndicatorObjectView.h"

#include <unity-misc/na-tray.h>
#include <unity-misc/na-tray-child.h>
#include <unity-misc/na-tray-manager.h>

namespace unity
{

// NOTE: Why does this inherit from PanelIndicatorObjectView?
// It doesn't ever get any indicator object.
class PanelTray : public PanelIndicatorObjectView
{
public:
  typedef std::vector<NaTrayChild*> TrayChildren;
  PanelTray();
  ~PanelTray();

  void Draw(nux::GraphicsEngine& gfx_content, bool force_draw);
  void Sync();

  unsigned int xid ();

  virtual void OnEntryAdded(unity::indicator::Entry::Ptr const& proxy);

public:
  char**     _whitelist;
protected:
  const gchar* GetName();
  const gchar* GetChildsName();
  void          AddProperties(GVariantBuilder* builder);

private:
  static gboolean FilterTrayCallback(NaTray* tray, NaTrayChild* child, PanelTray* self);
  static void     OnTrayIconRemoved(NaTrayManager* manager, NaTrayChild* child, PanelTray* self);
  static gboolean IdleSync(PanelTray* tray);
  static gboolean OnTrayDraw(GtkWidget* widget, cairo_t* cr, PanelTray* tray);
  
  void RealInit();
  int WidthOfTray();

private:
  GSettings* _settings;
  GtkWidget* _window;
  NaTray*    _tray;
  TrayChildren _children;
  int        _last_x;
  int        _last_y;

  gulong  _tray_expose_id;
  gulong  _tray_icon_added_id;
};

}

#endif
