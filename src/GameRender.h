#ifndef GAMERENDER_H
#define GAMERENDER_H

#include <SFML/Graphics.hpp>
#include "GameModel.h"

class GameRender: public sf::Drawable, public sf::Transformable
{
	GameModel &myGame;
	sf::RenderWindow myWindow;
	sf::Text myText;
public:
	explicit GameRender(GameModel &game);
	sf::RenderWindow &window()
	{
		return myWindow;
	};
	bool Init();
	void Render();
public:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //GAMERENDER_H
