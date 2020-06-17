#include "Employee.cpp"

#include <iostream>

using std::cout;
using std::endl;


//Node Struct
//Contained in List class
struct Node {
    Employee *value; //Contains the Employee Object
    Node *nextPtr { nullptr }; //Pointer points to next node

    //Constructor
    Node (Employee *value)
    : value(value) {}
};


/** List Class
    The list class is a temporary linked list created to contain Employee data temporarily. This class is far different for the Linked List class connected to AVL Tree, which used to store much permanent Employee data. The following list class offers much more methods than the other linked list as well as much flexible usage.
**/
class List {
    Node *head { nullptr }; //The head of the linked list
    Node *tail { nullptr }; //The tail of the linked list
    int size { 0 }; //The length of the linked list


    public:
        //Add Employee Object method
        void add(Employee *value) {
            if (this->head == nullptr) {
                //Creates head of linked list if it is empty
                this->head = new Node(value);
                this->tail = this->head;
            } else {
                //Adds the new input by putting it directly at the tail
                this->tail->nextPtr = new Node(value);
                this->tail = this->tail->nextPtr;
            }

            this->size += 1;
        }


        //Add Employee Object method and sorted
        void addSort(Employee *value) {
            if (value) {
                if (!this->head) {
                    //Creates head of linked list if it is empty
                    this->head = new Node(value);
                    this->tail = this->head;
                    this->size += 1;
                } else {
                    if (value->getName() < this->head->value->getName()) {
                        //If the input name value is smaller than the head's name value
                        Node *tempPtr { new Node(value) };
                        tempPtr->nextPtr = this->head;
                        this->head = tempPtr;
                        this->size += 1;
                    } else if (value->getName() >= this->tail->value->getName()) {
                        //If the input name value is bigger than the tail's name value
                        this->tail->nextPtr = new Node(value);
                        this->tail = this->tail->nextPtr;
                        this->size += 1;
                    } else {
                        //If the input name value is somewhere between the head's and tail's name value
                        Node *currentPtr { this->head->nextPtr };
                        Node *prevPtr { this->head };
                        while(currentPtr) {
                            if (value->getName() < currentPtr->value->getName()) {
                                Node *tempPtr = new Node(value);
                                tempPtr->nextPtr = currentPtr;
                                prevPtr->nextPtr = tempPtr;
                                this->size += 1;
                                break;
                            }
                            prevPtr = currentPtr;
                            currentPtr = currentPtr->nextPtr;
                        }
                    }
                }
            }
        }


        /** List Merger
            List merger merges 2 different lists into one list, which is the current object's list, not the one being input into the function. The function moves the pointers of inserted list in order to achieve efficiency by reducing copies. Although the current efficiency is not at its finest and has a downsides of input list destroyal. The merge function checks for input list's validity as well as implements merge sort through pointers manipulation.
        **/
        void merge(List *list) {
            //Conditions for valid type of list
            if (list && list->size > 0 && list != this) {
                //Creates new head if list is empty
                if (this->size == 0) {
                    this->head = list->getHead();
                    this->tail = list->getTail();
                    list->setHead(nullptr);
                    list->setTail(nullptr);
                    this->size = list->getSize();
                    return;
                }

                //Instantiate temporary pointers
                Node *currentLPtr { this->head };
                Node *currentRPtr { list->head };
                Node *prevLPtr { this->head };
                Node *prevRPtr { list->head };


                //Iterates while current left pointer and current right pointer are valid
                while (currentLPtr && currentRPtr) {
                    /**
                        The condition checks for the node with smaller name value. If the left node has smaller numbers, the pointer will moves to the next node until it meets a node with higher name value than the right node. If that happens, a change will be performed, the smaller right node will be inserted right before the compared node. In case there are some nodes left in the right list because they have bigger name value than the left list, they will be moved to the last part of left list and the last value will be assigned as the tail.
                    **/
                    if (currentLPtr->value->getName() < currentRPtr->value->getName()) {
                        prevLPtr = currentLPtr;
                        currentLPtr = currentLPtr->nextPtr;
                    } else {
                        if (currentLPtr == this->head) {
                            this->head = prevRPtr;
                        } else {
                            prevLPtr->nextPtr = prevRPtr;
                        }
                        currentRPtr = currentRPtr->nextPtr;
                        prevRPtr->nextPtr = currentLPtr;
                        prevLPtr = prevRPtr;
                        prevRPtr = currentRPtr;
                    }
                }

                //Moves the remaining right nodes to the left list and assign the last node as the tail
                if (currentRPtr) {
                    this->tail->nextPtr = currentRPtr;
                    this->tail = list->getTail();
                }

                list->setHead(nullptr); //Sets the input list head to point null pointer
                list->setTail(nullptr); //Sets the input list tail to point null pointer
                this->size += list->getSize(); //Changes the size of following list
            }
        }


        //Employee getter
        Employee *get(int index) {
            //Returns null pointer if index is greater than size of linked list
            if (index > this->size) {
                return nullptr;
            }

            Node *currentPtr { this->head }; //Sets the current pointer to head
            //Iterates until the desired index
            for (int i { 0 }; i < index; i++) {
                currentPtr = currentPtr->nextPtr;
            }

            return currentPtr->value;
        }


        //Head getter
        Node *getHead() {
            return this->head;
        }


        //Tail getter
        Node *getTail() {
            return this->tail;
        }


        //Head settter
        void setHead(Node *ptr) {
            this->head = ptr;
        }


        //Tail setter
        void setTail(Node *ptr) {
            this->tail = ptr;
        }


        //Size getter
        int getSize() {
            return this->size;
        }


        //Display every employee in the list
        void display() {
            Node *currentPtr { this->head }; //Sets the current pointer to head
            while(currentPtr) {
                //Iterate through the linked list
                cout << currentPtr->value->getID()->toString() << " : " << currentPtr->value->getName() << endl;
                currentPtr = currentPtr->nextPtr;
                }
        }
};
