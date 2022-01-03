#ifndef _MAP_H_
#define _MAP_H_
#include "Library.h"
#include "PLAYER.h"
#include "LEVEL.h"
#include "LANE.h"

class MAP {
private:
	PLAYER player;
	LEVEL level;
	vector<LANE> lanes;

public:
	MAP();
	void printMapBorder();
	void printMap();
	void fillInsideMap();
	int drawFromPosition(int x, int y, char** shape, int w, int h);
	void drawPlayer();
	void resetPlayer();
	void updatePosPlayer(char key);
	bool checkEndMap();

    int renderMAP(int frameTime);
	bool checkCollision();

	void initializeMap();
	void initialRender();
	void generateMap(int frameTime);

	void saveGame(string name,bool mode);
	bool loadGame(string name, bool &mode);
	void levelUp();
	bool checkMaxLevel();
	bool checkWin();

	friend class GAME;
};
#endif