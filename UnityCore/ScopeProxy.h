// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2013 Canonical Ltd
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
 * Authored by: Nick Dedekind <nick.dedekind@canonical.com>
 */

#ifndef UNITY_SCOPE_PROXY_H
#define UNITY_SCOPE_PROXY_H

#include "ScopeProxyInterface.h"

namespace unity
{
namespace dash
{

class ScopeProxy : public ScopeProxyInterface
{
public:
  ScopeProxy(std::string const& scope_id);
  ~ScopeProxy();

  virtual void CreateProxy();

  virtual void Search(std::string const& search_hint, SearchCallback const& callback, GCancellable* cancellable);

  virtual void Activate(std::string const& uri, uint activate_type, glib::HintsMap const& hints, ActivateCallback const& callback, GCancellable* cancellable);

  virtual void UpdatePreviewProperty(std::string const& uri, glib::HintsMap const& hints, UpdatePreviewPropertyCallback const& callback, GCancellable* cancellable);

  Results::Ptr GetResultsForCategory(unsigned category) const;

protected:
  ScopeProxy(std::string const& dbus_name, std::string const& dbus_path);

private:
  class Impl;
  std::unique_ptr<Impl> pimpl;
};

} // namespace dash
} // namespace unity

#endif // UNITY_SCOPE_PROXY_H
