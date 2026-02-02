#include "Lenerith/Core/Window.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_gamepad.h"
#include "SDL3/SDL_scancode.h"
#include <Lenerith/Core/Engine.h>

Lenerith::Engine::Engine(const Config &config)
    : window("lol", config), renderer(window) {
  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMEPAD)) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Init Error", SDL_GetError(),
                             nullptr);
  }
}

Lenerith::Engine::~Engine() { SDL_Quit(); }

void Lenerith::Engine::pollEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_EVENT_QUIT:
      eventQueue.push({.type = EventType::QUIT});
      break;
    case SDL_EVENT_KEY_DOWN:
      if (event.key.scancode == SDL_SCANCODE_P) {
        eventQueue.push({.type = EventType::PAUSE});
      }
      if (event.key.scancode == SDL_SCANCODE_ESCAPE) {
        eventQueue.push({.type = EventType::QUIT});
      }
      if (event.key.scancode == SDL_SCANCODE_F11) {
        window.toggleFullScreen();
      }
      break;
    case SDL_EVENT_GAMEPAD_BUTTON_DOWN:
      SDL_Log("%d", event.gbutton.button);
      break;
    case SDL_EVENT_GAMEPAD_AXIS_MOTION:
      SDL_Log("%f", event.gaxis.value / 32767.0f);
      break;
    case SDL_EVENT_GAMEPAD_ADDED:
      gamepads = SDL_OpenGamepad(event.gdevice.which);
      SDL_Log("%s", SDL_GetGamepadName(gamepads));
      break;
    case SDL_EVENT_GAMEPAD_REMOVED:
      break;
    default:
      break;
    }
  }
}

Renderer *Lenerith::Engine::getRenderer() { return &renderer; }
Window *Lenerith::Engine::getWindow() { return &window; }
