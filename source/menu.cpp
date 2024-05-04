#include <iostream>
#include <string>
#include "scene_manager.h"
#include "menu.h"
#include "game.h"
#include "settings.h"
#include "credits.h"
#include "settings_manager.h"
#include "language.h"

Menu::Menu() {}

/// <inheritdoc />
void Menu::render() {
    Language language = SettingsManager::get_instance()->get_language();
    std::cout << MENU_CONTENT.at(language)[0] + PLAY_GAME + MENU_CONTENT.at(language)[1] + CHANGE_SETTINGS + MENU_CONTENT.at(language)[2] + VIEW_CREDITS + MENU_CONTENT.at(language)[3] + EXIT + MENU_CONTENT.at(language)[4] << std::endl;
}

/// <inheritdoc />
void Menu::handle_input() {
    SceneManager* sm = SceneManager::get_instance();
    Language language = SettingsManager::get_instance()->get_language();

    bool isValidInput = false;
    std::string input;
    while (!isValidInput) {
        getline(std::cin, input);
        if (input == PLAY_GAME) {
            isValidInput = true;
            sm->set_scene(Game::get_instance());

        } else if (input == CHANGE_SETTINGS) {
            isValidInput = true;
            sm->set_scene(Settings::get_instance());
        } else if (input == VIEW_CREDITS) {
            isValidInput = true;
            sm->set_scene(Credits::get_instance());
        }  else if (input == EXIT) {
            exit(0);
        } else {
            std::cout << GAME_ERRORS.at(language)[4] << std::endl;
        }
    }
}

Menu::~Menu() {}

Menu* Menu::s_menu_instance = nullptr;

Menu* Menu::get_instance() {
    if (s_menu_instance == nullptr) {
        s_menu_instance = new Menu();
    }

    return s_menu_instance;
}

