#include <iostream>
#include <string>
#include "piece.h"
#include "position.h"
#include "color.h"
#include "player.h"

Piece::Piece() {}

Piece::Piece(int x, int y, Player *p) {
    this->position = Position(x,y);
    this->player = p;
}

Piece::~Piece() {}

void Piece::set_position(Position new_position) {
    this->position = new_position;
}

Position Piece::get_position() {
    return this->position;
}

Player *Piece::get_player() {
    return this->player;
}


// // Testing
// int main(int argc, char **argv) {
//     Player play = Player();
//     Piece p = Piece(3,4,&play);
//     std::cout << p.get_position().x << "x" << p.get_position().y << std::endl;
//     return 0;
// }