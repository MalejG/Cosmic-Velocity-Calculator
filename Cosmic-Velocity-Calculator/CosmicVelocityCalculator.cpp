#include <cmath>
#include <iostream>
#include <fstream>

#include "CosmicVelocityCalculator.h"

using namespace std;

double firstCosmicVelocity(double mass, double radiusObject,const double *orbit)
{
    const double gravitationalConstant = 6.6743 * pow(10, ( -11));
    double radius = (radiusObject + *orbit) * 1000; // convert to meters
    
    mass = mass * pow(10, 21); //yottagrams to kilograms

    double orbitalSpeed = sqrt((gravitationalConstant * mass)/(radius));
    return speedOfLightControl(orbitalSpeed / 1000); //convert to km/s
}


double secondCosmicVelocity(double mass, double radiusObject)
{
    const double gravitationalConstant = 6.6743 * pow(10, (-11));

    double radius = radiusObject * 1000; // convert to meters
    mass = mass * pow(10, 21); //yottagrams to kilograms

    double orbitalSpeed = sqrt((2 * gravitationalConstant * mass) / (radius));

    return speedOfLightControl(orbitalSpeed / 1000); //convert to km/s
}

double thirdCosmicVelocity(double massObject1, double radiusObject1, double massCenterObject2, double radiusCenterObject2, double AU)
{
    const double autokm = AU * 149597871;

    double centerV1 = secondCosmicVelocity(massCenterObject2, autokm);
    double centerV2 = firstCosmicVelocity(massCenterObject2, radiusCenterObject2, &autokm);
    double planetV2 = secondCosmicVelocity(massObject1, radiusObject1);
    
    if (speedOfLightControl(centerV1 == -1) || speedOfLightControl(centerV2 == -1) || speedOfLightControl(planetV2 == -1)) 
    {
        return -1; 
    }

    double v3 = sqrt( pow(planetV2 ,2) + pow((centerV1 - centerV2), 2));

    return speedOfLightControl(v3);
}

double speedOfLightControl(double speed)
{
    const double C = 299792.458; //km/s
    
    if(speed >= C)
    { 
        return -1;
    }
    else 
    {
        return speed;
    }
}


//pridat nazev
void exportData( double mass1, double radiusObject1, size_t n, const double Orbit[], double massCenterObject2, double radiusCenterObject2, double AU)
{


    ofstream myfile;
    myfile.open("cosmicVelocityDataExport.txt");

    //firstCosmicVelocity
    myfile << "\nFirst Cosmic Velocity\n";
    for (size_t i = 0; i < n; ++i)
    {
        double v1 = firstCosmicVelocity(mass1, radiusObject1, &Orbit[i]);
        cout << Orbit[i] << " " << i << "\n";

        if (v1 == -1)
        {
            myfile << Orbit[i] << "km  " << " Exceeds light limit";
        }
        else
        {
            myfile << Orbit[i] << "km  " << v1 << " km/s\n";
        }
    }

    //secondCosmicVelocity
    myfile << "\nSecond Cosmic Velocity\n";
    double v2 = secondCosmicVelocity(mass1, radiusObject1);

    if (v2 == -1) 
    {
        myfile << "Exceeds light limit";
    }
    else
    {
        myfile << v2 << " km/s\n";
    }

    //ThirdCosmicVelocity
    myfile << "\nThird Cosmic Velocity\n";
    double v3 = thirdCosmicVelocity(mass1, radiusObject1, massCenterObject2, radiusCenterObject2, AU);


    if (v3 == -1) 
    {
        myfile << "Exceeds light limit";
    }
    else 
    {
        myfile << v3 << " km/s\n";
    }

    myfile.close();
    cout << "Data written in file";

}
