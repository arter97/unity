// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
* Copyright © 2016 Canonical Ltd
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
* Authored by: Ted Gould <ted@canonical.com>
*/

#ifndef UNITY_SYSTEMD_WRAPPER
#define UNITY_SYSTEMD_WRAPPER

#include <memory>

namespace unity
{

class SystemdWrapper
{
public:
  typedef std::shared_ptr<SystemdWrapper> Ptr;

  SystemdWrapper();
  ~SystemdWrapper();

  void Start(std::string const& name);
  void Stop(std::string const& name);
  bool IsConnected();

protected:
  struct TestMode {};
  SystemdWrapper(TestMode const&);

private:
  // Noncopyable
  SystemdWrapper(SystemdWrapper const&) = delete;
  SystemdWrapper& operator=(SystemdWrapper const&) = delete;

  class Impl;
  std::unique_ptr<Impl> pimpl_;
};

}

#endif
