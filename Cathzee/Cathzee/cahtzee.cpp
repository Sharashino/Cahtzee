#include "Player.h"
#include <iostream>

int Player::rollDice()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> result(1, 6);

	return result(gen);
}

void Player::reRoll()
{
	for (int i = 0; i < 5; i++)
	{
		diceArray[i] = rollDice();
	}
}

void Player::showCurrentDice()
{

}

void Player::takeTurn()
{

}