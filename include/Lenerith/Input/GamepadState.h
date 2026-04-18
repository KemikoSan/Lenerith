#pragma once

#include "SDL3/SDL_gamepad.h"
#include <array>

struct GamepadState {
  SDL_Gamepad *handle = nullptr;
  SDL_GamepadType type;
  std::array<bool, 32> buttons;
  std::array<bool, 32> prevButtons;
  float axes[8] = {};
};
