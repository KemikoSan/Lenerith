#define LENERITH_EXPORT

#include <SDL3/SDL_render.h>

#include <Lenerith/UI/Button.hpp>

Lenerith::Button::Button(const std::string &text, const SDL_FRect &shape, const std::function<void()> &callback)
    : text(text), shape(shape), callback(callback) {
  SDL_Surface *surface = TTF_RenderText_Blended(font, text.c_str(), text.size(), SDL_Color{0, 0, 0, 255});
  // texture = SDL_CreateTextureFromSurface(Engine, surface);
  // SDL_RenderTexture();
}

Lenerith::Button::~Button() {
  SDL_DestroyTexture(texture);
}

void Lenerith::Button::press() {
  callback();
}
