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

#include "inputremover.h"
#include <X11/Xregion.h>
#include <cstdio>

compiz::WindowInputRemover::WindowInputRemover (Display *dpy,
                                                Window xid) :
  mDpy (dpy),
  mShapeWindow (xid),
  mShapeMask (0),
  mInputRects (NULL),
  mNInputRects (0),
  mInputRectOrdering (0),
  mBoundingRects (NULL),
  mNBoundingRects (0),
  mBoundingRectOrdering (0),
  mRemoved (false)
{
}

compiz::WindowInputRemover::~WindowInputRemover ()
{
  if (mRemoved)
    restore ();
}

void
compiz::WindowInputRemover::sendShapeNotify ()
{
  /* Send a synthetic ShapeNotify event to the root window
   * since we ignored shape events when setting visibility
   * in order to avoid cycling in the shape handling code -
   * ignore the sent shape notify event since that will
   * be send_event = true */

  XShapeEvent  xsev;
  XEvent       *xev = (XEvent *) &xsev;
  Window       rootReturn, parentReturn;
  Window       childReturn;
  Window       *children;
  int          x, y, xOffset, yOffset;
  unsigned int width, height, depth, border, nchildren;
  int          shapeEvent, shapeError, shapeMask;

  /* FIXME: roundtrip */
  XShapeQueryExtension (mDpy, &shapeEvent, &shapeError);
  shapeMask = XShapeInputSelected (mDpy, mShapeWindow);

  xev->type   = shapeEvent + ShapeNotify;
  xsev.window = mShapeWindow;

  if (!mRemoved)
  {
    /* FIXME: these roundtrips suck */
    XGetGeometry (mDpy, mShapeWindow, &rootReturn, &x, &y, &width, &height, &depth, &border);
    XQueryTree (mDpy, mShapeWindow, &rootReturn, &parentReturn, &children, &nchildren);

    /* We need to translate the co-ordinates of the origin to the
     * client window to its parent to find out the offset of its
     * position so that we can subtract that from the final bounding
     * rect of the window shape according to the Shape extension
     * specification */

    XTranslateCoordinates (mDpy, mShapeWindow, parentReturn, 0, 0, &xOffset, &yOffset, &childReturn);

    xev->type = ShapeBounding;

    /* Calculate extents of the bounding shape */
    if (!mNBoundingRects)
    {
      /* No set input shape, we must use the client geometry */
      xsev.x = x - xOffset;
      xsev.y = y - yOffset;
      xsev.width = width; 
      xsev.height = height;
      xsev.shaped = false;
    }
    else
    {
      Region      boundingRegion = XCreateRegion ();

      for (int i = 0; i < mNBoundingRects; i++)
	XUnionRectWithRegion (&(mBoundingRects[i]), boundingRegion, boundingRegion);

      xsev.x = boundingRegion->extents.x1 - xOffset;
      xsev.y = boundingRegion->extents.y1 - yOffset;
      xsev.width = boundingRegion->extents.x2 - boundingRegion->extents.x1;
      xsev.height = boundingRegion->extents.y2 - boundingRegion->extents.y1;
      xsev.shaped = true;

      XDestroyRegion (boundingRegion);
    }

    xsev.time = CurrentTime;
    XSendEvent (mDpy, DefaultRootWindow (mDpy), false, shapeMask, xev);

    xev->type = ShapeInput;

    /* Calculate extents of the bounding shape */
    if (!mNInputRects)
    {
      /* No set input shape, we must use the client geometry */
      xsev.x = x - xOffset;
      xsev.y = y - yOffset;
      xsev.width = width; 
      xsev.height = height;
      xsev.shaped = false;
    }
    else
    {
      Region      inputRegion = XCreateRegion ();

      for (int i = 0; i < mNInputRects; i++)
	XUnionRectWithRegion (&(mInputRects[i]), inputRegion, inputRegion);

      xsev.x = inputRegion->extents.x1 - xOffset;
      xsev.y = inputRegion->extents.y1 - yOffset;
      xsev.width = inputRegion->extents.x2 - inputRegion->extents.x1;
      xsev.height = inputRegion->extents.y2 - inputRegion->extents.y1;
      xsev.shaped = true;

      XDestroyRegion (inputRegion);
    }

    xsev.time = CurrentTime;
    XSendEvent (mDpy, DefaultRootWindow (mDpy), false, shapeMask, xev);

    if (children)
      XFree (children);
  }
  else
  {
    xev->type = ShapeBounding;

    xsev.x = 0;
    xsev.y = 0;
    xsev.width = 0;
    xsev.height = 0;
    xsev.shaped = true;

    xsev.time = CurrentTime;
    XSendEvent (mDpy, DefaultRootWindow (mDpy), false, shapeMask, xev);

    xev->type = ShapeInput;

    /* Both ShapeBounding and ShapeInput are null */

    xsev.time = CurrentTime;
    XSendEvent (mDpy, DefaultRootWindow (mDpy), false, shapeMask, xev);
  }
}

