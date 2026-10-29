//
// Created by Clément on 25/10/2026.
//

#include "raylib.h"
#include "../../physics/include_physics/physics_include.h"

void drawObjectsGalaxy(t_object objects[], t_disk const disk, int const N) {
    for (int i = 0 ; i < N ; i++) {
        DrawCircle(objects[i].xPosition, objects[i].yPosition, 5, WHITE); //Draw objects
    }
}