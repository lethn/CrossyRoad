#include "PLAYER.h"

PLAYER::PLAYER() {
	checkDead = false;
	x = 34;
	y = 30;

	createShapelessPlayer();
	createPlayer();
}

PLAYER::PLAYER(int x, int y) {
	checkDead = false;

	createShapelessPlayer();
	createPlayer();
}

PLAYER::~PLAYER() {
	for (int i = 0; i < 3; i++) {
		delete[] player[i];
		delete[] shapelessPlayer[i];
	}
	delete[] player;
	delete[] shapelessPlayer;
}

void PLAYER::createShapelessPlayer() {
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

void PLAYER::createPlayer() {
	player = new char* [3];
	for (int i = 0; i < 3; i++)
		player[i] = new char[5];

	createShapelessPlayer();
	// Head
	player[0][0] = ' ';
	player[0][1] = ' ';
	player[0][2] = MIDDLE_SMALL_BLACK_PIECE;
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

int PLAYER::getHeight() {
	return height;
}

int PLAYER::getWidth() {
	return width;
}

int PLAYER::getX() {
	return x;
}

int PLAYER::getY() {
	return y;
}

void PLAYER::Up() {
	if (getX() <= 3)
		return;
	x = x - 3;
}

void PLAYER::Down() {
	if (getX() + 3 >= 37)
		return;
	x = x + 3;
}

void PLAYER::Left() {
	if (getY() <= LEFT_MAP)
		return;
	y = y - 1;
}

void PLAYER::Right() {
	if (getY() + 2 >= RIGHT_MAP)
		return;
	y = y + 1;
}

char** PLAYER::getPlayer() {
	return player;
}

char** PLAYER::getShapelessPlayer() {
	return shapelessPlayer;
}

void PLAYER::setCheckDead() {
	checkDead = true;
}
bool PLAYER::getCheckDead() {
	return checkDead;
}

bool PLAYER::checkCollision(ENEMY enemy)
{
	if (x != enemy.x)
		return 0;
	
	bool xCollision = 0;
	bool yCollision = 0;

	if ((enemy.x + 1 <= x && x <= enemy.x + strlen(enemy.shape[0])) || (enemy.x + 1 <= x + 5 && x + 5 <= enemy.x + strlen(enemy.shape[0])))
		xCollision = 1;
	
	if ((enemy.y <= y && y <= enemy.y + 3) || (enemy.y <= y + 3 && y + 3 <= enemy.y + 3))
		yCollision = 1;

	return xCollision && yCollision;
}