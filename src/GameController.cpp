#include "GameController.h"

void GameController::run() {
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
                    _game.move(Direction::Left);
                } else if (event.key.code == sf::Keyboard::Right) {
                    _game.move(Direction::Right);
                } else if (event.key.code == sf::Keyboard::Up) {
                    _game.move(Direction::Up);
                } else if (event.key.code == sf::Keyboard::Down) {
                    _game.move(Direction::Down);
                } else if (event.key.code == sf::Keyboard::F2) {
                    _game.reset();
                }
            }
        }
        _render.render();
    }
}