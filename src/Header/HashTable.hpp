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


class HashTable {
	AVLTree **table;
	int n { 10 };

	void toLower(string &name);
	int *getLoc(ID *id);
	bool check_ID(string &id);


	public:
		HashTable();
		int read (const string filePath);
		int input (Employee *employee);
		int input(string firstName, string lastName);
		Employee *getEmployee(string id);
		List *getEmployee(string firstName, string lastName);
		int deactivate(string id);
		int display();
		int displaySort();
		int write(const string filePath);
};
