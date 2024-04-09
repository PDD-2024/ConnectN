#ifndef CREDITS
#define CREDITS

#include <iostream>
#include "scene.h"

class Menu : public Scene {

public:
    Menu();
    ~Menu();
    void render() override;
    void handle_input() override;
};

#endif