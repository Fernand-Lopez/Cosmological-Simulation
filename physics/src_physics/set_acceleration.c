//
// Created by Clément on 28/11/2026.
//
#include "../include_physics/physics_include.h"

void setAcceleration(t_object objects[], int const N) {
    for (int i = 0 ; i < N ; i++) { // acceleration update
        objects[i].xAcceleration = 0; //replace by new function
        objects[i].yAcceleration = 0;
    }
}
