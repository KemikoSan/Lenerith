#pragma once

#include <Lenerith/Scene/Scene.h>
#include <Lenerith/export.h>
#include <vector>

namespace Lenerith {
class LENERITH_API SceneManager {
private:
public:
  std::vector<Scene> scenes;
  int currentScene;
  Scene *getCurrentScene();
  // void setCurrentScene(int scene);
  void nextScene();
  void previousScene();
  SceneManager();
  ~SceneManager();
  SceneManager(const SceneManager &) = delete;
  Scene &operator=(const Scene &) = delete;
  SceneManager(SceneManager &&) = default;
  SceneManager &operator=(SceneManager &&) = default;
};
}; // namespace Lenerith
