#ifndef ACCOUNTS_CPP
#define ACCOUNTS_CPP

#include <iostream>
#include "Accounts.h"

using namespace std;

Accounts::Accounts(ifstream& newUsers) {

}

bool Accounts::addUser(User& newUser) {
	bool success = false;

	unsigned int id = newUser.getID();
	users[id] = &newUser; // mapping 

	// increment size
	numUsers++;

	return success;
}

void Accounts::displayAll() {
	for (map<int, User*>::iterator it=users.begin(); it != users.end(); ++it) {
		it->second->display();
		cout << endl;
	}
}

#endif