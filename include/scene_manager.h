#ifndef SCENE_MANAGER
#define SCENE_MANAGER

#include "scene.h"

class SceneManager {
private:
    SceneManager();

    static SceneManager* s_scene_manager_instance;
public:
    Scene* currentScene;

    ~SceneManager();
    static SceneManager* get_instance();
    void set_scene(Scene* scene);
};

#endif // !DEBUG
