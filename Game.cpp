#include "Game.h"

Game::Game()
{
	font.loadFromFile("OpenSans-Regular.ttf");
	Init();
}

void Game::Init()
{
	for (uint32_t i = 0; i < ARRAY_SIZE - 1; i++) {
		elements[i] = i + 1;
	}
	empty_index = ARRAY_SIZE - 1;
	elements[empty_index] = 0;
	solved = true;
}

bool Game::Check()
{
	for (uint32_t i = 0; i < ARRAY_SIZE; i++) {
		if (elements[i] > 0 && elements[i] != i + 1) {
			return false;
		}
	}
	return true;
}

void Game::Move(Direction direction)
{
	uint32_t col = empty_index % SIZE;
	uint32_t row = empty_index / SIZE;

	int32_t move_index = -1;
	if (direction == Direction::Left && col < (SIZE - 1)) {
		move_index = empty_index + 1;
	}
	else if (direction == Direction::Right && col > 0) {
		move_index = empty_index - 1;
	}
	else if (direction == Direction::Up && row < (SIZE - 1)) {
		move_index = empty_index + SIZE;
	}
	else if (direction == Direction::Down && row > 0) {
		move_index = empty_index - SIZE;
	}

	if (empty_index >= 0 && move_index >= 0) {
		std::swap(elements[empty_index], elements[move_index]);
		empty_index = move_index;
	}
	solved = Check();
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	sf::Color color = sf::Color(200, 100, 200);

	sf::RectangleShape shape(sf::Vector2f(FIELD_SIZE, FIELD_SIZE));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);
	target.draw(shape, states);

	shape.setSize(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);

	sf::Text text("", font, 52);

	for (uint32_t i = 0; i < ARRAY_SIZE; i++) {
		shape.setOutlineColor(color);
		text.setFillColor(color);
		text.setString(std::to_string(elements[i]));
		if (solved) {
			shape.setOutlineColor(sf::Color::Cyan);
			text.setFillColor(sf::Color::Cyan);
		}
		else if (elements[i] == i + 1) {
			text.setFillColor(sf::Color::Green);
		}

		if (elements[i] > 0) {
			sf::Vector2f position(i % SIZE * CELL_SIZE + 10.f, i / SIZE * CELL_SIZE + 10.f);
			shape.setPosition(position);
			text.setPosition(position.x + 30.f + (elements[i] < 10 ? 15.f : 0.f), position.y + 25.f);
			target.draw(shape, states);
			target.draw(text, states);
		}
	}
}

void Game::Reset()
{
	Init();
	for (uint32_t i = 0; i < 100; i++) {
		Move((Game::Direction)(rand() % 4));
	}
}