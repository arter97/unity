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
 * Authored by: Jay Taoko <jay.taoko@canonical.com>
 */

#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <sys/time.h>

#include <Nux/View.h>
#include <Nux/BaseWindow.h>
#include <Nux/TimerProc.h>
#include <NuxGraphics/IOpenGLAsmShader.h>

#include "PointerBarrier.h"
#include "AbstractIconRenderer.h"
#include "BackgroundEffectHelper.h"
#include "DNDCollectionWindow.h"
#include "DndData.h"
#include "GeisAdapter.h"
#include "Introspectable.h"
#include "LauncherOptions.h"
#include "LauncherDragWindow.h"
#include "LauncherHideMachine.h"
#include "LauncherHoverMachine.h"
#include "UBusWrapper.h"

#define ANIM_DURATION_SHORT_SHORT 100
#define ANIM_DURATION_SHORT 125
#define ANIM_DURATION       200
#define ANIM_DURATION_LONG  350

#define SUPER_TAP_DURATION  250
#define SHORTCUTS_SHOWN_DELAY  750
#define START_DRAGICON_DURATION 250
#define BEFORE_HIDE_LAUNCHER_ON_SUPER_DURATION 1000

#define IGNORE_REPEAT_SHORTCUT_DURATION  250

#define MAX_SUPERKEY_LABELS 10

class QuicklistView;

namespace unity
{
namespace launcher
{
class AbstractLauncherIcon;
class LauncherModel;

class Launcher : public unity::debug::Introspectable, public nux::View
{
  NUX_DECLARE_OBJECT_TYPE(Launcher, nux::View);
public:

  Launcher(nux::BaseWindow* parent, NUX_FILE_LINE_PROTO);
  ~Launcher();

  nux::Property<Display*> display;
  nux::Property<int> monitor;
  nux::Property<Options::Ptr> options;

  virtual void Draw(nux::GraphicsEngine& GfxContext, bool force_draw);
  virtual void DrawContent(nux::GraphicsEngine& GfxContext, bool force_draw);
  virtual void PostDraw(nux::GraphicsEngine& GfxContext, bool force_draw);

  AbstractLauncherIcon* GetSelectedMenuIcon();

  void SetIconSize(int tile_size, int icon_size);
  void SetBackgroundAlpha(float background_alpha);

  LauncherHideMachine* HideMachine() { return _hide_machine; }

  bool Hidden()
  {
    return _hidden;
  }
  bool ShowOnEdge()
  {
    return _hide_machine->GetShowOnEdge();
  }

  void SetModel(LauncherModel* model);
  LauncherModel* GetModel();

  void SetFloating(bool floating);

  void SetHideMode(LauncherHideMode hidemode);
  LauncherHideMode GetHideMode();

  void StartKeyShowLauncher();
  void EndKeyShowLauncher();

  void SetBacklightMode(BacklightMode mode);
  BacklightMode GetBacklightMode();
  bool IsBackLightModeToggles();

  void SetLaunchAnimation(LaunchAnimation animation);
  LaunchAnimation GetLaunchAnimation();

  void SetUrgentAnimation(UrgentAnimation animation);
  UrgentAnimation GetUrgentAnimation();

  void SetAutoHideAnimation(AutoHideAnimation animation);
  AutoHideAnimation GetAutoHideAnimation();

  gboolean CheckSuperShortcutPressed(Display *x_display, unsigned int key_sym, unsigned long key_code, unsigned long key_state, char* key_string);
  void SetLatestShortcut(guint64 shortcut);

  nux::BaseWindow* GetParent()
  {
    return _parent;
  };

  virtual void RecvMouseUp(int x, int y, unsigned long button_flags, unsigned long key_flags);
  virtual void RecvMouseDown(int x, int y, unsigned long button_flags, unsigned long key_flags);
  virtual void RecvMouseDrag(int x, int y, int dx, int dy, unsigned long button_flags, unsigned long key_flags);
  virtual void RecvMouseEnter(int x, int y, unsigned long button_flags, unsigned long key_flags);
  virtual void RecvMouseLeave(int x, int y, unsigned long button_flags, unsigned long key_flags);
  virtual void RecvMouseMove(int x, int y, int dx, int dy, unsigned long button_flags, unsigned long key_flags);
  virtual void RecvMouseWheel(int x, int y, int wheel_delta, unsigned long button_flags, unsigned long key_flags);
  virtual void RecvMouseDownOutsideArea(int x, int y, unsigned long button_flags, unsigned long key_flags);

