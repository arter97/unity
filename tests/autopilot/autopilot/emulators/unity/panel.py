# -*- Mode: Python; coding: utf-8; indent-tabs-mode: nil; tab-width: 4 -*-
# Copyright 2012 Canonical
# Author: Marco Trevisan (Treviño)
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 3, as published
# by the Free Software Foundation.
#

import logging

from autopilot.keybindings import KeybindingsHelper
from autopilot.emulators.X11 import Mouse, ScreenGeometry
from autopilot.emulators.unity import UnityIntrospectionObject

logger = logging.getLogger(__name__)


class PanelController(UnityIntrospectionObject):
    """The PanelController class."""

    def get_panel_for_monitor(self, monitor_num):
        """Return an instance of panel for the specified monitor, or None."""
        panels = self.get_children_by_type(UnityPanel, monitor=monitor_num)
        return panels[0] if panels else None

    def get_active_panel(self):
        """Return the active panel, or None."""
        panels = self.get_children_by_type(UnityPanel, active=True)
        assert(len(panels) == 1)
        return panels[0] if panels else None

    def get_panels(self):
        """Return the available panels, or None."""
        return self.get_children_by_type(UnityPanel)

class UnityPanel(UnityIntrospectionObject, KeybindingsHelper):
    """An individual panel for a monitor."""

    def __init__(self, *args, **kwargs):
        super(UnityPanel, self).__init__(*args, **kwargs)
        self._mouse = Mouse()

    def __get_menu_view(self):
        """Return the menu view."""
        menus = self.get_children_by_type(MenuView)
        assert(len(menus) == 1)
        return menus[0]

    def __get_grab_area(self):
        """Return the panel grab area."""
        grab_areas = self.get_children_by_type(GrabArea)
        assert(len(grab_areas) == 1)
        return grab_areas[0]

    def __get_indicators_view(self):
        """Return the menu view."""
        indicators = self.get_children_by_type(Indicators)
        assert(len(indicators) == 1)
        return indicators[0]

    def __get_window_buttons(self):
        """Return the window buttons view."""
        buttons = self.get_children_by_type(WindowButtons)
        assert(len(buttons) == 1)
        return buttons[0]

    def move_mouse_below_the_panel(self):
        """Places the mouse to bottom of this panel."""
        (x, y, w, h) = self.geometry
        target_x = x + w / 2
        target_y = y + h + 10

        logger.debug("Moving mouse away from panel.")
        self._mouse.move(target_x, target_y)

    def move_mouse_over_menus(self):
        """Move the mouse over the menu area for this panel."""
        (x, y, w, h) = self.menus.geometry
        target_x = x + w / 2
        target_y = y + h / 2

        # The menu view has bigger geometry than the real layout
        menu_entries = self.menus.get_entries()
        if menu_entries and len(menu_entries) > 0:
            first_x = menu_entries[0].x
            last_x = menu_entries[len(menu_entries)-1].x + menu_entries[len(menu_entries)-1].width / 2

            target_x = (last_x - first_x) / 2

        logger.debug("Moving mouse to center of menu area.")
        self._mouse.move(target_x, target_y)

    def move_mouse_over_grab_area(self):
        """Move the mouse over the grab area for this panel."""
        (x, y, w, h) = self.grab_area.geometry
        target_x = x + w / 2
        target_y = y + h / 2

        logger.debug("Moving mouse to center of grab area.")
        self._mouse.move(target_x, target_y)

    def get_indicator_entries(self, visible_only=True):
        """Returns a list of entries for this panel including both menus and indicators"""
        entries = self.get_menu_entries(visible_only)
        entries += self.indicators.get_ordered_entries(visible_only)
        return entries

    def get_indicator_entry(self, id):
        """Returns the indicator entry for the given ID or None"""
        for en in self.get_indicator_entries():
            if en.id == id:
                return en

        return None

    @property
    def title(self):
        return self.menus.panel_title

    @property
    def desktop_is_active(self):
        return self.menus.desktop_active

    @property
    def window_buttons(self):
        return self.__get_window_buttons()

    @property
    def menus(self):
        return self.__get_menu_view()

    @property
    def grab_area(self):
        return self.__get_grab_area()

    @property
    def indicators(self):
        return self.__get_indicators_view()

    @property
    def geometry(self):
        """Returns a tuple of (x,y,w,h) for the current panel."""
        return (self.x, self.y, self.width, self.height)


