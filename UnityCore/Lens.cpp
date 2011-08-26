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

#include "Lens.h"

#include <gio/gio.h>
#include <glib.h>
#include <NuxCore/Logger.h>

#include "config.h"
#include "GLibDBusProxy.h"
#include "GLibWrapper.h"
#include "Utils.h"

namespace unity
{
namespace dash
{

namespace
{
nux::logging::Logger logger("unity.dash.lens");
}

using std::string;

class Lens::Impl
{
public:
  Impl(Lens* owner,
       string const& id,
       string const& dbus_name,
       string const& dbus_path,
       string const& name,
       string const& icon_hint,
       string const& description,
       string const& search_hint,
       bool visible,
       string const& shortcut);

  ~Impl();

  void OnProxyConnected();
  void OnProxyDisconnected();

  void OnSearchFinished(GVariant* parameters);
  void OnGlobalSearchFinished(GVariant* parameters);
  void OnChanged(GVariant* parameters);
  void UpdateProperties(bool search_in_global,
                        bool visible,
                        string const& search_hint,
                        string const& private_connection_name,
                        string const& results_model_name,
                        string const& global_results_model_name,
                        string const& categories_model_name,
                        string const& filters_model_name);
  void OnActiveChanged(bool is_active);

  void GlobalSearch(std::string const& search_string);
  void Search(std::string const& search_string);
  void Activate(std::string const& uri);
  void ActivationReply(GVariant* parameters);
  void Preview(std::string const& uri);
  void PreviewReply(GVariant* parameters);

  string const& id() const;
  string const& dbus_name() const;
  string const& dbus_path() const;
  string const& name() const;
  string const& icon_hint() const;
  string const& description() const;
  string const& search_hint() const;
  bool visible() const;
  bool search_in_global() const;
  string const& shortcut() const;
  Results::Ptr const& results() const;
  Results::Ptr const& global_results() const;
  Categories::Ptr const& categories() const;
  Filters::Ptr const& filters() const;
  bool connected() const;

  Lens* owner_;

  string id_;
  string dbus_name_;
  string dbus_path_;
  string name_;
  string icon_hint_;
  string description_;
  string search_hint_;
  bool visible_;
  bool search_in_global_;
  string shortcut_;
  Results::Ptr results_;
  Results::Ptr global_results_;
  Categories::Ptr categories_;
  Filters::Ptr filters_;
  bool connected_;

  string private_connection_name_;

