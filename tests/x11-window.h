/*
 * Copyright (C) 2011 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * Authored By:
 * Sam Spilsbury <sam.spilsbury@canonical.com>
 */

#include <transientfor.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <vector>
#include <list>
#include <string>

#ifndef _COMPIZ_X11_WINDOW_H
#define _COMPIZ_X11_WINDOW_H

class X11Window
{
  public:

    X11Window (Display *, Window id = 0);
    ~X11Window ();

    void makeTransientFor (X11Window *w);
    void setClientLeader (X11Window *w);
    void printTransients ();

    std::vector<unsigned int> transients ();

    unsigned int id () { return mXid; }

  private:

    Window mXid;
    Display *mDpy;
    bool mCreated;
};

#endif
