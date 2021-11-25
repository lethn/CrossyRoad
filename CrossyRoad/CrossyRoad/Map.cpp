#include "Map.h"
#include "Menu.h"

Map::Map() {
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
			map[i][j] = '0';	// Inside Map
		}
	}
}

void Map::printMapScreen() {
	gotoxy(0, 0);
	for (int i = 0; i <= height + 1; ++i) {
		cout << "   ";
		for (int j = 0; j <= width; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}
}
