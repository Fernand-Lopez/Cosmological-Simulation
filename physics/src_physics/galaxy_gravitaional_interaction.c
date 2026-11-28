//
// Created by Clément on 29/10/2026.
//

#include "../include_physics/physics_include.h"

void galaxyGravitationalInteraction(t_object objects[], t_centerOfGalaxy const center, int const N) {

    setAcceleration(objects, N);

    interactionWithCenterOfGalaxy(objects, center, N);

    galaxyStarsInteractions(objects, N);
}