  virtual void RecvKeyPressed(unsigned long    eventType  ,   /*event type*/
    unsigned long    keysym     ,   /*event keysym*/
    unsigned long    state      ,   /*event state*/
    const char*      character  ,   /*character*/
    unsigned short   keyCount       /*key repeat count*/);

  virtual void RecvQuicklistOpened(QuicklistView* quicklist);
  virtual void RecvQuicklistClosed(QuicklistView* quicklist);

  void startKeyNavMode();
  void leaveKeyNavMode(bool preserve_focus = true);

  void exitKeyNavMode();    // Connected to signal OnEndFocus

  int GetMouseX();
  int GetMouseY();

  void Resize();

  void CheckWindowOverLauncher();
  void EnableCheckWindowOverLauncher(gboolean enabled);

  sigc::signal<void, char*, AbstractLauncherIcon*> launcher_addrequest;
  sigc::signal<void, char*, AbstractLauncherIcon*, char*, char*> launcher_addrequest_special;
  sigc::signal<void, AbstractLauncherIcon*> launcher_removerequest;
  sigc::signal<void> selection_change;
  sigc::signal<void> hidden_changed;

  // Key navigation
  virtual bool InspectKeyEvent(unsigned int eventType,
                               unsigned int keysym,
                               const char* character);

  void SelectPreviousIcon();
  void SelectNextIcon();

  void KeySwitcherActivate();
  void KeySwitcherTerminate();
  bool KeySwitcherIsActive();
  void KeySwitcherNext();
  void KeySwitcherPrevious();

protected:
  // Introspectable methods
  std::string GetName() const;
  void AddProperties(GVariantBuilder* builder);

  void ProcessDndEnter();
  void ProcessDndLeave();
  void ProcessDndMove(int x, int y, std::list<char*> mimes);
  void ProcessDndDrop(int x, int y);
private:
  typedef nux::ObjectPtr<nux::BaseTexture> BaseTexturePtr;

  typedef enum
  {
    ACTION_NONE,
    ACTION_DRAG_LAUNCHER,
    ACTION_DRAG_ICON,
    ACTION_DRAG_EXTERNAL,
  } LauncherActionState;

  typedef enum
  {
    TIME_ENTER,
    TIME_LEAVE,
    TIME_DRAG_END,
    TIME_DRAG_THRESHOLD,
    TIME_AUTOHIDE,
    TIME_DRAG_EDGE_TOUCH,
    TIME_DRAG_OUT,
    TIME_TAP_SUPER,
    TIME_SUPER_PRESSED,

    TIME_LAST
  } LauncherActionTimes;

  void OnOptionsChanged(Options::Ptr options);
  void OnOptionChanged();
  void UpdateOptions(Options::Ptr options);

  void OnWindowMaybeIntellihide(guint32 xid);
  void OnWindowMaybeIntellihideDelayed(guint32 xid);
  static gboolean CheckWindowOverLauncherSync(Launcher* self);
  void OnWindowMapped(guint32 xid);
  void OnWindowUnmapped(guint32 xid);

  void OnDragStart(GeisAdapter::GeisDragData* data);
  void OnDragUpdate(GeisAdapter::GeisDragData* data);
  void OnDragFinish(GeisAdapter::GeisDragData* data);

  void OnPluginStateChanged();

  void OnViewPortSwitchStarted();
  void OnViewPortSwitchEnded();

  static gboolean AnimationTimeout(gpointer data);
  static gboolean SuperShowLauncherTimeout(gpointer data);
  static gboolean SuperHideLauncherTimeout(gpointer data);
  static gboolean SuperShowShortcutsTimeout(gpointer data);
  static gboolean StrutHack(gpointer data);
  static gboolean MoveFocusToKeyNavModeTimeout(gpointer data);
  static gboolean StartIconDragTimeout(gpointer data);
  static gboolean ResetRepeatShorcutTimeout(gpointer data);

  void SetMousePosition(int x, int y);

  void SetStateMouseOverLauncher(bool over_launcher);
  void SetStateKeyNav(bool keynav_activated);

  bool MouseBeyondDragThreshold();

  void OnDragWindowAnimCompleted();

  bool IconNeedsAnimation(AbstractLauncherIcon* icon, struct timespec const& current);
  bool IconDrawEdgeOnly(AbstractLauncherIcon* icon);
  bool AnimationInProgress();

  void SetActionState(LauncherActionState actionstate);
  LauncherActionState GetActionState();

