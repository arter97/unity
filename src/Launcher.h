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
#include <core/core.h>

#include <Nux/View.h>
#include <Nux/BaseWindow.h>
#include "Introspectable.h"
#include "LauncherIcon.h"
#include "LauncherDragWindow.h"
#include "NuxGraphics/IOpenGLAsmShader.h"
#include "Nux/TimerProc.h"
#include "PluginAdapter.h"

class LauncherModel;
class QuicklistView;

class Launcher : public Introspectable, public nux::View
{
public:
  typedef enum
  {
    LAUNCH_ANIMATION_NONE,
    LAUNCH_ANIMATION_PULSE,
    LAUNCH_ANIMATION_BLINK,
  } LaunchAnimation;

  typedef enum
  {
    URGENT_ANIMATION_NONE,
    URGENT_ANIMATION_PULSE,
    URGENT_ANIMATION_WIGGLE,
  } UrgentAnimation;

  Launcher(nux::BaseWindow *parent, CompScreen *screen, NUX_FILE_LINE_PROTO);
  ~Launcher();

  virtual long ProcessEvent(nux::IEvent &ievent, long TraverseInfo, long ProcessEventInfo);
  virtual void Draw(nux::GraphicsEngine& GfxContext, bool force_draw);
  virtual void DrawContent(nux::GraphicsEngine& GfxContext, bool force_draw);
  virtual void PostDraw(nux::GraphicsEngine& GfxContext, bool force_draw);

  LauncherIcon* GetActiveTooltipIcon() {return m_ActiveTooltipIcon;}
  LauncherIcon* GetActiveMenuIcon() {return m_ActiveMenuIcon;}

  void SetIconSize(int tile_size, int icon_size);

  void SetModel (LauncherModel *model);

  void SetFloating (bool floating);

  void SetAutohide (bool autohide, nux::View *show_trigger);
  bool AutohideEnabled ();

  void SetBacklightAlwaysOn (bool always_on);
  bool GetBacklightAlwaysOn ();
  
  void SetLaunchAnimation (LaunchAnimation animation);
  LaunchAnimation GetLaunchAnimation ();
  
  void SetUrgentAnimation (UrgentAnimation animation);
  UrgentAnimation GetUrgentAnimation ();
  
  nux::BaseWindow* GetParent () { return _parent; };

  virtual void RecvMouseUp(int x, int y, unsigned long button_flags, unsigned long key_flags);
  virtual void RecvMouseDown(int x, int y, unsigned long button_flags, unsigned long key_flags);
  virtual void RecvMouseDrag(int x, int y, int dx, int dy, unsigned long button_flags, unsigned long key_flags);
  virtual void RecvMouseEnter(int x, int y, unsigned long button_flags, unsigned long key_flags);
  virtual void RecvMouseLeave(int x, int y, unsigned long button_flags, unsigned long key_flags);
  virtual void RecvMouseMove(int x, int y, int dx, int dy, unsigned long button_flags, unsigned long key_flags);
  virtual void RecvMouseWheel(int x, int y, int wheel_delta, unsigned long button_flags, unsigned long key_flags);

  virtual void RecvQuicklistOpened (QuicklistView *quicklist);
  virtual void RecvQuicklistClosed (QuicklistView *quicklist);

  sigc::signal<void, LauncherIcon *, LauncherIcon *, bool> request_reorder_smart;
  sigc::signal<void, LauncherIcon *, LauncherIcon *, bool> request_reorder_before;
protected:
  // Introspectable methods
  const gchar* GetName ();
  void AddProperties (GVariantBuilder *builder);

private:
  typedef enum
  {
    ACTION_NONE,
    ACTION_DRAG_LAUNCHER,
    ACTION_DRAG_ICON,
  } LauncherActionState;

  typedef struct
  {
    LauncherIcon *icon;
    nux::Point3   render_center;
    nux::Point3   logical_center;
    float         x_rotation;
    float         y_rotation;
    float         z_rotation;
    float         alpha;
    float         backlight_intensity;
    float         glow_intensity;
    float         shimmer_progress;
    float         progress;
    float         progress_bias;
    bool          running_arrow;
    bool          running_colored;
    bool          active_arrow;
    bool          active_colored;
    bool          skip;
    bool          stick_thingy;
    int           window_indicators;
  } RenderArg;

