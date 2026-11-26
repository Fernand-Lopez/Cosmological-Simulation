//
// Created by Clément on 05/09/2026.
//

#ifndef NBODY_OBJECT_H
#define NBODY_OBJECT_H
#define GM 1e6
#define G 6.67e-11
#define M 1.9884e30 //stellar mass

typedef struct { //s_object a retirer inutile
    double xPosition;
    double yPosition;
    double xVelocity;
    double yVelocity;
    double xAcceleration;
    double yAcceleration;
    double mass;
    double radius;
} t_object;

typedef struct {
    int xPosition;
    int yPosition;
    double mass;
    float radius;
}t_disk;

void gravitationalInteraction(t_object objects[], int N);
void updatePosition(t_object objects[], int N, double dt);
void setPositionMassVelocity(t_object object[], int N);
void galaxySetPositionMassVelocity(t_object object[], t_disk disk, int N);
void orbitalVelocity(t_object objects[], t_disk disk, int N);
void galaxyUpdatePosition(t_object objects[],  int N, double dt);

#endif //NBODY_OBJECT_H