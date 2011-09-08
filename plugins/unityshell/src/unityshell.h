// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/* Compiz unity plugin
 * unity.h
 *
 * Copyright (c) 2010-11 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Your own copyright notice would go above. You are free to choose whatever
 * licence you want, just take note that some compiz code is GPL and you will
 * not be able to re-use it if you want to use a different licence.
 */

#ifndef UNITYSHELL_H
#define UNITYSHELL_H

#include <core/core.h>
#include <core/pluginclasshandler.h>
#include <composite/composite.h>
#include <opengl/opengl.h>

#include "unityshell_options.h"

#include "Introspectable.h"
#include "DashController.h"
#include "FontSettings.h"
#include "Launcher.h"
#include "LauncherController.h"
#include "PanelController.h"
#include "PlacesStyle.h"
#include "UScreen.h"
#include "GestureEngine.h"
#include "DebugDBusInterface.h"
#include "SwitcherController.h"
#include "UBusWrapper.h"
#include <Nux/WindowThread.h>
#include <sigc++/sigc++.h>
#include <boost/shared_ptr.hpp>

#include "compizminimizedwindowhandler.h"

class UnityFBO
{
public:

  typedef boost::shared_ptr <UnityFBO> Ptr;

  UnityFBO (CompOutput *o);
  ~UnityFBO ();

public:

  void bind ();
  void unbind ();

  bool status ();
  void paint ();

  GLuint texture () { return mFBTexture; }

private:

  /* compiz fbo handle that goes through to nux */
  GLuint   mFboHandle; // actual handle to the framebuffer_ext
  bool    mFboStatus; // did the framebuffer texture bind succeed
  GLuint   mFBTexture;
  CompOutput *output;
};

class UnityShowdesktopHandler
{
public:

  UnityShowdesktopHandler (CompWindow *w);
  ~UnityShowdesktopHandler ();

  typedef enum {
    Visible = 0,
    FadeOut = 1,
    FadeIn = 2,
    Invisible = 3
  } State;

public:

  void fadeOut ();
  void fadeIn ();
  bool animate (unsigned int ms);
  void paintAttrib (GLWindowPaintAttrib &attrib);

  UnityShowdesktopHandler::State state ();

  static const unsigned int fade_time;
  static CompWindowList     animating_windows;
  static bool shouldHide (CompWindow *);

private:

  CompWindow                     *mWindow;
  compiz::WindowInputRemover     *mRemover;
  UnityShowdesktopHandler::State mState;
  float                          mProgress;
};
  


#include "BGHash.h"
#include "DesktopLauncherIcon.h"

#include <compiztoolbox/compiztoolbox.h>

using unity::FontSettings;
using unity::PlacesStyle;
using namespace unity::switcher;
using namespace unity::dash;
using unity::UBusManager;

