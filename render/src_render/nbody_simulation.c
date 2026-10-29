//
// Created by Clément on 05/09/2026.
//

#include "raylib.h"
#include "../../physics/include_physics/physics_include.h"
#include "../include_render/render_include.h"


void NBodySimulation(t_object objects[], int const N){

    initWindow();

    setPositionMassVelocity(objects, N);

    while (!WindowShouldClose()) { //Raylib screen
        double const secondes = 0.0000000001;
        drawObjects(objects, N);
        gravitationalInteraction(objects, N);
        updatePosition(objects, N, secondes);
        exitSimulation();
    }
    CloseWindow();
}