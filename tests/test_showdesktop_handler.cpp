#include <list>
#include <algorithm>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <UnityShowdesktopHandler.h>

using namespace unity;
using ::testing::_;
using ::testing::Return;
using ::testing::Invoke;
using ::testing::InSequence;

compiz::WindowInputRemoverInterface::~WindowInputRemoverInterface () {}

class MockWindowInputRemover :
  public compiz::WindowInputRemoverInterface
{
  public:

    MockWindowInputRemover ()
    {
      ON_CALL (*this, saveInput ()).WillByDefault (Return (true));
      ON_CALL (*this, removeInput ()).WillByDefault (Return (true));
      ON_CALL (*this, restoreInput ()).WillByDefault (Return (true));
    }

    MOCK_METHOD0 (saveInput, bool ());
    MOCK_METHOD0 (removeInput, bool ());
    MOCK_METHOD0 (restoreInput, bool ());
};

class UnityShowdesktopHandlerTest :
  public ::testing::Test
{
public:

  ~UnityShowdesktopHandlerTest ()
  {
    UnityShowdesktopHandler::animating_windows.clear ();
  }

  template <class T, class U> static typename T::Ptr makeShared () { return typename T::Ptr (new U); }

};


class MockUnityShowdesktopHandlerWindow :
  public UnityShowdesktopHandlerWindowInterface
{
  public:

    MockUnityShowdesktopHandlerWindow ()
    {
      ON_CALL (*this, IsOverrideRedirect ()).WillByDefault (Return (false));
      ON_CALL (*this, IsManaged ()).WillByDefault (Return (true));
      ON_CALL (*this, IsGrabbed ()).WillByDefault (Return (false));
      ON_CALL (*this, IsDesktopOrDock ()).WillByDefault (Return (false));
      ON_CALL (*this, IsSkipTaskbarOrPager ()).WillByDefault (Return (false));
      ON_CALL (*this, IsHidden ()).WillByDefault (Return (false));
      ON_CALL (*this, IsInShowdesktopMode ()).WillByDefault (Return (false));
      ON_CALL (*this, IsShaded ()).WillByDefault (Return (false));
      ON_CALL (*this, IsMinimized ()).WillByDefault (Return (false));

      ON_CALL (*this, DoHandleAnimations (_)).WillByDefault (Return (UnityShowdesktopHandlerWindowInterface::PostPaintAction::Damage));
      ON_CALL (*this, GetNoCoreInstanceMask ()).WillByDefault (Return (1));
      ON_CALL (*this, GetInputRemover ()).WillByDefault (Invoke (UnityShowdesktopHandlerTest::makeShared<compiz::WindowInputRemoverInterface, MockWindowInputRemover>));
    }

    MOCK_METHOD0 (DoEnableFocus, void ());
    MOCK_METHOD0 (DoDisableFocus, void ());
    MOCK_METHOD0 (IsOverrideRedirect, bool ());
    MOCK_METHOD0 (IsManaged, bool ());
    MOCK_METHOD0 (IsGrabbed, bool ());
    MOCK_METHOD0 (IsDesktopOrDock, bool ());
    MOCK_METHOD0 (IsSkipTaskbarOrPager, bool ());
    MOCK_METHOD0 (IsHidden, bool ());
    MOCK_METHOD0 (IsInShowdesktopMode, bool ());
    MOCK_METHOD0 (IsShaded, bool ());
    MOCK_METHOD0 (IsMinimized, bool ());
    MOCK_METHOD1 (DoOverrideFrameRegion, void (CompRegion &));
    MOCK_METHOD0 (DoHide, void ());
    MOCK_METHOD0 (DoNotifyHidden, void ());
    MOCK_METHOD0 (DoShow, void ());
    MOCK_METHOD0 (DoNotifyShown, void ());
    MOCK_METHOD0 (DoMoveFocusAway, void ());
    MOCK_METHOD1 (DoHandleAnimations, UnityShowdesktopHandlerWindowInterface::PostPaintAction (unsigned int));
    MOCK_METHOD0 (DoAddDamage, void ());
    MOCK_METHOD0 (GetNoCoreInstanceMask, unsigned int ());
    MOCK_METHOD0 (GetInputRemover, compiz::WindowInputRemoverInterface::Ptr ());
    MOCK_METHOD0 (DoDeleteHandler, void ());
};

