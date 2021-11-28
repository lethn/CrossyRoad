#ifndef _LANE_H_
#define _LANE_H_

#include "Library.h"
#include "ENEMY.h"

class LANE
{
    private: 
        vector<ENEMY*> enemies;
        bool direction;
        bool redLight;
        int speed;

    public:
        LANE();

};

#endif