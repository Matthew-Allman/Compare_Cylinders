#include "ComputerScieneProject1.h"
#include <string>
#include <iostream>
#include "ErrorCheck.h"
#include "GetInputDimensions.h"

using namespace std;

// Declaration of function prototypes
//
void cylinderOutput(int radius, int height, double totalSurfaceAreaArr, double lateralSurfaceAreaArr, double volumeArr);
void compareCylinder(double totalSurfaceAreaArr[], double lateralSurfaceAreaArr[], double volumeArr[]);

int main()
{
	// Declare int variables userDecision that will later be used to 
	// obtain the actions the user wishes to perform
	//
	int userDecision  = 0;
	int userDecision1 = 0;

	// Declare two integer arrays initialized to two elements each that will store the radius and heights  
	// of the cylinder(s)
	//
	int radiusArr[2] = { 0 };
	int heightArr[2] = { 0 };

	// Declare 3 arrays with datatype double, initialized to two elements each
	// that will be used to store the values of the cylinder(s)
	//
	double lateralSurfaceAreaArr[2] = { 0 };
	double totalSurfaceAreaArr[2]   = { 0 };
	double volumeArr[2]             = { 0 };

	// Declare two boolean variables, set to false
	//
	bool exitFlag  = false;
	bool exitFlag2 = false;

	// Prompt user to enter which action they wish to perform.
	// Store values into userDecision
	//
	cout << "What would you like to do today? \nPlease type the number corresponding to the choice!\n";
	cout << "\n1) Calculate the dimensions of one right-circular cylinder.\n2) Compare two right-circular cylinders.\n3) Terminate program.\n";
	cin >> userDecision;

	// Call function errorCheck and correct any invalid input if entered by user
	//
	errorCheck();

	// Enter "while" loop only if the boolean variable exitFlag is set to false.
	// Keep user in while loop until condition tests to false
	//
	while (!exitFlag)
	{
		// Switch statement on the variable userDecision
		//
		switch (userDecision)
		{
			// Execute this case block if userDecision = 1
			//
			case 1:
			{
				// Make calls to the functions getRadius and getHeight then store
				// the returned data into the 1st element of their respective arrays
				//
				radiusArr[0] = getRadius();
				heightArr[0] = getHeight();
				
				// Create an object of the ComputerScieneProject1 class and pass as parameter
				// the first element of the radius and height arrays to the constructor of this class
				//
				ComputerScienceProject1 cylinderObj(radiusArr[0], heightArr[0]);

				// Make calls to the functions in the ComputerScieneProject1 class using the previously created object.
				// Store the returned values into the 1st element of the surface areas and volume arrays
				//
				lateralSurfaceAreaArr[0] = cylinderObj.LateralSurfaceArea();
				totalSurfaceAreaArr[0]   = cylinderObj.totalSurfaceArea();
				volumeArr[0]			 = cylinderObj.totalVolume();
				
				// Set the boolean variable to false.
				// Allow the user to re-enter the while loop after a full run-throough of the program, 
				// so that the user does not need to re-execute the program 
				// if they wish to enter different values or try different options
				//
				exitFlag2 = false;

				// Keep user in the while loop until the condition tests false.
				// Allow the re-enter input in case they enter invalid input 
				// without having to restart the entire program
				//
				while (!exitFlag2)
				{
					// Ask user what they wish to be calculated and displayed.
					// Store the information into userDecision1
					//
					cout << "\n\nWould you like:\n1) The Total Surface Area\n2) The Lateral Surface Area\n3) The volume\n4) All\n";
					cin >> userDecision1;

					// Test and clear invalid input
					//
					errorCheck();

					// Switch statement on userDecision1
					//
					switch (userDecision1)
					{
						// Execute if userDecision1 = 0
						//
						case 1:
						{
							// Output the total surface area of the cylinder and
							// display the radius and height entered by user
							//
							cout << "The total surface area of the right-circular cylinder with radius: "
								<< radiusArr[0] << " and height: " << heightArr[0] << " is: " << totalSurfaceAreaArr[0];

							// Set exitFlag2 to true to exit the while loop
							//
							exitFlag2 = true;

							// End this case block and the switch statement
							//
							break;
						}

						// Execute this block if userDecision1 = 2
						//
						case 2:
						{
							// Output the lateral surface area and dimensions of the cylinder
							//
							cout << "The lateral surface area of the right-circular cylinder with radius: "
								<< radiusArr[0] << " and height: " << heightArr[0] << " is:: " << lateralSurfaceAreaArr[0];
							exitFlag2 = true;
							break;
						}

						// Execute this block if user entered 3
						//
						case 3:
						{
							// Output the volume of the cylinder
							//
							cout << "The volume of the right-circular cylinder with radius: "
								<< radiusArr[0] << " and height: " << heightArr[0] << " is: " << volumeArr[0];
							exitFlag2 = true;
							break;
						}

						// Execute if user entered 4
						//
						case 4:
						{
							// Make a call to the function cylinderOutput and 
							// pass the 1st element of 5 arrays as parameters
							//
							cylinderOutput(radiusArr[0], heightArr[0], totalSurfaceAreaArr[0], lateralSurfaceAreaArr[0], volumeArr[0]);
							exitFlag2 = true;
							break;
						}

						// Execute the default case if user entered any values other than the specified values
						//
						default:
						{
							// Set userDecision1 to 0 so the user can attempt to enter another value
							// as their choice
							//
							userDecision1 = 0;
							cout << "Invalid Input\n";
						}
					}
				}
				
				// Set userDecision to 0 so the program will continue running until the user wishes for it to stop.
				// Test userDecision with the initial switch statement, this will result in the "default" case
				// which will ask user to enter their decision again - keeping them in the loop
				//
				userDecision = 0;

				// End this case block and the switch statement
				//
				break;
			}

			// Execute this block of code if userDecision = 2
			//
			case 2:
			{
				// Basic for loop that will loop twice
				//
				for (int i = 0; i < 2; i++)
				{
					cout << "For cylinder " << (i + 1)  << ":\n";

					// Call the dimension functions and store the values into their respective 
					// arrays, indexed to the variable i that will increment by 1 with each execution of the "for" loop
					//
					radiusArr[i] = getRadius();
					heightArr[i] = getHeight();
				}
				
				// Declare an object array with two elements of the ComputerScieneProject1 class.
				// Pass the dimension arrays as the constructor variables
				//
				ComputerScienceProject1 cylinderObj1[2] = { ComputerScienceProject1(radiusArr[0], heightArr[0]),
														   ComputerScienceProject1(radiusArr[1], heightArr[1]) };

				for (int i = 0; i < 2; i++)
				{
					// Call functions and store their returned values into elements of 3 arrays
					//
					lateralSurfaceAreaArr[i] = cylinderObj1[i].LateralSurfaceArea();
					totalSurfaceAreaArr[i]	 = cylinderObj1[i].totalSurfaceArea();
					volumeArr[i]	         = cylinderObj1[i].totalVolume();
				}

				for (int i = 0; i < 2; i++)
				{
					// Call the cylinderOutput function 
					//
					cout << "\nCylinder " << (i + 1) << ":\n";
					cylinderOutput(radiusArr[i], heightArr[i], totalSurfaceAreaArr[i], lateralSurfaceAreaArr[i], volumeArr[i]);
				}

				// Call the compare function and output the differenced between cylinders
				//
				compareCylinder(totalSurfaceAreaArr, lateralSurfaceAreaArr, volumeArr);

				// Set userDecision to 0 to restart the loop
				//
				userDecision = 0;

				// End the switch statement
				//
				break;
			}

			// Execute if userDecision = 3
			//
			case 3:
			{
				cout << "Goodbye";

				// Set exitFlag to 0 to exit the initial while loop and end the program
				//
				exitFlag = true;
				break;
			}

			// Execute the default case if user entered any values other than the specified values
			//
			default:
			{
				// Ask user what options they want to execute then store into userDecision variable
				//
				cout << "\nPlease enter a number between 1 and 3 inclusively\n"
					 << "1) Calculate the dimensions of one right-circular cylinder.\n"
					 << "2) Compare two right-circular cylinders.\n3) Terminate program.\n";

				cin >> userDecision;
				errorCheck();
				break;
			}
		}
	}
}

