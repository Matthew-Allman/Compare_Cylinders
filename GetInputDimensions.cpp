#include <iostream>
#include "GetInputDimensions.h"
#include "ErrorCheck.h"

using namespace std;

// Function called getRadius with return type of integer
// 
int getRadius()
{
	// Declare an integer variable, radius to 0
	//
	int radius = 0;

	// Prompt user to enter the radius of their cylinder then store value in "radius"
	//
	cout << "\nPlease enter the radius: ";
	cin >> radius;

	// Test if user entered invalid data and keep user in loop until
	// valid input is entered
	//
	while (cin.fail())
	{
		// Perform a call to the function errorCheck that will clear the "cin"
		//
		errorCheck();

		// Re-ask user to enter the radius
		//
		cout << "Please enter the radius: ";
		cin >> radius;
	}

	// Return the int variable radius
	//
	return radius;
}

// Function called getHeight with the return type of int
//
int getHeight()
{
	int height = 0;

	cout << "Please enter the height: ";
	cin >> height;

	while (cin.fail())
	{
		// Perform a call to the function errorCheck that will clear the "cin"
		//
		errorCheck();
		cout << "Please enter the height: ";
		cin >> height;
	}

	// Return the int variable height
	//
	return height;
}