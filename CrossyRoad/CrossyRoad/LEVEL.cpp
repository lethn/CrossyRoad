#include "LEVEL.h"

LEVEL::LEVEL() {
	level = 1;
	curEnemy = 0;
	initialize();
}

LEVEL::LEVEL(int level, int curEnemy) {
	this->level = level;
	this->curEnemy = curEnemy;
	initialize();
}

void LEVEL::initialize() {
	switch (level)
		{
		case 1: {
			maxEnemy = 5; // t de theo tam linh
			maxSpeed = 900;  
			minSpeed = 700; 
			break; 
		}
		case 2: {
			maxEnemy = 7; 
			maxSpeed = 650;  
			minSpeed = 500; 
			break;
		}
		case 3: {
			maxEnemy = 9; 
			maxSpeed = 450;  
			minSpeed = 300; 
			break;
		}
		case 4: {
			maxEnemy = 11; 
			maxSpeed = 350;  
			minSpeed = 200; 
			break;
		}
		default:
			maxEnemy = 13; 
			maxSpeed = 200;  
			minSpeed = 100; 
			break;
		}
}

bool LEVEL::newLevel(int lv) {
	if (lv > maxLevel) return false;
	level = lv;
	curEnemy = 0;
	initialize();
	return true;
}

bool LEVEL::nextLevel() {
	if (level == maxLevel) return false;
	++level;
	curEnemy = 0;
	return true;
}

ENEMY * LEVEL::randNewEnemy(cPosition pos, short direction) {
	if (curEnemy == maxEnemy) return NULL;
	if (curEnemy < (maxEnemy)) {
		++curEnemy;
		ENEMY * pEnemy = NULL;
		switch (direction)
		{
		case -1: {
			int k = rand() % 2;
			if( k == 0 ) {
				pEnemy = new DOG(pos);
			} /*else
				pEnemy = new BAT(pos); */ // Wait for BAT class
			break;
		}
		default:
			int k = rand() % 3;
			if( k == 0 ) {
				pEnemy = new TRUCK(pos);
			} else if( k == 1 ) {
				pEnemy = new CAR(pos);
			} /* else {
				pEnemy = new something // wait for Duc Anh
			}*/
			break;
		}
		return pEnemy;
	}
	return NULL;
}

int LEVEL::randSpeed()
{
	int k = maxSpeed - minSpeed + ;
	return rand % minSpeed + k ;

}

void LEVEL::decNEnemy(int d) {
	curEnemy -= d;
}