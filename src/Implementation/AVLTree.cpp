#include "../Header/AVLTree.hpp"

//Gets the height of a linkedList
int AVLTree::getHeight(LinkedList *linkedList) {
    int lHeight = (linkedList && linkedList->lPtr) ? linkedList->lPtr->height : 0;
    int rHeight = (linkedList && linkedList->rPtr) ? linkedList->rPtr->height : 0;
    return (lHeight > rHeight) ? lHeight + 1 : rHeight + 1;
}


//Get the balance factor for determining rotation action
int AVLTree::getBalanceFactor(LinkedList *linkedList) {
    int lHeight = (linkedList && linkedList->lPtr) ? linkedList->lPtr->height : 0;
    int rHeight = (linkedList && linkedList->rPtr) ? linkedList->rPtr->height : 0;
    return lHeight - rHeight;
}


//Performs linkedList rotation To Right (LL Imbalance)
LinkedList *AVLTree::rotateToR(LinkedList *linkedList) {
    //Sets the position of linkedLists
    LinkedList *temp = linkedList->lPtr;
    linkedList->lPtr = temp->rPtr;
    temp->rPtr = linkedList;

    //Updates the height of swaped linkedLists
    linkedList->height = this->getHeight(linkedList);
    temp->height = this->getHeight(temp);

    //Updates the root if the position of previous root swapped
    if (linkedList == this->root) {
        this->root = temp;
    }

    return temp;
}


//Performs linkedList rotation To Left then To Right (LR Imbalance)
LinkedList *AVLTree::rotateToLToR(LinkedList *linkedList) {
    //Sets the position of linkedLists
    LinkedList *temp = linkedList->lPtr->rPtr;
    linkedList->lPtr->rPtr = temp->lPtr;
    temp->lPtr = linkedList->lPtr;
    linkedList->lPtr = temp->rPtr;
    temp->rPtr = linkedList;

    //Updates the height of swaped linkedLists
    linkedList->height = this->getHeight(linkedList);
    temp->height = this->getHeight(linkedList);
    temp->lPtr->height = this->getHeight(temp->lPtr);

    //Updates the root if the position of previous root swapped
    if (linkedList == this->root) {
        this->root = temp;
    }

    return temp;

}


//Perform linkedList rotation To Left (RR Imbalance)
LinkedList *AVLTree::rotateToL(LinkedList *linkedList) {
    //Sets the position of linkedLists
    LinkedList *temp = linkedList->rPtr;
    linkedList->rPtr = temp->rPtr;
    temp->lPtr = linkedList;

    //Updates the height of swaped linkedLists
    linkedList->height = this->getHeight(linkedList);
    temp->height = this->getHeight(temp);

    //Updates the root if the position of previous root swapped
    if (linkedList == this->root) {
        this->root = temp;
    }

    return temp;
}


//Performs linkedList rotation To Right then To Left (RL Imbalance)
LinkedList *AVLTree::rotateToRToL(LinkedList *linkedList) {
    //Sets the position of linkedLists
    LinkedList *temp = linkedList->rPtr->lPtr;
    linkedList->rPtr->lPtr = temp->rPtr;
    temp->rPtr = linkedList->rPtr;
    linkedList->rPtr = temp->lPtr;
    temp->lPtr = linkedList;

    //Updates the height of swaped linkedLists
    linkedList->height = this->getHeight(linkedList);
    temp->height = this->getHeight(linkedList);
    temp->rPtr->height = this->getHeight(temp->rPtr);

    //Updates the root if the position of previous root swapped
    if (linkedList == this->root) {
        this->root = temp;
    }

    return temp;
}


