#include "GameController.h"

void GameController::Run() {
    sf::Event event;
    while (_render.window().isOpen()) {
        while (_render.window().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _render.window().close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    _render.window().close();
                } else if (event.key.code == sf::Keyboard::Left) {
                    _game.Move(GameModel::Direction::Left);
                } else if (event.key.code == sf::Keyboard::Right) {
                    _game.Move(GameModel::Direction::Right);
                } else if (event.key.code == sf::Keyboard::Up) {
                    _game.Move(GameModel::Direction::Up);
                } else if (event.key.code == sf::Keyboard::Down) {
                    _game.Move(GameModel::Direction::Down);
                } else if (event.key.code == sf::Keyboard::F2) {
                    _game.Reset();
                }
            }
        }
        _render.Render();
    }
}