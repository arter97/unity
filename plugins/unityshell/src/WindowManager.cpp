// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2010 Canonical Ltd
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
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 */

#include "WindowManager.h"

static WindowManager* window_manager = NULL;

class WindowManagerDummy : public WindowManager
{
  unsigned int GetWindowActiveNumber (guint32 xid)
  {
    return 0;
  }

  bool IsScreenGrabbed()
  {
    return false;
  }

  bool IsViewPortSwitchStarted()
  {
    return false;
  }

  void ShowDesktop()
  {
    g_debug("%s", G_STRFUNC);
  }

  bool IsWindowMaximized(guint32 xid)
  {
    return false;
  }

  bool IsWindowDecorated(guint32 xid)
  {
    return true;
  }

  bool IsWindowOnCurrentDesktop(guint32 xid)
  {
    return true;
  }

  bool IsWindowObscured(guint32 xid)
  {
    return false;
  }

  bool IsWindowMapped(guint32 xid)
  {
    return true;
  }

  void Restore(guint32 xid)
  {
    g_debug("%s", G_STRFUNC);
  }

  void Minimize(guint32 xid)
  {
    g_debug("%s", G_STRFUNC);
  }

  void Close(guint32 xid)
  {
    g_debug("%s", G_STRFUNC);
  }

  void Activate(guint32 xid)
  {
    g_debug("%s", G_STRFUNC);
  }

  void Raise(guint32 xid)
  {
    g_debug("%s", G_STRFUNC);
  }

  void Lower(guint32 xid)
  {
    g_debug("%s", G_STRFUNC);
  }

  void FocusWindowGroup(std::vector<Window> windows)
  {
    g_debug("%s", G_STRFUNC);
  }

  bool ScaleWindowGroup(std::vector<Window> windows, int state, bool force)
  {
    g_debug("%s", G_STRFUNC);
    return false;
  }

  nux::Geometry GetWindowGeometry(guint xid)
  {
    int width = (guint32)xid >> 16;
    int height = (guint32)xid & 0x0000FFFF;
    return nux::Geometry(0, 0, width, height);
  }

  nux::Geometry GetScreenGeometry()
  {
    return nux::Geometry(0, 0, 1, 1);
  }

  void SetWindowIconGeometry(Window window, nux::Geometry const& geo)
  {
    g_debug("%s", G_STRFUNC);
  }

  void CheckWindowIntersections (nux::Geometry const& region, bool &active, bool &any)
  {
    active = false;
    any = false;
  }

  int WorkspaceCount ()
  {
    return 1;
  }

  void TerminateScale()
  {
    g_debug("%s", G_STRFUNC);
  }

  bool IsScaleActive()
  {
    g_debug("%s", G_STRFUNC);
    return false;
  }

  void InitiateExpo()
  {
    g_debug("%s", G_STRFUNC);
  }

  bool IsExpoActive()
  {
    g_debug("%s", G_STRFUNC);
    return false;
  }

};

WindowManager*
WindowManager::Default()
{
  if (!window_manager)
    window_manager = new WindowManagerDummy();

  return window_manager;
}

void
WindowManager::SetDefault(WindowManager* manager)
{
  window_manager = manager;
}

#define NET_WM_MOVERESIZE_MOVE 8


void
WindowManager::StartMove(guint32 xid, int x, int y)
{
  if (x < 0 || y < 0)
    return;

  XEvent ev;
  Display* d = nux::GetGraphicsDisplay()->GetX11Display();

  /* We first need to ungrab the pointer. FIXME: Evil */

  XUngrabPointer(d, CurrentTime);

  // --------------------------------------------------------------------------
  // FIXME: This is a workaround until the non-paired events issue is fixed in
  // nux
  XButtonEvent bev =
  {
    ButtonRelease,
    0,
    False,
    d,
    0,
    0,
    0,
    CurrentTime,
    x, y,
    x, y,
    0,
    Button1,
    True
  };
  XEvent* e = (XEvent*)&bev;
  nux::GetGraphicsThread()->ProcessForeignEvent(e, NULL);

  ev.xclient.type    = ClientMessage;
  ev.xclient.display = d;

  ev.xclient.serial     = 0;
  ev.xclient.send_event = true;

  ev.xclient.window     = xid;
  ev.xclient.message_type = m_MoveResizeAtom;
  ev.xclient.format     = 32;

  ev.xclient.data.l[0] = x;
  ev.xclient.data.l[1] = y;
  ev.xclient.data.l[2] = NET_WM_MOVERESIZE_MOVE;
  ev.xclient.data.l[3] = 1;
  ev.xclient.data.l[4] = 1;

  XSendEvent(d, DefaultRootWindow(d), FALSE,
             SubstructureRedirectMask | SubstructureNotifyMask,
             &ev);

  XSync(d, FALSE);
}
