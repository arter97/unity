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
 * Authored by: Sam Spilsbury <sam.spilsbury@canonical.com>
 */

#include <gtk/gtk.h>
#include <core/core.h>
#include <core/atoms.h>
#include <composite/composite.h>
#include <opengl/opengl.h>
#include <X11/Xatom.h>
#include <X11/Xproto.h>

#include <cairo-xlib-xrender.h>

#include "unitydialog_options.h"

class UnityDialogShadeTexture
{
    public:

	UnityDialogShadeTexture ();

	Pixmap pixmap;
	GLTexture::List texture;
	cairo_surface_t *surface;
	cairo_t		*cairo;
	Damage		damage;

	void
	cairoClear (cairo_t    *cr);

	cairo_t *
	cairoContext ();

	void
	render ();
};

class UnityDialogWindow;

class UnityDialogScreen :
    public PluginClassHandler <UnityDialogScreen, CompScreen>,
    public ScreenInterface,
    public CompositeScreenInterface,
    public UnitydialogOptions
{
    public:

	UnityDialogScreen (CompScreen *);
	~UnityDialogScreen ();

	void
	handleEvent (XEvent *);

	void
	handleCompizEvent (const char *, const char *, CompOption::Vector &);

	void
	matchExpHandlerChanged ();

	CompMatch::Expression *
	matchInitExp (const CompString &value);

	void
	preparePaint (int);

	bool
	glPaintOutput (const GLScreenPaintAttrib &attrib,
		       const GLMatrix		 &transform,
		       const CompRegion		 &region,
		       CompOutput		 *output,
		       unsigned int		 mask);

	void
	donePaint ();

    public:

	CompositeScreen *cScreen;
	GLScreen	*gScreen;

	bool		mSwitchingVp;
	std::map <Window, UnityDialogWindow *> mIpws;
	UnityDialogShadeTexture mTex;

	GtkWidget *mOffscreenContainer;
	char	  *mThemeName;

	static void
	updateTexture (GObject		*obj,
		       GParamSpec	*pspec,
		       gpointer		data);
	

    public:

	Atom		compizResizeAtom;

    private:
	
};

#define UNITY_DIALOG_SCREEN(s)						       \
    UnityDialogScreen *uds = UnityDialogScreen::get (s);

class UnityDialogWindow :
    public PluginClassHandler <UnityDialogWindow, CompWindow>,
    public WindowInterface,
    public GLWindowInterface
{
    public:

	UnityDialogWindow (CompWindow *w);
	~UnityDialogWindow ();

    public:

	CompWindow *window;
	CompositeWindow *cWindow;
	GLWindow   *gWindow;

    public:

	bool
	glDraw (const GLMatrix &, GLFragment::Attrib &,
		const CompRegion &, unsigned int);

	bool
	glPaint (const GLWindowPaintAttrib &, const GLMatrix &,
		 const CompRegion &, unsigned int);

	void windowNotify (CompWindowNotify n);
	void grabNotify (int x, int y,
			 unsigned int state,
			 unsigned int mask);
	void ungrabNotify ();
	void moveNotify (int x, int y, bool immediate);
	void resizeNotify (int, int, int, int);

	bool place (CompPoint &);

	void getAllowedActions (unsigned int &setActions, unsigned int &clearActions);

	void addTransient (CompWindow *transient);
	void removeTransient (CompWindow *transient);

	CompPoint getChildCenteredPositionForRect (CompRect rect);
	CompPoint getParentCenteredPositionForRect (CompRect rect);

	void	  moveTransientsToRect (CompWindow *skip, CompRect rect, bool);
	void	  moveParentToRect (CompWindow *requestor, CompRect rect, bool);

	void	  grabTransients (CompWindow *skip, int x, int y,
				  unsigned int state, unsigned int mask, bool);
	void	  grabParent (CompWindow *requestor, int x, int y,
			      unsigned int state, unsigned int mask, bool);

	void      animateTransients (CompWindow *skip, CompPoint &orig, CompPoint &dest, bool cont);
	void	  animateParent (CompWindow *requestor, CompPoint &orig, CompPoint &dest);

	void      setMaxConstrainingAreas ();

	CompWindow * transientParent ();

	void adjustIPW ();

	bool	       mSkipNotify;
	CompWindowList mTransients;
	CompWindow     *mParent;
	CompSize       mOldHintsSize;
	int	       mGrabMask;
	int	       mShadeProgress;
	CompPoint      mTargetPos;
	CompPoint      mCurrentPos;

	Window	       mIpw;

    private:
};

#define VIG_WINDOW(w)						       \
    UnityDialogWindow *vw = UnityDialogWindow::get (w);

class UnityDialogPluginVTable :
    public CompPlugin::VTableForScreenAndWindow <UnityDialogScreen, UnityDialogWindow>
{
    public:

	bool init ();
};
