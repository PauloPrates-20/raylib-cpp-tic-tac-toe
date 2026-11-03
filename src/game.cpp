#include "game.h"
#include "colors.h"
#include "config.h"
#include "raylib.h"
#include <cstdio>

Game::Game() {
    InitWindow(g_wWidth, g_wHeight, g_wTitle);
    SetTargetFPS(60);
}

void Game::Run() {
    while(!WindowShouldClose()) {
        Update();
        Draw();
    }

    CloseWindow();
}

void Game::Draw() {
    BeginDrawing();

    ClearBackground(g_bgColor);

    board.Draw();

    EndDrawing();
}

void Game::Update() {
    if(state == RUNNING) {
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            float x = GetMouseX();
            float y = GetMouseY();

            if(board.PutChar((turn % 2)? 'O' : 'X', board.GetCellIdx(x, y))) {
                turn++;
            }
        }
    }
}
