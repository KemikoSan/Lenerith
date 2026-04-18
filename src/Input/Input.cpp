#define LENERITH_EXPORT

#include "Lenerith/Input/InputMap.h"
#include <Lenerith/Input/Input.h>

Lenerith::Input &Lenerith::Input::instance() {
  static Lenerith::Input instance;
  return instance;
}

bool Lenerith::Input::isKeyDown(Keyboard key) const {
  return keys[static_cast<int>(key)];
}

void Lenerith::Input::setKey(int key, bool down) {
  keys[key] = down;
}

bool Lenerith::Input::isButtonPressed(SDL_JoystickID id, Gamepad button) const {
  if (id >= gamepadsNum.size()) {
    return false;
  }
  auto it = gamepads.find(gamepadsNum[id]);
  bool pressed = it->second.buttons[static_cast<int>(button)] && !it->second.prevButtons[static_cast<int>(button)];
  return it->second.buttons[static_cast<int>(button)] && !it->second.prevButtons[static_cast<int>(button)];
}

bool Lenerith::Input::isButtonDown(SDL_JoystickID id, Gamepad button) const {
  if (id >= gamepadsNum.size()) {
    return false;
  }
  auto it = gamepads.find(gamepadsNum[id]);
  return it->second.buttons[static_cast<int>(button)];
}

float Lenerith::Input::getAxis(SDL_JoystickID id, Gamepad axis) const {
  if (id >= gamepadsNum.size()) {
    return 0.f;
  }
  SDL_JoystickID device_id = gamepads.find(gamepadsNum[id])->first;
  return gamepads.at(device_id).axes[static_cast<int>(axis)];
}

void Lenerith::Input::setButton(SDL_JoystickID id, int button, bool down) {
  gamepads.at(id).buttons[button] = down;
}

void Lenerith::Input::setAxis(SDL_JoystickID id, int axis, float value) {
  gamepads.at(id).axes[axis] = value;
}

void Lenerith::Input::update() {
  for (auto &[id, pad] : gamepads) {
    pad.prevButtons = pad.buttons;
  }
}
