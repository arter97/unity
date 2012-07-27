/*
 * CompoundGestureRecognizer.h
 * This file is part of Unity
 *
 * Copyright (C) 2012 - Canonical Ltd.
 *
 * Unity is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Unity is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Unity; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#ifndef COMPOUND_GESTURE_RECOGNIZER_H
#define COMPOUND_GESTURE_RECOGNIZER_H

#include <sigc++/sigc++.h>

namespace nux
{
  class GestureEvent;
}

enum class RecognitionResult
{
  NONE,
  DOUBLE_TAP_RECOGNIZED, /*! Returned when a double-tap is recognized */
  TAP_AND_HOLD_RECOGNIZED, /*!< Returned when a "tap and hold" is recognized
                             At this point the user is still "holding". I.e.,
                             his fingers are still on the touchscreen or
                             trackpad. */
};

/*!
  Recognizes compound gestures. I.e. high level gestures that are maded up by
  two sequencial regular gestures (like a tap followed by a second tap).
 */
class CompoundGestureRecognizer
{
  public:
    // in milliseconds
    static const int MAX_TIME_BETWEEN_GESTURES = 600;
    static const int MAX_TAP_TIME = 300;
    static const int HOLD_TIME = 600;

    CompoundGestureRecognizer();

    virtual RecognitionResult GestureEvent(const nux::GestureEvent &event);

  private:
    enum class State
    {
      WaitingFirstTapBegin,
      WaitingFirstTapEnd,
      WaitingSecondGestureBegin,
      RecognizingSecondGesture
    };

    RecognitionResult WaitingFirstTapBegin(const nux::GestureEvent &event);
    RecognitionResult WaitingFirstTapEnd(const nux::GestureEvent &event);
    RecognitionResult WaitingSecondGestureBegin(const nux::GestureEvent &event);
    RecognitionResult RecognizingSecondGesture(const nux::GestureEvent &event);
    void ResetStateMachine();

    State state_;

    class GestureInfo
    {
      public:
      GestureInfo() {Clear();}
      int begin_time;
      int end_time;
      int id;
      int Duration() const {return end_time - begin_time;}
      void Clear() {begin_time = end_time = id = -1;}
    };
    GestureInfo first_gesture;
    GestureInfo second_gesture;
};

#endif // COMPOUND_GESTURE_RECOGNIZER_H
