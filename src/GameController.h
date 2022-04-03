#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "GameRender.h"

class GameController {
    GameModel &_game;
    GameRender &_render;

  public:
    GameController(GameModel &game, GameRender &render) : _game(game), _render(render) {}
    void run();
};

#endif // GAMECONTROLLER_H
