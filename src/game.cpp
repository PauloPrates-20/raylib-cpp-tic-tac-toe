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

            int cellIdx = board.GetCellIdx(x, y);
            bool boardUpdated = board.PutChar((turn % 2)? 'X' : 'O', cellIdx);

            if(boardUpdated) {
                playerPositions[turn%2] |= (1 << cellIdx);

                for(auto position : winPositions) {
                    if((position & playerPositions[turn%2]) == position) {
                        state = (turn%2)? X_WIN : O_WIN;
                        break;
                    }
                }

                turn++;
                if(turn == 9 && state == RUNNING) {
                    state = DRAW;
                }
                // printf("Game state: %d\n", state);
                // printf("Turn: %d\n", turn);
            }
        }
    }
}
