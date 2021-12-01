#include "MAP.h"
#include "GAME.h"

void MAP::printMapBorder() {
	txtColor(15);

	gotoxy(3, 0);
	for (int i = 0; i < 117; ++i)
		cout << DOWN_BLACK_PIECE;

	for (int i = 1; i < 37; ++i) {
		gotoxy(119, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	for (int i = 1; i < 37; ++i) {
		gotoxy(3, i);
		cout << VERTICAL_BLACK_PIECE;
	}

	gotoxy(3, 37);
	for (int i = 0; i < 117; ++i)
		cout << UP_BLACK_PIECE;
}

void MAP::printMap() {
	printMapBorder();
	
	int x = 127;
	int y = 6;
	gotoxy(x, y);
	for (int i = 0; i < 35; ++i)
		cout << DOWN_BLACK_PIECE;
	for (int i = 7; i < 21; ++i) {
		gotoxy(x, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	for (int i = 7; i < 21; ++i) {
		gotoxy(x + 34, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	gotoxy(x, y + 15);
	for (int i = 0; i < 35; ++i)
		cout << UP_BLACK_PIECE;

	txtColor(14);	gotoxy(x + 6, y + 2); cout << MIDDLE_SMALL_BLACK_PIECE << " ROUND: ";
	cout << "1";

	txtColor(12);	gotoxy(x + 6, y + 4); cout << MIDDLE_SMALL_BLACK_PIECE << " MOVING KEYBOARD " << endl;
	txtColor(15);
	gotoxy(x + 8, 11); cout << "W: UP" << endl;
	gotoxy(x + 8, 12); cout << "S: DOWN" << endl;
	gotoxy(x + 8, 13); cout << "A: LEFT" << endl;
	gotoxy(x + 8, 14); cout << "D: RIGHT" << endl;

	txtColor(12); gotoxy(x + 6, y + 10); cout << MIDDLE_SMALL_BLACK_PIECE << " COMMAND KEYBOARD " << endl;
	txtColor(15);
	gotoxy(x + 8, 17); cout << "J: SAVE GAME" << endl;
	gotoxy(x + 8, 18); cout << "L: LOAD GAME" << endl;
	gotoxy(x + 8, 19); cout << "P: PAUSE GAME" << endl;
}

int MAP::drawFromPosition(int x, int y, char** shape, int w, int h) {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			gotoxy(x * 2 + j, y + i);
			cout << shape[i][j];
		}
	}
	return 1;
}

void MAP::drawPlayer() {
	int live = drawFromPosition(player.getX(), player.getY(), player.getPlayer(), player.getWidth(), player.getHeight());
	if (live == -1)
		player.setCheckDead();
}

void MAP::resetPlayer() {
	drawFromPosition(player.getX(), player.getY(), player.getShapelessPlayer(), player.getWidth(), player.getHeight());
}

void MAP::updatePosPlayer(char key) {
	resetPlayer();

	if (key == 'W' || key == 'w')
		player.Up();
	else if (key == 'S' || key == 's')
		player.Down();
	else if (key == 'A' || key == 'a')
		player.Left();
	else if (key == 'D' || key == 'd')
		player.Right();
	else
		return;
}

bool MAP::checkEndMap() {
	return player.getCheckDead();
}

