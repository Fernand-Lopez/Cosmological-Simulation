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
        double const weightMin = 1e10; //Minimum weight for stars
        double const weightMax = 1e30; //Maximum weight for stars-
        double const Δ = 0.15;
        double const radiusMin = 20;
        double const radiusMax = 350;
        int const armIndice = rand() % (int)K;
        polar.radius = radiusMin + (double)rand() / ((double)RAND_MAX + 1.0) * (radiusMax - radiusMin);  //add min radius and max radius
        polar.θ = logarithmicSpirale(polar, 100, -1, K, armIndice); //calculate the angle of the spire
        double const randomSpacing = -Δ + ((double)rand() / (double)RAND_MAX + 1) * 2*Δ;
        object[i].xPosition = center.xPosition + polar.radius * cos(polar.θ + randomSpacing);
        object[i].yPosition = center.yPosition + polar.radius * sin(polar.θ + randomSpacing);
        object[i].mass = weightMin + (double)rand() / ((double)RAND_MAX / (weightMax - weightMin)); //Randomize objects mass
        double const rx = object[i].xPosition - center.xPosition;
        double const ry = object[i].yPosition - center.yPosition;

        double const distance = sqrt(pow(rx, 2) + pow(ry, 2));
        object[i].xVelocity = -ry / distance * sqrt(GM / distance); //start velocity
        object[i].yVelocity = rx / distance * sqrt(GM / distance);
    }
    }

