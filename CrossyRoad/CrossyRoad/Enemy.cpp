#include "ENEMY.h"
#include "GAME.h"

ENEMY::ENEMY() : shape(new char*[3]()), outOfMap(false) {}

ENEMY::ENEMY(int x, int y) : shape(new char*[3]()), x(x), y(y), outOfMap(false) {}

ENEMY::~ENEMY()
{
    for (int i = 0; i < 3; ++i)
        delete [] shape[i];

    delete [] shape;
}

void ENEMY::renderShape()
{
    int leftMost = x < LEFT_BORDER ? LEFT_BORDER - x : 0;

    int pos = x < LEFT_BORDER ? LEFT_BORDER : x;

    int rightMost = x + (int)strlen(shape[0]) > RIGHT_BORDER ? RIGHT_BORDER - x + 1 : strlen(shape[0]) + 1;

    if (leftMost >= rightMost)
        return;

    for (int i = 0; i < 3; ++i) 
    {
        gotoxy(pos, y + i);
        for (int j = leftMost; j < rightMost; ++j)
        {
            cout << shape[i][j];
        }
    }
}