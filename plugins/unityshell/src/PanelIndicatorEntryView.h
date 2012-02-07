// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2010-2012 Canonical Ltd
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
 *              Marco Trevisan (Treviño) <mail@3v1n0.net>
 */

#ifndef PANEL_INDICATOR_OBJECT_ENTRY_VIEW_H
#define PANEL_INDICATOR_OBJECT_ENTRY_VIEW_H

#include <Nux/TextureArea.h>
#include <Nux/View.h>
#include <NuxImage/CairoGraphics.h>
#include <NuxGraphics/GraphicsEngine.h>

#include <UnityCore/IndicatorEntry.h>
#include <UnityCore/GLibWrapper.h>
#include <UnityCore/GLibSignal.h>

#include <gtk/gtk.h>

#include "Introspectable.h"

namespace unity
{
using namespace indicator;

class PanelIndicatorEntryView : public nux::TextureArea, public debug::Introspectable
{
public:
  enum IndicatorEntryType {
    INDICATOR,
    MENU,
    OTHER
  };

  PanelIndicatorEntryView(Entry::Ptr const& proxy, int padding = 5,
                          IndicatorEntryType type = INDICATOR);

  void Refresh();

  void Activate(int button = 1);
  void Unactivate();
  bool GetShowNow();
  void SetDisabled(bool disabled);
  bool IsDisabled();
  void SetOpacity(double alpha);
  double GetOpacity();

  void GetGeometryForSync(EntryLocationMap& locations);
  bool IsSensitive() const;
  bool IsActive() const;
  bool IsVisible() const;
  int  GetEntryPriority() const;

  void DashShown();
  void DashHidden();

  std::string GetName() const;
  void AddProperties(GVariantBuilder* builder);

  virtual void Draw(nux::GraphicsEngine& GfxContext, bool force_draw);

  sigc::signal<void, PanelIndicatorEntryView*, bool> active_changed;
  sigc::signal<void, PanelIndicatorEntryView*> refreshed;

private:
  static const int PANEL_HEIGHT = 24;
  static const int SPACING = 3;

  Entry::Ptr proxy_;
  IndicatorEntryType type_;
  nux::BaseTexture* entry_texture_;
  int padding_;
  double opacity_;
  bool draw_active_;
  bool dash_showing_;
  bool disabled_;

  void OnMouseDown(int x, int y, long button_flags, long key_flags);
  void OnMouseUp(int x, int y, long button_flags, long key_flags);
  void OnMouseWheel(int x, int y, int delta, unsigned long mouse_state, unsigned long key_state);
  void OnActiveChanged(bool is_active);

  void SetActiveState(bool active, int button);
  void ShowMenu(int button);

  glib::Object<GdkPixbuf> MakePixbuf();

  void DrawEntryBackground(cairo_t* cr, unsigned int w, unsigned int h);
  void DrawEntryContent(cairo_t* cr, unsigned int width, unsigned int height,
                        glib::Object<GdkPixbuf> const& pixbuf,
                        glib::Object<PangoLayout> const& layout);
};

}

#endif // PANEL_INDICATOR_OBJECT_ENTRY_VIEW_H
