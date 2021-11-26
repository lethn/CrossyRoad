#include "Enemy.h"

Enemy::Enemy() : outMap(false) 
{
    shape = new char*[3]();

    for (int i = 0; i < 3; ++i)
        shape[i] = new char[6]();
}

Enemy::Enemy(int x, int y) : x(x), y(y), outMap(false)
{
    shape = new char*[3]();

    for (int i = 0; i < 3; ++i)
        shape[i] = new char[6]();
}

Enemy::~Enemy()
{
    for (int i = 0; i < 3; ++i)
        delete [] shape[i];

    delete [] shape;
}