#include "MatriciMenu.h"
#include"../MenuState.h"


MatriciMenu::MatriciMenu(Game* game)
{
	this->game = game;
	this->isSelectedASII = true;

	sf::Color titleColor(0x29ADB2FF);
	sf::Color selectedColor(0x0766ADFF);

	titlu.setFont(this->game->font);
	titlu.setString("Operatii pe Matrici");
	titlu.setFillColor(titleColor);
	titlu.setCharacterSize(80);

	titlu.setOrigin(titlu.getLocalBounds().width / 2,
		titlu.getLocalBounds().height / 2);

	titlu.setPosition(this->game->window.getSize().x / 2,
		40);

	// Adunare si celelalte

	adScInmImp.setFont(this->game->font);
	adScInmImp.setString("Adunarea/Scaderea/Inmultirea/Impartirea elementelor");
	adScInmImp.setFillColor(selectedColor);
	adScInmImp.setCharacterSize(25);
	adScInmImp.setOrigin(adScInmImp.getLocalBounds().width / 2,
		adScInmImp.getLocalBounds().height / 2);

	adScInmImp.setPosition(this->game->window.getSize().x / 2,
		this->game->window.getSize().y / 2 - 75);

	//transpusa sau inversul 

	transpusaInverMat = adScInmImp;

	transpusaInverMat.setString("Transpusa / Inversul unei Matrici");

	transpusaInverMat.setOrigin(transpusaInverMat.getLocalBounds().width / 2,
		transpusaInverMat.getLocalBounds().height / 2);

	transpusaInverMat.setPosition(this->game->window.getSize().x / 2,
		this->game->window.getSize().y / 2 - 25);

	//Operatii pe mat

	operatiiMatrice = transpusaInverMat;

	operatiiMatrice.setString("Operatii pe Matrici");

	operatiiMatrice.setOrigin(operatiiMatrice.getLocalBounds().width / 2,
		operatiiMatrice.getLocalBounds().height / 2);

	operatiiMatrice.setPosition(this->game->window.getSize().x / 2,
		this->game->window.getSize().y / 2 + 25);

	//inapoi
	inapoi = operatiiMatrice;

	inapoi.setString("inapoi");

	inapoi.setOrigin(inapoi.getLocalBounds().width / 2,
		inapoi.getLocalBounds().height / 2);

	inapoi.setPosition(this->game->window.getSize().x / 2,
		this->game->window.getSize().y / 2 + 75);

}

void MatriciMenu::handleInput()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			game->window.close();

		if (event.type == sf::Event::KeyPressed) {

			if (event.key.code == sf::Keyboard::Enter)
			{
				if (isSelectedASII)
				{
					isPressedASII = true;
				}
				else if (isSelectedTIM)
				{
					isPressedTIM = true;
				}
				else if (isSelectedOM)
				{
					isPressedOM = true;
				}
				else
				{
					isPressedInapoi = true;
				}

			}

			else if (event.key.code == sf::Keyboard::Down && isSelectedASII)
			{
				isSelectedASII = false;
				isSelectedTIM = true;
				isSelectedOM = false;
				isSeLectedInapoi = false;
			}

			else if (event.key.code == sf::Keyboard::Down && isSelectedTIM)
			{
				isSelectedASII = false;
				isSelectedTIM = false;
				isSelectedOM = true;
				isSeLectedInapoi = false;
			}

			else if (event.key.code == sf::Keyboard::Down && isSelectedOM)
			{
				isSelectedASII = false;
				isSelectedTIM = false;
				isSelectedOM = false;
				isSeLectedInapoi = true;
			}
			else if (event.key.code == sf::Keyboard::Up && isSeLectedInapoi)
			{
				isSelectedASII = false;
				isSelectedTIM = false;
				isSelectedOM = true;
				isSeLectedInapoi = false;
			}
			else if (event.key.code == sf::Keyboard::Up && isSelectedOM)
			{
				isSelectedASII = false;
				isSelectedTIM = true;
				isSelectedOM = false;
				isSeLectedInapoi = false;
			}
			else {
				isSelectedASII = true;
				isSelectedTIM = false;
				isSelectedOM = false;
				isSeLectedInapoi = false;
			}
		}
	}

}

void MatriciMenu::update(double dt)
{
	adScInmImp.setFillColor(sf::Color::White);
	transpusaInverMat.setFillColor(sf::Color::White);
	operatiiMatrice.setFillColor(sf::Color::White);
	inapoi.setFillColor(sf::Color::White);

	sf::Color selectedColor(0x0766ADFF);

	if (isSelectedASII)
	{
		adScInmImp.setFillColor(selectedColor);
		
	}
	

	if (isSelectedTIM)
	{
		transpusaInverMat.setFillColor(selectedColor);
	}
	

	if (isSelectedOM)
	{
		operatiiMatrice.setFillColor(selectedColor);
	}
	

	if (isSeLectedInapoi) {
		inapoi.setFillColor(selectedColor);
		
	}
	

	if (isPressedASII)
	{

	}
	else if (isPressedTIM) {

	}
	else if (isPressedOM) {

	}
	else if (isPressedInapoi)
	{
		isPressedInapoi = false;
		game->pushState(new menuState(game));
	}
}

void MatriciMenu::draw(double dt)
{
	game->window.draw(titlu);
	game->window.draw(adScInmImp);
	game->window.draw(transpusaInverMat);
	game->window.draw(operatiiMatrice);
	game->window.draw(inapoi);
}