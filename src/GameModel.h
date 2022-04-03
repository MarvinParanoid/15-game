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
    static constexpr uint32_t SCREEN_SIZE = 600;
    enum class Direction { Left, Right, Up, Down };

  protected:
    std::vector<uint32_t> _elements;
    int32_t _emptyIndex;
    bool _isSolved;

  public:
    GameModel();
    void init();
    bool check();
    void move(Direction direction);
    void reset();
    const std::vector<uint32_t> &elements() const { return _elements; }
    bool isSolved() const { return _isSolved; }
};

#endif // GAMEMODEL_H
