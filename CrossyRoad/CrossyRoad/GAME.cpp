#include "GAME.h"

void gotoxy(int x, int y) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void Nocursortype() {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void UnNocursortype() {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void txtColor(int color) {
	HANDLE hConsoleColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clrscr() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

void GAME::resizeConsole(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT edge;
	GetWindowRect(console, &edge);
	MoveWindow(console, edge.left, edge.top, width, height, TRUE);
}

void GAME::FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GAME::logoCrossyRoad() {
	Nocursortype();
	txtColor(15);
	int x = 38;
	int y = 4;
	gotoxy(x - 1, y);		cout << " _______  ______    _______  _______  _______  __   __      ______    _______  _______  ______  " << endl;
	gotoxy(x - 1, y + 1);	cout << "|       ||    _ |  |       ||       ||       ||  | |  |    |    _ |  |       ||   _   ||      | " << endl;
	gotoxy(x - 1, y + 2);	cout << "|       ||   | ||  |   _   ||  _____||  _____||  |_|  |    |   | ||  |   _   ||  |_|  ||  _    |" << endl;
	gotoxy(x - 1, y + 3);	cout << "|       ||   |_||_ |  | |  || |_____ | |_____ |       |    |   |_||_ |  | |  ||       || | |   |" << endl;
	gotoxy(x - 1, y + 4);	cout << "|      _||    __  ||  |_|  ||_____  ||_____  ||_     _|    |    __  ||  |_|  ||       || |_|   |" << endl;
	gotoxy(x - 1, y + 5);	cout << "|     |_ |   |  | ||       | _____| | _____| |  |   |      |   |  | ||       ||   _   ||       |" << endl;
	gotoxy(x - 1, y + 6);	cout << "|_______||___|  |_||_______||_______||_______|  |___|      |___|  |_||_______||__| |__||______| " << endl;

	gotoxy(x - 8, y - 2);
	for (int i = 0; i < 110; ++i)
		cout << DOWN_BLACK_PIECE;
	gotoxy(x - 5, y - 1);
	for (int i = 0; i < 105; ++i)
		cout << HORIZONTAL_PALE_PIECE;
	gotoxy(x - 5, y + 8);
	for (int i = 0; i < 105; ++i)
		cout << HORIZONTAL_PALE_PIECE;
	gotoxy(x - 8, 13);
	for (int i = 0; i < 110; ++i)
		cout << UP_BLACK_PIECE;

	gotoxy(x - 6, y - 1);
	cout << UP_LEFT_CORNER_PALE_PIECE;
	gotoxy(x - 6, y + 8);
	cout << DOWN_LEFT_CORNER_PALE_PIECE;

	gotoxy(x + 99, y - 1);
	cout << UP_RIGHT_CORNER_PALE_PIECE;
	gotoxy(x + 99, y + 8);
	cout << DOWN_RIGHT_CORNER_PALE_PIECE;

	for (int i = 4; i < 12; ++i) {
		gotoxy(x - 6, i);
		cout << VERTICAL_PALE_PIECE;
	}
	for (int i = 4; i < 12; ++i) {
		gotoxy(x + 99, i);
		cout << VERTICAL_PALE_PIECE;
	}
	for (int i = 3; i < 13; ++i) {
		gotoxy(x - 8, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	for (int i = 3; i < 13; ++i) {
		gotoxy(x + 101, i);
		cout << VERTICAL_BLACK_PIECE;
	}
}

void GAME::menu() {
	//PlaySound(TEXT("SugarCookie.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	Nocursortype();
	txtColor(15);
	int x = 74;
	int y = 18;
	gotoxy(x + 1, y);
	for (int i = 0; i < 20; ++i)
		cout << UP_BLACK_PIECE;
	for (int i = y; i < y + 9; ++i)
	{
		gotoxy(x, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	for (int i = y; i < y + 9; ++i)
	{
		gotoxy(x + 21, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	gotoxy(x + 1, y + 8);
	for (int i = 0; i < 20; ++i)
		cout << DOWN_BLACK_PIECE;

	txtColor(15);
	gotoxy(x + 7, y + 1); cout << "NEW GAME";
	gotoxy(x + 5, y + 3); cout << "LOADING GAME";
	gotoxy(x + 6, y + 5); cout << "SOUND:";
	gotoxy(x + 13, y + 5); cout << "ON";
	gotoxy(x + 9, y + 7); cout << "EXIT";

	bool sound = true;
	int cnt = 0;
	while (true)
	{
		char choice = _getch();
		txtColor(15);
		gotoxy(x + 6, y + 1); cout << " NEW GAME ";
		gotoxy(x + 4, y + 3); cout << " LOADING GAME ";
		gotoxy(x + 6, y + 5); cout << "SOUND:";
		gotoxy(x + 8, y + 7); cout << " EXIT ";

		if (choice == KEY_DOWN || choice == 'S' || choice == 's') {
			cnt++;
			if (cnt > 4)
				cnt = 1;
		}
		if (choice == KEY_UP || choice == 'W' || choice == 'w') {
			cnt--;
			if (cnt < 1)
				cnt = 4;
		}
		if (choice == KEY_ESC) {
			clrscr();
			exit(0);
		}

		if (cnt == 1) {
			txtColor(240);
			gotoxy(x + 6, y + 1); cout << " NEW GAME ";
			if (choice == KEY_ENTER ) {
				if (newGame() == true) {

					break;
				}
			}
		}
		if (cnt == 2) {
			txtColor(240);
			gotoxy(x + 4, y + 3); cout << " LOADING GAME ";
			if (choice == KEY_ENTER) {
				loadGame();
				break;
			}
		}
		if (cnt == 3) {
			txtColor(240);
			gotoxy(x + 6, y + 5); cout << "SOUND:";
			if (choice == KEY_ENTER) {
				if (sound == true)
					sound = false;
				else
					sound = true;

				if (sound == true) {
					txtColor(15);
					gotoxy(x + 13, y + 5); cout << "ON ";
					PlaySound(TEXT("SugarCookie.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				}
				else {
					txtColor(15);
					gotoxy(x + 13, y + 5); cout << "OFF";
					PlaySound(NULL, NULL, SND_ASYNC);
				}
			}
		}
		if (cnt == 4) {
			txtColor(240);
			gotoxy(x + 8, y + 7); cout << " EXIT ";
			if (choice == KEY_ENTER) {
				txtColor(15);
				clrscr();
				exit(0);
			}
		}
	}
}

bool GAME::newGame() {
	Nocursortype();
	txtColor(15);
	clrscr();
	map.printMapScreen();
	map.drawPlayer();

	// int l1 = 31;
	// LANE lane1;
	// lane1.enemies.push_back(new CAR(-7, l1));
	// lane1.enemies.push_back(new TRUCK(-20, l1));
	
	// int t = 120;
	// while (t--)
	// 	lane1.moveEnemies();

	// // ENEMY *e = new CAR(1, 31);
	// // e -> renderShape();
	// // delete e;

	while (!map.checkEndMap()){

		while (true) {
			char key = _getch();

			if (key == 'H' || key == 'h') {
				// save game
			}
			if (key == 'L' || key == 'l') {
				// load game
			}
			if (key == 'P' || key == 'p') {
				// pause game
			}

			if (key == 'W' || key == 'w') {
				if (checkPauseGame == false) {
					map.updatePosPlayer('W');
				}
					
			}
			if (key == 'S' || key == 's') {
				if (checkPauseGame == false)
					map.updatePosPlayer('S');
			}
			if (key == 'A' || key == 'a') {
				if (checkPauseGame == false)
					map.updatePosPlayer('A');
			}
			if (key == 'D' || key == 'd') {
				if (checkPauseGame == false)
					map.updatePosPlayer('D');
			}

			map.drawPlayer();
		}
		
	}
	return false;
}

void GAME::logoLoadGame() {
	Nocursortype();
	txtColor(15);
	clrscr();
	int x = 38;
	int y = 4;

	gotoxy(x - 2, y);		cout << " ___      _______  _______  ______   ___   __    _  _______    _______  _______  __   __  _______ " << endl;
	gotoxy(x - 2, y + 1);	cout << "|   |    |       ||   _   ||      | |   | |  |  | ||       |  |       ||   _   ||  |_|  ||       |" << endl;
	gotoxy(x - 2, y + 2);	cout << "|   |    |   _   ||  |_|  ||  _    ||   | |   |_| ||    ___|  |    ___||  |_|  ||       ||    ___|" << endl;
	gotoxy(x - 2, y + 3);	cout << "|   |    |  | |  ||       || | |   ||   | |       ||   | __   |   | __ |       ||       ||   |___ " << endl;
	gotoxy(x - 2, y + 4);	cout << "|   |___ |  |_|  ||       || |_|   ||   | |  _    ||   ||  |  |   ||  ||       ||       ||    ___|" << endl;
	gotoxy(x - 2, y + 5);	cout << "|       ||       ||   _   ||       ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |___ " << endl;
	gotoxy(x - 2, y + 6);	cout << "|_______||_______||__| |__||______| |___| |_|  |__||_______|  |_______||__| |__||_|   |_||_______|" << endl;

	gotoxy(x - 8, y - 2);
	for (int i = 0; i < 110; ++i)
		cout << DOWN_BLACK_PIECE;
	gotoxy(x - 5, y - 1);
	for (int i = 0; i < 105; ++i)
		cout << HORIZONTAL_PALE_PIECE;
	gotoxy(x - 5, y + 8);
	for (int i = 0; i < 105; ++i)
		cout << HORIZONTAL_PALE_PIECE;
	gotoxy(x - 8, 13);
	for (int i = 0; i < 110; ++i)
		cout << UP_BLACK_PIECE;

	gotoxy(x - 6, y - 1);
	cout << UP_LEFT_CORNER_PALE_PIECE;
	gotoxy(x - 6, y + 8);
	cout << DOWN_LEFT_CORNER_PALE_PIECE;

	gotoxy(x + 99, y - 1);
	cout << UP_RIGHT_CORNER_PALE_PIECE;
	gotoxy(x + 99, y + 8);
	cout << DOWN_RIGHT_CORNER_PALE_PIECE;

	for (int i = 4; i < 12; ++i) {
		gotoxy(x - 6, i);
		cout << VERTICAL_PALE_PIECE;
	}
	for (int i = 4; i < 12; ++i) {
		gotoxy(x + 99, i);
		cout << VERTICAL_PALE_PIECE;
	}
	for (int i = 3; i < 13; ++i) {
		gotoxy(x - 8, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	for (int i = 3; i < 13; ++i) {
		gotoxy(x + 101, i);
		cout << VERTICAL_BLACK_PIECE;
	}
}

void GAME::loadGame() {
	logoLoadGame();
	int x = 51;
	int y = 18;

	gotoxy(x, y);
	for (int i = 0; i < 68; ++i)
		cout << HORIZONTAL_PALE_PIECE;

	gotoxy(x, y + 2);
	for (int i = 0; i < 68; ++i)
		cout << HORIZONTAL_PALE_PIECE;

	gotoxy(x - 1, y);
	cout << UP_LEFT_CORNER_PALE_PIECE;
	gotoxy(x - 1, y + 2);
	cout << DOWN_LEFT_CORNER_PALE_PIECE;

	gotoxy(x + 68, y);
	cout << UP_RIGHT_CORNER_PALE_PIECE;
	gotoxy(x + 68, y + 2);
	cout << DOWN_RIGHT_CORNER_PALE_PIECE;

	gotoxy(x - 1, y + 1);
	cout << VERTICAL_PALE_PIECE;
	gotoxy(x + 68, y + 1);
	cout << VERTICAL_PALE_PIECE;

	gotoxy(x + 1, y + 1);
	cout << "Enter your file here: ";
	
	UnNocursortype();
	string file;
	cin >> file;
	
	Nocursortype();
}