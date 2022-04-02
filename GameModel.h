#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <cstdint>

class GameModel
{
public:
	static constexpr uint32_t SIZE = 4;
	static constexpr uint32_t ARRAY_SIZE = SIZE * SIZE;
	static constexpr uint32_t FIELD_SIZE = 500;
	static constexpr uint32_t CELL_SIZE = 120;
	enum class Direction
	{
		Left, Right, Up, Down
	};
protected:
	int32_t myElements[ARRAY_SIZE];
	int32_t myEmptyIndex;
	bool myIsSolved;
public:
	GameModel();
	void Init();
	bool Check();
	void Move(Direction direction);
	void Reset();
	int32_t *Elements()
	{
		return myElements;
	}
	bool IsSolved() const
	{
		return myIsSolved;
	}
};

#endif //GAMEMODEL_H
