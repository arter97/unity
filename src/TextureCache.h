/*
 * Copyright (C) 2010 Canonical Ltd
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
 * Authored by Gordon Allott <gord.allott@canonical.com>
 */

#ifndef TEXTURECACHE_H
#define TEXTURECACHE_H
#include <Nux/Nux.h>
#include <string>
#include <map>
#include <vector>
#include <sigc++/sigc++.h>

/* Basically a nice simple texture cache system, you ask the cache for a texture by id
 * if the texture does not exist it calls the callback function you provide it with to create the
 * texture, then returns it.
 * you should remember to ref/unref the textures yourself however
 */

class TextureCache
{

public:
  // id, width, height, texture 
  typedef sigc::slot<void, const char *, int, int, nux::BaseTexture **> TextureCacheCallback;
  
  /* don't new this class, use getdefault */
  TextureCache();
  ~TextureCache();

  static TextureCache * GetDefault ();
  nux::BaseTexture * FindTexture (const char *texture_id, int width, int height, TextureCacheCallback slot);

protected:
  struct TexDestroyPayload
  {
    TextureCache *self;
    char         *texid;
  };

  char * Hash (const char *id, int width, int height);
  std::map<std::string, nux::BaseTexture *> _cache;
  static void *OnDestroyNotify (void *data);
};

#endif // TEXTURECACHE_H
