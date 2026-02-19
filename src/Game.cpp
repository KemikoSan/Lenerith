#include "Lenerith/Core/Engine.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_timer.h"
#include "SDL3_image/SDL_image.h"
#include <Lenerith/Animation.h>
#include <Lenerith/Core/Game.h>
#include <Lenerith/Input/Input.h>
#include <Lenerith/UI/UI.h>
#include <cstddef>
#include <format>
#include <string>

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
  SDL_Texture *guncat = IMG_LoadTexture(renderer->SDLrenderer, "guncat.png");
  Animation animation(guncat, 450, 490, 12, 15);

  while (isRunning) {
    float deltatime = getDeltaTime();
    engine.pollEvents();
    handleEvents();

    if (!isPaused) {
      scenes[currentScene].update(deltatime);
    }
    SDL_FRect frame = animation.Play(deltatime);
    SDL_FRect dest = {.x = 100.f, .y = 100.f, .w = 450.f, .h = 490.f};

    renderer->renderClear();
    scenes[currentScene].render();
    SDL_RenderTexture(renderer->SDLrenderer, animation.tileSet, &frame, &dest);

    SDL_RenderDebugText(renderer->SDLrenderer, 10.f, 10.f, "Lenerith-Tech");
    SDL_RenderDebugText(renderer->SDLrenderer, 10.f, 20.f, SDL_GetRendererName(renderer->SDLrenderer));
    SDL_RenderDebugText(renderer->SDLrenderer, 10.f, 30.f, std::format("FPS: {}", std::floor(1.f / deltatime)).c_str());
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
