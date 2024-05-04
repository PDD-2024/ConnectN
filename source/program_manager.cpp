#include "program_manager.h"

ProgramManager::ProgramManager() {
    this->sceneManager = SceneManager::get_instance();
}

ProgramManager* ProgramManager::s_program_manager_instance = nullptr;

ProgramManager* ProgramManager::get_instance() {
    if (s_program_manager_instance == nullptr) {
        s_program_manager_instance = new ProgramManager();
    }

    return s_program_manager_instance;
}

void ProgramManager::init() {
    Settings* settingsScene = Settings::get_instance();
    Credits* creditsScene = Credits::get_instance();
    Menu* menuScene = Menu::get_instance();
    Game* gameScene = Game::get_instance();

    this->sceneManager->set_scene(menuScene);

    // Game loop
    while (true) {
        this->sceneManager->currentScene->render();
        this->sceneManager->currentScene->handle_input();
    }
}
