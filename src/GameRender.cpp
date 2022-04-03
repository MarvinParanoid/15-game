#include "GameRender.h"
#include "AssetsManager.h"
#include <iostream>

GameRender::GameRender(GameModel &game) : _game(game) {
    _font = AssetsManager::instance().getFont("MainFont");
    init();
}

bool GameRender::init() {
    setPosition(50.f, 50.f);
    _window.create(sf::VideoMode(GameModel::SCREEN_SIZE, GameModel::SCREEN_SIZE), "15");
    _window.setFramerateLimit(60);
    _text = sf::Text("F2 - New Game / Esc - Exit / Arrow Keys - move Tile", _font, 18);
    _text.setFillColor(sf::Color::Cyan);
    _text.setPosition(5.f, 5.f);
    return true;
}

void GameRender::render() {
    _window.clear();
    _window.draw(*this);
    _window.draw(_text);
    _window.display();
}

void GameRender::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    sf::Color color = sf::Color(200, 100, 200);

    sf::RectangleShape shape(sf::Vector2f(GameModel::FIELD_SIZE, GameModel::FIELD_SIZE));
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(color);
    shape.setFillColor(sf::Color::Transparent);
    target.draw(shape, states);

    shape.setSize(sf::Vector2f(GameModel::CELL_SIZE - 2, GameModel::CELL_SIZE - 2));
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(color);
    shape.setFillColor(sf::Color::Transparent);

    sf::Text text("", _font, 50);

    auto &elements = _game.elements();
    for (uint32_t i = 0; i < GameModel::ARRAY_SIZE; i++) {
        shape.setOutlineColor(color);
        text.setFillColor(color);
        text.setString(std::to_string(elements[i]));
        if (_game.isSolved()) {
            shape.setOutlineColor(sf::Color::Cyan);
            text.setFillColor(sf::Color::Cyan);
        } else if (elements[i] == i + 1) {
            text.setFillColor(sf::Color::Green);
        }

        if (elements[i] > 0) {
            sf::Vector2f position(i % GameModel::SIZE * GameModel::CELL_SIZE + 10.f, i / GameModel::SIZE * GameModel::CELL_SIZE + 10.f);
            shape.setPosition(position);
            sf::FloatRect textRect = text.getLocalBounds();
            text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
            text.setPosition(position.x + GameModel::HALF_CELL_SIZE, position.y + GameModel::HALF_CELL_SIZE);
            target.draw(shape, states);
            target.draw(text, states);
        }
    }
}