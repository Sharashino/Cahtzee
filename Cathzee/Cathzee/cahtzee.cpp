#include "Player.h"
#include "DiceDrawer.h"

int Player::rollDice()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> result(1, 6);

	return result(gen);
}

void Player::rollFiveDice()
{
	for (int i = 0; i < 5; i++)
	{
		int x = rollDice();
		diceArray[i] = x;

		switch (diceArray[i])
		{
		case 1: 
			DrawDice1();
			break;
		case 2:
			DrawDice2();
			break;
		case 3:
			DrawDice3();
			break;
		case 4:
			DrawDice4();
			break;
		case 5:
			DrawDice5();
			break;
		case 6:
			DrawDice6();
			break;
		default:
			break;
		}
	}
}
