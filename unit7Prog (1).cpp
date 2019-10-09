/******************************************************************************************
* Beatriz Mazati Anderson
* unit7Prog.cpp
*
* This program uses Trees and Binary Search Trees. The Binary Search Tree will accept
* integers in a specifc order. The user is asked to input a number, and if the number they
* input is not in between the specific numbers in the tree, it returns false. If the number
* is in the tree, it returns true.
*******************************************************************************************/
#include <iostream> 

using namespace std; // uses the standard library 

struct tree_struct // created a structure for binary tree, variable for data and the left and right subtrees
{
	int data; // variable for data in the tree
	tree_struct* leftSubtree;
	tree_struct* rightSubtree;
}; //end struct tree_struct


// Insert and searchFunc methods here
tree_struct* insert(tree_struct* root, int key); // points to the root to start
bool searchFunc(tree_struct* tree, int key); // to search the tree

// Main Method
int main()
{
	// 1. Create Binary Search Tree that will accept integers in this order: 35, 18, 48, 72, 60, 25
	// 2. Refer to page 537 Example 10-8 for example code.
	int arr[] = { 35, 18, 48, 72, 60, 25 };
	int integer; // variable to store the user input
	tree_struct* tree = NULL; // indicates the tree is null so we can add the values
	tree = insert(tree, 35);  // uses insert method to enter integer 35 in the tree  
	tree = insert(tree, 18);  // uses insert method to enter integer 18 in the tree 
	tree = insert(tree, 48);  // uses insert method to enter integer 48 in the tree 
	tree = insert(tree, 72);  // uses insert method to enter integer 72 in the tree  
	tree = insert(tree, 60);  // uses insert method to enter integer 60 in the tree  
	tree = insert(tree, 25);  // uses insert method to enter integer 25 in the tree 

	// 3. Ask user for input and search tree utilizing integer input.
	cout << "Enter Integer to search for : ";
	cin >> integer;   // passes the value to the variable

	// 4. Return “True” if integer is found or “False” if number is not found in tree.
	if (searchFunc(tree, integer))
	{
		cout << "True" << endl;
	} // end if
	else
	{
		cout << "False" << endl;
	} // end else

	// Do it again to mimic output in the assignment description
	cout << "Enter Integer to search for : ";
	cin >> integer;   // passes the value to the variable

	// 4. Return “True” if integer is found or “False” if number is not found in tree.
	if (searchFunc(tree, integer))
	{
		cout << "True" << endl;
	} // end if
	else
	{
		cout << "False" << endl;
	} // end else

	// Include: system("PAUSE"); after your output to pause the screen.
	system("pause");

	return 0;

} // end main method

// Insert method
tree_struct* insert(tree_struct* root, int key)
{

	if (root == NULL) // first case - using recursion
	{
		tree_struct* newNode = new tree_struct();
		newNode->data = key; // set the data of new node to the parameter key
		newNode->leftSubtree = NULL;
		newNode->rightSubtree = NULL;
		return newNode; // return new node as new tree
	}
	else if (root->data > key) // if the data value is greater than the key
	{
		// attaches the new left subtree to the root's left subtree
		root->leftSubtree = insert(root->leftSubtree, key); 
		return root;
	}
	else
	{
		// attaches the new right subtree to the root's right subtree
		root->rightSubtree = insert(root->rightSubtree, key);
		return root;
	}
} // end insert method

// search method 
bool searchFunc(tree_struct* tree, int key)
{
	if (tree == NULL) // 1st case base
	{
		return false;
	}
	if (tree->data == key)  // if the data in the tree is the same as the keys inserted, return true
	{
		return true;
	}
	else if (tree->data > key) // if the data is greater than the key
	{
		return searchFunc(tree->leftSubtree, key); // call recursive function to explore left subtree
	}
	else
	{
		return searchFunc(tree->rightSubtree, key); // recursive call to search in the right subtree
	}

} // end search method