/*
 * Copyright 2010 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the  Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 3 along with this program.  If not, see
 * <http://www.gnu.org/licenses/>
 *
 * Authored by: Gordon Allott <gord.allott@canonical.com>
 *              Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */
#include <gtk/gtk.h>

#include "Nux/Nux.h"
#include "Nux/VLayout.h"
#include "Nux/WindowThread.h"
#include "NuxGraphics/GraphicsEngine.h"
#include <NuxCore/Logger.h>

#include "BGHash.h"
#include "FontSettings.h"
#include "DashView.h"

#define WIDTH 1054
#define HEIGHT 600

using namespace unity::dash;

class TestRunner
{
public:
  TestRunner ();
  ~TestRunner ();

  static void InitWindowThread (nux::NThread* thread, void* InitData);
  void Init ();
  nux::Layout *layout;

private:

};

TestRunner::TestRunner ()
{
}

TestRunner::~TestRunner ()
{
}

void TestRunner::Init ()
{
  layout = new nux::HLayout(NUX_TRACKER_LOCATION);

  DashView* view = new DashView();
  view->DisableBlur();
  view->SetMinMaxSize(WIDTH, HEIGHT);
  layout->AddView (view, 1, nux::MINOR_POSITION_CENTER);
  layout->SetFocused (true);
  layout->SetMinMaxSize(WIDTH, HEIGHT);

  view->AboutToShow();

  nux::GetGraphicsThread()->SetLayout (layout);
}

void TestRunner::InitWindowThread(nux::NThread* thread, void* InitData)
{
  TestRunner *self =  (TestRunner *) InitData;
  self->Init ();
}

void
ControlThread (nux::NThread* thread,
               void*         data)
{
  // sleep for 3 seconds
  nux::SleepForMilliseconds (3000);
  printf ("ControlThread successfully started\n");
}

int main(int argc, char **argv)
{
  nux::SystemThread* st = NULL;
  nux::WindowThread* wt = NULL;

  gtk_init (&argc, &argv);

  unity::BGHash bghash;
  unity::FontSettings font_settings;

  nux::NuxInitialize(0);
  nux::logging::configure_logging(::getenv("UNITY_LOG_SEVERITY"));

  TestRunner *test_runner = new TestRunner ();
  wt = nux::CreateGUIThread(TEXT("Unity Dash"),
                            WIDTH+12, HEIGHT+12,
                            0,
                            &TestRunner::InitWindowThread,
                            test_runner);

  st = nux::CreateSystemThread (NULL, ControlThread, wt);

  if (st)
    st->Start (NULL);

  wt->Run (NULL);
  delete st;
  delete wt;
  return 0;
}
