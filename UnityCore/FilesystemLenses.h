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

#ifndef UNITY_FILESYSTEM_LENSES_H
#define UNITY_FILESYSTEM_LENSES_H

#include <memory>
#include <sigc++/signal.h>
#include <sigc++/trackable.h>

#include "Lenses.h"

namespace unity
{
namespace dash
{

// Reads Lens information from the filesystem, as per-specification, and creates
// Lens instances using this data
class FilesystemLenses : public Lenses
{
public:
  typedef std::shared_ptr<FilesystemLenses> Ptr;

  FilesystemLenses();
  FilesystemLenses(std::string const& lens_directory);

  void Init();

  ~FilesystemLenses();

  LensList GetLenses() const;
  Lens::Ptr GetLens(std::string const& lens_id) const;
  Lens::Ptr GetLensAtIndex(std::size_t index) const;

  sigc::signal<void> lenses_loaded;

  class Impl;
private:
  Impl* pimpl;
};

}
}

#endif
