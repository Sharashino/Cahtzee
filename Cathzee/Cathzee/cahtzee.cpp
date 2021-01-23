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

void Player::ReRoll()
{
    for (int i = 0; i < 5; i++)
    {
        if (diceArray[i] == 0)
        {
            diceArray[i] = RollDice();
        }
    }
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

void Player::ShowCurrentDices()
{
    for (int i = 0; i < 5; i++)
    {
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

void Player::TakeTurn()
{
        RollFiveDice();

        int remainingRolls = 3;
        int playerChoice = 0;

        while (remainingRolls > 0)
        {

            std::cout << "Pozostala liczba ponownych rzutow: " << remainingRolls << std::endl;
            std::cout << "Co chcesz zrobic?" << std::endl;
            std::cout << "1. Wybierz kosci do zostawienia" << std::endl;
            std::cout << "2. Ponowny rzut wszystkimi koscmi" << std::endl;
            std::cout << "3. Zakoncz ture i wybierz kategorie" << std::endl;
            std::cout << "4. Pokaz tablice z punktami" << std::endl;
            std::cout << "5. Pokaz kostki" << std::endl;
            std::cout << "Wybor: ";
            std::cin >> playerChoice;

            switch (playerChoice)
            {
            case 1:
                HoldDice();
                system("cls");
                ShowCurrentDices();
                break;
            case 2:
                system("cls");
                RollFiveDice();
                break;
            case 3:
                remainingRolls = 0;
                system("cls");
                SelectScoreCard();
                break;
            case 4:
                remainingRolls++;
                system("cls");
                DisplayScoreboard();
                break;
            case 5:
                remainingRolls++;
                system("cls");
                ShowCurrentDices();
                break;
            default:
                std::cout << "Wybierz wlasciwa opcje!!! \n";
                remainingRolls++;
                break;
            }

            remainingRolls--;

            if (remainingRolls == 0)
            {
                SelectScoreCard();
            }
        }
}

void Player::HoldDice()
{
    std::string diceToHold;

    std::cout << "Podaj numer kostki, ktora chcesz zatrzymac" << std::endl;
    std::cout << "Wypisz numery kostek bez spacji: ";
    std::cin >> diceToHold;

    if ((diceToHold.find("1", 0, 1)) == -1) {
        diceArray[0] = 0;
    }
    if ((diceToHold.find("2", 0, 1)) == -1) {
        diceArray[1] = 0;
    }
    if ((diceToHold.find("3", 0, 1)) == -1) {
        diceArray[2] = 0;
    }
    if ((diceToHold.find("4", 0, 1)) == -1) {
        diceArray[3] = 0;
    }
    if ((diceToHold.find("5", 0, 1)) == -1) {
        diceArray[4] = 0;
    }

    ReRoll();
}


void Player::SelectScoreCard()
{
    char category;

    ShowCurrentDices();
    DisplayScoreboard();

    std::cout << "Wybierz kategorie punktow: ";
    std::cin >> category;


    bool valid = false;

    while (valid == false)
    {
        switch (category)
        {
        case 'a':
            if (aces == -1)
            {
                aces = 0;

                for (int i = 0; i < 5; i++)
                {
                    if (diceArray[i] == 1)
                    {
                        aces++;
                    }
                }

                slotsFilled++;
                playerScore += aces;
                topScore += aces;
                valid = true;
            }
            else
            {
                std::cout << "Juz wypelniles to pole! \n";
                SelectScoreCard();
            }
            break;
        case 'b':
            if (twos == -1)
            {
                twos = 0;

                for (int i = 0; i < 5; i++)
                {
                    if (diceArray[i] == 2)
                    {
                        twos += 2;
                    }
                }

                slotsFilled++;
                playerScore += twos;
                topScore += twos;
                valid = true;
            }
            else
            {
                std::cout << "Juz wypelniles to pole! \n";
                SelectScoreCard();
            }
            break;
        case 'c':
            if (threes == -1)
            {
                threes = 0;

                for (int i = 0; i < 5; i++)
                {
                    if (diceArray[i] == 3)
                    {
                        threes += 3;
                    }
                }

                slotsFilled++;
                playerScore += threes;
                topScore += threes;
                valid = true;
            }
            else
            {
                std::cout << "Juz wypelniles to pole! \n";
                SelectScoreCard();
            }
            break;
        case 'd':
            if (fours == -1)
            {
                fours = 0;

                for (int i = 0; i < 5; i++)
                {
                    if (diceArray[i] == 4)
                    {
                        fours += 4;
                    }
                }

                slotsFilled++;
                playerScore += fours;
                topScore += fours;
                valid = true;
            }
            else
            {
                std::cout << "Juz wypelniles to pole! \n";
                SelectScoreCard();
            }
            break;
        case 'e':
            if (fives == -1)
            {
                fives = 0;

                for (int i = 0; i < 5; i++)
                {
                    if (diceArray[i] == 5)
                    {
                        fives += 5;
                    }
                }

                slotsFilled++;
                playerScore += fives;
                topScore += fives;
                valid = true;
            }
            else
            {
                std::cout << "Juz wypelniles to pole! \n";
                SelectScoreCard();
            }
            break;
        case 'f':
            if (sixes == -1)
            {
                sixes = 0;

                for (int i = 0; i < 5; i++)
                {
                    if (diceArray[i] == 6)
                    {
                        sixes += 6;
                    }
                }

                slotsFilled++;
                playerScore += sixes;
                topScore += sixes;
                valid = true;
            }
            else
            {
                std::cout << "Juz wypelniles to pole! \n";
                SelectScoreCard();
            }
            break;
        case 'g':
            if (threeKind == -1)
            {
                threeKind = 0;
                int oneCount = 0;
                int twoCount = 0;
                int threeCount = 0;
                int fourCount = 0;
                int fiveCount = 0;
                int sixCount = 0;

                for (int i = 0; i < 5; i++)
                {
                    if (diceArray[i] == 1) { oneCount++; }
                    if (diceArray[i] == 2) { twoCount++; }
                    if (diceArray[i] == 3) { threeCount++; }
                    if (diceArray[i] == 4) { fourCount++; }
                    if (diceArray[i] == 5) { fiveCount++; }
                    if (diceArray[i] == 6) { sixCount++; }
                }

                if (oneCount > 2 || twoCount > 2 || threeCount > 2 || fourCount > 2 || fiveCount > 2 || sixCount > 2)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        threeKind += diceArray[i];
                    }
                }

                slotsFilled++;
                playerScore += threeKind;
                valid = true;
            }
            else
            {
                std::cout << "Juz wypelniles to pole! \n";
                SelectScoreCard();
            }
            break;
        case 'h':
            if (fourKind == -1)
            {
                fourKind = 0;
                int oneCount = 0;
                int twoCount = 0;
                int threeCount = 0;
                int fourCount = 0;
                int fiveCount = 0;
                int sixCount = 0;

                for (int i = 0; i < 5; i++)
                {
                    if (diceArray[i] == 1) { oneCount++; }
                    if (diceArray[i] == 2) { twoCount++; }
                    if (diceArray[i] == 3) { threeCount++; }
                    if (diceArray[i] == 4) { fourCount++; }
                    if (diceArray[i] == 5) { fiveCount++; }
                    if (diceArray[i] == 6) { sixCount++; }
                }

                if (oneCount > 3 || twoCount > 3 || threeCount > 3 || fourCount > 3 || fiveCount > 3 || sixCount > 3)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        fourKind += diceArray[i];
                    }
                }

                slotsFilled++;
                playerScore += fourKind;
                valid = true;
            }
            else
            {
                std::cout << "Juz wypelniles to pole! \n";
                SelectScoreCard();
            }
            break;
        case 'i':
            if (fullHouse == -1)
            {
                fullHouse = 0;
                int oneCount = 0;
                int twoCount = 0;
                int threeCount = 0;
                int fourCount = 0;
                int fiveCount = 0;
                int sixCount = 0;

                for (int i = 0; i < 5; i++)
                {
                    if (diceArray[i] == 1) { oneCount++; }
                    if (diceArray[i] == 2) { twoCount++; }
                    if (diceArray[i] == 3) { threeCount++; }
                    if (diceArray[i] == 4) { fourCount++; }
                    if (diceArray[i] == 5) { fiveCount++; }
                    if (diceArray[i] == 6) { sixCount++; }
                }

                if ((oneCount == 3 || twoCount == 3 || threeCount == 3 || fourCount == 3 || fiveCount == 3 || sixCount == 3) && (oneCount == 2 || twoCount == 2 || threeCount == 2 || fourCount == 2 || fiveCount == 2 || sixCount == 2))
                {
                    fullHouse = 25;
                }

                slotsFilled++;
                playerScore += fullHouse;
                valid = true;
            }
            else
            {
                std::cout << "Juz wypelniles to pole! \n";
                SelectScoreCard();
            }
            break;
        case 'j':
            if (smStraight == -1)
            {
                smStraight = 0;
                int oneCount = 0;
                int twoCount = 0;
                int threeCount = 0;
                int fourCount = 0;
                int fiveCount = 0;
                int sixCount = 0;

                for (int i = 0; i < 5; i++) {
                    if (diceArray[i] == 1) { oneCount++; }
                    if (diceArray[i] == 2) { twoCount++; }
                    if (diceArray[i] == 3) { threeCount++; }
                    if (diceArray[i] == 4) { fourCount++; }
                    if (diceArray[i] == 5) { fiveCount++; }
                    if (diceArray[i] == 6) { sixCount++; }
                }

                if ((oneCount >= 1 && twoCount >= 1 && threeCount >= 1 && fourCount >= 1) || (twoCount >= 1 && threeCount >= 1 && fourCount >= 1 && fiveCount >= 1) || (threeCount >= 1 && fourCount >= 1 && fiveCount >= 1 && sixCount >= 1))
                {
                    smStraight = 30;
                }

                slotsFilled++;
                playerScore += smStraight;
                valid = true;
            }
            else
            {
                std::cout << "Juz wypelniles to pole! \n";
                SelectScoreCard();
            }
            break;
        case 'k':
            if (lrgStraight == -1)
            {
                lrgStraight = 0;
                int oneCount = 0;
                int twoCount = 0;
                int threeCount = 0;
                int fourCount = 0;
                int fiveCount = 0;
                int sixCount = 0;

                for (int i = 0; i < 5; i++) {
                    if (diceArray[i] == 1) { oneCount++; }
                    if (diceArray[i] == 2) { twoCount++; }
                    if (diceArray[i] == 3) { threeCount++; }
                    if (diceArray[i] == 4) { fourCount++; }
                    if (diceArray[i] == 5) { fiveCount++; }
                    if (diceArray[i] == 6) { sixCount++; }
                }

                if ((oneCount >= 1 && twoCount >= 1 && threeCount >= 1 && fourCount >= 1 && fiveCount >= 1) || (twoCount >= 1 && threeCount >= 1 && fourCount >= 1 && fiveCount >= 1 && sixCount >= 1))
                {
                    lrgStraight = 40;
                }

                slotsFilled++;
                playerScore += lrgStraight;
                valid = true;
            }
            else
            {
                std::cout << "Juz wypelniles to pole! \n";
                SelectScoreCard();
            }
            break;
        case 'l':
            if (yahtzee == -1)
            {
                yahtzee = 0;
                int oneCount = 0;
                int twoCount = 0;
                int threeCount = 0;
                int fourCount = 0;
                int fiveCount = 0;
                int sixCount = 0;

                for (int i = 0; i < 5; i++)
                {
                    if (diceArray[i] == 1) { oneCount++; }
                    if (diceArray[i] == 2) { twoCount++; }
                    if (diceArray[i] == 3) { threeCount++; }
                    if (diceArray[i] == 4) { fourCount++; }
                    if (diceArray[i] == 5) { fiveCount++; }
                    if (diceArray[i] == 6) { sixCount++; }
                }

                if (oneCount == 5 || twoCount == 5 || threeCount == 5 || fourCount == 5 || fiveCount == 5 || sixCount == 5)
                {
                    yahtzee = 50;
                }

                slotsFilled++;
                playerScore += yahtzee;
                valid = true;
            }
            else
            {
                std::cout << "Juz wypelniles to pole! \n";
                SelectScoreCard();
            }
            break;
        case 'm':
            if (chance == -1)
            {
                chance = 0;

                for (int i = 0; i < 5; i++)
                {
                    chance += diceArray[i];
                }

                slotsFilled++;
                playerScore += chance;
                valid = true;
            }
            else
            {
                std::cout << "Juz wypelniles to pole! \n";
                SelectScoreCard();
            }
            break;
        default:
            std::cout << "Wpisz poprawna litere polecenia! \n";
            SelectScoreCard();
            break;
        }
    }
}

void Player::DisplayScoreboard() 
{
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

void Player::EndGame()
{
    system("CLS");
    std::cout << "Gratulacje, wygrywa gracz "<<playerName<<"!"<< std::endl;
    DisplayScoreboard();
}