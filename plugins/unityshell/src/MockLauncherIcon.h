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
 * Authored by: Jason Smith <jason.smith@canonical.com>
 * 
 */

#ifndef MOCKLAUNCHERICON_H
#define MOCKLAUNCHERICON_H

#include <Nux/Nux.h>
#include <NuxCore/Math/MathInc.h>

#include <Nux/BaseWindow.h>
#include <Nux/View.h>

#include <sigc++/sigc++.h>

#include <libdbusmenu-glib/menuitem.h>

#include "AbstractLauncherIcon.h"

class MockLauncherIcon : public AbstractLauncherIcon
{
public:
  MockLauncherIcon ()
  : icon_ (0)
  {}

  void HideTooltip () {}

  void SetTooltipText (std::string) {}
  
  std::string GetTooltipText () { return std::string (); }
  
  void    SetShortcut (guint64 shortcut) {}
  
  guint64 GetShortcut () { return 0; }
  
  void SetSortPriority (int priority) {}

  bool OpenQuicklist (bool default_to_first_item = false) { return false; }

  void        SetCenter (nux::Point3 center) {}

  nux::Point3 GetCenter () { return nux::Point3 (); }

  std::vector<nux::Vector4> & GetTransform (std::string name)
  {
    if (transform_map.find (name) == transform_map.end ())
      transform_map[name] = std::vector<nux::Vector4> (4);

    return transform_map[name];
  }

  void Activate (ActionArg arg) {}
  
  void OpenInstance (ActionArg arg) {}

  int SortPriority () { return 0; }
  
  int RelatedWindows () { return 0; }
  
  bool HasWindowOnViewport () { return false; }
  
  bool IsSpacer () { return false; }
  
  float PresentUrgency () { return 0.0f; }

  float GetProgress () { return 0.0f; }
  
  bool ShowInSwitcher () { return true; }

  unsigned int SwitcherPriority () { return 0; }
  
  bool GetQuirk (Quirk quirk) { return false; }

  void SetQuirk (Quirk quirk, bool value) {}

  struct timespec GetQuirkTime (Quirk quirk) { timespec tv; return tv; }
  
  IconType Type () { return TYPE_APPLICATION; }
  
  nux::Color BackgroundColor () { return nux::Color (0xFFAAAAAA); }

  nux::Color GlowColor () { return nux::Color (0xFFAAAAAA); }
  
  const gchar * RemoteUri () { return "fake"; }
  
  nux::BaseTexture * TextureForSize (int size)
  {
    if (icon_ && size == icon_->GetHeight ())
      return icon_;
      
    if (icon_)
      icon_->UnReference ();
    icon_ = 0;
    
    icon_ = TextureFromGtkTheme ("firefox", size);
    return icon_;  
  }

  nux::BaseTexture * Emblem () { return 0; }

  std::list<DbusmenuMenuitem *> Menus () { return std::list<DbusmenuMenuitem *> (); }

  nux::DndAction QueryAcceptDrop (std::list<char *> paths) { return nux::DNDACTION_NONE; }

  void AcceptDrop (std::list<char *> paths) {}

  void SendDndEnter () {}

  void SendDndLeave () {}

private:
  nux::BaseTexture * TextureFromGtkTheme (const char *icon_name, int size)
  {
    GdkPixbuf *pbuf;
    GtkIconInfo *info;  
    nux::BaseTexture *result = NULL;
    GError *error = NULL;
    GIcon *icon;

    GtkIconTheme *theme = gtk_icon_theme_get_default ();
    
    icon = g_icon_new_for_string (icon_name, NULL);

    if (G_IS_ICON (icon))
    {
      info = gtk_icon_theme_lookup_by_gicon (theme, icon, size, (GtkIconLookupFlags)0);
      g_object_unref (icon);
    }
    else
    {   
      info = gtk_icon_theme_lookup_icon (theme,
                                         icon_name,
                                         size,
                                         (GtkIconLookupFlags) 0);
    }
    
    if (!info)
      return NULL;
    
    pbuf = gtk_icon_info_load_icon (info, &error);
    gtk_icon_info_free (info);

    if (GDK_IS_PIXBUF (pbuf))
    {
      result = nux::CreateTexture2DFromPixbuf (pbuf, true);
      g_object_unref (pbuf);
    }
    else
    {
      g_warning ("Unable to load '%s' from icon theme: %s",
                 icon_name,
                 error ? error->message : "unknown");
      g_error_free (error);
    }
    
    return result;
  }


  std::map<std::string, std::vector<nux::Vector4> > transform_map;
  nux::BaseTexture * icon_;

};

#endif // MOCKLAUNCHERICON_H

