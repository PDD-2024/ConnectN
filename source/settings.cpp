#include <iostream>
#include <string>
#include "settings.h"

Settings::Settings() {
    // language = settings_manager.language.to_string()
    std::string language = "English";
    isRendered = false;
    content = "\n\nCurrent language: " + language + "\n\nEnter: (1) to change language\t(2) to save settings and return to menu\t(3) to return to menu without saving\n\n";
}

void Settings::render() {
    std::cout << content << std::endl;
    isRendered = true;
}

void Settings::handle_input() {
    std::string input;
    getline(std::cin, input);
    if (input == CHANGE_LANGUAGE) {
        content = "Enter: (1) to switch language to English\t(2) to switch language to Spanish";
        // TODO: use SceneManager to switch scene back to menu
    } else if (input == SAVE_AND_RETURN_TO_MENU) {
        // TODO: write updated settings to settings file
        // TODO: use SceneManager to switch scene back to menu
    } else if (input == RETURN_TO_MENU) {
        // TODO: use SceneManager to switch scene back to menu
    }
}

Settings::~Settings() {}