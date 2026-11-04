#pragma once

#include "board.h"
#include <cstdint>

enum GameStates {
    RUNNING,
    O_WIN,
    X_WIN,
    DRAW,
};

inline int winPositions[] = {
    0b111000000,
    0b000111000,
    0b000000111,
    0b100100100,
    0b010010010,
    0b001001001,
    0b100010001,
    0b001010100,
};

class Game {
public:
    Game();
    void Run();

private:
    int playerPositions[2] = {0};
    uint8_t turn = 0;
    Board board;
    GameStates state = RUNNING;
    void Draw();
    void Update();
};
