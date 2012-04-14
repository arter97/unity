# -*- Mode: Python; coding: utf-8; indent-tabs-mode: nil; tab-width: 4 -*-
# Copyright 2012 Canonical
# Authors: Thomi Richards,
#          Marco Trevisan (Treviño)
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 3, as published
# by the Free Software Foundation.

import logging
from testtools.matchers import Equals, NotEquals, LessThan, GreaterThan
from time import sleep

from autopilot.tests import AutopilotTestCase, multiply_scenarios
from autopilot.emulators.X11 import ScreenGeometry
from autopilot.emulators.unity.icons import BFBLauncherIcon

logger = logging.getLogger(__name__)

def _make_scenarios():
    """Make scenarios for launcher test cases based on the number of configured
    monitors.
    """
    screen_geometry = ScreenGeometry()
    num_monitors = screen_geometry.get_num_monitors()

    # it doesn't make sense to set only_primary when we're running in a single-monitor setup.
    if num_monitors == 1:
        return [('Single Monitor', {'launcher_monitor': 0, 'only_primary': False})]

    monitor_scenarios = [('Monitor %d' % (i), {'launcher_monitor': i}) for i in range(num_monitors)]
    launcher_mode_scenarios = [('launcher_on_primary', {'only_primary': True}),
                                ('launcher on all', {'only_primary': False})]
    return multiply_scenarios(monitor_scenarios, launcher_mode_scenarios)

class LauncherTestCase(AutopilotTestCase):
    """A base class for all launcher tests that uses scenarios to run on
    each launcher (for multi-monitor setups).
    """
    scenarios = _make_scenarios()

    def setUp(self):
        super(LauncherTestCase, self).setUp()
        self.screen_geo = ScreenGeometry()
        self.set_unity_log_level("unity.launcher", "DEBUG")
        self.set_unity_option('num_launchers', int(self.only_primary))
        self.launcher_instance = self.get_launcher()

        if self.only_primary:
            try:
                old_primary_screen = self.screen_geo.get_primary_monitor()
                self.screen_geo.set_primary_monitor(self.launcher_monitor)
                self.addCleanup(self.screen_geo.set_primary_monitor, old_primary_screen)
            except ScreenGeometry.BlacklistedDriverError:
                self.skipTest("Impossible to set the monitor %d as primary" % self.launcher_monitor)

    def tearDown(self):
        super(LauncherTestCase, self).tearDown()
        self.set_unity_log_level("unity.launcher", "INFO")

    def get_launcher(self):
        """Get the launcher for the current scenario."""
        return self.launcher.get_launcher_for_monitor(self.launcher_monitor)

