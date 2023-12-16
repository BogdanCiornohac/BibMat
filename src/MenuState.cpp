#include "menuState.h"
#include "Vectori/VectoriMenu.h"
#include"Matrici//MatriciMenu.h"


menuState::menuState(Game* game) {
	this->game = game;
	this->isSelectedPlay = true;

	sf::Color titleColor(0x29ADB2FF);
	sf::Color selectedColor(0x0766ADFF);

	titlu.setFont(this->game->font);
	titlu.setString("BibMat");
	titlu.setFillColor(titleColor);
	titlu.setCharacterSize(200);


	titlu.setOrigin(titlu.getLocalBounds().width / 2,
		titlu.getLocalBounds().height / 2);
	

	titlu.setPosition(this->game->window.getSize().x / 2,
		40);

	matriciText.setFont(this->game->font);
	matriciText.setString("Operatii pe Matrici");
	matriciText.setFillColor(selectedColor);
	matriciText.setCharacterSize(40);

	matriciText.setOrigin(matriciText.getLocalBounds().width / 2,
		matriciText.getLocalBounds().height / 2);

	matriciText.setPosition(this->game->window.getSize().x / 2,
		this->game->window.getSize().y / 2 - 25);

	vectoriText = matriciText;
	vectoriText.setOrigin(vectoriText.getLocalBounds().width / 2,
		vectoriText.getLocalBounds().height / 2);

	vectoriText.setPosition(this->game->window.getSize().x / 2 ,
		this->game->window.getSize().y / 2 + 25);

	vectoriText.setString("Operatii pe Vectori");

	inchideText = matriciText;
	inchideText.setOrigin(inchideText.getLocalBounds().width / 2,
		inchideText.getLocalBounds().height / 2);

	inchideText.setPosition(this->game->window.getSize().x / 2 +3,
		this->game->window.getSize().y / 2 + 75);

	inchideText.setString("Inchide");
}




void menuState::handleInput() {
	sf::Event event;

	while (game->window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			game->window.close();

		if (event.type == sf::Event::MouseButtonPressed) {
			
				if (isSelectedPlay)
					isPressedPlay = true;
				else if (isSelectedVectori)
					isPressedVectori = true;
				else if(isSelectedExit) isPressedExit = true;	
		}

		break;
	}
}

void menuState::update(double dt) {
	matriciText.setFillColor(sf::Color::White);
	inchideText.setFillColor(sf::Color::White);
	vectoriText.setFillColor(sf::Color::White);


	isSelectedPlay = game->isMouseOverText(matriciText);
	isSelectedVectori = game->isMouseOverText(vectoriText);
	isSelectedExit = game->isMouseOverText(inchideText);

	sf::Color titleColor(0x29ADB2FF);
	sf::Color selectedColor(0x0766ADFF);

	if (isSelectedPlay) {
		matriciText.setFillColor(selectedColor);
		matriciText.setCharacterSize(47);
	}
	else {
		matriciText.setCharacterSize(40);
	}

	if (isSelectedVectori) {
		vectoriText.setFillColor(selectedColor);
		vectoriText.setCharacterSize(47);
	}
	else {
		vectoriText.setCharacterSize(40);
	}


	if (isSelectedExit) {
		inchideText.setFillColor(selectedColor);
		inchideText.setCharacterSize(47);
	}
	else {
		inchideText.setCharacterSize(40);
	}

	if (isPressedPlay) {
		isPressedPlay = 0;
		game->pushState(new MatriciMenu(game));
	}
	if (isPressedVectori)
	{
		isPressedVectori = 0;
		game->pushState(new VectoriMenu(game));
	}
	if (isPressedExit)
		game->window.close();
}

void menuState::draw(double dt) {
	game->window.draw(titlu);
	game->window.draw(matriciText);
	game->window.draw(vectoriText);
	game->window.draw(inchideText);
}