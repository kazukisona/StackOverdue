/*
Author: Kazuki Sona
Date: 14th, Dec
Class: CSCI23500
Instructor: Simon Ayzman
Prgrram: Accounts.h
*/

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

	// accessor
	unsigned int getNumUsers(); // implemented
	User* getUser(unsigned int userId) { return users[userId];}

	// other
	bool addUser(User& newUser);
	bool delUser(unsigned int delUserId); // return all of checkedBooks
	unsigned int findUser(string criteria);
	void sortAccounts(string criteria);
	void displayAll();
	unsigned int getOverdueUsers();
	bool isThereAccount(unsigned int id);
	void updateStatus();
	void exportAccounts(ofstream& output);

private:
	map<int, User*> users;
};
#endif