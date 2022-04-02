#include "GameModel.h"
#include <algorithm>

GameModel::GameModel() : myElements(ARRAY_SIZE, 0) { Init(); }

void GameModel::Init() {
    for (uint32_t i = 0; i < ARRAY_SIZE - 1; i++) {
        myElements[i] = i + 1;
    }
    myEmptyIndex = ARRAY_SIZE - 1;
    myElements[myEmptyIndex] = 0;
    myIsSolved = true;
}

bool GameModel::Check() {
    for (uint32_t i = 0; i < ARRAY_SIZE; i++) {
        if (myElements[i] > 0 && myElements[i] != i + 1) {
            return false;
        }
    }
    return true;
}

void GameModel::Move(Direction direction) {
    uint32_t col = myEmptyIndex % SIZE;
    uint32_t row = myEmptyIndex / SIZE;

    int32_t move_index = -1;
    if (direction == Direction::Left && col < (SIZE - 1)) {
        move_index = myEmptyIndex + 1;
    } else if (direction == Direction::Right && col > 0) {
        move_index = myEmptyIndex - 1;
    } else if (direction == Direction::Up && row < (SIZE - 1)) {
        move_index = myEmptyIndex + SIZE;
    } else if (direction == Direction::Down && row > 0) {
        move_index = myEmptyIndex - SIZE;
    }

    if (myEmptyIndex >= 0 && move_index >= 0) {
        std::swap(myElements[myEmptyIndex], myElements[move_index]);
        myEmptyIndex = move_index;
    }
    myIsSolved = Check();
}

void GameModel::Reset() {
    Init();
    for (uint32_t i = 0; i < 100; i++) {
        Move((GameModel::Direction)(rand() % 4));
    }
}