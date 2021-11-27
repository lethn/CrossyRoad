#include "PEOPLE.h"

PEOPLE::PEOPLE() {
	checkDead = false;
	x = 34;
	y = 28;

	createShapelessPlayer();
	createPlayer();
}

PEOPLE::PEOPLE(int x, int y) {
	checkDead = false;

	player = new char* [3];
	for (int i = 0; i < 3; i++)
		player[i] = new char[5];

	createShapelessPlayer();
	createPlayer();
}

PEOPLE::~PEOPLE() {
	for (int i = 0; i < 3; i++) {
		delete[] player[i];
		delete[] shapelessPlayer[i];
	}
	delete[] player;
	delete[] shapelessPlayer;
}

void PEOPLE::createShapelessPlayer() {
	shapelessPlayer = new char* [3];
	for (int i = 0; i < 3; i++)
		shapelessPlayer[i] = new char[5];

	for (int i = 0; i < 3; ++i) {
		shapelessPlayer[i] = new char[5];
		for (int j = 0; j < 5; ++j) {
			shapelessPlayer[i][j] = ' ';
		}
	}
}

void PEOPLE::createPlayer() {
	player = new char* [3];
	for (int i = 0; i < 3; i++)
		player[i] = new char[5];

	createShapelessPlayer();
	// Head
	player[0][0] = ' ';
	player[0][1] = ' ';
	player[0][2] = MIDDLE_SMALL_BLACKE_PIECE;
	player[0][3] = ' ';
	player[0][4] = ' ';

	// Body
	player[1][0] = '/';
	player[1][1] = ' ';
	player[1][2] = VERTICAL_BLACK_PIECE;
	player[1][3] = ' ';
	player[1][4] = '\\';

	// Legs
	player[2][0] = ' ';
	player[2][1] = '/';
	player[2][2] = ' ';
	player[2][3] = '\\';
	player[2][4] = ' ';
}

int PEOPLE::getHeight() {
	return height;
}

int PEOPLE::getWidth() {
	return width;
}

int PEOPLE::getX() {
	return x;
}

int PEOPLE::getY() {
	return y;
}

void PEOPLE::Up() {
	if (getX() <= 3)
		return;
	x = x - 3;
}

void PEOPLE::Down() {
	if (getX() + 3 >= 34)
		return;
	x = x + 3;
}

void PEOPLE::Left() {
	if (getY() <= LEFT_MAP)
		return;
	y = y - 1;
}

void PEOPLE::Right() {
	if (getY() + 2 >= RIGHT_MAP)
		return;
	y = y + 1;
}