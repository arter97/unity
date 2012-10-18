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
 * Authored by: Manuel de la Pena <manuel.delapena@canonical.com>
 *
 */

#include "ActionLink.h"
#include <NuxCore/Logger.h>
#include <Nux/VLayout.h>
#include <UnityCore/Variant.h>
#include "unity-shared/DashStyle.h"
#include "unity-shared/IconTexture.h"
#include "unity-shared/StaticCairoText.h"

namespace
{
nux::logging::Logger logger("unity.dash.actionlink");
}

namespace unity
{
namespace dash
{

ActionLink::ActionLink(std::string const& action_hint, std::string const& label, NUX_FILE_LINE_DECL)
  : nux::AbstractButton(NUX_FILE_LINE_PARAM)
  , action_hint_(action_hint)
{
  SetAcceptKeyNavFocusOnMouseDown(false);
  SetAcceptKeyNavFocusOnMouseEnter(true);
  Init();
  BuildLayout(label);
}

ActionLink::~ActionLink()
{
}

std::string ActionLink::GetName() const
{
  return "ActionLink";
}

void ActionLink::AddProperties(GVariantBuilder* builder)
{
  variant::BuilderWrapper(builder)
    .add(GetAbsoluteGeometry())
    .add("action", action_hint_)
    .add("label", label_)
    .add("font-hint", font_hint_)
    .add("active", active_);
}

void ActionLink::Init()
{
  SetMinimumHeight(40);

  key_nav_focus_change.connect([&] (nux::Area*, bool, nux::KeyNavDirection)
  {
    QueueDraw();
  });

  key_nav_focus_activate.connect([&](nux::Area*)
  {
    if (GetInputEventSensitivity())
      activate.emit(this, action_hint_);
  });
}

void ActionLink::BuildLayout(std::string const& label)
{

  if (label != label_)
  {
    label_ = label;
    if (static_text_)
    {
      static_text_.Release();
      static_text_ = NULL;
    }

    if (!label_.empty())
    {
      static_text_ = new nux::StaticCairoText(label_, true, NUX_TRACKER_LOCATION);
      if (!font_hint_.empty())
        static_text_->SetFont(font_hint_);
      static_text_->SetInputEventSensitivity(false);
      static_text_->SetTextAlignment(nux::StaticCairoText::NUX_ALIGN_CENTRE);
      static_text_->SetUnderline(nux::StaticCairoText::NUX_UNDERLINE_SINGLE);
    }
  }

  RemoveLayout();

  nux::VLayout* layout = new nux::VLayout();
  if (static_text_)
  {
    layout->AddView(static_text_.GetPointer(),
                    1, nux::MINOR_POSITION_START, nux::MINOR_SIZE_FULL,
                    100.0f, nux::NUX_LAYOUT_END);
  }
  SetLayout(layout);

  ComputeContentSize();
  QueueDraw();
}

long ActionLink::ComputeContentSize()
{
  long ret = nux::View::ComputeContentSize();

  nux::Geometry const& geo = GetGeometry();

  if (cached_geometry_ != geo && geo.width > 0 && geo.height > 0)
  {
    cached_geometry_ = geo;
  }

  return ret;
}

void ActionLink::Draw(nux::GraphicsEngine& GfxContext, bool force_draw)
{
  nux::Geometry const& geo = GetGeometry();

  gPainter.PaintBackground(GfxContext, geo);
  // set up our texture mode
  nux::TexCoordXForm texxform;
  texxform.SetWrap(nux::TEXWRAP_REPEAT, nux::TEXWRAP_REPEAT);
  texxform.SetTexCoordType(nux::TexCoordXForm::OFFSET_COORD);

  // clear what is behind us
  unsigned int alpha = 0, src = 0, dest = 0;
  GfxContext.GetRenderStates().GetBlend(alpha, src, dest);
  GfxContext.GetRenderStates().SetBlend(true, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

  nux::Color col = nux::color::Black;
  col.alpha = 0;
  GfxContext.QRP_Color(geo.x,
                       geo.y,
                       geo.width,
                       geo.height,
                       col);

  GfxContext.GetRenderStates().SetBlend(alpha, src, dest);

  if (GetCompositionLayout())
  {
    gPainter.PushPaintLayerStack();
    {
      nux::Geometry clip_geo = geo;

      GfxContext.PushClippingRectangle(clip_geo);
      gPainter.PushPaintLayerStack();
      GetCompositionLayout()->ProcessDraw(GfxContext, force_draw);
      gPainter.PopPaintLayerStack();
      GfxContext.PopClippingRectangle();
    }
    gPainter.PopPaintLayerStack();
  }
}

void ActionLink::RecvClick(int x, int y, unsigned long button_flags, unsigned long key_flags)
{
  activate.emit(this, action_hint_);
}

void ActionLink::SetFont(std::string const& font_hint)
{
  if (static_text_)
  {
    static_text_->SetFont(font_hint);
    ComputeContentSize();
    QueueDraw();
  }
}

std::string ActionLink::GetLabel() const
{
  return label_;
}

} // namespace dash
} // namespace unity