class LauncherSwitcherTests(LauncherTestCase):
    """ Tests the functionality of the launcher's switcher capability"""
    
    def setUp(self):
        super(LauncherSwitcherTests, self).setUp()
        self.launcher_instance.switcher_start()
        sleep(0.5)

    def tearDown(self):
        super(LauncherSwitcherTests, self).tearDown()
        if self.launcher_instance.in_switcher_mode:
            self.launcher_instance.switcher_cancel()

    def test_launcher_switcher_cancel(self):
        """Test that ending the launcher switcher actually works."""
        self.launcher_instance.switcher_cancel()
        self.assertThat(self.launcher.key_nav_is_active, Equals(False))

    def test_launcher_switcher_cancel_resume_focus(self):
        """Test that ending the launcher switcher resume the focus."""
        self.close_all_app("Calculator")
        calc = self.start_app("Calculator")
        self.assertTrue(calc.is_active)

        self.launcher_instance.switcher_start()
        sleep(.5)
        self.assertFalse(calc.is_active)

        self.launcher_instance.switcher_cancel()
        sleep(.5)
        self.assertTrue(calc.is_active)

    def test_launcher_switcher_starts_at_index_zero(self):
        """Test that starting the Launcher switcher puts the keyboard focus on item 0."""
        self.assertThat(self.launcher.key_nav_is_active, Equals(True))
        self.assertThat(self.launcher.key_nav_is_grabbed, Equals(False))
        self.assertThat(self.launcher.key_nav_selection, Equals(0))

    def test_launcher_switcher_next(self):
        """Moving to the next launcher item while switcher is activated must work."""
        self.launcher_instance.switcher_next()
        sleep(0.5)
        logger.info("After next, keynav selection is %d", self.launcher.key_nav_selection)
        # The launcher model has hidden items, so the keynav indexes do not
        # increase by 1 each time. This test was failing because the 2nd icon
        # had an index of 2, not 1 as expected. The best we can do here is to
        # make sure that the index has increased. This opens us to the
        # possibility that the launcher really is skipping forward more than one
        # icon at a time, but we can't do much about that.
        self.assertThat(self.launcher.key_nav_selection, GreaterThan(0))

    def test_launcher_switcher_prev(self):
        """Moving to the previous launcher item while switcher is activated must work."""
        self.launcher_instance.switcher_prev()
        self.assertThat(self.launcher.key_nav_selection, NotEquals(0))

    def test_launcher_switcher_down(self):
        """Pressing the down arrow key while switcher is activated must work."""
        self.launcher_instance.switcher_down()
        sleep(.25)
        # The launcher model has hidden items, so the keynav indexes do not
        # increase by 1 each time. This test was failing because the 2nd icon
        # had an index of 2, not 1 as expected. The best we can do here is to
        # make sure that the index has increased. This opens us to the
        # possibility that the launcher really is skipping forward more than one
        # icon at a time, but we can't do much about that.
        self.assertThat(self.launcher.key_nav_selection, GreaterThan(0))

    def test_launcher_switcher_up(self):
        """Pressing the up arrow key while switcher is activated must work."""
        self.launcher_instance.switcher_up()
        self.assertThat(self.launcher.key_nav_selection, NotEquals(0))

    def test_launcher_switcher_next_doesnt_show_shortcuts(self):
        """Moving forward in launcher switcher must not show launcher shortcuts."""
        self.launcher_instance.switcher_next()
        # sleep so that the shortcut timeout could be triggered
        sleep(2)
        self.assertThat(self.launcher_instance.are_shortcuts_showing(), Equals(False))

    def test_launcher_switcher_prev_doesnt_show_shortcuts(self):
        """Moving backward in launcher switcher must not show launcher shortcuts."""
        self.launcher_instance.switcher_prev()
        # sleep so that the shortcut timeout could be triggered
        sleep(2)
        self.assertThat(self.launcher_instance.are_shortcuts_showing(), Equals(False))

    def test_launcher_switcher_cycling_forward(self):
        """Launcher Switcher must loop through icons when cycling forwards"""
        prev_icon = 0
        num_icons = self.launcher.model.num_launcher_icons()
        logger.info("This launcher has %d icons", num_icons)
        for icon in range(1, num_icons):
            self.launcher_instance.switcher_next()
            sleep(.25)
            # FIXME We can't directly check for selection/icon number equalty
            # since the launcher model also contains "hidden" icons that aren't
            # shown, so the selection index can increment by more than 1.
            self.assertThat(prev_icon, LessThan(self.launcher.key_nav_selection))
            prev_icon = self.launcher.key_nav_selection

        sleep(.5)
        self.launcher_instance.switcher_next()
        self.assertThat(self.launcher.key_nav_selection, Equals(0))

    def test_launcher_switcher_cycling_backward(self):
        """Launcher Switcher must loop through icons when cycling backwards"""
        self.launcher_instance.switcher_prev()
        # FIXME We can't directly check for self.launcher.num_launcher_icons - 1
        self.assertThat(self.launcher.key_nav_selection, GreaterThan(1))

    def test_launcher_switcher_activate_keep_focus(self):
        """Activating a running launcher icon should focus it"""
        calc = self.start_app("Calculator")
        sleep(.5)

        self.close_all_app("Mahjongg")
        mahjongg = self.start_app("Mahjongg")
        self.assertTrue(mahjongg.is_active)
        self.assertFalse(calc.is_active)

        self.launcher_instance.switcher_start()

        found = False
        for icon in self.launcher.model.get_launcher_icons_for_monitor(self.launcher_monitor):
            if (icon.tooltip_text == calc.name):
                found = True
                # FIXME: When releasing the keybinding another "next" is done
                self.launcher_instance.switcher_prev()
                self.launcher_instance.switcher_activate()
                break
            else:
                self.launcher_instance.switcher_next()

        sleep(.5)
        if not found:
            self.addCleanup(self.launcher_instance.switcher_cancel)

        self.assertTrue(found)
        self.assertTrue(calc.is_active)
        self.assertFalse(mahjongg.is_active)

    def test_launcher_switcher_using_shorcuts(self):
        """Using some other shortcut while switcher is active must cancel switcher."""
        self.keyboard.press_and_release("s")
        sleep(.25)
        self.keyboard.press_and_release("Escape")
        sleep(.25)
        self.assertThat(self.launcher.key_nav_is_active, Equals(False))

