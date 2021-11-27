#ifndef _MAP_H_
#define _MAP_H_
#include "Library.h"
#include "PLAYER.h"

class MAP {
private:
	int width;	// 115
	int height;	// 36
	char map[38][116];
	PLAYER player;
public:
	MAP();
	void initializeMap();
	void printMapScreen();	// just Map
	int drawFromPosition(int x, int y, char** shape, int w, int h);
	void drawPlayer();
	void resetPlayer();
	void updatePosPlayer(char key);
};


#endif