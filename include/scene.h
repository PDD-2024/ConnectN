#ifndef SCENE 
#define SCENE

#include <iostream>

class Scene {
public:
    std::string content;
    bool isRendered;
    virtual void render() = 0;
    virtual void handle_input() = 0;
};

#endif