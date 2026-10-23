#pragma once

#include "raylib.h"

class Cell {
public:
    Cell(float x, float y, char symbol = '\0');
    void Draw();

    char symbol;
    Vector2 pos;
    Rectangle rec;
};
