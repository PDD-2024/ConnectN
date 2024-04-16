#ifndef PIECE
#define PIECE

#include <iostream>
#include "player.h"
#include "position.h"
#include "color.h"

class Piece {
private:
    Position position;
    Player *player;
public:
    Piece();
    Piece(int x, int y, Player *p);
    ~Piece();
    void set_position(Position new_position);
    Position get_position();
    Player *get_player();
};

#endif