#include "LEVEL.h"

LEVEL::LEVEL() :
    level(1),
    maxEnemy(5), currEnemy(0),
    minSpeed(700), maxSpeed(900),
    redLightRate(5), greenLightRate(10) {}

LEVEL::LEVEL(int level, int currEnemy) : level(level), currEnemy(currEnemy) {
    generateLevel();
}

void LEVEL::generateLevel() {
    switch (level)
    {
        case 1:
            maxEnemy = 5; // t de theo tam linh
            maxSpeed = 900;
            minSpeed = 700;
            redLightRate = 5;
            greenLightRate = 10;
            break;
        
        case 2:
            maxEnemy = 7;
            maxSpeed = 650;
            minSpeed = 500;
            redLightRate = 10;
            greenLightRate = 15;
            break;
        
        case 3:
            maxEnemy = 9;
            maxSpeed = 450;
            minSpeed = 300;
            redLightRate = 15;
            greenLightRate = 15;
            break;
        
        case 4:
            maxEnemy = 11;
            maxSpeed = 350;
            minSpeed = 200;
            redLightRate = 20;
            greenLightRate = 10;
            break;
        
        default:
            maxEnemy = 11;
            maxSpeed = 200;
            minSpeed = 100;
            redLightRate = 25;
            greenLightRate = 10;
            break;
    }
}

bool LEVEL::newLevel(int lv) {
    if (lv > maxLevel) return false;
    level = lv;
    currEnemy = 0;
    generateLevel();
    return true;
}

bool LEVEL::nextLevel() {
    if (level == maxLevel) return false;
    ++level;
    currEnemy = 0;
    return true;
}

ENEMY *LEVEL::randNewEnemy(int x, int y, bool type) {
    if (currEnemy == maxEnemy)
        return NULL;

    if (currEnemy < (maxEnemy)) {
        ++currEnemy;
        ENEMY * enemy = NULL;
        
        if (type) {
            if (rand() % 2)
                enemy = new CAR(x, y, type);

            else
                enemy = new TRUCK(x, y, type);

        }
        else {
            switch (rand() % 3)
            {
                case 0:
                    enemy = new DOG(x, y, type);
                    break;

                // case 1:
                //     enemy = new BAT(x, y, type);
                //     break;

                // default:
                //     // enemy = new (x, y, type);
                //     break;
            }
        }
        
        return enemy;
    }
    
    return NULL;
}

int LEVEL::randSpeed()
{
    int k = maxSpeed - minSpeed;
    return rand() % minSpeed + k ;

}

void LEVEL::decNEnemy(int d) {
    currEnemy -= d;
}
