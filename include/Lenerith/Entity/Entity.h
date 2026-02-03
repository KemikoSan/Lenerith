#pragma once

#include "Lenerith/Vector2.h"
#include "SDL3/SDL_render.h"
namespace Lenerith {
class Entity {
protected:
  SDL_Texture *texture;
  Vector2 position{0, 0};

public:
  virtual void update(float deltatime) = 0;
  Entity() = default;
  Entity(const Vector2 &position, SDL_Texture *texture);
  virtual ~Entity();
  SDL_Texture *getTexture() const {
    return texture;
  }
  const Vector2 &getPosition() const {
    return position;
  }
};
}; // namespace Lenerith
