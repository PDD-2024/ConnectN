#include <iostream>
#include <string>
#include "menu.h"

Menu::Menu() {
    isRendered = false;
    // TODO: assign based off of language set in settings
    content = "\n\n\nMenu - Choose an option\n\t(1) Play Game\n\t(2) Change Settings\n\t(3) View Credits\n\n";
}

void Menu::render() {
    std::cout << content << std::endl;
    isRendered = true;
}

void Menu::handle_input() {
    
}

Menu::~Menu() {}


// Testing
int main(int argc, char **argv) {
    Menu m = Menu();
    m.render();
    return 0;
}