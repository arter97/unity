// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
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

#ifndef UNITY_CHECK_BUTTON_FILTER_H
#define UNITY_CHECK_BUTTON_FILTER_H

#include "Filter.h"

namespace unity
{
namespace dash
{

class CheckButtonFilter : public Filter
{
public:
  typedef std::shared_ptr<CheckButtonFilter> Ptr;

  typedef std::vector<FilterButton::Ptr> CheckButtons;

  CheckButtonFilter(DeeModel* model, DeeModelIter* iter);

  void Clear();

  /* When a button is clicked. Don't worry about state, we'll handle that internally.
   * From this you'll get a changed event on "buttons", which you can then re-render
   * your view
   */
  void Toggle(std::string id);

  nux::ROProperty<CheckButtons> buttons;

  sigc::signal<void, FilterButton::Ptr> button_added;
  sigc::signal<void, FilterButton::Ptr> button_removed;

protected:
  void Update(Filter::Hints& hints);

private:
  void UpdateState(bool raw_filtering);
  CheckButtons const& get_buttons() const;

private:
  CheckButtons buttons_;
};

}
}

#endif
