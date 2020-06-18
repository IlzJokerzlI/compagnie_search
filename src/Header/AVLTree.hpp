#pragma once

#include "LinkedList.hpp"


#include <fstream>
#include <iostream>


using std::ofstream;
using std::endl;


/** AVL Tree Class
	The AVL Tree plays an important role in the data storing. Although it may looks complicated in inputting data and memory consuming, the AVL Tree is faster and more efficient when compared to a pure hash table and when it comes to massive amount of data. In other words, it is worth using when it comes to storing data up to ten thousands or even a million.
	The methods for inserting data takes up a big proportion of the class and it is too complicated to be explained in this documentation. The point is it stores the inputted data and maintains the balance of the tree. There are also other methods such as gets the employee data by using id and by using name. These two methods will be further explained in the Linked List documentation.
	There are 2 display methods in this class, the display method which is based on ID order and displaySorted method which is based on alphabetical order.
	The class also has write to file methods, it palys no important role in this class but simply passing data to each of the linked list and output the data to a file by using the method of the linked list.
**/
class AVLTree {
	LinkedList *root { nullptr }; //The root of the tree

	int getHeight(LinkedList *linkedList); //Get the height position of linkedLists in the tree
	int getBalanceFactor(LinkedList *linkedList); //Get balance factor for linkedLists to determine their rotation
	LinkedList *rotateToR(LinkedList *linkedList); //Rotation for LL Imbalance
	LinkedList *rotateToLToR(LinkedList *linkedList); //Rotation for LR Imbalance
	LinkedList *rotateToL(LinkedList *linkedList); //Rotation for RR Imbalance
	LinkedList *rotateToRToL(LinkedList *linkedList); //Rotation for RL Imbalance
	LinkedList *insert(LinkedList *linkedList, Employee *employee); //Insert linkedList
	void inordDisp(LinkedList *linkedList); //Display the nodes of the linked list in an Inorder manner
	void inordSort(List *list, LinkedList *linkedList); //Access the nodes of the linked list in an Inorder manner with alphabetical order
	void inordWrite(ofstream &file, LinkedList *linkedList); //Write the data contained in an Inorder manner

	public:
		int insert(Employee *employee); //Inserts linkedList for public
		Employee *getEmployee(ID *id); //Finds and Gets the Employee Object by using ID
		List *getEmployee(string firstName, string lastName, ID *id); //Finds and Gets the Employee Object by using name
		LinkedList *getRoot(); //Gets the root linkedList of the tree uses
		int display(); //Displays the file contained in the AVL Tree
		int displaySorted(List *list); //Displays the file contained in the AVL Tree sorted with an alphabetical order
		int write(ofstream &file); //Writes the data contained in the AVL Tree to a .txt file
}; 
