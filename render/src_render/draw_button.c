//
// Created by Clément on 21/10/2026.
//

#include "../../render/include_render/render_include.h"


void drawButton(t_listButton button) {
    Vector2 const mousePosition = GetMousePosition(); //recovery of the mouse position
    button->isHovered = CheckCollisionPointRec(mousePosition, button->bounds); //store bool value
    Color const buttonColor = RED; //set button color
    DrawRectangleRec(button->bounds, buttonColor); //draw button
    DrawText(button->label, (int)button->bounds.x + 30, (int)button->bounds.y + 30, 20, WHITE);
}