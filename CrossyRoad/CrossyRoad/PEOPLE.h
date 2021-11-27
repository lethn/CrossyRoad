#ifndef _PEOPLE_H_
#define _PEOPLE_H_

#include "Library.h"
#include "GAME.h"

#define DOWN_MAP 34
#define LEFT_MAP 2
#define RIGHT_MAP 58

class PEOPLE {
private:
	int x, y; // position
	int height = 3;
	int width = 5;
	char** shapelessPlayer;	// shapeless player
	char** player;			// player
	bool checkDead;

public:
	PEOPLE();
	PEOPLE(int x, int y);
	~PEOPLE();
	void createShapelessPlayer();
	void createPlayer();
	int getHeight();
	int getWidth();
	int getX();
	int getY();
	void Up();
	void Down();
	void Left();
	void Right();
};


#endif