  void OnWindowMaybeIntellihide (CompWindow *window);

  static gboolean AnimationTimeout (gpointer data);
  static gboolean OnAutohideTimeout (gpointer data);
  static gboolean StrutHack (gpointer data);
  
  void SetMousePosition (int x, int y);
  
  bool MouseBeyondDragThreshold ();

  void OnDragWindowAnimCompleted ();
  void OnTriggerMouseEnter (int x, int y, unsigned long button_flags, unsigned long key_flags);
  void OnTriggerMouseLeave (int x, int y, unsigned long button_flags, unsigned long key_flags);

  bool IconNeedsAnimation  (LauncherIcon *icon, struct timespec const &current);
  bool AnimationInProgress ();
  void SetTimeStruct       (struct timespec *timer, struct timespec *sister = 0, int sister_relation = 0);

  void EnsureHoverState ();
  void EnsureHiddenState ();
  void EnsureAnimation    ();
  void SetupAutohideTimer ();

  void CheckWindowOverLauncher ();

  float DnDStartProgress        (struct timespec const &current);
  float DnDExitProgress         (struct timespec const &current);
  float GetHoverProgress        (struct timespec const &current);
  float AutohideProgress        (struct timespec const &current);
  float DragThresholdProgress   (struct timespec const &current);
  float IconPresentProgress     (LauncherIcon *icon, struct timespec const &current);
  float IconUrgentProgress      (LauncherIcon *icon, struct timespec const &current);
  float IconShimmerProgress     (LauncherIcon *icon, struct timespec const &current);
  float IconUrgentPulseValue    (LauncherIcon *icon, struct timespec const &current);
  float IconUrgentWiggleValue   (LauncherIcon *icon, struct timespec const &current);
  float IconStartingBlinkValue  (LauncherIcon *icon, struct timespec const &current);
  float IconStartingPulseValue  (LauncherIcon *icon, struct timespec const &current);
  float IconBackgroundIntensity (LauncherIcon *icon, struct timespec const &current);
  float IconProgressBias        (LauncherIcon *icon, struct timespec const &current);
  float IconCenterTransitionProgress (LauncherIcon *icon, struct timespec const &current);

  void SetHover   ();
  void UnsetHover ();
  void SetHidden  (bool hidden);

  void SetDndDelta (float x, float y, nux::Geometry geo, struct timespec const &current);
  float  DragLimiter (float x);

  void SetupRenderArg (LauncherIcon *icon, struct timespec const &current, RenderArg &arg);
  void FillRenderArg (LauncherIcon *icon,
                      RenderArg &arg,
                      nux::Point3 &center,
                      float folding_threshold,
                      float folded_size,
                      float folded_spacing,
                      float autohide_offset,
                      float folded_z_distance,
                      float animation_neg_rads,
                      struct timespec const &current);
                      
  void RenderArgs (std::list<Launcher::RenderArg> &launcher_args,
                   nux::Geometry &box_geo);

  void DrawRenderArg (nux::GraphicsEngine& GfxContext, RenderArg const &arg, nux::Geometry geo);

  void OnIconAdded    (LauncherIcon *icon);
  void OnIconRemoved  (LauncherIcon *icon);
  void OnOrderChanged ();

  void OnIconNeedsRedraw (LauncherIcon *icon);

  void RenderIndicators (nux::GraphicsEngine& GfxContext,
                         RenderArg const &arg,
                         int running,
                         int active,
                         nux::Geometry geo);

  void RenderIcon (nux::GraphicsEngine& GfxContext,
                   RenderArg const &arg,
                   nux::IntrusiveSP<nux::IOpenGLBaseTexture> icon,
                   nux::Color bkg_color,
                   float alpha,
                   nux::Vector4 xform_coords[]);
                   
