#include "SDL3/SDL_render.h"
#include <Lenerith/UI/Button.h>

Button::Button(const std::string &text, const SDL_FRect &shape, const std::function<void()> &callback) : text(text), shape(shape), callback(callback) {}

Button::~Button() {
  SDL_DestroyTexture(texture);
}
