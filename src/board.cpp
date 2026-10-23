#include "board.h"
#include "colors.h"
#include "raylib.h"

void Board::Draw() {
    const float lineThick = 5.0f;

    // Draw lines
    DrawLineEx(
        {cells[0].rec.x, cells[3].rec.y + lineThick/2},
        {cells[2].rec.x + cells[2].rec.width, cells[3].rec.y + lineThick/2},
        lineThick,
        g_spriteColor
    );

    DrawLineEx(
        {cells[0].rec.x, cells[6].rec.y + lineThick/2},
        {cells[2].rec.x + cells[2].rec.width, cells[6].rec.y + lineThick/2},
        lineThick,
        g_spriteColor
    );

    // Draw columns
    DrawLineEx(
        {cells[1].rec.x + lineThick/2, cells[0].rec.y},
        {cells[1].rec.x + lineThick/2, cells[8].rec.y + cells[8].rec.height},
        lineThick,
        g_spriteColor
    );

    DrawLineEx(
        {cells[2].rec.x + lineThick/2, cells[0].rec.y},
        {cells[2].rec.x + lineThick/2, cells[8].rec.y + cells[8].rec.height},
        lineThick,
        g_spriteColor
    );

    // Draw cell
    for(auto cell : cells) {
        cell.Draw();
    }
}

void Board::Update(char symbol, uint8_t &turn) {
    if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        Vector2 mouse = GetMousePosition();
        for(auto &cell : cells) {
            if(CheckCollisionPointRec(mouse, cell.rec) && !cell.symbol) {
                turn++;
                cell.symbol = symbol;
            }
        }
    }
}
