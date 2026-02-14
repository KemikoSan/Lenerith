#include <Lenerith/Entity/Object.h>
#include <Lenerith/Input/Input.h>
#include <Lenerith/Vector2.h>

Lenerith::Object::Object(const Vector2 &position, SDL_Texture *texture) {
  this->position = position;
  this->texture = texture;
}

void Lenerith::Object::update(float deltatime) {
  auto &input = Input::instance();
  if (input.isKeyDown(Keyboard::LEFT) || input.getAxis(0, Gamepad::LEFT_AXIS_X) < -0.10f) {
    position.x -= 100 * deltatime;
  }
  if (input.isKeyDown(Keyboard::RIGHT) || input.getAxis(0, Gamepad::LEFT_AXIS_X) > 0.10f) {
    position.x += 100 * deltatime;
  }
  if (input.isKeyDown(Keyboard::DOWN) || input.getAxis(0, Gamepad::LEFT_AXIS_Y) > 0.10f) {
    position.y += 100 * deltatime;
  }
  if (input.isKeyDown(Keyboard::UP) || input.getAxis(0, Gamepad::LEFT_AXIS_Y) < -0.10f) {
    position.y -= 100 * deltatime;
  }
}

Lenerith::Object::~Object() {}