TEST_F(UnityShowdesktopHandlerTest, TestNoORWindowsSD)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ());

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsOverrideRedirect ()).WillOnce (Return (true));
  EXPECT_FALSE (UnityShowdesktopHandler::ShouldHide (&mMockWindow));
}

TEST_F(UnityShowdesktopHandlerTest, TestNoUnmanagedWindowsSD)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ());

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsOverrideRedirect ());
  EXPECT_CALL (mMockWindow, IsManaged ()).WillOnce (Return (false));
  EXPECT_FALSE (UnityShowdesktopHandler::ShouldHide (&mMockWindow));
}

TEST_F(UnityShowdesktopHandlerTest, TestNoGrabbedWindowsSD)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ());

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsOverrideRedirect ());
  EXPECT_CALL (mMockWindow, IsManaged ());
  EXPECT_CALL (mMockWindow, IsGrabbed ()).WillOnce (Return (true));
  EXPECT_FALSE (UnityShowdesktopHandler::ShouldHide (&mMockWindow));
}

TEST_F(UnityShowdesktopHandlerTest, TestNoDesktopOrDockWindowsSD)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ());

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsOverrideRedirect ());
  EXPECT_CALL (mMockWindow, IsManaged ());
  EXPECT_CALL (mMockWindow, IsGrabbed ());
  EXPECT_CALL (mMockWindow, IsDesktopOrDock ()).WillOnce (Return (true));
  EXPECT_FALSE (UnityShowdesktopHandler::ShouldHide (&mMockWindow));
}

TEST_F(UnityShowdesktopHandlerTest, TestNoSkipTaskbarOrPagerWindowsSD)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ());

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsOverrideRedirect ());
  EXPECT_CALL (mMockWindow, IsManaged ());
  EXPECT_CALL (mMockWindow, IsGrabbed ());
  EXPECT_CALL (mMockWindow, IsDesktopOrDock ());
  EXPECT_CALL (mMockWindow, IsSkipTaskbarOrPager ()).WillOnce (Return (true));
  EXPECT_FALSE (UnityShowdesktopHandler::ShouldHide (&mMockWindow));
}

TEST_F(UnityShowdesktopHandlerTest, TestHiddenNotSDAndShadedWindowsNoSD)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ());

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsOverrideRedirect ());
  EXPECT_CALL (mMockWindow, IsManaged ());
  EXPECT_CALL (mMockWindow, IsGrabbed ());
  EXPECT_CALL (mMockWindow, IsDesktopOrDock ());
  EXPECT_CALL (mMockWindow, IsSkipTaskbarOrPager ());
  EXPECT_CALL (mMockWindow, IsHidden ()).WillOnce (Return (true));
  EXPECT_CALL (mMockWindow, IsInShowdesktopMode ()).WillOnce (Return (false));
  EXPECT_CALL (mMockWindow, IsShaded ()).WillOnce (Return (true));
  EXPECT_FALSE (UnityShowdesktopHandler::ShouldHide (&mMockWindow));
}

TEST_F(UnityShowdesktopHandlerTest, TestHiddenSDAndShadedWindowsNoSD)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ());

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsOverrideRedirect ());
  EXPECT_CALL (mMockWindow, IsManaged ());
  EXPECT_CALL (mMockWindow, IsGrabbed ());
  EXPECT_CALL (mMockWindow, IsDesktopOrDock ());
  EXPECT_CALL (mMockWindow, IsSkipTaskbarOrPager ());
  EXPECT_CALL (mMockWindow, IsHidden ()).WillOnce (Return (true));
  EXPECT_CALL (mMockWindow, IsInShowdesktopMode ()).WillOnce (Return (true));
  EXPECT_FALSE (UnityShowdesktopHandler::ShouldHide (&mMockWindow));
}

TEST_F(UnityShowdesktopHandlerTest, TestHiddenNotSDAndNotShadedWindowsSD)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ());

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsOverrideRedirect ());
  EXPECT_CALL (mMockWindow, IsManaged ());
  EXPECT_CALL (mMockWindow, IsGrabbed ());
  EXPECT_CALL (mMockWindow, IsDesktopOrDock ());
  EXPECT_CALL (mMockWindow, IsSkipTaskbarOrPager ());
  EXPECT_CALL (mMockWindow, IsHidden ()).WillOnce (Return (true));
  EXPECT_CALL (mMockWindow, IsInShowdesktopMode ()).WillOnce (Return (false));
  EXPECT_CALL (mMockWindow, IsShaded ()).WillOnce (Return (false));
  EXPECT_TRUE (UnityShowdesktopHandler::ShouldHide (&mMockWindow));
}

