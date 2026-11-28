//
// Created by Clément on 22/10/2026.
//

#include "../../physics/include_physics/physics_include.h"
#include "raylib.h"
#include "../include_render/render_include.h"
#define Δt 0.1

void galaxySimulation(t_centerOfGalaxy const center, t_object object[], int const N, int const K, t_polar const polar) {
    initWindow();
    galaxySetPositionMassVelocity(object, polar, center, N, K); //suspect

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        drawCenter(center);
        drawObjectsGalaxy(object, N);
        galaxyGravitationalInteraction(object, center, N);
        galaxyUpdatePosition(object, N, Δt);
        exitSimulation();
        EndDrawing();
    }
    CloseWindow();
}
