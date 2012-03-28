# -*- Mode: Python; coding: utf-8; indent-tabs-mode: nil; tab-width: 4 -*-
# Copyright 2012 Canonical
# Author: Thomi Richards
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 3, as published
# by the Free Software Foundation.
#

from autopilot.emulators.unity import (
    get_state_by_path,
    make_introspection_object,
    UnityIntrospectionObject,
)


from autopilot.keybindings import KeybindingsHelper
from autopilot.emulators.unity import UnityIntrospectionObject


class HudView(UnityIntrospectionObject):
    """Proxy object for the hud view child of the controller."""

    def get_searchbar(self):
        """Get the search bar attached to this hud view."""
        return self.get_children_by_type(SearchBar)[0]

class HudController(UnityIntrospectionObject, KeybindingsHelper):
    """Proxy object for the Unity Hud Controller."""

    def ensure_hidden(self):
        """Hides the hud if it's not already hidden."""
        if self.is_visible():
            self.toggle_reveal()

    def ensure_visible(self):
        """Shows the hud if it's not already showing."""
        if not self.is_visible():
            self.toggle_reveal()

    def is_visible(self):
        return self.visible

    def toggle_reveal(self, tap_delay=0.1):
        """Tap the 'Alt' key to toggle the hud visibility."""
        self.keybinding("hud/reveal", tap_delay)

    def get_searchbar(self):
        """Returns the searchbar attached to the dash."""
        return self._get_view().get_searchbar();

    def _get_view(self):
        views = self.get_children_by_type(HudView)
        return views[0] if views else None

    @property
    def selected_button(self):
        view = self._get_view()
        if view:
            return view.selected_button
        else:
            return 0

    @property
    def num_buttons(self):
        view = self._get_view()
        if view:
            return view.num_buttons
        else:
            return 0

class SearchBar(UnityIntrospectionObject):
    """The search bar for the dash view."""
