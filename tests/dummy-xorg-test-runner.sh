#!/bin/bash
# Copyright (C) 2013 Canonical Ltd
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 3 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Authored by: Marco Trevisan <marco.trevisan@canonical.com>

MAX_WAIT=5

binary=$(which $1)

if [ -z "$binary" ]; then
  if [ -z "$1" ]; then
    echo "Empty command submitted"
  elif [ ! -x "$1" ]; then
    echo "The provided $1 is not executable"
  fi

  exit 1
fi

logfile=$(mktemp -t dummy.Xorg.log.XXXXXXXX)
conffile=$(mktemp -t dummy.Xorg.conf.XXXXXXXX)

cat << 'END_OF_CONFIG' > $conffile
Section "Monitor"
        Identifier "Dummy Monitor"
EndSection

Section "Device"
        Identifier "Dummy Card"
        Driver "dummy"
EndSection

Section "Screen"
        DefaultDepth 24
        Identifier "Dummy Screen"
        Device "Dummy Card"
        Monitor "Dummy Monitor"
EndSection
END_OF_CONFIG

export DISPLAY=:`for id in $(seq 100 150); do test -e /tmp/.X$id-lock || { echo $id; exit 0; }; done; exit 1`
Xorg $DISPLAY -config $conffile -logfile $logfile &> /dev/null &
x_pid=$!

start_time=$(date +%s)
while [ ! -e /tmp/.X${DISPLAY:1}-lock ] && [ $(($(date +%s) - start_time)) -lt $MAX_WAIT ]; do
  sleep 0.1
done

shift
$binary $@
ret_val=$?

if (kill -0 $x_pid &> /dev/null); then kill $x_pid; fi
rm $conffile
rm $logfile*

exit $ret_val
