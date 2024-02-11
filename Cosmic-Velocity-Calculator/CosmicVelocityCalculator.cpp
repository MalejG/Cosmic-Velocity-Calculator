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
