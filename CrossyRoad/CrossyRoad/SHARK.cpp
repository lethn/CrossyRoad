#include"SHARK.h"
// ___/(_____/
//>`_ ____v--\
//    \(

SHARK::SHARK() {
    shape[0] = new char[14]{' ', '_','_','_','/','(','_', '_', '_', '_', '_', '/',' '};
    shape[1] = new char[14]{'>','`','_', ' ','_', '_', '_', '_', 'v','-','-','\\',' '};
    shape[2] = new char[14]{ ' ',' ',' ',' ','\\','(',' ', ' ', ' ', ' ', ' ', ' ',' '};
}

SHARK::SHARK(int x) : ENEMY(x, 0) {
    shape[0] = new char[14]{' ', '_','_','_','/','(','_', '_', '_', '_', '_', '/',' '};
    shape[1] = new char[14]{'>','`','_', ' ','_', '_', '_', '_', 'v','-','-','\\',' '};
    shape[2] = new char[14]{ ' ',' ',' ',' ','\\','(',' ', ' ', ' ', ' ', ' ', ' ',' '};
}

void SHARK::sound() {
    PlaySound(TEXT("Sound\\Shark.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
int SHARK::isWhat() {
    return 4;
}


