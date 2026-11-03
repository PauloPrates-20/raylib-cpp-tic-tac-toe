#pragma once

#include "board.h"
#include <cstdint>

enum GameStates {
    RUNNING,
    O_WIN,
    X_WIN,
    DRAW,
};

class Game {
public:
    Game();
    void Run();

private:
    uint8_t turn = 0;
    Board board;
    GameStates state = RUNNING;
    void Draw();
    void Update();
};