class LauncherShortcutTests(LauncherTestCase):
    def setUp(self):
        super(LauncherShortcutTests, self).setUp()
        self.launcher_instance.keyboard_reveal_launcher()
        sleep(2)

    def tearDown(self):
        super(LauncherShortcutTests, self).tearDown()
        self.launcher_instance.keyboard_unreveal_launcher()

    def test_launcher_keyboard_reveal_shows_shortcut_hints(self):
        """Launcher icons must show shortcut hints after revealing with keyboard."""
        self.assertThat(self.launcher_instance.are_shortcuts_showing(), Equals(True))

    def test_launcher_switcher_keeps_shorcuts(self):
        """Initiating launcher switcher after showing shortcuts must not hide shortcuts"""
        self.addCleanup(self.launcher_instance.switcher_cancel)
        self.launcher_instance.switcher_start()
        sleep(.5)

        self.assertThat(self.launcher.key_nav_is_active, Equals(True))
        self.assertThat(self.launcher_instance.are_shortcuts_showing(), Equals(True))

    def test_launcher_switcher_next_keeps_shortcuts(self):
        """Launcher switcher next action must keep shortcuts after they've been shown."""
        self.addCleanup(self.launcher_instance.switcher_cancel)
        self.launcher_instance.switcher_start()
        sleep(.5)

        self.launcher_instance.switcher_next()
        sleep(.5)
        self.assertThat(self.launcher_instance.are_shortcuts_showing(), Equals(True))

    def test_launcher_switcher_prev_keeps_shortcuts(self):
        """Launcher switcher prev action must keep shortcuts after they've been shown."""
        self.addCleanup(self.launcher_instance.switcher_cancel)
        self.launcher_instance.switcher_start()
        sleep(.5)

        self.launcher_instance.switcher_prev()
        sleep(.5)
        self.assertThat(self.launcher_instance.are_shortcuts_showing(), Equals(True))

