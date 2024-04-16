#include "player.h"

Player::Player() {}
Player::~Player() {}
void Player::set_name(std::string n) {
    this->name = n;
}
void Player::set_color(Color c) {
    this->color = c;
}
Color Player::get_color() {
    return this->color;
}