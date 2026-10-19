#pragma once

#include <array>

#include <SDL3/SDL_gamepad.h>

struct GamepadState {
  SDL_Gamepad *gamepad = nullptr;
  SDL_GamepadType type;
  std::array<bool, 32> buttons{};
  std::array<bool, 32> prevButtons{};
  std::array<float, 8> axes{};
};
