#pragma once

namespace Lenerith {
class Entity {
public:
  virtual void update() = 0;
  virtual void render() = 0;
  virtual ~Entity() = 0;
};
}; // namespace Lenerith
