//
// Created by Clément on 22/10/2026.
//

#include "../../physics/include_physics/physics_include.h"
#include "raylib.h"
#include "../include_render/render_include.h"

void galaxySimulation(t_centerOfGalaxy const center, t_object object[], int const N, int const K, t_polar const polar) {
    initWindow();
    galaxySetPositionMassVelocity(object, polar, center, N, K); //suspect

    while (!WindowShouldClose()) {
        double const secondes = 0.1;
        BeginDrawing();
        ClearBackground(BLACK);
        drawDisk(center);
        drawObjectsGalaxy(object, N);
        galaxyGravitationalInteraction(object, polar, center, N);
        galaxyUpdatePosition(object, N, secondes);
        exitSimulation();
        EndDrawing();
    }
    CloseWindow();
}
