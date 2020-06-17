#include "Header/HashTable.hpp"

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    HashTable hashTable = HashTable();
    hashTable.input("Arvin", "Lee");
    hashTable.input("Arvin", "Lee");
    hashTable.input("Arvin", "Ldf");
    // string id { "anle4001"};
    // cout << hashTable.getEmployee(id)->getFirstName() << endl;
    // List *result = hashTable.getEmployee("Arvin", "Lee");
    // result->display();

    hashTable.display();
    return 0;
}
