#include <iostream>
#include <cstdlib>
#include <memory>
#include "game.h"

/**
 * @brief Construct a new Game of ConnectN.
 * 
 * Creates Players for the player1 and player2 fields and sets their colors. Sets the initial currentState value to be getPlayer1Name.
 * @see Player
 */
Game::Game() {
    board = NULL;
    player1 = new Player();
    player1->set_color(Red);

    player2 = new Player();
    player2->set_color(Black);
    
    currentState = getPlayer1Name;
    this->playsNext = this->player1;
}

/**
 * @brief Cleans up the Game and associated parameters.
 * 
 */
Game::~Game() {
    delete board;
    delete player1;
    delete player2;

    board = NULL;
    player1 = NULL;
    player2 = NULL;
}

/**
 * @brief Completes a player's turn by putting their piece on the board in a specified column.
 * A piece will be placed in the column on the board, unless the column is out of bounds or already full. The value of playsNext is updated to prepare for the other player's turn.
 * @param column The column where the piece will be placed
 * @return 0 for success, -1 for an out-of-bounds column, 1 for a full column
 */
int Game::player_turn(int column) {
    // Return error value if the column is out of bounds
    if (column < 0 || column >= this->board->get_width()) {
        return -1;
    }

    // Place the piece in the appropriate column, return error value if it is already full
    bool success = this->board->place_piece(column, this->playsNext);
    if (!success) {
        return 1;
    }

    // Switch to the other player's turn
    if (this->playsNext == player1) {
        this->playsNext = player2;
    } else {
        this->playsNext = player1;
    }
    return 0;
}

/**
 * @brief Renders the current content to the screen
 * @note Unlike the Credits, Menu, and Settings implementations of the Scene interface, the content printed depends on the state of the Game, and so this method will not always produce the same results.
 * @see Credits
 * @see Menu
 * @see Settings
 * @see Scene
 */
void Game::render() {
    if (currentState == getPlayer1Name) {
        content = std::string("\nEnter player1 name:");
    } else if (currentState == getPlayer2Name) {
        content = std::string("\nEnter player2 name:");
    } else if (currentState == getBoardSize) {
        content = std::string("\nEnter N (the number of tiles to connect in order to win):");
    } else if (currentState == playGame) { 
        board->print_board();
        content = std::string("\nIt's ") + std::string(playsNext->get_name()) + std::string("'s turn. Enter the number of the column where you would like to play:");
    } else {
        // State has not been properly initialized. Print error message.
        content = std::string("Error: illegal game state!");
    }
    std::cout << content << std::endl;
}

/**
 * @brief Accept and handle user input
 * 
 * Takes in the user input. Depending on the state of the Game, uses it to set one of the players' names, set up a board of the appropriate size, or play a move. If in one of the set up states (getPlayer1Name, getPlayer2Name, or getBoardSize), update to next state
 * @see Scene
 */
void Game::handle_input() {
    std::string input;
    getline(std::cin, input);

    if (currentState == getPlayer1Name) {
        player1->set_name(input);
        set_state(getPlayer2Name);

    } else if (currentState == getPlayer2Name) {
        player2->set_name(input);
        set_state(getBoardSize);

    } else if (currentState == getBoardSize) {
        int board_size = std::atoi(input.c_str());
        
        // If the board size is too small, prompt the user to enter a new value and recursively call handle_input
        if (board_size < 1){
            std::cout << "\nThat board size is invalid. Please enter a number greater than 1:" << std::endl;
            handle_input();
        } else {
            board = new Board(board_size);

            // Update state
            set_state(playGame);
        }

    } else if (currentState == playGame) {
        // Place a piece in the requested column
        int column = atoi(input.c_str());
        int success = player_turn(column);

        // If the column was out of bounds, prompt the user to enter a new value and recursively call handle_input
        if (success == -1) {
            int max_col_val = this->board->get_width() - 1;
            std::cout << "\nThat column value is invalid. Please enter a number between 0 and " << max_col_val << std::endl;
            handle_input();
        } else if (success == 1) {
            std::cout << "\nThat column is full. Please choose another column:" << std::endl;
            handle_input();
        }

    } else {
        // State has not been properly initialized. Print error message and exit.
        std::cout << "'nError: illegal game state!" << std::endl;
        exit(1);
    }
}

/**
 * @brief Set the state of the game
 * 
 * @param s The new state of the game
 */
void Game::set_state(State s) {
    currentState = s;
}

Game* Game::s_game_instance = nullptr;

/**
 * @brief Gets the singleton instance of this class
 * 
 * @return s_game_instance, the static singleton instance
 */
Game* Game::get_instance() {
    if (s_game_instance == nullptr) {
        s_game_instance = new Game();
    }

    return s_game_instance;
}