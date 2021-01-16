#pragma once
class Player
{
public:
	double liczba; //prawo dostêpu: publiczne
	char tablica[20]; //prawo dostêpu: publiczne
	int TwojaPrywatnaFunkcja(int a, int b)
	{
		return(a + b);
	}

private:
	int abc; //prawo dostêpu: prytatne
	char znak; //prawo dostêpu: prytatne
	std::string napis; //prawo dostêpu: prytatne
};

