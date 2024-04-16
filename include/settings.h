#ifndef SETTINGS
#define SETTINGS

#include <iostream>
#include "scene.h"

class Settings : public Scene {
private:
    std::string CHANGE_LANGUAGE = "1";
    std::string SAVE_AND_RETURN_TO_MENU = "2";
    std::string RETURN_TO_MENU = "3";
    // Settingsanager* settings_manager
public:
    Settings();
    ~Settings();
    void render() override;
    void handle_input() override;
};

#endif
