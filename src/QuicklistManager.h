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
 */

#ifndef QUICKLISTMANAGER_H
#define QUICKLISTMANAGER_H

#include "QuicklistView.h"

class QuicklistManager
{
public:
  QuicklistManager ();

  ~QuicklistManager ();

  QuicklistManager * Default ();
  QuicklistView * Current ();

  void RegisterQuicklist (QuicklistView *quicklist);
  void ShowQuicklist (QuicklistView *quicklist, int tip_x, int tip_y, bool hide_existing_if_open = true);
  void HideQuicklist (QuicklistView *quicklist);

  sigc::signal<void, QuicklistView*> quicklist_opened;
  sigc::signal<void, QuicklistView*> quicklist_closed;

private:
  std::list<QuicklistView*> _quicklist_list;
  QuicklistView *_current_quicklist;

};

#endif

