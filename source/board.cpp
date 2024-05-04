#include <cmath>
#include <algorithm> 
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
 * Checks if there is a sequence of N same-colored pieces in a row horizontally, vertically, or diagonally, and returns the user associated with those pieces.
 * @note If there are multiple types of winning sequences on the board (horizontal, vertical, and diagonal sequences), the winner returned will be the one with the higher-precedence sequence type. The precedence levels are: horizontal -> vertical -> right diagonal -> left diagonal. Additionally, the player whose sequence is higher (for horizontal sequences) or farther left (for vertical sequences) on the board will be given the win.
 * @see Piece
 * @return Player that has won the game (Player*) or NULL.
 */
Player *Board::check_for_winner() {
    // Check for horizontal N in a row
    for (int i=0; i<this->height; i++) {
        int num_in_a_row = 0;
        for (int j=0; j<this->width; j++) {
            if (pieces[j][i] == NULL) { // If there's no piece here, the number of pieces in a row resets to 0
                num_in_a_row = 0;
            } else if (j == 0 || pieces[j-1][i] == NULL || pieces[j][i]->get_player() == pieces[j-1][i]->get_player()) { // If this is the first piece in a row, if it follows an empty slot, or if it was placed by the same player as the previous piece, increment the number of pieces in a row
                num_in_a_row++;
            } else { // Otherwise, this piece exists and is not the first piece in a row and the pieces must be opposite colors, so set the number in a row to one.
                num_in_a_row = 1;
            }

            // If there's N in a row put by the same player, that player wins.
            if (num_in_a_row >= this->n) {
                return pieces[j][i]->get_player();
            }
        }
    }

    // Check for vertical N in a row
    for (int j=0; j<this->width; j++) {
        int num_in_a_row = 0;
        for (int i=0; i<this->height; i++) {
            if (pieces[j][i] == NULL) { // If there's no piece here, the number of pieces in a row resets to 0
                num_in_a_row = 0;
            } else if (i == 0 || pieces[j][i-1] == NULL || pieces[j][i]->get_player() == pieces[j][i-1]->get_player()) { // If this is the first piece in a column or if it was placed by the same player as the previous piece, increment the number of pieces in a row
                num_in_a_row++;
            } else { // Otherwise, this piece exists and is not the first piece in a column and the pieces must be opposite colors, so set the number in a row to one.
                num_in_a_row = 1;
            }

            // If there's N in a row put by the same player, that player wins.
            if (num_in_a_row >= this->n) {
                return pieces[j][i]->get_player();
            }
        }
    }

    // Check for N in a row along a right diagonal
    int last_diagonal = this->width + this->height - 2;
    int max_height_idx = this->height-1;
    for (int i=0; i<=last_diagonal; i++) {
        int num_in_a_row = 0;
        for (int j=std::max(0,i-this->width+1); j<=std::min(max_height_idx,i); j++) {
            if (pieces[i-j][j] == NULL) { // If there's no piece here, the number of pieces in a row resets to 0
                num_in_a_row = 0;
            } else if (j == 0 || i-j+1 >= this->width || pieces[i-j+1][j-1] == NULL || pieces[i-j][j]->get_player() == pieces[i-j+1][j-1]->get_player()) { // If this is the first piece in a diagonal or if it was placed by the same player as the previous piece, increment the number of pieces in a row
                num_in_a_row++;
            } else { // Otherwise, this piece exists and is not the first piece in a diagonal and the pieces must be opposite colors, so set the number in a row to one.
                num_in_a_row = 1;
            }
            // If there's N in a row put by the same player, that player wins.
            if (num_in_a_row >= this->n) {
                return pieces[i-j][j]->get_player();
            }
        }
    }

    // Check for N in a row along a left diagonal
    for (int i=0; i <= last_diagonal; i++) {
        int num_in_a_row = 0;
        for (int j=std::max(0,max_height_idx-i); j<=std::min(max_height_idx,last_diagonal-i); j++) {
            if (pieces[i-max_height_idx+j][j] == NULL) { // If there's no piece here, the number of pieces in a row resets to 0
                num_in_a_row = 0;
            } else if (j == 0 || i-max_height_idx+j == 0 || pieces[i-max_height_idx+j-1][j-1] == NULL || pieces[i-max_height_idx+j][j]->get_player() == pieces[i-max_height_idx+j-1][j-1]->get_player()) { // If this is the first piece in a diagonal or if it was placed by the same player as the previous piece, increment the number of pieces in a row
                num_in_a_row++;
            } else { // Otherwise, this piece exists and is not the first piece in a diagonal and the pieces must be opposite colors, so set the number in a row to one.
                num_in_a_row = 1;
            }
            // If there's N in a row put by the same player, that player wins.
            if (num_in_a_row >= this->n) {
                return pieces[i-max_height_idx+j][j]->get_player();
            }
        }
    }
    
    // There were not N in a row horizontally, vertically, or diagonally. Return NULL to signify no winner.
    return NULL;
}

/**
 * @brief Checks if the board is full.
 * 
 * @return true if the board is full, or false otherwise.
 */
bool Board::check_if_full() {
    for (int i=0; i<this->width; i++) {
        if (pieces[i][0] == NULL) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Prints the board out to the screen
 * 
 * Prints a visual representation of the board, including the column numbers and the pieces on the board.
 */
std::string Board::board_to_string() {
    std::string out = "|";
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
        out += " ";
        for (int k=0; k<padding_spaces; k++) {
            out += " ";
        }
        out += std::to_string(j) + " ";
    }
    out += "|\n";
    for (int i=0; i<this->height; i++) {
        out += "| ";
        for (int j=0; j<this->width; j++) {
            for (int k=0; k<num_spaces-1; k++) {
                out += " ";
            }
            if (pieces[j][i] == NULL) {
                out += "   ";
                continue;
            }
            Color c = pieces[j][i]->get_player()->get_color();
            if (c == Black) {
                out += " B ";
            } else if (c == Red) {
                out += " R ";
            } else {
                out += "E";
            }
        }
        out += "|\n";
    }
    out += "\n";
    return out;
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
