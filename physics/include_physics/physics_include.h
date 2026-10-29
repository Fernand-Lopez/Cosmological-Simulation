//
// Created by Clément on 05/09/2026.
//

#ifndef NBODY_OBJECT_H
#define NBODY_OBJECT_H

typedef struct { //s_object a retirer inutile
    double xPosition;
    double yPosition;
    double xVelocity;
    double yVelocity;
    double xAcceleration;
    double yAcceleration;
    double mass;
} t_object;

typedef struct {
    int xPosition;
    int yPosition;
    float mass;
    float radius;
}t_disk;

void gravitationalInteraction(t_object objects[], int N);
void updatePosition(t_object objects[], int N, double dt);
void setPositionMassVelocity(t_object object[], int N);
void galaxySetPositionMassVelocity(t_object object[], t_disk disk, int N);

#endif //NBODY_OBJECT_H