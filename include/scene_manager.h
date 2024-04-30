#ifndef SCENE_MANAGER
#define SCENE_MANAGER

#include "scene.h"

/** @brief Singleton class that handles game scenes.
 *
 *  This class handles the swapping of scenes.
 */
class SceneManager {
private:
    SceneManager();

    static SceneManager* sceneManagerInstance;
public:
    Scene* currentScene; /**< Currently displayed scene. */

    ~SceneManager();

    /**
     * @brief Get the instance object
     * 
     * @return SceneManager*
     */
    static SceneManager* get_instance();

    /**
     * @brief Set the scene object
     * 
     * @param scene New scene
     */
    void set_scene(Scene* scene);
};

#endif
