#include "../Header/LinkedList.hpp"

int LinkedList::add(Employee *employee) {
    if (this->head == nullptr) {
		this->head = employee;
		this->tail = this->head;
		this->head->getID()->setSequence(1);
		return 0;
	}

    employee->getID()->setSequence(tail->getID()->getSequence() + 1);

    this->tail->nextPtr = employee;
    employee->prevPtr = this->tail;
    this->tail = employee;
    return 0;
}


Employee *LinkedList::getEmployee(ID *id) {
    Employee *currentPtr { this->head };
    while (currentPtr) {
        if (!currentPtr->isDeactivated() && id->getSequence() == currentPtr->getID()->getSequence()) {
            return currentPtr;
        }

        currentPtr = currentPtr->nextPtr;
    }

    return nullptr;
}


List *LinkedList::getEmployee(string firstName, string lastName) {
    List *tempList { new List() };
    Employee *currentPtr { this->head };
    while (currentPtr) {
        if (!currentPtr->isDeactivated() && firstName == currentPtr->getFirstName() && lastName == currentPtr->getLastName()) {
            tempList->add(currentPtr);
        }

        currentPtr = currentPtr->nextPtr;
    }

    return tempList;
}


Employee *LinkedList::getHead() {
    return this->head;
}


Employee *LinkedList::getTail() {
    return this->tail;
}


void LinkedList::display() {
    Employee *currentPtr { this->head };
    while(currentPtr) {
        cout << currentPtr->getID()->toString() << " ";
        cout << currentPtr->getName() << " ";
        cout << endl;
        currentPtr = currentPtr->nextPtr;
    }
}
