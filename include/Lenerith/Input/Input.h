#include "SDL3/SDL_joystick.h"
#include <Lenerith/Input/GamepadState.h>
#include <Lenerith/Input/InputMap.h>
#include <unordered_map>
#include <vector>

namespace Lenerith {
class Input {
private:
  bool keys[512] = {};

public:
  static Input &instance();
  std::unordered_map<SDL_JoystickID, GamepadState> gamepads;
  std::vector<SDL_JoystickID> gamepadsNum;
  bool isKeyDown(Keyboard key) const;
  void setKey(int key, bool down);
  bool isButtonDown(SDL_JoystickID id, Gamepad button) const;
  void setButton(SDL_JoystickID id, int btn, bool down);
  float getAxis(SDL_JoystickID id, Gamepad axis) const;
  void setAxis(SDL_JoystickID id, int axis, float value);

  Input &operator=(const Input &) = delete;
  Input operator=(const Input) = delete;
};
}; // namespace Lenerith
