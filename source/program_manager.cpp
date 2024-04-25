#include "program_manager.h"

ProgramManager::ProgramManager() {
    this->sceneManager = SceneManager::get_instance();
    // TODO :: Initialize settings manager
}

ProgramManager* ProgramManager::programManagerInstance = nullptr;

ProgramManager* ProgramManager::get_instance() {
    if (programManagerInstance == nullptr) {
        programManagerInstance = new ProgramManager();
    }

    return programManagerInstance;
}

void ProgramManager::init() {
    // Game* gameScene = Game::get_instance();
    Settings* settingsScene = Settings::get_instance();
    Credits* creditsScene = Credits::get_instance();
    Menu* menuScene = Menu::get_instance();

    this->sceneManager->set_scene(menuScene);

    // Game loop
    while (true) {
        this->sceneManager->currentScene->render();
        this->sceneManager->currentScene->handle_input();
    }
}
