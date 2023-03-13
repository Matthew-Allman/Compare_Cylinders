#pragma once
#include <cmath>

// Declare a class called ComputerScieneProject1 with functions that will be used in another file
//
class ComputerScienceProject1
{
	// Not accessible outside of the class
	//
	private:

		// Declare two private int variables that will not be accessible throughout the class
		//
		int cylinderRadius = 0;
		int cylinderHeight = 0;

		// Declare a constant double variable, PI
		//
		const double PI = 3.14159;

	// Accessible throughout entire class
	//
	public:

		// Constructor function for class ComputerScieneProject1 that will be executed 
		// as soon as an object of this class is created.
		// Pass two integers as parameters
		//
		ComputerScienceProject1(int radius, int height)
		{
			// Assigne the two constructor variables to these values
			//
			cylinderRadius = radius;
			cylinderHeight = height;
		}

		// Declare a function with return type double called totalSurfaceArea
		// with a double parameter PI
		//
		double totalSurfaceArea()
		{
			// Declare a double variable to 0
			//
			double totalSA = 0; 

			// Set totalSA = the formula for the total surface area of the cylinder
			//
			totalSA = (2 * PI * cylinderRadius * (cylinderRadius + cylinderHeight));

			// Return the total surface area of the cylinder
			//
			return totalSA;
		}

		// Declare a function that will get the lateral surface area of the given cylinder
		//
		double LateralSurfaceArea()
		{
			double lateralSA = 0;
			lateralSA = (2 * PI * cylinderRadius * cylinderHeight);
			return lateralSA;
		}

		// Declare a function that will get the volume of the given cylinder
		//
		double totalVolume()
		{
			double volume  = 0;
			double tempNum = 0;

			tempNum = pow(cylinderRadius, 2);
			volume  = (PI * tempNum * cylinderHeight);
			return volume;
		}
};