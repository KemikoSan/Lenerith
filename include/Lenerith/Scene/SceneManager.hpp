#pragma once

#include <vector>

#include <Lenerith/DLL.hpp>
#include <Lenerith/Scene/Scene.hpp>

namespace Lenerith {
class LENERITH_API SceneManager {
private:
public:
  std::vector<Scene> scenes;
  int currentScene;
  Scene *getCurrentScene();
  void loadScene(int scene);
  void loadNextScene();
  void loadPreviousScene();
  void loadSceneList();
  SceneManager();
  ~SceneManager();
  SceneManager(const SceneManager &) = delete;
  Scene &operator=(const Scene &) = delete;
  SceneManager(SceneManager &&) = default;
  SceneManager &operator=(SceneManager &&) = default;
};
}; // namespace Lenerith
