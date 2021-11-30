#include "MAP.h"
#include "GAME.h"

MAP::MAP() {
	width = 115;
	height = 36;
	initializeMap();
}

void MAP::initializeMap() {
	for (int i = 0; i <= width; ++i) {
		map[0][i] = DOWN_BLACK_PIECE;			// First row
		map[height + 1][i] = UP_BLACK_PIECE;	// Last row
	}

	for (int i = 1; i <= height; ++i) {
		map[i][0] = VERTICAL_BLACK_PIECE;
		map[i][width] = VERTICAL_BLACK_PIECE;

		for (int j = 1; j < width; ++j) {
			map[i][j] = ' ';	// Inside MAP
		}
	}
	for (int i = 0; i <= height + 1; ++i)
		map[i][width + 1] = 'A';	// Right Light
}

void MAP::printMapScreen() {
	txtColor(15);
	gotoxy(0, 0);
	for (int i = 0; i <= height + 1; ++i) {
		cout << "   ";
		for (int j = 0; j <= width + 1; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}

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
	gotoxy(x + 8, 17); cout << "H: SAVE GAME" << endl;
	gotoxy(x + 8, 18); cout << "L: LOAD GAME" << endl;
	gotoxy(x + 8, 19); cout << "P: PAUSE GAME" << endl;
}

int MAP::drawFromPosition(int x, int y, char** shape, int w, int h) {
	if ((y + w <= 0) || (y > width))
		return 0;
	for (int i = 0; i < h; ++i) {
		for (int j = max(1, y); j <= min(width, y + w - 1); ++j) {
			gotoxy(y + j, x + i);
			cout << shape[i][j - max(1, y)];
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

