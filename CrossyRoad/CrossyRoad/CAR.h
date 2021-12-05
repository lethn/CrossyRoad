#ifndef _CAR_H_
#define _CAR_H_

#include "ENEMY.h"

//Starting x position for the car is -6

class CAR : public ENEMY
{
    public:
        CAR();
        CAR(int x);
        
        void sound();
    
};


#endif