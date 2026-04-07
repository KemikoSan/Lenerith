#include <Lenerith/Entity/Entity.h>

Lenerith::Entity::Entity(const Vector2 &position, SDL_Texture *texture) : position(position), texture(texture) {};
Lenerith::Entity::~Entity() = default;