class LauncherKeyNavTests(LauncherTestCase):
    """Test the launcher key navigation"""
    def setUp(self):
        super(LauncherKeyNavTests, self).setUp()
        self.launcher_instance.key_nav_start()

    def tearDown(self):
        super(LauncherKeyNavTests, self).tearDown()
        if self.launcher.key_nav_is_active:
            self.launcher_instance.key_nav_cancel()

    def test_launcher_keynav_initiate(self):
        """Tests we can initiate keyboard navigation on the launcher."""
        self.assertThat(self.launcher.key_nav_is_active, Equals(True))
        self.assertThat(self.launcher.key_nav_is_grabbed, Equals(True))

    def test_launcher_keynav_cancel(self):
        """Test that we can exit keynav mode."""
        self.launcher_instance.key_nav_cancel()
        self.assertThat(self.launcher.key_nav_is_active, Equals(False))
        self.assertThat(self.launcher.key_nav_is_grabbed, Equals(False))

    def test_launcher_keynav_cancel_resume_focus(self):
        """Test that ending the launcher keynav resume the focus."""
        self.close_all_app("Calculator")
        calc = self.start_app("Calculator")
        self.assertTrue(calc.is_active)

        self.launcher_instance.key_nav_start()
        sleep(.5)
        self.assertFalse(calc.is_active)

        self.launcher_instance.key_nav_cancel()
        sleep(.5)
        self.assertTrue(calc.is_active)

    def test_launcher_keynav_starts_at_index_zero(self):
        """Test keynav mode starts at index 0."""
        self.assertThat(self.launcher.key_nav_selection, Equals(0))

    def test_launcher_keynav_forward(self):
        """Must be able to move forwards while in keynav mode."""
        self.launcher_instance.key_nav_next()
        sleep(.5)
        # The launcher model has hidden items, so the keynav indexes do not
        # increase by 1 each time. This test was failing because the 2nd icon
        # had an index of 2, not 1 as expected. The best we can do here is to
        # make sure that the index has increased. This opens us to the
        # possibility that the launcher really is skipping forward more than one
        # icon at a time, but we can't do much about that.
        self.assertThat(self.launcher.key_nav_selection, GreaterThan(0))

    def test_launcher_keynav_prev_works(self):
        """Must be able to move backwards while in keynav mode."""
        self.launcher_instance.key_nav_next()
        sleep(.5)
        self.launcher_instance.key_nav_prev()
        self.assertThat(self.launcher.key_nav_selection, Equals(0))

    def test_launcher_keynav_cycling_forward(self):
        """Launcher keynav must loop through icons when cycling forwards"""
        prev_icon = 0
        for icon in range(1, self.launcher.model.num_launcher_icons()):
            self.launcher_instance.key_nav_next()
            sleep(.25)
            # FIXME We can't directly check for selection/icon number equalty
            # since the launcher model also contains "hidden" icons that aren't
            # shown, so the selection index can increment by more than 1.
            self.assertThat(prev_icon, LessThan(self.launcher.key_nav_selection))
            prev_icon = self.launcher.key_nav_selection

        sleep(.5)
        self.launcher_instance.key_nav_next()
        self.assertThat(self.launcher.key_nav_selection, Equals(0))

    def test_launcher_keynav_cycling_backward(self):
        """Launcher keynav must loop through icons when cycling backwards"""
        self.launcher_instance.key_nav_prev()
        # FIXME We can't directly check for self.launcher.num_launcher_icons - 1
        self.assertThat(self.launcher.key_nav_selection, GreaterThan(1))
        
    def test_launcher_keynav_can_open_and_close_quicklist(self):
        """Tests that we can open and close a quicklist from keynav mode."""
        self.launcher_instance.key_nav_next()
        sleep(.5)
        self.launcher_instance.key_nav_enter_quicklist()
        self.assertThat(self.launcher_instance.is_quicklist_open(), Equals(True))
        sleep(.5)
        self.launcher_instance.key_nav_exit_quicklist()
        self.assertThat(self.launcher_instance.is_quicklist_open(), Equals(False))
        self.assertThat(self.launcher.key_nav_is_active, Equals(True))
        self.assertThat(self.launcher.key_nav_is_grabbed, Equals(True))

    def test_launcher_keynav_mode_toggles(self):
        """Tests that keynav mode toggles with Alt+F1."""
        # was initiated in setup.
        self.launcher_instance.key_nav_start()
        sleep(0.25)
        self.assertThat(self.launcher.key_nav_is_active, Equals(False))

    def test_launcher_keynav_activate_keep_focus(self):
        """Activating a running launcher icon should focus it"""
        calc = self.start_app("Calculator")
        sleep(.5)

        self.close_all_app("Mahjongg")
        mahjongg = self.start_app("Mahjongg")
        self.assertTrue(mahjongg.is_active)
        self.assertFalse(calc.is_active)

        self.launcher_instance.key_nav_start()

        found = False
        for icon in self.launcher.model.get_launcher_icons_for_monitor(self.launcher_monitor):
            if (icon.tooltip_text == calc.name):
                found = True
                self.launcher_instance.key_nav_activate()
                break
            else:
                self.launcher_instance.key_nav_next()

        sleep(.5)
        if not found:
            self.addCleanup(self.launcher_instance.key_nav_cancel)

        self.assertTrue(found)
        self.assertTrue(calc.is_active)
        self.assertFalse(mahjongg.is_active)

    def test_launcher_keynav_alt_tab_quits(self):
        """Tests that alt+tab exits keynav mode."""

        self.switcher.initiate()
        sleep(1)
        self.switcher.stop()

        self.assertThat(self.launcher.key_nav_is_active, Equals(False))

    def test_launcher_keynav_alt_grave_quits(self):
        """Tests that alt+` exits keynav mode."""

        self.switcher.initiate_detail_mode()
        sleep(1)
        self.switcher.stop()

        self.assertThat(self.launcher.key_nav_is_active, Equals(False))
  
    def test_launcher_activate_last_focused_window(self):
        """ 

        This tests shows that when you activate a launcher icon only the last 
        focused instance of that application is raised.

        This is tested by opening 2 Mahjongg and a Calculator. 
        Then we activate the Calculator launcher icon.
        Then we activate the Mahjongg launcher icon.
        Then we minimize the focused applications.
        This should give focus to the next window on the stack.
        If only 1 instance is raised then the Calculator gets the focus.
        If ALL the instances are raised then the second Mahjongg gets the focus.

        """

        self.start_app("Mahjongg")
        sleep(.5)
        calc = self.start_app("Calculator")
        sleep(.5)
        mahj = self.start_app("Mahjongg")
        sleep(.5)

        self.launcher_instance.key_nav_start()

        for icon in self.launcher.model.get_launcher_icons_for_monitor(self.launcher_monitor):
            if (icon.tooltip_text == calc.name):
                self.launcher_instance.key_nav_activate()
                break
            else:
                self.launcher_instance.key_nav_next()
      
        self.launcher_instance.key_nav_start()

        for icon in self.launcher.model.get_launcher_icons_for_monitor(self.launcher_monitor):
            if (icon.tooltip_text == mahj.name):
                self.launcher_instance.key_nav_activate()
                break
            else:
                self.launcher_instance.key_nav_next()

        sleep(1)
        self.keybinding("window/minimize")
        sleep(1)

        self.assertTrue(calc.is_active)
        self.assertFalse(mahj.is_active)

    def test_launcher_activate_does_not_focus_minimized_windows(self):
        """

        Testing that activating a launcher icon wont focus a minimized window.
        
        This is tested by making 2 calculators and 1 mahjongg.
        While making the second calculator you minimize it.
        While mahjongg has focus, activate the calculator icon.
        It should focus the non-minimized calculator.

        """ 

        self.close_all_app("Calculator")
        sleep(.5)

        self.start_app("Calculator")
        sleep(.5)
        mahj = self.start_app("Mahjongg")
        sleep(.5)

        sleep(.5)
        calc = self.start_app("Calculator")
        sleep(.5)
        self.keybinding("window/minimize")
        
        wins = calc.get_windows()
        self.assertThat (len(wins), Equals(2))

        min_calc = calc.get_windows()[0]
        focused_calc = calc.get_windows()[1]
        
        self.launcher_instance.key_nav_start()

        for icon in self.launcher.model.get_launcher_icons_for_monitor(self.launcher_monitor):
            if (icon.tooltip_text == calc.name):
                self.launcher_instance.key_nav_activate()
                break
            else:
                self.launcher_instance.key_nav_next()

        sleep(1)

        self.assertTrue(focused_calc.is_focused)
        self.assertTrue(min_calc.is_hidden)

