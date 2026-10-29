//
// Created by Clément on 29/10/2026.
//
#include "../include_physics/physics_include.h"

void galaxyUpdatePosition(t_object objects[], int N, double dt) {
    for (int i = 0 ; i < N ; i++) {
        objects[i].xVelocity += objects[i].xAcceleration * dt; //Update velocity on X position with this equation v = a*dt in a movement uniformly accelerated
        objects[i].yVelocity += objects[i].yAcceleration * dt; //Update velocity on Y position with this equation v = a*dt in a movement uniformly accelerated
        objects[i].xPosition += objects[i].xVelocity * dt; //Update position on X position with this equation x = v*dt in a movement uniformly accelerated
        objects[i].yPosition += objects[i].yVelocity * dt; //Update position on Y position with this equation x = v*dt in a movement uniformly accelerated
    }
}