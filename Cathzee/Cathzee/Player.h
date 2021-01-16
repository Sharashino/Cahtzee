#include <stdlib.h>
#include <random>
class Player
{
public:
	int score = 0; //prawo dostêpu: publiczne
	int ones; //prawo dostêpu: publiczne
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
	int abc; //prawo dostêpu: prytatne
	char znak; //prawo dostêpu: prytatne
	std::string napis; //prawo dostêpu: prytatne
};

