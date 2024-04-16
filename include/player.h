#ifndef PLAYER
#define PLAYER

#include <iostream>
#include "player.h"
#include "color.h"

/**
 * @brief Class that represents a player in ConnectN.
 * A player has two components: a name and color.
 */
class Player {
private:
    std::string name;
    Color color;
public:
    Player();
    ~Player();
    void set_name(std::string n);
    void set_color(Color c);
    Color get_color();
};

#endif