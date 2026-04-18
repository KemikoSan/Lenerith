#pragma once

#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"

#include "Lenerith/Math/Vector2.h"
#include <Lenerith/export.h>

namespace Lenerith {
class LENERITH_API Entity {
protected:
  SDL_Texture *texture;
  Vector2 position{0, 0};
  SDL_FRect shape;

public:
  virtual void update() = 0;
  Entity() = default;
  Entity(const Vector2 &position, SDL_Texture *texture);
  virtual ~Entity();
  SDL_Texture *getTexture() const {
    return texture;
  }

  void setTexture(SDL_Texture *texture) {
    this->texture = texture;
  }

  const Vector2 &getPosition() const {
    return position;
  }

  const SDL_FRect *getShape() const {
    return &shape;
  };
};
}; // namespace Lenerith
