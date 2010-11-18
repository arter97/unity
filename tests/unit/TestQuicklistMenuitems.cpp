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
 * Authored by: Mirco Müller <mirco.mueller@canonical.com>
 *
 */

#include "config.h"

#include "QuicklistMenuItem.h"
#include "QuicklistMenuItemCheckmark.h"
#include "QuicklistMenuItemLabel.h"
#include "QuicklistMenuItemRadio.h"
#include "QuicklistMenuItemSeparator.h"

static void TestMenuItem          (void);
static void TestMenuItemCheckmark (void);
static void TestMenuItemLabel     (void);
static void TestMenuItemRadio     (void);
static void TestMenuItemSeparator (void);

void
TestQuicklistMenuitemsCreateSuite ()
{
#define _DOMAIN "/Unit/QuicklistMenuitems"

  g_test_add_func (_DOMAIN"/MenuItem",          TestMenuItem);
  g_test_add_func (_DOMAIN"/MenuItemCheckmark", TestMenuItemCheckmark);
  g_test_add_func (_DOMAIN"/MenuItemLabel",     TestMenuItemLabel);
  g_test_add_func (_DOMAIN"/MenuItemRadio",     TestMenuItemRadio);
  g_test_add_func (_DOMAIN"/MenuItemSeparator", TestMenuItemSeparator);
}

static void
TestMenuItem ()
{
}

static void
TestMenuItemCheckmark ()
{
}

static void
TestMenuItemLabel ()
{
}

static void
TestMenuItemRadio ()
{
}

static void
TestMenuItemSeparator ()
{
}
