#ifndef SETTINGS_MANAGER
#define SETTINGS_MANAGER

#include "settings.h"
#include "language.h"
#include <iostream>

class SettingsManager {
private:
    Language language;
    std::string settings_file_path = "settings.txt";
    SettingsManager();

    static SettingsManager* settingsManagerInstance;
public:
    ~SettingsManager();
    static SettingsManager* get_instance();
    void change_settings();
    void save_settings();
    void retrieve_settings();
    std::string get_language();
};

#endif