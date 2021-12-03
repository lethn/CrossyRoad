#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Library.h"
#include <algorithm>
#include "ENEMY.h"
#include "DOG.h"
#include "TRUCK.h"
#include "CAR.h"
//#include "BAT.h"

class LEVEL
{
    private:
        int level;
        int    maxEnemy, currEnemy;
        int minSpeed, maxSpeed;
        int redLightRate, greenLightRate;
        const int maxLevel = 5;

        void generateLevel();

    public:
        LEVEL();
        LEVEL(int level, int currEnemy);
        ~LEVEL() {};
        bool newLevel(int lv);
        bool nextLevel();
        ENEMY *randNewEnemy(int x, int y, short direction);
        int randSpeed();
        void decNEnemy(int d);

    friend class LANE;
    friend class MAP;
};

#endif
