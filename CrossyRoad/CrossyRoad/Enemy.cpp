#include "ENEMY.h"

ENEMY::ENEMY() : shape(new char*[3]()), outOfMap(false) {}

ENEMY::ENEMY(int x, int y) : shape(shape = new char*[3]()), x(x), y(y), outOfMap(false) {}

ENEMY::~ENEMY()
{
    for (int i = 0; i < 3; ++i)
        delete [] shape[i];

    delete [] shape;
}