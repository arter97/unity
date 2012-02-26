# -*- Mode: Python; coding: utf-8; indent-tabs-mode: nil; tab-width: 4 -*-
# Copyright 2010 Canonical
# Author: Thomi Richards
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 3, as published
# by the Free Software Foundation.

from compizconfig import Setting
from compizconfig import Plugin
from subprocess import call
from testtools.matchers import Equals, NotEquals
from time import sleep

from autopilot.emulators.bamf import Bamf
from autopilot.emulators.unity.switcher import Switcher
from autopilot.emulators.X11 import Keyboard
from autopilot.glibrunner import GlibRunner
from autopilot.globals import global_context
from autopilot.tests import AutopilotTestCase


class SwitcherTests(AutopilotTestCase):
    """Test the switcher."""
    run_test_with = GlibRunner

    def set_timeout_setting(self, value):
        self.setting.Value = value
        global_context.Write()

    def setUp(self):
        self.plugin = Plugin(global_context, "unityshell")
        self.setting = Setting(self.plugin, "alt_tab_timeout")
        self.bamf = Bamf()

        self.bamf.launch_application("gucharmap.desktop")
        self.bamf.launch_application("gcalctool.desktop")
        self.bamf.launch_application("mahjongg.desktop")

        super(SwitcherTests, self).setUp()

        self.server = Switcher()

    def tearDown(self):
        call(["killall", "gcalctool"])
        call(["killall", "gucharmap"])
        call(["killall", "mahjongg"])
        super(SwitcherTests, self).tearDown()
        sleep(1)

    def test_switcher_move_next(self):
        self.set_timeout_setting(False)
        sleep(1)

        self.server.initiate()
        sleep(.2)

        start = self.server.get_selection_index()
        self.server.next_icon()
        sleep(.2)

        end = self.server.get_selection_index()
        self.server.terminate()

        self.assertThat(start, NotEquals(0))
        self.assertThat(end, Equals(start + 1))
        self.set_timeout_setting(True)

    def test_switcher_move_prev(self):
        self.set_timeout_setting(False)
        sleep(1)

        self.server.initiate()
        sleep(.2)

        start = self.server.get_selection_index()
        self.server.previous_icon()
        sleep(.2)

        end = self.server.get_selection_index()
        self.server.terminate()

        self.assertThat(start, NotEquals(0))
        self.assertThat(end, Equals(start - 1))
        self.set_timeout_setting(True)

    def test_switcher_starts_in_normal_mode(self):
        """Switcher must start in normal (i.e.- not details) mode."""
        self.server.initiate()
        self.assertThat(self.server.get_is_in_details_mode(), Equals(False))

    def test_down_arrow_starts_details_mode(self):
        """Pressing 'Down' while not in details mode must start details mode."""
        self.server.initiate()
        kb = Keyboard()
        kb.press_and_release('Down')
        self.assertThat(self.server.get_is_in_details_mode(), Equals(True))

    def test_grave_starts_details_mode(self):
        """Pressing '`' while not in details mode must start detils mode."""
        self.server.initiate()
        kb = Keyboard()
        kb.press_and_release('`')
        self.assertThat(self.server.get_is_in_details_mode(), Equals(True))

