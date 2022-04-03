#include "GameModel.h"
#include <algorithm>

GameModel::GameModel() : _elements(ARRAY_SIZE, 0) { Init(); }

void GameModel::Init() {
    for (uint32_t i = 0; i < ARRAY_SIZE - 1; i++) {
        _elements[i] = i + 1;
    }
    _emptyIndex = ARRAY_SIZE - 1;
    _elements[_emptyIndex] = 0;
    _isSolved = true;
}

bool GameModel::Check() {
    for (uint32_t i = 0; i < ARRAY_SIZE; i++) {
        if (_elements[i] > 0 && _elements[i] != i + 1) {
            return false;
        }
    }
    return true;
}

void GameModel::Move(Direction direction) {
    uint32_t col = _emptyIndex % SIZE;
    uint32_t row = _emptyIndex / SIZE;

    int32_t move_index = -1;
    if (direction == Direction::Left && col < (SIZE - 1)) {
        move_index = _emptyIndex + 1;
    } else if (direction == Direction::Right && col > 0) {
        move_index = _emptyIndex - 1;
    } else if (direction == Direction::Up && row < (SIZE - 1)) {
        move_index = _emptyIndex + SIZE;
    } else if (direction == Direction::Down && row > 0) {
        move_index = _emptyIndex - SIZE;
    }

    if (_emptyIndex >= 0 && move_index >= 0) {
        std::swap(_elements[_emptyIndex], _elements[move_index]);
        _emptyIndex = move_index;
    }
    _isSolved = Check();
}

void GameModel::Reset() {
    Init();
    for (uint32_t i = 0; i < 100; i++) {
        Move((GameModel::Direction)(rand() % 4));
    }
}