#define LENERITH_EXPORT

#include <fstream>
#include <string>

#include <Lenerith/Scene/SceneManager.h>

Lenerith::Scene *Lenerith::SceneManager::getCurrentScene() {
  return &scenes[currentScene];
}

void Lenerith::SceneManager::loadScene(int scene) {
  scenes[currentScene].unload();
  currentScene = scene;
  scenes[currentScene].load();
}

void Lenerith::SceneManager::loadNextScene() {
  if (currentScene + 1 < scenes.size()) {
    scenes[currentScene].unload();
    currentScene++;
    scenes[currentScene].load();
  }
}

void Lenerith::SceneManager::loadPreviousScene() {
  if (!(currentScene - 1 < 0)) {
    scenes[currentScene].unload();
    currentScene--;
    scenes[currentScene].load();
  }
}

void Lenerith::SceneManager::loadSceneList() {
  std::ifstream file("assets/scenes.txt");
  std::string line;
  while (!file.eof()) {
    std::getline(file, line);
    if (line != "") {
      scenes.emplace_back(line);
    }
  }
}

Lenerith::SceneManager::SceneManager() {}
Lenerith::SceneManager::~SceneManager() {}
