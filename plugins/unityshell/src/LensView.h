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

#ifndef UNITY_LENS_VIEW_H_
#define UNITY_LENS_VIEW_H_

#include <string>

#include <NuxGraphics/GraphicsEngine.h>
#include <Nux/Nux.h>
#include <Nux/HLayout.h>
#include <Nux/View.h>
#include <Nux/VLayout.h>
#include <UnityCore/Lens.h>

#include "Introspectable.h"
#include "ResultViewGrid.h"
#include "PlacesGroup.h"

namespace unity
{
namespace dash
{

class LensView : public nux::View, public unity::Introspectable
{
  NUX_DECLARE_OBJECT_TYPE(LensView, nux::View);
  typedef std::vector<PlacesGroup*> CategoryGroups;
  typedef std::map<PlacesGroup*, unsigned int> ResultCounts;

public:
  LensView(Lens::Ptr lens);
  ~LensView();

private:
  void SetupViews();

  void OnCategoryAdded(Category const& category);
  void OnResultAdded(Result const& result);
  void OnResultRemoved(Result const& result);
  void UpdateCounts(PlacesGroup* group);
  void OnGroupExpanded(PlacesGroup* group);

  long ProcessEvent(nux::IEvent& ievent, long traverse_info, long event_info);
  void Draw(nux::GraphicsEngine& gfx_context, bool force_draw);
  void DrawContent(nux::GraphicsEngine& gfx_context, bool force_draw);
  
  bool AcceptKeyNavFocus();
  const gchar* GetName();
  void AddProperties(GVariantBuilder* builder);

private:
  Lens::Ptr lens_;
  CategoryGroups categories_;
  ResultCounts counts_;

  nux::HLayout* layout_;
  nux::ScrollView* scroll_view_;
  nux::VLayout* scroll_layout_;
};


}
}
#endif
