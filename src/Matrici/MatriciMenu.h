#pragma once
#include"../State.h"

class MatriciMenu : public State {
private:
	sf::Text titlu, adScInmImp, transpusaInverMat, operatiiMatrice, inapoi;
	bool isSelectedASII, isSelectedTIM, isSelectedOM, isSeLectedInapoi;
	bool isPressedASII, isPressedTIM, isPressedOM, isPressedInapoi;

public:
	MatriciMenu(Game *game);
	void handleInput() override;
	void update(double) override;
	void draw(double) override;
};