#ifndef CREDITS
#define CREDITS

#include <iostream>
#include "scene.h"

/** @brief Singleton class that implements the scene class to create the credits scene.
 * Visually represents the credits scene to show of the developers of this application.
 */
class Credits : public Scene {
private:
    std::string RETURN_TO_MENU = "1";

    static Credits* creditsInstance;

    Credits();
public:
    ~Credits();
    void render() override;
    void handle_input() override;
    /**
     * @brief Get the instance object
     * 
     * @return Credits*
     */
    static Credits* get_instance();
};

#endif
