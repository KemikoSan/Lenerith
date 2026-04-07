#pragma once

#include <Lenerith/Scene/Scene.h>
#include <vector>

namespace Lenerith {
class SceneManager {
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
};
}; // namespace Lenerith
