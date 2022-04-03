#ifndef GAMERENDER_H
#define GAMERENDER_H

#include "GameModel.h"
#include <SFML/Graphics.hpp>

class GameRender : public sf::Drawable, public sf::Transformable {
    GameModel &_game;
    sf::RenderWindow _window;
    sf::Font _font;
    sf::Text _text;

  public:
    explicit GameRender(GameModel &game);
    sf::RenderWindow &window() { return _window; };
    bool Init();
    void Render();

  public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif // GAMERENDER_H
