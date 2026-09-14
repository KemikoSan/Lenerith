#pragma once

#include "SDL3/SDL_render.h"

#include "Lenerith/Entity/Entity.h"
#include <Lenerith/Animation.h>
#include <Lenerith/Camera.h>
#include <Lenerith/Core/Audio.h>
#include <Lenerith/DLL.h>
#include <Lenerith/Math/Vector2.h>

namespace Lenerith {
class LENERITH_API Player : public Entity {
public:
  Player(const Vector2 &position, SDL_Texture *texture);
  virtual void update() = 0;
  virtual ~Player();
};
}; // namespace Lenerith