  void RenderIconToTexture (nux::GraphicsEngine& GfxContext, LauncherIcon *icon, nux::IntrusiveSP<nux::IOpenGLBaseTexture> texture);
  void RenderProgressToTexture (nux::GraphicsEngine& GfxContext, nux::IntrusiveSP<nux::IOpenGLBaseTexture> texture, float progress_fill, float bias);

  void SetIconXForm (LauncherIcon *icon, nux::Matrix4 ViewProjectionMatrix, nux::Geometry geo,
                     float x, float y, float w, float h, float z, std::string name);
  void UpdateIconXForm (std::list<Launcher::RenderArg> &args);

  LauncherIcon* MouseIconIntersection (int x, int y);
  void EventLogic ();
  void MouseDownLogic (int x, int y, unsigned long button_flags, unsigned long key_flags);
  void MouseUpLogic (int x, int y, unsigned long button_flags, unsigned long key_flags);
  
  void StartIconDrag (LauncherIcon *icon);
  void EndIconDrag ();
  void UpdateDragWindowPosition (int x, int y);

  virtual void PreLayoutManagement();
  virtual long PostLayoutManagement(long LayoutResult);
  virtual void PositionChildLayout(float offsetX, float offsetY);

  void SetOffscreenRenderTarget (nux::IntrusiveSP<nux::IOpenGLBaseTexture> texture);
  void RestoreSystemRenderTarget ();

  nux::HLayout* m_Layout;
  int m_ContentOffsetY;

  LauncherIcon* m_ActiveTooltipIcon;
  LauncherIcon* m_ActiveMenuIcon;


  QuicklistView* _active_quicklist;

  bool  _hovered;
  bool  _floating;
  bool  _autohide;
  bool  _hidden;
  bool  _mouse_inside_launcher;
  bool  _mouse_inside_trigger;
  bool  _window_over_launcher;
  bool  _render_drag_window;
  bool  _backlight_always_on;

  float _folded_angle;
  float _neg_folded_angle;
  float _folded_z_distance;
  float _launcher_top_y;
  float _launcher_bottom_y;

  LauncherActionState _launcher_action_state;
  LaunchAnimation _launch_animation;
  UrgentAnimation _urgent_animation;
  
  LauncherIcon* _icon_under_mouse;
  LauncherIcon* _icon_mouse_down;
  LauncherIcon* _drag_icon;

  int _space_between_icons;
  int _icon_size;
  int _icon_image_size;
  int _icon_image_size_delta;
  int _icon_glow_size;
  int _dnd_delta_y;
  int _dnd_delta_x;
  int _launcher_drag_delta;
  int _dnd_security;
  int _enter_y;

  nux::BaseTexture* _icon_bkg_texture;
  nux::BaseTexture* _icon_shine_texture;
  nux::BaseTexture* _icon_outline_texture;
  nux::BaseTexture* _icon_glow_texture;
  nux::BaseTexture* _progress_bar_trough;
  nux::BaseTexture* _progress_bar_fill;
  
  nux::IntrusiveSP<nux::IOpenGLBaseTexture> _offscreen_drag_texture;
  nux::IntrusiveSP<nux::IOpenGLBaseTexture> _offscreen_progress_texture;

  guint _autohide_handle;

  nux::Matrix4  _view_matrix;
  nux::Matrix4  _projection_matrix;
  nux::Point2   _mouse_position;
  nux::IntrusiveSP<nux::IOpenGLShaderProgram>    _shader_program_uv_persp_correction;
  nux::IntrusiveSP<nux::IOpenGLAsmShaderProgram> _AsmShaderProg;
  nux::BaseTexture* m_RunningIndicator;
  nux::BaseTexture* m_ActiveIndicator;
  nux::AbstractPaintLayer* m_BackgroundLayer;
  nux::BaseWindow* _parent;
  nux::View* _autohide_trigger;
  LauncherModel* _model;
  LauncherDragWindow* _drag_window;

  CompScreen* _screen;

  /* event times */
  struct timespec _enter_time;
  struct timespec _exit_time;
  struct timespec _drag_end_time;
  struct timespec _drag_start_time;
  struct timespec _drag_threshold_time;
  struct timespec _autohide_time;
};

#endif // LAUNCHER_H


