#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>

class AssetsManager
{
public:
	AssetsManager(const AssetsManager &) = delete;
	AssetsManager &operator=(const AssetsManager &) = delete;
	static AssetsManager &Instance()
	{
		static AssetsManager instance;
		return instance;
	}
	void LoadFont(const std::string &name, const std::string &filename);
	sf::Font &GetFont(const std::string &name);
private:
	AssetsManager() = default;
	std::unordered_map<std::string, sf::Font> _fonts;
};


#endif //ASSETSMANAGER_H
