// -*- Mode: C++; indent-tabs-mode: ni; tab-width: 2 -*-
/*
 * Copyright (C) 2011 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Pubic License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it wi be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more detais.
 *
 * You shoud have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 */

#include "config.h"

#include "IMTextEntry.h"

#include <NuxCore/Logger.h>
#include <UnityCore/GLibWrapper.h>

namespace unity
{

namespace
{
nux::logging::Logger logger("unity.imtextentry");
}

NUX_IMPLEMENT_OBJECT_TYPE(IMTextEntry);

IMTextEntry::IMTextEntry()
: TextEntry("", NUX_TRACKER_LOCATION)
{
  mouse_up.connect(sigc::mem_fun(this, &IMTextEntry::OnMouseButtonUp));
}

bool IMTextEntry::InspectKeyEvent(unsigned int event_type,
                                  unsigned int keysym,
                                  const char* character)
{
  nux::Event const& event = nux::GetGraphicsDisplay()->GetCurrentEvent();
  bool need_to_filter_event = TryHandleSpecial(event);

  if (need_to_filter_event)
    need_to_filter_event = TextEntry::InspectKeyEvent(event_type, keysym, character);

  return need_to_filter_event;
}

bool IMTextEntry::TryHandleSpecial(nux::Event const& event)
{
  /* If there is preedit, handle the event else where, but we
     want to be able to copy/paste while ibus is active */
  if (!preedit_.empty())
    return true;

  if (event.type != NUX_KEYDOWN)
    return false;

  unsigned int keyval = event.GetKeySym();
  bool shift = event.GetKeyModifierState(KEY_MODIFIER_SHIFT);
  bool ctrl = event.GetKeyModifierState(KEY_MODIFIER_CTRL);
  bool super = event.GetKeyModifierState(KEY_MODIFIER_SUPER);
  bool alt = event.GetKeyModifierState(KEY_MODIFIER_ALT);

  if ((ctrl && !shift && keyval == NUX_VK_x) ||    // Ctrl + X
      (shift && !ctrl && keyval == NUX_VK_DELETE)) // Shift + Del
  {
    Cut();
  }
  else if (ctrl && !shift && (keyval == NUX_VK_c || keyval == NUX_VK_INSERT))  // Ctrl + C / Ins
  {
    Copy();
  }
  else if ((ctrl && !shift && keyval == NUX_VK_v) ||   // Ctrl + V
           (shift && !ctrl && keyval == NUX_VK_INSERT)) // Shift + Ins
  {
    Paste();
  }
  else if (ctrl)
  {
    if (keyval == NUX_VK_LEFT || keyval == NUX_VK_RIGHT || // Ctrl + Move keys
        keyval == NUX_VK_HOME || keyval == NUX_VK_END || // Ctrl + Home / End
        keyval == NUX_VK_BACKSPACE || keyval == NUX_VK_DELETE || // Ctrl + Backspace / Delete
        keyval == NUX_VK_a) // Ctrl + A
    {
      return true;
    }
  }
  else if (!alt && !super)
  {
    return true;
  }

  return false;
}

void IMTextEntry::Cut()
{
  Copy();
  DeleteSelection();
  QueueRefresh (true, true);
}

void IMTextEntry::Copy()
{
  int start=0, end=0;
  if (GetSelectionBounds(&start, &end))
  {
    GtkClipboard* clip = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    gtk_clipboard_set_text(clip, text_.c_str() + start, end - start);
  }
}

void IMTextEntry::Paste(bool primary)
{
  GdkAtom origin = primary ? GDK_SELECTION_PRIMARY : GDK_SELECTION_CLIPBOARD;
  GtkClipboard* clip = gtk_clipboard_get(origin);

  auto callback = [](GtkClipboard* clip, const char* text, gpointer user_data)
   {
     IMTextEntry* self = static_cast<IMTextEntry*>(user_data);
     if (text)
      self->InsertText(std::string(text));
   };

  gtk_clipboard_request_text(clip, callback, this);
}

void IMTextEntry::InsertText(std::string const& text)
{
  DeleteSelection();

  if (!text.empty())
  {
    std::string new_text(GetText());
    new_text.insert(cursor_, text);

    int cursor = cursor_;
    SetText(new_text.c_str());
    SetCursor(cursor + text.length());
    QueueRefresh (true, true);
  }
}

void IMTextEntry::OnMouseButtonUp(int x, int y, unsigned long bflags, unsigned long kflags)
{
  int button = nux::GetEventButton(bflags);

  if (button == 2)
  {
    SetCursor(XYToTextIndex(x,y));
    Paste(true);
  }
}

bool IMTextEntry::im_preedit()
{
  return !preedit_.empty();
}
}
