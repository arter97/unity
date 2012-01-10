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
 *
 */

#include <sstream>
#include "Nux/Nux.h"
#include "Nux/VLayout.h"
#include "Nux/Button.h"
#include "Nux/TextureArea.h"
#include "Nux/WindowThread.h"
#include "NuxGraphics/GraphicsEngine.h"
#include <gtk/gtk.h>

#include "HudView.h"
#include "DashStyle.h"
#include <NuxCore/Logger.h>

namespace
{
  nux::logging::Logger logger("unity.tests.Hud");
}

class TestRunner
{
public:
  TestRunner ();
  ~TestRunner ();

  static void InitWindowThread (nux::NThread* thread, void* InitData);
  void Init ();
  nux::Layout *layout;
  unity::hud::View* hud_view_;

private:
  unity::hud::Hud hud_service_;
};

TestRunner::TestRunner ()
  : hud_service_("com.canonical.hud", "/com/canonical/hud")
{
}

TestRunner::~TestRunner ()
{
}

void TestRunner::Init ()
{
  LOG_WARNING(logger) << "test init";
  layout = new nux::VLayout();

  hud_view_ = new unity::hud::View();

  layout->AddView (hud_view_, 1, nux::MINOR_POSITION_TOP, nux::MINOR_SIZE_FULL);
  nux::GetWindowCompositor().SetKeyFocusArea(hud_view_->default_focus());

  nux::GetWindowThread()->SetLayout (layout);

  // things the controller normally does
  hud_service_.suggestion_search_finished.connect([&] (unity::hud::Hud::Suggestions suggestions) {
    hud_view_->SetSuggestions(suggestions);
  });

  hud_view_->suggestion_activated.connect([&] (unity::hud::Suggestion::Ptr suggestion) {
    hud_service_.ExecuteBySuggestion(suggestion);
  });  
  
//   hud_service_.target_icon.changed.connect([&] (std::string icon_name) {
//     hud_view_->SetIcon(icon_name);
//   });

  hud_view_->search_changed.connect([&] (std::string search_string) {
    hud_service_.GetSuggestions(search_string);
  });

  hud_view_->search_activated.connect([&] (std::string search_string) {
    hud_service_.Execute(search_string);
  });
  

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

  // no real tests right now, just make sure we don't get any criticals and such
  // waiting on nice perceptual diff support before we can build real tests
  // for views

  g_type_init ();
  gtk_init (&argc, &argv);

  nux::NuxInitialize(0);
  
  // Slightly higher as we're more likely to test things we know will fail
  nux::logging::configure_logging("unity.hud=debug");
  
  nux::logging::configure_logging(::getenv("UNITY_LOG_SEVERITY"));
  LOG_DEBUG(logger) << "starting the standalone hud";
  // The instances for the pseudo-singletons.
  unity::dash::Style dash_style;

  TestRunner *test_runner = new TestRunner ();
  wt = nux::CreateGUIThread(TEXT("Hud Prototype Test"),
                            864, 240,
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
