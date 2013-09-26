/*
 * Copyright 2012-2013 Canonical Ltd.
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
 * Authored by: Marco Trevisan (Treviño) <3v1n0@ubuntu.com>
 *
 */

#include "test_im_text_entry.h"

namespace
{
using namespace nux;

struct TestIMTextEntry : testing::Test
{
  bool EventNativelyHandled() { return !text_entry.im_running(); }

  MockTextEntry text_entry;
};

TEST_F(TestIMTextEntry, CopyCtrlC)
{
  TestEvent event(KEY_MODIFIER_CTRL, NUX_VK_c);

  EXPECT_CALL(text_entry, CopyClipboard());
  EXPECT_EQ(EventNativelyHandled(), text_entry.InspectKeyEvent(event));
}

TEST_F(TestIMTextEntry, CopyCtrlIns)
{
  TestEvent event(KEY_MODIFIER_CTRL, NUX_VK_INSERT);

  EXPECT_CALL(text_entry, CopyClipboard());
  EXPECT_EQ(EventNativelyHandled(), text_entry.InspectKeyEvent(event));
}

TEST_F(TestIMTextEntry, PasteCtrlV)
{
  TestEvent event(KEY_MODIFIER_CTRL, NUX_VK_v);

  EXPECT_CALL(text_entry, PasteClipboard());
  EXPECT_EQ(EventNativelyHandled(), text_entry.InspectKeyEvent(event));
}

TEST_F(TestIMTextEntry, PasteShiftIns)
{
  TestEvent event(KEY_MODIFIER_SHIFT, NUX_VK_INSERT);

  EXPECT_CALL(text_entry, PasteClipboard());
  EXPECT_EQ(EventNativelyHandled(), text_entry.InspectKeyEvent(event));
}

TEST_F(TestIMTextEntry, CutCtrlX)
{
  TestEvent event(KEY_MODIFIER_CTRL, NUX_VK_x);

  EXPECT_CALL(text_entry, CutClipboard());
  EXPECT_EQ(EventNativelyHandled(), text_entry.InspectKeyEvent(event));
}

TEST_F(TestIMTextEntry, CutShiftDel)
{
  TestEvent event(KEY_MODIFIER_SHIFT, NUX_VK_DELETE);

  EXPECT_CALL(text_entry, CutClipboard());
  EXPECT_EQ(EventNativelyHandled(), text_entry.InspectKeyEvent(event));
}

TEST_F(TestIMTextEntry, CtrlMoveKeys)
{
  TestEvent left(KEY_MODIFIER_CTRL, NUX_VK_LEFT);
  EXPECT_EQ(EventNativelyHandled(), text_entry.InspectKeyEvent(left));

  TestEvent right(KEY_MODIFIER_CTRL, NUX_VK_RIGHT);
  EXPECT_TRUE(text_entry.InspectKeyEvent(right));

  TestEvent home(KEY_MODIFIER_CTRL, NUX_VK_HOME);
  EXPECT_TRUE(text_entry.InspectKeyEvent(home));

  TestEvent end(KEY_MODIFIER_CTRL, NUX_VK_END);
  EXPECT_TRUE(text_entry.InspectKeyEvent(end));
}

TEST_F(TestIMTextEntry, CtrlDeleteKeys)
{
  TestEvent del(KEY_MODIFIER_CTRL, NUX_VK_DELETE);
  EXPECT_EQ(EventNativelyHandled(), text_entry.InspectKeyEvent(del));

  TestEvent backspace(KEY_MODIFIER_CTRL, NUX_VK_BACKSPACE);
  EXPECT_TRUE(text_entry.InspectKeyEvent(backspace));
}

TEST_F(TestIMTextEntry, CtrlA)
{
  TestEvent selectall(KEY_MODIFIER_CTRL, NUX_VK_a);
  EXPECT_EQ(EventNativelyHandled(), text_entry.InspectKeyEvent(selectall));
}

struct CtrlKeybindings : TestIMTextEntry, testing::WithParamInterface<unsigned long> {};
INSTANTIATE_TEST_CASE_P(TestIMTextEntry, CtrlKeybindings, testing::Values(NUX_VK_a, NUX_VK_BACKSPACE,
                                                                          NUX_VK_LEFT, NUX_VK_RIGHT,
                                                                          NUX_VK_HOME, NUX_VK_END,
                                                                          NUX_VK_BACKSPACE, NUX_VK_DELETE));

TEST_P(/*TestIMTextEntry*/CtrlKeybindings, Handling)
{
  TestEvent event(KEY_MODIFIER_CTRL, GetParam());
  EXPECT_EQ(EventNativelyHandled(), text_entry.InspectKeyEvent(event));
}

} // anonymous namespace
