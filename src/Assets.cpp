#include "Assets.h"

void Assets::Load()
{
	if (!font.loadFromFile("resources/RobotoMono-Regular.ttf")) {
		throw;
	}
}
