#include "LANE.h"
#include "GAME.h"

LANE::LANE() : direction(1), redLight(0), speed(1) {}

LANE::LANE(short direction, bool redLight, int speed) : direction(direction), redLight(redLight), speed(speed) {}

LANE::~LANE()
{
    for (ENEMY *enemy : enemies)
        delete enemy;
}

int LANE::moveEnemies(int frameTime)
{
    int outOfMap = 0;

    // std::mt19937 rng(getSeed());
	// std::uniform_int_distribution<unsigned> random(0, INT_MAX);

    // if ((redLight && random(rng) % greenLightRate == 0) || (!redLight && random(rng) % redLightRate == 0) || frameTime == 0)
    //     redLight = !redLight;
    
    // if (redLight)
    //     return 0;
    
    if (frameTime % speed != 0)
        return 0;

    for (int i = 0; i < enemies.size(); ++i)
    {
        enemies[i] -> x += direction;
        if (enemies[i] -> checkOutOfBounds())
        {
            enemies.erase(enemies.begin() + i);
            ++outOfMap;
        }
        else
            enemies[i] -> renderShape();
    }

    return outOfMap;
}