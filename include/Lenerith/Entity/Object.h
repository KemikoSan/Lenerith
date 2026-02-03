#include "Lenerith/Entity/Entity.h"
#include "Lenerith/Vector2.h"
#include "SDL3/SDL_render.h"

namespace Lenerith {
class Object : public Lenerith::Entity {
public:
  Object(const Vector2 &position, SDL_Texture *texture);
  ~Object() override;
  void update(float deltatime) override;
};
}; // namespace Lenerith
