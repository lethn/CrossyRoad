#pragma once

#include "ENEMY.h"

class DOG : public ENEMY
{

public:
    DOG();
    DOG(int x);

    void sound();
};