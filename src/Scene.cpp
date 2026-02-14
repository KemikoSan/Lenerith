#include "Lenerith/Vector2.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include <Lenerith/Entity/Object.h>
#include <Lenerith/Scene.h>
#include <SDL3_image/SDL_image.h>
#include <filesystem>
#include <memory>
// #include <fstream>

Lenerith::Scene::Scene(SDL_Renderer *render, const std::filesystem::path &path) : renderer(render), path(path) {
  // DEBUG ONLY
  backgrounds.emplace_back(IMG_LoadTexture(renderer, "background.jpg"));
  entities.emplace_back(std::make_unique<Lenerith::Object>(Vector2(200.f, 200.f), IMG_LoadTexture(renderer, "main.png")));
  // DEBUG ONLY
}

void Lenerith::Scene::update(float deltatime) {
  for (auto &entity : entities) {
    entity->update(deltatime);
  }
}

void Lenerith::Scene::render() {
  for (auto &background : backgrounds) {
    SDL_RenderTexture(renderer, background, nullptr, nullptr); // Need background FRect or Not???
  }

  for (auto &entity : entities) {
    SDL_Texture *texture = entity->getTexture();
    Vector2 position = entity->getPosition();
    SDL_FRect rect{position.x, position.y, (float)texture->w, (float)texture->h};
    SDL_RenderTexture(renderer, texture, nullptr, &rect);
  }
}

// Realease binary file loading
// void Lenerith::Scene::load() { std::ifstream file(path, std::ios::binary); }
