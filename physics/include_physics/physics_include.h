//
// Created by Clément on 05/09/2026.
//

#ifndef NBODY_OBJECT_H
#define NBODY_OBJECT_H
#define GM 1e6
#define G 6.67e-11
#define M 1.9884e30 //stellar mass
#define ϵ 0.0001
#define π 3.141592653589793

typedef struct {
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
}t_centerOfGalaxy;

typedef struct {
    double radius;
    double θ;
}t_polar;

void gravitationalInteraction(t_object objects[], int N);
void updatePosition(t_object objects[], int N, double dt);
void setPositionMassVelocity(t_object object[], int N);
void galaxySetPositionMassVelocity(t_object object[], t_polar polar, t_centerOfGalaxy center, int N, int K);
void galaxyGravitationalInteraction(t_object objects[], t_polar polar, t_centerOfGalaxy center, int N);
void galaxyUpdatePosition(t_object objects[],  int N, double dt);
double logarithmicSpirale(t_polar polar, double a, double b, int K, int k);

#endif //NBODY_OBJECT_H