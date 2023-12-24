#pragma once
#include<SFML/Graphics.hpp>
#include"../State.h"
#include"VectorSortare.h"

class SortareState : public State {
private:
	sf::Text sortType, inapoi, reset, crescator, descrescator, bubble, selection,insertion,merge;
	sf::RectangleShape dropdownButton,drp1,drp2,drp3, drp4;
	sf::RectangleShape linie;
	sf::ConvexShape triangle;
	bool isSelectedStart, isSelectedInapoi, isSelectedReset, isSelectedCrescator, isSelectedDescrescator, isSelectedDrop, isSelectedBubble, isSelectedIns, isSelectedSel, isSelectedMerge;
	bool isPressedStart, isPressedInapoi, isPressedReset, isPressedCrescator, isPressedDescrescator, isPressedDrop, isPressedBubble, isPressedIns,isPressedSel, isPressedMerge;
	VectorSortare vectS;

public:
	SortareState(Game *game);
	void handleInput() override;
	void update(double) override;
	void draw(double) override;
};