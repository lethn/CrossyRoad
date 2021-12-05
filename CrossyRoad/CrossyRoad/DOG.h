#pragma once

#include "ENEMY.h"

class DOG : public ENEMY
{

public:
    DOG();
    DOG(int x);
    int isWhat();
    void sound();
};