class LauncherRevealTests(LauncherTestCase):
    """Test the launcher reveal bahavior when in autohide mode."""

    def setUp(self):
        super(LauncherRevealTests, self).setUp()
        # these automatically reset to the original value, as implemented in AutopilotTestCase
        self.set_unity_option('launcher_capture_mouse', True)
        self.set_unity_option('launcher_hide_mode', 1)
        launcher = self.get_launcher()
        for counter in range(10):
            sleep(1)
            if launcher.hidemode == 1:
                break
        self.assertThat(launcher.hidemode, Equals(1),
                        "Launcher did not enter auto-hide mode.")

    def test_launcher_keyboard_reveal_works(self):
        """Revealing launcher with keyboard must work."""
        self.addCleanup(self.launcher_instance.keyboard_unreveal_launcher)

        self.launcher_instance.keyboard_reveal_launcher()
        sleep(0.5)
        self.assertThat(self.launcher_instance.is_showing(), Equals(True))

    def test_reveal_on_mouse_to_edge(self):
        """Tests reveal of launchers by mouse pressure."""
        self.launcher_instance.move_mouse_to_right_of_launcher()
        self.launcher_instance.mouse_reveal_launcher()
        self.assertThat(self.launcher_instance.is_showing(), Equals(True))

    def test_reveal_with_mouse_under_launcher(self):
        """Tests that the launcher hides properly if the
        mouse is under the launcher when it is revealed.
        """
        self.launcher_instance.move_mouse_over_launcher()
        # we can't use "launcher_instance.keyboard_reveal_launcher()"
        # since it moves the mouse out of the way, invalidating the test.
        self.keybinding_hold("launcher/reveal")
        sleep(1)
        self.keybinding_release("launcher/reveal")
        sleep(2)
        self.assertThat(self.launcher_instance.is_showing(), Equals(False))

    def test_reveal_does_not_hide_again(self):
        """Tests reveal of launchers by mouse pressure to ensure it doesn't
        automatically hide again.
        """
        self.launcher_instance.move_mouse_to_right_of_launcher()
        self.launcher_instance.mouse_reveal_launcher()
        sleep(2)
        self.assertThat(self.launcher_instance.is_showing(), Equals(True))

    def test_launcher_does_not_reveal_with_mouse_down(self):
        """Launcher must not reveal if have mouse button 1 down."""
        self.screen_geo.move_mouse_to_monitor(self.launcher_instance.monitor)
        self.mouse.press(1)
        self.addCleanup(self.mouse.release, 1)
        #FIXME: This is really bad API. it says reveal but it's expected to fail. bad bad bad!!
        self.launcher_instance.mouse_reveal_launcher()
        self.assertThat(self.launcher_instance.is_showing(), Equals(False))

