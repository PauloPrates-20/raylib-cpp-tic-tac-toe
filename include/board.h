#pragma once

#include "cell.h"

class Board {
public:
    Board() {};
    int GetCellIdx(float x, float y);
    bool IsCellEmpty(int idx);
    bool PutChar(char c, int idx);
    void Draw();

private:
    Cell cells[9] = {
        Cell(2, 2), Cell(2, 3), Cell(2, 4),
        Cell(3, 2), Cell(3, 3), Cell(3, 4),
        Cell(4, 2), Cell(4, 3), Cell(4, 4),
    };
};
