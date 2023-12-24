#include"ISState.h"
#include "VectoriMenu.h"
#include <string>
using namespace std;

ISState::ISState(Game* game) {
	this->game = game;

	//start
	start.setCharacterSize(40);
	start.setFont(game->font);
	start.setString("Incepe");
	start.setFillColor(sf::Color::White);
	start.setPosition(30, 15);

	// reset

	reset = start;
	reset.setString("Reset");
	reset.setPosition(320, 15);
	
	//Scalar

	scalar = reset;
	scalar.setString("Adauga scalar");
	scalar.setPosition(560, 15);

	//inapoi

	inapoi = reset;
	inapoi.setString("inapoi");
	inapoi.setPosition(1160 - inapoi.getLocalBounds().width, 15);


	//linie separatoare

	linie.setSize(sf::Vector2f(game->window.getSize().x, 4));
	linie.setFillColor(sf::Color::White);
	linie.setPosition(0, 70);
}

void ISState::handleInput() {
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
			else if (isSelectedStart)
				isPressedStart = true;
			else if (isSelectedScalar)
				isPressedScalar = true;
		}
		else if (event.type == sf::Event::TextEntered && isSelectedScalar) {
			sf::Text inputText;
			inputText.setString(to_string(vectorV.getScalar()));
			if (event.text.unicode < 128) {
				if (isdigit(static_cast<char>(event.text.unicode))) {
					inputText.setString(inputText.getString() + static_cast<char>(event.text.unicode));
				}
				else if (event.text.unicode == 8) { // Backspace
					string currentText = inputText.getString();
					int currentNum = stoi(currentText);
					if (currentNum < 10) {
						inputText.setString("0");
					}else if (!currentText.empty()) {
						currentText.pop_back();
						inputText.setString(currentText);
					}
				}
				string num = inputText.getString();
				vectorV.setScalar(stoi(num));
			}
		}
		else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Enter) {
				isPressedScalar = false;
			}
		}
	}

}

void ISState::update(double dt) {

	start.setFillColor(sf::Color::White);
	reset.setFillColor(sf::Color::White);
	scalar.setFillColor(sf::Color::White);
	inapoi.setFillColor(sf::Color::White);

	sf::Color selectedColor(0x0766ADFF);

	//state uri pt butoane

	isSelectedInapoi = game->isMouseOverText(inapoi);
	isSelectedReset = game->isMouseOverText(reset);
	isSelectedStart = game->isMouseOverText(start);
	isSelectedScalar = game->isMouseOverText(scalar) || isPressedScalar;

	if (isSelectedInapoi)
	{
		inapoi.setFillColor(selectedColor);
	}

	if (isSelectedScalar)
	{
		scalar.setFillColor(selectedColor);
	}

	if (isSelectedReset)
	{
		reset.setFillColor(selectedColor);
	}

	if (isSelectedStart)
	{
		start.setFillColor(selectedColor);
	}



	if (isPressedInapoi)
	{
		isPressedInapoi = false;
		game->pushState(new VectoriMenu(game));
	}

	if (isPressedStart)
	{
		isPressedStart = false;
		vectorV.startOperation();
	}

	if (isPressedReset)
	{
		isPressedReset = false;
		vectorV.reset();
	}


}

void ISState::draw(double dt) {
	game->window.draw(start);
	game->window.draw(reset);
	game->window.draw(inapoi);
	game->window.draw(linie);
	game->window.draw(scalar);
	vectorV.deseneazaInmScalar(game);
}