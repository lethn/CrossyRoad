#include "ENEMY.h"
#include "GAME.h"

ENEMY::ENEMY() : shape(new char*[3]()), type(type) {}

ENEMY::ENEMY(int x, bool type) : shape(new char*[3]()), x(x), type(type) {}

// ENEMY::ENEMY(const ENEMY& other) : shape(new char*[3]()), x(other.x), type(other.type) 
// {
//     int n = strlen(other.shape[0]) + 1;
//     for (int i = 0; i < 3; ++i)
//     {
//         shape[i] = new char[n];
//         for (int j = 0; j < n; ++j)
//         {
//             shape[i][j] = other.shape[i][j];
//         }
//     }
// }

ENEMY::~ENEMY()
{
    for (int i = 0; i < 3; ++i)
        delete [] shape[i];

    delete [] shape;
}

bool ENEMY::checkOutOfMap()
{
    return x < -13 || x > 123;
}

bool ENEMY::checkAtSpawn()
{
    return  x < 7 || x > 100;
}

void ENEMY::renderShape(int y)
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