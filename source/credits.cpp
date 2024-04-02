#include <iostream>
#include <string>
#include "credits.h"

Credits::Credits() {
    isRendered = false;
    // TODO: assign based off of language set in settings
    content = "\n\n\nCreated by J&B Development\n\tJoel Markley - Developer\n\tBrooklyn Cooper - Developer\n\nEnter 1 to return to menu\n\n";
}

void Credits::render() {
    std::cout << content << std::endl;
    isRendered = true;
}

void Credits::handle_input() {
    std::string input;
    getline(std::cin, input);
    if (input == RETURN_TO_MENU) {
        // TODO: use SceneManager to switch scene back to menu
    }
}

Credits::~Credits() {}


// // Testing
// int main(int argc, char **argv) {
//     Credits c = Credits();
//     c.render();
//     c.handle_input();
//     return 0;
// }