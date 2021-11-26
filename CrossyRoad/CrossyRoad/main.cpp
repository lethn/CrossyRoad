#include "GAME.h"
#include "MAP.h"
using namespace std;

int main() {
	GAME game;
	game.resizeConsole(1280, 720);
	game.FixConsoleWindow();
	
	game.logo();
	game.menu();
	cout << "\n\n\n\n";

	//MAP map;
	//map.printMapScreen();


	return 0;
}