bool
compiz::WindowInputRemover::save ()
{
  XRectangle   *rects;
  int          count = 0, ordering;
  Window       root;
  int          x, y;
  unsigned int width, height, border, depth;

  /* FIXME: There should be a generic GetGeometry request we can
     * use here in order to avoid a round-trip */
  if (!XGetGeometry (mDpy, mShapeWindow, &root, &x, &y, &width, &height,
                     &border, &depth))
  {
    return false;
  }

  rects = XShapeGetRectangles (mDpy, mShapeWindow, ShapeInput,
                               &count, &ordering);

  /* check if the returned shape exactly matches the window shape -
   * if that is true, the window currently has no set input shape */
  if ((count == 1) &&
      (rects[0].x == -((int) border)) &&
      (rects[0].y == -((int) border)) &&
      (rects[0].width == (width + border)) &&
      (rects[0].height == (height + border)))
  {
    count = 0;
  }

  if (mInputRects)
    XFree (mInputRects);

  mInputRects = rects;
  mNInputRects = count;
  mInputRectOrdering = ordering;

  rects = XShapeGetRectangles (mDpy, mShapeWindow, ShapeBounding,
                               &count, &ordering);

  if (mBoundingRects)
    XFree (mBoundingRects);

  mBoundingRects = rects;
  mNBoundingRects = count;
  mBoundingRectOrdering = ordering;

  mShapeMask = XShapeInputSelected (mDpy, mShapeWindow);

  return true;
}

bool
compiz::WindowInputRemover::remove ()
{
  if (!mNInputRects)
    save ();

  XShapeSelectInput (mDpy, mShapeWindow, NoEventMask);

  XShapeCombineRectangles (mDpy, mShapeWindow, ShapeInput, 0, 0,
                           NULL, 0, ShapeSet, 0);
  XShapeCombineRectangles (mDpy, mShapeWindow, ShapeBounding, 0, 0,
                           NULL, 0, ShapeSet, 0);

  XShapeSelectInput (mDpy, mShapeWindow, ShapeNotify);

  sendShapeNotify ();

  mRemoved = true;
  return true;
}

bool
compiz::WindowInputRemover::restore ()
{
  if (mRemoved)
  {
    if (mNInputRects)
    {
      XShapeCombineRectangles (mDpy, mShapeWindow, ShapeInput, 0, 0,
	                       mInputRects, mNInputRects,
	                       ShapeSet, mInputRectOrdering);

    }
    else
    {
      XShapeCombineMask (mDpy, mShapeWindow, ShapeInput,
  	               0, 0, None, ShapeSet);
    }

    if (mInputRects)
      XFree (mInputRects);

    if (mNBoundingRects)
    {
      XShapeCombineRectangles (mDpy, mShapeWindow, ShapeBounding, 0, 0,
                         mBoundingRects, mNBoundingRects,
                         ShapeSet, mBoundingRectOrdering);
    }
    else
    {
      XShapeCombineMask (mDpy, mShapeWindow, ShapeBounding,
                   0, 0, None, ShapeSet);
    }

    if (mBoundingRects)
      XFree (mBoundingRects);
  }

  XShapeSelectInput (mDpy, mShapeWindow, mShapeMask);

  sendShapeNotify ();

  mRemoved = false;
  mNInputRects  = 0;
  mInputRects = NULL;
  mNBoundingRects = 0;
  mBoundingRects = NULL;
  return true;
}
