#include"SPVector.h"
#include <random>
#include <ctime>
#include<iostream>
using namespace std;

SPVector::SPVector() {
	srand(static_cast<unsigned int>(time(0)));
	vectorSize = 16;
	inaltime = 70;
	start = false;
	isSum = true;

	for (int i = 0; i < vectorSize; i++)
	{
		v[i] = rand() % 100 + 1;
	}

	operatie.setCharacterSize(30);
	operatie.setString("Suma elementelor: ");
	blinkingCellIndex = 0;
	suma = 0;
	
}

void SPVector::deseneazaVector(Game *game) {
	int linie = 0;

	sf::Color contur(0xC5E898);
	sf::Color numberColor(0x0766ADFF);

	for (int i = 0; i < vectorSize; i++) {
		sf::RectangleShape patrat(sf::Vector2f(inaltime, inaltime));

		//text
		operatie.setFont(game->font);
		operatie.setPosition(40, 320);
		operatie.setFillColor(numberColor);

		sf::Text rez;

		rez = operatie;
		rez.setString(std::to_string(suma));
		rez.setPosition(operatie.getLocalBounds().width + 40, 320);
		game->window.draw(rez);
		game->window.draw(operatie);

		//creem patrat
		if (i * inaltime > game->window.getSize().x)
			linie += inaltime;
		patrat.setPosition(i * inaltime + 40, 200 + linie);
		patrat.setFillColor(sf::Color::Transparent);
		patrat.setOutlineColor(contur);
		patrat.setOutlineThickness(2.0f);

		if (start)
		{
			if (i == blinkingCellIndex)
			{
				patrat.setFillColor(sf::Color::White); // Empty text for blinking effect
			}
			else
			{
				patrat.setFillColor(sf::Color::Transparent);
			}
		}

		//text

		sf::Text text;
		text.setFont(game->font);
		text.setString(to_string(v[i]));
		text.setCharacterSize(inaltime / 2);
		text.setFillColor(numberColor);
		sf::FloatRect textBounds = text.getLocalBounds();
		text.setPosition(patrat.getPosition().x + (inaltime - textBounds.width) / 2,
			patrat.getPosition().y + (inaltime - textBounds.height) / 4);

		game->window.draw(patrat);
		game->window.draw(text);


	}

	if (start)
	{
		if (blinkTimer.getElapsedTime().asMilliseconds() > 500)  // Adjust the delay duration
		{
			blinkTimer.restart();
			if (isSum) {
				suma += v[blinkingCellIndex];
			}
			else {
				suma *= v[blinkingCellIndex];
			}
			blinkingCellIndex = blinkingCellIndex + 1;
			if (blinkingCellIndex > vectorSize)
				stopOperation();
		}
	}
}

void SPVector::reset()
{
	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < vectorSize; i++)
	{
		v[i] = rand() % 100 + 1;
	}

	blinkingCellIndex = 0;
	suma = 0;

}

void SPVector::seteazaOperatie(bool status) {
	isSum = status;
	if(status)
		operatie.setString("Suma elementelor: ");
	else
		operatie.setString("Produsul elementelor: ");
}

void SPVector::startOperation() {
	start = true;
}

void SPVector::stopOperation() {
	start = false;
}

