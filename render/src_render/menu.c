//
// Created by Clément on 20/09/2026.
//

#include "../include_render/render_include.h"
#include "raylib.h"
#define WIDTH 1200
#define HEIGHT 900

void menu() {
    InitWindow(WIDTH, HEIGHT, "Cosmological Simulation");

    t_button nBodyButton;
    t_button quitButton;
    t_button galaxySimulationButton;


    nBodyButton.label = "N-Body";
    quitButton.label = "Quit";
    galaxySimulationButton.label = "Galaxy";

    initButton(&nBodyButton, 500, 400);
    initButton(&galaxySimulationButton, 500, 550);
    initButton(&quitButton, 500, 700);

    Color const textColor = WHITE;


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Cosmologicals Simulations", 100, 250, 75, textColor);
        drawButton(&nBodyButton);
        drawButton(&quitButton);
        drawButton(&galaxySimulationButton);
        if (nBodyButton.isHovered) { //execution of the NBody simulation
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                CloseWindow();
                t_object object[30];
                NBodySimulation(object, 30);
                return; //Close window and execute the NBody simulation
            }
        }
        if (quitButton.isHovered) { //quit
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                CloseWindow();
                return;
            }
        }
        if (galaxySimulationButton.isHovered) { //execution of the galaxy simulation
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                CloseWindow();
                t_disk disk;
                t_object object[1];
                disk.mass = 1e35;
                disk.radius = 10;
                disk.xPosition = 600;
                disk.yPosition = 450;
                galaxySimulation(disk, object, 1);
                return;
            }
        }
        EndDrawing();
    }
    CloseWindow();
}