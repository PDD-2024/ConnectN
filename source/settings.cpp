#include <iostream>
#include <string>
#include "settings.h"
#include "menu.h"
#include "scene_manager.h"
#include "settings_manager.h"

Settings::Settings() {
    SettingsManager *stm = SettingsManager::get_instance();
    std::string language = stm->get_language();
    isRendered = false;
    content = std::string("\n\n\nSettings - Choose an option\n\t(") + CHANGE_LANGUAGE + std::string(") Change Language (current:" + language + ")\n\t(") + SAVE_AND_RETURN_TO_MENU + std::string(") Save Settings and Return to Menu \n\t(") + RETURN_TO_MENU + std::string(") Return to Menu\n\n");
}

/// <inheritdoc />
void Settings::render() {
    std::cout << content << std::endl;
    isRendered = true;
}

/// <inheritdoc />
void Settings::handle_input() {
    SceneManager* sm = SceneManager::get_instance();

    bool isValidInput = false;
    std::string input;
    while (!isValidInput) {
        getline(std::cin, input);
        if (input == CHANGE_LANGUAGE) {
            isValidInput = true;
            //content = "Enter: (1) to switch language to English\t(2) to switch language to Spanish";
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
            std::cout << "Invalid input! Please enter a valid input: " << std::endl;
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
