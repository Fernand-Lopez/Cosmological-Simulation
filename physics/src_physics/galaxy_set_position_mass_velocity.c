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



void galaxySetPositionMassVelocity(t_object object[], t_polar polar, t_centerOfGalaxy const center, int const N, int const K) {


    for (int i = 0 ; i < N ; i++) {
        int const armIndice = (double)rand() / (double)K;
        polar.radius = (double)rand() / (double)RAND_MAX; //add min radius and max radius
        polar.theta = logarithmicSpirale(polar, 4, 8, K, armIndice); //calculate the angle of the spire
        //object[i].xPosition = polar.radius +

    }

    for (int i = 0 ; i < N ; i++) {

        double const weightMin = 1e10; //Minimum weight for stars
        double const weightMax = 1e30; //Maximum weight for stars


        object[i].xPosition = center.radius + (float)center.xPosition + (double)rand() / (double)RAND_MAX * 300 * cos((double)rand() / (double)RAND_MAX * 2*PI); //Randomize objects spawns  Ne pas avoir de lien avec la taille de l'écran (world space)
        object[i].yPosition = center.radius + (float)center.yPosition + (double)rand() / (double)RAND_MAX * 300 * sin((double)rand() / (double)RAND_MAX * 2*PI);

        while (object[i].xPosition > 1200 || object[i].yPosition > 900){
            object[i].xPosition = center.radius + (float)center.xPosition + (double)rand() / (double)RAND_MAX * 300 * cos((double)rand() / (double)RAND_MAX * 2*PI);
            object[i].yPosition = center.radius + (float)center.yPosition + (double)rand() / (double)RAND_MAX * 300 * sin((double)rand() / (double)RAND_MAX * 2*PI);
        }

        double const rx = object[i].xPosition - center.xPosition;
        double const ry = object[i].yPosition - center.yPosition;

        double const distance = sqrt(pow(rx, 2) + pow(ry, 2));

        object[i].mass = weightMin + (double)rand() / ((double)RAND_MAX / (weightMax - weightMin)); //Randomize objects mass


        object[i].xVelocity = -ry / distance * sqrt(GM / distance); //start velocity
        object[i].yVelocity = rx / distance * sqrt(GM / distance);

        }

    }

