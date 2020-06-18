#include <string>


using std::stoi;
using std::string;
using std::to_string;


/** ID Class
    The ID class is needed to instansiate an ID object which is used to store the ID of an employee. The ID iteslef served an important key role in data storing in this program, in which ressembles the position of the Employee data in the storage.
    The ID consist of 2 parts, code and sequence, the code is created from several characters and mathematics of employee's name while sequence is created by the sequence order of similar ID code in order to make an ID unique and distinct from the other ID.
**/
class ID {
    string code { "" }; //Main ID
    int seq { 0 }; //Ordered sequential of the code
    bool _isValid = false; //Determines the availability to set the sequence
    int size { 8 }; //The length of ID


    /** Calculates the sum of string ASCII and moduled by 10
        The only calculation which determines two characters of an ID, the basic material is first name and last name. Each sum of the ASCII code will be summed and moduled by 10 before returned.
    **/
    int calc_Name(string &name) {
        int sum { 0 };
        for (char character : name) {
            sum += int(character);
        }

        return sum % 10;
    }




    public:
        //Constructor for creating ID from name
        ID(string &firstName, string &lastName) {
            this->code += string(1, firstName[0]) + string(1, firstName[firstName.size() - 1]);

            this->code += string(1, lastName[0]) + string(1, lastName[lastName.size() - 1]);

            this->code += to_string(this->calc_Name(firstName)) + to_string(this->calc_Name(lastName));

        }


        //Constructor for creatign ID from id string
        ID(string id) {
            string tempSeq { "" };
            for (int i { 0 }; i < this->size; i++) {
                if (i < 6) {
                    this->code += string(1, id[i]);
                } else {
                    tempSeq += string(1, id[i]);
                }
            }

            this->seq = stoi(tempSeq);
        }


        //ID code getter
        string getCode() {
            return this->code;
        }


        //ID sequence getter
        int getSequence() {
            return this->seq;
        }


        /**ID Sequence setter
            The sequence of the ID can be set only once. Once it is set for the first time, the _isValid will be set to true, indicating that the ID is fully valid and can't be changed anymore.
        **/
        int setSequence(int seq) {
            if (!this->_isValid) {
                this->seq = seq;
                this->_isValid = true;
                return 0;
            }

            return 1;
        }


        //Gets the full ID by combining ID code and ID sequence
        string toString() {
            string seq = (this->seq < 10) ? ("0" + to_string(this->seq)) : to_string(this->seq);
            return (this->code + seq);
        }
};
