#pragma once

#include <Lenerith/Vector2.h>

namespace lenerith {
class Player {
  Vector2 position;
  Player();
  virtual void update() = 0;
  virtual ~Player();
};
}; // namespace lenerith
