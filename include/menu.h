#ifndef MENU
#define MENU

#include <iostream>
#include "scene.h"

/**
 * @brief Class that implements scene to create the menu scene.
 * 
 * Entry scene to ConnectN. Allows the user to navigate to three different scenes: Game, Settings, and Credits
 * 
 * @see Scene
 * @see Game
 * @see Settings
 * @see Credits
 */
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