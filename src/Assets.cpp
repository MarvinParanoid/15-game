#include "Assets.h"

void Assets::Load()
{
	if (!font.loadFromFile("resources/OpenSans-Regular.ttf")) {
		throw;
	}
}
