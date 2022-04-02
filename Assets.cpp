#include "Assets.h"

void Assets::Load()
{
	if (!font.loadFromFile("OpenSans-Regular.ttf")) {
		throw;
	}
}
