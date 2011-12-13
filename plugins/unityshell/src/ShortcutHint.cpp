// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2011 Canonical Ltd
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
 * Authored by: Andrea Azzarone <azzaronea@gmail.com>
 */

#include "ShortcutHint.h"

#include <core/core.h> // Compiz...
#include <NuxCore/Logger.h>

#include "ShortcutHintPrivate.h"

namespace unity
{
namespace shortcut
{
namespace
{
  nux::logging::Logger logger("unity.shortcut");
} // anonymouse namespace 

// Ctor
Hint::Hint(std::string const& category,
           std::string const& prefix,
           std::string const& postfix,
           std::string const& description,
           OptionType const type,
           std::string const& arg1, 
           std::string const& arg2,
           std::string const& arg3)
  : AbstractHint(category, prefix, postfix, description, type, arg1, arg2, arg3)
{
}

// Dtor
Hint::~Hint()
{
}

/*
 * Gets and fills the shortcut value. 
 * Returns true if everything was OK, returns false otherwise.
 * Use member property Value to get it.
 */
bool Hint::Fill()
{
  switch(Type())
  {
    case COMPIZ_OPTION:
    {
      // Arg1 = Plugin name
      // Arg2 = Option name
      CompPlugin* p = CompPlugin::find(Arg1().c_str());

      if (!p) 
        return false;

      foreach (CompOption &opt, p->vTable->getOptions())
      {
          if (opt.name() == Arg2())
          {
            std::string temp = impl::FixShortcutFormat(opt.value().action().keyToString());
            if (Value() != temp)
            {
              Value = temp;
              Shortkey = Prefix() + Value() + Postfix();
            }
              
            return true;
          }
      }

      break;
    }
    case HARDCODED_OPTION:
      if (Value != Arg1())
      {
        Value = Arg1();
        Shortkey = Prefix() + Value() + Postfix();
      }
      return true;

    default:
      LOG_WARNING(logger) << "Unable to find the option type" << Type(); 
  }

  return false;
}

} // namespace shortcut
} // namespace unity