class LauncherVisualTests(LauncherTestCase):
    """Tests for visual aspects of the launcher (icon saturation etc.)."""

    def test_keynav_from_dash_saturates_icons(self):
        """Starting super+tab switcher from the dash must resaturate launcher icons.

        Tests fix for bug #913569.
        """
        bfb = self.launcher.model.get_bfb_icon()
        self.mouse.move(bfb.center_x, bfb.center_y)
        self.dash.ensure_visible()
        sleep(1)
        # We can't use 'launcher_instance.switcher_start()' since it moves the mouse.
        self.keybinding_hold_part_then_tap("launcher/switcher")
        self.addCleanup(self.keybinding_release, "launcher/switcher")
        self.addCleanup(self.keybinding, "launcher/switcher/exit")

        self.keybinding_tap("launcher/switcher/next")
        for icon in self.launcher.model.get_launcher_icons():
            self.assertFalse(icon.desaturated)

    def test_opening_dash_desaturates_icons(self):
        """Opening the dash must desaturate all the launcher icons."""
        self.dash.ensure_visible()
        self.addCleanup(self.dash.ensure_hidden)

        for icon in self.launcher.model.get_launcher_icons():
            if isinstance(icon, BFBLauncherIcon):
                self.assertFalse(icon.desaturated)
            else:
                self.assertTrue(icon.desaturated)

    def test_opening_dash_with_mouse_over_launcher_keeps_icon_saturation(self):
        """Opening dash with mouse over launcher must not desaturate icons."""
        launcher_instance = self.get_launcher()
        x,y,w,h = launcher_instance.geometry
        self.mouse.move(x + w/2, y + h/2)
        sleep(.5)
        self.dash.ensure_visible()
        self.addCleanup(self.dash.ensure_hidden)
        for icon in self.launcher.model.get_launcher_icons():
            self.assertFalse(icon.desaturated)

    def test_mouse_over_with_dash_open_desaturates_icons(self):
        """Moving mouse over launcher with dash open must saturate icons."""
        launcher_instance = self.get_launcher()
        self.dash.ensure_visible()
        self.addCleanup(self.dash.ensure_hidden)
        sleep(.5)
        x,y,w,h = launcher_instance.geometry
        self.mouse.move(x + w/2, y + h/2)
        sleep(.5)
        for icon in self.launcher.model.get_launcher_icons():
            self.assertFalse(icon.desaturated)

