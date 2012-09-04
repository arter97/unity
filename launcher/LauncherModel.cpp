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
 * Authored by: Jason Smith <jason.smith@canonical.com>
 *              Marco Trevisan <marco.trevisan@canonical.com>
 */

#include "LauncherModel.h"
#include "AbstractLauncherIcon.h"

#include <UnityCore/GLibWrapper.h>
#include <UnityCore/Variant.h>

namespace unity
{
namespace launcher
{

LauncherModel::LauncherModel()
  : selection_(0)
{}

std::string LauncherModel::GetName() const
{
  return "LauncherModel";
}

void LauncherModel::AddProperties(GVariantBuilder* builder)
{
  unity::variant::BuilderWrapper(builder)
  .add("selection", selection_);
}

unity::debug::Introspectable::IntrospectableList LauncherModel::GetIntrospectableChildren()
{
  introspection_results_.clear();

  for (auto icon : _inner)
    introspection_results_.push_back(icon.GetPointer());

  return introspection_results_;
}

bool LauncherModel::IconShouldShelf(AbstractLauncherIcon::Ptr icon) const
{
  return icon->GetIconType() == AbstractLauncherIcon::IconType::TRASH;
}

bool LauncherModel::CompareIcons(AbstractLauncherIcon::Ptr first, AbstractLauncherIcon::Ptr second)
{
  if (first->GetIconType() < second->GetIconType())
    return true;
  else if (first->GetIconType() > second->GetIconType())
    return false;

  return first->SortPriority() < second->SortPriority();
}

void LauncherModel::PopulatePart(iterator begin, iterator end)
{
  AbstractLauncherIcon::Ptr prev_icon;
  for (auto it = begin; it != end; ++it)
  {
    auto const& icon = *it;
    _inner.push_back(icon);

    if (prev_icon)
    {
      if (icon->SortPriority() < prev_icon->SortPriority())
      {
        int new_prio = prev_icon->SortPriority() + 1;
        icon->SetSortPriority(new_prio);
      }
    }

    prev_icon = icon;
  }
}

bool LauncherModel::Populate()
{
  Base copy = _inner;
  _inner.clear();
  PopulatePart(main_begin(), main_end());
  PopulatePart(shelf_begin(), shelf_end());

  return copy.size() == _inner.size() && !std::equal(begin(), end(), copy.begin());
}

void LauncherModel::AddIcon(AbstractLauncherIcon::Ptr icon)
{
  if (IconShouldShelf(icon))
    _inner_shelf.push_back(icon);
  else
    _inner_main.push_back(icon);

  Sort();

  icon_added.emit(icon);

  if (icon->on_icon_removed_connection.connected())
    icon->on_icon_removed_connection.disconnect();
  icon->on_icon_removed_connection = icon->remove.connect(sigc::mem_fun(this, &LauncherModel::OnIconRemove));
}

void LauncherModel::RemoveIcon(AbstractLauncherIcon::Ptr icon)
{
  size_t size;

  _inner_shelf.erase(std::remove(_inner_shelf.begin(), _inner_shelf.end(), icon), _inner_shelf.end());
  _inner_main.erase(std::remove(_inner_main.begin(), _inner_main.end(), icon), _inner_main.end());

  size = _inner.size();
  _inner.erase(std::remove(_inner.begin(), _inner.end(), icon), _inner.end());

  if (size != _inner.size())
  {
    icon_removed.emit(icon);
  }
}

void LauncherModel::OnIconRemove(AbstractLauncherIcon::Ptr icon)
{
  timeouts_.AddTimeout(1000, [this, icon] {
    RemoveIcon(icon);
    return false;
  });
}

void LauncherModel::Save()
{
  saved.emit();
}

void LauncherModel::Sort()
{
  std::stable_sort(_inner_shelf.begin(), _inner_shelf.end(), &LauncherModel::CompareIcons);
  std::stable_sort(_inner_main.begin(), _inner_main.end(), &LauncherModel::CompareIcons);

  if (Populate())
    order_changed.emit();
}

bool LauncherModel::IconHasSister(AbstractLauncherIcon::Ptr icon) const
{
  const_iterator it;
  const_iterator end;

  if (IconShouldShelf(icon))
  {
    it = _inner_shelf.begin();
    end = _inner_shelf.end();
  }
  else
  {
    it = _inner_main.begin();
    end = _inner_main.end();
  }

  for (; it != end; ++it)
  {
    AbstractLauncherIcon::Ptr const& iter_icon = *it;

    if (iter_icon != icon && iter_icon->GetIconType() == icon->GetIconType())
      return true;
  }

  return false;
}

void LauncherModel::ReorderAfter(AbstractLauncherIcon::Ptr icon, AbstractLauncherIcon::Ptr other)
{
  if (icon == other || icon.IsNull() || other.IsNull())
    return;

  if (icon->GetIconType() != other->GetIconType())
    return;

  icon->SetSortPriority(other->SortPriority() + 1);
  bool target_found = false;

  for (auto it = begin(); it != end(); ++it)
  {
    auto const& icon_it = *it;

    if (icon_it == icon)
      continue;

    if (icon_it == other)
    {
      target_found = true;
    }
    else if (target_found)
    {
      int new_prio = icon_it->SortPriority() + 1;
      icon_it->SetSortPriority(new_prio);
    }
  }

  Sort();
}

void LauncherModel::ReorderBefore(AbstractLauncherIcon::Ptr icon, AbstractLauncherIcon::Ptr other, bool animate)
{
  if (icon == other || icon.IsNull() || other.IsNull())
    return;

  if (icon->GetIconType() != other->GetIconType())
    return;

  bool found_target = false;
  bool center = false;

  for (auto it = begin(); it != end(); ++it)
  {
    auto const& icon_it = *it;

    if (icon_it == icon)
    {
      center = !center;
      continue;
    }

    int new_prio = icon_it->SortPriority() + (found_target ? 1 : -1);
    icon_it->SetSortPriority(new_prio);

    if (icon_it == other)
    {
      if (animate && center)
        icon_it->SaveCenter();

      center = !center;
      new_prio = new_prio - 1;
      icon->SetSortPriority(new_prio);

      if (animate && center)
        icon_it->SaveCenter();

      found_target = true;
    }
    else
    {
      if (animate && center)
        icon_it->SaveCenter();
    }
  }

  Sort();
}

void LauncherModel::ReorderSmart(AbstractLauncherIcon::Ptr icon, AbstractLauncherIcon::Ptr other, bool save)
{
  if (icon == other || icon.IsNull() || other.IsNull())
    return;

  if (icon->GetIconType() != other->GetIconType())
    return;

  bool found_icon = false;
  bool found_target = false;
  bool center = false;

  for (auto it = begin(); it != end(); ++it)
  {
    auto const& icon_it = *it;

    if (icon_it == icon)
    {
      found_icon = true;
      center = !center;
      continue;
    }

    int new_prio = icon_it->SortPriority() + (found_target ? 1 : -1);
    icon_it->SetSortPriority(new_prio);

    if (icon_it == other)
    {
      if (save && center)
        icon_it->SaveCenter();

      center = !center;
      new_prio = new_prio + (found_icon ? 1 : -1);
      icon->SetSortPriority(new_prio);

      if (save && center)
        icon_it->SaveCenter();

      found_target = true;
    }
    else
    {
      if (save && center)
        icon_it->SaveCenter();
    }
  }

  Sort();
}

int
LauncherModel::Size() const
{
  return _inner.size();
}

AbstractLauncherIcon::Ptr LauncherModel::Selection () const
{
  return _inner[selection_];
}

int LauncherModel::SelectionIndex() const
{
  return selection_;
}

void LauncherModel::SetSelection(int selection)
{
  int new_selection = std::min<int>(Size() - 1, std::max<int> (0, selection));

  if (new_selection == selection_)
    return;

  selection_ = new_selection;
  selection_changed.emit(Selection());
}

void LauncherModel::SelectNext()
{
  int temp = selection_;

  temp++;
  while (temp != selection_)
  {
    if (temp >= Size())
      temp = 0;

    if (_inner[temp]->IsVisible())
    {
      selection_ = temp;
      selection_changed.emit(Selection());
      break;
    }
    temp++;
  }
}

void LauncherModel::SelectPrevious()
{
  int temp = selection_;

  temp--;
  while (temp != selection_)
  {
    if (temp < 0)
      temp = Size() - 1;

    if (_inner[temp]->IsVisible())
    {
      selection_ = temp;
      selection_changed.emit(Selection());
      break;
    }
    temp--;
  }
}

AbstractLauncherIcon::Ptr LauncherModel::GetClosestIcon(AbstractLauncherIcon::Ptr icon, bool& is_before) const
{
  AbstractLauncherIcon::Ptr prev, next;
  bool found_target = false;

  for (auto const& current : _inner)
  {
    if (current->GetIconType() != icon->GetIconType())
      continue;

    if (!found_target)
    {
      if (current == icon)
      {
        found_target = true;

        if (prev)
          break;
      }
      else
      {
        prev = current;
      }
    }
    else
    {
      next = current;
      break;
    }
  }

  is_before = next.IsNull();

  return is_before ? prev : next;
}

int LauncherModel::IconIndex(AbstractLauncherIcon::Ptr target) const
{
  int pos = 0;
  bool found = false;

  for (auto const& icon : _inner)
  {
    if (icon == target)
    {
      found = true;
      break;
    }

    ++pos;
  }

  return found ? pos : -1;
}

/* iterators */

LauncherModel::iterator LauncherModel::begin()
{
  return _inner.begin();
}

LauncherModel::iterator LauncherModel::end()
{
  return _inner.end();
}

LauncherModel::iterator LauncherModel::at(int index)
{
  LauncherModel::iterator it;
  int i;

  // start currently selected icon
  for (it = _inner.begin(), i = 0; it != _inner.end(); ++it, i++)
  {
    if (i == index)
      return it;
  }

  return (LauncherModel::iterator)NULL;
}

LauncherModel::reverse_iterator LauncherModel::rbegin()
{
  return _inner.rbegin();
}

LauncherModel::reverse_iterator LauncherModel::rend()
{
  return _inner.rend();
}

LauncherModel::iterator LauncherModel::main_begin()
{
  return _inner_main.begin();
}

LauncherModel::iterator LauncherModel::main_end()
{
  return _inner_main.end();
}

LauncherModel::reverse_iterator LauncherModel::main_rbegin()
{
  return _inner_main.rbegin();
}

LauncherModel::reverse_iterator LauncherModel::main_rend()
{
  return _inner_main.rend();
}

LauncherModel::iterator LauncherModel::shelf_begin()
{
  return _inner_shelf.begin();
}

LauncherModel::iterator LauncherModel::shelf_end()
{
  return _inner_shelf.end();
}

LauncherModel::reverse_iterator LauncherModel::shelf_rbegin()
{
  return _inner_shelf.rbegin();
}

LauncherModel::reverse_iterator LauncherModel::shelf_rend()
{
  return _inner_shelf.rend();
}

} // namespace launcher
} // namespace unity
