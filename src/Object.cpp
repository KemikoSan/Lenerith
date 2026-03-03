#include <Lenerith/Entity/Object.h>
#include <Lenerith/Input/Input.h>
#include <Lenerith/Vector2.h>

Lenerith::Object::Object(const Vector2 &position, SDL_Texture *texture) {
  this->position = position;
  this->texture = texture;
}

void Lenerith::Object::update(float deltatime) {}

Lenerith::Object::~Object() {}
