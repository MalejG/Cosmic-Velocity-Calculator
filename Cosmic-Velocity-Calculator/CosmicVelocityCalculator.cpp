#include <iostream>
#include <cmath>
#include "CosmicVelocityCalculator.h"

using namespace std;


double firstCosmicVelocity(double mass, double radiusObject,const double *orbit)
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
    const double autokm = AU * 149597871;

    double centerV1 = secondCosmicVelocity(massCenterObject2, autokm);
    double centerV2 = firstCosmicVelocity(massCenterObject2, radiusCenterObject2, &autokm);
    double planetV2 = secondCosmicVelocity(massObject1, radiusObject1);

    double v3 = sqrt( pow(planetV2 ,2) + pow((centerV1 - centerV2), 2));

    return v3;
}
