#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <iostream>
#include <map>
#include "User.h"

class Accounts {
public:
	// constructors
	Accounts() {}
	Accounts(ifstream& newUsers) {}
	~Accounts() {};

	// method
	// mutator
	void setNumUsers(unsigned int newNumUsers) { numUsers = newNumUsers;}; // implemented

	// accessor
	unsigned int getNumUsers() { return numUsers;}; // implemented
	User* getUser(unsigned int userId) { return users[userId];}

	// other
	bool addUser(User& newUser);
	bool delUser(unsigned int delUserId);
	unsigned int findUser(string criteria);
	void sortAccounts(string criteria);
	void displayUser(unsigned int userId);
	void displayAll();

private:
	unsigned int numUsers;
	map<int, User*> users;
};
#endif