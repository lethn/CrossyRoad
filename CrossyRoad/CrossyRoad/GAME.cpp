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

std::mt19937::result_type getSeed()
{
	std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );
	
	return seed;
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

void GAME::logoSaveGame() {
	Nocursortype();
	txtColor(15);
	clrscr();
	int x = 50;
	int y = 4;

	gotoxy(x - 2, y);		cout << " _______  _______  __   __  _______    _______  _______  __   __  _______ " << endl;
	gotoxy(x - 2, y + 1);	cout << "|       ||   _   ||  | |  ||       |  |       ||   _   ||  |_|  ||       |" << endl;
	gotoxy(x - 2, y + 2);	cout << "|  _____||  |_|  ||  |_|  ||    ___|  |    ___||  |_|  ||       ||    ___|" << endl;
	gotoxy(x - 2, y + 3);	cout << "| |_____ |       ||       ||   |___   |   | __ |       ||       ||   |___ " << endl;
	gotoxy(x - 2, y + 4);	cout << "|_____  ||       ||       ||    ___|  |   ||  ||       ||       ||    ___|" << endl;
	gotoxy(x - 2, y + 5);	cout << " _____| ||   _   | |     | |   |___   |   |_| ||   _   || ||_|| ||   |___ " << endl;
	gotoxy(x - 2, y + 6);	cout << "|_______||__| |__|  |___|  |_______|  |_______||__| |__||_|   |_||_______|" << endl;

	gotoxy(x - 8, y - 2);
	for (int i = 0; i < 86; ++i)
		cout << DOWN_BLACK_PIECE;
	gotoxy(x - 5, y - 1);
	for (int i = 0; i < 81; ++i)
		cout << HORIZONTAL_PALE_PIECE;
	gotoxy(x - 5, y + 8);
	for (int i = 0; i < 81; ++i)
		cout << HORIZONTAL_PALE_PIECE;
	gotoxy(x - 8, 13);
	for (int i = 0; i < 86; ++i)
		cout << UP_BLACK_PIECE;

	gotoxy(x - 6, y - 1);
	cout << UP_LEFT_CORNER_PALE_PIECE;
	gotoxy(x - 6, y + 8);
	cout << DOWN_LEFT_CORNER_PALE_PIECE;

	gotoxy(x + 75, y - 1);
	cout << UP_RIGHT_CORNER_PALE_PIECE;
	gotoxy(x + 75, y + 8);
	cout << DOWN_RIGHT_CORNER_PALE_PIECE;

	for (int i = 4; i < 12; ++i) {
		gotoxy(x - 6, i);
		cout << VERTICAL_PALE_PIECE;
	}
	for (int i = 4; i < 12; ++i) {
		gotoxy(x + 75, i);
		cout << VERTICAL_PALE_PIECE;
	}
	for (int i = 3; i < 13; ++i) {
		gotoxy(x - 8, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	for (int i = 3; i < 13; ++i) {
		gotoxy(x + 77, i);
		cout << VERTICAL_BLACK_PIECE;
	}
}

void GAME::logoLoseGame() {
	Nocursortype();
	int x = 45;
	int y = 11;
	int z = 2;

	gotoxy(x, z);		cout << " __   __  _______  __   __    ___      _______  _______  _______    __   __   __ " << endl;
	gotoxy(x, z + 1);	cout << "|  | |  ||       ||  | |  |  |   |    |       ||       ||       |  |  | |  | |  |" << endl;
	gotoxy(x, z + 2);	cout << "|  |_|  ||   _   ||  | |  |  |   |    |   _   ||  _____||_     _|  |  | |  | |  |" << endl;
	gotoxy(x, z + 3);	cout << "|       ||  | |  ||  |_|  |  |   |    |  | |  || |_____   |   |    |  | |  | |  |" << endl;
	gotoxy(x, z + 4);	cout << "|_     _||  |_|  ||       |  |   |___ |  |_|  ||_____  |  |   |    |__| |__| |__|" << endl;
	gotoxy(x, z + 5);	cout << "  |   |  |       ||       |  |       ||       | _____| |  |   |     __   __   __ " << endl;
	gotoxy(x, z + 6);	cout << "  |___|  |_______||_______|  |_______||_______||_______|  |___|    |__| |__| |__|" << endl;

	gotoxy(x, y);       cout << R"(                               _________________ )" << endl;
	gotoxy(x, y + 1);   cout << R"(                          ____/  (  (    )   )  \___ )" << endl;
	gotoxy(x, y + 2);   cout << R"(                         /( (  (  )   _    ))  )   )\\ )" << endl;
	gotoxy(x, y + 3);   cout << R"(                       ((     (   )(    )  )   (   )  ) )" << endl;
	gotoxy(x, y + 4);   cout << R"(                     ((/  ( _(   )   (   _) ) (  () )  ) )" << endl;
	gotoxy(x, y + 5);   cout << R"(                    ( (  ( (_)   ((    (   )  .((_ ) .  )_ )" << endl;
	gotoxy(x, y + 6);   cout << R"(                   ( (  )    (      (  )    )   ) . ) (   ) )" << endl;
	gotoxy(x, y + 7);   cout << R"(                  (  (   (  (   ) (  _  ( _) ).  ) . ) ) ( ) )" << endl;
	gotoxy(x, y + 8);   cout << R"(                  ( (  (   ) (  )   (  ))     ) _)(   )  )  ) )" << endl;
	gotoxy(x, y + 9);   cout << R"(                 ( (  ( \\ ) (    (_  ( ) ( )  )   ) )  )) ( ) )" << endl;
	gotoxy(x, y + 10);  cout << R"(                  (  (   (  (   (_ ( ) ( _    )  ) (  )  )   ) )" << endl;
	gotoxy(x, y + 11);  cout << R"(                 ( (  ( (  (  )     (_  )  ) )  _)   ) _( ( ) )" << endl;
	gotoxy(x, y + 12);  cout << R"(                  ((  (   )(    (     _    )   _) _(_ (  (_ ) )" << endl;
	gotoxy(x, y + 13);  cout << R"(                   (_((__(_(__(( ( ( |  ) ) ) )_))__))_)___) )" << endl;
	gotoxy(x, y + 14);  cout << R"(                   ((__)        \\|||||||||///          \\_)) )" << endl;
	gotoxy(x, y + 15);  cout << R"(                            (   /(/ (  )  ) )\\   ) )" << endl;
	gotoxy(x, y + 16);  cout << R"(                          (    ( ( ( | | ) ) )\\   ) )" << endl;
	gotoxy(x, y + 17);  cout << R"(                           (   /(| / ( )) ) ) )) ) )" << endl;
	gotoxy(x, y + 18);  cout << R"(                         (     ( ((((_(|)_)))))     ) )" << endl;
	gotoxy(x, y + 19);  cout << R"(                          (      ||\\(|(|)|/||     ) )" << endl;
	gotoxy(x, y + 20);  cout << R"(                        (        |(||(||)||||        ) )" << endl;
	gotoxy(x, y + 21);  cout << R"(                          (     //|/||||)|\\ \\     ) )" << endl;
	gotoxy(x, y + 22);  cout << R"(                        (/ / //  /|//||||\\  \\ \\  \\ _) )" << endl;
	gotoxy(x, y + 23);  cout << R"(--------------------------------------------------------------------------------- )" << endl;
}

void GAME::logoWinGame() {
	Nocursortype();
	int x = 42;
	int y = 8;

	gotoxy(x + 34, y + 6);   cout << " __   __  _______  __   __    _     _  ___   __    _    __   __   __ " << endl;
	gotoxy(x + 34, y + 7);	 cout << "|  | |  ||       ||  | |  |  | | _ | ||   | |  |  | |  |  | |  | |  |" << endl;
	gotoxy(x + 34, y + 8);	 cout << "|  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| |  |  | |  | |  |" << endl;
	gotoxy(x + 34, y + 9);   cout << "|       ||  | |  ||  |_|  |  |       ||   | |       |  |  | |  | |  |" << endl;
	gotoxy(x + 34, y + 10);	 cout << "|_     _||  |_|  ||       |  |       ||   | |  _    |  |__| |__| |__|" << endl;
	gotoxy(x + 34, y + 11);	 cout << "  |   |  |       ||       |  |   _   ||   | | | |   |   __   __   __ " << endl;
	gotoxy(x + 34, y + 12);	 cout << "  |___|  |_______||_______|  |__| |__||___| |_|  |__|  |__| |__| |__|" << endl;

	gotoxy(x - 20, y);       cout << R"(                 .__.--"""-,)" << endl;
	gotoxy(x - 20, y + 1);   cout << R"(               .'         `\)" << endl;
	gotoxy(x - 20, y + 2);   cout << R"(              /   _         \)" << endl;
	gotoxy(x - 20, y + 3);   cout << R"( .-""-.       |  (O\.--.-.-/O)          .-""-.)" << endl;
	gotoxy(x - 20, y + 4);   cout << R"(/ O O  \      .\|(_._.__._.__)         /  O O \)" << endl;
	gotoxy(x - 20, y + 5);   cout << R"(|O .-.  \    (   )   0 _ 0   \        /  .-. O|)" << endl;
	gotoxy(x - 20, y + 6);   cout << R"(\ (   )  '.   `-|     (_)     |     .'  (   ) /)" << endl;
	gotoxy(x - 20, y + 7);   cout << R"( '.`-'     '-./`|             |`\.-'     '-'.')" << endl;
	gotoxy(x - 20, y + 8);   cout << R"(   \         |  \   \     /   /  |         /)" << endl;
	gotoxy(x - 20, y + 9);   cout << R"(    \        \   '.  '._.'  .'   /        /)" << endl;
	gotoxy(x - 20, y + 10);  cout << R"(     \        '.   `'-----'`   .'        /)" << endl;
	gotoxy(x - 20, y + 11);  cout << R"(      \   .'    '-._        .-'\   '.   /)" << endl;
	gotoxy(x - 20, y + 12);  cout << R"(       |/`          `'''''')    )    `\|)" << endl;
	gotoxy(x - 20, y + 13);  cout << R"(       /                  (    (      ,\)" << endl;
	gotoxy(x - 20, y + 14);  cout << R"(      ;                    \    '-..-'/ ;)" << endl;
	gotoxy(x - 20, y + 15);  cout << R"(      |                     '.       /  |)" << endl;
	gotoxy(x - 20, y + 16);  cout << R"(      |                       `'---'`   |)" << endl;
	gotoxy(x - 20, y + 17);  cout << R"(      ;                                 ;)" << endl;
	gotoxy(x - 20, y + 18);  cout << R"(       \                               /)" << endl;
	gotoxy(x - 20, y + 19);  cout << R"(        `.                           .')" << endl;
	gotoxy(x - 20, y + 20);  cout << R"(          '-._                   _.-')" << endl;
	gotoxy(x - 20, y + 21);  cout << R"(           __/`"  '  - - -  ' "`` \__)" << endl;
	gotoxy(x - 20, y + 22);  cout << R"(         /`            /^\           `\)" << endl;
	gotoxy(x - 20, y + 23);  cout << R"(         \(          .'   '.         )/)" << endl;
	gotoxy(x - 20, y + 24);  cout << R"(          '.(__(__.-'       '.__)__).')" << endl;
}

void GAME::fillMenu() {
	txtColor(15);
	for (int i = 18; i < 28; ++i) {
		gotoxy(74, i);
		for (int j = 0; j < 22; ++j) {
			cout << " ";
		}
	}
}

void GAME::loadingBar() {
	txtColor(15);
	Nocursortype();

	int x = 51;
	int y = 18;
	for (int i = 18; i < 28; ++i) {
		gotoxy(40, i);
		for (int j = 0; j < 100; ++j) {
			cout << " ";
		}
	}

	y = 20;
	gotoxy(80, y - 1);	cout << "LOADING...";
	gotoxy(x - 1, y);
	for (int i = 0; i < 70; ++i)
		cout << DOWN_BLACK_PIECE;

	gotoxy(x - 1, y + 2);
	for (int i = 0; i < 70; ++i)
		cout << UP_BLACK_PIECE;

	gotoxy(x - 1, y + 1);
	cout << VERTICAL_BLACK_PIECE;
	gotoxy(x + 68, y + 1);
	cout << VERTICAL_BLACK_PIECE;

	gotoxy(x, y + 1);
	for (int i = 0; i < 68; ++i) {
		Sleep(20);
		cout << char(178);
	}

	while (_kbhit())
		_getch();
}

void GAME::settings() {
	Nocursortype();
	txtColor(15);
	fillMenu();
	int x = 74;
	int y = 18;
	gotoxy(x + 1, y);
	for (int i = 0; i < 20; ++i)
		cout << UP_BLACK_PIECE;
	for (int i = y; i < y + 7; ++i)
	{
		gotoxy(x, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	for (int i = y; i < y + 7; ++i)
	{
		gotoxy(x + 21, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	gotoxy(x + 1, y + 6);
	for (int i = 0; i < 20; ++i)
		cout << DOWN_BLACK_PIECE;

	txtColor(15);
	gotoxy(x + 6, y + 1); cout << "MODE:";
	if (mode == true) {
		gotoxy(x + 12, y + 1); cout << "EASY";
	}
	else {
		gotoxy(x + 12, y + 1); cout << "HARD";
	}
	gotoxy(x + 6, y + 3); cout << "SOUND:";
	if (checkMute == false) {
		gotoxy(x + 13, y + 3); cout << "ON";
	}
	else {
		gotoxy(x + 13, y + 3); cout << "OFF";
	}
	gotoxy(x + 9, y + 5); cout << "BACK";

	int cnt = 0;
	while (true)
	{
		char choice = _getch();
		txtColor(15);
		gotoxy(x + 6, y + 1); cout << "MODE:";
		gotoxy(x + 6, y + 3); cout << "SOUND:";
		gotoxy(x + 8, y + 5); cout << " BACK ";

		if (choice == KEY_DOWN || choice == 'S' || choice == 's') {
			cnt++;
			if (cnt > 3)
				cnt = 1;
		}
		if (choice == KEY_UP || choice == 'W' || choice == 'w') {
			cnt--;
			if (cnt < 1)
				cnt = 3;
		}
		if (cnt == 1) {
			txtColor(240);
			gotoxy(x + 6, y + 1); cout << "MODE:";
			if (choice == KEY_ENTER) {
				if (mode == true)
					mode = false;
				else
					mode = true;

				if (mode == true) {
					txtColor(15);
					gotoxy(x + 12, y + 1); cout << "EASY";
				}
				else {
					txtColor(15);
					gotoxy(x + 12, y + 1); cout << "HARD";
				}
			}
		}
		if (cnt == 2) {
			txtColor(240);
			gotoxy(x + 6, y + 3); cout << "SOUND:";
			if (choice == KEY_ENTER) {
				if (checkMute == true)
					checkMute = false;
				else
					checkMute = true;

				if (checkMute == false) {
					txtColor(15);
					gotoxy(x + 13, y + 3); cout << "ON ";
					PlaySound(TEXT("Sound\\SugarCookie.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				}
				else {
					txtColor(15);
					gotoxy(x + 13, y + 3); cout << "OFF";
					PlaySound(NULL, NULL, SND_ASYNC);
				}
			}
		}
		if (cnt == 3) {
			txtColor(240);
			gotoxy(x + 8, y + 5); cout << " BACK ";
			if (choice == KEY_ENTER) {
				fillMenu();
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
				txtColor(240);
				gotoxy(x + 6, y + 5); cout << " SETTINGS ";
				txtColor(15);
				gotoxy(x + 9, y + 7); cout << "EXIT";
				return;
			}
		}
	}
}

void GAME::menu() {
	while (true) {
		clrscr();
		logoCrossyRoad();
		if (checkMute == false)
			PlaySound(TEXT("Sound\\SugarCookie.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
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
		gotoxy(x + 7, y + 5); cout << "SETTINGS";
		gotoxy(x + 9, y + 7); cout << "EXIT";

		int cnt = 0;
		while (true) {
			char choice = _getch();
			txtColor(15);
			gotoxy(x + 6, y + 1); cout << " NEW GAME ";
			gotoxy(x + 4, y + 3); cout << " LOADING GAME ";
			gotoxy(x + 6, y + 5); cout << " SETTINGS ";
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
				if (choice == KEY_ENTER) {
					loadingBar();
					txtColor(15);
					newGame();
					break;
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
				gotoxy(x + 6, y + 5); cout << " SETTINGS ";
				if (choice == KEY_ENTER) {
					settings();
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
		while (true) {
			if (checkLoadGame == true)
				newGame();
			else
				break;
		}
	}
}

void GAME::newGame() {
	Nocursortype();
	txtColor(15);

	if (checkLoadGame == false) {
		map.~MAP();
		new(&map) MAP();
		new(&map.level) LEVEL(mode, 1);
	}

	clrscr();
	map.printMap();
	map.drawPlayer();

	if (checkLoadGame == false)
		map.initializeMap();

	map.initialRender();

	checkLoadGame = false;
	checkPauseGame = false;
	int frameTime = 0;
	int round = map.level.getLevel();
	txtColor(14);
	gotoxy(142, 8); cout << round;
	gotoxy(152, 8);
	if (mode == true)
		cout << "EASY";
	else
		cout << "HARD";
	txtColor(15);

	while (!map.checkEndMap()) {
		if (checkPauseGame == false) {
			if (++frameTime == INT_MAX)
				frameTime = 0;
			map.generateMap(frameTime);
		}
		else if (checkPauseGame == true) {
			txtColor(12); gotoxy(133, 23); cout << MIDDLE_SMALL_BLACK_PIECE << " PAUSE GAME " << endl;
			txtColor(15);
			gotoxy(134, 25); cout << " RESUME " << endl;
			gotoxy(134, 27); cout << "  EXIT  " << endl;

			int temp = 0;
			while (true) {
				char choice = _getch();
				txtColor(15);
				gotoxy(134, 25); cout << " RESUME " << endl;
				gotoxy(134, 27); cout << "  EXIT  " << endl;

				if (choice == KEY_DOWN || choice == 'S' || choice == 's') {
					temp++;
					if (temp > 2)
						temp = 1;
				}
				if (choice == KEY_UP || choice == 'W' || choice == 'w') {
					temp--;
					if (temp < 1)
						temp = 2;
				}
				if (temp == 1) {
					txtColor(240);
					gotoxy(134, 25); cout << " RESUME " << endl;
					if (choice == KEY_ENTER) {
						checkPauseGame = false;
						txtColor(0);
						gotoxy(133, 23); cout << "             " << endl;
						gotoxy(134, 25); cout << "        " << endl;
						gotoxy(134, 27); cout << "        " << endl;
						txtColor(15);
						break;
					}
				}
				if (temp == 2) {
					txtColor(240);
					gotoxy(134, 27); cout << "  EXIT  " << endl;
					if (choice == KEY_ENTER) {
						checkPauseGame = false;
						txtColor(0);
						gotoxy(133, 23); cout << "             " << endl;
						gotoxy(134, 25); cout << "        " << endl;
						gotoxy(134, 27); cout << "        " << endl;
						txtColor(15);
						return;
					}
				}
			}
		}

		if (_kbhit()) {
			char key = _getch();

			if (key == 'J' || key == 'j') {
				checkPauseGame = true;
				// save game
				saveGame();
				clrscr();
				map.printMap();
				map.initialRender();
				txtColor(14);
				gotoxy(142, 8); cout << round;
				gotoxy(152, 8);
				if (mode == true)
					cout << "EASY";
				else
					cout << "HARD";
				txtColor(15);
				checkPauseGame = false;
			}
			if (key == 'L' || key == 'l') {
				checkLoadGame = false;
				checkPauseGame = true;
				// load game
				loadGame();
				clrscr();
				map.printMap();
				map.initialRender();
				txtColor(14);
				gotoxy(142, 8); cout << round;
				gotoxy(152, 8);
				if (mode == true)
					cout << "EASY";
				else
					cout << "HARD";
				txtColor(15);
				checkPauseGame = false;
				if (checkLoadGame == true)
					return;
			}
			if (key == 'p') {
				checkPauseGame = true;
			}

			if (key == 'W' || key == 'w') {
				map.updatePosPlayer('W');
			}
			if (key == 'S' || key == 's') {
				map.updatePosPlayer('S');
			}
			if (key == 'A' || key == 'a') {
				map.updatePosPlayer('A');
			}
			if (key == 'D' || key == 'd') {
				map.updatePosPlayer('D');
			}

			map.drawPlayer();
		}

		if (map.checkCollision()){
			Sleep(1500);
			checkPauseGame = false;
			txtColor(15);
			clrscr();
			PlaySound(TEXT("Sound\\GameOver.wav"), NULL, SND_FILENAME | SND_ASYNC);
			for (int i = 0; i < 16; ++i) {
				clrscr();
				txtColor(i);
				logoLoseGame();
				Sleep(140);
			}
			while (_kbhit())
				_getch();
			gotoxy(68, 10);		cout << "*** Press any key to continue ***";
			txtColor(15);
			_getch();
			return;
		}

		if (map.checkWin() == true) {
			if (map.checkMaxLevel() == true) {
				clrscr();
				PlaySound(TEXT("Sound\\Victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
				for (int i = 0; i < 16; ++i) {
					clrscr();
					txtColor(i);
					logoWinGame();
					Sleep(140);
				}
				while (_kbhit())
					_getch();
				gotoxy(94, 22);		cout << "*** Press any key to continue ***";
				txtColor(15);
				_getch();
				return;
			}

			round++;
			PlaySound(TEXT("Sound\\LevelUp.wav"), NULL, SND_FILENAME | SND_ASYNC);
			txtColor(14);
			gotoxy(57, 2); cout << "LEVEL UP!!!";
			Sleep(1000);
			gotoxy(57, 2); cout << "            ";
			gotoxy(142, 8); cout << round;
			txtColor(15);
			map.fillInsideMap();
			map.levelUp();
			map.resetPlayer();
			map.initializeMap();
			map.printMap();
			map.initialRender();
			map.drawPlayer();
			if (checkMute == false)
				PlaySound(TEXT("Sound\\SugarCookie.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

			while (_kbhit())
				_getch();
		}
	
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
	string filename = "Data/";
	filename += file + ".bin";
	Nocursortype();
	Sleep(50);
	while (_kbhit())
		_getch();

	if (map.loadGame(filename, mode) == false) {
		checkLoadGame = false;
		return;
	}
	else {
		checkLoadGame = true;
	}

}

void GAME::saveGame() {
	logoSaveGame();
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
	string filename = "Data/";
	filename +=  file + ".bin";
	Nocursortype();
	Sleep(50);
	while (_kbhit())
		_getch();

	map.saveGame(filename, mode);
}

