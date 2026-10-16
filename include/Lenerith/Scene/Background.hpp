#pragma once

#include <SDL3/SDL_render.h>

#include <Lenerith/DLL.hpp>

namespace Lenerith {
struct Background {
  SDL_Texture *texture;
  float paralax;
};
} // namespace Lenerith
