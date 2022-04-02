#include "AssetsManager.h"

void AssetsManager::Load()
{
	if (!font.loadFromFile("resources/RobotoMono-Regular.ttf")) {
		throw;
	}
}
