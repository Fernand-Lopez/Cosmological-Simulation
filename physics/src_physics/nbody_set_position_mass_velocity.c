//
// Created by Clément on 20/09/2026.
//

#include "../include_physics/physics_include.h"
#include <stdio.h>
#include <stdlib.h>


void setPositionMassVelocity(t_object object[], int N) {

    for (int i = 0 ; i < N ; i++) {

        double const weightMin = 1e10; //Minimum weight for stars
        double const weightMax = 1e30; //Maximum weight for stars

        object[i].xPosition = rand() % 1201; //Randomize objects spawns  Ne pas avoir de lien avec la taille de l'écran (world space)
        object[i].yPosition = rand() % 901;

        object[i].mass = weightMin + (double)rand() / ((double)RAND_MAX / (weightMax - weightMin)); //Randomize objects mass

        object[i].xVelocity = 0; //start velocity
        object[i].yVelocity = 0;
    }
}