// Function of return type void with 5 parameters, radius, height, etc.
// Output the dimensions, calculated areas, and volumes of the user-inputted cylinder(s).
//
void cylinderOutput(int radius, int height, double totalSurfaceAreaArr, double lateralSurfaceAreaArr, double volumeArr)
{
	cout << "\nThe radius is              : " << radius 
		 << "\nThe height is              : " << height 
		 << "\nThe total surface area is  : " << totalSurfaceAreaArr
		 << "\nThe lateral surface area is: " << lateralSurfaceAreaArr
		 << "\nThe volume is              : " << volumeArr 
		 << "\n";
}

// Function of return type void with 3 array parameters.
// Compare the areas and volumes of the cylinders and display the difference between the values.
//
void compareCylinder(double totalSurfaceAreaArr[], double lateralSurfaceAreaArr[], double volumeArr[])
{
	// Test which cylinder has the largest surface area then display the difference.
	// 
	if (totalSurfaceAreaArr[0] > totalSurfaceAreaArr[1])
	{
		cout << "\nThe surface area of cylinder 1 is larger by: " << totalSurfaceAreaArr[0] - totalSurfaceAreaArr[1];
	}
	else if (totalSurfaceAreaArr[0] < totalSurfaceAreaArr[1])
	{
		cout << "\nThe surface area of cylinder 2 is larger by: " << totalSurfaceAreaArr[1] - totalSurfaceAreaArr[0];
	}
	else
	{
		cout << "\nThe surface area of the cylinders are equal";
	}

	// Test which cylinder has the largest lateral surface area then display the difference.
	// 
	if (lateralSurfaceAreaArr[0] > lateralSurfaceAreaArr[1])
	{
		cout << "\nThe lateral surface area of cylinder 1 is larger by: " << lateralSurfaceAreaArr[0] - lateralSurfaceAreaArr[1];
	}
	else if (lateralSurfaceAreaArr[0] < lateralSurfaceAreaArr[1])
	{
		cout << "\nThe lateral surface area of cylinder 2 is larger by: " << lateralSurfaceAreaArr[1] - lateralSurfaceAreaArr[0];
	}
	else
	{
		cout << "\nThe lateral surface area of the cylinders are equal";
	}

	// Test which cylinder has the largest volume then display the difference.
	// 
	if (volumeArr[0] > volumeArr[1])
	{
		cout << "\nThe volumes of cylinder 1 is larger by: " << volumeArr[0] - volumeArr[1] << "\n";
	}
	else if (volumeArr[0] < volumeArr[1])
	{
		cout << "\nThe volumes of cylinder 2 is larger by: " << volumeArr[1] - volumeArr[0] << "\n";
	}
	else
	{
		cout << "\nThe volumes of the cylinders are equal" << "\n";
	}
}