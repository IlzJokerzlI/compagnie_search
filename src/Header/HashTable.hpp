#include "AVLTree.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <string>


using std::for_each;
using std::atoi;
using std::ifstream;
using std::isalpha;
using std::isdigit;
using std::string;
using std::tolower;


/** Hash Table Class
	The Hash Table is the one to contain all the AVL Tree together, it is to ease the burden of AVL Tree, because no matter how efficient an AVL Tree is, it still takes time when it comes to managing massive amount of data. An example would be best to explain, imagine there is an avl tree with one million data which has 20 levels. The AVL Tree then will be distributed into smaller AVL Tree and each will be stored in a Hash Table with size of 10. In the best scenario, each AVL Tree will now contains one hundred thousand data with only 16 levels. How much of the height or data contained can be further decreased when we distribute it into Hash Table with size of 100? The more distributed it is, the less data will be contained in the AVL Tree and so is the time consumption.
	The Hash Table is also the home for various user-end methods as well as methods which is used to process the raw data before passed into the AVL Tree.
	The Hash Table has a strong bond with AVL Tree just like how the AVL Tree with linked list, they can't perform action without the presence of the other.
**/
class HashTable {
	AVLTree **table;
	int n { 10 };

	void toLower(string &name); //Converts string to lower case
	int *getLoc(ID *id); //Checks the stored Employee Object location in hashtable from given ID
	bool check_ID(string &id); //Checks the validity of an id


	public:
		HashTable(); //Constructors
		int read (const string filePath); //Read data from file
		int input (Employee *employee); //Input data with exisiting Employee Object
		int input(string firstName, string lastName); //Inputs data
		Employee *getEmployee(string id); //Employee getter by using ID
		List *getEmployee(string firstName, string lastName); //Employee getter by using name
		int deactivate(string id); //Remove an object by deactivating it
		int display(); //Displays all the data contained in the hash table
		int displaySort(); //Displays all the sorted data contained in the hash table based on alphabetical order
		int write(const string filePath); //Writes the data into a .txt file
};
