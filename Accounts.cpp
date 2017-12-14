#ifndef ACCOUNTS_CPP
#define ACCOUNTS_CPP

#include <iostream>
#include <fstream>
#include <string>
#include "Accounts.h"

using namespace std;

unsigned int Accounts::getNumUsers() {
	unsigned int numUsers = 0;

	for (map<int, User*>::iterator it = users.begin(); it != users.end(); ++it) {
		if (users.count(it->first) && it->first != 0)
			numUsers++;
	}
	return numUsers;
}

bool Accounts::addUser(User& newUser) {
	bool success = false;
	unsigned int id = newUser.getID();
	users[id] = &newUser; // mapping 

	return success;
}

bool Accounts::delUser(unsigned int delUserId) {
	for (map<int, User*>::iterator it=users.begin(); it!=users.end(); ++it) {
		if (it->first == delUserId) {
			// return all of checkedBooks
			it->second->returnAll();
			cout << it->second->getName() << "'s account successfully removed." << endl << endl;
			delete it->second; // delete pointer
			users.erase(it); 
			break;
		}
	}
	return true;
} 

void Accounts::displayAll() {
	int c = 0;
	for (map<int, User*>::iterator it=users.begin(); it != users.end(); ++it) {
		if (it->first != 0) {
			cout << c << ". ";
			it->second->display();
		}
		c++;
	}
}

unsigned int Accounts::getOverdueUsers() {
	map<int, User*>::iterator it;
	unsigned int count = 0;
	for (it=users.begin(); it != users.end(); ++it) {
		if (it->second->isOverdue())
			count++;
	}
	return count;
}

bool Accounts::isThereAccount(unsigned int id) {
	if (users.count(id) > 0)
		return true;
	else
		return false;
}

void Accounts::updateStatus() {
	for (map<int, User*>::iterator it = users.begin(); it != users.end(); ++it) {
		if (it->second->getNumOverdue() > 0) {
			it->second->setOverdue(true);
		}
	}
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
	} else if (criteria == "accountid" || criteria == "checkouts") {
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
	} else {
		cout << "Invalid value." << endl;
		return;
	}
}

void Accounts::exportAccounts(ofstream& output) {
	output << to_string(getNumUsers()) << "\n";

	for (map<int, User*>::iterator it=users.begin(); it != users.end(); ++it) {
		if (it->first != 0)
			output << it->second->outputFormat();
	}
}

#endif
