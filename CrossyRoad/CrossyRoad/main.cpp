#include "GAME.h"
#include "MAP.h"
using namespace std;

int main() {
	GAME game;
	game.resizeConsole(1280, 720);
	game.FixConsoleWindow();

	game.menu();
	return 0;
}