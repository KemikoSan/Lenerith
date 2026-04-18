#pragma once

#include <SDL3/SDL_render.h>

#include <Lenerith/Core/Window.h>
#include <Lenerith/export.h>

namespace Lenerith {
class LENERITH_API Renderer {
public:
  SDL_Renderer *SDLrenderer;
  Renderer(const Lenerith::Window &window);
  ~Renderer();
  void renderClear();
  void renderPresent();
};
}; // namespace Lenerith
