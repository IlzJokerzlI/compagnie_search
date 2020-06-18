#include "../Header/LinkedList.hpp"


//Add employee into the linked list
int LinkedList::add(Employee *employee) {
    //Checks if the head is still empty
    if (this->head == nullptr) {
        //Creates a new head
		this->head = employee;
		this->tail = this->head;
		this->size = 1; //Updates the size of linked list
		this->head->getID()->setSequence(this->size);
		return 0;
	}

    this->size += 1; //Updates the size of linked list
    employee->getID()->setSequence(this->size);

    //Extends the tail
    this->tail->nextPtr = employee;
    employee->prevPtr = this->tail;
    this->tail = employee;
    return 0;
}


//Get an employee by ID
Employee *LinkedList::getEmployee(ID *id) {
    Employee *currentPtr { this->head }; //Assign temporary pointer
    //Iterates through the linked list
    while (currentPtr) {
        //Checks for the similar ID
        if (id->getSequence() == currentPtr->getID()->getSequence()) {
            return currentPtr;
        }

        currentPtr = currentPtr->nextPtr;
    }

    return nullptr;
}


//Get employees by full name
List *LinkedList::getEmployee(string firstName, string lastName) {
    List *tempList { new List() }; //Assign temporary list pointer
    Employee *currentPtr { this->head }; //Assign temporary pointer
    //Iterates through the linked list
    while (currentPtr) {
        //Checks for avtivation status and the similarity of name
        if (!currentPtr->isDeactivated() && firstName == currentPtr->getFirstName() && lastName == currentPtr->getLastName()) {
            //Adds the the current node (Employee) to the temporary list
            tempList->add(currentPtr);
        }

        currentPtr = currentPtr->nextPtr;
    }

    return tempList;
}


//Get sorted Employee list based on alpha order
List *LinkedList::getSortedList() {
    Employee *currentPtr { this->getHead() }; //Assign temporary pointer
    List *list { new List() }; //Assign temporary list pointer
    //Iterates through the linked list
    while (currentPtr) {
        //Checks if the current node (Employee) is not deactivated
        if (!currentPtr->isDeactivated()) {
            //Adds the node (Employee) to the temporary list and sort it
            list->addSort(currentPtr);
        }
        currentPtr = currentPtr->nextPtr;
    }
    return list;
}


//Head getter
Employee *LinkedList::getHead() {
    return this->head;
}


//Tail getter
Employee *LinkedList::getTail() {
    return this->tail;
}


//Display the data in each node (Employee Object)
void LinkedList::display() {
    Employee *currentPtr { this->head }; //Assign temporary pointer
    //Iterates through the linked list
    while(currentPtr) {
        //Checks if the current node (Employee) is not deactivated
        if (!currentPtr->isDeactivated()) {
            cout << currentPtr->getID()->toString() << " ";
            cout << currentPtr->getName() << " ";
            cout << endl;
        }
        currentPtr = currentPtr->nextPtr;
    }
}


//Write the content of linked list to .txt file
int LinkedList::write(ofstream &file) {
    Employee *currentPtr { this->head }; //Assign temporary pointer
    //Iterates through the linked list
    while (currentPtr) {
        //Writes the data into file
        file << currentPtr->isDeactivated() << ",";
        file << currentPtr->getID()->toString() << ",";
        file << currentPtr->getFirstName() << ",";
        file << currentPtr->getLastName();
        file << endl;

        currentPtr = currentPtr->nextPtr;
    }
    return 0;
}
