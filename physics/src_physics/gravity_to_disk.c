//
// Created by Clément on 29/10/2026.
//

#include "../include_physics/physics_include.h"
#include <math.h>

void orbitalVelocity(t_object objects[], t_disk const disk, int const N) {
    double Force = 0; //Newtonian force*
    double iForce = 0;
    double jForce = 0;
    const double epsilon = 0.0001;

    for (int i = 0 ; i < N ; i++) { // acceleration update
        objects[i].xAcceleration = 0;
        objects[i].yAcceleration = 0;
    }
    for (int i = 0 ; i < N ; i++) {
        const double idx = disk.xPosition - objects[i].xPosition;// - objects[j].xPosition; //composante x
        double const idy = disk.yPosition - objects[i].yPosition;// - objects[j].yPosition; //composante y
        double const idistance =  sqrt(pow(idx, 2) + pow(idy, 2) + pow(epsilon, 2));
        double const iex = idx / idistance; //+ epsilon ; //unitary vector (direction)
        double const iey = idy / idistance;// + epsilon; //unitary vector (direction)
        Force = 3*GM / (pow(idistance, 2) + pow(epsilon, 2)); // the epsilon allow to not divide by 0
        objects[i].xAcceleration += Force * iex; // the acceleration depend of the force and the mass of the others objects
        objects[i].yAcceleration += Force * iey;// the acceleration depend of the force and the mass of the others objects
    }
    for (int i = 0 ; i < N ; i++) {
        for (int j = i+1 ; j < N ; j++) {
            double const dx = objects[i].xPosition - objects[j].xPosition;
            double const dy = objects[i].yPosition - objects[j].yPosition;

            double const distance = sqrt(pow(dx, 2) + pow(dy, 2) + pow(epsilon, 2));

            double const ex = dx / distance;
            double const ey = dy / distance;


            jForce = G*objects[i].mass / (pow(distance, 2)+ pow(epsilon, 2)); // the epsilon allow to not divide by 0
            iForce = G*objects[j].mass / (pow(distance, 2)+ pow(epsilon, 2)); // the epsilon allow to not divide by 0


            objects[j].xAcceleration += jForce / objects[i].mass  * ex;
            objects[j].yAcceleration += jForce / objects[i].mass * ey;
            objects[i].xAcceleration -= iForce / objects[j].mass * ex;
            objects[i].yAcceleration -= iForce / objects[j].mass * ey;
        }
    }
}