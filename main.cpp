#include "Assets.h"
#include "GameModel.h"
#include "GameRender.h"
#include "GameController.h"

int main()
{
	Assets::Instance().Load();
	GameModel game;
	GameRender render(game);
	GameController controller(game, render);
	controller.Run();
	return 0;
}