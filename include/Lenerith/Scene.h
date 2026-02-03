#include "SDL3/SDL_render.h"
#include <Lenerith/Entity/Entity.h>
#include <filesystem>
#include <memory>
#include <vector>

namespace Lenerith {
class Scene {
  SDL_Renderer *renderer;
  std::filesystem::path path;
  std::vector<SDL_Texture *> backgrounds;                  // layers of background
  std::vector<std::unique_ptr<Lenerith::Entity>> entities; // entities to update and render

public:
  Scene(SDL_Renderer *render, const std::filesystem::path &path);
  void update(float deltatime);
  void render();
  void load();
};
}; // namespace Lenerith
