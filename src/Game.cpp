#include "Lenerith/Core/Engine.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_timer.h"
#include <Lenerith/Core/Game.h>

float Lenerith::Game::getDeltaTime() {
  static Uint64 lastCounter = SDL_GetPerformanceCounter();
  Uint64 currentCounter = SDL_GetPerformanceCounter();
  Uint64 frequency = SDL_GetPerformanceFrequency();
  float deltaTime =
      (currentCounter - lastCounter) / static_cast<float>(frequency);
  lastCounter = currentCounter;
  return deltaTime;
}

Lenerith::Game::Game(Lenerith::Engine &engine) : engine(engine) {}

void Lenerith::Game::run() {
  isRunning = true;
  isPaused = false;
  Renderer *renderer = engine.getRenderer();
  SDL_FRect rectagle{.x = 100, .y = 100, .w = 100, .h = 100};

  while (isRunning) {
    float deltatime = getDeltaTime();
    engine.pollEvents();
    handleEvents();
    renderer->renderClear();
    SDL_SetRenderDrawColor(renderer->SDLrenderer, 255, 255, 255, 255);
    SDL_RenderRect(renderer->SDLrenderer, &rectagle);
    if (!isPaused) {
      rectagle.x += 100 * deltatime;
      rectagle.y += 100 * deltatime;
    }
    renderer->renderPresent();
  }
}

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
      SDL_Log("%d", isPaused);
      break;
    case EventType::INPUT:
      break;
    }
    engine.eventQueue.pop();
  }
}