  glib::DBusProxy proxy_;
};

Lens::Impl::Impl(Lens* owner,
                 string const& id,
                 string const& dbus_name,
                 string const& dbus_path,
                 string const& name,
                 string const& icon_hint,
                 string const& description,
                 string const& search_hint,
                 bool visible,
                 string const& shortcut)
  : owner_(owner)
  , id_(id)
  , dbus_name_(dbus_name)
  , dbus_path_(dbus_path)
  , name_(name)
  , icon_hint_(icon_hint)
  , description_(description)
  , search_hint_(search_hint)
  , visible_(visible)
  , search_in_global_(false)
  , shortcut_(shortcut)
  , results_(new Results())
  , global_results_(new Results())
  , categories_(new Categories())
  , filters_(new Filters())
  , connected_(false)
  , proxy_(dbus_name, dbus_path, "com.canonical.Unity.Lens")
{
  proxy_.connected.connect(sigc::mem_fun(this, &Lens::Impl::OnProxyConnected));
  proxy_.disconnected.connect(sigc::mem_fun(this, &Lens::Impl::OnProxyDisconnected));
  proxy_.Connect("Changed", sigc::mem_fun(this, &Lens::Impl::OnChanged));
  proxy_.Connect("SearchFinished", sigc::mem_fun(this, &Lens::Impl::OnSearchFinished));
  proxy_.Connect("GlobalSearchFinished", sigc::mem_fun(this, &Lens::Impl::OnGlobalSearchFinished));
}

Lens::Impl::~Impl()
{}

void Lens::Impl::OnProxyConnected()
{
  proxy_.Call("InfoRequest");
  proxy_.Call("SetActive", g_variant_new("(b)", owner_->active ? TRUE : FALSE));
}

void Lens::Impl::OnProxyDisconnected()
{
  connected_ = false;
  owner_->connected.EmitChanged(connected_);
}

void Lens::Impl::OnSearchFinished(GVariant* parameters)
{
  glib::String search_string;

  g_variant_get(parameters, "(sa{sv})", &search_string, NULL);
  owner_->search_finished.emit(search_string.Str());
}

void Lens::Impl::OnGlobalSearchFinished(GVariant* parameters)
{
  glib::String search_string;

  g_variant_get(parameters, "(sa{sv})", &search_string, NULL);
  owner_->global_search_finished.emit(search_string.Str());
}

void Lens::Impl::OnChanged(GVariant* parameters)
{
  glib::String dbus_path;
  gboolean search_in_global = FALSE;
  gboolean visible = FALSE;
  glib::String search_hint;
  glib::String private_connection_name;
  glib::String results_model_name;
  glib::String global_results_model_name;
  glib::String categories_model_name;
  glib::String filters_model_name;
  GVariantIter* hints_iter = NULL;

  g_variant_get(parameters, "((sbbssssssa{sv}))",
                &dbus_path,
                &search_in_global,
                &visible,
                &search_hint,
                &private_connection_name,
                &results_model_name,
                &global_results_model_name,
                &categories_model_name,
                &filters_model_name,
                &hints_iter);

  LOG_DEBUG(logger) << "Lens info changed for " << name_ << "\n"
                    << "  Path: " << dbus_path << "\n"
                    << "  SearchInGlobal: " << search_in_global << "\n"
                    << "  Visible: " << visible << "\n"
                    << "  PrivateConnName: " << private_connection_name << "\n"
                    << "  Results: " << results_model_name << "\n"
                    << "  GlobalModel: " << global_results_model_name << "\n"
                    << "  Categories: " << categories_model_name << "\n"
                    << "  Filters: " << filters_model_name << "\n";
  if (dbus_path.Str() == dbus_path_)
  {
    /* FIXME: We ignore hints for now */
    UpdateProperties(search_in_global,
                     visible,
                     search_hint.Str(),
                     private_connection_name.Str(),
                     results_model_name.Str(),
                     global_results_model_name.Str(),
                     categories_model_name.Str(),
                     filters_model_name.Str());
  }
  else
  {
    LOG_WARNING(logger) << "Paths do not match " << dbus_path_ << " != " << dbus_path;
  }

  connected_ = true;
  owner_->connected.EmitChanged(connected_);

  g_variant_iter_free(hints_iter);
}

void Lens::Impl::UpdateProperties(bool search_in_global,
                                  bool visible,
                                  string const& search_hint,
                                  string const& private_connection_name,
                                  string const& results_model_name,
                                  string const& global_results_model_name,
                                  string const& categories_model_name,
                                  string const& filters_model_name)
{
  // Diff the properties received from those we have
  if (search_hint_ != search_hint)
  {
    search_hint_ = search_hint;
    owner_->search_hint.EmitChanged(search_hint_);
  }

  if (search_in_global_ != search_in_global)
  {
    search_in_global_ = search_in_global;
    owner_->search_in_global.EmitChanged(search_in_global_);
  }

  if (visible_ != visible)
  {
    visible_ = visible;
    owner_->visible.EmitChanged(visible_);
  }

  if (private_connection_name_ != private_connection_name)
  {
    // FIXME: Update all the models as they are no longer valid when we use this
    private_connection_name_ = private_connection_name;
  }
  categories_->swarm_name = categories_model_name;
  filters_->swarm_name = filters_model_name;
  global_results_->swarm_name = global_results_model_name;
  results_->swarm_name = results_model_name;
}

void Lens::Impl::OnActiveChanged(bool is_active)
{
  proxy_.Call("SetActive", g_variant_new("(b)", is_active ? TRUE : FALSE));
}

void Lens::Impl::GlobalSearch(std::string const& search_string)
{
  LOG_DEBUG(logger) << "Global Searching " << id_ << " for " << search_string;

  GVariantBuilder b;
  g_variant_builder_init(&b, G_VARIANT_TYPE("a{sv}"));

  proxy_.Call("GlobalSearch",
              g_variant_new("(sa{sv})",
                            search_string.c_str(),
                            &b));
  g_variant_builder_clear(&b);
}

void Lens::Impl::Search(std::string const& search_string)
{
  LOG_DEBUG(logger) << "Searching " << id_ << " for " << search_string;

  GVariantBuilder b;
  g_variant_builder_init(&b, G_VARIANT_TYPE("a{sv}"));

  proxy_.Call("Search",
              g_variant_new("(sa{sv})",
                            search_string.c_str(),
                            &b));
  g_variant_builder_clear(&b);
}

void Lens::Impl::Activate(std::string const& uri)
{
  LOG_DEBUG(logger) << "Activating " << uri << " on  " << id_;

  proxy_.Call("Activate",
              g_variant_new("(su)", uri.c_str(), 0),
              sigc::mem_fun(this, &Lens::Impl::ActivationReply));
}

void Lens::Impl::ActivationReply(GVariant* parameters)
{
  glib::String uri;
  guint32 handled;
  GVariantIter* hints_iter;
  Hints hints;
  
  g_variant_get(parameters, "((sua{sv}))", &uri, &handled, &hints_iter);
  
  Utils::ASVToHints(hints, hints_iter);

  owner_->activated.emit(uri.Str(), static_cast<HandledType>(handled), hints);

  g_variant_iter_free(hints_iter);
}

void Lens::Impl::Preview(std::string const& uri)
{
  LOG_DEBUG(logger) << "Previewing " << uri << " on  " << id_;

  proxy_.Call("Preview",
              g_variant_new("(s)", uri.c_str()),
              sigc::mem_fun(this, &Lens::Impl::PreviewReply));
}

void Lens::Impl::PreviewReply(GVariant* parameters)
{
  glib::String uri;
  glib::String renderer_name;
  GVariantIter* hints_iter;
  Hints hints;
  
  g_variant_get(parameters, "((ssa{sv}))", &uri, &renderer_name, &hints_iter);
  Utils::ASVToHints(hints, hints_iter);

  Preview::Ptr preview = Preview::PreviewForProperties(renderer_name.Str(), hints);
  owner_->preview_ready.emit(uri.Str(), preview);

  g_variant_iter_free(hints_iter);
}
string const& Lens::Impl::id() const
{
  return id_;
}

string const& Lens::Impl::dbus_name() const
{
  return dbus_name_;
}

string const& Lens::Impl::dbus_path() const
{
  return dbus_path_;
}

string const& Lens::Impl::name() const
{
  return name_;
}

string const& Lens::Impl::icon_hint() const
{
  return icon_hint_;
}

string const& Lens::Impl::description() const
{
  return description_;
}

string const& Lens::Impl::search_hint() const
{
  return search_hint_;
}

bool Lens::Impl::visible() const
{
  return visible_;
}

bool Lens::Impl::search_in_global() const
{
  return search_in_global_;
}

string const& Lens::Impl::shortcut() const
{
  return shortcut_;
}

Results::Ptr const& Lens::Impl::results() const
{
  return results_;
}

Results::Ptr const& Lens::Impl::global_results() const
{
  return global_results_;
}

Categories::Ptr const& Lens::Impl::categories() const
{
  return categories_;
}

Filters::Ptr const& Lens::Impl::filters() const
{
  return filters_;
}

bool Lens::Impl::connected() const
{
  return connected_;
}

Lens::Lens(string const& id_,
           string const& dbus_name_,
           string const& dbus_path_,
           string const& name_,
           string const& icon_hint_,
           string const& description_,
           string const& search_hint_,
           bool visible_,
           string const& shortcut_)

