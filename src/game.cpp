#include "game.h"
#include "config.h"
#include "raylib.h"
#include "colors.h"

Game::Game() {
    const float lineThick = 5.0f;
    frame = Rectangle{1*g_cellSize/2 + lineThick/2, 1*g_cellSize/2 + lineThick/2, (g_cellCount - 1)*g_cellSize - lineThick/2, (g_cellCount - 1)*g_cellSize - lineThick/2};
    InitWindow(g_wWidth, g_wHeight, g_wTitle);
    SetTargetFPS(60);

    Loop();

    CloseWindow();
}

void Game::Loop() {
    while(!WindowShouldClose()) {
        Draw();
        if(state == RUNNING) {
            Update();
        }
    }
}

void Game::Draw() {
    BeginDrawing();

    ClearBackground(g_bg);
    DrawRectangleLinesEx(frame, 5.0f, g_spriteColor);
    ShowTurn();

    board.Draw();

    EndDrawing();
}

void Game::Update() {
    symbol = (turn % 2)? 'O' : 'X';
    board.Update(symbol, turn);
    if(turn == 9) {
        state = DRAW;
    }
}

void Game::ShowTurn() {
    const float padding = 10.0f;
    const float x = frame.x + padding;
    const float y = frame.y + padding;

    DrawText(TextFormat("Turn: %c", symbol), x, y, g_cellSize/2, g_spriteColor);
}
