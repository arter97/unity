// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright 2011 Canonical Ltd.
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

#include "ApplicationPreview.h"
#include "ActionButton.h"
#include "unity-shared/IntrospectableWrappers.h"
#include "unity-shared/PreviewStyle.h"
#include "unity-shared/ApplicationScreenshot.h"
#include "unity-shared/IconTexture.h"
#include <UnityCore/ApplicationPreview.h>
#include <NuxCore/Logger.h>
#include <Nux/HLayout.h>
#include <Nux/VLayout.h>
#include <Nux/Button.h>
#include <PreviewFactory.h>
#include "PreviewInfoHintWidget.h"
#include "PreviewRatingsWidget.h"


namespace unity
{
namespace dash
{
namespace previews
{

#define TMP_VIEW(name, colour) \
class TmpView_##name : public nux::View \
{ \
public: \
  TmpView_##name():View(NUX_TRACKER_LOCATION) {} \
  ~TmpView_##name() {} \
  virtual void Draw(nux::GraphicsEngine& gfx_engine, bool force_draw) { \
    gPainter.Paint2DQuadColor(gfx_engine, GetGeometry(), colour); \
  } \
  virtual void DrawContent(nux::GraphicsEngine& gfx_engine, bool force_draw) {} \
};

TMP_VIEW(AppImage, nux::Color(0xAA, 0x00, 0x00, 0.1f))
TMP_VIEW(AppIcon, nux::Color(0x00, 0x00, 0xAA, 0.1f))
TMP_VIEW(UserRating, nux::Color(0x00, 0xAA, 0x00, 0.1f))
TMP_VIEW(Actions, nux::Color(0x00, 0xAA, 0xAA, 0.1f))

namespace
{
nux::logging::Logger logger("unity.dash.previews.applicationpreview");

}

NUX_IMPLEMENT_OBJECT_TYPE(ApplicationPreview);

ApplicationPreview::ApplicationPreview(dash::Preview::Ptr preview_model)
: Preview(preview_model)
, full_data_layout_(nullptr)
{
  SetupBackground();
  SetupViews();
}

ApplicationPreview::~ApplicationPreview()
{
}

void ApplicationPreview::Draw(nux::GraphicsEngine& gfx_engine, bool force_draw)
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

void ApplicationPreview::DrawContent(nux::GraphicsEngine& gfx_engine, bool force_draw)
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

std::string ApplicationPreview::GetName() const
{
  return "ApplicationPreview";
}

void ApplicationPreview::AddProperties(GVariantBuilder* builder)
{
  Preview::AddProperties(builder);
}

void ApplicationPreview::SetupBackground()
{
  nux::ROPConfig rop;
  rop.Blend = true;
  rop.SrcBlend = GL_ONE;
  rop.DstBlend = GL_ONE_MINUS_SRC_ALPHA;
  details_bg_layer_.reset(new nux::ColorLayer(nux::Color(0.03f, 0.03f, 0.03f, 0.0f), true, rop));
}

void ApplicationPreview::SetupViews()
{
  dash::ApplicationPreview* app_preview_model = dynamic_cast<dash::ApplicationPreview*>(preview_model_.get());
  if (!app_preview_model)
    return;

  previews::Style& style = dash::previews::Style::Instance();

  nux::HLayout* image_data_layout = new nux::HLayout();
  image_data_layout->SetSpaceBetweenChildren(12);

  ApplicationScreenshot* app_image = new ApplicationScreenshot("../../../dash/previews/Skype.png");

    /////////////////////
    // App Data Panel
    full_data_layout_ = new nux::VLayout();
    full_data_layout_->SetPadding(10);
    full_data_layout_->SetSpaceBetweenChildren(16);

      /////////////////////
      // Main App Info
      nux::HLayout* main_app_info = new nux::HLayout();
      main_app_info->SetSpaceBetweenChildren(16);

        /////////////////////
        // Icon Layout
        nux::VLayout* icon_layout = new nux::VLayout();
        app_icon_ = new IconTexture(g_icon_to_string(app_preview_model->app_icon.Get().RawPtr()), 72);
        app_icon_->SetMinimumSize(100,100);
        app_icon_->SetMaximumSize(100,100);
        icon_layout->AddView(app_icon_, 0);

        app_rating_ = new PreviewRatingsWidget();
        app_rating_->SetMinimumHeight(36);
        app_rating_->SetRating(0.7);
        app_rating_->SetReviews(17);
        icon_layout->AddView(app_rating_, 0);

        // buffer space      
        /////////////////////

        /////////////////////
        // App Data
        nux::VLayout* app_data_layout = new nux::VLayout();
        app_data_layout->SetSpaceBetweenChildren(14);

        nux::VLayout* app_name_subtitle_layout = new nux::VLayout();
        app_name_subtitle_layout->SetSpaceBetweenChildren(8);

        app_name_ = new nux::StaticCairoText(app_preview_model->title);
        app_name_->SetFont(style.app_name_font().c_str());

        subtitle_ = new nux::StaticCairoText(app_preview_model->subtitle);
        subtitle_->SetFont(style.version_size_font().c_str());

        nux::VLayout* app_updated_copywrite_layout = new nux::VLayout();
        app_updated_copywrite_layout->SetSpaceBetweenChildren(8);

        license_ = new nux::StaticCairoText(app_preview_model->license);
        license_->SetFont(style.app_license_font().c_str());

        last_update_ = new nux::StaticCairoText(std::string("Last Updated ") + app_preview_model->last_update.Get());
        last_update_->SetFont(style.app_last_update_font().c_str());

        copywrite_ = new nux::StaticCairoText(app_preview_model->copyright);
        copywrite_->SetFont(style.app_copywrite_font().c_str());

        app_name_subtitle_layout->AddView(app_name_, 1);
        app_name_subtitle_layout->AddView(subtitle_, 1);

        app_updated_copywrite_layout->AddView(license_, 1);
        app_updated_copywrite_layout->AddView(last_update_, 1);
        app_updated_copywrite_layout->AddView(copywrite_, 1);

        app_data_layout->AddLayout(app_name_subtitle_layout);
        app_data_layout->AddLayout(app_updated_copywrite_layout);

        // buffer space
        /////////////////////

      main_app_info->AddLayout(icon_layout, 0);
      main_app_info->AddLayout(app_data_layout, 1);
      /////////////////////

      /////////////////////
      // App Description
      nux::ScrollView* app_info = new nux::ScrollView(NUX_TRACKER_LOCATION);
      app_info->EnableHorizontalScrollBar(false);

      nux::VLayout* app_info_layout = new nux::VLayout();
      app_info_layout->SetSpaceBetweenChildren(16);
      app_info->SetLayout(app_info_layout);

      app_description_ = new nux::StaticCairoText("");
      app_description_->SetFont(style.app_description_font().c_str());
      app_description_->SetTextAlignment(nux::StaticCairoText::NUX_ALIGN_TOP);
      app_description_->SetLines(-20);
      app_description_->SetLineSpacing(1);
      app_description_->SetMaximumWidth(400);
      app_description_->SetText(app_preview_model->description);

      PreviewInfoHintWidget* preview_info_hints = new PreviewInfoHintWidget(preview_model_);

      app_info_layout->AddView(app_description_);
      app_info_layout->AddView(preview_info_hints);
      /////////////////////

      /////////////////////
      // App Actions
      nux::HLayout* actions_layout = new nux::HLayout();
      actions_layout->SetSpaceBetweenChildren(12);
      actions_layout->AddSpace(0, 1);

      for (dash::Preview::ActionPtr action : preview_model_->GetActions())
      {
        ActionButton* button = new ActionButton(action->display_name, NUX_TRACKER_LOCATION);
        button->click.connect(sigc::bind(sigc::mem_fun(this, &ApplicationPreview::OnActionActivated), action->id));

        actions_layout->AddView(button, 0);
      }
      /////////////////////

    full_data_layout_->AddLayout(main_app_info, 0);
    full_data_layout_->AddView(app_info, 1);
    full_data_layout_->AddLayout(actions_layout, 0);
    /////////////////////
  
  image_data_layout->AddView(app_image, 1);
  image_data_layout->AddLayout(full_data_layout_, 1);

  SetLayout(image_data_layout);
}

void ApplicationPreview::OnActionActivated(nux::Button*, std::string const& id)
{
  if (preview_model_)
    preview_model_->PerformAction(id);
}

} // namespace previews
} // namespace dash
} // namepsace unity
