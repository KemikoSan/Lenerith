#pragma once

#include "Lenerith/Entity/Entity.h"
#include "Lenerith/Math/Vector2.h"
#include "SDL3/SDL_render.h"

namespace Lenerith {
class Object : public Lenerith::Entity {
public:
  Object(const Vector2 &position, SDL_Texture *texture);
  ~Object() override;
  void update() override;
};
}; // namespace Lenerith
