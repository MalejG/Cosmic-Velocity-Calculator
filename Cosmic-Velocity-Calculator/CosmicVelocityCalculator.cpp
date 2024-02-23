#include <iostream>
#include <cmath>
#include "CosmicVelocityCalculator.h"

using namespace std;


double firstCosmicVelocity(double mass, double radiusObject,const int *orbit)
{
    const double gravitationalConstant = 6.6743 * pow(10, ( -11));
    double radius = (radiusObject + *orbit) * 1000; // convert to meters
    
    mass = mass * pow(10, 21); //yottagrams to kilograms

    double orbitalSpeed = sqrt((gravitationalConstant * mass)/(radius));

    return orbitalSpeed / 1000; //to km/s
}


double secondCosmicVelocity(double mass, double radiusObject)
{
    const double gravitationalConstant = 6.6743 * pow(10, (-11));

    double radius = radiusObject * 1000; // convert to meters
    mass = mass * pow(10, 21); //yottagrams to kilograms

    double orbitalSpeed = sqrt((2 * gravitationalConstant * mass) / (radius));

    return orbitalSpeed / 1000; //convert to km/s
}

double thirdCosmicVelocity(double massObject1, double radiusObject1, double massCenterObject2, double radiusCenterObject2, double AU)
{

    //druha kosmicka rychllost  objektu1
    const double gravitationalConstant = 6.6743 * pow(10, (-11));
    //druha kosmicka rychllost  objektu2

    // v3 = sqr(v1pla**2 + v2esc**2)
    double radius = radiusObject1 * 1000; // convert to meters
    massObject1 = massObject1 * pow(10, 21); //yottagrams to kilograms

    double orbitalSpeed = sqrt((2 * gravitationalConstant * massObject1) / (radius));

    return orbitalSpeed / 1000; //convert to km/s
}
