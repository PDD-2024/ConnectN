#include <iostream>
#include <string>
#include "menu.h"

Menu::Menu() {
    isRendered = false;
    // TODO: assign based off of language set in settings
    content = std::string("\n\n\nMenu - Choose an option\n\t(") + PLAY_GAME + std::string(") Play Game\n\t(") + CHANGE_SETTINGS + std::string(") Change Settings\n\t(") + VIEW_CREDITS + std::string(") View Credits\n\n");
}

void Menu::render() {
    std::cout << content << std::endl;
    isRendered = true;
}

void Menu::handle_input() {
    std::string input;
    getline(std::cin, input);
    if (input == PLAY_GAME) {
        // TODO: use SceneManager to switch scene to game
        std::cout << "Play game" << std::endl;
    } else if (input == CHANGE_SETTINGS) {
        // TODO: use SceneManager to switch scene to settings
        std::cout << "Change settings" << std::endl;
    } else if (input == VIEW_CREDITS) {
        // TODO: use SceneManager to switch scene to credits
        std::cout << "View credits" << std::endl;
    } else {
        // TODO: handle error
        std::cout << "Invalid input!" << std::endl;
    }
}

Menu::~Menu() {}


// Testing
int main(int argc, char **argv) {
    Menu m = Menu();
    m.render();
    m.handle_input();
    return 0;
}