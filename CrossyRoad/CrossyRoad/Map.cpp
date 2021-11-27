#include "MAP.h"
#include "GAME.h"

MAP::MAP() {
	width = 115;
	height = 36;
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
}

void MAP::printSubMapScreen() {
	txtColor(15);
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

	txtColor(14);	gotoxy(125, 8); cout << char(254) << " ROUND: ";
	cout << "1";

	txtColor(12);	gotoxy(125, 10); cout << char(254) << " MOVING KEYBOARD " << endl;
	txtColor(15);
	gotoxy(127, 11); cout << "W: UP" << endl;
	gotoxy(127, 12); cout << "S: DOWN" << endl;
	gotoxy(127, 13); cout << "A: LEFT" << endl;
	gotoxy(127, 14); cout << "D: RIGHT" << endl;

	txtColor(12); gotoxy(125, 17); cout << char(254) << " COMMAND KEYBOARD " << endl;
	txtColor(15);
	gotoxy(127, 18); cout << "H: SAVE GAME" << endl;
	gotoxy(127, 19); cout << "L: LOAD GAME" << endl;
	gotoxy(127, 20); cout << "P: PAUSE GAME" << endl;
}

