#include "scene_manager.h"

SceneManager::SceneManager() {}

void SceneManager::set_scene(Scene* scene) {
    this->currentScene = scene;
}

SceneManager* SceneManager::s_scene_manager_instance = nullptr;

SceneManager* SceneManager::get_instance() {
    if (s_scene_manager_instance == nullptr) {
        s_scene_manager_instance = new SceneManager();
    }

    return s_scene_manager_instance;
}

