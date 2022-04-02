#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "GameRender.h"

class GameController
{
	GameModel &myGame;
	GameRender &myRender;
public:
	GameController(GameModel &game, GameRender &render)
		: myGame(game), myRender(render)
	{}
	void Run();
};

#endif //GAMECONTROLLER_H
