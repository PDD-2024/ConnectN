#include <iostream>
#include <string>
#include "settings.h"

/** Constructor that configures the inital state of the class.
 *
 * This constructor sets the content (visual representation) of the settings scene and sets the rendered state of the scene to false.
 */
Settings::Settings() {
    // language = settings_manager.language.to_string()
    std::string language = "English";
    isRendered = false;
    content = "\n\nCurrent language: " + language + "\n\nEnter: (1) to change language\t(2) to save settings and return to menu\t(3) to return to menu without saving\n\n";
}

/// <inheritdoc />
void Settings::render() {
    std::cout << content << std::endl;
    isRendered = true;
}

/// <inheritdoc />
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
