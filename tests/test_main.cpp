#include <gtest/gtest.h>
#include <gio/gio.h>
#include <gtk/gtk.h>
#include <NuxCore/Logger.h>
#include <Nux/Nux.h>
#include <config.h>

#include "logger_helper.h"


const gchar* LOCAL_DATA_DIR = BUILDDIR"/tests/data:/usr/share";
const gchar* SCHEMA_DIRECTORY = BUILDDIR"/settings";

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  // init XDG_DATA_DIRS before GTK to point to the local test-dir as 
  // the environment is only read once by glib and then cached
  g_setenv("XDG_DATA_DIRS", LOCAL_DATA_DIR, TRUE);

  g_setenv("GSETTINGS_SCHEMA_DIR", SCHEMA_DIRECTORY, true);



  gtk_init(&argc, &argv);
  setlocale(LC_ALL, "C");

  nux::NuxInitialize(0);
  std::unique_ptr<nux::WindowThread> win_thread(nux::CreateNuxWindow("Tests",
                                                300, 200, nux::WINDOWSTYLE_NORMAL,
                                                NULL, false, NULL, NULL));

  // Slightly higher as we're more likely to test things we know will fail
  nux::logging::configure_logging("<root>=error");

  unity::helper::configure_logging("UNITY_TEST_LOG_SEVERITY");

  // StandaloneWindowManager brought in at link time.
  int ret = RUN_ALL_TESTS();

  return ret;
}

