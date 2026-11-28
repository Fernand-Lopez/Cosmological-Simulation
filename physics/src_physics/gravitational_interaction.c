//
// Created by Clément on 06/09/2026.
//
#include "../include_physics/physics_include.h"
#include <math.h>
#define G 6.67e-11

void gravitationalInteraction(t_object objects[], int const N) {
    // dx : x-component y : y-component ex : unitary vector x ey : unitary vector y
    double Force = 0; //Newtonian force

    setAcceleration(objects, N);
    
    for (int i = 0 ; i < N ; i++) {// multiplies masses of two object and calculate the distance
        for (int j = i+1 ; j < N ; j++) {
            const double epsilon = 10000;
            const double dx = objects[j].xPosition - objects[i].xPosition; //composante x
            double const dy = objects[j].yPosition - objects[i].yPosition; //composante y
            double const distance =  sqrt((objects[j].xPosition - objects[i].xPosition)*(objects[j].xPosition - objects[i].xPosition) + (objects[j].yPosition - objects[i].yPosition)*(objects[j].yPosition - objects[i].yPosition));
            double const ex = dx / distance; //unitary vector (direction)
            double const ey = dy / distance; //unitary vector (direction)

            const double Masses = objects[i].mass * objects[j].mass; //multiplies masses
            Force = G * Masses / (distance*distance + epsilon); // the epsilon allow to not divide by 0
            objects[i].xAcceleration += (Force / objects[i].mass) * ex; // the acceleration depend of the force and the mass of the others objects
            objects[i].yAcceleration += (Force / objects[i].mass) * ey;// the acceleration depend of the force and the mass of the others objects
            objects[j].xAcceleration -= (Force / objects[j].mass) * ex; // Fa/b = -Fb/a
            objects[j].yAcceleration -= (Force / objects[j].mass) * ey; // Fa/b = -Fb/a

        }
    }
}