class LauncherCaptureTests(AutopilotTestCase):
    """Test the launchers ability to capture/not capture the mouse."""

    screen_geo = ScreenGeometry()

    def setHideMode(self, mode):
        launcher = self.launcher.get_launcher_for_monitor(0)
        for counter in range(10):
            sleep(1)
            if launcher.hidemode == mode:
                break
        self.assertThat(launcher.hidemode, Equals(mode),
                        "Launcher did not enter revealed mode.")

    def leftMostMonitor(self):
        x1, y1, width, height = self.screen_geo.get_monitor_geometry(0)
        x2, y2, width, height = self.screen_geo.get_monitor_geometry(1)

        if x1 < x2:
            return 0
        return 1

    def rightMostMonitor(self):
        return 1 - self.leftMostMonitor()

    def setUp(self):
        super(LauncherCaptureTests, self).setUp()
        self.set_unity_option('launcher_capture_mouse', True)
        self.set_unity_option('launcher_hide_mode', 0)
        self.set_unity_option('num_launchers', 0)
        self.setHideMode(0)

    def test_launcher_captures_while_sticky_and_revealed(self):
        """Tests that the launcher captures the mouse when moving between monitors
        while revealed.
        """
        if self.screen_geo.get_num_monitors() <= 1:
            self.skipTest("Cannot run this test with a single monitor configured.")

        x, y, width, height = self.screen_geo.get_monitor_geometry(self.rightMostMonitor())
        self.mouse.move(x + width / 2, y + height / 2, False)
        self.mouse.move(x - width / 2, y + height / 2, True, 5, .002)

        x_fin, y_fin = self.mouse.position()
        # The launcher should have held the mouse a little bit
        self.assertThat(x_fin, GreaterThan(x - width / 2))

    def test_launcher_not_capture_while_not_sticky_and_revealed(self):
        """Tests that the launcher doesn't captures the mouse when moving between monitors
        while revealed and stick is off.
        """
        if self.screen_geo.get_num_monitors() <= 1:
            self.skipTest("Cannot run this test with a single monitor configured.")

        self.set_unity_option('launcher_capture_mouse', False)

        x, y, width, height = self.screen_geo.get_monitor_geometry(self.rightMostMonitor())
        self.mouse.move(x + width / 2, y + height / 2, False)
        self.mouse.move(x - width / 2, y + height / 2, True, 5, .002)

        x_fin, y_fin = self.mouse.position()
        # The launcher should have held the mouse a little bit
        self.assertThat(x_fin, Equals(x - width / 2))

    def test_launcher_not_capture_while_not_sticky_and_hidden_moving_right(self):
        """Tests that the launcher doesn't capture the mouse when moving between monitors
        while hidden and sticky is off.
        """
        if self.screen_geo.get_num_monitors() <= 1:
            self.skipTest("Cannot run this test with a single monitor configured.")

        self.set_unity_option('launcher_hide_mode', 1)
        self.set_unity_option('launcher_capture_mouse', False)

        self.setHideMode(1)

        x, y, width, height = self.screen_geo.get_monitor_geometry(self.leftMostMonitor())
        self.mouse.move(x + width / 2, y + height / 2, False)
        sleep(1.5)
        self.mouse.move(x + width * 1.5, y + height / 2, True, 5, .002)

        x_fin, y_fin = self.mouse.position()
        # The launcher should have held the mouse a little bit
        self.assertThat(x_fin, Equals(x + width * 1.5))

    def test_launcher_capture_while_sticky_and_hidden_moving_right(self):
        """Tests that the launcher captures the mouse when moving between monitors
        while hidden.
        """
        if self.screen_geo.get_num_monitors() <= 1:
            self.skipTest("Cannot run this test with a single monitor configured.")

        self.set_unity_option('launcher_hide_mode', 1)

        self.setHideMode(1)

        x, y, width, height = self.screen_geo.get_monitor_geometry(self.leftMostMonitor())
        self.mouse.move(x + width / 2, y + height / 2, False)
        sleep(1.5)
        self.mouse.move(x + width * 1.5, y + height / 2, True, 5, .002)

        x_fin, y_fin = self.mouse.position()
        # The launcher should have held the mouse a little bit
        self.assertThat(x_fin, LessThan(x + width * 1.5))
