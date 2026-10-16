#define LENERITH_EXPORT

#include <filesystem>
#include <fstream>
#include <memory>

#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include <SDL3_image/SDL_image.h>

#include <Nlohmann/json.hpp>

#include <Lenerith/Core/Renderer.h>
#include <Lenerith/Entity/Entity.h>
#include <Lenerith/Entity/Object.h>
#include <Lenerith/Entity/Player.h>
#include <Lenerith/Math/Vector2.h>
#include <Lenerith/Scene/Background.h>
#include <Lenerith/Scene/Scene.h>

Lenerith::Scene::Scene(const std::filesystem::path &path) : path(path) {}

void Lenerith::Scene::update() {
  for (auto &entity : entities) {
    entity->update();
  }
}

void Lenerith::Scene::render(Renderer *renderer, Camera *camera) {
  for (auto &background : backgrounds) {
    if (background.texture) {
      SDL_FRect rect{-camera->viewport.x * background.paralax, -camera->viewport.y * background.paralax, static_cast<float>(background.texture->w),
                     static_cast<float>(background.texture->h)};
      renderer->renderTexture(background.texture, nullptr, &rect);
    }
  }

  for (auto &entity : entities) {
    SDL_Texture *texture = entity->getTexture();
    if (texture) {
      Vector2 position = entity->getPosition();
      SDL_FRect rect{position.x - camera->viewport.x, position.y - camera->viewport.y, static_cast<float>(texture->w),
                     static_cast<float>(texture->h)};
      renderer->renderTexture(texture, nullptr, &rect);
    }
  }
}

void Lenerith::Scene::load(Renderer *renderer) {
  std::ifstream file(path, std::ios::binary);
  nlohmann::json data = nlohmann::json::from_ubjson(file);
  for (auto &background : data["backgrounds"]) {
    std::string_view path = background["background"].get<std::string_view>();
    float paralax = background["paralax"].get<float>();
    backgrounds.emplace_back(renderer->loadTexture(path), paralax);
  }
}

void Lenerith::Scene::unload() {
  for (auto &entity : entities) {
    SDL_DestroyTexture(entity->getTexture());
    entity->setTexture(nullptr);
  }
  entities.clear();
  entities.shrink_to_fit();

  for (auto &background : backgrounds) {
    SDL_DestroyTexture(background.texture);
    background.texture = nullptr;
  }
  backgrounds.clear();
  backgrounds.shrink_to_fit();
}
