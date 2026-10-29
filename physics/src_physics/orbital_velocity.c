//
// Created by Clément on 29/10/2026.
//

#include "../include_physics/physics_include.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11
#define M 1.9884e30 //stellar mass

void orbitalVelocity(t_object object[], t_disk disk, int N){
    double distance, dy, ex, ey;// dx : x-component y : y-component ex : unitary vector x ey : unitary vector y
    const double epsilon = 10000;
    double velocity = 0; //velocity
    for (int i = 0 ; i < N ; i++) { // acceleration update
        object[i].xAcceleration = 0;
        object[i].yAcceleration = 0;
    }
    for (int i = 0 ; i < N ; i++) {// multiplies masses of two object and calculate the distance
        for (int j = i+1 ; j < N ; j++) {

            velocity = 0;
            const double dx = object[j].xPosition - object[i].xPosition; //composante x
            dy = object[j].yPosition - object[i].yPosition; //composante y
            distance =  sqrt((object[j].xPosition - object[i].xPosition)*(object[j].xPosition - object[i].xPosition) + (object[j].yPosition - object[i].yPosition)*(object[j].yPosition - object[i].yPosition));
            ex = dx / distance; //unitary vector (direction)
            ey = dy / distance; //unitary vector (direction)

            //const double Masses = objects[i].mass * objects[j].mass; //multiplies masses
            //velocity = G * Masses / (distance*distance + epsilon); // the epsilon allow to not divide by 0
            velocity = sqrt((G*M*pow(distance, 2))/pow((pow(distance, 2) + pow(epsilon, 2)), 1.5));
            object[i].xAcceleration += (G*M / pow(distance, 2)) * ex; // the acceleration depend of the force and the mass of the others objects
            object[i].yAcceleration += (G*M / pow(distance, 2)) * ey;// the acceleration depend of the force and the mass of the others objects
            object[j].xAcceleration -= (G*M / pow(distance, 2)) * ex; // Fa/b = -Fb/a
            object[j].yAcceleration -= (G*M / pow(distance, 2)) * ey; // Fa/b = -Fb/a

        }
    }
}