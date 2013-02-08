// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2011-2012 Canonical Ltd
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
 *              Michal Hruby <michal.hruby@canonical.com>
 */

#include <NuxCore/Logger.h>
#include <unity-protocol.h>

#include "Preview.h"
#include "Scope.h"

#include "ApplicationPreview.h"
#include "GenericPreview.h"
#include "MusicPreview.h"
#include "MoviePreview.h"
#include "SocialPreview.h"
#include "SeriesPreview.h"

namespace unity
{
namespace dash
{
DECLARE_LOGGER(logger, "unity.dash.preview");

Preview::Ptr Preview::PreviewForProtocolObject(glib::Object<GObject> const& proto_obj)
{
  if (!proto_obj || !UNITY_PROTOCOL_IS_PREVIEW(proto_obj.RawPtr()))
  {
    LOG_WARN(logger) << "Unable to create Preview object from " << proto_obj.RawPtr();
    return nullptr;
  }

  std::string renderer_name(
      unity_protocol_preview_get_renderer_name(
        UNITY_PROTOCOL_PREVIEW(proto_obj.RawPtr())));

  if (renderer_name == "preview-generic")
  {
    return Preview::Ptr(new GenericPreview(proto_obj));
  }
  else if (renderer_name == "preview-application")
  {
    return Preview::Ptr(new ApplicationPreview(proto_obj));
  }
  else if (renderer_name == "preview-music")
  {
    return Preview::Ptr(new MusicPreview(proto_obj));
  }
  else if (renderer_name == "preview-movie")
  {
    return Preview::Ptr(new MoviePreview(proto_obj));
  }
  else if (renderer_name == "preview-social")
  {
    return Preview::Ptr(new SocialPreview(proto_obj));
  }
  else if (renderer_name == "preview-series")
  {
    return Preview::Ptr(new SeriesPreview(proto_obj));
  }
  else
  {
    LOG_WARN(logger) << "Unable to create Preview for renderer: " << renderer_name;
  }

  return nullptr;
}

Preview::Ptr Preview::PreviewForVariant(glib::Variant const& properties)
{
  glib::Object<UnityProtocolPreview> preview(unity_protocol_preview_parse(properties));
  if (!preview)
  {
    LOG_WARN(logger) << "Unable to create Preview object for variant type: " << g_variant_get_type_string(properties);
    return nullptr;
  }

  auto proto_obj = unity::glib::object_cast<GObject>(preview);
  return PreviewForProtocolObject(proto_obj);
}

unity::glib::Object<GIcon> Preview::IconForString(std::string const& icon_hint)
{
  glib::Error error;
  glib::Object<GIcon> icon(g_icon_new_for_string(icon_hint.c_str(), &error));

  if (error)
  {
    LOG_WARN(logger) << "Unable to instantiate icon: " << icon_hint;
  }

  return icon;
}

class Preview::Impl
{
public:
  Impl(Preview* owner, glib::Object<GObject> const& proto_obj);

  void SetupGetters();
  std::string get_renderer_name() const { return renderer_name_; };
  std::string get_title() const { return title_; };
  std::string get_subtitle() const { return subtitle_; };
  std::string get_description() const { return description_; };
  unity::glib::Object<GIcon> get_image() const { return image_; };
  std::string get_image_source_uri() const { return image_source_uri_; };
  ActionPtrList get_actions() const { return actions_list_; };
  InfoHintPtrList get_info_hints() const { return info_hint_list_; };
  void EmitClosed() const;

  Scope* get_parent_scope() const { return parent_scope_; };
  bool set_parent_scope(Scope* scope)
  {
    parent_scope_ = scope;
    return false; // TODO: do we need the notifications here?
  };

  Preview* owner_;
  glib::Object<UnityProtocolPreview> raw_preview_;

