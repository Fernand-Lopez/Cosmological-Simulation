//
// Created by Clément on 20/09/2026.
//

#include "../../physics/include_physics/physics_include.h"
#include "../include_render/render_include.h"
#include "raylib.h"

void drawObjects(t_object objects[], int const N) {
    BeginDrawing();
    ClearBackground(BLACK);
    for (int i = 0 ; i < N ; i++) {
        DrawCircle(objects[i].xPosition, objects[i].yPosition, 5, WHITE); //Draw objects
    }
    EndDrawing();
}


