#ifndef _TRUCK_H_
#define _TRUCK_H_

#include "ENEMY.h"

//Starting x position for the truck is -7

class TRUCK : public ENEMY
{
    private:

    public:
        TRUCK();
        TRUCK(int x, int y);

};


#endif