  std::string renderer_name_;
  std::string title_;
  std::string subtitle_;
  std::string description_;
  unity::glib::Object<GIcon> image_;
  std::string image_source_uri_;
  ActionPtrList actions_list_;
  InfoHintPtrList info_hint_list_;
  Scope* parent_scope_;
};

Preview::Impl::Impl(Preview* owner, glib::Object<GObject> const& proto_obj)
  : owner_(owner)
  , parent_scope_(nullptr)
{
  if (!proto_obj)
  {
    LOG_WARN(logger) << "Passed nullptr to Preview constructor";
  }
  else if (UNITY_PROTOCOL_IS_PREVIEW(proto_obj.RawPtr()))
  {
    raw_preview_ = glib::object_cast<UnityProtocolPreview>(proto_obj);
    const gchar *s;
    // renderer is guaranteed to be non-NULL, if it is it's a bug in proto lib
    renderer_name_ = unity_protocol_preview_get_renderer_name(raw_preview_);
    s = unity_protocol_preview_get_title(raw_preview_);
    if (s) title_ = s;
    s = unity_protocol_preview_get_subtitle(raw_preview_);
    if (s) subtitle_ = s;
    s = unity_protocol_preview_get_description(raw_preview_);
    if (s) description_ = s;
    glib::Object<GIcon> icon(unity_protocol_preview_get_image(raw_preview_),
                             unity::glib::AddRef());
    image_ = icon;
    s = unity_protocol_preview_get_image_source_uri(raw_preview_);
    if (s) image_source_uri_ = s;

    int actions_len;
    auto actions = unity_protocol_preview_get_actions(raw_preview_, &actions_len);
    for (int i = 0; i < actions_len; i++)
    {
      UnityProtocolPreviewActionRaw *raw_action = &actions[i];
      actions_list_.push_back(std::make_shared<Action>(
            raw_action->id, raw_action->display_name,
            raw_action->icon_hint,
            static_cast<LayoutHint>(raw_action->layout_hint),
            raw_action->hints));
    }
    
    int info_hints_len;
    auto info_hints = unity_protocol_preview_get_info_hints(raw_preview_, &info_hints_len);
    for (int i = 0; i < info_hints_len; i++)
    {
      UnityProtocolInfoHintRaw *raw_hint = &info_hints[i];
      info_hint_list_.push_back(std::make_shared<InfoHint>(
            raw_hint->id, raw_hint->display_name, raw_hint->icon_hint,
            raw_hint->value));
    }
  }
  else
  {
    LOG_WARN(logger) << "Object passed to Preview constructor isn't UnityProtocolPreview";
  }

  SetupGetters();
}

void Preview::Impl::SetupGetters()
{
  owner_->renderer_name.SetGetterFunction(
      sigc::mem_fun(this, &Preview::Impl::get_renderer_name));
  owner_->title.SetGetterFunction(
      sigc::mem_fun(this, &Preview::Impl::get_title));
  owner_->subtitle.SetGetterFunction(
      sigc::mem_fun(this, &Preview::Impl::get_subtitle));
  owner_->description.SetGetterFunction(
      sigc::mem_fun(this, &Preview::Impl::get_description));
  owner_->image.SetGetterFunction(
      sigc::mem_fun(this, &Preview::Impl::get_image));
  owner_->image_source_uri.SetGetterFunction(
    sigc::mem_fun(this, &Preview::Impl::get_image_source_uri));

  owner_->parent_scope.SetGetterFunction(
      sigc::mem_fun(this, &Preview::Impl::get_parent_scope));
  owner_->parent_scope.SetSetterFunction(
      sigc::mem_fun(this, &Preview::Impl::set_parent_scope));
}

void Preview::Impl::EmitClosed() const
{
  UnityProtocolPreview *preview = UNITY_PROTOCOL_PREVIEW(raw_preview_.RawPtr());

  unity_protocol_preview_begin_updates(preview);
  unity_protocol_preview_preview_closed(raw_preview_);
  glib::Variant properties(unity_protocol_preview_end_updates(preview),
                           glib::StealRef());

  glib::HintsMap property_hints;
  if (properties.ASVToHints(property_hints))
    owner_->Update(property_hints);
  else
    LOG_ERROR(logger) << "EmitClosed could not convert property hints to variant for " << owner_->preview_result.uri;
}

Preview::Preview(glib::Object<GObject> const& proto_obj)
  : pimpl(new Impl(this, proto_obj))
{
}

Preview::~Preview()
{
}

Preview::ActionPtrList Preview::GetActions() const
{
  return pimpl->get_actions();
}

Preview::InfoHintPtrList Preview::GetInfoHints() const
{
  return pimpl->get_info_hints();
}

void Preview::Update(glib::HintsMap const& property_hints,
                     std::function<void(glib::HintsMap const&, glib::Error const&)> const& reply_callback) const
{
  if (pimpl->parent_scope_)
  {
    pimpl->parent_scope_->UpdatePreviewProperty(preview_result, property_hints, reply_callback);
  }
  else
  {
    LOG_WARN(logger) << "Unable to update Preview, parent_scope_ wasn't set!";
  }
}

void Preview::PerformAction(std::string const& id, glib::HintsMap const& hints) const
{
  if (pimpl->parent_scope_)
  {
    pimpl->parent_scope_->ActivatePreviewAction(id, preview_result, hints);
  }
  else
  {
    LOG_WARN(logger) << "Unable to perform action '" << id << "', parent_scope_ wasn't set!";
  }
}

void Preview::EmitClosed() const
{
  pimpl->EmitClosed();
}

} // namespace dash
} // namespace unity
