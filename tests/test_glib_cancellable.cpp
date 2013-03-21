// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2013 Canonical Ltd
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
 * Authored by: Marco Trevisan <marco.trevisan@canonical.com>
 */

#include <gmock/gmock.h>
#include <UnityCore/GLibWrapper.h>

using namespace unity::glib;

namespace
{

TEST(TestGLibCancellable, Construction)
{
  Cancellable cancellable;
  Error error;
  ASSERT_TRUE(cancellable.Get().IsType(G_TYPE_CANCELLABLE));
  EXPECT_FALSE(cancellable.IsCancelled());
  EXPECT_FALSE(cancellable.IsCancelled(error));
}

TEST(TestGLibCancellable, Destruction)
{
  Object<GCancellable> canc_obj;
  {
    Cancellable cancellable;
    canc_obj = cancellable.Get();
  }

  EXPECT_TRUE(g_cancellable_is_cancelled(canc_obj));
}

TEST(TestGLibCancellable, Cancel)
{
  Cancellable cancellable;

  cancellable.Cancel();
  EXPECT_TRUE(cancellable.IsCancelled());
}

TEST(TestGLibCancellable, CancelWithError)
{
  Cancellable cancellable;
  Error error;

  cancellable.Cancel();
  EXPECT_TRUE(cancellable.IsCancelled(error));
  EXPECT_FALSE(error.Message().empty());
}

TEST(TestGLibCancellable, Reset)
{
  Cancellable cancellable;

  cancellable.Cancel();
  ASSERT_TRUE(cancellable.IsCancelled());

  cancellable.Reset();
  EXPECT_FALSE(cancellable.IsCancelled());
}

TEST(TestGLibCancellable, OperatorGCancellable)
{
  Cancellable cancellable;

  EXPECT_EQ(g_cancellable_is_cancelled(cancellable), cancellable.IsCancelled());

  g_cancellable_cancel(cancellable);
  EXPECT_EQ(g_cancellable_is_cancelled(cancellable), cancellable.IsCancelled());
}

TEST(TestGLibCancellable, CopyConstructor)
{
  Cancellable cancellable1;
  auto obj1 = cancellable1.Get();

  Cancellable cancellable2(cancellable1);
  auto obj2 = cancellable2.Get();

  Cancellable cancellable3 = cancellable2;
  auto obj3 = cancellable2.Get();

  EXPECT_EQ(obj1, obj2);
  EXPECT_EQ(obj1, obj3);
}

TEST(TestGLibCancellable, Assignment)
{
  Cancellable cancellable1;
  auto obj1 = cancellable1.Get();

  Cancellable cancellable2;
  auto tmp_obj = cancellable2.Get();

  cancellable2 = cancellable1;
  auto obj2 = cancellable2.Get();

  EXPECT_TRUE(g_cancellable_is_cancelled(tmp_obj));
  ASSERT_EQ(obj1, obj2);

  cancellable2 = cancellable1;
  EXPECT_FALSE(obj1.IsCancelled());
}

} // Namespace
