#include <iostream>
#include "credits.h"
#include "menu.h"

int main(int, char**){
    std::cout << "Hello, from ConnectN!\n";
    Credits c = Credits();
    c.render();
}
