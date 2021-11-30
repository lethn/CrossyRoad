#include "LANE.h"
#include "Library.h"

LANE::LANE() : direction(1), redLight(0), speed(0) {}

LANE::LANE(short direction, bool redLight, int speed) : direction(direction), redLight(redLight), speed(speed) {}

LANE::~LANE()
{
    for (ENEMY *enemy : enemies)
        delete enemy;
}