class MockWindowInputRemoverTestFadeOut :
  public compiz::WindowInputRemoverInterface
{
  public:

    MockWindowInputRemoverTestFadeOut ()
    {
      ON_CALL (*this, saveInput ()).WillByDefault (Return (true));
      ON_CALL (*this, removeInput ()).WillByDefault (Return (true));
      ON_CALL (*this, restoreInput ()).WillByDefault (Return (true));

      EXPECT_CALL (*this, saveInput ()).WillOnce (Return (true));
      EXPECT_CALL (*this, removeInput ()).WillOnce (Return (true));
    }

    MOCK_METHOD0 (saveInput, bool ());
    MOCK_METHOD0 (removeInput, bool ());
    MOCK_METHOD0 (restoreInput, bool ());
};

TEST_F(UnityShowdesktopHandlerTest, TestFadeOutHidesWindow)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ()).WillOnce (Invoke (UnityShowdesktopHandlerTest::makeShared<compiz::WindowInputRemoverInterface, MockWindowInputRemoverTestFadeOut>));

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsHidden ());
  EXPECT_CALL (mMockWindow, DoHide ());
  EXPECT_CALL (mMockWindow, DoNotifyHidden ());

  mMockHandler.FadeOut ();

  EXPECT_EQ (UnityShowdesktopHandler::animating_windows.size (), 1);
}

class MockWindowInputRemoverTestFadeOutAlready :
  public compiz::WindowInputRemoverInterface
{
  public:

    MockWindowInputRemoverTestFadeOutAlready ()
    {
      ON_CALL (*this, saveInput ()).WillByDefault (Return (true));
      ON_CALL (*this, removeInput ()).WillByDefault (Return (true));
      ON_CALL (*this, restoreInput ()).WillByDefault (Return (true));
    }

    MOCK_METHOD0 (saveInput, bool ());
    MOCK_METHOD0 (removeInput, bool ());
    MOCK_METHOD0 (restoreInput, bool ());
};

TEST_F(UnityShowdesktopHandlerTest, TestFadeOutOnHiddenDoesntHideWindow)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ()).WillOnce (Invoke (UnityShowdesktopHandlerTest::makeShared<compiz::WindowInputRemoverInterface, MockWindowInputRemoverTestFadeOutAlready>));

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsHidden ()).WillOnce (Return (true));

  mMockHandler.FadeOut ();

  EXPECT_EQ (UnityShowdesktopHandler::animating_windows.size (), 0);
}

TEST_F(UnityShowdesktopHandlerTest, TestFadeOutAlreadyFadedDoesntHideWindow)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ()).WillOnce (Invoke (UnityShowdesktopHandlerTest::makeShared<compiz::WindowInputRemoverInterface, MockWindowInputRemoverTestFadeOut>));

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsHidden ());
  EXPECT_CALL (mMockWindow, DoHide ());
  EXPECT_CALL (mMockWindow, DoNotifyHidden ());

  mMockHandler.FadeOut ();
  mMockHandler.FadeOut ();

  EXPECT_EQ (UnityShowdesktopHandler::animating_windows.size (), 1);
}

TEST_F(UnityShowdesktopHandlerTest, TestFadeInNonFadedDoesntShowWindow)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ()).WillOnce (Invoke (UnityShowdesktopHandlerTest::makeShared<compiz::WindowInputRemoverInterface, MockWindowInputRemoverTestFadeOutAlready>));

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  mMockHandler.FadeIn ();

  EXPECT_EQ (UnityShowdesktopHandler::animating_windows.size (), 0);
}

