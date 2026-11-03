#include "board.h"
#include "colors.h"
#include "config.h"
#include "raylib.h"
#include <cstdlib>
#include <cmath>
#include <cstdio>

int Board::GetCellIdx(float x, float y) {
    Vector2 pos{floorf(x/g_gridSize), floorf(y/g_gridSize)};

    // printf("Mouse X: %.0f, Y: %.0f\n", pos.x, pos.y);
    for(size_t i = 0; i < 9; i++) {
        Vector2 cellPos = cells[i].GetPos();

        if(pos.x == cellPos.x && pos.y == cellPos.y) {
            // printf("match: %ld\n", i);
            return i;
        }  
    }

    return -1;
}

bool Board::IsCellEmpty(int idx) {
    if(idx < 0 || idx >= 9) {
        return false;
    }

    return cells[idx].IsEmpty();
    // printf("Cell %d empty\n", idx);
}

bool Board::PutChar(char c, int idx) {
    if(!IsCellEmpty(idx)) {
        return false;
    }

    // printf("Put char %c in cell %d\n", c, idx);
    cells[idx].PutChar(c);

    return true;
}

void Board::Draw() {
    const float lineThick = 5.0f;
    
    Vector2 start = cells[1].GetPos();
    Vector2 end = cells[7].GetPos();
    start = {start.x*g_gridSize, start.y*g_gridSize};
    end = {end.x*g_gridSize + g_gridSize, end.y*g_gridSize};
    start.y += lineThick/2;
    end.y += lineThick/2;

    // Lines
    DrawLineEx(start, end, lineThick, g_spriteColor);


    start = cells[2].GetPos();
    end = cells[8].GetPos();
    start = {start.x*g_gridSize, start.y*g_gridSize};
    end = {end.x*g_gridSize + g_gridSize, end.y*g_gridSize};
    start.y += lineThick/2;
    end.y += lineThick/2;

    DrawLineEx(start, end, lineThick, g_spriteColor);

    start = cells[3].GetPos();
    end = cells[5].GetPos();
    start = {start.x*g_gridSize, start.y*g_gridSize};
    end = {end.x*g_gridSize, end.y*g_gridSize + g_gridSize};
    start.x += lineThick/2;
    end.x += lineThick/2;

    DrawLineEx(start, end, lineThick, g_spriteColor);

    start = cells[6].GetPos();
    end = cells[8].GetPos();
    start = {start.x*g_gridSize, start.y*g_gridSize};
    end = {end.x*g_gridSize, end.y*g_gridSize + g_gridSize};
    start.x += lineThick/2;
    end.x += lineThick/2;

    DrawLineEx(start, end, lineThick, g_spriteColor);

    for(auto cell : cells) {
        cell.Draw();
    }
}
