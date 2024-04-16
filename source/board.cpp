#include "board.h"

/**
 * @brief Default constructor to make a new Board.
 * 
 */
Board::Board() {}
/**
 * @brief Construct a new Board with 'w' width and 'h' height.
 * 
 * @param w Width of the board.
 * @param h Height of the board.
 */
Board::Board(int w, int h) {
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
        delete this->pieces[i];
    }
    delete this->pieces;
}

/**
 * @brief Places a piece on the board.
 * @note The piece at the current piece-to-be-placed's position will be overwritten.
 * @see Piece
 * @param piece Piece to be placed.
 */
void Board::place_piece(Piece *piece) {
    this->pieces[piece->get_position().x][piece->get_position().y] = piece;
}

/**
 * @brief Checks if a player has won the game.
 * 
 * Checks if there is a sequence of N similar pieces and returns the user associated with those pieces.
 * 
 * @see Piece
 * @return Player that has won the game (Player*) or NULL.
 */
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

// Testing only
void Board::print_board() {
    for (int i=0; i<this->height; i++) {
        for (int j=0; j<this->width; j++) {
            if (pieces[j][i] == NULL) {
                std::cout << "   " << std::endl;
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
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Testing
int main(int argc, char **argv) {
    Board b = Board(3,4);
    Player pl1 = Player();
    Player pl2 = Player();
    pl1.set_color(Red);
    pl2.set_color(Black);
    pl1.set_name("Brooklyn");
    pl2.set_name("Joey");
    Piece p1 = Piece(0,0,&pl1);
    Piece p2 = Piece(0,1,&pl1);
    Piece p3 = Piece(0,2,&pl2);
    Piece p4 = Piece(0,3,&pl1);

    Piece p5 = Piece(1,0,&pl2);
    Piece p6 = Piece(1,1,&pl1);
    Piece p7 = Piece(1,2,&pl2);
    Piece p8 = Piece(1,3,&pl2);

    Piece p9 = Piece(2,0,&pl1);
    Piece p10 = Piece(2,1,&pl2);
    Piece p11 = Piece(2,2,&pl1);

    b.place_piece(&p1);
    b.place_piece(&p2);
    b.place_piece(&p3);
    b.place_piece(&p4);
    b.place_piece(&p5);
    b.place_piece(&p6);
    b.place_piece(&p7);
    b.place_piece(&p8);
    b.place_piece(&p9);
    b.place_piece(&p10);
    b.place_piece(&p11);

    b.print_board();

    Player *winner = b.check_for_winner();

    if (winner == NULL) {
        std::cout << "no winner yet!" << std::endl;
    } else if (winner->get_color() == Red) {
        std::cout << "Red wins" << std::endl;
    } else if (winner->get_color() == Black) {
        std::cout << "Black wins" << std::endl;
    } else {
        std::cout << "error" << std::endl;
    }

    return 0;
}