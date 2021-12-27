#include "LEVEL.h"
#include "GAME.h"

LEVEL::LEVEL(bool mode, int level) : mode(mode), level(level), currEnemy(0) 
{
    generateLevel();
}

LEVEL::LEVEL(bool mode, int level, int currEnemy) : mode(mode), level(level), currEnemy(currEnemy) {
    generateLevel();
}

void LEVEL::generateLevel() {
    if (mode)
        switch (level)
        {   
            case 1:
                maxEnemy = 10;
                minSpeed = 1400;
                maxSpeed = 1000;
                break;
            
            case 2:
                maxEnemy = 13;
                minSpeed = 1400;
                maxSpeed = 1000;
                break;
            
            case 3:
                maxEnemy = 15;
                minSpeed = 1200;
                maxSpeed = 800;
                break;
            
            case 4:
                maxEnemy = 15;
                minSpeed = 1000;
                maxSpeed = 600;
                break;
                
            default:
                maxEnemy = 17;
                minSpeed = 1000;
                maxSpeed = 600;
                break;
        }
    else 
        switch (level)
        {
            case 1:
                maxEnemy = 17; // t de theo tam linh
                minSpeed = 1000;
                maxSpeed = 600;
                break;
            
            case 2:
                maxEnemy = 20;
                minSpeed = 800;
                maxSpeed = 400;
                break;
            
            case 3:
                maxEnemy = 23;
                minSpeed = 800;
                maxSpeed = 400;
                break;
            
            case 4:
                maxEnemy = 25;
                minSpeed = 800;
                maxSpeed = 400;
                break;
            
            default:
                maxEnemy = 28;
                minSpeed = 700;
                maxSpeed = 300;
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

ENEMY *LEVEL::randNewEnemy(int x, short direction) {
    if (currEnemy == maxEnemy)
        return NULL;

    if (currEnemy < (maxEnemy)) {
        ++currEnemy;
        ENEMY * enemy = NULL;

        std::mt19937 rng(getSeed());
        std::uniform_int_distribution<unsigned> Vehicle(0, 2);
        std::uniform_int_distribution<unsigned> Animal(0, 3);
        
        if (direction == 1) {
            if (Vehicle(rng))
                enemy = new CAR(x);

            else
                enemy = new TRUCK(x);

        }
        else {
            switch (Animal(rng))
            {
                case 0:
                    enemy = new DOG(x);
                    break;

                case 1:
                    enemy = new BAT(x);
                    break;

                default:
                    enemy = new SHARK(x);
                    break;
            }
        }
        
        return enemy;
    }
    
    return NULL;
}
int LEVEL::getLevel() {
    return level;
}

