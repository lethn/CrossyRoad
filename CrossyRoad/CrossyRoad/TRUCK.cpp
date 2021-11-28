#include "TRUCK.h"

TRUCK::TRUCK()
{
    for (int i = 0; i < 3; ++i)
        shape[i] = new char[12];

    shape[0][0] = ' ';
    shape[0][1] = '_';
    shape[0][2] = '_';
    shape[0][3] = '_';
    shape[0][4] = '_';
    shape[0][5] = '_';
    shape[0][6] = '_';
    shape[0][7] = '_';
    shape[0][8] = ' ';
    shape[0][9] = ' ';
    shape[0][10] = ' ';
    shape[0][11] = '\0';

    shape[1][0] = '|';
    shape[1][1] = ' ';
    shape[1][2] = ' ';
    shape[1][3] = ' ';
    shape[1][4] = '|';
    shape[1][5] = ' ';
    shape[1][6] = ' ';
    shape[1][7] = 'L';
    shape[1][8] = '\\';
    shape[1][9] = '_';
    shape[1][10] = ' ';
    shape[1][11] = '\0';

    shape[2][0] = '\'';
    shape[2][1] = '-';
    shape[2][2] = 'o';
    shape[2][3] = '-';
    shape[2][4] = '-';
    shape[2][5] = '-';
    shape[2][6] = '-';
    shape[2][7] = '-';
    shape[2][8] = 'o';
    shape[2][9] = '-';
    shape[2][10] = '\'';
    shape[2][11] = '\0';

}


TRUCK::TRUCK(int x, int y) : ENEMY(x, y)
{
    for (int i = 0; i < 3; ++i)
        shape[i] = new char[12];

    shape[0][0] = ' ';
    shape[0][1] = '_';
    shape[0][2] = '_';
    shape[0][3] = '_';
    shape[0][4] = '_';
    shape[0][5] = '_';
    shape[0][6] = '_';
    shape[0][7] = '_';
    shape[0][8] = ' ';
    shape[0][9] = ' ';
    shape[0][10] = ' ';
    shape[0][11] = '\0';

    shape[1][0] = '|';
    shape[1][1] = ' ';
    shape[1][2] = ' ';
    shape[1][3] = ' ';
    shape[1][4] = '|';
    shape[1][5] = ' ';
    shape[1][6] = ' ';
    shape[1][7] = 'L';
    shape[1][8] = '\\';
    shape[1][9] = '_';
    shape[1][10] = ' ';
    shape[1][11] = '\0';

    shape[2][0] = '\'';
    shape[2][1] = '-';
    shape[2][2] = 'o';
    shape[2][3] = '-';
    shape[2][4] = '-';
    shape[2][5] = '-';
    shape[2][6] = '-';
    shape[2][7] = '-';
    shape[2][8] = 'o';
    shape[2][9] = '-';
    shape[2][10] = '\'';
    shape[2][11] = '\0';
}