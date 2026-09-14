#include <filesystem>
#include <memory>
#include <vector>

#include <Lenerith/DLL.h>
#include <Lenerith/Entity/Entity.h>
#include <Lenerith/Entity/Player.h>
#include <Lenerith/Scene/Background.h>

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
  void render(Camera *camera);
  void load();
  void unload();
  Scene(const Scene &) = delete;
  Scene &operator=(const Scene &) = delete;
  Scene(Scene &&) = default;
  Scene &operator=(Scene &&) = default;
};
}; // namespace Lenerith
