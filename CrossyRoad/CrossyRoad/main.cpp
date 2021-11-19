#include "Menu.h"
using namespace std;

int main() {
	UserInterface UI;
	UI.resizeConsole(1000, 600);
	UI.FixConsoleWindow();
	
	UI.logo();
	UI.menu();
	cout << "\n\n\n\n";

	return 0;
}