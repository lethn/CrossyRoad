#include "MAP.h"
#include "GAME.h"

MAP::MAP() {
	width = 115;
	height = 36;
	initializeMap();
}

void MAP::initializeMap() {
	for (int i = 0; i <= width; i++) {
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
}

void MAP::printMapScreen() {
	txtColor(15);
	gotoxy(0, 0);
	for (int i = 0; i <= height + 1; ++i) {
		cout << "   ";
		for (int j = 0; j <= width; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}

	gotoxy(119, 6);
	for (int i = 0; i < 35; ++i)
		cout << DOWN_BLACK_PIECE;
	for (int i = 7; i < 22; ++i) {
		gotoxy(153, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	gotoxy(119, 22);
	for (int i = 0; i < 35; ++i)
		cout << UP_BLACK_PIECE;

	txtColor(14);	gotoxy(125, 8); cout << MIDDLE_SMALL_BLACKE_PIECE << " ROUND: ";
	cout << "1";

	txtColor(12);	gotoxy(125, 10); cout << MIDDLE_SMALL_BLACKE_PIECE << " MOVING KEYBOARD " << endl;
	txtColor(15);
	gotoxy(127, 11); cout << "W: UP" << endl;
	gotoxy(127, 12); cout << "S: DOWN" << endl;
	gotoxy(127, 13); cout << "A: LEFT" << endl;
	gotoxy(127, 14); cout << "D: RIGHT" << endl;

	txtColor(12); gotoxy(125, 17); cout << MIDDLE_SMALL_BLACKE_PIECE << " COMMAND KEYBOARD " << endl;
	txtColor(15);
	gotoxy(127, 18); cout << "H: SAVE GAME" << endl;
	gotoxy(127, 19); cout << "L: LOAD GAME" << endl;
	gotoxy(127, 20); cout << "P: PAUSE GAME" << endl;
}

//int MAP::drawFromPosition(int x, int y, char** shape, int w, int h) {
//	if (y > w || (y + w <= 0))
//		return 0;
//
//	for (int i = 0; i < h; ++i) {
//		for (int j = max(1, y); j <= min(width, y + w - 1); ++j) {
//			gotoxy(y + j, x + i);
//			cout << shape[i][j - max(1, y)];
//		}
//	}
//	return 1;
//}
//
//void MAP::drawPlayer() {
//	int live = drawFromPosition(player.getX(), player.getY(), player.getPlayer(), player.getWidth(), player.getHeight());
//	if (live == -1)
//		player.setCheckDead();
//}
//
//void MAP::resetPlayer() {
//	drawFromPosition(player.getX(), player.getY(), player.getShapelessPlayer(), player.getWidth(), player.getHeight());
//}


