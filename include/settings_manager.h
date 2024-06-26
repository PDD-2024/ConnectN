#ifndef SETTINGS_MANAGER
#define SETTINGS_MANAGER

#include "settings.h"
#include "language.h"
#include <iostream>

/** @brief Class that handles configuring settings. This class retrieves, changes, and writes updated settings to the settings file.
 *
 */
class SettingsManager {
private:
    Language language;
    std::string settingsFilePath = "settings.txt";
    SettingsManager();

    static SettingsManager* s_settings_manager_instance;
public:
    ~SettingsManager();
    /** @brief Retrieves the settings manager singleton instance.
     */
    static SettingsManager* get_instance();
    void change_settings();
    void save_settings();
    void retrieve_settings();
    Language get_language();
    std::string get_language_str();
};

#endif
