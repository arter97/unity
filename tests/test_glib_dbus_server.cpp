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
 * Authored by: Marco Trevisan (Treviño) <marco.trevisan@canonical.com>
 */

#include <gmock/gmock.h>
#include <UnityCore/GLibDBusServer.h>
#include <UnityCore/GLibDBusProxy.h>
#include "test_utils.h"

using namespace unity::glib;

namespace
{

const std::string DBUS_TEST_NAME = "com.canonical.Unity.Test.Server.Name";
const std::string TEST_OBJECT_PATH = "/com/canonical/Unity/Test/Object";

namespace introspection
{
const std::string SINGLE_OJBECT =
R"(<node>
  <interface name="com.canonical.Unity.ObjectTest">
    <method name="Foo">
      <arg type="i" name="type" direction="in"/>
    </method>
    <method name="Bar">
      <arg type="i" name="type" direction="out"/>
    </method>
    <signal name="SignalWithNoParameters" />
    <signal name="SignalWithParameter">
      <arg type="i" name="arg" />
    </signal>
    <property name="ReadOnlyProperty" type="i" access="read"/>
    <property name="WriteOnlyProperty" type="i" access="write"/>
    <property name="ReadWriteProperty" type="i" access="readwrite"/>
  </interface>
</node>)";

const std::string MULTIPLE_OJBECTS =
R"(<node>
  <interface name="com.canonical.Unity.ObjectTest1">
    <method name="Test1" />
  </interface>
  <interface name="com.canonical.Unity.ObjectTest2">
    <method name="Test2" />
  </interface>
  <interface name="com.canonical.Unity.ObjectTest3">
    <method name="Test3" />
  </interface>
</node>)";

}

TEST(TestGLibDBusServer, OwnsName)
{
  bool name_owned = false;
  DBusServer server(DBUS_TEST_NAME);
  EXPECT_EQ(server.Name(), DBUS_TEST_NAME);

  server.name_acquired.connect([&name_owned] { name_owned = true; });
  Utils::WaitUntil(name_owned);

  EXPECT_TRUE(name_owned);
  EXPECT_TRUE(server.OwnsName());
}

TEST(TestGLibDBusServer, AddsObjectWhenOwingName)
{
  bool object_registered = false;

  auto interface = "com.canonical.Unity.ObjectTest";
  auto object = std::make_shared<DBusObject>(introspection::SINGLE_OJBECT, interface);

  object->registered.connect([&object_registered] (std::string const& path) {
    EXPECT_EQ(path, TEST_OBJECT_PATH);
    object_registered = true;
  });

  DBusServer server(DBUS_TEST_NAME);
  server.AddObject(object, TEST_OBJECT_PATH);
  ASSERT_EQ(server.GetObject(interface), object);
  ASSERT_EQ(server.GetObjects().front(), object);

  Utils::WaitUntil([&server] { return server.OwnsName(); });

  ASSERT_EQ(server.GetObjects().front(), object);
  EXPECT_TRUE(object_registered);
}

TEST(TestGLibDBusServer, AddsObjectsWhenOwingName)
{
  unsigned objects_registered = 0;

  DBusServer server(DBUS_TEST_NAME);
  server.AddObjects(introspection::MULTIPLE_OJBECTS, TEST_OBJECT_PATH);
  ASSERT_EQ(server.GetObjects().size(), 3);

  for (auto const& obj : server.GetObjects())
  {
    ASSERT_EQ(server.GetObject(obj->InterfaceName()), obj);

    obj->registered.connect([&objects_registered] (std::string const& path) {
      EXPECT_EQ(path, TEST_OBJECT_PATH);
      ++objects_registered;
    });
  }

  Utils::WaitUntil([&server] { return server.OwnsName(); });

  EXPECT_EQ(objects_registered, 3);
}

TEST(TestGLibDBusServer, RemovingObjectWontRegisterIt)
{
  unsigned objects_registered = 0;

  DBusServer server(DBUS_TEST_NAME);
  server.AddObjects(introspection::MULTIPLE_OJBECTS, TEST_OBJECT_PATH);
  ASSERT_EQ(server.GetObjects().size(), 3);

  server.RemoveObject(server.GetObjects().front());
  ASSERT_EQ(server.GetObjects().size(), 2);

  for (auto const& obj : server.GetObjects())
  {
    obj->registered.connect([&objects_registered] (std::string const& path) {
      EXPECT_EQ(path, TEST_OBJECT_PATH);
      ++objects_registered;
    });
  }

  Utils::WaitUntil([&server] { return server.OwnsName(); });

  EXPECT_EQ(objects_registered, 2);
}

TEST(TestGLibDBusServer, RemovingObjectsUnregistersThem)
{
  DBusServer server(DBUS_TEST_NAME);
  server.AddObjects(introspection::MULTIPLE_OJBECTS, TEST_OBJECT_PATH);
  ASSERT_EQ(server.GetObjects().size(), 3);

  Utils::WaitUntil([&server] { return server.OwnsName(); });

  unsigned objects_unregistered = 0;
  for (auto const& obj : server.GetObjects())
  {
    obj->unregistered.connect([&objects_unregistered] (std::string const& path) {
      EXPECT_EQ(path, TEST_OBJECT_PATH);
      ++objects_unregistered;
    });
  }

  server.RemoveObject(server.GetObjects().front());
  ASSERT_EQ(server.GetObjects().size(), 2);
  EXPECT_EQ(objects_unregistered, 1);

  server.RemoveObject(server.GetObjects().front());
  ASSERT_EQ(server.GetObjects().size(), 1);
  EXPECT_EQ(objects_unregistered, 2);

  server.RemoveObject(server.GetObjects().front());
  ASSERT_EQ(server.GetObjects().size(), 0);
  EXPECT_EQ(objects_unregistered, 3);
}


} // Namespace
