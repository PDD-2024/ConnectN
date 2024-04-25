#include <iostream>
#include <string>
#include "scene_manager.h"
#include "menu.h"
#include "game.h"
#include "settings.h"
#include "credits.h"

Menu::Menu() {
    isRendered = false;
    // TODO: assign based off of language set in settings
    content = std::string("\n\n\nMenu - Choose an option\n\t(") + PLAY_GAME + std::string(") Play Game\n\t(") + CHANGE_SETTINGS + std::string(") Change Settings\n\t(") + VIEW_CREDITS + std::string(") View Credits\n\n");
}

/// <inheritdoc />
void Menu::render() {
    std::cout << content << std::endl;
    isRendered = true;
}

/// <inheritdoc />
void Menu::handle_input() {
    SceneManager* sm = SceneManager::get_instance();

    bool isValidInput = false;
    std::string input;
    while (!isValidInput) {
        getline(std::cin, input);
        if (input == PLAY_GAME) {
            isValidInput = true;
            // sm.set_scene(Menu::get_instance());
            std::cout << "Play game" << std::endl;
        } else if (input == CHANGE_SETTINGS) {
            isValidInput = true;
            sm->set_scene(Settings::get_instance());
            // TODO: use SceneManager to switch scene to settings
            std::cout << "Change settings" << std::endl;
        } else if (input == VIEW_CREDITS) {
            isValidInput = true;
            sm->set_scene(Credits::get_instance());
            std::cout << "View credits" << std::endl;
        } else {
            // TODO: handle error
            std::cout << "Invalid input!" << std::endl;
        }
    }
}

Menu::~Menu() {}

Menu* Menu::menuInstance = nullptr;

Menu* Menu::get_instance() {
    if (menuInstance == nullptr) {
        menuInstance = new Menu();
    }

    return menuInstance;
}

// Testing
//int main(int argc, char **argv) {
//    Menu m = Menu();
//    m.render();
//    m.handle_input();
//    return 0;
//}