//Inserts employee to tree
LinkedList *AVLTree::insert(LinkedList *linkedList, Employee *employee) {
    //Set the root if none presents in the tree
    if (this->root == nullptr) {
        this->root = new LinkedList();
        this->root->add(employee);

        return this->root;
    }

    //Create new linkedList at the leaf of the tree
    if (linkedList == nullptr) {
        linkedList = new LinkedList();
        linkedList->add(employee);
        return linkedList;
    }

    //Get to the leaf of the tree
    if (employee->getID()->getCode() < linkedList->getHead()->getID()->getCode()) {
        //Put left if employee is smaller
        linkedList->lPtr = insert(linkedList->lPtr, employee);
    } else if (employee->getID()->getCode() > linkedList->getHead()->getID()->getCode()) {
        //Put right if employee is bigger
        linkedList->rPtr = insert(linkedList->rPtr, employee);
    } else {
        //Put to linked list if employee is equal
        linkedList->add(employee);
    }

    //Update the height of the linkedLists traversed by the new employee
    linkedList->height = this->getHeight(linkedList);

    //Check which rotation to take
    if (this->getBalanceFactor(linkedList) == 2 && this->getBalanceFactor(linkedList->lPtr) == 1) {
        //LL Imbalance
        return this->rotateToR(linkedList);
    } else if (this->getBalanceFactor(linkedList) == 2 && this->getBalanceFactor(linkedList->lPtr) == -1) {
        //LR Imbalance
        return this->rotateToLToR(linkedList);
    } else if (this->getBalanceFactor(linkedList) == -2 && this->getBalanceFactor(linkedList->rPtr) == -1) {
        //RR Imbalance
        return this->rotateToL(linkedList);
    } else if (this->getBalanceFactor(linkedList) == -2 && this->getBalanceFactor(linkedList->rPtr) == 1) {
        //RL Imbalance
        return this->rotateToRToL(linkedList);
    }

    return linkedList;
}


//Display the nodes of the linked list in an Inorder manner
void AVLTree::inordDisp(LinkedList *linkedList) {
    if (linkedList) {
        this->inordDisp(linkedList->lPtr);
        linkedList->display();
        this->inordDisp(linkedList->rPtr);
    }
}


//Access the nodes of the linked list in an Inorder manner with alphabetical order
void AVLTree::inordSort(List *list, LinkedList *linkedList) {
    if (linkedList) {
        this->inordSort(list, linkedList->lPtr);
        list->merge(linkedList->getSortedList());
        this->inordSort(list, linkedList->rPtr);
    }
}


//Write the data contained in an Inorder manner
void AVLTree::inordWrite(ofstream &file, LinkedList *linkedList) {
    if (linkedList) {
        this->inordWrite(file, linkedList->lPtr);
        linkedList->write(file);
        this->inordWrite(file, linkedList->rPtr);
    }
}


//Public Methods

//Inserts employee to tree
int AVLTree::insert(Employee *employee) {
    //Try-Catch error from insert function
    try {
        this->insert(this->getRoot(), employee);
    } catch (...) {
        return -1;
    }

    return 0;
}


//Finds and Gets the Employee by using ID
Employee *AVLTree::getEmployee(ID *id) {
    LinkedList *currentPtr { this->root };
    while (currentPtr) {
        if (id->getCode() < currentPtr->getHead()->getID()->getCode()) {
            currentPtr = currentPtr->lPtr;
        } else if (id->getCode() > currentPtr->getHead()->getID()->getCode()) {
            currentPtr = currentPtr->rPtr;
        } else {
            return currentPtr->getEmployee(id);
        }
    }

    return nullptr;
}


//Finds and Gets the Employee by using name
List *AVLTree::getEmployee(string firstName, string lastName, ID *id) {
    LinkedList *currentPtr { this->root };
    while (currentPtr) {
        if (id->getCode() < currentPtr->getHead()->getID()->getCode()) {
            currentPtr = currentPtr->lPtr;
        } else if (id->getCode() > currentPtr->getHead()->getID()->getCode()) {
            currentPtr = currentPtr->rPtr;
        } else {
            return currentPtr->getEmployee(firstName, lastName);
        }
    }

    return nullptr;
}


//Gets the root of the tree
LinkedList *AVLTree::getRoot() {
    return this->root;
}


//Displays the file contained in the AVL Tree
int AVLTree::display() {
    //Checks if root exists
    if (this->root) {
        this->inordDisp(this->root);
        return 0;
    }
    return -1;
}


//Displays the file contained in the AVL Tree sorted with an alphabetical order
int AVLTree::displaySorted(List *list) {
    //Checks if root exists
    if (this->root) {
        this->inordSort(list, this->root);
        return 0;
    }

    return -1;
}

//Writes the data contained in the AVL Tree to a .txt file
int AVLTree::write(ofstream &file) {
    //Checks if root exists
    if (this->root) {
        this->inordWrite(file, this->root);
        return 0;
    }
    return -1;
}
