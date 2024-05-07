#include "player.h"

Player::Player() {}
Player::~Player() {}

/**
 * @brief Configures the name of the player.
 * 
 * @param n Name of the player.
 */
void Player::set_name(std::string n) {
    this->name = n;
}

/**
 * @brief Configures the color of the player.
 * @see Color
 * @param c Color of the player.
 */
void Player::set_color(Color c) {
    this->color = c;
}

/**
 * @brief Gets the color associated with the player.
 * @see Color
 * @return Color of the player.
 */
Color Player::get_color() {
    return this->color;
}

/**
 * @brief Gets the color associated with the player.
 * @return Name of the player.
 */
std::string Player::get_name() {
    return this->name;
}