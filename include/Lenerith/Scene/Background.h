#pragma once

#include <Lenerith/DLL.h>
#include <SDL3/SDL_render.h>

namespace Lenerith {
struct Background {
  SDL_Texture *texture;
  float paralax;
};
} // namespace Lenerith
