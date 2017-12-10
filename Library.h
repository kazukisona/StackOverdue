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
	Library() {} // implemented
	Library(ifstream& newBooks, ifstream& newAccounts);
	~Library() {} // implemented

	// method
	// accessor
	unsigned int getNumBooks() { return warehouse.getNumBooks();}; // implemented
	unsigned int getNumUsers() { return accounts.getNumUsers();}; // implemented

	// other
	void browseAllBooks() { warehouse.displayAll();} // implemented
	void browseBooks(string criteria) { warehouse.sortBooks(criteria);}
	void searchBooks(string criteria);
	void browseAllAccounts() { accounts.displayAll();} // implemented
	void browseAccounts(string criteria) { accounts.sortAccounts(criteria);}
	void searchAccounts(string criteria);
	void findBook(unsigned int bookId);
	void findAccount(unsigned int userId);
	bool checkOut(unsigned int userId, unsigned int bookId);
	bool renewBook(unsigned int userId);
	bool returnBook(unsigned int bookId);
	bool addBook(Book& book) { return warehouse.addBook(book);} // implemented
	bool addBook(string newTitle, string newAuthor, string newGenre, unsigned int newPop);
	bool removeBook();
	bool addAccount(User& newUser) { return accounts.addUser(newUser);} // implemented
	bool addAccount(string newName);
	bool removeAccount();
	void importBooks(ifstream& newBooks);
	void importAccounts(ifstream& newAccounts);

private:
	BookWarehouse warehouse;
	Accounts accounts;
};

#endif