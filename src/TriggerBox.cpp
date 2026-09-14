#define LENERITH_EXPORT

#include <functional>

#include "SDL3/SDL_rect.h"

#include "Lenerith/Entity/Player.h"
#include "Lenerith/Math/Vector2.h"
#include <Lenerith/TriggerBox.h>

Lenerith::TriggerBox::TriggerBox(const Vector2 &position, const Vector2 &size, const std::function<void()> &callback)
    : area(SDL_FRect{position.x, position.y, size.x, size.y}), callback(callback) {};

void Lenerith::TriggerBox::hasCollide(const Player &player) {
  SDL_FRect rect = {.x = player.getPosition().x, .y = player.getPosition().y, .w = 450.f, .h = 490.f};
  if (SDL_HasRectIntersectionFloat(&rect, &area)) {
    callback();
  }
}

void Lenerith::TriggerBox::Render(SDL_Renderer *renderer, Camera *camera) {
  SDL_FRect box = {.x = area.x - camera->viewport.x, .y = area.y - camera->viewport.y, .w = area.w, .h = area.h};
  SDL_RenderRect(renderer, &box);
}

const SDL_FRect *Lenerith::TriggerBox::getArea() {
  return &area;
}
