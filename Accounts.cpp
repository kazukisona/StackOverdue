#ifndef ACCOUNTS_CPP
#define ACCOUNTS_CPP

#include <iostream>
#include "Accounts.h"

using namespace std;

bool Accounts::addUser(User& newUser) {
	bool success = false;
	unsigned int id = newUser.getID();
	users[id] = &newUser; // mapping 

	// increment size
	numUsers++;

	return success;
}

void Accounts::displayAll() {
	int c = 0;
	for (map<int, User*>::iterator it=users.begin(); it != users.end(); ++it) {
		if (it->first != 0) {
			cout << c << ". ";
			it->second->display();
			cout << endl;
		}
		c++;
	}
}

void Accounts::displayUser(unsigned int userId) {
	
}

void Accounts::sortAccounts(string criteria) {
	if (criteria == "accountid") {
		displayAll(); 
		return;
	}
	else if (criteria == "name") {
		multimap<string, User*> sorted;
		multimap<string, User*>::iterator sortedIt;
		for (map<int, User*>::iterator it=users.begin(); it!=users.end(); ++it) {
			string key;
			key = it->second->getName();
			if (it->first != 0)
				sorted.insert(pair<string, User*>(key, it->second));
		}
		int c = 1;
		for (sortedIt=sorted.begin(); sortedIt != sorted.end(); ++sortedIt) {
			cout << c << ". ";
			sortedIt->second->display();
			c++;
		}
	} else {
		multimap<int, User*> sorted;
		multimap<int, User*>::iterator sortedIt;
		for (map<int, User*>::iterator it=users.begin(); it!=users.end(); ++it) {
			unsigned int key = it->second->getNumCheckout();
			if (it->first != 0)
				sorted.insert(pair<int, User*>(key, it->second));
		}
		int c = 1;
		multimap<int, User*>::reverse_iterator rit;
		for (rit=sorted.rbegin(); rit != sorted.rend(); ++rit) {
			cout << c << ". ";
			rit->second->display();
			c++;
		}
	}
}

#endif