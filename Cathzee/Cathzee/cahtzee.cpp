#include "Player.h"
#include <iostream>

int Player::RollDice()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> result(1, 6);

	return result(gen);
}


void Player::HoldDice()
{

}

void Player::DisplayCurDice()
{

}

void Player::TakeTurn()
{
}



