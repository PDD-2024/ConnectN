#include <iostream>
#include <string>
#include "piece.h"
#include "position.h"
#include "color.h"
#include "player.h"

/**
 * @brief Default constructor to create a new piece object.
 */
Piece::Piece() {}

/**
 * @brief Constructor to create a new piece object with a (x, y) position and associated player.
 * 
 * @param x X position of the piece.
 * @param y Y Position of the piece
 * @param p Player associated with the piece.
 */
Piece::Piece(int x, int y, Player *p) {
    this->position = Position(x,y);
    this->player = p;
}

Piece::~Piece() {}

/**
 * @brief Gets the position of the piece object.
 * @see Position
 * @return Position of the piece object.
 */
Position Piece::get_position() {
    return this->position;
}

/**
 * @brief Gets the player associated with the piece object.
 * @see Player
 * @return Player associated with the piece object (Player*) 
 */
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