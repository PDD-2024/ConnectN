#include <iostream>
#include <string>
#include "settings.h"
#include "menu.h"
#include "scene_manager.h"
#include "settings_manager.h"

Settings::Settings() {}

/// <inheritdoc />
void Settings::render() {
    SettingsManager *stm = SettingsManager::get_instance();
    Language language = stm->get_language();
    std::string language_str = stm->get_language_str();
    std::cout << SETTINGS_CONTENT.at(language)[0] + CHANGE_LANGUAGE + SETTINGS_CONTENT.at(language)[1] + language_str + ")\n\t(" + SAVE_AND_RETURN_TO_MENU + SETTINGS_CONTENT.at(language)[2] + RETURN_TO_MENU + SETTINGS_CONTENT.at(language)[3] << std::endl;
}

/// <inheritdoc />
void Settings::handle_input() {
    SceneManager* sm = SceneManager::get_instance();
    Language language = SettingsManager::get_instance()->get_language();

    bool isValidInput = false;
    std::string input;
    while (!isValidInput) {
        getline(std::cin, input);
        if (input == CHANGE_LANGUAGE) {
            isValidInput = true;
            SettingsManager *stm = SettingsManager::get_instance();
            stm->change_settings();
        } else if (input == SAVE_AND_RETURN_TO_MENU) {
            isValidInput = true;

            sm->set_scene(Menu::get_instance());
            SettingsManager *stm = SettingsManager::get_instance();
            stm->save_settings();
        } else if (input == RETURN_TO_MENU) {
            isValidInput = true;

            sm->set_scene(Menu::get_instance());
        } else {
            std::cout << GAME_ERRORS.at(language)[4] << std::endl;
        }
    }
}

Settings* Settings::settingsInstance = nullptr;

Settings* Settings::get_instance() {
    if (settingsInstance == nullptr) {
        settingsInstance = new Settings();
    }

    return settingsInstance;
}

Settings::~Settings() {}
