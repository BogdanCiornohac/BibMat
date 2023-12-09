#pragma once
#include"../State.h"

class VectoriMenu : public State {
private:
	sf::Text titlu, sumaProdElem, sortareElemente, inmScalar, inapoi;
	bool isSelectedSPE, isSelectedSE, isSelectedIS, isSeLectedInapoi;
	bool isPressedSPE, isPressedSE, isPressedIS, isPressedInapoi;

public:
	VectoriMenu(Game* game);
	void handleInput() override;
	void update(double) override;
	void draw(double) override;

};