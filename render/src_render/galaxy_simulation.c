//
// Created by Clément on 22/10/2026.
//

#include "../../physics/include_physics/physics_include.h"
#include "raylib.h"
#include "../include_render/render_include.h"

void galaxySimulation(t_disk const disk, t_object object[], int const N) {
    initWindow();

    galaxySetPositionMassVelocity(object, disk, N); //suspect

    while (!WindowShouldClose()) {
        double const secondes = 0.00000001;
        BeginDrawing();
        ClearBackground(BLACK);
        drawDisk(disk);
        drawObjectsGalaxy(object, disk, N);
        orbitalVelocity(object, disk, N);
        galaxyUpdatePosition(object, N, secondes);
        exitSimulation();
        EndDrawing();
    }
    CloseWindow();
}
