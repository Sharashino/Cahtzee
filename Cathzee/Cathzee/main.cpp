#include <windows.h>
#include "Player.h"

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 800, 800, TRUE); // 800 width, 100 height

	std::cout << "Witaj w grze w kosci!\n";

	Player player1;

	player1.SetName();
	player1.TakeTurn();



	return 0;
}