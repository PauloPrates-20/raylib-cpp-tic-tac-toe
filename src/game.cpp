#include "game.h"
#include "config.h"
#include "raylib.h"
#include "colors.h"

static void DrawFrame() {
    const float lineThick = 5.0f;
    const Rectangle rec{1*g_cellSize/2 + lineThick/2, 1*g_cellSize/2 + lineThick/2, (g_cellCount - 1)*g_cellSize - lineThick/2, (g_cellCount - 1)*g_cellSize - lineThick/2};

    DrawRectangleLinesEx(rec, lineThick, g_spriteColor);
}

Game::Game() {
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
    DrawFrame();

    board.Draw();

    EndDrawing();
}

void Game::Update() {
    board.Update((turn % 2)? 'O' : 'X', turn);
    if(turn == 9) {
        state = DRAW;
    }
}
