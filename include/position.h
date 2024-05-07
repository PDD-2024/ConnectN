#ifndef POSITION
#define POSITION

/**
 * @brief Represents the (x, y) position of a playable piece.
 */
struct Position {
public:
    int x; /**< X position of the piece. */
    int y; /**< Y position of the piece. */
    Position();
    Position(int xPos, int yPos);
    ~Position();
};

#endif