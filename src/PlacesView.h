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
#include <NuxGraphics/GraphicsEngine.h>
#include <Nux/AbstractPaintLayer.h>
#include <Nux/VLayout.h>
#include <Nux/LayeredLayout.h>

#include "Introspectable.h"

#include "Place.h"
#include "PlaceEntry.h"
#include "PlaceEntryHome.h"
#include "PlaceFactory.h"

#include "PlacesSearchBar.h"
#include "PlacesHomeView.h"

#include "PlacesResultsController.h"
#include "PlacesResultsView.h"

#include "IconLoader.h"

class PlacesView : public nux::View, public Introspectable
{
  NUX_DECLARE_OBJECT_TYPE (PlacesView, nux::View);
public:

  // Current size of the Dash
  enum SizeMode
  {
    SIZE_MODE_FULLSCREEN,
    SIZE_MODE_HOVER
  };

  // This controls how the Dash resizes to it's contents
  enum ShrinkMode
  {
    SHRINK_MODE_NONE,
    SHRINK_MODE_CONTENTS
  };

  PlacesView (PlaceFactory *factory);
  ~PlacesView ();

  // nux::View overrides
  long ProcessEvent(nux::IEvent &ievent, long TraverseInfo, long ProcessEventInfo);
  void Draw(nux::GraphicsEngine& GfxContext, bool force_draw);
  void DrawContent (nux::GraphicsEngine &GfxContext, bool force_draw);

  // Methods
  void         SetActiveEntry (PlaceEntry *entry,
                               guint       section_id,
                               const char *search_string,
                               bool        signal=true);

  PlaceEntry * GetActiveEntry ();
  
  PlacesResultsController * GetResultsController ();

  nux::TextEntry* GetTextEntryView ();

  // UBus handlers
  void PlaceEntryActivateRequest (const char *entry_id, guint section, const gchar *search);

  SizeMode GetSizeMode ();
  void     SetSizeMode (SizeMode size_mode);

  void AboutToShow ();

  // Signals
  sigc::signal<void, PlaceEntry *> entry_changed;
  sigc::signal<void> fullscreen_request;
 
protected:

  const gchar* GetName ();
  void AddProperties (GVariantBuilder *builder);

private:
  static void CloseRequest (GVariant *data, PlacesView *self);

  void OnGroupAdded    (PlaceEntry *entry, PlaceEntryGroup& group);
  void OnResultAdded   (PlaceEntry *entry, PlaceEntryGroup& group, PlaceEntryResult& result);
  void OnResultRemoved (PlaceEntry *entry, PlaceEntryGroup& group, PlaceEntryResult& result);

  bool TryPlaceActivation (const char *uri);
  static void OnResultActivated (GVariant *data, PlacesView *self);
  void OnSearchChanged (const char *search_string);
  void OnResultsViewGeometryChanged (nux::Area *view, nux::Geometry& view_geo);

  static void OnPlaceViewQueueDrawNeeded (GVariant *data, PlacesView *self);

  void OnEntryActivated ();

  void LoadPlaces ();
  void OnPlaceAdded (Place *place);
  void OnPlaceResultActivated (const char *uri, ActivationResult res);
  void ReEvaluateShrinkMode ();

private:
  PlaceFactory       *_factory;
  nux::HLayout       *_layout;
  nux::LayeredLayout *_layered_layout;
  PlacesSearchBar    *_search_bar;
  PlacesHomeView     *_home_view;
  PlaceEntryHome     *_home_entry;
  PlaceEntry         *_entry;
  sigc::connection    _group_added_conn;
  sigc::connection    _result_added_conn;
  sigc::connection    _result_removed_conn;

  PlacesResultsController *_results_controller;
  PlacesResultsView       *_results_view;

  IconLoader       *_icon_loader;
  nux::ColorLayer  *_bg_layer;
  nux::SpaceLayout *_h_spacer;
  nux::SpaceLayout *_v_spacer;

  SizeMode   _size_mode;
  ShrinkMode _shrink_mode;

  nux::ObjectPtr <nux::IOpenGLBaseTexture> _bg_blur_texture;
  nux::Geometry _bg_blur_geo;

  guint _target_height;
  guint _actual_height;
};

#endif // PANEL_HOME_BUTTON_H

