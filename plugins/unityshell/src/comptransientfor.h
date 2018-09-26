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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * Authored By:
 * Sam Spilsbury <sam.spilsbury@canonical.com>
 */

#ifndef _COMPIZ_COMPIZTRANSIENTFOR_H
#define _COMPIZ_COMPIZTRANSIENTFOR_H

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <core/core.h>
#include "transientfor.h"

// Will be merged back into compiz
namespace compiz
{
class PrivateCompTransientForReader;

class CompTransientForReader :
    public X11TransientForReader
{
public:

  CompTransientForReader (CompWindow *w);
  virtual ~CompTransientForReader ();

  bool isTransientFor (unsigned int transient);
  bool isGroupTransientFor (unsigned int transient);
protected:

  unsigned int getAncestor ();

private:

  PrivateCompTransientForReader *priv;
};
}

#endif
