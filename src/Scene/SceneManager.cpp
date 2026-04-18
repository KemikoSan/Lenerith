#define LENERITH_EXPORT

#include <Lenerith/Scene/SceneManager.h>

Lenerith::Scene *Lenerith::SceneManager::getCurrentScene() {
  return &scenes[currentScene];
}

// void Lenerith::SceneManager::setCurrentScene(int scene) {
//   currentScene = scene;
// }

void Lenerith::SceneManager::nextScene() {
  if (!(currentScene + 1 >= scenes.size())) {
    scenes[currentScene].unload();
    currentScene++;
    scenes[currentScene].load();
  }
}

void Lenerith::SceneManager::previousScene() {
  if (!(currentScene - 1 < 0)) {
    scenes[currentScene].unload();
    currentScene--;
    scenes[currentScene].load();
  }
}

Lenerith::SceneManager::SceneManager() {}
Lenerith::SceneManager::~SceneManager() {}
