//
// Created by Clément on 29/10/2026.
//

#include "../include_physics/physics_include.h"
#include <math.h>



void orbitalVelocity(t_object objects[], t_disk disk, int const N){
    // dx : x-component y : y-component ex : unitary vector x ey : unitary vector y
    double Force = 0; //Newtonian force*
    for (int i = 0 ; i < N ; i++) { // acceleration update
        objects[i].xAcceleration = 0;
        objects[i].yAcceleration = 0;
    }
    for (int i = 0 ; i < N ; i++) {// multiplies masses of two object and calculate the distance
        const double epsilon = 0.000001;
        const double dx = disk.xPosition - objects[i].xPosition; //composante x
        double const dy = disk.yPosition - objects[i].yPosition; //composante y
        double const distance =  sqrt((disk.xPosition - objects[i].xPosition)*(disk.xPosition - objects[i].xPosition) + (disk.yPosition - objects[i].yPosition)*(disk.yPosition - objects[i].yPosition));
        double const ex = dx / distance + epsilon ; //unitary vector (direction)
        double const ey = dy / distance + epsilon; //unitary vector (direction)

        //const double Masses = objects[i].mass * disk.mass; //multiplies masses
        Force = GM / (pow(distance, 2) + pow(epsilon, 2)); // the epsilon allow to not divide by 0
        objects[i].xAcceleration += Force * ex; // the acceleration depend of the force and the mass of the others objects
        objects[i].yAcceleration += Force * ey;// the acceleration depend of the force and the mass of the others objects
        }
    }
