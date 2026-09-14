#define LENERITH_EXPORT

#include <Lenerith/UI/Text.h>

Lenerith::Text::Text(const std::string &text, const Vector2 &position, TTF_Font *font, const SDL_Color &color)
    : text(text), position(position), font(font), color(color) {
  surface = TTF_RenderText_Blended(font, text.c_str(), text.size(), SDL_Color{0, 0, 0, 255});
}

Lenerith::Text::~Text() {
  SDL_DestroySurface(surface);
}

void Lenerith::Text::setText(const std::string &text) {
  this->text = text;
  textChanged = true;
}

void Lenerith::Text::setColor(const SDL_Color &color) {
  this->color = color;
}

void Lenerith::Text::update() {
  if (textChanged) {
    SDL_DestroySurface(surface);
    surface = TTF_RenderText_Blended(font, text.c_str(), text.size(), SDL_Color{0, 0, 0, 255});
    textChanged = false;
  }
}
