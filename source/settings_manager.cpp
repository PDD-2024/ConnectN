#include "settings_manager.h"
#include <fstream>

SettingsManager::SettingsManager() {
    retrieve_settings();
}

/** Writes the user's current settings to the settings file.
 */
void SettingsManager::save_settings() {
    std::ofstream file;
    file.open(settingsFilePath);
    if (file.is_open())
    {
        if (language == English) {
            file << "English";
        } else {
            file << "Español";
        }
        file.close();
    }
}

/** @brief Retrieves the user's currently configured settings.
 */
void SettingsManager::retrieve_settings() {
    // Read in the language settings from the file
    std::ifstream file;
    std::string line;

    file.open(settingsFilePath);
    bool settingsFound = false;
    while (getline(file, line)) {
        if (line == "English") {
            language = English;
            settingsFound = true;
        }
        if (line == "Español") {
            language = Spanish;
            settingsFound = true;
        }
    }
    file.close();

    // Default to English, if no settings found
    if (!settingsFound) {
        language = English;
        save_settings();
    }
}

/** @brief Toggles ConnectN's language between Spanish and English.
 */
void SettingsManager::change_settings() {
    if (language == English) {
        language = Spanish;
    } else {
        language = English;
    }
}

/** @brief Retrieves the currently configured language string.
 */
std::string SettingsManager::get_language_str() {
    if (language == English) {
        return std::string("English");
    } else {
        return std::string("Español");
    }
}

/** @brief Retrieves the currently configured language string.
 */
Language SettingsManager::get_language() {
    if (language == English) {
        return English;
    } else {
        return Spanish;
    }
}

SettingsManager* SettingsManager::s_settings_manager_instance = nullptr;

SettingsManager* SettingsManager::get_instance() {
    if (s_settings_manager_instance == nullptr) {
        s_settings_manager_instance = new SettingsManager();
    }
    
    return s_settings_manager_instance;
}