  : pimpl(new Impl(this,
                   id_,
                   dbus_name_,
                   dbus_path_,
                   name_,
                   icon_hint_,
                   description_,
                   search_hint_,
                   visible_,
                   shortcut_))
{
  id.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::id));
  dbus_name.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::dbus_name));
  dbus_path.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::dbus_path));
  name.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::name));
  icon_hint.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::icon_hint));
  description.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::description));
  search_hint.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::search_hint));
  visible.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::visible));
  search_in_global.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::search_in_global));
  shortcut.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::shortcut));
  results.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::results));
  global_results.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::global_results));
  categories.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::categories));
  filters.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::filters));
  connected.SetGetterFunction(sigc::mem_fun(pimpl, &Lens::Impl::connected));
  active.changed.connect(sigc::mem_fun(pimpl, &Lens::Impl::OnActiveChanged));
}

Lens::~Lens()
{
  delete pimpl;
}

void Lens::GlobalSearch(std::string const& search_string)
{
  pimpl->GlobalSearch(search_string);
}

void Lens::Search(std::string const& search_string)
{
  pimpl->Search(search_string);
}

void Lens::Activate(std::string const& uri)
{
  pimpl->Activate(uri);
}

void Lens::Preview(std::string const& uri)
{
  pimpl->Preview(uri);
}

}
}
