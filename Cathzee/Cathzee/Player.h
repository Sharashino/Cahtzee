#pragma once
class Player
{
public:
	double liczba; //prawo dost�pu: publiczne
	char tablica[20]; //prawo dost�pu: publiczne
	int TwojaPrywatnaFunkcja(int a, int b)
	{
		return(a + b);
	}

private:
	int abc; //prawo dost�pu: prytatne
	char znak; //prawo dost�pu: prytatne
	std::string napis; //prawo dost�pu: prytatne
};

