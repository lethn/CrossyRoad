#include "CAR.h"

CAR::CAR()
{
    shape[0] = new char[12] {' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' ', ' ', ' '};
    shape[1] = new char[12] {' ', ' ', '_', '/', ' ', ' ', 'L', '\\', '_', '_', ' '};
    shape[2] = new char[12] {' ', '\'', '=', 'o', '-', '-', '-', '-', 'o', '-', '\''};
}

CAR::CAR(int x, int y) : ENEMY(x, y, 1)
{
    shape[0] = new char[12] {' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' ', ' ', ' '};
    shape[1] = new char[12] {' ', ' ', '_', '/', ' ', ' ', 'L', '\\', '_', '_', ' '};
    shape[2] = new char[12] {' ', '\'', '=', 'o', '-', '-', '-', '-', 'o', '-', '\''};
}

void CAR::sound() {
    PlaySound(TEXT("Sound\\Car.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
