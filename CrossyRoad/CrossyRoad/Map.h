#ifndef _MAP_H_
#define _MAP_H_
#include "Library.h"
#include "PLAYER.h"
#include "LEVEL.h"

class MAP {
private:
	PLAYER player;
	LEVEL level;
	vector<LANE> lanes;

public:
	MAP();
	void printMapBorder();
	void printMap();
	int drawFromPosition(int x, int y, char** shape, int w, int h);
	void drawPlayer();
	void resetPlayer();
	void updatePosPlayer(char key);
	bool checkEndMap();

    void renderMAP(int frameTime);
	bool checkCollision();

	void generateMap();
	void initializeLanes();
	void generateLanes();


	friend class GAME;
};


#endif