#include "AssetsManager.h"
#include "GameController.h"
#include "GameModel.h"
#include "GameRender.h"

int main() {
    AssetsManager::Instance().LoadFont("MainFont", "resources/RobotoMono-Regular.ttf");
    GameModel game;
    GameRender render(game);
    GameController controller(game, render);
    controller.Run();
    return 0;
}