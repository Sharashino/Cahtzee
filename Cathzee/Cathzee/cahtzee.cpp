#include "Player.h"
#include "DiceDrawer.h"

void Player::SetName()
{
    std::cout << "Podaj imie: ";
	std::cin >> playerName;
	
}

int Player::RollDice()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> result(1, 6);

	return result(gen);
}

void Player::RollFiveDice()
{
	std::cout << "Rolling for " << playerName;
	std::cout << "\n";

	for (int i = 0; i < 5; i++)
	{
		int x = RollDice();
		diceArray[i] = x;

        std::cout << i + 1;

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

void Player::DisplayPlayerCard() {
    std::cout << "------------------------------------" << std::endl;
    if (aces != -1) {
        std::cout << "a. Aces           | " << aces << std::endl;
    }
    else {
        std::cout << "a. Aces           | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (twos != -1) {
        std::cout << "b. 2's            | " << twos << std::endl;
    }
    else {
        std::cout << "b. 2's            | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (threes != -1) {
        std::cout << "c. 3's            | " << threes << std::endl;
    }
    else {
        std::cout << "c. 3's            | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (fours != -1) {
        std::cout << "d. 4's            | " << fours << std::endl;
    }
    else {
        std::cout << "d. 4's            | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (fives != -1) {
        std::cout << "e. 5's            | " << fives << std::endl;
    }
    else {
        std::cout << "e. 5's            | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (sixes != -1) {
        std::cout << "f. 6's            | " << sixes << std::endl;
    }
    else {
        std::cout << "f. 6's            | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (bonus != -1) {
        std::cout << "Bonus             | " << bonus << std::endl;
    }
    else {
        std::cout << "Bonus             | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Top Score            | " << topScore << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    if (threeKind != -1) {
        std::cout << "g. 3 of a kind       | " << threeKind << std::endl;
    }
    else {
        std::cout << "g. 3 of a kind       | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (fourKind != -1) {
        std::cout << "h. 4 of a kind       | " << fourKind << std::endl;
    }
    else {
        std::cout << "h. 4 of a kind       | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (fullHouse != -1) {
        std::cout << "i. Full House        | " << fullHouse << std::endl;
    }
    else {
        std::cout << "i. Full House        | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (smStraight != -1) {
        std::cout << "j. Sm. Straight      | " << smStraight << std::endl;
    }
    else {
        std::cout << "j. Sm. Straight      | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (lrgStraight != -1) {
        std::cout << "k. Lrg. Straight     | " << lrgStraight << std::endl;
    }
    else {
        std::cout << "k. Lrg. Straight     | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (yahtzee != -1) {
        std::cout << "l. Yahtzee           | " << yahtzee << std::endl;
    }
    else {
        std::cout << "l. Yahtzee           | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (chance != -1) {
        std::cout << "m. Chance            | " << chance << std::endl;
    }
    else {
        std::cout << "m. Chance            | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Score                    | " << playerScore << std::endl;
    std::cout << "------------------------------------" << std::endl;
}