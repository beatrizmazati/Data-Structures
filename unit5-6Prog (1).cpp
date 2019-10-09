/**************************************************************************************
* Beatriz Mazati Anderson
* unit5-6Prog.cpp
* This program uses a Stack and a Linked List.
***************************************************************************************/

#include <iostream>     // standard library for input/output 
#include <string>       // standard library for the string class

using namespace std;    // using the standard library

/* Create a structure called AddressNode
   The structure should contain a string for name and a pointer 
   called AddressNode that points to “next” (the next element in the list). */

struct AddressNode // structure called AddressNode
{
	string name; // a string for name
	AddressNode* next; // a pointer called AddressNode that points to “next”
}; // end struct AddressNode

class ABook // Create a class called ABook.
{
// 1. Create the Default Constructure. (public) 
// 2. Create the Deconstructor. (public)
public:        
	// including ABook Methods for following step:
	ABook(); // default constructor 
	void Insert(string NewItem); // Add item to the Linked List
	void SortedInsert(string NewItem); // Add item to the Linked List (sorted)
	void Remove(string& item); // Remove element from the top of the stack and return the item.
	~ABook(); // Deconstructor. Removes all elements from the list.

// 3. AddressNode* topPtr. (private) – Should be a pointer to the top of the list.
private: 
	AddressNode* topPtr; 

}; // end class aBook

/* ABook Methods (each of these methods must be created in your program)
   1. ABook::ABook() – Default Constructor
   2. ABook::Insert(string NewItem) – Add item to the Linked List
   3. ABook::SortedInsert(string NewItem) – Add item to the Linked List (sorted)
   4. ABook::Remove(string& item) – Remove element from the top of the stack and return the item.
   5. ABook::~ABook() – Deconstructor. Removes all elements from the list. */

// 1. ABook::ABook() – Default Constructor
ABook::ABook() // ABook::ABook() – Default Constructor
{
	topPtr = NULL; // empty list
} // end ABook::ABook() method


// 2. ABook::Insert(string NewItem) – Add item to the Linked List
void ABook::Insert(string NewItem)
{
	AddressNode* newNode = new AddressNode;  // creates a new item
	newNode->name = NewItem; // assign data, in this case a name, to the new item
	if (topPtr == NULL)      // if statement checks if topPtr is null
	{
		topPtr = newNode; // topPtr is a new node now
		newNode->next = NULL; // sets its next to NULL when the list is empty 
	} // end if
	else  // otherwise, it points to the next link and topPtr is a new node now
	{
		newNode->next = topPtr;
		topPtr = newNode;
	} // end else

} // end ABook::Insert method

// 3. ABook::SortedInsert(string NewItem) – Add item to the Linked List (sorted)
void ABook::SortedInsert(string NewItem)
{
	AddressNode* temp = topPtr;  // a pointer to the current node, temp
	AddressNode* delay = temp;   // pointer to previous one, delay

	AddressNode* newNode = new AddressNode; // creates a new item
	newNode->name = NewItem; // assign data, in this case a name, to the new item

	while (temp != NULL)  // while temp is not null
	{
		if (newNode->name < temp->name) // if the name to add is less the current name 
		{
			if (temp == topPtr) // if temp is topPtr
			{
				newNode->next = topPtr; // points to the next link
				topPtr = newNode;       // topPtr is a new node now
			} // end if (temp == topPtr)
			else 
			{
				newNode->next = temp; 
				delay->next = newNode; 
			} // end else
			return; //  to exit the function and not continue to the end 
		} // end if (newNode->name < temp->name) 
		delay = temp;  // previous node is now the current node
		temp = temp->next;
	} // end while

	delay-> next = newNode; // delay now points to the newNode
} // end ABook::SortedInsert method

// 4. ABook::Remove(string& item) – Remove element from the top of the stack and return the item.
void ABook::Remove(string& item)
{
	if (topPtr != NULL) // if topPtr is not null,
	{
		AddressNode* temp = topPtr;
		item = topPtr->name; // parameter item to remove 
		topPtr = topPtr->next; // topPtr point to its next to change the list and detach first node
		delete temp; // delete first node 
	} // end if
} // end  ABook::Remove method


// 5. ABook::~ABook() – Deconstructor. Removes all elements from the list.
ABook::~ABook()
{
	AddressNode* temp;
	// loop to delete all the nodes: loop from the beginning to the end of the list 
  while (topPtr != NULL) // test topPtr while it is not NULL
  {  
    temp = topPtr; //  temp to topPtr
    topPtr = topPtr-> next; // topPtr to its next 
    delete temp; //  delete temp 
    
  } // end while loop

} // end ABook::~ABook() method

// Main Method
int main()
{
	ABook Book;                  // 1. Declare new List
	string newName;              // 2. Declare new string newName.
	string nameToRemove;         // 3. Declare new string nameToRemove.
	Book.Insert("Precious");     // 4. Call Book.Insert(“Precious”); - Insert Precious into list.
	Book.SortedInsert("Ken");    // 5. Call Book.SortedInsert(“Ken”); - Insert Ken into listed (sorted)
	Book.SortedInsert("Eileen"); // 6. Call Book.SortedInsert(“Eileen”); - Insert Eileen into list (sorted)
	Book.SortedInsert("Frank");  // 7. Call Book.SortedInsert(“Frank”); - Insert Frank into list (sorted)

	// To mimic "Sorted List: " output from assignment description:
	cout << "Sorted List: " << endl;

	// 8. Use Book.Remove to remove each name one at a time and display to screen.
	// If names need to be removed one at a time, it is necessary to use a loop.
	for (int i = 0; i < 4; i++)
	{
		Book.Remove(nameToRemove);  // Use Book.Remove to remove each name while looping
		cout << nameToRemove << endl; // displays the nameToRemove to screen.
	} // end for loop

	// Include: system("PAUSE"); after your output to pause the screen.
	system("PAUSE");

	return 0;
} // end main method

/* References:
Ford, W., & Topp, W. (2002). Data Structures with C++ Using STL. New Jersey: Prentice - Hall.
*/
