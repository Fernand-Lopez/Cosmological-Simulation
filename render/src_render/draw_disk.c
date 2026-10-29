//
// Created by Clément on 22/10/2026.
//
#include "../include_render/render_include.h"
#include "raylib.h"

void drawDisk(t_disk disk) {//affichage d'un centre de gravité qui sera le centre de la galaxie
    DrawCircle(disk.xPosition, disk.yPosition, disk.radius, YELLOW);
}

//les idées ne sont pas bien claires pour l'instant ---> à paufiner !!