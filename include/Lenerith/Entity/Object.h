#pragma once

#include "SDL3/SDL_render.h"

#include "Lenerith/Entity/Entity.h"
#include "Lenerith/Math/Vector2.h"
#include <Lenerith/DLL.h>

namespace Lenerith {
class LENERITH_API Object : public Lenerith::Entity {
public:
  Object(const Vector2 &position, SDL_Texture *texture);
  ~Object() override;
  void update() override;
};
}; // namespace Lenerith
