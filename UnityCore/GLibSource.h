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
* Authored by: Marco Trevisan (Treviño) <3v1n0@ubuntu.com>
*/

#ifndef UNITY_GLIB_SOURCE_H
#define UNITY_GLIB_SOURCE_H

#include <boost/utility.hpp>
#include <sigc++/sigc++.h>
#include <glib.h>
#include <memory>
#include <map>

namespace unity
{
namespace glib
{

/**
 * glib::Source is a wrapper class used to handle GSource based events using
 * at C++ level.
 *
 * The class is basically to be intended abstract and is currently implemented
 * by glib::Timeout() and glib::Idle() that are the higher-level wrappers for
 * g_timeout and g_idle respectively.
 *
 * As this is meant to be mostly a wrapper, I've mostly kept the same logic of
 * the glib sources, and so, for example, a source can't be ran more than once.
 *
 * Sources should define a callback function that will be called every time that
 * the source is dispatched. If the callback function returns false, then the
 * source will be removed, otherwise it will continue.
 *
 * Pointer types have been defined and should be used to handle dynamically
 * allocated sources. They also implicitly allow to remove running Sources
 * by setting their value to nullptr.
 */
class Source : public boost::noncopyable
{
public:
  typedef std::shared_ptr<Source> Ptr;
  typedef std::unique_ptr<Source> UniquePtr;
  typedef sigc::slot<bool> SourceCallback;

  /**
   * This is an enum used for convenience, you can actually cast to this
   * any integer: the bigger it is, the lower priority we have.
   */
  enum Priority
  {
    HIGH = G_PRIORITY_HIGH,                 // -100
    DEFAULT = G_PRIORITY_DEFAULT,           // 0
    HIGH_IDLE = G_PRIORITY_HIGH_IDLE,       // 100
    DEFAULT_IDLE = G_PRIORITY_DEFAULT_IDLE, // 200
    LOW = G_PRIORITY_LOW                    // 300
  };

  virtual ~Source();
  unsigned int Id() const;

  /**
   * This Run a source using the @callback function as Source's callback.
   * The method will return false if the source is already running, true otherwise.
   */
  bool Run(SourceCallback callback);
  bool IsRunning() const;

  /**
   * This removes a source, and stop it from being executed.
   * After that a source has been removed, it can't be ran again.
   */
  void Remove();

  void SetPriority(Priority prio);
  Priority GetPriority() const;

  /**
   * The removed signal is emitted when the Source has been removed and so it
   * can happen both when the Remove() method is called and when the callback
   * function returns false.
   */
  sigc::signal<void, unsigned int> removed;

protected:
  Source();

  GSource* source_;

private:
  static gboolean Callback(gpointer data);
  static void DestroyCallback(gpointer data);

  unsigned int source_id_;
  SourceCallback callback_;
};


/**
 * glib::Timeout is a wrapper to g_timeout and must be used to initialize a
 * timeout that will be executed every @milliseconds milliseconds, whenever
 * there are no higher priority events pending to the default main loop.
 *
 * If the SourceCallback is defined on construction, then the Timeout is ran
 * as soon as it is created, otherwise you must manually call the Run() method
 * with the appropriate parameters.
 */
class Timeout : public Source
{
public:
  Timeout(unsigned int milliseconds, Priority prio = Priority::DEFAULT);
  Timeout(unsigned int milliseconds, SourceCallback cb, Priority prio = Priority::DEFAULT);

private:
  void Init(unsigned int milliseconds, Priority prio);
};


/**
 * glib::Idle is a wrapper to g_idle and must be used to initialize an idle
 * that will be executed whenever there are no higher priority events pending to
 * the default main loop.
 *
 * If the SourceCallback is defined on construction, then the Timeout is ran
 * as soon as it is created, otherwise you must manually call the Run() method
 * with the appropriate parameters.
 */
class Idle : public Source
{
public:
  Idle(Priority prio = Priority::DEFAULT_IDLE);
  Idle(SourceCallback cb, Priority prio = Priority::DEFAULT_IDLE);

private:
  void Init(Priority prio);
};


/**
 * glib::SourceManager is a container for the glib::Source pointers.
 * It can be used to store multiple Sources pointers, possibly defining a
 * "nick" name to reference them.
 *
 * This is meant to be an utility class that ensures that all the Sources
 * are removed and destructed when the container itself is destructed.
 */
class SourceManager : public boost::noncopyable
{
public:
  SourceManager();
  ~SourceManager();

  /**
   * Adds a new Source to the manager.
   * Only new valid sources can be added to the manager.
   *
   * The developer may define a nickname for a Source, when adding a new Source
   * with an already known nickname, the old Source will be removed, and the
   * new one will replace it.
   */
  bool Add(Source* source, std::string const& nick = "");
  bool Add(Source::Ptr const& source, std::string const& nick = "");

  void Remove(std::string const& nick);
  void Remove(unsigned int id);

  Source::Ptr GetSource(std::string const& nick) const;
  Source::Ptr GetSource(unsigned int id) const;

protected:
  void OnSourceRemoved(unsigned int id);

  std::map<std::string, Source::Ptr> sources_;
};

} // glib namespace
} // unity namespace


/* This code is needed to make the lambda functions with a return value to work
 * with the sigc::slot. We need that here to use lambdas as SourceCallback.
 * This can safely removed once libsigc++ will include it.
 *
 * Thanks to Chow Loong Jin <hyperair@gmail.com> for this code, see:
 * http://mail.gnome.org/archives/libsigc-list/2012-January/msg00000.html */

#if __cplusplus >= 201100L || defined (__GXX_EXPERIMENTAL_CXX0X__)
#include <type_traits>

namespace sigc
{
  template <typename Functor>
  struct functor_trait<Functor, false>
  {
    typedef decltype (::sigc::mem_fun(std::declval<Functor&>(), &Functor::operator())) _intermediate;
    typedef typename _intermediate::result_type result_type;
    typedef Functor functor_type;
  };
}
#endif

#endif
