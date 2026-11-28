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
#define WEIGHT_MIN 1e10
#define WEIGHT_MAX 1e30
#define Δ 0.15
#define RADIUS_MIN 20
#define RADIUS_MAX 350




void galaxySetPositionMassVelocity(t_object object[], t_polar polar, t_centerOfGalaxy const center, int const N, int const K) {


    for (int i = 0 ; i < N ; i++) {
        int const armIndice = rand() % (int)K;

        polar.radius = RADIUS_MIN + (double)rand() / ((double)RAND_MAX + 1.0) * (RADIUS_MAX - RADIUS_MIN);  //add min radius and max radius
        polar.θ = logarithmicSpirale(polar, 100, -1, K, armIndice); //calculate the angle of the spire

        double const randomSpacing = -Δ + ((double)rand() / (double)RAND_MAX + 1) * 2*Δ;

        object[i].xPosition = center.xPosition + polar.radius * cos(polar.θ + randomSpacing);
        object[i].yPosition = center.yPosition + polar.radius * sin(polar.θ + randomSpacing);

        object[i].mass = WEIGHT_MIN + (double)rand() / ((double)RAND_MAX / (WEIGHT_MAX - WEIGHT_MIN)); //Randomize objects mass

        double const rx = object[i].xPosition - center.xPosition;
        double const ry = object[i].yPosition - center.yPosition;

        double const distance = sqrt(pow(rx, 2) + pow(ry, 2));
        object[i].xVelocity = -ry / distance * sqrt(GM / distance); //start velocity
        object[i].yVelocity = rx / distance * sqrt(GM / distance);
    }
}

