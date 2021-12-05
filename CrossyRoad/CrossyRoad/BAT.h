#pragma once

#include "ENEMY.h"

class BAT : public ENEMY {
public:
	BAT();
	BAT(int x);
	int isWhat();
	void sound();
};