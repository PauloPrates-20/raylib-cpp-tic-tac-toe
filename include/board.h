#pragma once

#include "cell.h"
#include <cstdint>

class Board {
public:
    Board() {}
    void Draw();
    void Update(char symbol, uint8_t &turn);

private:
    Cell cells[9] = {
        Cell(2, 2), Cell(3, 2), Cell(4, 2),
        Cell(2, 3), Cell(3, 3), Cell(4, 3),
        Cell(2, 4), Cell(3, 4), Cell(4, 4),
    };
};
