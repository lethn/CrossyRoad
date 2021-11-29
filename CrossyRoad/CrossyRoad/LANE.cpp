#include "LANE.h"

LANE::LANE() : direction(0), redLight(0), speed(0) {}

LANE::LANE(bool direction, bool redLight, int speed) : direction(direction), redLight(redLight), speed(speed)
{

}