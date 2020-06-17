#include "Employee.cpp"

#include <iostream>

using std::cout;
using std::endl;

struct Node {
    Employee *value;
    Node *nextPtr { nullptr };

    Node (Employee *value)
    : value(value) {}
};


class List {
    Node *head { nullptr };
    Node *tail { nullptr };
    int size { 0 };

    public:
        void add(Employee *value) {
            if (this->head == nullptr) {
                this->head = new Node(value);
                this->tail = this->head;
            } else {
                this->tail->nextPtr = new Node(value);
                this->tail = this->tail->nextPtr;
            }

            this->size += 1;
        }

        Employee *get(int index) {
            if (index > this->size) {
                return nullptr;
            }

            Node *currentPtr { this->head };
            for (int i { 0 }; i < index; i++) {
                currentPtr = currentPtr->nextPtr;
            }

            return currentPtr->value;
        }

        void display() {
            Node *currentPtr { this->head };
            while(currentPtr) {
                cout << currentPtr->value->getID()->toString() << " : " << currentPtr->value->getName() << endl;
                currentPtr = currentPtr->nextPtr;
                }
        }
};
