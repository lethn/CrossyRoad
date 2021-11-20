#include "Library.h"
#define DOWN_BLACK_PIECE char(220);
#define UP_BLACK_PIECE char(223);
#define VERTICAL_BLACK_PIECE char(219);

#define HORIZONTAL_PALE_PIECE char(205);
#define VERTICAL_PALE_PIECE char(186);
#define UP_LEFT_CORNER_PALE_PIECE char(201);
#define UP_RIGHT_CORNER_PALE_PIECE char(187);
#define DOWN_LEFT_CORNER_PALE_PIECE char(200);
#define DOWN_RIGHT_CORNER_PALE_PIECE char(188);

#define KEY_DOWN 80
#define KEY_UP 72
#define KEY_ESC 27
#define KEY_ENTER 13

class UserInterface {
public:
	void resizeConsole(int width, int height);
	void FixConsoleWindow();
	void gotoxy(int x, int y);
	void Nocursortype();
	void UnNocursortype();
	void txtColor(int color);

	void logo();
	void menu();
};