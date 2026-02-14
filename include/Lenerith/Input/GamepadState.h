#pragma once

#include "SDL3/SDL_gamepad.h"

struct GamepadState {
  SDL_Gamepad *handle = nullptr;
  SDL_GamepadType type;
  bool buttons[32] = {};
  float axes[8] = {};
};
