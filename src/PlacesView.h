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

#ifndef PLACES_VIEW_H
#define PLACES_VIEW_H

#include <Nux/Nux.h>
#include <Nux/View.h>
#include <NuxImage/CairoGraphics.h>
#include "NuxGraphics/GraphicsEngine.h"
#include "Nux/AbstractPaintLayer.h"
#include <Nux/VLayout.h>

#include "Introspectable.h"

#include "Place.h"
#include "PlaceEntry.h"

#include "PlacesSearchBar.h"
#include "PlacesHomeView.h"

#include "PlacesSimpleTile.h"
#include "PlacesGroup.h"
#include "PlacesResultsController.h"
#include "PlacesResultsView.h"

class PlacesView : public nux::View, public Introspectable
{
  NUX_DECLARE_OBJECT_TYPE (PlacesView, nux::View);
public:
  PlacesView (NUX_FILE_LINE_PROTO);
  ~PlacesView ();

  // nux::View overrides
  long ProcessEvent(nux::IEvent &ievent, long TraverseInfo, long ProcessEventInfo);
  void Draw(nux::GraphicsEngine& GfxContext, bool force_draw);
  void DrawContent (nux::GraphicsEngine &GfxContext, bool force_draw);

  // Methods
  void         SetActiveEntry (PlaceEntry *entry, guint section_id, const char *search_string);
  PlaceEntry * GetActiveEntry ();

  // UBus handlers
  void PlaceEntryActivateRequest (const char *entry_id, guint section, const gchar *search);
 
protected:

  const gchar* GetName ();
  void AddProperties (GVariantBuilder *builder);

private:
  static void CloseRequest (GVariant *data, PlacesView *self);

  static void OnGroupAdded    (DeeModel *model, DeeModelIter *iter, PlacesView *self);
  static void OnGroupRemoved  (DeeModel *model, DeeModelIter *iter, PlacesView *self);
  static void OnResultAdded   (DeeModel *model, DeeModelIter *iter, PlacesView *self);
  static void OnResultRemoved (DeeModel *model, DeeModelIter *iter, PlacesView *self);

private:
  nux::VLayout    *_layout;
  PlacesSearchBar *_search_bar;
  PlacesHomeView  *_home_view;
  PlaceEntry      *_entry;
  gulong           _group_added_id;
  gulong           _group_removed_id;
  gulong           _result_added_id;
  gulong           _result_removed_id;

  PlacesResultsController *_results_controller;
  PlacesResultsView       *_results_view;
};

#endif // PANEL_HOME_BUTTON_H

