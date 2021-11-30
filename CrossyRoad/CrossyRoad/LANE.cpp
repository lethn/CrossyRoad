#include "LANE.h"

LANE::LANE() : direction(1), redLight(0), speed(1) {}

LANE::LANE(short direction, bool redLight, int speed) : direction(direction), redLight(redLight), speed(speed) {}

LANE::~LANE()
{
    for (ENEMY *enemy : enemies)
        delete enemy;
}

void LANE::moveEnemies()
{
    if (redLight)
        return;

    for (ENEMY *enemy : enemies)
    {
        enemy -> x += direction;
        enemy -> renderShape();
        Sleep(speed * 100);
    }
}