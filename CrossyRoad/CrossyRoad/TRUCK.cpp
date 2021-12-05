#include "TRUCK.h"

TRUCK::TRUCK()
{
    shape[0] = new char[13] {' ', ' ', '_', '_', '_', '_', '_', '_', ' ', ' ', ' ', ' '};
    shape[1] = new char[13] {' ', '|', ' ', ' ', ' ', ' ', ' ', 'L', '\\', '_', ' ', ' '};
    shape[2] = new char[13] {' ', '\'', '-', 'o', '-', '-', '-', '-', '-', 'o', '-', '\''};
}


TRUCK::TRUCK(int x) : ENEMY(x, 1)
{
    shape[0] = new char[13] {' ', ' ', '_', '_', '_', '_', '_', '_', ' ', ' ', ' ', ' '};
    shape[1] = new char[13] {' ', '|', ' ', ' ', ' ', ' ', ' ', 'L', '\\', '_', ' ', ' '};
    shape[2] = new char[13] {' ', '\'', '-', 'o', '-', '-', '-', '-', '-', 'o', '-', '\''};
}

void TRUCK::sound() {
    PlaySound(TEXT("Sound\\Car.wav"), NULL, SND_FILENAME | SND_ASYNC);
}