#pragma once

#include "LinkedList.hpp"


#include <fstream>
#include <iostream>


using std::ofstream;
using std::endl;


class AVLTree {
	LinkedList *root { nullptr };

	int getHeight(LinkedList *linkedList); //Get the height position of linkedLists in the tree
	int getBalanceFactor(LinkedList *linkedList); //Get balance factor for linkedLists to determine their rotation
	LinkedList *rotateToR(LinkedList *linkedList); //Rotation for LL Imbalance
	LinkedList *rotateToLToR(LinkedList *linkedList); //Rotation for LR Imbalance
	LinkedList *rotateToL(LinkedList *linkedList); //Rotation for RR Imbalance
	LinkedList *rotateToRToL(LinkedList *linkedList); //Rotation for RL Imbalance
	LinkedList *insert(LinkedList *linkedList, Employee *employee); //Insert linkedList
	void inordDisp(LinkedList *linkedList);
	void inordSort(List *list, LinkedList *linkedList);
	void inordWrite(ofstream &file, LinkedList *linkedList);

	public:
		int insert(Employee *employee); //Insert linkedList for public
		Employee *getEmployee(ID *id); //Finds and Gets the Employee Object by using ID
		List *getEmployee(string firstName, string lastName, ID *id); //Finds and Gets the Employee Object by using name
		LinkedList *getRoot(); //Get the root linkedList of the tree uses
		int display();
		int displaySorted(List *list);
		int write(ofstream &file);
}; 
