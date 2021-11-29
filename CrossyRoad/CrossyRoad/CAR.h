#ifndef _CAR_H_
#define _CAR_H_

#include "ENEMY.h"

class CAR : public ENEMY
{
    public:
        CAR();
        CAR(int x, int y);
        
        void renderShape();
    
};


#endif