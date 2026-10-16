#define LENERITH_EXPORT

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_gamepad.h>
#include <SDL3/SDL_video.h>

#include <Lenerith/Core/Config.hpp>
#include <Lenerith/Core/Engine.hpp>
#include <Lenerith/Core/Window.hpp>
#include <Lenerith/Input/Input.hpp>

Lenerith::Engine::Engine() : window(), renderer(window) {
  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMEPAD)) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Init Error", SDL_GetError(), nullptr);
  }
}

Lenerith::Engine::~Engine() {
  SDL_Quit();
}

void Lenerith::Engine::pollEvents() {
  SDL_Event event;
  Input &input = Input::instance();
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_EVENT_QUIT:
      eventQueue.push(EventType::QUIT);
      break;
    case SDL_EVENT_KEY_DOWN:
      input.setKey(event.key.scancode, true);
      break;
    case SDL_EVENT_KEY_UP:
      input.setKey(event.key.scancode, false);
      break;
    case SDL_EVENT_GAMEPAD_BUTTON_DOWN:
      input.setButton(event.gdevice.which, event.gbutton.button, true);
      break;
    case SDL_EVENT_GAMEPAD_BUTTON_UP:
      input.setButton(event.gdevice.which, event.gbutton.button, false);
      break;
    case SDL_EVENT_GAMEPAD_AXIS_MOTION:
      input.setAxis(event.gdevice.which, event.gaxis.axis, event.gaxis.value / 36700.f);
      break;
    case SDL_EVENT_GAMEPAD_ADDED: {
      SDL_Gamepad *gamepad = SDL_OpenGamepad(event.gdevice.which);
      input.gamepads.insert(std::make_pair(event.gdevice.which, gamepad));
      input.gamepadsId.push_back(event.gdevice.which);
      eventQueue.push(EventType::GAMEPAD_ADDED);
      break;
    }
    case SDL_EVENT_GAMEPAD_REMOVED:
      SDL_CloseGamepad(SDL_GetGamepadFromID(event.gdevice.which));
      input.gamepads.erase(event.gdevice.which);
      input.gamepadsId.erase(std::find(input.gamepadsId.begin(), input.gamepadsId.end(), event.gdevice.which));
      eventQueue.push(EventType::GAMEPAD_REMOVED);
      break;
    case SDL_EVENT_WINDOW_RESIZED:
      SDL_GetWindowSize(window.getSDLWindow(), &Config::instance().screenWidth, &Config::instance().screenHeight);
    default:
      break;
    }
  }
}

Lenerith::Renderer *Lenerith::Engine::getRenderer() {
  return &renderer;
}

Lenerith::Window *Lenerith::Engine::getWindow() {
  return &window;
}
