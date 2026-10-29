//
// Created by Clément on 21/10/2026.
//
#include "../include_render/render_include.h"

void exitSimulation() {
    if (IsKeyPressed(KEY_ESCAPE)) {
        CloseWindow();
        menu();
    }
}