#include"DOG.h"
#include"cstring"

DOG::DOG() {
	shape[0] = new char[13]{'o','\'','\'',')','}','_','_','_','_','/','/',' '};
	shape[1] = new char[13]{' ','`','_','/',' ',' ',' ',' ',' ',' ',')',' ' };
	shape[2] = new char[13]{' ','(','_','(','_','/','-','(','_','_','/',' ' };
}
DOG::DOG(int x) : ENEMY(x, 0) {
	shape[0] = new char[13]{ 'o','\'','\'',')','}','_','_','_','_','/','/',' ' };
	shape[1] = new char[13]{ ' ','`','_','/',' ',' ',' ',' ',' ',' ',')',' ' };
	shape[2] = new char[13]{ ' ','(','_','(','_','/','-','(','_','_','/',' ' };
}

void DOG::sound() {
	PlaySound(TEXT("Sound\\Dog.wav"), NULL, SND_FILENAME | SND_ASYNC);
}