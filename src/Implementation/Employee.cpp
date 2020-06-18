#include "ID.cpp"


#include <string>


using std::string;

/**Employee Class
    All the information of an employee will be contained in an object which is instansiated from the following Employee Class. The Employee Object is also served as a node of double linked list which is why it has next pointer and previous pointer properties. The Employee object created will never be removed completely but deactivated. The reason is, once an employee is registered, the id registered is already permanently created, a missing ID might create a confusion during employee data checking.
**/
class Employee{
    string firstName; //Stores the first name of an employee
    string lastName; //Stores the last name of an employee
    ID *id; //Stores the ID of an employee
    bool _isDeactivated { false }; //The account or data status

    public:
        Employee *nextPtr { nullptr }; //Points to the next node of a linked list of Employee Objects
        Employee *prevPtr { nullptr }; //Points to the previous node of a linked list of Employee Objects


        //Constructor
        Employee (string firstName, string lastName, ID *id, bool deactivatedStatus = false)
        : firstName(firstName),
        lastName(lastName),
        id(id),
        _isDeactivated(deactivatedStatus) {}


        //ID getter
        ID *getID() {
            return this->id;
        }


        //First name getter
        string getFirstName() {
            return this->firstName;
        }


        //Last name getter
        string getLastName() {
            return this->lastName;
        }


        //Name getter
        //Gets a complete name by adding first and last name
        string getName() {
            return this->firstName + " " + this->lastName;
        }


        //Deactivated status setter
        void setDeactivatedStatus(bool deactivatedStatus) {
            this->_isDeactivated = deactivatedStatus;
        }


        //Deactivated status getter
        bool isDeactivated() {
            return this->_isDeactivated;
        }
};