  void EnsureAnimation();
  void EnsureScrollTimer();

  bool MouseOverTopScrollArea();
  bool MouseOverTopScrollExtrema();

  bool MouseOverBottomScrollArea();
  bool MouseOverBottomScrollExtrema();

  static gboolean OnScrollTimeout(gpointer data);
  static gboolean OnUpdateDragManagerTimeout(gpointer data);

  float DnDStartProgress(struct timespec const& current);
  float DnDExitProgress(struct timespec const& current);
  float GetHoverProgress(struct timespec const& current);
  float AutohideProgress(struct timespec const& current);
  float DragThresholdProgress(struct timespec const& current);
  float DragHideProgress(struct timespec const& current);
  float DragOutProgress(struct timespec const& current);
  float IconDesatValue(AbstractLauncherIcon* icon, struct timespec const& current);
  float IconPresentProgress(AbstractLauncherIcon* icon, struct timespec const& current);
  float IconUrgentProgress(AbstractLauncherIcon* icon, struct timespec const& current);
  float IconShimmerProgress(AbstractLauncherIcon* icon, struct timespec const& current);
  float IconUrgentPulseValue(AbstractLauncherIcon* icon, struct timespec const& current);
  float IconPulseOnceValue(AbstractLauncherIcon *icon, struct timespec const &current);
  float IconUrgentWiggleValue(AbstractLauncherIcon* icon, struct timespec const& current);
  float IconStartingBlinkValue(AbstractLauncherIcon* icon, struct timespec const& current);
  float IconStartingPulseValue(AbstractLauncherIcon* icon, struct timespec const& current);
  float IconBackgroundIntensity(AbstractLauncherIcon* icon, struct timespec const& current);
  float IconProgressBias(AbstractLauncherIcon* icon, struct timespec const& current);
  float IconDropDimValue(AbstractLauncherIcon* icon, struct timespec const& current);
  float IconCenterTransitionProgress(AbstractLauncherIcon* icon, struct timespec const& current);

  void SetHover(bool hovered);
  void SetHidden(bool hidden);

  void  SetDndDelta(float x, float y, nux::Geometry const& geo, timespec const& current);
  float DragLimiter(float x);

  void SetupRenderArg(AbstractLauncherIcon* icon, struct timespec const& current, ui::RenderArg& arg);
  void FillRenderArg(AbstractLauncherIcon* icon,
                     ui::RenderArg& arg,
                     nux::Point3& center,
                     nux::Geometry const& parent_abs_geo,
                     float folding_threshold,
                     float folded_size,
                     float folded_spacing,
                     float autohide_offset,
                     float folded_z_distance,
                     float animation_neg_rads,
                     struct timespec const& current);

  void RenderArgs(std::list<ui::RenderArg> &launcher_args,
                  nux::Geometry& box_geo, float* launcher_alpha, nux::Geometry const& parent_abs_geo);

  void OnIconAdded(AbstractLauncherIcon* icon);
  void OnIconRemoved(AbstractLauncherIcon* icon);
  void OnOrderChanged();

  void OnIconNeedsRedraw(AbstractLauncherIcon* icon);

  void OnPlaceViewHidden(GVariant* data);
  void OnPlaceViewShown(GVariant* data);

  void DesaturateIcons();
  void SaturateIcons();

  void OnBGColorChanged(GVariant *data);

  void OnLockHideChanged(GVariant *data);

  void OnActionDone(GVariant* data);

  void RenderIconToTexture(nux::GraphicsEngine& GfxContext, AbstractLauncherIcon* icon, nux::ObjectPtr<nux::IOpenGLBaseTexture> texture);

  AbstractLauncherIcon* MouseIconIntersection(int x, int y);
  void EventLogic();
  void MouseDownLogic(int x, int y, unsigned long button_flags, unsigned long key_flags);
  void MouseUpLogic(int x, int y, unsigned long button_flags, unsigned long key_flags);

  void StartIconDragRequest(int x, int y);
  void StartIconDrag(AbstractLauncherIcon* icon);
  void EndIconDrag();
  void UpdateDragWindowPosition(int x, int y);

  float GetAutohidePositionMin();
  float GetAutohidePositionMax();

  virtual void PreLayoutManagement();
  virtual long PostLayoutManagement(long LayoutResult);
  virtual void PositionChildLayout(float offsetX, float offsetY);

  void SetOffscreenRenderTarget(nux::ObjectPtr<nux::IOpenGLBaseTexture> texture);
  void RestoreSystemRenderTarget();

