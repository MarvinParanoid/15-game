#include "Game.h"
#include "AssetsManager.h"
#include "GameController.h"
#include "GameModel.h"
#include "GameRender.h"

void Game::run() {
    AssetsManager::instance().loadFont("MainFont", "resources/RobotoMono-Regular.ttf");
    GameModel model;
    GameRender render(model);
    GameController controller(model, render);
    controller.run();
}
