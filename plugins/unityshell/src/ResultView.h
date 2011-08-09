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

#ifndef RESULTVIEW_H
#define RESULTVIEW_H

#include <Nux/Nux.h>
#include <Nux/View.h>
#include <dee.h>

#include <UnityCore/GLibSignal.h>
#include <UnityCore/Results.h>

#include "PreviewBase.h"
#include "ResultRenderer.h"

namespace unity
{
namespace dash
{

class ResultView : public nux::View
{
public:
  typedef std::vector<Result*> ResultList;

  ResultView(NUX_FILE_LINE_DECL);
  virtual ~ResultView();

  void SetModelRenderer(ResultRenderer* renderer);

  void AddResult(Result & result);
  void RemoveResult(Result & result);

  void SetPreview (PreviewBase *preview, Result& related_result);

  nux::Property<bool> expanded;
  sigc::signal<void, std::string> UriActivated;

protected:
  virtual void Draw(nux::GraphicsEngine& GfxContext, bool force_draw);
  virtual long int ProcessEvent(nux::IEvent& ievent, long int TraverseInfo, long int ProcessEventInfo);
  virtual void DrawContent(nux::GraphicsEngine& GfxContext, bool force_draw);
  virtual long ComputeLayout2();

  // properties
  nux::Layout *preview_layout_;
  Result* preview_result_;
  ResultRenderer *renderer_;
  ResultList results_;
};

}
}

#endif //RESULTVIEW_H
