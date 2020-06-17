#include "AVLTree.hpp"

#include <algorithm>
#include <cctype>
#include <string>


using std::for_each;
using std::atoi;
using std::isalpha;
using std::isdigit;
using std::string;
using std::tolower;


class HashTable {
public:
	AVLTree **table;
	int n { 10 };

	void toLower(string &name);
	int *getLoc(ID *id);
	bool check_ID(string &id);

	public:
		HashTable();
		int input(string firstName, string lastName);
		Employee *getEmployee(string id);
		List *getEmployee(string firstName, string lastName);
		int deactivate(string id);
		int display();
		int displaySort();
};
