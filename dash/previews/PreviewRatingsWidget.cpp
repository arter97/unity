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

#include <Nux/Nux.h>
#include <Nux/VLayout.h>
#include <glib.h>
#include <glib/gi18n-lib.h>

#include "unity-shared/RatingsButton.h"
#include "unity-shared/StaticCairoText.h"
#include "unity-shared/PreviewStyle.h"
#include "PreviewRatingsWidget.h"

namespace unity
{
namespace dash
{
namespace previews
{

NUX_IMPLEMENT_OBJECT_TYPE(PreviewRatingsWidget);

PreviewRatingsWidget::PreviewRatingsWidget(NUX_FILE_LINE_DECL)
  : View(NUX_FILE_LINE_PARAM)
{
  nux::VLayout* layout = new nux::VLayout();
  layout->SetSpaceBetweenChildren(3);

  previews::Style& style = previews::Style::Instance();

  ratings_ = new RatingsButton(18,2);
  ratings_->SetEditable(false);
  layout->AddView(ratings_);
  

  reviews_ = new nux::StaticCairoText("");
  reviews_->SetFont(style.user_rating_font());
  layout->AddView(reviews_);

  SetLayout(layout);
}

PreviewRatingsWidget::~PreviewRatingsWidget()
{
}

void PreviewRatingsWidget::SetRating(float rating)
{
  ratings_->SetRating(rating);
}

float PreviewRatingsWidget::GetRating() const
{
  return ratings_->GetRating();
}

void PreviewRatingsWidget::SetReviews(int count)
{
  std::stringstream out;
  out << count;
  out << " reviews";

  reviews_->SetText(out.str());
}



void PreviewRatingsWidget::Draw(nux::GraphicsEngine& gfx_engine, bool force_draw)
{
}

void PreviewRatingsWidget::DrawContent(nux::GraphicsEngine& gfx_engine, bool force_draw)
{
  nux::Geometry const& base = GetGeometry();
  gfx_engine.PushClippingRectangle(base);

  if (GetCompositionLayout())
    GetCompositionLayout()->ProcessDraw(gfx_engine, force_draw);

  gfx_engine.PopClippingRectangle();
}



} // namespace previews
} // namespace dash
} // namespace unity