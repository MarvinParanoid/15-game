#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H

#include <SFML/Graphics.hpp>

class AssetsManager
{
public:
	sf::Font font;
	AssetsManager(const AssetsManager &) = delete;
	AssetsManager &operator=(const AssetsManager &) = delete;
	static AssetsManager &Instance()
	{
		static AssetsManager instance;
		return instance;
	}
	void Load();
private:
	AssetsManager() = default;
};


#endif //ASSETSMANAGER_H
