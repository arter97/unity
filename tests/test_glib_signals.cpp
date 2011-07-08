#include <UnityCore/UnityCore.h>
#include <gtest/gtest.h>

#include "test_glib_signals_utils.h"

using namespace std;
using namespace unity;
using namespace unity::glib;

namespace {

class TestGLibSignals : public testing::Test
{
public:
  TestGLibSignals()
    : signal1_emitted_(false)
  {
    test_signals_ = static_cast<TestSignals*>(g_object_new(TEST_TYPE_SIGNALS, NULL));
  }

  virtual ~TestGLibSignals()
  {
    if (G_IS_OBJECT(test_signals_))
      g_object_unref(test_signals_);
  }

  void Signal1Callback(const char *str)
  {
    signal1_emitted_ = true;
  }

protected:
  TestSignals* test_signals_;

  bool signal1_emitted_;
};


TEST_F(TestGLibSignals, TestConstructions)
{
  SignalBase base;

  Signal0<void> signal0;
  Signal1<void, string> signal1;
  Signal2<void, string, int> signal2;
  Signal3<void, string, int, float> signal3;
  Signal4<void, string, int, float, double> signal4;
  Signal5<void, string, int, float, double, bool> signal5;
  Signal6<bool, string, int, float, double, bool, char> signal6;
  Signal7<bool, string, int, float, double, bool, char, unsigned int> signal7;

  Signal<void> signal00;
  Signal<void, string> signal01;
  Signal<void, string, int> signal02;
  Signal<void, string, int, float> signal03;
  Signal<void, string, int, float, double> signal04;
  Signal<void, string, int, float, double, bool> signal05;
  Signal<bool, string, int, float, double, bool, char> signal06;
  Signal<bool, string, int, float, double, bool, char, unsigned int> signal07;
}

TEST_F(TestGLibSignals, TestConnections)
{

}

TEST_F(TestGLibSignals, TestEmission)
{
  /*
  signal1.Connect(test_signals_, "signal-1",
                  sigc::mem_fun(this, &TestGLibSignals::Signal1Callback));
  g_signal_emit_by_name(test_signals_, "signal-1", "hello");
  EXPECT_TRUE(signal1_emitted_);
  */
}

TEST_F(TestGLibSignals, TestEmissionAfter)
{

}

TEST_F(TestGLibSignals, TestDisconnection)
{

}

TEST_F(TestGLibSignals, TestAutoDisconnection)
{

}

TEST_F(TestGLibSignals, TestAccumulation)
{

}

/*
TEST(TestIndicatorEntry, TestConstruction) {

  indicator::Entry entry("id", "label", true, true,
                         1, "some icon", false, true);

  EXPECT_EQ(entry.id(), "id");
  EXPECT_EQ(entry.label(), "label");
  EXPECT_TRUE(entry.label_sensitive());
  EXPECT_TRUE(entry.label_visible());
  EXPECT_FALSE(entry.image_sensitive());
  EXPECT_TRUE(entry.image_visible());
  EXPECT_FALSE(entry.active());
  EXPECT_FALSE(entry.show_now());
  EXPECT_FALSE(entry.IsUnused());
  EXPECT_EQ(entry.image_type(), 1);
  EXPECT_EQ(entry.image_data(), "some icon");
}
*/

}
