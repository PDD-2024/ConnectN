#include "settings_manager.h"
#include <fstream>

SettingsManager::SettingsManager() {
    retrieve_settings();
}

void SettingsManager::save_settings() {
    std::ofstream file;
    file.open(settings_file_path);
    if (file.is_open())
    {
        if (language == English) {
            file << "English";
        } else {
            file << "Spanish";
        }
        file.close();
    }
    else {
        // TODO: error handle
        std::cout << "File I/O Error";
    }
}

void SettingsManager::retrieve_settings() {
    // Read in the language settings from the file
    std::ifstream file;
    std::string line;

    file.open(settings_file_path);
    bool settingsFound = false;
    while (getline(file, line)) {
        if (line == "English") {
            language = English;
            settingsFound = true;
        }
        if (line == "Spanish") {
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

void SettingsManager::change_settings() {
    if (language == English) {
        language = Spanish;
    } else {
        language = English;
    }
}

std::string SettingsManager::get_language() {
    if (language == English) {
        return std::string("English");
    } else {
        return std::string("Spanish");
    }
}

SettingsManager* SettingsManager::settingsManagerInstance = nullptr;

SettingsManager* SettingsManager::get_instance() {
    if (settingsManagerInstance == nullptr) {
        settingsManagerInstance = new SettingsManager();
    }
    return settingsManagerInstance;
}
