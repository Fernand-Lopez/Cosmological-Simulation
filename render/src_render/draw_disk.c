//
// Created by Clément on 22/10/2026.
//
#include "../include_render/render_include.h"
#include "raylib.h"

void drawDisk(t_centerOfGalaxy const center) {//affichage d'un centre de gravité qui sera le centre de la galaxie
    DrawCircle(center.xPosition, center.yPosition, center.radius, YELLOW);
}

//les idées ne sont pas bien claires pour l'instant ---> à paufiner !!