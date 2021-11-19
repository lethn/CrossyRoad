#include "Menu.h"

void UserInterface::resizeConsole(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT edge;
	GetWindowRect(console, &edge);
	MoveWindow(console, edge.left, edge.top, width, height, TRUE);
}

void UserInterface::FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void UserInterface::gotoxy(int x, int y) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void UserInterface::Nocursortype() {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void UserInterface::UnNocursortype() {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void UserInterface::txtColor(int color) {
	HANDLE hConsoleColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void UserInterface::logo() {
	txtColor(15);
	int x = 19;
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