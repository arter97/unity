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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

namespace Utils
{
  [CCode (lower_case_prefix = "utils_")]
    public extern void set_strut (Gtk.Window *window,
                                  uint32      strut_size,
                                  uint32      strut_start,
                                  uint32      strut_end,
                                  uint32      top_size,
                                  uint32      top_start,
                                  uint32      top_end);
}
