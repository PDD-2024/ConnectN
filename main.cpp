#include <iostream>
#include "credits.h"
#include "menu.h"
#include "scene_manager.h"
#include "piece.h"
#include "game.h"
#include "program_manager.h"
#include "settings_manager.h"


int main(int, char**){
    ProgramManager *pm = ProgramManager::get_instance();
    pm->init();

    
}
