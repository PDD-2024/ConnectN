#include <cmath>
#include "board.h"

/**
 * @brief Default constructor to make a new Board.
 * 
 */
Board::Board() {}
/**
 * @brief Construct a new Board for a game of ConnectN where the N value is 'n'.
 * 
 * @param n the number of pieces in a row needed to win the game
 */
Board::Board(int n) {
    int w = ceil((float) n / 4 * 7);
    int h = ceil((float) n / 4 * 6);
    this->n = n;
    this->width = w;
    this->height = h;
    this->pieces = new Piece **[this->width];
    for (int i=0; i<this->width; i++) {
        this->pieces[i] = new Piece *[this->height];
        for (int j=0; j<this->height; j++) {
            this->pieces[i][j] = NULL;
        }
    }
}

/**
 * @brief Cleans up the Board and associated Pieces.
 * 
 */
Board::~Board() {
    for (int i=0; i<this->width; i++) {
        for (int j=0; j<this->height; j++) {
            delete this->pieces[i][j];
            this->pieces[i][j] = NULL;
        }
        delete this->pieces[i];
        this->pieces[i] = NULL;
    }
    delete this->pieces;
    this->pieces = NULL;
}

/**
 * @brief Places a Player's piece on the board in a specified column.
 * @see Piece
 * @see Player
 * @param column the column the Piece will be placed int
 * @param player the Player that is placing the piece
 * @return true for success or false for failure.
 */
bool Board::place_piece(int column, Player *player) {
    int i = this->height - 1;
    while (i >= 0) {
        if (this->pieces[column][i] == NULL) {
            this->pieces[column][i] = new Piece(column, i, player);
            return true;
        }
        i--;
    }
    return false;
}

/**
 * @brief Checks if a player has won the game.
 * 
 * Checks if there is a sequence of N similar pieces and returns the user associated with those pieces.
 * 
 * @see Piece
 * @return Player that has won the game (Player*) or NULL.
 */
// TODO: fix this to follow the actual rules of connect
Player *Board::check_for_winner() {
    for (int i=0; i<this->width; i++) {
        bool whole_col_same_color = true;
        for (int j=1; j<this->height; j++) {
            // Check if there is no piece in either place
            if (this->pieces[i][j-1] == NULL || this->pieces[i][j] == NULL) {
                whole_col_same_color = false;
                continue;
            }

            // Check if there is a mismatch between the pieces' colors
            Color previous_piece_color = this->pieces[i][j-1]->get_player()->get_color();
            Color current_piece_color = this->pieces[i][j]->get_player()->get_color();
            
            if (previous_piece_color != current_piece_color) {
                whole_col_same_color = false;
            }
        }
        if (whole_col_same_color) {
            return this->pieces[i][0]->get_player();
        }
    }
    return NULL;
}

/**
 * @brief Prints the board out to the screen
 * 
 * Prints a visual representation of the board, including the column numbers and the pieces on the board.
 */
void Board::print_board() {
    std::cout << "|";
    int num_spaces = 0;
    int space_calculator = this->width;
    while (space_calculator >= 1) {
        space_calculator /= 10;
        num_spaces++;
    }
    for (int j=0; j<this->width; j++) {
        int num_j_spaces = 0;
        space_calculator = j;
        while (space_calculator >= 1) {
            space_calculator /= 10;
            num_j_spaces++;
        }
        int padding_spaces = num_spaces - num_j_spaces;
        std::cout << " ";
        for (int k=0; k<padding_spaces; k++) {
            std::cout << " ";
        }
        std::cout << j << " ";
    }
    std::cout << "|" << std::endl;
    for (int i=0; i<this->height; i++) {
        std::cout << "| ";
        for (int j=0; j<this->width; j++) {
            for (int k=0; k<num_spaces-1; k++) {
                std::cout << " ";
            }
            if (pieces[j][i] == NULL) {
                std::cout << "   ";
                continue;
            }
            Color c = pieces[j][i]->get_player()->get_color();
            if (c == Black) {
                std::cout << " B ";
            } else if (c == Red) {
                std::cout << " R ";
            } else {
                std::cout << "E";
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Gets the number n of pieces in a row needed to win the game.
 * 
 * @return The value of n
 */
int Board::get_n() {
    return this->n;
}


/**
 * @brief Gets the width of the board.
 * 
 * @return The width of the board
 */
int Board::get_width() {
    return this->width;
}

// Testing
// int main(int argc, char **argv) {
//     Board b = Board(3,4);
//     Player pl1 = Player();
//     Player pl2 = Player();
//     pl1.set_color(Red);
//     pl2.set_color(Black);
//     pl1.set_name("Brooklyn");
//     pl2.set_name("Joey");
//     Piece p1 = Piece(0,0,&pl1);
//     Piece p2 = Piece(0,1,&pl1);
//     Piece p3 = Piece(0,2,&pl2);
//     Piece p4 = Piece(0,3,&pl1);

//     Piece p5 = Piece(1,0,&pl2);
//     Piece p6 = Piece(1,1,&pl1);
//     Piece p7 = Piece(1,2,&pl2);
//     Piece p8 = Piece(1,3,&pl2);

//     Piece p9 = Piece(2,0,&pl1);
//     Piece p10 = Piece(2,1,&pl2);
//     Piece p11 = Piece(2,2,&pl1);

//     b.place_piece(&p1);
//     b.place_piece(&p2);
//     b.place_piece(&p3);
//     b.place_piece(&p4);
//     b.place_piece(&p5);
//     b.place_piece(&p6);
//     b.place_piece(&p7);
//     b.place_piece(&p8);
//     b.place_piece(&p9);
//     b.place_piece(&p10);
//     b.place_piece(&p11);

//     b.print_board();

//     Player *winner = b.check_for_winner();

//     if (winner == NULL) {
//         std::cout << "no winner yet!" << std::endl;
//     } else if (winner->get_color() == Red) {
//         std::cout << "Red wins" << std::endl;
//     } else if (winner->get_color() == Black) {
//         std::cout << "Black wins" << std::endl;
//     } else {
//         std::cout << "error" << std::endl;
//     }

//     return 0;
// }