#include "MAP.h"
#include "GAME.h"

MAP::MAP() : player(), level(), lanes(9) {}

void MAP::printMapBorder() {
	txtColor(15);

	for (int i = 0; i < 37; ++i) {
		gotoxy(0, i);	cout << "  ";
		gotoxy(121, i);	cout << "  ";
	}

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

	txtColor(14);
	gotoxy(x + 6, y + 2); cout << MIDDLE_SMALL_BLACK_PIECE << " ROUND: ";
	gotoxy(x + 17, y + 2); cout << "| MODE: ";

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

void MAP::fillInsideMap() {
	txtColor(15);
	for (int i = 1; i < 37; ++i) {
		gotoxy(4, i);
		for (int j = 0; j < 115; ++j) {
			cout << " ";
		}
	}
}

int MAP::drawFromPosition(int x, int y, char** shape, int w, int h) {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			gotoxy(x + j, y + i);
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

int MAP::renderMAP(int frameTime)
{
	int outOfMap = 0;

	for (LANE &lane : lanes)
		outOfMap += lane.moveEnemies(frameTime);

	return outOfMap;
}

bool MAP::checkCollision()
{
	for (LANE &lane : lanes)
	{
		for (ENEMY *&enemy : lane.enemies)
		{
			if (player.y == lane.y && player.checkCollision(*enemy))
				return true;
		}
	}
	
	return false;
}

void MAP::initializeMap()
{
	player.~PLAYER();
	new (&player) PLAYER();
	lanes.clear();

	std::mt19937 rng(getSeed());
	std::uniform_int_distribution<unsigned> ZeroOne(0, 1);
	std::uniform_int_distribution<unsigned> Speed(level.maxSpeed, level.minSpeed);
	std::uniform_int_distribution<unsigned> Steps(60, 80);

	switch (level.level)
	{
		case 1:
			lanes = vector<LANE>(5);

			for (int i = 0; i < 5; ++i)
			{
				lanes[i].y = i * 6 + 7;
				lanes[i].speed = Speed(rng);
				lanes[i].redLightRate = lanes[i].speed * Steps(rng);
				lanes[i].greenLightRate = lanes[i].speed * Steps(rng);
				lanes[i].direction = ZeroOne(rng) ? 1 : -1;
				lanes[i].redLight = ZeroOne(rng);
			}

			break;

		case 2:
			lanes = vector<LANE>(6);

			for (int i = 0; i < 6; ++i)
			{
				if (i < 3)
					lanes[i].y = i * 3 + 7;
				else
					lanes[i].y = lanes[i - 1].y + 6;

				lanes[i].speed = Speed(rng);
				lanes[i].redLightRate = lanes[i].speed * Steps(rng);
				lanes[i].greenLightRate = lanes[i].speed * Steps(rng);
				lanes[i].direction = ZeroOne(rng) ? 1 : -1;
				lanes[i].redLight = ZeroOne(rng);
			}

			break;

		case 3:
			lanes = vector<LANE>(7);

			for (int i = 0; i < 7; ++i)
			{
				if (i < 5)
					lanes[i].y = i * 3 + 7;
				else
					lanes[i].y = lanes[i - 1].y + 6;

				lanes[i].speed = Speed(rng);
				lanes[i].redLightRate = lanes[i].speed * Steps(rng);
				lanes[i].greenLightRate = lanes[i].speed * Steps(rng);
				lanes[i].direction = ZeroOne(rng) ? 1 : -1;
				lanes[i].redLight = ZeroOne(rng);
			}
			
			break;

		case 4:
			lanes = vector<LANE>(8);

			for (int i = 0; i < 8; ++i)
			{
				if (i < 7)
					lanes[i].y = i * 3 + 7;
				else
					lanes[i].y = lanes[i - 1].y + 6;

				lanes[i].speed = Speed(rng);
				lanes[i].redLightRate = lanes[i].speed * Steps(rng);
				lanes[i].greenLightRate = lanes[i].speed * Steps(rng);
				lanes[i].direction = ZeroOne(rng) ? 1 : -1;
				lanes[i].redLight = ZeroOne(rng);
			}
			
			break;

		default:
			lanes = vector<LANE>(9);

			for (int i = 0; i < 9; ++i)
			{
				lanes[i].y = i * 3 + 7;
				lanes[i].speed = Speed(rng);
				lanes[i].redLightRate = lanes[i].speed * Steps(rng);
				lanes[i].greenLightRate = lanes[i].speed * Steps(rng);
				lanes[i].direction = ZeroOne(rng) ? 1 : -1;
				lanes[i].redLight = ZeroOne(rng);
			}

			break;
	}

	std::uniform_int_distribution<unsigned> Row(0, lanes.size() - 1);
	std::uniform_int_distribution<unsigned> Pos(LEFT_BORDER, RIGHT_BORDER);
	std::uniform_int_distribution<unsigned> distance(25, 30);
	
	int xPos[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	ENEMY *newEnemy;
	while (level.currEnemy < level.maxEnemy)
	{
		int row = Row(rng);

		if (xPos[row] == 0)
			xPos[row] += Pos(rng);
		else 
			xPos[row] += distance(rng);
		
		newEnemy = level.randNewEnemy(xPos[row], lanes[row].direction);

		if (newEnemy)
			lanes[row].enemies.push_back(newEnemy);
	}	
}

void MAP::initialRender()
{
	for (LANE &lane : lanes)
	{
		lane.renderTrafficLight();
		for (ENEMY *&enemy : lane.enemies)
			enemy -> renderShape(lane.y);
	}
}

void MAP::generateMap(int frameTime)
{
	std::mt19937 rng(getSeed());
	std::uniform_int_distribution<unsigned> Row(0, lanes.size() - 1);
	std::uniform_int_distribution<unsigned> Pos(LEFT_BORDER, RIGHT_BORDER);


	ENEMY *newEnemy;
	int fails = 0;
	while (level.currEnemy < level.maxEnemy)
	{
		int row = Row(rng);
		
		if (lanes[row].enemies.empty() || !lanes[row].enemies.back() -> checkAtSpawn())
		{
			int xPos = lanes[row].direction == 1 ? -10 : 120;
			newEnemy = level.randNewEnemy(xPos, lanes[row].direction);

			if (newEnemy)
				lanes[row].enemies.push_back(newEnemy);
		}
		else 
			if (++fails > lanes.size())
				break;
		
	}

	level.currEnemy -= renderMAP(frameTime);
}

void MAP::levelUp() {
	level.nextLevel();
}

bool MAP::checkMaxLevel() {
	if (level.getLevel() == 5)
		return true;
	return false;
}

bool MAP::checkWin() {
	if (player.getY() == 4)
		return true;
	return false;
}

bool MAP::loadGame(string name, bool &mode) {
	ifstream f;
	f.open(name);
	if (!f.is_open())
		return false;

	this->~MAP();
	new(this) MAP();

	f.read((char*)& mode, sizeof(mode));
	f.read((char*)& player.x, sizeof(player.x));
	f.read((char*)& player.y, sizeof(player.y));
	f.read((char*)& level.level, sizeof(level.level));
	f.read((char*)& level.currEnemy, sizeof(level.currEnemy));

	int lSize;
	f.read((char*)& lSize, sizeof(lSize));

	lanes.clear();
	lanes = vector<LANE>(lSize);

	for (int i = 0; i < lSize; i++) {
		int eSize;
		f.read((char*)& eSize, sizeof(eSize));
		f.read((char*)& lanes[i].direction, sizeof(lanes[i].direction));
		f.read((char*)& lanes[i].redLight, sizeof(lanes[i].redLight));
		f.read((char*)& lanes[i].redLightRate, sizeof(lanes[i].redLightRate));
		f.read((char*)& lanes[i].greenLightRate, sizeof(lanes[i].greenLightRate));
		f.read((char*)& lanes[i].speed, sizeof(lanes[i].speed));
		f.read((char*)& lanes[i].y, sizeof(lanes[i].y));

		for (int j = 0; j < eSize; j++) {
			int type, x;
			f.read((char*)& type, sizeof(type));
			f.read((char*)& x, sizeof(x));

			ENEMY* temp = NULL;
			if (type == 1)
				temp = new BAT(x);
			if (type == 2)
				temp = new CAR(x);
			if (type == 3)
				temp = new DOG(x);
			if (type == 4)
				temp = new SHARK(x);
			if (type == 5)
				temp = new TRUCK(x);

			lanes[i].enemies.push_back(temp);
		}
	}

	f.close();
	return true;
}

void MAP::saveGame(string name,bool mode) {
	ofstream f;
	f.open(name, ios::binary);
	if (!f.is_open())
		return;

	//player
	f.write((char*)& mode, sizeof(mode));
	f.write((char*)& player.x, sizeof(player.x));
	f.write((char*)& player.y, sizeof(player.y));
	//level
	f.write((char*)& level.level, sizeof(level.level));
	f.write((char*)& level.currEnemy, sizeof(level.currEnemy));
	//lane
	int temp = lanes.size();
	f.write((char*)& temp, sizeof(temp));
	for (int i = 0; i < lanes.size(); i++) {
		temp = lanes[i].enemies.size();
		f.write((char*)& temp, sizeof(temp));
		f.write((char*)& lanes[i].direction, sizeof(lanes[i].direction));
		f.write((char*)& lanes[i].redLight, sizeof(lanes[i].redLight));
		f.write((char*)& lanes[i].redLightRate, sizeof(lanes[i].redLightRate));
		f.write((char*)& lanes[i].greenLightRate, sizeof(lanes[i].greenLightRate));
		f.write((char*)& lanes[i].speed, sizeof(lanes[i].speed));
		f.write((char*)& lanes[i].y, sizeof(lanes[i].y));

		for (int j = 0; j < lanes[i].enemies.size(); j++) {
			// bat = 1, car = 2, dog = 3, shark = 4, truck = 5
			temp = lanes[i].enemies[j]->isWhat();
			f.write((char*)& temp, sizeof(temp));
			f.write((char*)& lanes[i].enemies[j]->x, sizeof(lanes[i].enemies[j]->x));
		}
	}
	f.close();
}