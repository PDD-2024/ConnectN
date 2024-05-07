#include "position.h"

/**
 * @brief Default constructor to create a position object.
 * 
 */
Position::Position() {}

/**
 * @brief Construct a new position object with X and Y positions.
 * 
 * @param xPos 
 * @param yPos 
 */
Position::Position(int xPos, int yPos) {
    this->x = xPos;
    this->y = yPos;
}

Position::~Position() {}
