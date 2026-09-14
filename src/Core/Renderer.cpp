#define LENERITH_EXPORT

#include "SDL3/SDL_render.h"

#include <Lenerith/Core/Config.h>
#include <Lenerith/Core/Renderer.h>

Lenerith::Renderer::Renderer(const Lenerith::Window &window) : SDLrenderer(SDL_CreateRenderer(window.getSDLWindow(), nullptr)) {
  SDL_SetRenderVSync(SDLrenderer, Config::instance().vsync);
}

Lenerith::Renderer::~Renderer() {
  SDL_DestroyRenderer(SDLrenderer);
}

SDL_Renderer *Lenerith::Renderer::getSDLRenderer() {
  return SDLrenderer;
}

void Lenerith::Renderer::renderTexture(SDL_Texture *texture, const SDL_FRect *srcrect, const SDL_FRect *dstrect) {
  SDL_RenderTexture(SDLrenderer, texture, srcrect, dstrect);
}

void Lenerith::Renderer::renderTextureRotated(SDL_Texture *texture, const SDL_FRect *srcrect, const SDL_FRect *dstrect, double angle,
                                              const SDL_FPoint *center, SDL_FlipMode flip) {
  SDL_RenderTextureRotated(SDLrenderer, texture, srcrect, dstrect, angle, center, flip);
}

void Lenerith::Renderer::renderClear() {
  SDL_SetRenderDrawColor(SDLrenderer, 0, 0, 0, 255);
  SDL_RenderClear(SDLrenderer);
}

void Lenerith::Renderer::renderPresent() {
  SDL_RenderPresent(SDLrenderer);
}
