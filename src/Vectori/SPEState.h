#pragma once
#include "../State.h"
#include "../Game.h"
#include "SPVector.h"

class SPEState: public State
{
private:
	sf::Text start, inapoi, reset, suma, produs;
	sf::RectangleShape linie;
	SPVector vectorV;
	bool isSelectedStart, isSelectedInapoi, isSelectedReset, isSelectedSuma, isSelectedProdus;
	bool isPressedStart, isPressedInapoi, isPressedReset, isPressedSuma, isPressedProdus;
	

public:
	SPEState(Game *game);
	void handleInput() override;
	void update(double) override;
	void draw(double) override;

};

