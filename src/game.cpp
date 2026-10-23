#include "game.h"
#include "config.h"
#include "raylib.h"
#include "colors.h"

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

    board.Draw();

    EndDrawing();
}

void Game::Update() {
    board.Update((turn % 2)? 'O' : 'X', turn);
    if(turn == 9) {
        state = DRAW;
    }
}
