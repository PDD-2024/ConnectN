#include <assert.h>
#include "credits.h"
#include "color.h"
#include "player.h"
#include "menu.h"
#include "board.h"
#include "scene_manager.h"
#include "piece.h"
#include "game.h"
#include "program_manager.h"
#include "settings_manager.h"
#include <fstream>
#include <iostream>
#include <string>
 
using namespace std;
void unit_tests() {
    // Player
    Player p = Player();
    p.set_name("player");
    p.set_color(Red);
    assert(p.get_name() == "player");
    assert(p.get_color() == Red);

    // Position
    Position pos = Position(2,3);
    assert(pos.x == 2);
    assert(pos.y == 3);
}

void integration_tests() {
    // Redirect cin to take input from test text file
    // Open file
    fstream file;
    file.open("../test/integration_test_input.txt", ios::in);
    // Backup streambuffers
    streambuf* coutSB = cout.rdbuf();
    streambuf* cinSB = cin.rdbuf();
    // Get the streambuffer of the file
    streambuf* fileSB = file.rdbuf();
    // Redirect cin to file
    cin.rdbuf(fileSB);

    // Piece
    Player *p = new Player();
    p->set_name("player");
    p->set_color(Red);
    Piece piece = Piece(2,3,p);
    assert(piece.get_position().x == 2);
    assert(piece.get_position().y == 3);
    assert(piece.get_player() == p);
    delete p;

    // Board
    Board *b = new Board(4);
    assert(b->get_n() == 4);
    assert(b->get_width() == 7);
    // Check horizontal wins
    assert(b->check_for_winner() == NULL);
    b->place_piece(2,p);
    b->place_piece(2,p);
    b->place_piece(2,p);
    b->place_piece(2,p);
    assert(b->check_for_winner() == p);
    delete b;
    // Check vertical wins
    b = new Board(5);
    assert(b->check_for_winner() == NULL);
    b->place_piece(2,p);
    b->place_piece(3,p);
    b->place_piece(4,p);
    b->place_piece(5,p);
    b->place_piece(6,p);
    assert(b->check_for_winner() == p);
    delete b;
    // Check diagonal wins
    Player *p2 = new Player();
    p->set_name("player2");
    p->set_color(Black);
    b = new Board(3);
    assert(b->check_for_winner() == NULL);
    b->place_piece(0,p);
    b->place_piece(1,p2);
    b->place_piece(1,p);
    b->place_piece(2,p);
    b->place_piece(2,p2);
    b->place_piece(2,p);
    assert(b->check_for_winner() == p);
    b = new Board(3);
    assert(b->check_for_winner() == NULL);
    b->place_piece(0,p);
    b->place_piece(0,p2);
    b->place_piece(0,p);
    b->place_piece(1,p2);
    b->place_piece(1,p);
    b->place_piece(2,p);
    assert(b->check_for_winner() == p);
    assert(!b->check_if_full());
    b->place_piece(0,p2);
    b->place_piece(0,p);
    for (int i=0; i<3; i++) {
        b->place_piece(1,p2);
    }
    for (int i=0; i<4; i++) {
        b->place_piece(2,p2);
    }
    for (int i=0; i<6; i++) {
        b->place_piece(3,p2);
    }
    for (int i=0; i<6; i++) {
        b->place_piece(4,p2);
    }
    for (int i=0; i<6; i++) {
        b->place_piece(5,p2);
    }
    assert(b->check_if_full());

    // Credits 
    SceneManager* sm = SceneManager::get_instance();
    Credits *c = Credits::get_instance();
    c->handle_input();
    assert(sm->currentScene == Menu::get_instance());

    // Menu
    Menu *m = Menu::get_instance();
    m->handle_input();
    assert(sm->currentScene == Game::get_instance());
    m->handle_input();
    assert(sm->currentScene == Settings::get_instance());
    m->handle_input();
    assert(sm->currentScene == Credits::get_instance());

    // Settings
    Settings *s = Settings::get_instance();
    string l1 = SettingsManager::get_instance()->get_language_str();
    s->handle_input();
    string l2 = SettingsManager::get_instance()->get_language_str();
    assert(l1 != l2);
    sm->currentScene = s;
    s->handle_input();
    assert(sm->currentScene == Menu::get_instance());
    sm->currentScene = s;
    s->handle_input();
    assert(sm->currentScene == Menu::get_instance());

    // Settings manager
    SettingsManager *stm = SettingsManager::get_instance();
    stm->retrieve_settings();
    Language currentLanguage = stm->get_language();
    stm->change_settings();
    stm->save_settings();
    stm->retrieve_settings();
    Language newLanguage = stm->get_language();
    assert(currentLanguage != newLanguage);

    // Redirect cin back to screen
    cin.rdbuf(cinSB);
    file.close();
}

void system_tests() {
    // Redirect cin to take input from test file and cout to print output to another file
    // Open files
    fstream fileIn;
    fstream fileOut;
    fileIn.open("../test/system_test_input.txt", ios::in);
    fileOut.open("../test/system_test_output.txt", ios::out);
    // Backup streambuffers
    streambuf* coutSB = cout.rdbuf();
    streambuf* cinSB = cin.rdbuf();
    // Get the streambuffer of the input file
    streambuf* fileSBIn = fileIn.rdbuf();
    // Redirect cin to file
    cin.rdbuf(fileSBIn);
    // Get the streambuffer of the output file
    streambuf* fileSBOut = fileOut.rdbuf();
    // Redirect cout to file
    cout.rdbuf(fileSBOut);

    ProgramManager *pm = ProgramManager::get_instance();
    pm->init();
    pm->init();
    pm->init();

    // Redirect cin and cout back to screen
    cin.rdbuf(cinSB);
    fileIn.close();
    cout.rdbuf(coutSB);
    fileOut.close();

    // Read content of output file and conpare to the expected output
    ifstream realOutputFile("../test/system_test_output.txt");
    ifstream expectedOutputFile("../test/system_test_expected_output.txt"); 
  
    string realLine;
    string expectedLine;  
     
    while (getline(realOutputFile,realLine)){
        getline(expectedOutputFile, expectedLine);
         assert(realLine == expectedLine);
    } 
    while (getline(expectedOutputFile,expectedLine)){
        getline(realOutputFile, realLine);
         assert(realLine == expectedLine);
    } 
  
    // Close the file 
    realOutputFile.close();
    expectedOutputFile.close(); 
}

int main(int, char**){

    unit_tests();
    integration_tests();
    system_tests();
    
}
