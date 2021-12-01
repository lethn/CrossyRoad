#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Library.h"
#include <algorithm>
#include "ENEMY.h"
#include "DOG.h"
#include "TRUCK.h"
#include "CAR.h"
//#include "BAT.h"   

class LEVEL
{
private:
	int level;
	int maxEnemy, minSpeed, maxSpeed, curEnemy;
	const int maxLevel = 5;
public:
	LEVEL();
	LEVEL(int level, int nEnemy);
	~LEVEL(){};
	void initialize();
	bool newLevel(int lv);
	bool nextLevel();
	/*cEnemy * randNewEnemy(cPosition pos);*/
	int randSpeed();
	void decNEnemy(int d);
	friend class LANE;
};

#endif