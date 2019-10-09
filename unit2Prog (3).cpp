/***************************************************************************************
* Beatriz Mazati Anderson
* unit2Prog.cpp
* CS352 - Unit 2: Programming Assignment
*
* This program creates a definition for sumDigits Function. 
* Function will receive and return an integer.
*****************************************************************************************/

#include <iostream>   // including the standard C++ library iostream class (for cin, cout, etc.) (Unit 1 Lecture)
#include <string>     // including the standard C++ library string class (Unit 1 Lecture)

using namespace std; // using the C++ standard library 

int sumDigits(int integer);

int main() // Main Method
{
	// Declared two varibles - one to get input the the other one to receive it, so I can use pass-by-reference in step 2.
	int integerInput, integerReceived;

	// 1. Ask for input for numerous non-negative integers (used the output example phrasing in assignment description)
	cout << "Enter a nonnegative integer: " << endl;
	cin >> integerInput; // gets input

	// 2. Using pass-by-reference, pass integer received into recursive function called sumDigits.
	integerReceived = sumDigits(integerInput);

	// 3. Receive result back from sumDigits and output result to screen.
	cout << "The sum of the digits of " << integerInput << " is " << integerReceived << endl;

	// 4. Include: system("PAUSE"); after your output to pause the screen.
	system("PAUSE");

} // end Main Method

/*
sumDigits Function (Receives integer)
Recursively call sumDigits adding up the integers received.
Return result to main method for output.
If a single digit is received, just return it to the main method.
*/

int sumDigits(int integer) // sumDigits Function (Receives integer)
{
	int division = integer / 10;  // delcares variable and its operation
	cout << "entering sumDigits(" << integer << ")" << endl; // created this cout statement so I could troubleshoot program

    // checking if the integer divided by 10 equals 0
	if (integer / 10 == 0) {
		cout << "returning integer : " << integer << endl; // created this cout statement so I could troubleshoot program
		return integer;
	}
	// created to troubleshoot and know where I was at - it allowed me to visualize my calculation procedure step by step
	cout << "going to recurse .. returning " << integer % 10 << " + sumDigits(" << division << ")" << endl; 

	return integer % 10 + sumDigits(division); // return the sum to main method for output

} // end sumDigits Function (Receives integer)

// References
// Ford, W., &Topp, W. (2002).Data Structures with C++ Using STL.New Jersey : Prentice - Hall.
// Unit 2: Lecture - Object Design Techniques-2