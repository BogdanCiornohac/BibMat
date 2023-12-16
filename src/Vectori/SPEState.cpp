#include"SPEState.h"
#include "VectoriMenu.h"


SPEState::SPEState(Game *game) {
	this->game = game;

	//start
	start.setCharacterSize(40);
	start.setFont(game->font);
	start.setString("Incepe");
	start.setFillColor(sf::Color::White);
	start.setPosition(20, 15);

	// reset

	reset = start;
	reset.setString("Reset");
	reset.setPosition(250, 15);

	//suma

	suma = reset;
	suma.setString("suma");
	suma.setPosition( 450, 15);

	//produs am adunat 60 la toate

	produs = suma;
	produs.setString("produs");
	produs.setPosition(640, 15);

	//inapoi

	inapoi = produs;
	inapoi.setString("inapoi");
	inapoi.setPosition(880, 15);


	//linie separatoare

	linie.setSize(sf::Vector2f(game->window.getSize().x, 4));
	linie.setFillColor(sf::Color::White);
	linie.setPosition(0, 70);
}

void SPEState::handleInput() {
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			game->window.close();
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (isSelectedInapoi)
				isPressedInapoi = true;
			else if (isSelectedReset)
				isPressedReset = true;
			else if (isSelectedSuma)
				isPressedSuma = true;
			else if (isSelectedProdus)
				isPressedProdus = true;
			else if (isSelectedStart)
				isPressedStart = true;
		}
	}

}

void SPEState::update(double dt) {

	start.setFillColor(sf::Color::White);
	reset.setFillColor(sf::Color::White);
	suma.setFillColor(sf::Color::White);
	produs.setFillColor(sf::Color::White);
	inapoi.setFillColor(sf::Color::White);

	sf::Color selectedColor(0x0766ADFF);

	//state uri pt butoane

	isSelectedInapoi = game->isMouseOverText(inapoi);
	isSelectedProdus = game->isMouseOverText(produs);
	isSelectedReset = game->isMouseOverText(reset);
	isSelectedStart = game->isMouseOverText(start);
	isSelectedSuma = game->isMouseOverText(suma);

	if (isSelectedInapoi)
	{
		inapoi.setFillColor(selectedColor);
	}

	if (isSelectedProdus)
	{
		produs.setFillColor(selectedColor);
	}

	if (isSelectedReset)
	{
		reset.setFillColor(selectedColor);
	}

	if (isSelectedStart)
	{
		start.setFillColor(selectedColor);
	}

	if (isSelectedSuma)
	{
		suma.setFillColor(selectedColor);
	}

	if (isPressedInapoi)
	{
		isPressedInapoi = false;
		game->pushState(new VectoriMenu(game));
	}else if (isPressedReset)
	{
		isPressedReset = 0;
		vectorV.reset();
	}
	else if (isPressedSuma)
	{
		isPressedSuma = false;
		vectorV.seteazaOperatie(true);
	}
	else if (isPressedProdus)
	{
		isPressedProdus = false;
		vectorV.seteazaOperatie(false);
	}
	else if (isPressedStart)
	{
		isPressedStart = false;
		vectorV.startOperation();
	}
}

void SPEState::draw(double dt) {
	game->window.draw(start);
	game->window.draw(reset);
	game->window.draw(suma);
	game->window.draw(produs);
	game->window.draw(inapoi);
	game->window.draw(linie);
	vectorV.deseneazaVector(game);
}