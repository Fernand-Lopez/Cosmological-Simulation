//
// Created by Clément on 25/10/2026.
//

#include "raylib.h"
#include "../../physics/include_physics/physics_include.h"

void drawObjectsGalaxy(t_object objects[], int const N) {
    for (int i = 0 ; i < N ; i++) {
        DrawCircle((int)objects[i].xPosition, (int)objects[i].yPosition, 2, WHITE); //Draw objects
    }
}