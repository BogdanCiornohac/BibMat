#include "SortareState.h"
#include "VectoriMenu.h"
#include<vector>
using namespace std;

SortareState::SortareState(Game* game)
{
	sf::Color selectedColor(0xC5E898FF);
	this->game = game;
	isPressedStart = false;
	isPressedDrop = false;
	isPressedCrescator = true;
	isPressedDescrescator = false;

	dropdownButton.setSize(sf::Vector2f(250, 40));
	dropdownButton.setPosition(25, 15);
	dropdownButton.setFillColor(selectedColor);
	

	drp1.setPosition(25, 55);
	drp2.setPosition(25, 95);
	drp3.setPosition(25, 135);
	drp4.setPosition(25, 175);
	
	//buton start

	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(1100, 85));
	triangle.setPoint(1, sf::Vector2f(1100, 135));
	triangle.setPoint(2, sf::Vector2f(1135, 110));

	//start
	sortType.setCharacterSize(28);
	sortType.setFont(game->font);
	sortType.setString("Bubble sort");
	sortType.setFillColor(sf::Color::White);
	sortType.setPosition(30, 15);

	// sortari

	bubble = sortType;
	bubble.setPosition(30, 50);

	selection = bubble;
	selection.setString("Selection Sort");
	selection.setPosition(30, 85);

	insertion = selection;
	insertion.setString("Insertion Sort");
	insertion.setPosition(30, 120);

	merge = bubble;
	merge.setString("Merge Sort");
	merge.setPosition(30, 155);

	//reset
	reset = sortType;
	reset.setString("Reset");
	reset.setPosition(320, 15);

	//crescator
	crescator = reset;
	crescator.setString("Crescator");
	crescator.setPosition(480, 15);

	//descrescator

	descrescator = reset;
	descrescator.setString("Descrescator");
	descrescator.setPosition(740, 15);

	//inapoi

	inapoi = reset;
	inapoi.setString("inapoi");
	inapoi.setPosition(1160 - inapoi.getLocalBounds().width, 15);


	//linie separatoare

	linie.setSize(sf::Vector2f(game->window.getSize().x, 4));
	linie.setFillColor(sf::Color::White);
	linie.setPosition(0, 70);
}


void SortareState::handleInput() {
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
			else if (isSelectedBubble)
				isPressedBubble = true;
			else if (isSelectedIns)
				isPressedIns = true;
			else if (isSelectedSel)
				isPressedSel = true;
			else if (isSelectedMerge)
				isPressedMerge = true;
			else if (isSelectedDrop)
				isPressedDrop = !isPressedDrop;
			else if (isSelectedStart)
				isPressedStart = !isPressedStart;
			else if (isSelectedCrescator)
			{
				isPressedCrescator = true;
				isPressedDescrescator = false;
				vectS.setCrescatorStatus(isPressedCrescator);
			}
			else if (isSelectedDescrescator)
			{
				isPressedCrescator = false;
				isPressedDescrescator = true;
				vectS.setCrescatorStatus(isPressedCrescator);
			}
		}
	}
}

void SortareState::update(double dt) {
	sortType.setFillColor(sf::Color::White);
	reset.setFillColor(sf::Color::White);
	crescator.setFillColor(sf::Color::White);
	descrescator.setFillColor(sf::Color::White);
	inapoi.setFillColor(sf::Color::White);
	triangle.setFillColor(sf::Color::White);
	bubble.setFillColor(sf::Color::White);
	selection.setFillColor(sf::Color::White);
	insertion.setFillColor(sf::Color::White);
	merge.setFillColor(sf::Color::White);

	sf::Color selectedColor(0x0766ADFF);
	sf::Color titleColor(0x29ADB2FF);

	//state uri pt butoane

	isSelectedInapoi = game->isMouseOverText(inapoi);
	isSelectedReset = game->isMouseOverText(reset);
	isSelectedStart = game->isMouseOverButton(triangle);
	isSelectedDrop = game->isMouseOverText(sortType);
	isSelectedCrescator = game->isMouseOverText(crescator) ;
	isSelectedDescrescator = game->isMouseOverText(descrescator) ;
	isSelectedBubble = game->isMouseOverText(bubble);
	isSelectedIns = game->isMouseOverText(insertion);
	isSelectedSel = game->isMouseOverText(selection);
	isSelectedMerge = game->isMouseOverText(merge);
	

	if (isSelectedInapoi)
	{
		inapoi.setFillColor(selectedColor);
	}

	if (isSelectedCrescator || isPressedCrescator)
	{
		crescator.setFillColor(titleColor);
	}

	if (isSelectedDescrescator || isPressedDescrescator)
	{
		descrescator.setFillColor(titleColor);
	}

	if (isSelectedReset)
	{
		reset.setFillColor(selectedColor);
	}

	if (isSelectedStart)
	{
		triangle.setFillColor(selectedColor);
	}

	if (isSelectedDrop)
	{
		sortType.setFillColor(selectedColor);
	}

	vector<sf::Text> text = { sortType,inapoi,reset, crescator, descrescator};
	if (isSelectedBubble)
	{
		bubble.setFillColor(selectedColor);
	}
	if (isSelectedSel)
	{
		selection.setFillColor(selectedColor);
	}
	if (isSelectedIns)
	{
		insertion.setFillColor(selectedColor);
	}
	if (isSelectedMerge)
	{
		merge.setFillColor(selectedColor);
	}
	

	if (isPressedInapoi)
	{
		isPressedInapoi = false;
		game->pushState(new VectoriMenu(game));
	}

	if (isPressedStart)
	{
		string sortOp = sortType.getString();
		if (sortOp == "Bubble sort")
		{
			vectS.bubbleSort(game, text, linie);
		}
		else if (sortOp == "Selection sort")
		{
			vectS.selectionSort(game, text, linie);
		}
		else if (sortOp == "Insertion sort")
		{
			vectS.insertionSort(game, text, linie);
		}
		else if (sortOp == "Merge sort")
		{
			vectS.mergeSort(game, text, linie, 0, 38);
		}
		isPressedStart = false;
	}

	if (isPressedReset)
	{
		isPressedReset = false;
		vectS.reset();
	}

	if (isPressedBubble)
	{
		sortType.setString("Bubble sort");
		isPressedBubble = false;
		isPressedDrop = false;
	}

	if (isPressedIns)
	{
		sortType.setString("Insertion sort");
		isPressedIns = false;
		isPressedDrop = false;
	}
	if (isPressedSel)
	{
		sortType.setString("Selection sort");
		isPressedSel = false;
		isPressedDrop = false;
	}
	if (isPressedMerge)
	{
		sortType.setString("Merge sort");
		isPressedMerge = false;
		isPressedDrop = false;
	}


}

void SortareState::draw(double dt) {
	game->window.draw(linie);
	game->window.draw(triangle);
	game->window.draw(dropdownButton);
	game->window.draw(sortType);
	if (isPressedDrop)
	{
		vectS.resetComp();
		dropdownButton.setSize(sf::Vector2f(273, 180));
		game->window.draw(bubble);
		game->window.draw(selection);
		game->window.draw(insertion);
		game->window.draw(merge);
	}
	else {
		dropdownButton.setSize(sf::Vector2f(273, 40));
	}
	game->window.draw(reset);
	game->window.draw(inapoi);
	game->window.draw(crescator);
	game->window.draw(descrescator);
	vectS.deseneazaVector(game);
}