class MockWindowInputRemoverTestFadeOutFadeIn :
  public compiz::WindowInputRemoverInterface
{
  public:

    MockWindowInputRemoverTestFadeOutFadeIn ()
    {
      ON_CALL (*this, saveInput ()).WillByDefault (Return (true));
      ON_CALL (*this, removeInput ()).WillByDefault (Return (true));
      ON_CALL (*this, restoreInput ()).WillByDefault (Return (true));

      EXPECT_CALL (*this, saveInput ()).WillOnce (Return (true));
      EXPECT_CALL (*this, removeInput ()).WillOnce (Return (true));
      EXPECT_CALL (*this, restoreInput ()).WillOnce (Return (true));
    }

    MOCK_METHOD0 (saveInput, bool ());
    MOCK_METHOD0 (removeInput, bool ());
    MOCK_METHOD0 (restoreInput, bool ());
};

TEST_F(UnityShowdesktopHandlerTest, TestFadeOutHidesWindowFadeInShowsWindow)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ()).WillOnce (Invoke (UnityShowdesktopHandlerTest::makeShared<compiz::WindowInputRemoverInterface, MockWindowInputRemoverTestFadeOutFadeIn>));

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsHidden ());
  EXPECT_CALL (mMockWindow, DoHide ());
  EXPECT_CALL (mMockWindow, DoNotifyHidden ());

  mMockHandler.FadeOut ();

  EXPECT_CALL (mMockWindow, DoShow ());
  EXPECT_CALL (mMockWindow, DoNotifyShown ());

  mMockHandler.FadeIn ();

  EXPECT_EQ (UnityShowdesktopHandler::animating_windows.size (), 1);
}

TEST_F(UnityShowdesktopHandlerTest, TestAnimationPostPaintActions)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ()).WillOnce (Invoke (UnityShowdesktopHandlerTest::makeShared<compiz::WindowInputRemoverInterface, MockWindowInputRemoverTestFadeOutFadeIn>));

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsHidden ());
  EXPECT_CALL (mMockWindow, DoHide ());
  EXPECT_CALL (mMockWindow, DoNotifyHidden ());

  mMockHandler.FadeOut ();

  EXPECT_CALL (mMockWindow, DoShow ());
  EXPECT_CALL (mMockWindow, DoNotifyShown ());

  for (unsigned int i = 0; i < UnityShowdesktopHandler::fade_time; i++)
  {
    UnityShowdesktopHandlerWindowInterface::PostPaintAction action = mMockHandler.Animate (1);

    if (i == 300)
      EXPECT_EQ (action, UnityShowdesktopHandlerWindowInterface::PostPaintAction::Wait);
    else
      EXPECT_EQ (action, UnityShowdesktopHandlerWindowInterface::PostPaintAction::Damage);
  }

  mMockHandler.FadeIn ();

  for (unsigned int i = 0; i < UnityShowdesktopHandler::fade_time; i++)
  {
    UnityShowdesktopHandlerWindowInterface::PostPaintAction action = mMockHandler.Animate (1);

    if (i == 300)
      EXPECT_EQ (action, UnityShowdesktopHandlerWindowInterface::PostPaintAction::Remove);
    else
      EXPECT_EQ (action, UnityShowdesktopHandlerWindowInterface::PostPaintAction::Damage);
  }

  EXPECT_EQ (UnityShowdesktopHandler::animating_windows.size (), 1);
}

TEST_F(UnityShowdesktopHandlerTest, TestAnimationOpacity)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ()).WillOnce (Invoke (UnityShowdesktopHandlerTest::makeShared<compiz::WindowInputRemoverInterface, MockWindowInputRemoverTestFadeOutFadeIn>));

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsHidden ());
  EXPECT_CALL (mMockWindow, DoHide ());
  EXPECT_CALL (mMockWindow, DoNotifyHidden ());

  mMockHandler.FadeOut ();

  EXPECT_CALL (mMockWindow, DoShow ());
  EXPECT_CALL (mMockWindow, DoNotifyShown ());

  /* The funny expectations here are to account for rounding errors that would
   * otherwise make testing the code painful */

  for (unsigned int i = 0; i < UnityShowdesktopHandler::fade_time; i++)
  {
    unsigned short opacity = std::numeric_limits <unsigned short>::max ();
    mMockHandler.PaintOpacity (opacity);

    mMockHandler.Animate (1);

    if (i == 300)
      EXPECT_EQ (opacity, std::numeric_limits <unsigned short>::max ());
    else
    {
      float rem = opacity - std::numeric_limits <unsigned short>::max () * (1.0f - i / static_cast <float> (UnityShowdesktopHandler::fade_time));
      EXPECT_TRUE (rem <= 1.0f && rem >= -1.0f);
    }
  }

  mMockHandler.FadeIn ();

  for (unsigned int i = 0; i < UnityShowdesktopHandler::fade_time; i++)
  {
    unsigned short opacity = std::numeric_limits <unsigned short>::max ();
    mMockHandler.PaintOpacity (opacity);

    mMockHandler.Animate (1);

    if (i == 300)
      EXPECT_EQ (opacity, std::numeric_limits <unsigned short>::max ());
    else
    {
      float rem = opacity - std::numeric_limits <unsigned short>::max () * (i / static_cast <float> (UnityShowdesktopHandler::fade_time));
      EXPECT_TRUE (rem <= 1.0f && rem >= -1.0f);
    }
  }

  EXPECT_EQ (UnityShowdesktopHandler::animating_windows.size (), 1);
}

