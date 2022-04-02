#include "AssetsManager.h"
#include "GameModel.h"
#include "GameRender.h"
#include "GameController.h"

int main()
{
	AssetsManager::Instance().Load();
	GameModel game;
	GameRender render(game);
	GameController controller(game, render);
	controller.Run();
	return 0;
}