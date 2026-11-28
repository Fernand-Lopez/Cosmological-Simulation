//
// Created by Clément on 28/11/2026.
//
#include "../include_physics/physics_include.h"
#include <math.h>

void interactionWithCenterOfGalaxy(t_object objects[], t_centerOfGalaxy const center,int const N) {

    double Force = 0; //Newtonian force*

    for (int i = 0 ; i < N ; i++) {
        const double idx = center.xPosition - objects[i].xPosition;// - objects[j].xPosition; //composante x
        double const idy = center.yPosition - objects[i].yPosition;// - objects[j].yPosition; //composante y
        double const iDistance =  sqrt(pow(idx, 2) + pow(idy, 2) + pow(ϵ, 2));
        double const iex = idx / iDistance; //+ epsilon ; //unitary vector (direction)
        double const iey = idy / iDistance;// + epsilon; //unitary vector (direction)
        Force = GM / (pow(iDistance, 2) + pow(ϵ, 2)); // the epsilon allow to not divide by 0
        objects[i].xAcceleration += Force * iex; // the acceleration depend on the force and the mass of the others objects
        objects[i].yAcceleration += Force * iey;// the acceleration depend on the force and the mass of the others objects
    }
}
