#include <iostream>
#include <string>
#include "credits.h"

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
    std::string input;
    getline(std::cin, input);
    if (input == RETURN_TO_MENU) {
        std::cout << "Return to menu!" << std::endl;
        // TODO: use SceneManager to switch scene back to menu
    } else {
        // TODO: handle error
        std::cout << "Invalid input!" << std::endl;
    }
}

Credits::~Credits() {}


// Testing
// int main(int argc, char **argv) {
//    Credits c = Credits();
//    c.render();
//    c.handle_input();
//    return 0;
//}
