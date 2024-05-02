#ifndef SETTINGS
#define SETTINGS

#include <iostream>
#include "scene.h"

/** @brief Class that implements the scene class to create the "settings scene".
 *
 * Visually and functionally represents the settings scene. Utilized by the user to modify their personal application settings.
 */
class Settings : public Scene {
private:
    std::string CHANGE_LANGUAGE = "1"; /**< Input that indicates a desire to change the application's language. */
    std::string SAVE_AND_RETURN_TO_MENU = "2"; /**< Input that indicates a desire to save the current settings and return to the main menu scene. */
    std::string RETURN_TO_MENU = "3"; /**< Input that indicates a desire to return to the main menu scene without saving .*/
    static Settings* settingsInstance;

    Settings();
public:
    ~Settings();
    void render() override;
    void handle_input() override;
    static Settings* get_instance();
};

#endif
