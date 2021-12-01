#include "LANE.h"

LANE::LANE() : direction(1), redLight(0), speed(1) {}

LANE::LANE(short direction, bool redLight, int speed) : direction(direction), redLight(redLight), speed(speed) {}

LANE::~LANE()
{
    for (ENEMY *enemy : enemies)
        delete enemy;
}

void LANE::generateEnemies(int frameTime)
{

}

void LANE::moveEnemies(int frameTime)
{
    if (redLight)
        return;
    
    if (frameTime % speed != 0)
        return;

    for (ENEMY *enemy : enemies)
    {
        enemy -> x += direction;
        enemy -> renderShape();
    }
}