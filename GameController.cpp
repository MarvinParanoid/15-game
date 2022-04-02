#include "GameController.h"

void GameController::Run()
{
	sf::Event event;
	while (myRender.window().isOpen()) {
		while (myRender.window().pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				myRender.window().close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					myRender.window().close();
				}
				else if (event.key.code == sf::Keyboard::Left) {
					myGame.Move(GameModel::Direction::Left);
				}
				else if (event.key.code == sf::Keyboard::Right) {
					myGame.Move(GameModel::Direction::Right);
				}
				else if (event.key.code == sf::Keyboard::Up) {
					myGame.Move(GameModel::Direction::Up);
				}
				else if (event.key.code == sf::Keyboard::Down) {
					myGame.Move(GameModel::Direction::Down);
				}
				else if (event.key.code == sf::Keyboard::F2) {
					myGame.Reset();
				}
			}
		}
		myRender.Render();
	}
}