#include "GameRender.h"
#include "AssetsManager.h"
#include <iostream>

GameRender::GameRender(GameModel &game) : myGame(game) {
    myFont = AssetsManager::Instance().GetFont("MainFont");
    Init();
}

bool GameRender::Init() {
    setPosition(50.f, 50.f);
    myWindow.create(sf::VideoMode(600, 600), "15");
    myWindow.setFramerateLimit(60);
    myText = sf::Text("F2 - New Game / Esc - Exit / Arrow Keys - Move Tile", myFont, 18);
    myText.setFillColor(sf::Color::Cyan);
    myText.setPosition(5.f, 5.f);
    return true;
}

void GameRender::Render() {
    myWindow.clear();
    myWindow.draw(*this);
    myWindow.draw(myText);
    myWindow.display();
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

    sf::Text text("", myFont, 50);

    auto &elements = myGame.Elements();
    for (uint32_t i = 0; i < GameModel::ARRAY_SIZE; i++) {
        shape.setOutlineColor(color);
        text.setFillColor(color);
        text.setString(std::to_string(elements[i]));
        if (myGame.IsSolved()) {
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