#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <iostream>
#include <map>
#include "User.h"

class Accounts {
public:
	// constructors
	Accounts();
	Accounts(unsigned int newNumUsers);
	~Accounts() {};

	// method
	// mutator
	void setNumUsers(unsigned int newNumUsers) { numUsers = newNumUsers;}; // implemented

	// accessor
	unsigned int getNumUsers() { return numUsers;}; // implemented

	// other
	bool addUser(unsigned int newUserId);
	bool delUser(unsigned int delUserId);
	unsigned int findUser(string criteria);
	void sortAccounts(string criteria);
	void displayUser(unsigned int userId);
	void displayAll();

private:
	unsigned int numUsers;
	map<unsigned int, User*> users;
};
#endif