#ifndef SCENE 
#define SCENE

#include <iostream>

/** @brief Class that represents the visual and functional components of each scene in ConnectN.
 * This prints its content with the render() method and accepts user input with the handle_input() method. This class is to be overriden by derived application scenes.
 */
class Scene {
public:
    std::string content; /**< Content that visually represents the scene. To be configured in derived class constructors. */
    bool isRendered; /**< Boolean to represent whether a scene is being rendered. */
    /**
     * @brief Method utilized to render the scene's content.
     */
    virtual void render() = 0;
    /**
     * @brief Method utilized to accept and handle user input after rendering the scene.
     */
    virtual void handle_input() = 0;
};

#endif
