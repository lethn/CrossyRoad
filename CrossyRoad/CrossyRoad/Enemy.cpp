#include "ENEMY.h"

ENEMY::ENEMY() : shape(NULL), outOfMap(false) {}

ENEMY::ENEMY(int x, int y) : x(x), y(y), outOfMap(false)
{
    shape = new char*[3]();

    for (int i = 0; i < 3; ++i)
        shape[i] = new char[6]();
}

ENEMY::~ENEMY()
{
    for (int i = 0; i < 3; ++i)
        delete [] shape[i];

    delete [] shape;
}