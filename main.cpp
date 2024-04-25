#include <iostream>
#include "credits.h"
#include "menu.h"
#include "scene_manager.h"

int main(int, char**){
    SceneManager* sm = SceneManager::get_instance();

    sm->set_scene(Menu::get_instance());
    sm->currentScene->render();
    sm->currentScene->handle_input();
    sm->currentScene->render();
}
