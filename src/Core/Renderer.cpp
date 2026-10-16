#define LENERITH_EXPORT

#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>

#include <Lenerith/Core/Config.hpp>
#include <Lenerith/Core/Renderer.hpp>

Lenerith::Renderer::Renderer(const Lenerith::Window &window) : SDLrenderer(SDL_CreateRenderer(window.getSDLWindow(), nullptr)) {
  SDL_SetRenderVSync(SDLrenderer, Config::instance().vsync);
}

Lenerith::Renderer::~Renderer() {
  SDL_DestroyRenderer(SDLrenderer);
}

SDL_Renderer *Lenerith::Renderer::getSDLRenderer() const {
  return SDLrenderer;
}

void Lenerith::Renderer::renderTexture(SDL_Texture *texture, const SDL_FRect *srcrect, const SDL_FRect *dstrect) const {
  SDL_RenderTexture(SDLrenderer, texture, srcrect, dstrect);
}

void Lenerith::Renderer::renderTextureRotated(SDL_Texture *texture, const SDL_FRect *srcrect, const SDL_FRect *dstrect, double angle,
                                              const SDL_FPoint *center, SDL_FlipMode flip) const {
  SDL_RenderTextureRotated(SDLrenderer, texture, srcrect, dstrect, angle, center, flip);
}

SDL_Texture *Lenerith::Renderer::loadTexture(std::string_view path) const {
  return IMG_LoadTexture(SDLrenderer, path.data());
}

void Lenerith::Renderer::renderClear() const {
  SDL_SetRenderDrawColor(SDLrenderer, 0, 0, 0, 255);
  SDL_RenderClear(SDLrenderer);
}

void Lenerith::Renderer::renderPresent() const {
  SDL_RenderPresent(SDLrenderer);
}