TEST_F(UnityShowdesktopHandlerTest, TestAnimationPaintMasks)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ()).WillOnce (Invoke (UnityShowdesktopHandlerTest::makeShared<compiz::WindowInputRemoverInterface, MockWindowInputRemoverTestFadeOutFadeIn>));

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsHidden ());
  EXPECT_CALL (mMockWindow, DoHide ());
  EXPECT_CALL (mMockWindow, DoNotifyHidden ());

  mMockHandler.FadeOut ();

  EXPECT_CALL (mMockWindow, DoShow ());
  EXPECT_CALL (mMockWindow, DoNotifyShown ());
  EXPECT_CALL (mMockWindow, GetNoCoreInstanceMask ());

  mMockHandler.Animate (UnityShowdesktopHandler::fade_time);

  EXPECT_EQ (mMockHandler.GetPaintMask (), 1);

  mMockHandler.FadeIn ();

  mMockHandler.Animate (UnityShowdesktopHandler::fade_time);

  EXPECT_EQ (mMockHandler.GetPaintMask (), 0);

  EXPECT_EQ (UnityShowdesktopHandler::animating_windows.size (), 1);
}

class MockWindowInputRemoverTestFadeOutFadeInWithShapeEvent :
  public compiz::WindowInputRemoverInterface
{
  public:

    MockWindowInputRemoverTestFadeOutFadeInWithShapeEvent ()
    {
      ON_CALL (*this, saveInput ()).WillByDefault (Return (true));
      ON_CALL (*this, removeInput ()).WillByDefault (Return (true));
      ON_CALL (*this, restoreInput ()).WillByDefault (Return (true));

      InSequence s;

      EXPECT_CALL (*this, saveInput ()).WillOnce (Return (true));
      EXPECT_CALL (*this, removeInput ()).WillOnce (Return (true));
      EXPECT_CALL (*this, saveInput ()).WillOnce (Return (true));
      EXPECT_CALL (*this, removeInput ()).WillOnce (Return (true));
      EXPECT_CALL (*this, restoreInput ()).WillOnce (Return (true));
    }

    MOCK_METHOD0 (saveInput, bool ());
    MOCK_METHOD0 (removeInput, bool ());
    MOCK_METHOD0 (restoreInput, bool ());
};

TEST_F(UnityShowdesktopHandlerTest, TestShapeEvent)
{
  MockUnityShowdesktopHandlerWindow mMockWindow;

  EXPECT_CALL (mMockWindow, GetInputRemover ()).WillOnce (Invoke (UnityShowdesktopHandlerTest::makeShared<compiz::WindowInputRemoverInterface, MockWindowInputRemoverTestFadeOutFadeInWithShapeEvent>));

  UnityShowdesktopHandler mMockHandler (static_cast <UnityShowdesktopHandlerWindowInterface *> (&mMockWindow));

  EXPECT_CALL (mMockWindow, IsHidden ());
  EXPECT_CALL (mMockWindow, DoHide ());
  EXPECT_CALL (mMockWindow, DoNotifyHidden ());

  mMockHandler.FadeOut ();

  EXPECT_CALL (mMockWindow, DoShow ());
  EXPECT_CALL (mMockWindow, DoNotifyShown ());

  mMockHandler.HandleShapeEvent ();

  mMockHandler.FadeIn ();

  EXPECT_EQ (UnityShowdesktopHandler::animating_windows.size (), 1);
}
