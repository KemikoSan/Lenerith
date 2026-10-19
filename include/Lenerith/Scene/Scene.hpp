#pragma once

#include <filesystem>
#include <memory>
#include <vector>

#include <Lenerith/Core/Renderer.hpp>
#include <Lenerith/DLL.hpp>
#include <Lenerith/Entity/Entity.hpp>
#include <Lenerith/Entity/Player.hpp>
#include <Lenerith/Scene/Background.hpp>

namespace Lenerith {
class LENERITH_API Scene {
private:
  std::filesystem::path path;
  std::vector<Background> backgrounds;
  std::vector<std::unique_ptr<Lenerith::Entity>> entities;
  // std::vector<Lenerith::Player> players;

public:
  Scene(const std::filesystem::path &path);
  void update();
  void render(Renderer *renderer, Camera *camera);
  void load(Renderer *renderer);
  void unload();
  Scene(const Scene &) = delete;
  Scene &operator=(const Scene &) = delete;
  Scene(Scene &&) = default;
  Scene &operator=(Scene &&) = default;
};
}; // namespace Lenerith
