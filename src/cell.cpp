#include "cell.h"

#include "colors.h"
#include "config.h"
#include "raylib.h"

Cell::Cell(float x, float y, char _symbol) : pos(Vector2{x, y}), symbol(_symbol), rec(Rectangle{x*g_cellSize, y*g_cellSize, g_cellSize, g_cellSize}) {}

void Cell::Draw() {
    const char text[] = {symbol, '\0'};
    const float fontSize = g_cellSize * 0.8f;
    const float spacing = 1.0f;
    
    const Vector2 textSize = MeasureTextEx(GetFontDefault(), text, fontSize, spacing);

    const float x = rec.x + (rec.width - textSize.x)/2;
    const float y = rec.y + (rec.height - textSize.y)/2;

    if(symbol) {
        DrawTextEx(GetFontDefault(), text, {x, y}, fontSize, spacing, g_spriteColor);
    }
}
