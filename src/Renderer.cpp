#include "SDL3/SDL_render.h"
#include <Lenerith/Core/Renderer.h>

Lenerith::Renderer::Renderer(const Lenerith::Window &window) : SDLrenderer(SDL_CreateRenderer(window.getSDLWindow(), nullptr)) {
  SDL_SetRenderVSync(SDLrenderer, 1);
}

Lenerith::Renderer::~Renderer() {
  SDL_DestroyRenderer(SDLrenderer);
}

void Lenerith::Renderer::renderClear() {
  SDL_SetRenderDrawColor(SDLrenderer, 0, 0, 0, 255);
  SDL_RenderClear(SDLrenderer);
}

void Lenerith::Renderer::renderPresent() {
  SDL_RenderPresent(SDLrenderer);
}
