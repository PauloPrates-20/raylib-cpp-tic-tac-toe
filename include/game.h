#pragma once

#include <cstdint>
#include "board.h"

enum GameStates {
    RUNNING,
    O_WIN,
    X_WIN,
    DRAW,
};

class Game {
public:
    Game();
    void Loop();
    void Draw();
    void Update();

private:
    uint8_t turn = 0;
    char symbol = 'O';
    Rectangle frame;
    Board board;
    GameStates state = RUNNING;

    void ShowTurn();
};
