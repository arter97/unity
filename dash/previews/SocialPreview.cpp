// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright 2012 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3, as
 * published by the  Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the applicable version of the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of both the GNU Lesser General Public
 * License version 3 along with this program.  If not, see
 * <http://www.gnu.org/licenses/>
 *
 * Authored by: Nick Dedekind <nick.dedekind@canonical.com>
 *
 */

#include "unity-shared/IntrospectableWrappers.h"
#include "unity-shared/PreviewStyle.h"
#include "unity-shared/IconTexture.h"
#include "unity-shared/StaticCairoText.h"
#include "unity-shared/PlacesVScrollBar.h"
#include <UnityCore/SocialPreview.h>
#include <NuxCore/Logger.h>
#include <Nux/HLayout.h>
#include <Nux/VLayout.h>
#include <Nux/GridHLayout.h>
#include <Nux/Button.h>
#include <glib/gi18n-lib.h>
 
#include "SocialPreview.h"
#include "SocialPreviewContent.h"
#include "ActionButton.h"
#include "PreviewInfoHintWidget.h"

namespace unity
{
namespace dash
{
namespace previews
{

namespace
{
nux::logging::Logger logger("unity.dash.previews.socialpreview");

}

class DetailsScrollView : public nux::ScrollView
{
public:
  DetailsScrollView(NUX_FILE_LINE_PROTO)
  : ScrollView(NUX_FILE_LINE_PARAM)
  {
    SetVScrollBar(new dash::PlacesVScrollBar(NUX_TRACKER_LOCATION));
  }

};

NUX_IMPLEMENT_OBJECT_TYPE(SocialPreview);

SocialPreview::SocialPreview(dash::Preview::Ptr preview_model)
: Preview(preview_model)
, full_data_layout_(nullptr)
{
  SetupBackground();
  SetupViews();
}

SocialPreview::~SocialPreview()
{
}

void SocialPreview::Draw(nux::GraphicsEngine& gfx_engine, bool force_draw)
{
  nux::Geometry const& base = GetGeometry();

  gfx_engine.PushClippingRectangle(base);
  nux::GetPainter().PaintBackground(gfx_engine, base);

  if (full_data_layout_)
  {
    unsigned int alpha, src, dest = 0;
    gfx_engine.GetRenderStates().GetBlend(alpha, src, dest);
    gfx_engine.GetRenderStates().SetBlend(true, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

    details_bg_layer_->SetGeometry(full_data_layout_->GetGeometry());
    nux::GetPainter().RenderSinglePaintLayer(gfx_engine, full_data_layout_->GetGeometry(), details_bg_layer_.get());

    gfx_engine.GetRenderStates().SetBlend(alpha, src, dest);
  }

  gfx_engine.PopClippingRectangle();
}

void SocialPreview::DrawContent(nux::GraphicsEngine& gfx_engine, bool force_draw)
{
  nux::Geometry const& base = GetGeometry();
  gfx_engine.PushClippingRectangle(base);

  if (!IsFullRedraw())
    nux::GetPainter().PushLayer(gfx_engine, details_bg_layer_->GetGeometry(), details_bg_layer_.get());

  unsigned int alpha, src, dest = 0;
  gfx_engine.GetRenderStates().GetBlend(alpha, src, dest);
  gfx_engine.GetRenderStates().SetBlend(true, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

  if (GetCompositionLayout())
    GetCompositionLayout()->ProcessDraw(gfx_engine, force_draw);

  gfx_engine.GetRenderStates().SetBlend(alpha, src, dest);

  if (!IsFullRedraw())
    nux::GetPainter().PopBackground();

  gfx_engine.PopClippingRectangle();
}

std::string SocialPreview::GetName() const
{
  return "SocialPreview";
}

void SocialPreview::AddProperties(GVariantBuilder* builder)
{
  Preview::AddProperties(builder);
}

void SocialPreview::SetupBackground()
{
  details_bg_layer_.reset(dash::previews::Style::Instance().GetBackgroundLayer());
}

void SocialPreview::SetupViews()
{
  dash::SocialPreview* social_preview_model = dynamic_cast<dash::SocialPreview*>(preview_model_.get());
  if (!social_preview_model)
  {
    LOG_ERROR(logger) << "Could not derive social preview model from given parameter.";
    return;
  }

  previews::Style& style = dash::previews::Style::Instance();

  nux::HLayout* image_data_layout = new nux::HLayout();
  image_data_layout->SetSpaceBetweenChildren(style.GetPanelSplitWidth());

  /////////////////////
  // Avatar
  nux::VLayout* social_content_layout = new nux::VLayout();
  social_content_layout->SetSpaceBetweenChildren(16);
  
  description_ = new SocialPreviewContent(social_preview_model->description, NUX_TRACKER_LOCATION);
  social_content_layout->AddView(description_.GetPointer(), 1);

  /////////////////////

    /////////////////////
    // Social Data Panel
    full_data_layout_ = new nux::VLayout();
    full_data_layout_->SetPadding(style.GetDetailsTopMargin(), 0, style.GetDetailsBottomMargin(), style.GetDetailsLeftMargin());
    full_data_layout_->SetSpaceBetweenChildren(16);

      /////////////////////
      // Main Social Info
      nux::HLayout* main_social_info = new nux::HLayout();
      main_social_info->SetSpaceBetweenChildren(style.GetSpaceBetweenIconAndDetails());

        /////////////////////
        // Icon Layout
        nux::VLayout* icon_layout = new nux::VLayout();
        icon_layout->SetSpaceBetweenChildren(3);
        avatar_ = new IconTexture(social_preview_model->avatar.Get().RawPtr() ? g_icon_to_string(social_preview_model->avatar.Get().RawPtr()) : "", MIN(style.GetAvatarAreaWidth(), style.GetAvatarAreaHeight()));
        avatar_->SetMinMaxSize(style.GetAvatarAreaWidth(), style.GetAvatarAreaHeight());
        icon_layout->AddView(avatar_.GetPointer(), 0);

        /////////////////////

        /////////////////////
        // Data
        nux::VLayout* social_data_layout = new nux::VLayout();
        social_data_layout->SetSpaceBetweenChildren(style.GetSpaceBetweenTitleAndSubtitle());

        title_ = new nux::StaticCairoText(preview_model_->title, true, NUX_TRACKER_LOCATION);
        title_->SetLines(-1);
        title_->SetFont(style.title_font().c_str());

        subtitle_ = new nux::StaticCairoText(preview_model_->subtitle, true, NUX_TRACKER_LOCATION);
        subtitle_->SetFont(style.subtitle_size_font().c_str());
        subtitle_->SetLines(-1);

        social_data_layout->AddView(title_.GetPointer(), 0);
        social_data_layout->AddView(subtitle_.GetPointer(), 0);
        social_data_layout->AddSpace(0, 1);

        // buffer space
        /////////////////////

      main_social_info->AddLayout(icon_layout, 0);
      main_social_info->AddLayout(social_data_layout, 1);
      /////////////////////

      /////////////////////
      // Details
      nux::ScrollView* social_info = new DetailsScrollView(NUX_TRACKER_LOCATION);
      social_info->EnableHorizontalScrollBar(false);

      nux::VLayout* social_info_layout = new nux::VLayout();
      social_info_layout->SetSpaceBetweenChildren(12);
      social_info->SetLayout(social_info_layout);

      if (!preview_model_->GetInfoHints().empty())
      {
        preview_info_hints_ = new PreviewInfoHintWidget(preview_model_, style.GetInfoHintIconSizeWidth());
        AddChild(preview_info_hints_.GetPointer());
        social_info_layout->AddView(preview_info_hints_.GetPointer());
      }
      /////////////////////

      /////////////////////
      // Comments/Replies
      //dash::SocialThread::Ptr thread_model = preview_model->GetThreadModel();
      //if (thread_model)
      //{
      //  thread_ = new previews::Tracks(tracks_model, NUX_TRACKER_LOCATION);
      //  AddChild(thread_.GetPointer());
      //}
      nux::ScrollView* social_thread = new DetailsScrollView(NUX_TRACKER_LOCATION);
      social_thread->EnableHorizontalScrollBar(false);

      nux::VLayout* social_thread_layout = new nux::VLayout();
      social_thread_layout->SetSpaceBetweenChildren(12);
      social_thread->SetLayout(social_thread_layout);
      nux::StaticCairoText* thread_sender_ = new nux::StaticCairoText(preview_model_->title, false, NUX_TRACKER_LOCATION);
      nux::StaticCairoText* thread_text_ = new nux::StaticCairoText(preview_model_->description, true, NUX_TRACKER_LOCATION);
      thread_text_->SetLines(-10);
      social_thread_layout->SetMaximumWidth(500);
      //social_thread->SetMaximumWidth(subtitle_->GetMaximumWidth());
      thread_sender_->SetFont(style.subtitle_size_font().c_str());
      thread_text_->SetFont(style.description_font().c_str());
      thread_text_->SetTextAlignment(nux::StaticCairoText::NUX_ALIGN_TOP);


      social_thread_layout->AddView(thread_sender_, 0);
      social_thread_layout->AddView(thread_text_, 0);

      //AddChild(thread_.GetPointer());

      
      /////////////////////

      /////////////////////
      // Actions
      action_buttons_.clear();
      nux::Layout* actions_layout = BuildGridActionsLayout(preview_model_->GetActions(), action_buttons_);
      actions_layout->SetLeftAndRightPadding(0, style.GetDetailsRightMargin());
      ///////////////////

    full_data_layout_->AddLayout(main_social_info, 0);
    full_data_layout_->AddView(social_info, 1);
    if (thread_text_)
    {
      full_data_layout_->AddView(social_thread, 2);
    }
    full_data_layout_->AddLayout(actions_layout, 0);
    /////////////////////
  
  image_data_layout->AddView(social_content_layout, 0);
  image_data_layout->AddLayout(full_data_layout_, 1);


  SetLayout(image_data_layout);
}

void SocialPreview::PreLayoutManagement()
{
  nux::Geometry geo = GetGeometry();

  previews::Style& style = dash::previews::Style::Instance();

  nux::Geometry geo_content(geo.x, geo.y, style.GetAppImageAspectRatio() * geo.height, geo.height);

  if (geo.width - geo_content.width - style.GetPanelSplitWidth() - style.GetDetailsLeftMargin() - style.GetDetailsRightMargin() < style.GetDetailsPanelMinimumWidth())
    geo_content.width = MAX(0, geo.width - style.GetPanelSplitWidth() - style.GetDetailsLeftMargin() - style.GetDetailsRightMargin() - style.GetDetailsPanelMinimumWidth());
  description_->SetMinMaxSize(geo_content.width, geo_content.height);

  int details_width = MAX(0, geo.width - geo_content.width - style.GetPanelSplitWidth() - style.GetDetailsLeftMargin() - style.GetDetailsRightMargin());
  int top_social_info_max_width = details_width - style.GetAppIconAreaWidth() - style.GetSpaceBetweenIconAndDetails();

  if (title_) { title_->SetMaximumWidth(top_social_info_max_width); }
  if (subtitle_) { subtitle_->SetMaximumWidth(top_social_info_max_width); }

  for (nux::AbstractButton* button : action_buttons_)
  {
    button->SetMinMaxSize(CLAMP((details_width - style.GetSpaceBetweenActions()) / 2, 0, style.GetActionButtonMaximumWidth()), style.GetActionButtonHeight());
  }

  Preview::PreLayoutManagement();
}

} // namespace previews
} // namespace dash
} // namepsace unity
