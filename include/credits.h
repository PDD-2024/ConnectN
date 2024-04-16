#ifndef CREDITS
#define CREDITS

#include <iostream>
#include "scene.h"

class Credits : public Scene {
private:
    std::string RETURN_TO_MENU = "1";
public:
    Credits();
    ~Credits();
    void render() override;
    void handle_input() override;
};

#endif
