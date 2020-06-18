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
//Constructor
HashTable::HashTable() {
    //Creating the hash table's 2D table
	AVLTree **tempAVL { new AVLTree*[this->n] };
	for (int i { 0 }; i < this->n; i++) {
	    tempAVL[i] = new AVLTree[this->n];
	    for (int j {0}; j < this->n; j++) {
            tempAVL[i][j] = AVLTree();
	    }
	}
	this->table = tempAVL;
}


//Read data from file
int HashTable::read(const string filePath) {
    ifstream file; //Text file
    string tempData[4] = {"0", "0", "0", "0"}; //Temporarily store data


    //Opens file and check validity
    file.open(filePath);
    if(!(file.is_open())) {
        return -1;
    }


    //Traverses the data in file and put into matrix
    while(getline(file, tempData[0], ',')) {
        getline(file, tempData[1], ',');
        getline(file, tempData[2], ',');
        getline(file, tempData[3]);

        if (!tempData[0].empty() && !tempData[1].empty() && !tempData[2].empty() && !tempData[3].empty()) {
            this->input(new Employee(tempData[2], tempData[3], new ID(tempData[1]), (tempData[0] != "0")));
        }    }

    file.close();
    return 0;
}


//Input data with exisiting Employee Object
int HashTable::input(Employee *employee) {
    int *loc = this->getLoc(employee->getID());

    this->table[loc[0]][loc[1]].insert(employee);
    return 0;
}


//Inputs data
int HashTable::input(string firstName, string lastName) {
    this->toLower(firstName);
    this->toLower(lastName);

    ID *tempID { new ID(firstName, lastName) };
    Employee *tempEmployee { new Employee(firstName, lastName, tempID) };
    int *loc = this->getLoc(tempID);

    this->table[loc[0]][loc[1]].insert(tempEmployee);
    return 0;
}


/** Gets Employee object stored in the system
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


/**Employee getter by using name
    This employee getter is pretty much the same as the Employee getter by using ID. The differences are, it accepts name as its parameter and returns a list of Employee Object (data) since it is not as specific or as unique as search ID, because of the unique characteristic of the ID itself.
    The Employee Getter can be used as a feature of data manipulation since it is returning the Employee Object. However, this method only display the data content since the data exist in this data are only the base data which must not be changed by any means (ID and names). This might cause serious trouble in searching since ID is permanent and it is created from name.
**/
List *HashTable::getEmployee(string firstName, string lastName) {
    this->toLower(firstName);
    this->toLower(lastName);

    ID *tempID { new ID(firstName, lastName) };
    int *loc = this->getLoc(tempID);
    return this->table[loc[0]][loc[1]].getEmployee(firstName, lastName, tempID);
}


/**Remove an object by deactivating it
    The remove method in this program has its own uniquness, it is called as deactivating, which is not completely remove it from the storage but simply deactivate it so it won't appear when the display method is called or any other methods except for the getEmployee method which accepts ID as its parameter. The reason is, once an account is created, a unique ID is created alongside. If it is completely removed, it will also removes the unique ID which may cause trouble in the future when the data is manipulated.
**/
int HashTable::deactivate(string id) {
    Employee *tempEmployee { this->getEmployee(id) };
    if (tempEmployee) {
        tempEmployee->setDeactivatedStatus(true);
        return 0;
    }
    return -1;
}


/**Display all the data contained in the hash table
    This method displays all the data in the storage with exception of data with deactivated employee status. It simply iterates to each AVL Tree in the Hash Table, and then it calls the display method from AVL Tree which will further iterates to each LinkedList in each AVL Trees. Finally iterates through the Employee (Nodes) in the linked list before printing out the data.
**/
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


/**Displays all the sorted data contained in the hash table based on alphabetical order
    Just as how it is called, it displays all the content of the storage just like the display method. However, it performs some sorting to the data based on alphabetical order.
**/
int HashTable::displaySort() {
    AVLTree **tempTable { this->table };
    List *list = new List();

    if (this->table) {
        for (int i { 0 }; i < this->n; i++) {
            for (int j {0}; j < this->n; j++) {
                List *tempList { new List() };
                int result { tempTable[i][j].displaySorted(tempList) };
                if (result == 0) {
                    list->merge(tempList);
                }
            }
        }

        list->display(); //Calls display method from List Object
        return 0;
    }

    return -1;
}


/**Writes the data into a .txt file
    The output method in this program only support "on save" type output, which means in order to save it, the ouput method needs to be called. Not the "on edit" type which updates the file data everytime the data is manipulated. The system works similar to display method mechanism
**/
int HashTable::write(const string filePath) {
    ofstream file(filePath + ".txt"); //Open file

    AVLTree **tempAVL { this->table };

    if (this->table) {
        for (int i { 0 }; i < this->n; i++) {
            for (int j {0}; j < this->n; j++) {
                tempAVL[i][j].write(file);
            }
        }

        file.close(); //Close file
        return 0;
    }

    return -1;
}
