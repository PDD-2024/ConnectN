#include <iostream>
#include <string>
#include "credits.h"
#include "scene_manager.h"
#include "menu.h"

Credits::Credits() {
    isRendered = false;
    // TODO: assign based off of language set in settings
    content = std::string("\n\n\nCreated by J&B Development\n\tJoel Markley - Developer\n\tBrooklyn Cooper - Developer\n\nEnter (") + std::string(RETURN_TO_MENU) + std::string(") to return to menu\n\n");
}

/// <inheritdoc />
void Credits::render() {
    std::cout << content << std::endl;
    isRendered = true;
}

/// <inheritdoc />
void Credits::handle_input() {
    SceneManager* sm = SceneManager::get_instance();

    bool isValidInput = false;
    std::string input;
    while (!isValidInput) {
        getline(std::cin, input);
        if (input == RETURN_TO_MENU) {
            isValidInput = true;
            sm->set_scene(Menu::get_instance());
        } else {
            std::cout << "Invalid input! Please enter a valid input: " << std::endl;
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


// Testing
// int main(int argc, char **argv) {
//    Credits c = Credits();
//    c.render();
//    c.handle_input();
//    return 0;
//}
