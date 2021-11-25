#include "Menu.h"
#include "Map.h"
using namespace std;

int main() {
	UserInterface UI;
	UI.resizeConsole(1280, 720);
	UI.FixConsoleWindow();
	
	UI.logo();
	UI.menu();
	cout << "\n\n\n\n";

	//Map map;
	//map.printMapScreen();


	return 0;
}