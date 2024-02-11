#ifndef __COSMICVELOCITYCALCULATOR_h__
#define __COSMICVELOCITYCALCULATOR_h__

#pragma message ("CosmicVelocityCalculator.h has been included.")

//Function Orbital Velocity
double firstCosmicVelocity(double mass, double radiusObject, const int *orbit);

//Function Escape Velocity
double secondCosmicVelocity(double mass, double radiusObject);



#endif //__COSMICVELOCITYCALCULATOR_h__