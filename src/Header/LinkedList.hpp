#pragma once

#include "../Implementation/List.cpp"

class LinkedList {
	Employee *head { nullptr };
	Employee *tail { nullptr };
	int size { 0 };

	public:
		LinkedList *lPtr {nullptr};
    		LinkedList *rPtr {nullptr};
    		int height { 1 };

    		int add(Employee *employee);
    		Employee *getEmployee(ID *id);
    		List *getEmployee(string firstName, string lastName);
    		Employee *getHead();
    		Employee *getTail();
    		void display();
};
