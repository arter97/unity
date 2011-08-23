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

#include "transientfor.h"

Atom compiz::X11TransientForReader::wmTransientFor = None;
Atom compiz::X11TransientForReader::wmClientLeader = None;

namespace compiz
{
class PrivateX11TransientForReader
{
public:

  PrivateX11TransientForReader () {};

  Window  mXid;
  Display *mDpy;
};
}

unsigned int
compiz::X11TransientForReader::getAncestor ()
{
  Window        serverAncestor = None;
  unsigned long nItems, nLeft;
  int           actualFormat;
  Atom          actualType;
  unsigned char *prop;

  if (XGetWindowProperty (priv->mDpy, priv->mXid, wmTransientFor, 0L, 2L, false,
                          XA_WINDOW, &actualType, &actualFormat, &nItems, &nLeft, &prop))
  {
    if (actualType == XA_WINDOW && actualFormat == 32 && nLeft == 0 && nItems == 1)
    {
	    Window *data = (Window *) prop;

	    serverAncestor = *data;
    }

    XFree (prop);
  }

  return serverAncestor;
}

bool
compiz::X11TransientForReader::isTransientFor (unsigned int ancestor)
{
  return ancestor == getAncestor ();
}

bool
compiz::X11TransientForReader::isGroupTransientFor (unsigned int clientLeader)
{
  Window        serverClientLeader = None;
  Window        ancestor           = getAncestor ();
  unsigned long nItems, nLeft;
  int           actualFormat;
  Atom          actualType;
  unsigned char *prop;
  std::vector<std::string> strings;
  std::list<Atom>   atoms;

  if (XGetWindowProperty (priv->mDpy, priv->mXid, wmClientLeader, 0L, 2L, false,
                          XA_WINDOW, &actualType, &actualFormat, &nItems, &nLeft, &prop))
  {
    if (actualType == XA_WINDOW && actualFormat == 32 && nLeft == 0 && nItems == 1)
    {
	    Window *data = (Window *) prop;

	    serverClientLeader = *data;
    }

    XFree (prop);
  }

  /* Check if the returned client leader matches
     * the requested one */
  if (serverClientLeader == clientLeader)
  {
    if (ancestor == None || ancestor == DefaultRootWindow (priv->mDpy))
    {
	    Atom wmWindowType = XInternAtom (priv->mDpy, "_NET_WM_WINDOW_TYPE", 0);

	    /* We need to get some common type strings */
	    strings.push_back ("_NET_WM_WINDOW_TYPE_UTILITY");
	    strings.push_back ("_NET_WM_WINDOW_TYPE_TOOLBAR");
	    strings.push_back ("_NET_WM_WINDOW_TYPE_MENU");
	    strings.push_back ("_NET_WM_WINDOW_TYPE_DIALOG");

	    foreach (std::string &s, strings)
	    {
        atoms.push_back (XInternAtom (priv->mDpy, s.c_str (), 0));
	    }

	    const unsigned int atomsSize = atoms.size ();

	    /* Now get the window type and check to see if this is a type that we
      * should consider to be part of a window group by this client leader */

	    if (XGetWindowProperty (priv->mDpy, priv->mXid, wmWindowType, 0L, 15L, false,
                              XA_ATOM, &actualType, &actualFormat, &nItems, &nLeft, &prop))
	    {
        if (actualType == XA_ATOM && actualFormat == 32 && nLeft == 32 && nItems)
        {
          Atom *data = (Atom *) prop;

          while (nItems--)
            atoms.remove (*data++);
        }
	    }

	    /* Means something was found */
	    if (atomsSize != atoms.size ())
        return true;
    }
  }

  return false;
}

compiz::X11TransientForReader::X11TransientForReader (Display *dpy, Window xid)
{
  priv = new PrivateX11TransientForReader ();

  priv->mXid = xid;
  priv->mDpy = dpy;

  if (!wmTransientFor)
    wmTransientFor = XInternAtom (dpy, "WM_TRANSIENT_FOR", 0);
  if (!wmClientLeader)
    wmClientLeader = XInternAtom (dpy, "WM_CLIENT_LEADER", 0);
}

compiz::X11TransientForReader::~X11TransientForReader ()
{
  delete priv;
}
