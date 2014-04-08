// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2014 Canonical Ltd
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

#include "ScreenSaverDBusManager.h"

#include "LockScreenSettings.h"
#include "Variant.h"

namespace unity
{
namespace lockscreen
{
namespace dbus
{
const std::string NAME = "org.gnome.ScreenSaver";
const std::string INTERFACE = "org.gnome.ScreenSaver";
const std::string OBJECT_PATH = "/org/gnome/ScreenSaver";
const std::string INTROSPECTION_XML =
R"(<node>
  <interface name="org.gnome.ScreenSaver">
    <method name="Lock" />
    <method name="GetActive">
      <arg type="b" direction="out" name="value" />
    </method>
    <method name="GetActiveTime">
      <arg type="u" direction="out" name="seconds" />
    </method>
    <method name="SetActive">
      <arg type="b" direction="in" name="value" />
    </method>
    <method name="SimulateUserActivity" />
    <signal name="ActiveChanged">
      <arg name="new_value" type="b" />
    </signal>
  </interface>
</node>)";
}

DBusManager::DBusManager(session::Manager::Ptr const& session)
  : active(false)
  , session_(session)
  , server_(dbus::NAME)
  , time_(0)
{
  active.changed.connect(sigc::mem_fun(this, &DBusManager::SetActive));
  server_.AddObjects(dbus::INTROSPECTION_XML, dbus::OBJECT_PATH);
  object_ = server_.GetObject(dbus::INTERFACE);

  object_->SetMethodsCallsHandler([this] (std::string const& method, GVariant* variant) -> GVariant* {
    if (method == "Lock")
    {
      session_->LockScreen();
    }
    else if (method == "GetActive")
    {
      return g_variant_new("(b)", active_ ? TRUE : FALSE);
    }
    else if (method == "GetActiveTime")
    {
      if (time_)
        return g_variant_new("(u)", time(nullptr) - time_);
      else
        return g_variant_new("(u)", 0);
    }
    else if (method == "SetActive")
    {
      session_->presence_status_changed.emit(glib::Variant(variant).GetBool());
    }
    else if (method == "SimulateUserActivity")
    {
      simulate_activity.emit();
    }

    return nullptr;
  });
}

void DBusManager::SetActive(bool active)
{
  if (active)
    time_ = time(nullptr);
  else
    time_ = 0;

  object_->EmitSignal("ActiveChanged", g_variant_new("(b)", active ? TRUE : FALSE));
}

} // lockscreen
} // unity
