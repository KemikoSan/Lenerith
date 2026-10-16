#define LENERITH_EXPORT

#include <Lenerith/Entity/Entity.hpp>

Lenerith::Entity::Entity(const Vector2 &position, SDL_Texture *texture) : position(position), texture(texture) {};
Lenerith::Entity::~Entity() = default;

SDL_Texture *Lenerith::Entity::getTexture() const {
  return texture;
}

void Lenerith::Entity::setTexture(SDL_Texture *texture) {
  this->texture = texture;
}

const Lenerith::Vector2 &Lenerith::Entity::getPosition() const {
  return position;
}

const SDL_FRect *Lenerith::Entity::getShape() const {
  return &shape;
};
