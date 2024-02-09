#include <iostream>
#include <cmath>
#include "CosmicVelocityCalculator.h"
#include <iomanip>

using namespace std;

int main()
{
    double mass = 1;
    double radiusObject = 1;

    cout << "Hello Cosmic Velocity Calculator!\n";
    cout << "\nLets calculate orbital velocity\n";
    cout << "\nPlease pick mass of your object in yottagrams: ";
    cin >> mass;
    cout << "\nPlease pick radius of your object in kilometers: ";
    cin >> radiusObject;
    cout << "The orbital velocity of 200 km above the surface of the object is: "
        << fixed << setprecision(2) << firstCosmicVelocity(mass, radiusObject) << "km/s" << endl << "\n\n";

    return 0;
}