#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Library.h"
#include "ENEMY.h"

#define DOWN_MAP 34
#define LEFT_MAP 2
#define RIGHT_MAP 58
#define VERTICAL_BLACK_PIECE char(219)
#define MIDDLE_SMALL_BLACK_PIECE char(254)

class PLAYER {
private:
	int x, y; // position
	int height = 3;
	int width = 5;
	char** shapelessPlayer;	// shapeless player
	char** player;			// player
	bool checkDead;
public:
	PLAYER();
	PLAYER(int x, int y);
	~PLAYER();
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
	char** getPlayer();
	char** getShapelessPlayer();
	void setCheckDead();
	bool getCheckDead();

	bool checkCollision(const ENEMY &enemy);
};


#endif