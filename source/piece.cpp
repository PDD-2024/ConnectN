#include <iostream>
#include <string>
#include "piece.h"
#include "position.h"
#include "color.h"

Piece::Piece() {}

Piece::Piece(int x, int y, Color c) {
    this->position = Position(x,y);
    this->color = color;
}

Piece::~Piece() {}

void Piece::set_position(Position new_position) {
    this->position = new_position;
}

Position Piece::get_position() {
    return this->position;
}


// Testing
int main(int argc, char **argv) {
    Piece p = Piece(3,4,Black);
    std::cout << p.get_position().x << "x" << p.get_position().y << std::endl;
    return 0;
}