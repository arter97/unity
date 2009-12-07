/* -*- Mode: vala; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/*
 * Copyright (C) 2009 Canonical Ltd
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
 * Authored by Gordon Allott <gord.allott@canonical.com>
 *
 */

namespace Unity.Quicklauncher.Stores
{
  
  public interface LauncherStore : GLib.Object 
  {
    public abstract bool is_active {get;}
    public abstract bool is_focused {get;}
    public abstract Gdk.Pixbuf icon {get;}
    public abstract bool is_sticky {get; set;}
  
    public abstract signal void notify_active ();
    public abstract signal void notify_focused ();
    public abstract signal void request_attention ();

    public abstract void activate ();
  }

}
