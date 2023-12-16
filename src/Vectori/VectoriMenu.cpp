#include "VectoriMenu.h"
#include"../MenuState.h"
#include "SPEState.h"


VectoriMenu::VectoriMenu(Game* game)
{
	this->game = game;
	this->isSelectedIS = true;

	sf::Color titleColor(0x29ADB2FF);
	sf::Color selectedColor(0x0766ADFF);

	titlu.setFont(this->game->font);
	titlu.setString("Operatii pe Vectori");
	titlu.setFillColor(titleColor);
	titlu.setCharacterSize(80);

	titlu.setOrigin(titlu.getLocalBounds().width / 2,
		titlu.getLocalBounds().height / 2);

	titlu.setPosition(this->game->window.getSize().x / 2,
		40);

	//inmultire scalar
	inmScalar.setFont(this->game->font);
	inmScalar.setFillColor(selectedColor);
	inmScalar.setCharacterSize(40);
	inmScalar.setString("Inmultirea elementelor cu un scalar");

	inmScalar.setOrigin(inmScalar.getLocalBounds().width / 2,
		inmScalar.getLocalBounds().height / 2);

	inmScalar.setPosition(this->game->window.getSize().x / 2,
		this->game->window.getSize().y / 2 - 75);

	//Suma sau produsul elementelor
	sumaProdElem = inmScalar;
	sumaProdElem.setString("Suma / Produsul elementelor");

	sumaProdElem.setOrigin(sumaProdElem.getLocalBounds().width / 2,
		sumaProdElem.getLocalBounds().height / 2);

	sumaProdElem.setPosition(this->game->window.getSize().x / 2,
		this->game->window.getSize().y / 2 - 25);

	//sortare elemente

	sortareElemente = sumaProdElem;

	sortareElemente.setString("Sortarea elementelor");

	sortareElemente.setOrigin(sortareElemente.getLocalBounds().width / 2,
		sortareElemente.getLocalBounds().height / 2);

	sortareElemente.setPosition(this->game->window.getSize().x / 2,
		this->game->window.getSize().y / 2 + 25);
	


	//inapoi
	inapoi = sumaProdElem;

	inapoi.setString("inapoi");

	inapoi.setOrigin(inapoi.getLocalBounds().width / 2,
		inapoi.getLocalBounds().height / 2);

	inapoi.setPosition(this->game->window.getSize().x / 2,
		this->game->window.getSize().y / 2 + 75);

}

void VectoriMenu::handleInput()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			game->window.close();

		if (event.type == sf::Event::MouseButtonPressed) {
				if (isSelectedSPE)
				{
					isPressedSPE = true;
				}
				else if (isSelectedSE)
				{
					isPressedSE = true;
				}
				else if (isSelectedIS)
				{
					isPressedIS = true;
				}
				else if(isSeLectedInapoi)
				{
					isPressedInapoi = true;
				} 
		}
	}

}

void VectoriMenu::update(double dt)
{
	sumaProdElem.setFillColor(sf::Color::White);
	sortareElemente.setFillColor(sf::Color::White);
	inmScalar.setFillColor(sf::Color::White);
	inapoi.setFillColor(sf::Color::White);

	sf::Color selectedColor(0x0766ADFF);

	isSelectedSPE = game->isMouseOverText(sumaProdElem);
	isSelectedSE = game->isMouseOverText(sortareElemente);
	isSelectedIS = game->isMouseOverText(inmScalar);
	isSeLectedInapoi = game->isMouseOverText(inapoi);

	if (isSelectedSPE)
	{
		sumaProdElem.setFillColor(selectedColor);
		sumaProdElem.setCharacterSize(47);
	}
	else {
		sumaProdElem.setCharacterSize(40);
	}

	if (isSelectedSE)
	{
		sortareElemente.setFillColor(selectedColor);
		sortareElemente.setCharacterSize(47);
	}else {
		sortareElemente.setCharacterSize(40);
	}

	if (isSelectedIS)
	{
		inmScalar.setFillColor(selectedColor);
		inmScalar.setCharacterSize(44);
	}
	else {
		inmScalar.setCharacterSize(40);
	}

	if (isSeLectedInapoi) {
		inapoi.setFillColor(selectedColor);
		inapoi.setCharacterSize(47);
	}
	else {
		inapoi.setCharacterSize(40);
	}

	 if (isPressedSE) {
		isPressedSE = false;
	}else if (isPressedSPE)
	{
		isPressedSPE = false;
		game->pushState(new SPEState(game));
	}
	else if (isPressedIS) {
		isPressedIS = false;
	}
	else if (isPressedInapoi)
	{
		isPressedInapoi = false;
		game->pushState(new menuState(game));
	}
}

void VectoriMenu::draw(double dt)
{
	game->window.draw(titlu);
	game->window.draw(sumaProdElem);
	game->window.draw(sortareElemente);
	game->window.draw(inmScalar);
	game->window.draw(inapoi);
}