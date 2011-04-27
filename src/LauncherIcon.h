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

#ifndef LAUNCHERICON_H
#define LAUNCHERICON_H

#include <Nux/Nux.h>
#include <Nux/BaseWindow.h>
#include <NuxCore/Math/MathInc.h>

#include <sigc++/trackable.h>
#include <sigc++/signal.h>
#include <sigc++/functors/ptr_fun.h>
#include <sigc++/functors/mem_fun.h>

#include <gtk/gtk.h>
#include <libdbusmenu-glib/client.h>
#include <libdbusmenu-glib/menuitem.h>

#include "Tooltip.h"
#include "QuicklistView.h"
#include "Introspectable.h"
#include "Launcher.h"
#include "LauncherEntryRemote.h"

class Launcher;
class QuicklistView;

class LauncherIcon : public Introspectable, public nux::InitiallyUnownedObject
{
  NUX_DECLARE_OBJECT_TYPE (LauncherIcon, nux::InitiallyUnownedObject);
public:
    typedef enum
    {
      TYPE_NONE,
      TYPE_BEGIN,
      TYPE_FAVORITE,
      TYPE_APPLICATION,
      TYPE_EXPO,
      TYPE_PLACE,
      TYPE_DEVICE,
      TYPE_TRASH,
      TYPE_END,
    } IconType;

    typedef enum
    {
      QUIRK_VISIBLE,
      QUIRK_ACTIVE,
      QUIRK_RUNNING,
      QUIRK_URGENT,
      QUIRK_PRESENTED,
      QUIRK_STARTING,
      QUIRK_SHIMMER,
      QUIRK_CENTER_SAVED,
      QUIRK_PROGRESS,
      QUIRK_DROP_PRELIGHT,
      QUIRK_DROP_DIM,
      QUIRK_DESAT,
      
      QUIRK_LAST,
    } Quirk;

    LauncherIcon(Launcher* launcher);
    virtual ~LauncherIcon();

    Launcher* GetLauncher () {return _launcher;};

    void SetTooltipText (const TCHAR* text);
    
    nux::NString GetTooltipText ();
    
    void    SetShortcut (guint64 shortcut);
    guint64 GetShortcut ();
    void SetSortPriority (int priority);
    
    void RecvMouseEnter ();
    void RecvMouseLeave ();
    void RecvMouseDown (int button);
    void RecvMouseUp (int button);
    void RecvMouseClick (int button);
    
    void HideTooltip ();
    gboolean OpenQuicklist (bool default_to_first_item = false);

    void        SetCenter (nux::Point3 center);
    nux::Point3 GetCenter ();

    void Activate ();
    void OpenInstance ();

    void SaveCenter ();
    
    int SortPriority ();
    
    int RelatedWindows ();
    
    bool HasVisibleWindow ();
    
    virtual bool IsSpacer () { return false; };
    
    float PresentUrgency ();
    
    float GetProgress ();
    
    void SetEmblemIconName (const char *name);
    void SetEmblemText (const char *text);
    
    void DeleteEmblem ();
    
    bool GetQuirk (Quirk quirk);
    struct timespec GetQuirkTime (Quirk quirk);
    
    IconType Type ();
    
    virtual nux::Color BackgroundColor ();
    virtual nux::Color GlowColor ();
    
    const gchar * RemoteUri () { return GetRemoteUri (); }
    
    nux::BaseTexture * TextureForSize (int size);
    
    nux::BaseTexture * Emblem ();
    
    std::list<DbusmenuMenuitem *> Menus ();
    
    void InsertEntryRemote (LauncherEntryRemote *remote);
    void RemoveEntryRemote (LauncherEntryRemote *remote);
    
    nux::DndAction QueryAcceptDrop (std::list<char *> paths) { return OnQueryAcceptDrop (paths); }
    void AcceptDrop (std::list<char *> paths) { return OnAcceptDrop (paths); }
    void SendDndEnter () { OnDndEnter (); }
    void SendDndLeave () { OnDndLeave (); }
    
    sigc::signal<void, int> MouseDown;
    sigc::signal<void, int> MouseUp;
    sigc::signal<void>      MouseEnter;
    sigc::signal<void>      MouseLeave;
    sigc::signal<void, int> MouseClick;
    
    sigc::signal<void, LauncherIcon *> show;
    sigc::signal<void, LauncherIcon *> hide;
    sigc::signal<void, LauncherIcon *> remove;
    sigc::signal<void, LauncherIcon *> needs_redraw;

    sigc::connection needs_redraw_connection;
    sigc::connection on_icon_added_connection;
    sigc::connection on_icon_removed_connection;
    sigc::connection on_order_changed_connection;

protected:
    const gchar * GetName ();
    void AddProperties (GVariantBuilder *builder);

