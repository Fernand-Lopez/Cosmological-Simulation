//
// Created by Clément on 27/11/2026.
//
#include "../include_physics/physics_include.h"
#include <math.h>

#include "raylib.h"


double logarithmicSpirale(t_polar const polar, double const a, double const b, int const K, int const k) {
    //check division error with b
    return 1/b*log(polar.radius/a) + (double)2*PI*k/K + ϵ;
}
