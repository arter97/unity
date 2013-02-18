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
 * Authored by: Jason Smith <jason.smith@canonical.com>
 */

#include <UnityCore/Variant.h>

#include "UnityWindowView.h"
#include <Nux/VLayout.h>

namespace unity {
namespace ui {

NUX_IMPLEMENT_OBJECT_TYPE(UnityWindowView);

UnityWindowView::UnityWindowView(NUX_FILE_LINE_DECL)
  : View(NUX_FILE_LINE_PARAM)
  , style(std::make_shared<UnityWindowStyle>())
  , closable(false)
  , internal_layout_(nullptr)
  , bounding_area_(new nux::InputArea())
{
  bg_helper_.owner = this;

  closable.changed.connect(sigc::mem_fun(this, &UnityWindowView::OnClosableChanged));

  // The bounding area always matches this size, but only handles events outside
  // the internal layout (when defined)
  bounding_area_->SetParentObject(this);
  geometry_changed.connect([this] (nux::Area*, nux::Geometry const& g) { bounding_area_->SetGeometry(g); });
}

UnityWindowView::~UnityWindowView()
{
  if (close_button_)
    close_button_->UnParentObject();

  bounding_area_->UnParentObject();
}

nux::Area*
UnityWindowView::FindAreaUnderMouse(const nux::Point& mouse, nux::NuxEventType etype)
{
  if (close_button_ && close_button_->TestMousePointerInclusionFilterMouseWheel(mouse, etype))
    return close_button_.GetPointer();

  nux::Area* under = nux::View::FindAreaUnderMouse(mouse, etype);

  if (under == this)
  {
    if (internal_layout_ && !internal_layout_->TestMousePointerInclusionFilterMouseWheel(mouse, etype))
    {
      if (bounding_area_->TestMousePointerInclusionFilterMouseWheel(mouse, etype))
        return bounding_area_.GetPointer();

      return nullptr;
    }
  }

  return under;
}

void
UnityWindowView::SetupBackground(bool enabled)
{
  bg_helper_.enabled = enabled;
}

void UnityWindowView::OnClosableChanged(bool closable)
{
  if (!closable)
  {
    close_button_ = nullptr;
    return;
  }

  auto const& texture = style()->GetCloseIcon();
  int padding = style()->GetCloseButtonPadding();
  close_button_ = new IconTexture(texture);
  close_button_->SetBaseXY(padding, padding);
  close_button_->SetParentObject(this);

  close_button_->mouse_enter.connect([this](int, int, unsigned long, unsigned long) {
    if (close_button_->IsMouseOwner())
      close_button_->SetTexture(style()->GetCloseIconPressed());
    else
      close_button_->SetTexture(style()->GetCloseIconHighligted());

     close_button_->QueueDraw();
  });

  close_button_->mouse_leave.connect([this](int, int, unsigned long, unsigned long) {
    close_button_->SetTexture(style()->GetCloseIcon());
  });

  close_button_->mouse_down.connect([this](int, int, unsigned long, unsigned long) {
    close_button_->SetTexture(style()->GetCloseIconPressed());
  });

  close_button_->mouse_up.connect([this](int, int, unsigned long, unsigned long) {
    bool inside = close_button_->IsMouseInside();
    close_button_->SetTexture(inside ? style()->GetCloseIconHighligted() : style()->GetCloseIcon());
  });

  close_button_->mouse_click.connect([this](int, int, unsigned long, unsigned long) {
    close_button_->SetTexture(style()->GetCloseIcon());
    request_close.emit();
  });

  close_button_->texture_updated.connect(sigc::hide(sigc::mem_fun(this, &UnityWindowView::QueueDraw)));
}

bool UnityWindowView::SetLayout(nux::Layout* layout)
{
  if (layout && layout->IsLayout())
  {
    int offset = style()->GetInternalOffset();

    // We wrap the internal layout adding some padding, so that inherited classes
    // can ignore the offsets we define here.
    nux::ObjectPtr<nux::Layout> wrapper(new nux::VLayout());
    wrapper->SetPadding(offset, offset);
    wrapper->AddLayout(layout);

    if (View::SetLayout(wrapper.GetPointer()))
    {
      internal_layout_ = layout;
      return true;
    }
  }

  return false;
}

nux::Layout* UnityWindowView::GetLayout()
{
  return internal_layout_;
}

nux::Geometry UnityWindowView::GetInternalBackground()
{
  int offset = style()->GetInternalOffset();
  return GetBackgroundGeometry().GetExpand(-offset, -offset);
}

nux::ObjectPtr<nux::InputArea> UnityWindowView::GetBoundingArea() const
{
  return bounding_area_;
}

void UnityWindowView::Draw(nux::GraphicsEngine& GfxContext, bool force_draw)
{
  PreDraw(GfxContext, force_draw);
  unsigned push = 0;

  nux::Geometry const& base = GetGeometry();
  GfxContext.PushClippingRectangle(base); ++push;

  // clear region
  gPainter.PaintBackground(GfxContext, base);

  nux::Geometry const& internal_clip = GetInternalBackground();
  GfxContext.PushClippingRectangle(internal_clip); ++push;

  nux::Geometry const& blur_geo = GetAbsoluteGeometry();

  if (BackgroundEffectHelper::blur_type != BLUR_NONE)
  {
    bg_texture_ = bg_helper_.GetBlurRegion(blur_geo);
  }
  else
  {
    bg_texture_ = bg_helper_.GetRegion(blur_geo);
  }

  if (bg_texture_.IsValid())
  {
    nux::TexCoordXForm texxform_blur_bg;
    texxform_blur_bg.flip_v_coord = true;
    texxform_blur_bg.SetTexCoordType(nux::TexCoordXForm::OFFSET_COORD);
    texxform_blur_bg.uoffset = base.x / static_cast<float>(blur_geo.width);
    texxform_blur_bg.voffset = base.y / static_cast<float>(blur_geo.height);

    nux::ROPConfig rop;
    rop.Blend = false;
    rop.SrcBlend = GL_ONE;
    rop.DstBlend = GL_ONE_MINUS_SRC_ALPHA;

#ifndef NUX_OPENGLES_20
    if (GfxContext.UsingGLSLCodePath())
      gPainter.PushDrawCompositionLayer(GfxContext, base,
                                        bg_texture_,
                                        texxform_blur_bg,
                                        nux::color::White,
                                        background_color, nux::LAYER_BLEND_MODE_OVERLAY,
                                        true, rop);
    else
      gPainter.PushDrawTextureLayer(GfxContext, base,
                                    bg_texture_,
                                    texxform_blur_bg,
                                    nux::color::White,
                                    true,
                                    rop);
#else
      gPainter.PushDrawCompositionLayer(GfxContext, base,
                                        bg_texture_,
                                        texxform_blur_bg,
                                        nux::color::White,
                                        background_color, nux::LAYER_BLEND_MODE_OVERLAY,
                                        true, rop);
#endif
  }

  nux::ROPConfig rop;
  rop.Blend = true;

#ifndef NUX_OPENGLES_20
  if (GfxContext.UsingGLSLCodePath() == false)
  {
    rop.SrcBlend = GL_ONE;
    rop.DstBlend = GL_ONE_MINUS_SRC_ALPHA;
    gPainter.PushDrawColorLayer (GfxContext, internal_clip, background_color, false, rop);
  }
#endif

  // Make round corners
  rop.Blend = true;
  rop.SrcBlend = GL_ZERO;
  rop.DstBlend = GL_SRC_ALPHA;
  gPainter.PaintShapeCornerROP(GfxContext,
                               internal_clip,
                               nux::color::White,
                               nux::eSHAPE_CORNER_ROUND4,
                               nux::eCornerTopLeft | nux::eCornerTopRight |
                               nux::eCornerBottomLeft | nux::eCornerBottomRight,
                               true,
                               rop);

  DrawOverlay(GfxContext, force_draw, internal_clip);

  for (unsigned i = 0; i < push; ++i)
    GfxContext.PopClippingRectangle();

  DrawBackground(GfxContext, GetBackgroundGeometry());

  if (close_button_)
  {
    nux::GetPainter().PushPaintLayerStack();
    GfxContext.GetRenderStates().SetBlend(true, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

    // Just doing ProcessDraw on the area should be enough, but unfortunately
    // this leads to a flickering close icon that is randomly drawn.
    // close_button_->ProcessDraw(GfxContext, force_draw);

    nux::TexCoordXForm texxform;
    auto const& geo = close_button_->GetGeometry();
    GfxContext.QRP_1Tex(geo.x, geo.y, geo.width, geo.height,
                        close_button_->texture()->GetDeviceTexture(),
                        texxform, nux::color::White);

    GfxContext.GetRenderStates().SetBlend(false);
    nux::GetPainter().PopPaintLayerStack();
  }
}

void UnityWindowView::DrawBackground(nux::GraphicsEngine& GfxContext, nux::Geometry const& geo)
{
  int border = style()->GetBorderSize();

  GfxContext.GetRenderStates().SetBlend(true, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

  nux::TexCoordXForm texxform;
  texxform.SetTexCoordType (nux::TexCoordXForm::OFFSET_COORD);
  texxform.SetWrap(nux::TEXWRAP_REPEAT, nux::TEXWRAP_REPEAT);

  // Draw TOP-LEFT CORNER
  texxform.u0 = 0;
  texxform.v0 = 0;
  texxform.u1 = border;
  texxform.v1 = border;
  GfxContext.QRP_1Tex (geo.x, geo.y,
                       border, border, style()->GetBackgroundCorner()->GetDeviceTexture(), texxform, nux::color::White);

  // Draw TOP-RIGHT CORNER
  texxform.u0 = 0;
  texxform.v0 = 0;
  texxform.u1 = border;
  texxform.v1 = border;
  texxform.flip_u_coord = true;
  texxform.flip_v_coord = false;
  GfxContext.QRP_1Tex (geo.x + geo.width - border, geo.y,
                       border, border, style()->GetBackgroundCorner()->GetDeviceTexture(), texxform, nux::color::White);

  // Draw BOTTOM-LEFT CORNER
  texxform.u0 = 0;
  texxform.v0 = 0;
  texxform.u1 = border;
  texxform.v1 = border;
  texxform.flip_u_coord = false;
  texxform.flip_v_coord = true;
  GfxContext.QRP_1Tex (geo.x, geo.y + geo.height - border,
                       border, border, style()->GetBackgroundCorner()->GetDeviceTexture(), texxform, nux::color::White);

  // Draw BOTTOM-RIGHT CORNER
  texxform.u0 = 0;
  texxform.v0 = 0;
  texxform.u1 = border;
  texxform.v1 = border;
  texxform.flip_u_coord = true;
  texxform.flip_v_coord = true;
  GfxContext.QRP_1Tex (geo.x + geo.width - border, geo.y + geo.height - border,
                       border, border, style()->GetBackgroundCorner()->GetDeviceTexture(), texxform, nux::color::White);

  int top_width = style()->GetBackgroundTop()->GetWidth();
  int top_height = style()->GetBackgroundTop()->GetHeight();

  // Draw TOP BORDER
  texxform.u0 = 0;
  texxform.v0 = 0;
  texxform.u1 = top_width;
  texxform.v1 = top_height;
  texxform.flip_u_coord = false;
  texxform.flip_v_coord = false;
  GfxContext.QRP_1Tex (geo.x + border, geo.y, geo.width - border - border, border, style()->GetBackgroundTop()->GetDeviceTexture(), texxform, nux::color::White);

  // Draw BOTTOM BORDER
  texxform.u0 = 0;
  texxform.v0 = 0;
  texxform.u1 = top_width;
  texxform.v1 = top_height;
  texxform.flip_u_coord = false;
  texxform.flip_v_coord = true;
  GfxContext.QRP_1Tex (geo.x + border, geo.y + geo.height - border, geo.width - border - border, border, style()->GetBackgroundTop()->GetDeviceTexture(), texxform, nux::color::White);


  int left_width = style()->GetBackgroundLeft()->GetWidth();
  int left_height = style()->GetBackgroundLeft()->GetHeight();

  // Draw LEFT BORDER
  texxform.u0 = 0;
  texxform.v0 = 0;
  texxform.u1 = left_width;
  texxform.v1 = left_height;
  texxform.flip_u_coord = false;
  texxform.flip_v_coord = false;
  GfxContext.QRP_1Tex (geo.x, geo.y + border, border, geo.height - border - border, style()->GetBackgroundLeft()->GetDeviceTexture(), texxform, nux::color::White);

  // Draw RIGHT BORDER
  texxform.u0 = 0;
  texxform.v0 = 0;
  texxform.u1 = left_width;
  texxform.v1 = left_height;
  texxform.flip_u_coord = true;
  texxform.flip_v_coord = false;
  GfxContext.QRP_1Tex (geo.x + geo.width - border, geo.y + border, border, geo.height - border - border, style()->GetBackgroundLeft()->GetDeviceTexture(), texxform, nux::color::White);

  GfxContext.GetRenderStates().SetBlend(false);
}

// Introspectable methods
std::string UnityWindowView::GetName() const
{
  return "UnityWindowView";
}

void UnityWindowView::AddProperties(GVariantBuilder* builder)
{
  unity::variant::BuilderWrapper(builder)
    .add("bg-texture-is-valid", bg_texture_.IsValid());
}


}
}
