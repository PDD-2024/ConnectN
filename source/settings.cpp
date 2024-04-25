#include <iostream>
#include <string>
#include "settings.h"
#include "menu.h"
#include "scene_manager.h"

Settings::Settings() {
    // language = settings_manager.language.to_string()
    std::string language = "English";
    isRendered = false;
    content = std::string("\n\n\nSettings - Choose an option\n\t(") + CHANGE_LANGUAGE + std::string(") Change Language (current: English)\n\t(") + SAVE_AND_RETURN_TO_MENU + std::string(") Save Settings and Return to Menu \n\t(") + RETURN_TO_MENU + std::string(") Return to Menu\n\n");
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
            content = "Enter: (1) to switch language to English\t(2) to switch language to Spanish";
            // TODO: use settings manager to update settings
        } else if (input == SAVE_AND_RETURN_TO_MENU) {
            isValidInput = true;

            sm->set_scene(Menu::get_instance());
            // TODO: write updated settings to settings file
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
