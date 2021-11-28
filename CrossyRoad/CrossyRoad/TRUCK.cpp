#include "TRUCK.h"

TRUCK::TRUCK()
{
    for (int i = 0; i < 3; ++i)
        shape[i] = new char[12];

    strcpy(shape[0], " _______   ");
    strcpy(shape[1], "|   |  L\\_ ");
    strcpy(shape[2], "'-O-----O-'");
}


TRUCK::TRUCK(int x, int y) : ENEMY(x, y)
{
    for (int i = 0; i < 3; ++i)
        shape[i] = new char[12];

    strcpy(shape[0], " _______   ");
    strcpy(shape[1], "|   |  L\\_ ");
    strcpy(shape[2], "'-O-----O-'");
}