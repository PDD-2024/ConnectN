#ifndef PROGRAM_MANAGER
#define PROGRAM_MANAGER

#include "scene_manager.h"
#include "game.h"
#include "credits.h"
#include "menu.h"
#include "settings.h"

/**
 * @brief Singleton class that handles the management of the program
 * 
 * Main game loop is executed here.
 */
class ProgramManager{
private:
    static ProgramManager* programManagerInstance;
    SceneManager* sceneManager;
    // Settings manager
    
    ProgramManager();
public:
    ~ProgramManager();
    /**
     * @brief Sets up the game and configures the main game loop
     * 
     */
    void init();

    /**
     * @brief Get the instance object.
     * 
     * @return ProgramManager*
     */
    static ProgramManager* get_instance();
};

#endif // !d

