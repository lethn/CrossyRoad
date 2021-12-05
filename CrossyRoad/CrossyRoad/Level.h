#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Library.h"
#include "ENEMY.h"
#include "DOG.h"
#include "TRUCK.h"
#include "CAR.h"
//#include "BAT.h"

class LEVEL
{
    private:
        int level;
        int maxEnemy, currEnemy;
        int minSpeed, maxSpeed;
        const int maxLevel = 5;

        void generateLevel();

    public:
        LEVEL(int level = 1);
        LEVEL(int level, int currEnemy);
        ~LEVEL() {};
        bool newLevel(int lv);
        bool nextLevel();
        ENEMY *randNewEnemy(int x, short direction);
        int getLevel();

    friend class LANE;
    friend class MAP;
};

#endif
