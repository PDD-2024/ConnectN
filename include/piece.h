#ifndef PIECE
#define PIECE

#include <iostream>
#include "position.h"
#include "color.h"

class Piece {
private:
    Position position;
    Color color;
public:
    Piece();
    Piece(int x, int y, Color c);
    ~Piece();
    void set_position(Position new_position);
    Position get_position();
};

#endif