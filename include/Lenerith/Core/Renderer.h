#pragma once

#include <SDL3/SDL_render.h>

#include <Lenerith/Core/Window.h>
#include <Lenerith/DLL.h>

namespace Lenerith {
class LENERITH_API Renderer {
private:
  SDL_Renderer *SDLrenderer = nullptr;

public:
  Renderer(const Lenerith::Window &window);
  ~Renderer();
  SDL_Renderer *getSDLRenderer();
  void renderTexture(SDL_Texture *texture, const SDL_FRect *srcrect, const SDL_FRect *dstrect);
  void renderTextureRotated(SDL_Texture *texture, const SDL_FRect *srcrect, const SDL_FRect *dstrect, double angle, const SDL_FPoint *center,
                            SDL_FlipMode flip);
  void renderClear();
  void renderPresent();
};
}; // namespace Lenerith
