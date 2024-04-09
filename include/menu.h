#ifndef MENU
#define MENU

#include <iostream>
#include "scene.h"

class Menu : public Scene {
private:
    std::string PLAY_GAME = "1";
    std::string CHANGE_SETTINGS = "2";
    std::string VIEW_CREDITS = "3";
public:
    Menu();
    ~Menu();
    void render() override;
    void handle_input() override;
};

#endif