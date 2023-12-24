#pragma once
#include "../State.h"
#include "../Game.h"
#include "SPVector.h"

class ISState : public State
{
private:
	sf::Text start, inapoi, reset, scalar;
	sf::RectangleShape linie;
	SPVector vectorV;
	bool isSelectedStart, isSelectedInapoi, isSelectedReset, isSelectedScalar;
	bool isPressedStart, isPressedInapoi, isPressedReset, isPressedScalar;


public:
	ISState(Game* game);
	void handleInput() override;
	void update(double) override;
	void draw(double) override;
};