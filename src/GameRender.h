#ifndef GAMERENDER_H
#define GAMERENDER_H

#include "GameModel.h"
#include <SFML/Graphics.hpp>

class GameRender : public sf::Drawable, public sf::Transformable {
  private:
    static constexpr uint32_t FIELD_SIZE = 500;
    static constexpr uint32_t CELL_SIZE = 120;
    static constexpr uint32_t HALF_CELL_SIZE = 60;
    static constexpr uint32_t SCREEN_SIZE = 600;
    static constexpr uint32_t TEXT_HINT_SIZE = 18;
    static constexpr uint32_t TEXT_BLOCK_SIZE = 50;

    GameModel &_game;
    sf::RenderWindow _window;
    sf::Font _font;
    sf::Text _text;

  public:
    explicit GameRender(GameModel &game);
    sf::RenderWindow &window() { return _window; };
    bool init();
    void render();

  public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif // GAMERENDER_H
