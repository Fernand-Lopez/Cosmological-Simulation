//
// Created by Clément on 28/11/2026.
//
#include "../include_physics/physics_include.h"
#include <math.h>

void galaxyStarsInteractions(t_object objects[], int const N) {

    double iForce = 0;
    double jForce = 0;

    for (int i = 0 ; i < N ; i++) {
        for (int j = i+1 ; j < N ; j++) {
            double const dx = objects[i].xPosition - objects[j].xPosition;
            double const dy = objects[i].yPosition - objects[j].yPosition;

            double const distance = sqrt(pow(dx, 2) + pow(dy, 2) + pow(ϵ, 2));

            double const ex = dx / distance;
            double const ey = dy / distance;


            jForce = G*objects[i].mass / (pow(distance, 2)+ pow(ϵ, 2)); // the epsilon allow to not divide by 0
            iForce = G*objects[j].mass / (pow(distance, 2)+ pow(ϵ, 2)); // the epsilon allow to not divide by 0


            objects[j].xAcceleration += jForce / objects[i].mass  * ex;
            objects[j].yAcceleration += jForce / objects[i].mass * ey;
            objects[i].xAcceleration -= iForce / objects[j].mass * ex;
            objects[i].yAcceleration -= iForce / objects[j].mass * ey;
        }
    }
}
