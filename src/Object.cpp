#include "Lenerith/Vector2.h"
#include <Lenerith/Entity/Object.h>

Lenerith::Object::Object(const Vector2 &position, SDL_Texture *texture) {
  this->position = position;
  this->texture = texture;
}

void Lenerith::Object::update(float deltatime) {
  position.x += 50 * deltatime;
}

Lenerith::Object::~Object() {}
