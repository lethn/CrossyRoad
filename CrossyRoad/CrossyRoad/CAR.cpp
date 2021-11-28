#include "CAR.h"

CAR::CAR()
{
    for (int i = 0; i < 3; ++i)
        shape[i] = new char[11];

    strcpy(shape[0], "   ___    ");
    strcpy(shape[1], " _/  L\\__ ");
    strcpy(shape[2], "'=o----o-'");
}

CAR::CAR(int x, int y) : ENEMY(x, y)
{
    for (int i = 0; i < 3; ++i)
        shape[i] = new char[10];

    strcpy(shape[0], "   ___    ");
    strcpy(shape[1], " _/  L\\__ ");
    strcpy(shape[2], "'=o----o-'");
}