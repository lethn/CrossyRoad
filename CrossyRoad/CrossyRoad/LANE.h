#ifndef _LANE_H_
#define _LANE_H_

#include "Library.h"
#include "ENEMY.h"

//First Lane x = 4, y = 31

class LANE
{
    private: 
        vector<ENEMY*> enemies;
        short direction;
        bool redLight;
        int speed;

    public:
        LANE();
        LANE(short direction, bool redLight, int speed);
        ~LANE();

        void generateLane(int frameTime);
        void moveEnemies(int frameTime);

    friend class GAME;
    friend class MAP;
};

#endif