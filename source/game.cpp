#include <iostream>
#include <cstdlib>
#include <memory>
#include "scene_manager.h"
#include "menu.h"
#include "game.h"
#include "language.h"
#include "settings_manager.h"

/**
 * @brief Construct a new Game of ConnectN.
 * 
 * Creates Players for the player1 and player2 fields and sets their colors. Sets the initial currentState value to be getPlayer1Name.
 * @see Player
 */
Game::Game() {
    board = NULL;
    winner = NULL;
    player1 = new Player();
    player1->set_color(Red);

    player2 = new Player();
    player2->set_color(Black);
    
    currentState = getPlayer1Name;
    playsNext = player1;
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
    std::string content;
    Language language = SettingsManager::get_instance()->get_language();
    if (currentState == getPlayer1Name) {
        content = GAME_CONTENT.at(language)[0];
    } else if (currentState == getPlayer2Name) {
        content = GAME_CONTENT.at(language)[1];
    } else if (currentState == getBoardSize) {
        content = GAME_CONTENT.at(language)[2];
    } else if (currentState == playGame) { 
        std::string board_string = board->board_to_string();
        content = board_string + GAME_CONTENT.at(language)[3] + std::string(playsNext->get_name()) + GAME_CONTENT.at(language)[4];
    } else if (currentState == gameOver) {
        if (winner == NULL) {
            content = "\n\n\n\n" + board->board_to_string() + GAME_CONTENT.at(language)[5] + PLAY_GAME + GAME_CONTENT.at(language)[6] + RETURN_TO_MENU + GAME_CONTENT.at(language)[7] + EXIT + GAME_CONTENT.at(language)[8];
        } else {
            content = "\n\n\n\n" + board->board_to_string() + GAME_CONTENT.at(language)[9] + winner->get_name() + GAME_CONTENT.at(language)[10] + PLAY_GAME + GAME_CONTENT.at(language)[6] + RETURN_TO_MENU + GAME_CONTENT.at(language)[7] + EXIT + GAME_CONTENT.at(language)[8];
        }
    } else {
        // State has not been properly initialized. Print error message.
        content = GAME_ERRORS.at(language)[0];
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
    Language language = SettingsManager::get_instance()->get_language();
    
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
            std::cout << GAME_ERRORS.at(language)[1] << std::endl;
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

        if (success == -1) {// If the column was out of bounds, prompt the user to enter a new value and recursively call handle_input
            int max_col_val = this->board->get_width() - 1;
            std::cout << GAME_ERRORS.at(language)[2] << max_col_val << ".\n\n" << std::endl;
            handle_input();
        } else if (success == 1) { // If the column is already full, prompt the user to enter a new value and recursively call handle_input
            std::cout << GAME_ERRORS.at(language)[3] << std::endl;
            handle_input();
        } else {// If the operation was successful, check if the game is over
            check_for_game_over();
        }

    } else if (currentState == gameOver) {
        // Set up for the next Game
        delete board;
        board = NULL;
        winner = NULL;
        currentState = getPlayer1Name;
        playsNext = player1;
        if (input == RETURN_TO_MENU) { // Return to Menu
            SceneManager* sm = SceneManager::get_instance();
            sm->set_scene(Menu::get_instance());
        } else if (input == EXIT) {
            // TODO: do this a little nicer, maybe return control to ProgramManager
            exit(0);
        } else if (input != PLAY_GAME) {
            std::cout << GAME_ERRORS.at(language)[4] << std::endl;
        }
    } else {
        // State has not been properly initialized. Print error message and exit.
        std::cout << GAME_ERRORS.at(language)[0] << std::endl;
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

void Game::check_for_game_over() {
    bool full = board->check_if_full();
    if (full) {
        currentState = gameOver;
    } else {
        Player *won = this->board->check_for_winner();
        if (won != NULL) {
            currentState = gameOver;
            winner = won;
        }
    }
}