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
    hashTable.input("Arvin", "Lee");
    hashTable.input("Arvin", "Ldf");
    hashTable.input("Warren", "Anderson");
    hashTable.input("Lay", "Acheadeth");
    hashTable.input("Muhammad", "Naufaldi");
    // string id { "anle4003"};
    // cout << hashTable.getEmployee(id)->getFirstName() << endl;
    // List *result = hashTable.getEmployee("Muhammad", "Naufaldi");
    // result->display();

    hashTable.displaySort();
    return 0;
}
