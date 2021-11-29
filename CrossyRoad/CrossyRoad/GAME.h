#ifndef _GAME_H_
#define _GAME_H_

#include "Library.h"
#include "MAP.h"
#include "PLAYER.h"
#include "ENEMY.h"
#include "CAR.h"
#include "TRUCK.h"

#define DOWN_BLACK_PIECE char(220)
#define UP_BLACK_PIECE char(223)
#define VERTICAL_BLACK_PIECE char(219)
#define MIDDLE_SMALL_BLACK_PIECE char(254)

#define HORIZONTAL_PALE_PIECE char(205);
#define VERTICAL_PALE_PIECE char(186);
#define UP_LEFT_CORNER_PALE_PIECE char(201)
#define UP_RIGHT_CORNER_PALE_PIECE char(187)
#define DOWN_LEFT_CORNER_PALE_PIECE char(200)
#define DOWN_RIGHT_CORNER_PALE_PIECE char(188)

#define KEY_DOWN 80
#define KEY_UP 72
#define KEY_ESC 27
#define KEY_ENTER 13

#define LEFT_BORDER 4
#define RIGHT_BORDER 117
#define TOP_BORDER 1
#define BOTTOM_BORDER 36

class GAME {
private:
	MAP map;
	bool checkLoadGame;
	bool checkPauseGame;
public:
	void resizeConsole(int width, int height);
	void FixConsoleWindow();
	void logoCrossyRoad();
	void menu();
	bool newGame();
	void logoLoadGame();
	void loadGame();
};

void gotoxy(int x, int y);
void Nocursortype();
void UnNocursortype();
void txtColor(int color);
void clrscr();


#endif