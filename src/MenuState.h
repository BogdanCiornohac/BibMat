#pragma once
#include "State.h"

class menuState : public State
{
private:
	sf::Text matriciText, inchideText, vectoriText, titlu;
	bool isPressedPlay, isPressedExit, isPressedVectori;
	bool isSelectedPlay, isSelectedExit, isSelectedVectori;

public:
	menuState(Game* game);
	void handleInput() override;
	void update(double) override;
	void draw(double) override;
};
