#ifndef GAME
#define GAME

#include <iostream>
#include "scene.h"
#include "position.h"
#include "color.h"
#include "board.h"
#include "player.h"

enum State {
    getPlayer1Name, 
    getPlayer2Name,
    getBoardSize,
    playGame
};

class Game : public Scene {
private:
    Board *board;
    Player *player1;
    Player *player2;
    Player *playsNext;
    State currentState;
    static Game* s_game_instance;
    Game();
public:
    ~Game();
    int player_turn(int column);
    void render() override;
    void handle_input() override;
    void set_state(State s);
    static Game* get_instance();
};

#endif