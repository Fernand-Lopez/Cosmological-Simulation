//
// Created by Clément on 20/09/2026.
//

#include "../include_render/render_include.h"
#include "raylib.h"


void initButton(t_listButton button, float const xPosition, float const yPosition) {
    button->bounds.x = xPosition;
    button->bounds.y = yPosition;
    button->bounds.height = 100;
    button->bounds.width = 200;
}

