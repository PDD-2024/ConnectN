#ifndef PROGRAM_MANAGER
#define PROGRAM_MANAGER

#include "scene_manager.h"
#include "game.h"
#include "credits.h"
#include "menu.h"
#include "settings.h"

class ProgramManager{
private:
    static ProgramManager* s_program_manager_instance;
    SceneManager* sceneManager;
    bool exit;
    
    ProgramManager();
public:
    ~ProgramManager();
    void init();
    void end();
    static ProgramManager* get_instance();
};

#endif // !d

