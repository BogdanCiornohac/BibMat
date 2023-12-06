#include <SFML/Graphics.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Green Circle");

    // Create a green circle
    sf::CircleShape greenCircle(50); // radius of 50 pixels
    greenCircle.setFillColor(sf::Color::Green);
    greenCircle.setPosition(375, 275); // position the circle at the center of the window

    // Main loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw the green circle
        window.draw(greenCircle);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
