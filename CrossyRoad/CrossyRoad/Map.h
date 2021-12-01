#ifndef _MAP_H_
#define _MAP_H_
#include "Library.h"
#include "PLAYER.h"

class MAP {
private:
	PLAYER player;
public:
	void printMapBorder();
	void printMap();
	int drawFromPosition(int x, int y, char** shape, int w, int h);
	void drawPlayer();
	void resetPlayer();
	void updatePosPlayer(char key);
	bool checkEndMap();
	friend class GAME;
};


#endif