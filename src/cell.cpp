#include "cell.h"
#include "colors.h"
#include "config.h"
#include "raylib.h"

bool Cell::IsEmpty() {
    return !symbol;
}

void Cell::PutChar(char c) {
    symbol = c;
}

Vector2 Cell::GetPos() {
    return Vector2{x, y};
}

void Cell::Draw() {
    const char text[] = {symbol, '\0'};
    const float fontSize = g_gridSize * 0.8f;
    const float spacing = 1.0f;

    const Vector2 textSize = MeasureTextEx(GetFontDefault(), text, fontSize, spacing);

    const float _x = x*g_gridSize + (g_gridSize - textSize.x)/2;
    const float _y = y*g_gridSize + (g_gridSize - textSize.y)/2;

    DrawTextEx(GetFontDefault(), text ,{_x, _y}, fontSize, spacing, g_spriteColor);
}
