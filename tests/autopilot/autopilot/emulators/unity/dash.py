# -*- Mode: Python; coding: utf-8; indent-tabs-mode: nil; tab-width: 4 -*-
# Copyright 2012 Canonical
# Author: Thomi Richards
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 3, as published
# by the Free Software Foundation.
#

from compizconfig import Setting, Plugin
from time import sleep

from autopilot.globals import global_context
from autopilot.emulators.unity import get_state_by_path
from autopilot.emulators.X11 import Keyboard

class Dash(object):
    """
    An emulator class that makes it easier to interact with the unity dash.
    """

    def __init__(self):
        self.plugin = Plugin(global_context, "unityshell")
        self.setting = Setting(self.plugin, "show_launcher")
        self._keyboard = Keyboard()
        super(Dash, self).__init__()

    def toggle_reveal(self):
        """
        Reveals the dash if it's currently hidden, hides it otherwise.
        """
        self._keyboard.press_and_release("Super")
        sleep(1)

    def ensure_visible(self):
        """
        Ensures the dash is visible.
        """
        if not self.get_is_visible():
            self.toggle_reveal();

    def ensure_hidden(self):
        """
        Ensures the dash is hidden.
        """
        if self.get_is_visible():
            self.toggle_reveal();

    def get_is_visible(self):
        """
        Is the dash visible?
        """
        return bool(get_state_by_path("/Unity/DashController")[0]["visible"])

    def get_search_string(self):
        """
        Return the current dash search bar search string.
        """
        return unicode(get_state_by_path("//SearchBar")[0]['search_string'])

    def get_current_lens(self):
        """Returns the id of the current lens.

        For example, the default lens is 'home.lens', the run-command lens is
        'commands.lens'.

        """
        return unicode(get_state_by_path("//DashController/DashView/LensBar")[0]['active-lens'])

    def get_focused_lens_icon(self):
        """Returns the id of the current focused icon."""
        return unicode(get_state_by_path("//DashController/DashView/LensBar")[0]['focused-lens-icon'])

    def get_num_rows(self):
        """Returns the number of displayed rows in the dash."""
        return get_state_by_path("//DashController/DashView")[0]['num-rows']

    def reveal_application_lens(self):
        """Reveal the application lense."""
        self._keyboard.press('Super')
        self._keyboard.press_and_release("a")
        self._keyboard.release('Super')

    def reveal_music_lens(self):
        """Reveal the music lense."""
        self._keyboard.press('Super')
        self._keyboard.press_and_release("m")
        self._keyboard.release('Super')

    def reveal_file_lens(self):
        """Reveal the file lense."""
        self._keyboard.press('Super')
        self._keyboard.press_and_release("f")
        self._keyboard.release('Super')

    def reveal_command_lens(self):
        """Reveal the 'run command' lens."""
        self._keyboard.press_and_release('Alt+F2')

    def get_focused_category(self):
        """Returns the current focused category. """
        groups = get_state_by_path("//PlacesGroup[header-has-keyfocus=True]")

        if len(groups) >= 1:
          return groups[0]
        else:
          return None

