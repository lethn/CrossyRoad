#include "CAR.h"

CAR::CAR()
{
    for (int i = 0; i < 3; ++i)
        shape[i] = new char[10];

    strcpy(shape[0], "   __     ");
    strcpy(shape[1], ".-'--`-._ ");
    strcpy(shape[2], "'-O---O--'");
}