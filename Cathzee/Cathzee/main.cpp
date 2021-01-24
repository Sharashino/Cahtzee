#include <windows.h>
#include "Player.h"


void SumPlayersPoints(Player fstPlayer, Player secPlayer)
{

	if (fstPlayer.playerScore > secPlayer.playerScore)
	{
		fstPlayer.EndGame();
	}
	else
	{
		secPlayer.EndGame();
	}
}


int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 800, 1000	, TRUE); // 800 width, 100 height

	std::cout << "Witaj w grze w kosci!\n";

	Player player1;
	Player player2;

	player1.SetName();
	player2.SetName();

	int i = 0;

	while (player1.slotsFilled != 13 && player2.slotsFilled != 13)
	{
		if (i % 2 == 0)
		{
			player1.TakeTurn();
		}
		else
		{
			player2.TakeTurn();
		}

		i++;
	}

	SumPlayersPoints(player1, player2);


	return 0;
}
