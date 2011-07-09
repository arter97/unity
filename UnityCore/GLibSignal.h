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

#ifndef UNITY_GLIB_SIGNAL_H
#define UNITY_GLIB_SIGNAL_H

#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <glib-object.h>
#include <sigc++/sigc++.h>

namespace unity {
namespace glib {

class SignalBase
{
public:
  typedef boost::shared_ptr<SignalBase> Ptr;

  SignalBase();
  virtual ~SignalBase();

  void Disconnect();

  GObject* get_object() const;
  std::string const& get_name() const;

protected:
  GObject* object_;
  guint32 connection_id_;
  std::string name_;
};

template <typename R, typename O>
class Signal0 : public SignalBase
{
public:
  typedef sigc::slot<R, O> SignalCallback;

  Signal0()
  {}
 
  void Connect(O                  object,
               std::string const& signal_name,
               SignalCallback     cb);
private:
  static R Callback(O object, Signal0* self);
private:
  SignalCallback callback_;
};

template <typename R, typename O, typename T>
class Signal1 : public SignalBase
{
public:
  typedef sigc::slot<R, O, T> SignalCallback;

  Signal1()
  {}

  void Connect(O                  object,
               std::string const& signal_name,
               SignalCallback     callback);
private:
  static R Callback(O object, T data1, Signal1* self);
private:
  SignalCallback callback_;
};

template <typename R, typename O, typename T1, typename T2>
class Signal2 : public SignalBase
{
public:
  typedef sigc::slot<R, O, T1, T2> SignalCallback;

  Signal2()
  {}

  void Connect(O                  object,
               std::string const& signal_name,
               SignalCallback     callback);
private:
  static R Callback(O        object,
                    T1       data1,
                    T2       data2,
                    Signal2* self);
private:
  SignalCallback callback_;
};

template <typename R, typename O, typename T1, typename T2, typename T3>
class Signal3 : public SignalBase
{
public:
  typedef sigc::slot<R, O, T1, T2, T3> SignalCallback;

  Signal3()
  {}

  void Connect(O                  object,
               std::string const& signal_name,
               SignalCallback     callback);
private:
  static R Callback(O        object,
                    T1       data1,
                    T2       data2,
                    T3       data3,
                    Signal3* self);
private:
  SignalCallback callback_;
};

template <typename R, typename O, typename T1, typename T2, typename T3, typename T4>
class Signal4 : public SignalBase
{
public:
  typedef sigc::slot<R, O, T1, T2, T3, T4> SignalCallback;

  Signal4()
  {}

  void Connect(O                  object,
               std::string const& signal_name,
               SignalCallback     callback);
private:
  static R Callback(O        object,
                    T1       data1,
                    T2       data2,
                    T3       data3,
                    T4       data4,
                    Signal4* self);
private:
  SignalCallback callback_;
};

template <typename R, typename O, typename T1, typename T2,
          typename T3, typename T4, typename T5>
class Signal5 : public SignalBase
{
public:
  typedef sigc::slot<R, O, T1, T2, T3, T4, T5> SignalCallback;

  Signal5()
  {}

  void Connect(O                  object,
               std::string const& signal_name,
               SignalCallback     callback);
private:
  static R Callback(O        object,
                    T1       data1,
                    T2       data2,
                    T3       data3,
                    T4       data4,
                    T5       data5,
                    Signal5* self);
private:
  SignalCallback callback_;
};

template <typename R, typename O, typename T1, typename T2,
          typename T3, typename T4, typename T5, typename T6>
class Signal6 : public SignalBase
{
public:
  typedef sigc::slot<R, O, T1, T2, T3, T4, T5, T6> SignalCallback;

  Signal6()
  {}

  void Connect(O                  object,
               std::string const& signal_name,
               SignalCallback     callback);
private:
  static R Callback(O        object,
                    T1       data1,
                    T2       data2,
                    T3       data3,
                    T4       data4,
                    T5       data5,
                    T6       data6,
                    Signal6* self);
private:
  SignalCallback callback_;
};

struct nil;

template <typename R, typename O,
          typename T1 = nil, typename T2 = nil,
          typename T3 = nil, typename T4 = nil,
          typename T5 = nil, typename T6 = nil>
class Signal : public Signal6<R, O, T1, T2, T3, T4, T5, T6>
{
public:
  typedef sigc::slot<R, O, T1, T2, T3, T4, T5, T6> SignalCallback;

  inline Signal();
  inline Signal(O              object,
                std::string    signal_name,
                SignalCallback callback);
};

template <typename R, typename O>
class Signal<R, O, nil, nil, nil, nil, nil, nil> : public Signal0<R, O>
{
public:
  typedef sigc::slot<R, O> SignalCallback;

  inline Signal();
  inline Signal(O              object,
                std::string    signal_name,
                SignalCallback callback);
};

template <typename R, typename O, typename T1>
class Signal<R, O, T1, nil, nil, nil, nil, nil> : public Signal1<R, O, T1>
{
public:
  typedef sigc::slot<R, O, T1> SignalCallback;

  inline Signal();
  inline Signal(O              object,
                std::string    signal_name,
                SignalCallback callback);
};

template <typename R, typename O, typename T1, typename T2>
class Signal<R, O, T1, T2, nil, nil, nil, nil> : public Signal2<R, O, T1, T2>
{
public:
  typedef sigc::slot<R, O, T1, T2> SignalCallback;

  inline Signal();
  inline Signal(O              object,
                std::string    signal_name,
                SignalCallback callback);
};

template <typename R, typename O, typename T1, typename T2, typename T3>
class Signal<R, O, T1, T2, T3, nil, nil, nil> : public Signal3<R, O, T1, T2 ,T3>
{
public:
  typedef sigc::slot<R, O, T1, T2, T3> SignalCallback;

  inline Signal();
  inline Signal(O              object,
                std::string    signal_name,
                SignalCallback callback);
};

template <typename R, typename O, typename T1, typename T2, typename T3, typename T4>
class Signal<R, O, T1, T2, T3, T4, nil, nil>
  : public Signal4<R, O, T1, T2 ,T3, T4>
{
public:
  typedef sigc::slot<R, O, T1, T2, T3, T4> SignalCallback;

  inline Signal();
  inline Signal(O              object,
                std::string    signal_name,
                SignalCallback callback);
};

template <typename R, typename O, typename T1, typename T2, typename T3, typename T4,
          typename T5>
class Signal<R, O, T1, T2, T3, T4, T5, nil>
  : public Signal5<R, O, T1, T2 ,T3, T4, T5>
{
public:
  typedef sigc::slot<R, O, T1, T2, T3, T4, T5> SignalCallback;

  inline Signal();
  inline Signal(O              object,
                std::string    signal_name,
                SignalCallback callback);
};

class SignalManager
{
public:
  typedef std::vector<SignalBase::Ptr> ConnectionVector;

  SignalManager();
  virtual ~SignalManager();
  
  void Add(SignalBase* signal);

  void Disconnect(void* object, std::string const& signal_name);
  
private:
  ConnectionVector connections_;
};

}
}

#include "GLibSignal-inl.h"

#endif
