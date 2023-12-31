#include "Game.h"
#include "State.h"
#include "menuState.h"



Game::Game() {
	window.create(sf::VideoMode(1200, 800), "BibMat");
	window.setFramerateLimit(60);
	sf::Color windowColor(0xF3F3F3);
	window.clear(windowColor);

	font.loadFromFile("fonts/Silkscreen-Regular.ttf");
	
}

void Game::pushState(State* state) {
	states.push(state);
}

void Game::popState() {
	if (!states.empty())
		states.pop();
}

void Game::changeState(State* state) {
	if (!states.empty())
		states.pop();

	pushState(state);
}

State* Game::getState() {
	if (!states.empty())
		return states.top();
	return NULL;
}

void Game::gameLoop() {
	sf::Clock clock;

	while (window.isOpen()) {
		sf::Time elapsed = clock.restart();

		double dt = elapsed.asSeconds();

		if (getState() == NULL) {
			continue;
		}

		getState()->handleInput();
		getState()->update(dt);

		window.clear(sf::Color(161, 161, 161));

		getState()->draw(dt);

		window.display();
	}
}

bool Game::isMouseOverText(const sf::Text& text) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	return text.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}

bool Game::isMouseOverButton(const sf::ConvexShape& shape) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	return shape.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}
