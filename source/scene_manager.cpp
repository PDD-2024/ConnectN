#include "scene_manager.h"

SceneManager::SceneManager() {}

void SceneManager::set_scene(Scene* scene) {
    this->currentScene = scene;
}

SceneManager* SceneManager::sceneManagerInstance = nullptr;

SceneManager* SceneManager::get_instance() {
    if (sceneManagerInstance == nullptr) {
        sceneManagerInstance = new SceneManager();
    }

    return sceneManagerInstance;
}

