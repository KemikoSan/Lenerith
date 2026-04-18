#include <filesystem>
#include <memory>
#include <vector>

#include "SDL3/SDL_render.h"

#include <Lenerith/Entity/Entity.h>
#include <Lenerith/Entity/Player.h>
#include <Lenerith/Scene/Background.h>
#include <Lenerith/export.h>

namespace Lenerith {
class LENERITH_API Scene {
private:
  SDL_Renderer *renderer;
  std::filesystem::path path;
  std::vector<Background> backgrounds;                     // layers of background
  std::vector<std::unique_ptr<Lenerith::Entity>> entities; // entities to update and render
  // std::vector<Lenerith::Player> players;

public:
  Scene(SDL_Renderer *render, const std::filesystem::path &path);
  void update();
  void render(Camera *camera);
  void load();
  void unload();
  Scene(const Scene &) = delete;
  Scene &operator=(const Scene &) = delete;
  Scene(Scene &&) = default;
  Scene &operator=(Scene &&) = default;
};
}; // namespace Lenerith