    void SetQuirk (Quirk quirk, bool value);

    void UpdateQuirkTimeDelayed (guint ms, Quirk quirk);
    void UpdateQuirkTime (Quirk quirk);
    void ResetQuirkTime (Quirk quirk);

    void SetRelatedWindows (int windows);
    void Remove ();
    
    void SetProgress (float progress);
    
    void SetHasVisibleWindow (bool val);
    
    void Present (float urgency, int length);
    void Unpresent ();
    
    void SetIconType (IconType type);

    void SetEmblem (nux::BaseTexture *emblem);
    void SetSuperkeyLabel (nux::BaseTexture* label);
    nux::BaseTexture* GetSuperkeyLabel ();

    virtual std::list<DbusmenuMenuitem *> GetMenus ();
    virtual nux::BaseTexture * GetTextureForSize (int size) = 0;
    
    virtual void OnCenterStabilized (nux::Point3 center) {}
    
    virtual const gchar * GetRemoteUri () { return 0; }
    
    virtual nux::DndAction OnQueryAcceptDrop (std::list<char *> files) { return nux::DNDACTION_NONE; }
    virtual void OnAcceptDrop (std::list<char *> files) {}
    virtual void OnDndEnter () {}
    virtual void OnDndLeave () {}
    
    virtual void ActivateLauncherIcon () {}
    virtual void OpenInstanceLauncherIcon () {}

    nux::BaseTexture * TextureFromGtkTheme         (const char *name, int size, bool update_glow_colors = true);
    nux::BaseTexture * TextureFromSpecificGtkTheme (GtkIconTheme *theme, const char *name, int size, bool update_glow_colors = true, bool is_default_theme=false);
    nux::BaseTexture * TextureFromPath             (const char *name, int size, bool update_glow_colors = true);
    static bool        IsMonoDefaultTheme          ();
    GtkIconTheme     * GetUnityTheme               ();

    void OnRemoteEmblemChanged    (LauncherEntryRemote *remote);
    void OnRemoteCountChanged     (LauncherEntryRemote *remote);
    void OnRemoteProgressChanged  (LauncherEntryRemote *remote);
    void OnRemoteQuicklistChanged (LauncherEntryRemote *remote);
    
    void OnRemoteUrgentChanged (LauncherEntryRemote *remote);

    void OnRemoteEmblemVisibleChanged   (LauncherEntryRemote *remote);
    void OnRemoteCountVisibleChanged    (LauncherEntryRemote *remote);
    void OnRemoteProgressVisibleChanged (LauncherEntryRemote *remote);

    nux::NString m_TooltipText;
    //! the window this icon belong too.
    nux::BaseWindow* m_Window;
    Launcher* _launcher;

    std::map<std::string, nux::Vector4*> _xform_coords;
    bool          _mouse_inside;
    float         _folding_angle;

    nux::Tooltip *_tooltip;
    QuicklistView *_quicklist;

    static nux::Tooltip *_current_tooltip;
    static QuicklistView *_current_quicklist;
    
    static int _current_theme_is_mono;

    DbusmenuClient *_menuclient_dynamic_quicklist;

    friend class Launcher;
    friend class LauncherController;
    friend class LauncherModel;

private:
    typedef struct
    {
      LauncherIcon *self;
      Quirk quirk;
    } DelayedUpdateArg;

    static void ChildRealized (DbusmenuMenuitem *newitem, QuicklistView *quicklist);
    static void RootChanged (DbusmenuClient * client, DbusmenuMenuitem *newroot, QuicklistView *quicklist);
    static gboolean OnPresentTimeout (gpointer data);
    static gboolean OnCenterTimeout (gpointer data);
    static gboolean OnDelayedUpdateTimeout (gpointer data);

    void ColorForIcon (GdkPixbuf *pixbuf, nux::Color &background, nux::Color &glow);

    nux::Color       _background_color;
    nux::Color       _glow_color;
    int              _sort_priority;
    int              _related_windows;
    float            _present_urgency;
    float            _progress;
    guint            _present_time_handle;
    guint            _center_stabilize_handle;
    guint            _time_delay_handle;
    bool             _quicklist_is_initialized;
    bool             _has_visible_window;
    bool             _remote_urgent;
    
    gint64           _shortcut;
    
    nux::Point3      _center;
    nux::Point3      _last_stable;
    nux::Point3      _saved_center;
    IconType         _icon_type;
    
    static GtkIconTheme *_unity_theme;
    
    nux::BaseTexture* _emblem;
    nux::BaseTexture* _superkey_label;
    
    bool             _quirks[QUIRK_LAST];
    struct timespec  _quirk_times[QUIRK_LAST];
    
    std::list<LauncherEntryRemote *> _entry_list;
    
};

#endif // LAUNCHERICON_H

