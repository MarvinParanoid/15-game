#ifndef ASSETS_H
#define ASSETS_H

#include <SFML/Graphics.hpp>

class Assets
{
public:
	sf::Font font;
	Assets(const Assets &) = delete;
	Assets &operator=(const Assets &) = delete;
	static Assets &Instance()
	{
		static Assets instance;
		return instance;
	}
	void Load();
private:
	Assets() = default;
};


#endif //ASSETS_H
