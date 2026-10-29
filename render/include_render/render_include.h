//
// Created by Clément on 19/09/2026.
//

#ifndef NBODY_RENDER_INCLUDE_H
#define NBODY_RENDER_INCLUDE_H
#include "../../physics/include_physics/physics_include.h"
#include "raylib.h"
typedef struct {
    Rectangle bounds;
    const char *label;
    bool isHovered;
}t_button;

typedef t_button* t_listButton;


void NBodySimulation(t_object objects[], int N);
void drawObjects(t_object objects[], int N);
void initWindow();
void menu();
void initButton(t_listButton button, float xPosition, float yPosition);
void drawButton(t_listButton button);
void exitSimulation();
void drawDisk(t_disk disk);
void galaxySimulation(t_disk disk, t_object object[], int N);
void drawObjectsGalaxy(t_object objects[], t_disk disk, int N);


#endif //NBODY_RENDER_INCLUDE_H