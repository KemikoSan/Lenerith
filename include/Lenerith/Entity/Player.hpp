#pragma once

#include "SDL3/SDL_render.h"

#include "Lenerith/Entity/Entity.hpp"
#include <Lenerith/Animation.hpp>
#include <Lenerith/Camera.hpp>
#include <Lenerith/Core/Audio.hpp>
#include <Lenerith/DLL.hpp>
#include <Lenerith/Math/Vector2.hpp>

namespace Lenerith {
class LENERITH_API Player : public Entity {
public:
  Player(const Vector2 &position, SDL_Texture *texture);
  virtual void update() = 0;
  virtual ~Player();
};
}; // namespace Lenerith
