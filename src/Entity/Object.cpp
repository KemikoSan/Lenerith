#define LENERITH_EXPORT

#include <Lenerith/Entity/Object.hpp>
#include <Lenerith/Input/Input.hpp>
#include <Lenerith/Math/Vector2.hpp>

Lenerith::Object::Object(const Vector2 &position, SDL_Texture *texture) {
  this->position = position;
  this->texture = texture;
}

void Lenerith::Object::update() {}

Lenerith::Object::~Object() {}
