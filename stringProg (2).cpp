/***************************************************************************************************
* Beatriz Mazati Anderson
* stringProg.cpp
* CS352 - Unit 1: Programming Assignment
*
* This program uses strings to receive input in a specific format and output in a different format
****************************************************************************************************/

#include <iostream>   // including the standard C++ library iostream class (for cin, cout, etc.) (Unit 1 Lecture)
#include <string>     // including the standard C++ library string class (Unit 1 Lecture)

using namespace std; // using the C++ standard library 

void inputData(string& myString); // Identifier
void outputData(string fullName); // Identifier

int main()           // Main Method
{
	string myString; // 1. Declare a string called myString.

	inputData(myString); // 2. Pass your string to a method called inputData();

	outputData(myString); // 3. pass your string to a method called outputData(); 

	return 0;        // return zero as the int main method is expected to return an integer data type

} // end Main Method

void inputData(string& myString)   // The inputData Method receives the string and uses Call-by-reference 
{
	// allows users to input their full name
	cout << "Enter your full name in the format of:\n Last, First Middle.\n" << endl;

	// 1. Get input into the string variable you received into this method
	// Had to use getline as cin >> by itself would only get the last name
	getline(cin, myString);

	// Using the string methods mentioned in this units lecture, have your program change the 
	// string to: First Middle Initial Last.

	// I would like you to break the string you received apart into 3 separate variables:
	// first, last, middle. (Hint: use find() to find the "," and spaces and usesubstr() to extract the pieces)

	int first, last, middle; // 3 separate variables

	int comma, stringLength; // so we can find the comma and the length of the user`s full name.

	comma = myString.find(",");       // use find() to find the comma in the input stored in myString

	// finds out the length of the user`s full name and meets requirements of using the following string methods 
	// (at least once): substr(),length(), find(), insert(), erase().
	stringLength = myString.length();

	first = myString.find(' ');    // finds the first space 

	middle = myString.find(' ', first + 1); // finds the middle name space

	last = myString.find(' ', middle + 1); // third space

	// first substring will contain Last Name (as the last name was input at first, before the comma)

	string firstArg = myString.substr(0, comma);

	firstArg.insert(0, " "); // adds a space instead of comma

	string secondArg = myString.substr(first + 1, (middle - first)); // substring for the first name

	// substring for the middle name - first argument is where to start in the string and the second is how many characters there should be
	string thirdArg = myString.substr(middle + 1, 1);

	// uses string concatenation to build the brand new string
	myString.insert(firstArg.length() + secondArg.length() + 1, " " + thirdArg.substr(0, 1));

	myString.erase(); // erasing the contents of previous string to properly arrange the new one in the correct order

	myString.append(secondArg); // appends the second Argument inputted by the user, which is the actual first name

	myString.append(thirdArg); // appends the third argument inputted by the user, which is the actual middle name

	myString.append("."); // appends a period to abbreviate the middle name initial

	myString.append(firstArg); // finally appends the last name

} // end inputData Method

void outputData(string fullName)     // The outputData Method receives the modified string and uses Call-by-value
{
	// Output the new string to the screen using cout <<
	cout << "When ordering the string, your full name is: " << endl;

	cout << fullName << endl;

	system("PAUSE"); // Include: system("PAUSE"); after your output to pause the screen.

} // end outputData Method

// References:
// Ford, W., & Topp, W.(2002). Data Structures with C++ Using STL. New Jersey:Prentice - Hall.
// Unit 1: Discussion
// Unit 1 : Lecture