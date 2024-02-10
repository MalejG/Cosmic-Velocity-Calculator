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
    cout << "\n\nIf you want to calculate for earth. \nUse for mass 5.972 Yg.\nUse for radius 6371 km. \n\n";
    cout << "\nPlease pick mass of your object in yottagrams: ";
    cin >> mass;
    cout << "\nPlease pick radius of your object in kilometers: ";
    cin >> radiusObject;
    cout << "The orbital velocity of 200 km above the surface of the object is: "
        << fixed << setprecision(3) << firstCosmicVelocity(mass, radiusObject) << "km/s" << endl << "\n\n";

    cout << "The Escape velocity from surface of the object is: "
        << fixed << setprecision(3) << secondCosmicVelocity(mass, radiusObject) << "km/s" << endl << "\n\n";

    return 0;
}