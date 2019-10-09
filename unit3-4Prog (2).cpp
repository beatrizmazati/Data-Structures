/********************************************************************************************************************
* Beatriz Mazati Anderson
* CS352 - Park University
* unit3-4Prog.cpp
*
* This program will store in miniVector v a list of 15 random integers from 0 to 99, then it will output the vector, 
* sort the vector, then output it again sorted. The miniVector class is on page 250.
*********************************************************************************************************************/

#include <iostream> // standard library for input/output 
#include <vector> //  standard library for the vector class

/* includes the vector header file obtained in the assignment description. Note that d_except.h was added to
*  my header as well to solve error on vector header file (as the except header file was included in it) */
#include "d_vector.h" 
#include "d_random.h" // includes the random header file obtained in the assignment description

using namespace std;  // standard library

/* 
Program Definition
1. Create program definition with the following templates and methods:

// output miniVector v
template <typename T>
void writeMiniVector(const miniVector<T>& v); 
*/

template <typename T>  
void writeMiniVector(const miniVector<T>& v);
/* 
// use insertion sort to place miniVector v in descending order
template <typename T>
void sortMiniVector(miniVector<T>& v); */

template <typename T> 
void sortMiniVector(miniVector<T>& v);


int main() // Main Method
{
  // 1. Declare: miniVector<int> v;
	miniVector<int> v;
  // 2. Declare: randomNumber rnd;
	randomNumber rnd;
  // for loop with integer j, to start from 0, be less than 15 (as it starts at position 0) and increments by 1 
	for (int j = 0; j < 15; ++j) 
	{
		// 3. call v.push_back(rnd.random(100)); to push 15 entries from 0-99 onto the vector
		v.push_back(rnd.random(100));
	} // end loop
	// To mimic the sample output in the assignment description, I am outputting "Original:"
	cout << "Original: ";
	// 4. call writeMiniVector to output vector
	 writeMiniVector(v);
	// 5. call sortMiniVector to sort the vector
	 sortMiniVector(v);
    // Mimics sample output and prints "Sorted: "
	 cout << "Sorted: ";
	// 6. call writeMiniVector to output the sorted vector.
	 writeMiniVector(v);

	 /*After you output the sorted vector:
       Include: system("PAUSE"); after your output to pause the screen.*/

	 system("PAUSE");

	 return 0;

} // end Main Method

/* writeMiniVector Method(const miniVector<T>& v)
1. Iterate through the vector v and output each element to the screen.*/

template <typename T>

void writeMiniVector(const miniVector<T>& v) // writeMiniVector Method(const miniVector<T>& v)
{
	for (int j = 0; j < v.size(); ++j) //iterate through the vector v
	{
		cout << v[j] << " ";  // and output each element to the screen 
	} // end loop

	cout << endl; // to end the line and mimic the sample output

} // end writeMiniVector Method

/* sortMiniVector Method (miniVector<T>& v)
1. Sort the elements of vector v.
2. Since it is passed-by-reference, no return is necessary.*/

template <typename T>
void sortMiniVector(miniVector<T>& v) // sortMiniVector Method
{
	//  declared a temporary variable of type T to save v[i-1]
	T temp;

	// using bubble sort
	/* nested loops: this loop repeats the same process of the loop inside of it, but size - 1 times
	   or until the array is sorted */
	for (int j = 0; j < v.size() - 1; ++j)
	{
		// loop over the vector to compare 2 adjacent elements
		/* -j so the loop is more efficient and saves time as it does not analyze the element from 
		* the last iteration.*/
		for (int i = 1; i < v.size() - j; ++i)
		{
			// test if the value at index i-1 is greater that the value at index i
			if (v[i - 1] > v[i])
			{
				// if the condition is true, swap the values in these locations i-1 and i
				// use temporary variable of type T to save v[i-1] into temp (as declared earlier in this method)
				temp = v[i - 1]; 
				v[i - 1] = v[i]; // copy v[i] inside v[i-1] 
				v[i] = temp;  // value of temp (original value of v[i-1]) inside v[i] (location is found)
			} // end if

		} // end for


	} // end for



} // end sortMiniVector Method