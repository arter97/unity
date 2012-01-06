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
 * Authored by: Gordon Allott <gord.allott@canonical.com>
 *
 */



#ifndef FILTERBASICBUTTON_H
#define FILTERBASICBUTTON_H

#include <Nux/Nux.h>
#include <Nux/CairoWrapper.h>
#include <Nux/Button.h>
#include <Nux/TextureArea.h>
#include <UnityCore/Hud.h>

namespace unity {

namespace hud {
  class HudButton : public nux::Button {
    typedef nux::ObjectPtr<nux::BaseTexture> BaseTexturePtr;
  public:
    HudButton (nux::TextureArea *image, NUX_FILE_LINE_PROTO);
    HudButton (const std::string label, NUX_FILE_LINE_PROTO);
    HudButton (const std::string label, nux::TextureArea *image, NUX_FILE_LINE_PROTO);
    HudButton (NUX_FILE_LINE_PROTO);
    virtual ~HudButton();

    void SetSuggestion(std::shared_ptr<Suggestion> suggestion);
    std::shared_ptr<Suggestion> GetSuggestion();

    nux::Property<std::string> label;
    nux::Property<std::string> hint;

  protected:
    virtual bool AcceptKeyNavFocus();
    virtual long ComputeContentSize();
    virtual void Draw(nux::GraphicsEngine& GfxContext, bool force_draw);
    virtual void DrawContent(nux::GraphicsEngine& GfxContext, bool force_draw);
    virtual void PostDraw(nux::GraphicsEngine& GfxContext, bool force_draw);

    void InitTheme ();
    void RedrawTheme ();

  private:
    std::shared_ptr<Suggestion> suggestion_;
    nux::Geometry cached_geometry_;
    bool is_focused_;
    BaseTexturePtr normal_texture_;
    BaseTexturePtr focused_texture_;
  };
}
}
#endif // FILTERBASICBUTTON_H