/* base screen class */
class UnityScreen :
  public unity::Introspectable,
  public sigc::trackable,
  public ScreenInterface,
  public CompositeScreenInterface,
  public GLScreenInterface,
  public BaseSwitchScreen,
  public PluginClassHandler <UnityScreen, CompScreen>,
  public UnityshellOptions
{
public:
  UnityScreen(CompScreen* s);
  ~UnityScreen();

  /* We store these  to avoid unecessary calls to ::get */
  CompScreen* screen;
  CompositeScreen* cScreen;
  GLScreen* gScreen;

  /* prepares nux for drawing */
  void nuxPrologue();
  /* pops nux draw stack */
  void nuxEpilogue();

  /* nux draw wrapper */
  void paintDisplay(const CompRegion& region, const GLMatrix& transform, unsigned int mask);
  void paintPanelShadow(const GLMatrix& matrix);

  void preparePaint (int ms);
  void paintFboForOutput (CompOutput *output);

  void
  handleCompizEvent (const char         *pluginName,
                     const char         *eventName,
                     CompOption::Vector &o);


  /* paint on top of all windows if we could not find a window
   * to paint underneath */
  bool glPaintOutput(const GLScreenPaintAttrib&,
                     const GLMatrix&,
                     const CompRegion&,
                     CompOutput*,
                     unsigned int);

  /* paint in the special case that the output is transformed */
  void glPaintTransformedOutput(const GLScreenPaintAttrib&,
                                const GLMatrix&,
                                const CompRegion&,
                                CompOutput*,
                                unsigned int);

  /* Pop our InputOutput windows from the paint list */
  const CompWindowList& getWindowPaintList();

  /* handle X11 events */
  void handleEvent(XEvent*);

  /* handle showdesktop */
  void enterShowDesktopMode ();
  void leaveShowDesktopMode (CompWindow *w);

  bool showLauncherKeyInitiate(CompAction* action, CompAction::State state, CompOption::Vector& options);
  bool showLauncherKeyTerminate(CompAction* action, CompAction::State state, CompOption::Vector& options);
  bool showPanelFirstMenuKeyInitiate(CompAction* action, CompAction::State state, CompOption::Vector& options);
  bool showPanelFirstMenuKeyTerminate(CompAction* action, CompAction::State state, CompOption::Vector& options);

  bool executeCommand(CompAction* action, CompAction::State state, CompOption::Vector& options);
  bool setKeyboardFocusKeyInitiate(CompAction* action, CompAction::State state, CompOption::Vector& options);
  bool launcherRevealEdgeInitiate(CompAction* action, CompAction::State state, CompOption::Vector& options);

  bool altTabInitiateCommon(CompAction* action,
                            CompAction::State state,
                            CompOption::Vector& options);
  bool altTabTerminateCommon(CompAction* action,
                             CompAction::State state,
                             CompOption::Vector& options);

  bool altTabForwardInitiate(CompAction* action, CompAction::State state, CompOption::Vector& options);
  bool altTabPrevInitiate(CompAction* action, CompAction::State state, CompOption::Vector& options);
  bool altTabDetailStartInitiate(CompAction* action, CompAction::State state, CompOption::Vector& options);
  bool altTabDetailStopInitiate(CompAction* action, CompAction::State state, CompOption::Vector& options);
  bool altTabNextWindowInitiate(CompAction* action, CompAction::State state, CompOption::Vector& options);

  /* handle option changes and change settings inside of the
   * panel and dock views */
  void optionChanged(CompOption*, Options num);

  /* Handle changes in the number of workspaces by showing the switcher
   * or not showing the switcher */
  bool setOptionForPlugin(const char* plugin, const char* name,
                          CompOption::Value& v);

  /* init plugin actions for screen */
  bool initPluginForScreen(CompPlugin* p);

  void outputChangeNotify();
  void NeedsRelayout();
  void ScheduleRelayout(guint timeout);

  void setActiveFbo (GLuint fbo) { mActiveFbo = fbo; }

  bool forcePaintOnTop ();

protected:
  const gchar* GetName();
  void AddProperties(GVariantBuilder* builder);

private:
  void initAltTabNextWindow ();

  void SendExecuteCommand();

  void EnsureKeybindings ();

  static gboolean initPluginActions(gpointer data);
  static void initLauncher(nux::NThread* thread, void* InitData);
  void damageNuxRegions();
  void onRedrawRequested();
  void Relayout();

  static gboolean RelayoutTimeout(gpointer data);
  static void launcherWindowConfigureCallback(int WindowWidth, int WindowHeight,
                                              nux::Geometry& geo, void* user_data);
  static void initUnity(nux::NThread* thread, void* InitData);
  static void OnStartKeyNav(GVariant* data, void* value);
  static void OnExitKeyNav(GVariant* data, void* value);
  static gboolean OnEdgeTriggerTimeout(gpointer data);

  void startLauncherKeyNav();
  void restartLauncherKeyNav();
  void OnLauncherHiddenChanged();

  static void OnQuicklistEndKeyNav(GVariant* data, void* value);
  static void OnLauncherStartKeyNav(GVariant* data, void* value);
  static void OnLauncherEndKeyNav(GVariant* data, void* value);

  PlacesStyle      places_style_;
  FontSettings            font_settings_;
  Launcher*               launcher;
  LauncherController*     controller;
  DashController::Ptr     dashController;
  PanelController*        panelController;
  SwitcherController*     switcherController;
  GestureEngine*          gestureEngine;
  nux::WindowThread*      wt;
  nux::BaseWindow*        launcherWindow;
  nux::BaseWindow*        panelWindow;
  nux::Geometry           lastTooltipArea;
  DebugDBusInterface*     debugger;
  bool                    needsRelayout;
  guint32                 relayoutSourceId;
  guint                   _edge_timeout;
  guint                   _edge_trigger_handle;
  gint                    _edge_pointerY;
  guint                   _ubus_handles[3];

  typedef std::shared_ptr<CompAction> CompActionPtr;
  typedef std::vector<CompActionPtr> ShortcutActions;
  ShortcutActions _shortcut_actions;

  /* keyboard-nav mode */
  CompWindow* newFocusedWindow;
  CompWindow* lastFocusedWindow;

  GLTexture::List _shadow_texture;

  /* handle paint order */
  bool    doShellRepaint;
  bool    allowWindowPaint;
  bool    damaged;
  bool    _key_nav_mode_requested;
  CompOutput* _last_output;
  CompWindowList _withRemovedNuxWindows;

  DesktopLauncherIcon* switcher_desktop_icon;

  GdkRectangle _primary_monitor;

  unity::BGHash _bghash;

  std::map <CompOutput *, UnityFBO::Ptr> mFbos;
  GLuint                                 mActiveFbo;

  bool   queryForShader ();

  UBusManager ubus_manager_;
  bool dash_is_open_;
  CompScreen::GrabHandle grab_index_;
  CompWindowList         fullscreen_windows_;
  bool                   painting_tray_;
  unsigned int           tray_paint_mask_;

  friend class UnityWindow;
};

