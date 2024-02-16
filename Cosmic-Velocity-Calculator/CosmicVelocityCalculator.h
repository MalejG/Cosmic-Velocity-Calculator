#ifndef __COSMICVELOCITYCALCULATOR_h__
#define __COSMICVELOCITYCALCULATOR_h__

#pragma message ("CosmicVelocityCalculator.h has been included.")

//Function Orbital Velocity
double firstCosmicVelocity(double mass, double radiusObject, const int *orbit);

//Function Escape Velocity
double secondCosmicVelocity(double mass, double radiusObject);

//Function Escape from Center Object Velocity
double thirdCosmicVelocity(double massObject1, double radiusObject1, double massCenterObject2, double radiusCenterObject2);

#endif //__COSMICVELOCITYCALCULATOR_h__