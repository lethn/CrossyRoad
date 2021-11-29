#include "CAR.h"
#include "GAME.h"

CAR::CAR()
{
    shape[0] = new char[12] {' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' ', ' ', ' '};
    shape[1] = new char[12] {' ', ' ', '_', '/', ' ', ' ', 'L', '\\', '_', '_', ' '};
    shape[2] = new char[12] {' ', '\'', '=', 'o', '-', '-', '-', '-', 'o', '-', '\''};
}

CAR::CAR(int x, int y) : ENEMY(x, y)
{
    shape[0] = new char[12] {' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' ', ' ', ' '};
    shape[1] = new char[12] {' ', ' ', '_', '/', ' ', ' ', 'L', '\\', '_', '_', ' '};
    shape[2] = new char[12] {' ', '\'', '=', 'o', '-', '-', '-', '-', 'o', '-', '\''};
}

void CAR::renderShape()
{
    int pos = x;
    int leftMost = x < 4 ? 4 - x : 0;

    if (x < 0)
        pos = 4;
    else if (x < 4)
        pos = 4 - x;

    int rightMost = 12; //x + 12 > 118 ? 118 - x : 12;

    for (int i = 0; i < 3; ++i) 
    {
        gotoxy(pos, y + i);
        for (int j = leftMost; j < rightMost; ++j)
        {
            cout << shape[i][j];
        }
    }
}