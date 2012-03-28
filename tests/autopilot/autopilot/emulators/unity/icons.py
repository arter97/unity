# -*- Mode: Python; coding: utf-8; indent-tabs-mode: nil; tab-width: 4 -*-
# Copyright 2012 Canonical
# Author: Thomi Richards
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 3, as published
# by the Free Software Foundation.
#

from autopilot.emulators.unity import UnityIntrospectionObject
from autopilot.emulators.unity.quicklist import Quicklist


class SimpleLauncherIcon(UnityIntrospectionObject):
    """Holds information about a simple launcher icon.

    Do not instantiate an instance of this class yourself. Instead, use the
    appropriate methods in the Launcher class instead.

    """

    @property
    def center_position(self):
        """Get the center point of an icon, returns a tuple with (x, y, z)"""
        return (self.center_x, self.center_y, self.center_z)

    def get_quicklist(self):
        """Get the quicklist for this launcher icon.

        This may return None, if there is no quicklist associated with this
        launcher icon.

        """
        matches = self.get_children_by_type(Quicklist)
        return matches[0] if matches else None

    def is_on_monitor(self, monitor):
        """Returns True if the icon is available in the defined monitor"""
        if monitor >= 0 and monitor < len(self.monitors_visibility):
            return self.monitors_visibility[monitor]

        return False

    def is_visible_on_monitor(self, monitor):
        """Returns True if the icon is visible in the defined monitor"""
        return self.visible and self.is_on_monitor(monitor)


class BFBLauncherIcon(SimpleLauncherIcon):
    """Represents the BFB button in the launcher."""


class HudLauncherIcon(SimpleLauncherIcon):
    """Represents the HUD button in the launcher."""


class BamfLauncherIcon(SimpleLauncherIcon):
    """Represents a launcher icon with BAMF integration."""


class TrashLauncherIcon(SimpleLauncherIcon):
    """Represents the trash launcher icon."""


class DeviceLauncherIcon(SimpleLauncherIcon):
    """Represents a device icon in the launcher."""


class DesktopLauncherIcon(SimpleLauncherIcon):
    """Represents an icon that may appear in the switcher."""
