#include "../Header/HashTable.hpp"


/** Converts string to lower case
    Converts every name input to lower case, be it first name or last name to achieve consistency as well as to prevent accindental upper case input.
**/
void HashTable::toLower(string &name) {
	for_each(name.begin(), name.end(), [](char &character) {
		character = tolower(character);
	});
}


/** Checks the stored Employee Object location in hashtable from given ID
    The location for the first dimension table is the 4th index of ID and  the second dimension table is the 5th index of ID, these index will be extracted and converted to int before put into loc array and returned.

**/
int *HashTable::getLoc(ID *id) {
    int *loc { new int[2] };

    loc[0] = id->getCode()[4] - '0';
    loc[1] = id->getCode()[5] - '0';

    return loc;
}



/** Checks the validity of an id
    The id checked is in the form of string, which is an input from the user in order to find information of a particular employee. This function will check for the size which is supposed to be exactly 8 characters, the character type which is supposed to be alphabet from index 0 to 3 and integer from index 4 to 7, and the sequence of the id (last 2 digits) which is not supposed to be "00".
**/
bool HashTable::check_ID(string &id) {
    //Checks size
    if (id.size() != 8) {
        return false;
    }

    //Checks alphabet type
    for (int i { 0 }; i < 8; i++) {
        if (i < 4) {
            if (!isalpha(id[i])) {
                return false;
            }
        } else if (i < 8) {
            if (!isdigit(id[i])) {
                return false;
            }
        }
    }

    //Checks sequence (last 2 digits)
    if (id[6] == '0' && id[7] == '0') {
        return false;
    }

    return true;
}




//Public methods
HashTable::HashTable() {
	AVLTree **tempAVL { new AVLTree*[this->n] };
	for (int i { 0 }; i < this->n; i++) {
	    tempAVL[i] = new AVLTree[this->n];
	    for (int j {0}; j < this->n; j++) {
            tempAVL[i][j] = AVLTree();
	    }
	}
	this->table = tempAVL;
}


int HashTable::input(string firstName, string lastName) {
    this->toLower(firstName);
    this->toLower(lastName);

    ID *tempID { new ID(firstName, lastName) };
    Employee *tempEmployee { new Employee(firstName, lastName, tempID) };
    int *loc = this->getLoc(tempID);

    this->table[loc[0]][loc[1]].insert(tempEmployee);
    return 0;
}


/** Get Employee object stored in the system
    The function returns a pointer of employee object which stores informations of a certain employee. The function needs to check the id validity (using check_ID() method) before search thourght it otherwise there is a possibility of error occuring.
**/
Employee *HashTable::getEmployee(string id) {
    //Checks for the validity of the user input id
    if (!this->check_ID(id)) {
        return nullptr;
    }

    //Gets the index position in hashtable
    ID *tempID { new ID(id) };
    int *loc = this->getLoc(tempID);
    return this->table[loc[0]][loc[1]].getEmployee(tempID);
}


List *HashTable::getEmployee(string firstName, string lastName) {
    this->toLower(firstName);
    this->toLower(lastName);

    ID *tempID { new ID(firstName, lastName) };
    int *loc = this->getLoc(tempID);
    return this->table[loc[0]][loc[1]].getEmployee(firstName, lastName, tempID);
}


int HashTable::deactivate(string id) {
    Employee *tempEmployee { this->getEmployee(id) };
    if (tempEmployee) {
        tempEmployee->setDeactivatedStatus(true);
        return 0;
    }
    return -1;
}


int HashTable::display() {
    AVLTree **tempAVL { this->table };

    if (this->table) {
        for (int i { 0 }; i < this->n; i++) {
            for (int j {0}; j < this->n; j++) {
                tempAVL[i][j].display();
            }
        }
        return 0;
    }

    return -1;
}


void HashTable::displaySort() {
    AVLTree **tempAVL { this->table };

    if (this->table) {
        for (int i { 0 }; i < this->n; i++) {
            for (int j {0}; j < this->n; j++) {
                tempAVL[i][j].display();
            }
        }
        return 0;
    }

    return -1;
}
