//
// Created by Clément on 25/10/2026.
//
//
// Created by Clément on 20/09/2026.
//

#include "../include_physics/physics_include.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592653589793


void galaxySetPositionMassVelocity(t_object object[], t_disk const disk, int const N) {

    for (int i = 0 ; i < N ; i++) {

        double const weightMin = 1e10; //Minimum weight for stars
        double const weightMax = 1e30; //Maximum weight for stars

        object[i].xPosition = disk.radius + (float)disk.xPosition + (double)rand() / (double)RAND_MAX * 300 * cos((double)rand() / (double)RAND_MAX * 2*PI); //Randomize objects spawns  Ne pas avoir de lien avec la taille de l'écran (world space)
        object[i].yPosition = disk.radius + (float)disk.yPosition + (double)rand() / (double)RAND_MAX * 300 * sin((double)rand() / (double)RAND_MAX * 2*PI);

        while ((object[i].xPosition > 1200 || object[i].yPosition > 900)){//&& (object[j].xPosition > 1200 || object[j].yPosition > 900)) {
            object[i].xPosition = disk.radius + (float)disk.xPosition + (double)rand() / (double)RAND_MAX * 300 * cos((double)rand() / (double)RAND_MAX * 2*PI);
            object[i].yPosition = disk.radius + (float)disk.yPosition + (double)rand() / (double)RAND_MAX * 300 * sin((double)rand() / (double)RAND_MAX * 2*PI);
        }

        double const rx = object[i].xPosition - disk.xPosition;
        double const ry = object[i].yPosition - disk.yPosition;

        double const distance = sqrt(pow(rx, 2) + pow(ry, 2));

        object[i].mass = weightMin + (double)rand() / ((double)RAND_MAX / (weightMax - weightMin)); //Randomize objects mass


        object[i].xVelocity = -ry / distance * sqrt(GM / distance); //start velocity
        object[i].yVelocity = rx / distance * sqrt(GM / distance);

        }

    }

