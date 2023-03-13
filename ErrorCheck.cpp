#include <iostream>
#include "ErrorCheck.h"

using namespace std;

// Function of return type void with no needed parameters
//
void errorCheck()
{
	// Keep user in the loop if they entered any invalid input
	//
	if (cin.fail())
	{
		cout << "Invalid input\n";

		// Clear the input if the user enters invalid information
		//
		cin.clear();

		// Ignore all characters that have been entered by the user
		//
		cin.ignore();
	}
}