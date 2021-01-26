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
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 1000, TRUE);


	std::cout << "Witaj w Cahtzee - grze w kosci!\n";
	std::cout << "Autorstwa Gerarda Adamkiewicza i Piotra Smilgina\n";

	Player player1;
	Player player2;

	player1.SetName("pierwszego gracza");
	player2.SetName("drugiego gracza");

	int i = 0;

	while ((player1.slotsFilled != 13) && (player2.slotsFilled != 13))
	{
		if (i % 2 == 0)
		{
			player1.TakeTurn();
		}
		else
		{
			player2.TakeTurn();
		}

		++i;
	}

	SumPlayersPoints(player1, player2);

	return 0;
}
