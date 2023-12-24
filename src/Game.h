#pragma once
#include <stack>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>

class State;

class Game
{
private:
	std::stack<State*> states;
	
public:
	sf::Font font;
	sf::RenderWindow window;

	Game();
	void pushState(State*);
	void popState();
	void changeState(State*);
	State* getState();

	void gameLoop();
	bool isMouseOverText(const sf::Text& text);
	bool isMouseOverButton(const sf::ConvexShape& shape);
};