class UnityWindow :
  public WindowInterface,
  public GLWindowInterface,
  public BaseSwitchWindow,
  public PluginClassHandler <UnityWindow, CompWindow>
{
public:
  UnityWindow(CompWindow*);
  ~UnityWindow();

  CompWindow* window;
  GLWindow* gWindow;

  nux::Geometry last_bound;

  void minimize ();
  void unminimize ();
  bool minimized ();

  void updateFrameRegion (CompRegion &region);

  /* occlusion detection
   * and window hiding */
  bool glPaint(const GLWindowPaintAttrib& attrib,
               const GLMatrix&            matrix,
               const CompRegion&          region,
               unsigned int              mask);

  /* basic window draw function */
  bool glDraw(const GLMatrix& matrix,
              GLFragment::Attrib& attrib,
              const CompRegion& region,
              unsigned intmask);

  void updateIconPos (int   &wx,
                      int   &wy,
                      int   x,
                      int   y,
                      float width,
                      float height);

  void windowNotify(CompWindowNotify n);
  void moveNotify(int x, int y, bool immediate);
  void resizeNotify(int x, int y, int w, int h);
  void stateChangeNotify(unsigned int lastState);

  bool place(CompPoint& pos);
  CompPoint tryNotIntersectLauncher(CompPoint& pos);

  void paintThumbnail (nux::Geometry const& bounding, float alpha);

  void enterShowDesktop ();
  void leaveShowDesktop ();
  bool handleAnimations (unsigned int ms);

  compiz::MinimizedWindowHandler::Ptr mMinimizeHandler;
  UnityShowdesktopHandler             *mShowdesktopHandler;
};


/**
 * Your vTable class is some basic info about the plugin that core uses.
 */
class UnityPluginVTable :
  public CompPlugin::VTableForScreenAndWindow<UnityScreen, UnityWindow>
{
public:
  bool init();
};

#endif // UNITYSHELL_H
