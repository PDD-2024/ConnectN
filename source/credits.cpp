#include <iostream>
#include <string>
#include "credits.h"
#include "scene_manager.h"
#include "menu.h"
#include "settings_manager.h"

Credits::Credits() {}

/// <inheritdoc />
void Credits::render() {
    Language language = SettingsManager::get_instance()->get_language();
    std::cout << CREDITS_CONTENT.at(language)[0] + std::string(RETURN_TO_MENU) + CREDITS_CONTENT.at(language)[1] << std::endl;
}

/// <inheritdoc />
void Credits::handle_input() {
    SceneManager* sm = SceneManager::get_instance();
    Language language = SettingsManager::get_instance()->get_language();

    bool isValidInput = false;
    std::string input;
    while (!isValidInput) {
        getline(std::cin, input);
        if (input == RETURN_TO_MENU) {
            isValidInput = true;
            sm->set_scene(Menu::get_instance());
        } else {
            std::cout << GAME_ERRORS.at(language)[4] << std::endl;
        } 
    }
}

Credits* Credits::creditsInstance = nullptr;

Credits* Credits::get_instance() {
    if (creditsInstance == nullptr) {
        creditsInstance = new Credits();
    }

    return creditsInstance;
}

Credits::~Credits() {}
