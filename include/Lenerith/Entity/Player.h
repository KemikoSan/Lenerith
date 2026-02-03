#pragma once

#include "Lenerith/Entity/Entity.h"
#include "SDL3/SDL_render.h"
#include <Lenerith/Vector2.h>

namespace lenerith {
class Player : public Lenerith::Entity {
  Player(const Vector2 &position, SDL_Texture *texture);
  virtual void update() = 0;
  virtual ~Player();
};
}; // namespace lenerith
