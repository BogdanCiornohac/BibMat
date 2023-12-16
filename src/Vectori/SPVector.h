#pragma once
#include<SFML/Graphics.hpp>
#include"../Game.h"

class SPVector
{
private:
	int v[101], vectorSize, inaltime;
	long long int blinkingCellIndex, suma;
	bool start, isSum;
	sf::Text operatie, rezultat;
	sf::Clock blinkTimer;

public:
	SPVector();
	void deseneazaVector(Game *game);
	void reset();
	void seteazaOperatie(bool status);
	void startOperation();
	void stopOperation();
};
