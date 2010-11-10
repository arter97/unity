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

#include "IndicatorObjectProxyRemote.h"

#include "IndicatorObjectEntryProxyRemote.h"

IndicatorObjectProxyRemote::IndicatorObjectProxyRemote (const char *name)
: _name (name)
{
}

IndicatorObjectProxyRemote::~IndicatorObjectProxyRemote ()
{
  std::vector<IndicatorObjectEntryProxy*>::iterator it;
  
  for (it = _entries.begin(); it != _entries.end(); it++)
  {
    IndicatorObjectEntryProxyRemote *remote = static_cast<IndicatorObjectEntryProxyRemote *> (*it);
    delete remote;
  }

  _entries.erase (_entries.begin (), _entries.end ());
}
  
std::string&
IndicatorObjectProxyRemote::GetName ()
{
  return _name;
}

std::vector<IndicatorObjectEntryProxy *>&
IndicatorObjectProxyRemote::GetEntries ()
{
  return _entries;
}


void
IndicatorObjectProxyRemote::BeginSync ()
{
  std::vector<IndicatorObjectEntryProxy*>::iterator it;
  
  for (it = _entries.begin(); it != _entries.end(); it++)
  {
    IndicatorObjectEntryProxyRemote *remote = static_cast<IndicatorObjectEntryProxyRemote *> (*it);
    remote->_dirty = true;
  }
  g_message ("%s", G_STRFUNC);
}

void
IndicatorObjectProxyRemote::AddEntry (const gchar *entry_id,
                                      const gchar *label,
                                      bool         label_sensitive,
                                      bool         label_visible,
                                      guint32      image_type,
                                      const gchar *image_data,
                                      bool         image_sensitive,
                                      bool         image_visible)
{
  g_message ("%s", G_STRFUNC);
  g_message ("\t%s %s %d %d %u %s %d %d",
             entry_id,
             label,
             label_sensitive,
             label_visible,
             image_type,
             image_type == 3 ? "Pixbuf": image_data,
             image_sensitive,
             image_visible);

  IndicatorObjectEntryProxyRemote *remote = NULL;
  std::vector<IndicatorObjectEntryProxy*>::iterator it;
  
  for (it = _entries.begin(); it != _entries.end(); it++)
  {
    IndicatorObjectEntryProxyRemote *r = static_cast<IndicatorObjectEntryProxyRemote *> (*it);
    if (r->_dirty == true)
      {
        remote = r;
        break;
      }
  }
  
  /* Create a new one */
  if (remote == NULL)
    {
      remote = new IndicatorObjectEntryProxyRemote ();
      remote->OnShowMenuRequest.connect (sigc::mem_fun (this,
                                                        &IndicatorObjectProxyRemote::OnShowMenuRequestReceived));
      g_message ("ADDED: %p", remote);
      _entries.push_back (remote);
    }

  remote->Refresh (entry_id,
                   label,
                   label_sensitive,
                   label_visible,
                   image_type,
                   image_data,
                   image_sensitive,
                   image_visible);
  if (remote->_dirty)
    remote->_dirty = false;
  else
    OnEntryAdded.emit (remote);
}

void
IndicatorObjectProxyRemote::EndSync ()
{
  g_message ("%s", G_STRFUNC);
  std::vector<IndicatorObjectEntryProxy*>::iterator it;
 
  for (it = _entries.begin(); it != _entries.end(); it++)
  {
    IndicatorObjectEntryProxyRemote *remote = static_cast<IndicatorObjectEntryProxyRemote *> (*it);
    if (remote->_dirty == true)
      {
        remote->Refresh ("",
                         "",
                         false,
                         false,
                         0,
                         "",
                         false,
                         false);
      }
  }
}

void
IndicatorObjectProxyRemote::OnShowMenuRequestReceived (const char *id,
                                                       int         x,
                                                       int         y,
                                                       guint32     timestamp)
{
  OnShowMenuRequest.emit (id, x, y, timestamp);
}