  gboolean TapOnSuper();

  void OnDisplayChanged(Display* display);
  void OnDNDDataCollected(const std::list<char*>& mimes);
  
  void DndReset();
  void DndHoveredIconReset();

  nux::HLayout* m_Layout;
  int m_ContentOffsetY;

  // used by keyboard/a11y-navigation
  AbstractLauncherIcon* _current_icon;
  AbstractLauncherIcon* m_ActiveTooltipIcon;
  AbstractLauncherIcon* _icon_under_mouse;
  AbstractLauncherIcon* _icon_mouse_down;
  AbstractLauncherIcon* _drag_icon;

  int           _current_icon_index;
  int           _last_icon_index;

  QuicklistView* _active_quicklist;

  bool  _hovered;
  bool  _floating;
  bool  _hidden;
  bool  _render_drag_window;
  bool  _check_window_over_launcher;

  bool          _shortcuts_shown;
  bool          _keynav_activated;
  bool          _key_switcher_activated;
  guint64       _latest_shortcut;

  BacklightMode _backlight_mode;

  float _folded_angle;
  float _neg_folded_angle;
  float _folded_z_distance;
  float _launcher_top_y;
  float _launcher_bottom_y;

  LauncherHideMode _hidemode;

  LauncherActionState _launcher_action_state;
  LaunchAnimation _launch_animation;
  UrgentAnimation _urgent_animation;
  AutoHideAnimation _autohide_animation;

  nux::ObjectPtr<nux::IOpenGLBaseTexture> _offscreen_drag_texture;

  ui::PointerBarrierWrapper::Ptr _pointer_barrier;

  int _space_between_icons;
  int _icon_size;
  int _icon_image_size;
  int _icon_image_size_delta;
  int _icon_glow_size;
  int _dnd_delta_y;
  int _dnd_delta_x;
  int _postreveal_mousemove_delta_x;
  int _postreveal_mousemove_delta_y;
  int _launcher_drag_delta;
  int _enter_y;
  int _last_button_press;
  int _drag_out_id;
  float _drag_out_delta_x;
  float _background_alpha;

  int _bfb_width;
  int _bfb_height;

  guint _autoscroll_handle;
  guint _focus_keynav_handle;
  guint _super_show_launcher_handle;
  guint _super_hide_launcher_handle;
  guint _super_show_shortcuts_handle;
  guint _start_dragicon_handle;
  guint _dnd_check_handle;
  guint _ignore_repeat_shortcut_handle;

  nux::Point2   _mouse_position;
  nux::Point2   _bfb_mouse_position;
  nux::AbstractPaintLayer* m_BackgroundLayer;
  nux::BaseWindow* _parent;
  LauncherModel* _model;
  LauncherDragWindow* _drag_window;
  LauncherHideMachine* _hide_machine;
  LauncherHoverMachine* _hover_machine;

  unity::DndData _dnd_data;
  nux::DndAction    _drag_action;
  bool              _data_checked;
  bool              _steal_drag;
  bool              _drag_edge_touching;
  AbstractLauncherIcon*     _dnd_hovered_icon;
  unity::DNDCollectionWindow* _collection_window;
  sigc::connection _on_data_collected_connection;

  Atom              _selection_atom;

  guint             _launcher_animation_timeout;

  /* gdbus */
  guint                       _dbus_owner;
  static const gchar          introspection_xml[];
  static GDBusInterfaceVTable interface_vtable;

  static void OnBusAcquired(GDBusConnection* connection, const gchar* name, gpointer user_data);
  static void OnNameAcquired(GDBusConnection* connection, const gchar* name, gpointer user_data);
  static void OnNameLost(GDBusConnection* connection, const gchar* name, gpointer user_data);
  static void handle_dbus_method_call(GDBusConnection*       connection,
                                      const gchar*           sender,
                                      const gchar*           object_path,
                                      const gchar*           interface_name,
                                      const gchar*           method_name,
                                      GVariant*              parameters,
                                      GDBusMethodInvocation* invocation,
                                      gpointer               user_data);

  struct timespec  _times[TIME_LAST];

  bool _initial_drag_animation;

  UBusManager ubus;

  nux::Color _background_color;
  BaseTexturePtr   launcher_sheen_;
  bool _dash_is_open;

  ui::AbstractIconRenderer::Ptr icon_renderer;
  BackgroundEffectHelper bg_effect_helper_;
};

}
}

#endif // LAUNCHER_H
