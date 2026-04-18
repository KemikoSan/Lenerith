#pragma once

#include <functional>

#include "SDL3/SDL_rect.h"

#include "Lenerith/Entity/Player.h"
#include "Lenerith/Math/Vector2.h"
#include <Lenerith/export.h>

namespace Lenerith {
class LENERITH_API TriggerBox {
private:
  SDL_FRect area;
  std::function<void()> callback;

public:
  TriggerBox(const Vector2 &position, const Vector2 &size, const std::function<void()> &callback);
  void hasCollide(const Player &entity);
  // use for debug only
  void Render(SDL_Renderer *renderer, Camera *camera);
  const SDL_FRect *getArea();
};
}; // namespace Lenerith
