#pragma once

#include <SDL3/SDL_render.h>

#include <Lenerith/Core/Window.hpp>
#include <Lenerith/DLL.hpp>

namespace Lenerith {
class LENERITH_API Renderer {
private:
  SDL_Renderer *SDLrenderer = nullptr;

public:
  Renderer(const Lenerith::Window &window);
  ~Renderer();
  SDL_Renderer *getSDLRenderer() const;
  void renderTexture(SDL_Texture *texture, const SDL_FRect *srcrect, const SDL_FRect *dstrect) const;
  void renderTextureRotated(SDL_Texture *texture, const SDL_FRect *srcrect, const SDL_FRect *dstrect, double angle, const SDL_FPoint *center,
                            SDL_FlipMode flip) const;
  SDL_Texture *loadTexture(std::string_view path) const;
  void destroyTexture(SDL_Texture *texture) const;
  void renderClear() const;
  void renderPresent() const;
};
}; // namespace Lenerith
