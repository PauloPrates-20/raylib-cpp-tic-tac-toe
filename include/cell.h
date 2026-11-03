#pragma once

#include "raylib.h"

class Cell {
public:
    Cell(float _x, float _y) : x(_x), y(_y) {}
    bool IsEmpty();
    void PutChar(char symbol);
    Vector2 GetPos();
    void Draw();

private:
    float x, y;
    char symbol = '\0';
};
