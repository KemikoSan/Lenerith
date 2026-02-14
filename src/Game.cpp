#include "Lenerith/Core/Engine.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_timer.h"
#include <Lenerith/Core/Game.h>
#include <Lenerith/Input/Input.h>

float Lenerith::Game::getDeltaTime() {
  static Uint64 lastCounter = SDL_GetPerformanceCounter();
  Uint64 currentCounter = SDL_GetPerformanceCounter();
  Uint64 frequency = SDL_GetPerformanceFrequency();
  float deltaTime = (currentCounter - lastCounter) / static_cast<float>(frequency);
  lastCounter = currentCounter;
  return deltaTime;
}

Lenerith::Game::Game(Lenerith::Engine &engine) : engine(engine) {}

void Lenerith::Game::run() {
  isRunning = true;
  isPaused = false;

  Renderer *renderer = engine.getRenderer();
  scenes.emplace_back(renderer->SDLrenderer, "");

  while (isRunning) {
    float deltatime = getDeltaTime();
    engine.pollEvents();
    handleEvents();

    if (!isPaused) {
      scenes[currentScene].update(deltatime);
    }

    renderer->renderClear();
    scenes[currentScene].render();
    renderer->renderPresent();
  }
}

// every event that is not input
void Lenerith::Game::handleEvents() {
  for (size_t i = 0; i < engine.eventQueue.size(); i++) {
    Event event = engine.eventQueue.front();
    switch (event.type) {
    case EventType::QUIT:
      isRunning = false;
      return;
      break;
    case EventType::PAUSE:
      isPaused = !isPaused;
      break;
    case EventType::INPUT:
      break;
    case EventType::GAMEPAD_ADDED:
      break;
    case EventType::GAMEPAD_REMOVED:
      break;
    }
    engine.eventQueue.pop();
  }
}
