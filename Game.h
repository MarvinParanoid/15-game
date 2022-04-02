#ifndef INC_15_GAME_H
#define INC_15_GAME_H

#include <SFML/Graphics.hpp>

class Game: public sf::Drawable, public sf::Transformable
{
	static constexpr uint32_t SIZE = 4;
	static constexpr uint32_t ARRAY_SIZE = SIZE * SIZE;
	static constexpr uint32_t FIELD_SIZE = 500;
	static constexpr uint32_t CELL_SIZE = 120;
protected:
	int32_t elements[ARRAY_SIZE];
	int32_t empty_index;
	bool solved;
	sf::Font font;
public:
	enum class Direction
	{
		Left, Right, Up, Down
	};
	Game();
	void Init();
	bool Check();
	void Move(Direction direction);
	void Reset();
public:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //INC_15_GAME_H
