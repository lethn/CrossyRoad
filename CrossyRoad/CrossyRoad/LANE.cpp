#include "LANE.h"
#include "GAME.h"

LANE::LANE() : direction(1), redLight(0), speed(1) {}

LANE::LANE(short direction, bool redLight, int speed) : direction(direction), redLight(redLight), speed(speed) {}

LANE::~LANE()
{
    for (ENEMY *enemy : enemies)
        delete enemy;
}

void LANE::renderTrafficLight()
{
    txtColor(redLight ? 12 : 10);
    gotoxy(direction == 1 ? 121 : 0, y + 1);
    
    cout << (char)254;
    txtColor(7);
}

int LANE::moveEnemies(int frameTime)
{
    int outOfMap = 0;

    if ((redLight && frameTime % greenLightRate == 0) || (!redLight && frameTime % redLightRate == 0))
    {
        redLight = !redLight;
        renderTrafficLight();
    }
        
    if (redLight)
        return 0;
    
    if (frameTime % speed != 0)
        return 0;

    for (int i = 0; i < enemies.size(); ++i)
    {
        enemies[i] -> x += direction;
        if (enemies[i] -> checkOutOfMap())
        {
            enemies.erase(enemies.begin() + i);
            ++outOfMap;
        }
        else
            enemies[i] -> renderShape(y);
    }

    return outOfMap;
}