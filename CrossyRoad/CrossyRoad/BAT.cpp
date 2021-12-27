#include "BAT.h"
//  _  ,,  _
// /`'=)(='`\
///.-.\  /.-.\

BAT::BAT() {
    shape[0] = new char[14]{' ', ' ','_', ' ', ' ',',',',',' ',' ','_',' ', ' ', ' '};
    shape[1] = new char[14]{' ','/','`','\'','=',')','(','=','\'','`','\\',' ', ' '};
    shape[2] = new char[14]{'/','.','-','.','\\',' ',' ','/','.','-','.','\\',' '};
}

BAT::BAT(int x) : ENEMY(x, 0) {
    shape[0] = new char[14]{ ' ',' ','_', ' ', ' ',',',',',' ',' ','_',' ', ' ', ' ' };
    shape[1] = new char[14]{ ' ','/','`','\'','=',')','(','=','\'','`','\\',' ', ' ' };
    shape[2] = new char[14]{ '/','.','-','.','\\',' ',' ','/','.','-','.','\\',' ' };
}

void BAT::sound() {
    PlaySound(TEXT("Sound\\Bat.wav"), NULL, SND_FILENAME | SND_ASYNC);
}


int BAT::isWhat() {
    return 1;
}
