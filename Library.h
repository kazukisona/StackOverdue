#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <fstream>
#include "BookWarehouse.h"
#include "Accounts.h"

using namespace std;

class Library {
public:
	// constructors
	Library();
	Library(ifstream& fileBooks, ifstream& fileUsers);
	~Library() {};

	// method
	// accessor
	unsigned int getNumBooks() { return books.getNumBooks();}; // implemented
	unsigned int getNumUsers() { return accounts.getNumUsers();}; // implemented

	// other
	void browseBooks(unsigned int bookId);
	void searchBooks(string criteria);
	void searchAccounts(string criteria);
	void findAccount(unsigned int userId);
	bool checkOut(unsigned int userId, unsigned int bookId);
	bool renew(unsigned int userId);
	bool return(unsigned int bookId);
	bool addBook();
	bool removeBook();
	bool addAccount();
	bool removeAccount();

private:
	BookWarehouse books;
	Accounts accounts;
};

#endif