class MenuView(UnityIntrospectionObject):
    """The Menu View class."""

    def get_entries(self, visible_only=True):
        """Return a list of menu entries"""
        if visible_only:
            return self.get_children_by_type(IndicatorEntry, visible=True)
        else:
            return self.get_children_by_type(IndicatorEntry)

    @property
    def geometry(self):
        """Returns a tuple of (x,y,w,h) for the current menu view."""
        return (self.x, self.y, self.width, self.height)


class WindowButtons(UnityIntrospectionObject):
    """The window buttons class"""

    def get_buttons(self, visible_only=True):
        """Return a list of window buttons"""
        if visible_only:
            return self.get_children_by_type(Button, visible=True)
        else:
            return self.get_children_by_type(Button)

    def get_button(self, type):
        return self.get_children_by_type(Button, type=type)

    @property
    def close(self):
        return self.get_button("Close")

    @property
    def minimize(self):
        return self.get_button("Minimize")

    @property
    def unmaximize(self):
        return self.get_button("Unmaximize")

    @property
    def maximize(self):
        return self.get_button("Maximize")

    @property
    def geometry(self):
        """Returns a tuple of (x,y,w,h) for the current panel."""
        return (self.x, self.y, self.width, self.height)


class WindowButton(UnityIntrospectionObject):
    """The Window Button class."""

    def __init__(self, *args, **kwargs):
        super(Button, self).__init__(*args, **kwargs)
        self._mouse = Mouse()

    def mouse_move_to(self):
        target_x = self.x + self.width / 2
        target_y = self.y + self.height / 2
        self._mouse.move(target_x, target_y)

    def mouse_click(self):
        self.mouse_move_to()
        sleep(.2)
        self._mouse.click(1)

    @property
    def geometry(self):
        """Returns a tuple of (x,y,w,h) for the window button."""
        return (self.x, self.y, self.width, self.height)


class GrabArea(UnityIntrospectionObject):
    """The grab area class"""

    @property
    def geometry(self):
        """Returns a tuple of (x,y,w,h) for the grab area."""
        return (self.x, self.y, self.width, self.height)


class Indicators(UnityIntrospectionObject):
    """The Indicators View class."""

    def get_ordered_entries(self, visible_only=True):
        """Return a list of indicators, ordered by their priority"""
        entries = []

        if visible_only:
            entries = self.get_children_by_type(IndicatorEntry, visible=True)
        else:
            entries = self.get_children_by_type(IndicatorEntry)

        return sorted(entries, key=lambda entry: entry.priority) 

    @property
    def geometry(self):
        """Returns a tuple of (x,y,w,h) for the indicators area."""
        return (self.x, self.y, self.width, self.height)


class IndicatorEntry(UnityIntrospectionObject):
    """The IndicatorEntry View class."""

    def __init__(self, *args, **kwargs):
        super(IndicatorEntry, self).__init__(*args, **kwargs)
        self._mouse = Mouse()

    def mouse_move_to(self):
        target_x = self.x + self.width / 2
        target_y = self.y + self.height / 2
        self._mouse.move(target_x, target_y)

    def mouse_click(self, button=1):
        self.mouse_move_to()
        sleep(.2)
        assert(self.visible)
        self._mouse.click(button)

    @property
    def geometry(self):
        """Returns a tuple of (x,y,w,h) for the indicator entry."""
        return (self.x, self.y, self.width, self.height)

    @property
    def menu_geometry(self):
        """Returns a tuple of (x,y,w,h) for the opened menu geometry."""
        return (self.menu_x, self.menu_y, self.menu_width, self.menu_height)

