#pragma once

#include "../Implementation/List.cpp"

#include <iostream>
#include <string>
#include <fstream>


using std::cout;
using std::endl;
using std::ofstream;


/** Linked List Class
	The lnked list class is the place to store the Employee Data, this is used to prevent the case of having identical data. This class has a strong connection to AVL Tree, they cannot be used without the other party.

	The data can be stored by using add method by passing in the name and accessed by using the getEmployee method. There are 3 employee getter:
	1. The getter which accept 1 parmeter, ID, which is used to retrieve the data of a single unique employee.
	2. The getter which accept 2 parameters, first name and last name, which is used to retrieve data by using name, this returns a list of multiple employees which share identical name.
	3. The getter which accept no parameter, which is used to retrieve all the employee data within the linked list and sort it in alphabetical order.

	The head and tail of this class can be accessed by using the head and tail getter respectively, The class also provide method such as displaying all of the content and write each data in the content into a file.
**/
class LinkedList {
	Employee *head { nullptr }; //Head of LinkedList
	Employee *tail { nullptr }; //Tail of LinkedList
	int size { 0 }; //The length of the list

	public:
		LinkedList *lPtr {nullptr}; //Left pointer
    		LinkedList *rPtr {nullptr}; //Right Pointer
    		int height { 1 }; //The Height Position of the Linked List in the AVL Tree

    		int add(Employee *employee); //Add employee into the linked list
    		Employee *getEmployee(ID *id); //Get an employee by ID
    		List *getEmployee(string firstName, string lastName); //Get employees by full name
    		List *getSortedList(); //Get sorted Employee list based on alpha order
    		Employee *getHead(); //Head getter
    		Employee *getTail(); //Tail getter
    		void display(); //Display the data in each node (Employee Object)
    		int write(ofstream &file); //Write the content of linked list to .txt file
};
