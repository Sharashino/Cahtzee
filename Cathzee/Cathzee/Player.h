#include <stdlib.h>
#include <random>
class Player
{
public:
	int score = 0; //prawo dost�pu: publiczne
	int ones; //prawo dost�pu: publiczne
	int twos;
	int threes;
	int fours;
	int fives;
	int sixs;
	int RollDice();
	void ReReollDice();
	void HoldDice();
	void DisplayCurDice();
	void TakeTurn();

private:
	int abc; //prawo dost�pu: prytatne
	char znak; //prawo dost�pu: prytatne
	std::string napis; //prawo dost�pu: prytatne
};

