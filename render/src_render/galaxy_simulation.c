//
// Created by Clément on 22/10/2026.
//

#include "../../physics/include_physics/physics_include.h"
#include "raylib.h"
#include "stdio.h"
#include "../include_render/render_include.h"

void galaxySimulation(t_disk const disk, t_object object[], int const N) {
    initWindow();

    galaxySetPositionMassVelocity(object, disk, N); //suspect

    while (!WindowShouldClose()) {
        double const secondes = 0.001;
        BeginDrawing();
        ClearBackground(BLACK);
        drawDisk(disk);
        drawObjectsGalaxy(object, disk, N);
        printf("%f    %f", object[0].xPosition, object[0].yPosition);
        orbitalVelocity(object, disk, N);
        galaxyUpdatePosition(object, disk, N, secondes);
        exitSimulation();
        EndDrawing();
    }
    CloseWindow();
}
