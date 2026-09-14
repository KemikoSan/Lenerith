#define LENERITH_EXPORT

#include <cstddef>
#include <format>
#include <string>

#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>

#include <Lenerith/Animation.h>
#include <Lenerith/Core/Engine.h>
#include <Lenerith/Core/Game.h>
#include <Lenerith/Core/Time.h>
#include <Lenerith/Core/Window.h>
#include <Lenerith/Input/Input.h>
#include <Lenerith/Scene/SceneManager.h>

Lenerith::Game::Game() {}

void Lenerith::Game::run() {
  Engine engine;
  Window *window = engine.getWindow();
  window->setTitle("Game");
  Renderer *renderer = engine.getRenderer();
  Input &input = Input::instance();
  Audio &audio = Audio::instance();
  SceneManager sceneManager;

  isRunning = true;
  isPaused = false;

  // Loading scenes
  sceneManager.loadScenes();
  sceneManager.getCurrentScene()->load();

  // SDL_Texture *walk = IMG_LoadTexture(renderer->SDLrenderer, "guncat.png");
  // SDL_Texture *idle = IMG_LoadTexture(renderer->SDLrenderer, "idle.png");
  //  Loading player and camera -> need change ?
  //  Player player(walk, idle, {400, 300}, 0);
  //  Player player2(walk, idle, {400, 300}, 1);
  Camera camera;

  // Load and play music
  // SDL_IOStream *stream = SDL_IOFromFile("cyber.mp3", "r");
  // MIX_Audio *music = MIX_LoadAudio_IO(audio.getMixer(), stream, false, true);
  // audio.playMusic(music);
  // MUSIC
  //

  // Main Loop
  while (isRunning) {
    // Update subsystems
    Time::update();
    input.update();
    audio.clearTracks();
    engine.pollEvents();
    handleEvents();

    // Update Stage
    if (!isPaused) {
      sceneManager.scenes[sceneManager.currentScene].update();
      // player.update();
      // player2.update();
      // camera.update(player.getPosition());
    }

    // Render Stage
    renderer->renderClear();
    sceneManager.scenes[sceneManager.currentScene].render(&camera);
    // player.render(renderer->SDLrenderer, &camera);
    // player2.render(renderer->SDLrenderer, &camera);

    // DEBUB
    SDL_SetRenderDrawColor(renderer->getSDLRenderer(), 255, 255, 255, 255);
    SDL_RenderDebugText(renderer->getSDLRenderer(), 10.f, 10.f, "Lenerith-Tech");
    SDL_RenderDebugText(renderer->getSDLRenderer(), 10.f, 20.f, SDL_GetRendererName(renderer->getSDLRenderer());
    SDL_RenderDebugText(renderer->getSDLRenderer(), 10.f, 30.f, std::format("FPS: {}", std::floor(1.f / Time::unscaledDeltatime)).c_str());
    // DEBUG

    renderer->renderPresent();
    // End Render Stage
  }
}

// every event that is not input (Some of this should user set :o)
void Lenerith::Game::handleEvents() {
  for (size_t i = 0; i < eventQueue.size(); i++) {
    Event event = eventQueue.front();
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
    eventQueue.pop();
  }
}
