#ifndef POSITION
#define POSITION

struct Position {
public:
    int x;
    int y;
    Position();
    Position(int xPos, int yPos);
    ~Position();
};

#endif