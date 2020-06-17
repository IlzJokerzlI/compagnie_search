#pragma once

#include "../Implementation/List.cpp"

class LinkedList {
public:
	Employee *head { nullptr };
	Employee *tail { nullptr };

	public:
		LinkedList *lPtr {nullptr};
    		LinkedList *rPtr {nullptr};
    		int height { 1 };

    		int add(Employee *employee);
    		Employee *getEmployee(ID *id);
    		List *getEmployee(string firstName, string lastName);
    		Employee *getHead();
    		void display();
};
