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

#endif