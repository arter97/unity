/*
 * Copyright 2011 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3, as
 * published by the  Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the applicable version of the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of both the GNU Lesser General Public
 * License version 3 along with this program.  If not, see
 * <http://www.gnu.org/licenses/>
 *
 * Authored by: Gordon Allott <gord.allott@canonical.com>
 *
 */
#include "config.h"

#include <Nux/Nux.h>

#include "FilterGenreButton.h"

namespace unity {
  FilterGenreButton::FilterGenreButton (const std::string label, NUX_FILE_LINE_DECL)
      : FilterBasicButton(label, NUX_FILE_LINE_PARAM) {
    InitTheme();
    
    state_change.connect ([&] (Button* button) {
      bool tmp_active = Active();
      if (filter_ != NULL)
        filter_->active = tmp_active;
    });
  }

  FilterGenreButton::FilterGenreButton (NUX_FILE_LINE_DECL)
      : FilterBasicButton(NUX_FILE_LINE_PARAM) {
    InitTheme();

    state_change.connect ([&] (Button* button) {
      bool tmp_active = Active();
      if (filter_ != NULL)
        filter_->active = tmp_active;
    });
  }


  void FilterGenreButton::SetFilter (dash::FilterOption::Ptr filter)
  {
    filter_ = filter;

    bool tmp_active = filter_->active;
    SetActive(tmp_active);
    filter_->active.changed.connect ([&] (bool is_active) {
        SetActive(is_active);
    });
  }

  dash::FilterOption::Ptr FilterGenreButton::GetFilter()
  {
    return filter_;
  }

  void FilterGenreButton::Draw(nux::GraphicsEngine& GfxContext, bool force_draw) {
    FilterBasicButton::Draw(GfxContext, force_draw);
  }

  void FilterGenreButton::DrawContent(nux::GraphicsEngine& GfxContext, bool force_draw) {
    FilterBasicButton::DrawContent(GfxContext, force_draw);
  }

  void FilterGenreButton::PostDraw(nux::GraphicsEngine& GfxContext, bool force_draw) {
    FilterBasicButton::PostDraw(GfxContext, force_draw);
  }

}
