#include "Lenerith/Core/Engine.h"
#include "Lenerith/Entity/Player.h"
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
  SDL_Texture *walk = IMG_LoadTexture(renderer->SDLrenderer, "guncat.png");
  SDL_Texture *idle = IMG_LoadTexture(renderer->SDLrenderer, "idle.png");

  Player player(walk, idle, {100, 300}, 0);
  Player player2(walk, idle, {400, 300}, 1);
  Camera camera;
  Lenerith::Input &input = Input::instance();

  // MUSIC
  Audio &audio = Audio::instance();
  // const SDL_AudioSpec *specs = audio.getSpec();
  // SDL_IOStream *stream = SDL_IOFromFile("cyber.mp3", "r");
  // MIX_Audio *music = MIX_LoadAudio_IO(audio.getMixer(), stream, false, true);
  // audio.playMusic(music);
  // MUSIC
  while (isRunning) {
    float deltatime = getDeltaTime();
    input.update();
    engine.pollEvents();
    handleEvents();
    audio.clearTracks();

    if (!isPaused) {
      scenes[currentScene].update(deltatime);
      player.update(deltatime);
      player2.update(deltatime);
      camera.update(player.getPosiotion());
    }

    renderer->renderClear();
    scenes[currentScene].render(&camera);
    player.render(renderer->SDLrenderer, &camera);
    player2.render(renderer->SDLrenderer, &camera);

    // DEBUB
    SDL_SetRenderDrawColor(renderer->SDLrenderer, 255, 255, 255, 255);
    SDL_RenderDebugText(renderer->SDLrenderer, 10.f, 10.f, "Lenerith-Tech");
    SDL_RenderDebugText(renderer->SDLrenderer, 10.f, 20.f, SDL_GetRendererName(renderer->SDLrenderer));
    SDL_RenderDebugText(renderer->SDLrenderer, 10.f, 30.f, std::format("FPS: {}", std::floor(1.f / deltatime)).c_str());
    // DEBUG

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
