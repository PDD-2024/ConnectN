#ifndef GAME
#define GAME

#include <iostream>
#include "scene.h"
#include "position.h"
#include "color.h"
#include "board.h"
#include "player.h"

/**
 * @brief Enum to represent the states that the Game can be in
 * 
 * @see Game
 */
enum State {
    getPlayer1Name, 
    getPlayer2Name,
    getBoardSize,
    playGame,
    gameOver
};

/**
 * @brief Class that implements scene to create the game scene.
 * 
 * The main game scene. Can have one of several states to allow the user to choose the players' names, 
 * set the board size, play the game, and then play again, exit, or return to the menu. When in playing 
 * state, shows players a representation of the board and lets them take turns placing pieces in columns. 
 * This state is exited when the check for game over returns successfully.
 * 
 * @see Scene
 * @see Menu
 * @see Board
 * @see Player
 */
class Game : public Scene {
private:
    Board *board;
    Player *player1;
    Player *player2;
    Player *playsNext;
    Player *winner;
    State currentState;
    int roundNumber;
    std::string PLAY_GAME = "1";
    std::string RETURN_TO_MENU = "2";
    std::string EXIT = "3";

    static Game* s_game_instance;
    Game();
public:
    ~Game();
    int player_turn(int column);
    void render() override;
    void handle_input() override;
    void set_state(State s);
    static Game* get_instance();
    void check_for_game_over();
};

#endif