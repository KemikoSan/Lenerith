#pragma once

#include <Lenerith/Core/Window.h>
#include <SDL3/SDL_render.h>

namespace Lenerith {
class Renderer {
public:
  SDL_Renderer *SDLrenderer;
  Renderer(const Lenerith::Window &window);
  ~Renderer();
  void renderClear();
  void renderPresent();
};
}; // namespace Lenerith
