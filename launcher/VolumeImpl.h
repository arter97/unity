// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2012 Canonical Ltd
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
 * Authored by: Andrea Azzarone <andrea.azzarone@canonical.com>
 */

#ifndef UNITYSHELL_VOLUME_IMPL_H
#define UNITYSHELL_VOLUME_IMPL_H

#include <memory>

#include <UnityCore/GLibWrapper.h>

#include "FileManagerOpener.h"
#include "Volume.h"

namespace unity
{
namespace launcher
{

class VolumeImpl : public Volume
{
public:
  VolumeImpl(glib::Object<GVolume> const& volume,
             std::shared_ptr<FileManagerOpener> const& file_manager_opener);
  virtual ~VolumeImpl();

  virtual std::string GetName() const;
  virtual std::string GetIconName() const;
  virtual std::string GetIdentifer() const;
  virtual bool IsMounted() const;
  virtual void MountAndOpenInFileManager();

private:
  class Impl;
  std::unique_ptr<Impl> pimpl;
};

} // namespace launcher
} // namespace unity

#endif // UNITYSHELL_VOLUME_IMPL_H