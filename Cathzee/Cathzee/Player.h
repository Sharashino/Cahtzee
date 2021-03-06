#include <stdlib.h>
#include <random>
#include <iostream>
#include <string>
#include <stdio.h>
#include <limits>

class Player
{
public:
    Player() { playerScore = 0; topScore = 0; aces = -1; twos = -1; threes = -1; fours = -1; fives = -1; sixes = -1; bonus = -1; threeKind = -1; fourKind = -1; fullHouse = -1; smStraight = -1; lrgStraight = -1; yahtzee = -1; chance = -1; bonus = -1; slotsFilled = 0; }
    int slotsFilled;
    int playerScore;
    void SetName(std::string name);
    void RollFiveDice();
    void ShowCurrentDices();
    void HoldDice();
    void TakeTurn();
    void ReRoll();
    void SelectScoreCard();
    void DisplayScoreboard();
    void EndGame();
    int RollDice();
    int DisplayPlayerScore();
private:
    std::string playerName;
    int diceArray[5];
    int topScore;
    int aces;
    int twos;
    int threes;
    int fours;
    int fives;
    int sixes;
    int bonus;
    int threeKind;
    int fourKind;
    int fullHouse;
    int smStraight;
    int lrgStraight;
    int yahtzee;
    int chance;
};

