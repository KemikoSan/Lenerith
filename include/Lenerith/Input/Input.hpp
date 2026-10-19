#include <array>
#include <unordered_map>
#include <vector>

#include <SDL3/SDL_joystick.h>

#include <Lenerith/DLL.hpp>
#include <Lenerith/Input/GamepadState.hpp>
#include <Lenerith/Input/InputMap.hpp>

namespace Lenerith {
class LENERITH_API Input {
private:
  std::array<bool, 512> keys{};
  std::array<bool, 512> prevkeys{};

public:
  static Input &instance();
  std::unordered_map<SDL_JoystickID, GamepadState> gamepads;
  std::vector<SDL_JoystickID> gamepadsId;
  bool isKeyPressed(Keyboard key) const;
  bool isKeyDown(Keyboard key) const;
  void setKey(int key, bool down);
  bool isButtonPressed(SDL_JoystickID id, Gamepad button) const;
  bool isButtonDown(SDL_JoystickID id, Gamepad button) const;
  void setButton(SDL_JoystickID id, int btn, bool down);
  float getAxis(SDL_JoystickID id, Gamepad axis) const;
  void setAxis(SDL_JoystickID id, int axis, float value);
  void update();

  Input &operator=(const Input &) = delete;
  Input operator=(const Input) = delete;
};
}; // namespace Lenerith
