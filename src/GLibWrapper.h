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
* Authored by: Tim Penhey <tim.penhey@canonical.com>
*/

#ifndef UNITY_GLIB_WRAPPER_H
#define UNITY_GLIB_WRAPPER_H

#include <glib.h>
#include <string>

namespace unity {
namespace glib {

template <typename T>
class Object
{
public:
  Object();
  explicit Object(T* val);
  Object(Object const&);
  ~Object();

  operator T*();
  operator bool();
  T* operator->();
  T* RawPtr();
  // Release ownership of the object. No unref will occur.
  T* Release();

private:
  T* object_;
};

class Error
{
public:
  Error();
  ~Error();

  GError** AsOutParam();
  operator bool() const;
  std::string Message() const;

private:
  GError* error_;
};

class String
{
public:
  String();
  String(gchar* str);
  ~String();

  gchar** AsOutParam();
  gchar* Value();
  std::string Str() const;

private:
  gchar* string_;
};

}
}

#include "GLibWrapper-inl.h"

#endif
