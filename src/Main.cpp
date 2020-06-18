#include "Header/HashTable.hpp"

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


void displayMenu() {
    cout << endl;
    cout << "COMPAGNIE SEARCH" << endl;
    cout << "================" << endl;
    cout << "[1] Read File" << endl;
    cout << "[2] Add" << endl;
    cout << "[3] Remove" << endl;
    cout << "[4] Find (ID)" << endl;
    cout << "[5] Find (Name)" << endl;
    cout << "[6] Display" << endl;
    cout << "[7] Display Sorted" << endl;
    cout << "[8] Write File" << endl;
    cout << "[0] Exit" << endl;
    cout << "================" << endl;
}


int main() {
    HashTable *hashTable { new HashTable() };
    while (true) {
        displayMenu();

        string option { "0" };
        string firstName { "" };
        string lastName { "" };
        string id { "" };
        string path { "" };
        cout << "Please choose option: ";
        cin >> option;
        cout << endl;

        if (option == "1") {
            cout << "[1] Read File" << endl;
            cout << "Path: ";
            cin >> path;

            delete hashTable;
            hashTable = new HashTable();
            int result { hashTable->read(path) };
            cout << "\n" << ((result == 0) ? "SUCCESSFULLY READ!" : "FILE NOT EXIST!") << "\n" <<  endl;

        } else if (option == "2") {
            cout << "[2] Add" << endl;
            cout << "First Name: ";
            cin >> firstName;

            cout << "Last Name: ";
            cin >> lastName;

            hashTable->input(firstName, lastName);
            cout << "\nNAME SUCCESSFULLY ADDED!\n" << endl;

        } else if (option == "3") {
            cout << "[3] Remove" << endl;
            cout << "ID: ";
            cin >> id;

            int result { hashTable->deactivate(id) };
            cout << "\n" << ((result == 0) ? "SUCCESSFULLY REMOVED!" : "FAILED TO REMOVE") << "\n" <<  endl;
        } else if (option == "4") {
            cout << "[4] Find (ID)" << endl;

            cout << "ID: ";
            cin >> id;

            Employee *employee { hashTable->getEmployee(id) };

            if (employee) {
                cout << endl;
                cout << employee->getID()->toString() << " : ";
                cout << employee->getName() << endl;
                cout << endl;
            } else {
                cout << "\nDATA NOT EXIST!\n" << endl;
            }


        } else if (option == "5") {
            cout << "[4] Find (Name)" << endl;

            cout << "First Name: ";
            cin >> firstName;

            cout << "Last Name: ";
            cin >> lastName;

            List *list { hashTable->getEmployee(firstName, lastName) };

            if (list) {
                cout << endl;
                list->display();
                cout << endl;
            } else {
                cout << "\nDATA NOT EXIST!\n" << endl;
            }
        } else if (option == "6") {
            cout << "[6] Display" << endl;
            hashTable->display();

        } else if (option == "7") {
            cout << "[6] Display Sorted" << endl;
            hashTable->displaySort();

        } else if (option == "8") {
            cout << "[8] Write File" << endl;
            cout << "Path: ";
            cin >> path;

            int result { hashTable->write(path) };
            cout << "\n" << ((result == 0) ? "SUCCESSFULLY WRITTEN!" : "FAILED TO WRITE!") << "\n" <<  endl;
        } else if (option == "0") {
            break;
        } else {
            cout << "\nINVALID OPTION!\n" << endl;
        }
    }
    return 0;
}
