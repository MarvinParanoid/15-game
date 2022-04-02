#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <cstdint>
#include <vector>

class GameModel {
  public:
    static constexpr uint32_t SIZE = 4;
    static constexpr uint32_t ARRAY_SIZE = SIZE * SIZE;
    static constexpr uint32_t FIELD_SIZE = 500;
    static constexpr uint32_t CELL_SIZE = 120;
    static constexpr uint32_t HALF_CELL_SIZE = 60;
    enum class Direction { Left, Right, Up, Down };

  protected:
    std::vector<uint32_t> myElements;
    int32_t myEmptyIndex;
    bool myIsSolved;

  public:
    GameModel();
    void Init();
    bool Check();
    void Move(Direction direction);
    void Reset();
    const std::vector<uint32_t> &Elements() const { return myElements; }
    bool IsSolved() const { return myIsSolved; }
};

#endif // GAMEMODEL_H
