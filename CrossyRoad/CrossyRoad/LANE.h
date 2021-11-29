#ifndef _LANE_H_
#define _LANE_H_

#include "Library.h"
#include "ENEMY.h"

//First Lane x = 4, y = 31

class LANE
{
    private: 
        vector<ENEMY*> enemies;
        bool direction;
        bool redLight;
        int speed;

    public:
        LANE();
        LANE(bool direction, bool redLight, int speed);
        
};

#endif