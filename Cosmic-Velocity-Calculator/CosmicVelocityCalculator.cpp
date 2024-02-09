#include <iostream>
#include <cmath>
#include "CosmicVelocityCalculator.h"

using namespace std;

// For now only OUTPUT will be orbital velocity for 200 km (function will be expended for variable heights)
double firstCosmicVelocity(double mass, double radiusObject)
{
    cout << "\nFirst Cosmic Velocity!(Orbital velocity)\n";
    
    const double gravitationalConstant = 6.674 * pow(10, ( -11));
    const double orbita = 200; //orbita 200 km
    
    double radius = (radiusObject + orbita) * 1000; // convert to meters
    mass = mass * pow(10, 24); //yottagrams to kilograms

    double orbitalSpeed = sqrt((gravitationalConstant * mass)/(radius));

    return orbitalSpeed / 1000; //to km/s
}


double secondCosmicVelocity() 
{
    cout << "Escape Velocity!\n";
    return 0;
}


