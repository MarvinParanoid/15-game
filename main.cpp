#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "15");
	window.setFramerateLimit(60);

	sf::Font font;
	font.loadFromFile("OpenSans-Regular.ttf");

	sf::Text text("F2 - New Game / Esc - Exit / Arrow Keys - Move Tile", font, 20);
	text.setFillColor(sf::Color::Cyan);
	text.setPosition(5.f, 5.f);

	Game game;
	game.setPosition(50.f, 50.f);

	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
				else if (event.key.code == sf::Keyboard::Left) {
					game.Move(Game::Direction::Left);
				}
				else if (event.key.code == sf::Keyboard::Right) {
					game.Move(Game::Direction::Right);
				}
				else if (event.key.code == sf::Keyboard::Up) {
					game.Move(Game::Direction::Up);
				}
				else if (event.key.code == sf::Keyboard::Down) {
					game.Move(Game::Direction::Down);
				}
				else if (event.key.code == sf::Keyboard::F2) {
					game.Reset();
				}
			}
		}

		window.clear();
		window.draw(game);
		window.draw(text);
		window.display();
	}

	return 0;
}