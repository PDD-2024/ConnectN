#ifndef BOARD
#define BOARD

#include <iostream>
#include "piece.h"
#include "player.h"

/**
 * @brief Class that represents the playable ConnectN board.
 * 
 * This class utilizes a 2D array composed of the Piece class to represent the playing board:
 * Board position schema:
 * (0,0)  (1,0)  (2,0)  (3,0)  ...
 * (0,1)  (1,1)  (2,1)  (3,1)
 * (0,2)  (1,2)  (2,2)  (3,2)
 *  ...                        ...
 * 
 * @see Piece
 */
class Board {
private:
    Piece ***pieces;
    int n;
    int width;
    int height;
public:
    Board();
    Board(int n);
    ~Board();
    bool place_piece(int column, Player *player);
    Player *check_for_winner();
    void print_board();
    int get_n();
    int get_width();
};

#endif