#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <cstdint>
#include <vector>

enum class Direction { Left, Right, Up, Down };

class GameModel {
  private:
    static constexpr uint32_t SIZE = 4;
    static constexpr uint32_t ARRAY_SIZE = SIZE * SIZE;

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
    static uint32_t getRow(uint32_t index) { return index / SIZE; }
    static uint32_t getColumn(uint32_t index) { return index % SIZE; }
};

#endif // GAMEMODEL_H
