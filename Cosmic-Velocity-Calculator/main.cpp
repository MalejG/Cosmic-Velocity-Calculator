#include <iostream>
#include <cmath>
#include "CosmicVelocityCalculator.h"
#include <iomanip>

using namespace std;

int main()
{
    double mass = 1;
    double radiusObject = 1;
    constexpr size_t n = 5;
    int orbits[n] = {200, 500, 1000, 5000, 100000};

    cout << "Hello Cosmic Velocity Calculator!\n";
    cout << "\nLets calculate orbital velocity\n";
    cout << "\n\nIf you want to calculate for earth. \nUse for mass 5972 Yg.\nUse for radius 6371 km. \n\n";
    cout << "\nPlease pick mass of your object in yottagrams: ";
    cin >> mass;
    cout << "\nPlease pick radius of your object in kilometers: ";
    cin >> radiusObject;


    cout << "\nFirst Cosmic Velocity!(Orbital velocity) => OB\n";
    for(size_t i = 0; i < n; i++)
    {
        cout << "OB " << orbits[i] << " km above the object surface is: "
            << fixed << setprecision(4) << firstCosmicVelocity(mass, radiusObject, &orbits[i]) << " km/s" << endl;
    }

    
    cout << "\nSecond Cosmic Velocity (Escape Velocity)\n";
    cout << "The Escape velocity from surface of the object is: "
        << fixed << setprecision(4) << secondCosmicVelocity(mass, radiusObject) << " km/s" << endl << "\n";

    return 0;
}