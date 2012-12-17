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
 * Authored by: Jason Smith <jason.smith@canonical.com>
 */

#include <math.h>

#include "SwitcherModel.h"
#include "unity-shared/WindowManager.h"

#include <UnityCore/Variant.h>

namespace unity
{
using launcher::AbstractLauncherIcon;

namespace switcher
{
namespace
{
bool compare_windows_by_active(Window first, Window second)
{
  WindowManager& wm = WindowManager::Default();
  return wm.GetWindowActiveNumber(first) > wm.GetWindowActiveNumber(second);
}

}


SwitcherModel::SwitcherModel(std::vector<AbstractLauncherIcon::Ptr> icons)
  : inner_(icons)
  , index_(0)
  , last_index_(0)
{
  detail_selection = false;
  detail_selection_index = 0;
  only_detail_on_viewport = false;

  for (auto icon : inner_)
  {
    AddChild(icon.GetPointer());
    if (icon->GetQuirk(AbstractLauncherIcon::Quirk::ACTIVE))
      last_active_icon_ = icon;
  }
}

SwitcherModel::~SwitcherModel()
{
  for (auto icon : inner_)
  {
    RemoveChild(icon.GetPointer());
  }
}

std::string SwitcherModel::GetName() const
{
  return "SwitcherModel";
}

void SwitcherModel::AddProperties(GVariantBuilder* builder)
{
  unity::variant::BuilderWrapper(builder)
  .add("detail-selection", detail_selection)
  .add("detail-selection-index", (int)detail_selection_index)
  .add("detail-current-count", DetailXids().size())
  .add("only-detail-on-viewport", only_detail_on_viewport)
  .add("selection-index", SelectionIndex())
  .add("last-selection-index", LastSelectionIndex());
}

SwitcherModel::iterator
SwitcherModel::begin()
{
  return inner_.begin();
}

SwitcherModel::iterator
SwitcherModel::end()
{
  return inner_.end();
}

SwitcherModel::reverse_iterator
SwitcherModel::rbegin()
{
  return inner_.rbegin();
}

SwitcherModel::reverse_iterator
SwitcherModel::rend()
{
  return inner_.rend();
}

AbstractLauncherIcon::Ptr
SwitcherModel::at(unsigned int index)
{
  if ((int) index >= Size ())
    return AbstractLauncherIcon::Ptr();
  return inner_[index];
}

int
SwitcherModel::Size()
{
  return inner_.size();
}

AbstractLauncherIcon::Ptr
SwitcherModel::Selection()
{
  return inner_.at(index_);
}

int
SwitcherModel::SelectionIndex()
{
  return index_;
}

AbstractLauncherIcon::Ptr
SwitcherModel::LastSelection()
{
  return inner_.at(last_index_);
}

int SwitcherModel::LastSelectionIndex()
{
  return last_index_;
}

bool WindowOnOtherViewport(Window xid)
{
  return !WindowManager::Default().IsWindowOnCurrentDesktop(xid);
}

std::vector<Window> SwitcherModel::DetailXids()
{
  std::vector<Window> results;
  for (auto& window : Selection()->Windows())
  {
    results.push_back(window->window_id());
  }

  if (only_detail_on_viewport)
  {
    results.erase(std::remove_if(results.begin(),
                                 results.end(),
                                 WindowOnOtherViewport),
                  results.end());
  }

  std::sort(results.begin(), results.end(), compare_windows_by_active);

  if (Selection() == last_active_icon_ && results.size () > 1)
  {
    for (unsigned int i = 0; i < results.size()-1; i++)
    {
      std::swap (results[i], results[i+1]);
    }
  }

  return results;
}

Window SwitcherModel::DetailSelectionWindow()
{
  if (!detail_selection || DetailXids ().empty())
    return 0;

  if (detail_selection_index > DetailXids().size() - 1)
    return 0;

  return DetailXids()[detail_selection_index];
}

void SwitcherModel::Next()
{
  last_index_ = index_;

  index_++;
  if (index_ >= inner_.size())
    index_ = 0;

  detail_selection = false;
  detail_selection_index = 0;
  selection_changed.emit(Selection());
}

void SwitcherModel::Prev()
{
  last_index_ = index_;

  if (index_ > 0)
    index_--;
  else
    index_ = inner_.size() - 1;

  detail_selection = false;
  detail_selection_index = 0;
  selection_changed.emit(Selection());
}

void SwitcherModel::NextDetail ()
{
  if (!detail_selection())
    return;

  if (detail_selection_index < DetailXids().size() - 1)
    detail_selection_index = detail_selection_index + 1;
  else
    detail_selection_index = 0;
}

void SwitcherModel::PrevDetail ()
{
  if (!detail_selection())
    return;

  if (detail_selection_index >= (unsigned int) 1)
    detail_selection_index = detail_selection_index - 1;
  else
    detail_selection_index = DetailXids().size() - 1;
}

void SwitcherModel::Select(AbstractLauncherIcon::Ptr const& selection)
{
  int i = 0;
  for (iterator it = begin(), e = end(); it != e; ++it)
  {
    if (*it == selection)
    {
      if ((int) index_ != i)
      {
        last_index_ = index_;
        index_ = i;

        detail_selection = false;
        detail_selection_index = 0;
        selection_changed.emit(Selection());
      }
      break;
    }
    ++i;
  }
}

void
SwitcherModel::Select(unsigned int index)
{
  unsigned int target = CLAMP(index, 0, inner_.size() - 1);

  if (target != index_)
  {
    last_index_ = index_;
    index_ = target;

    detail_selection = false;
    detail_selection_index = 0;
    selection_changed.emit(Selection());
  }
}

}
}
