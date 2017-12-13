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
	Library(ifstream& bFile, ifstream& aFile) {importBooks(bFile); importAccounts(aFile); currentTime=1;}
	~Library() {} // implemented

	// method
	// accessor
	unsigned int getCurrentTime() { return currentTime;}
	unsigned int getNumBooks() { return warehouse.getNumBooks();}; // implemented
	unsigned int getNumUsers() { return accounts.getNumUsers();}; // implemented

	// command related
	void browseAllBooks() { warehouse.displayAll();} // implemented
	void browseAllAccounts() { accounts.displayAll();} // implemented
	void browseBooks(string criteria) { warehouse.sortBooks(criteria);} // implemented
	void browseAccounts(string criteria) { accounts.sortAccounts(criteria);} // implemented
	void searchBooks(string criteria, string phrase) {warehouse.searchBooks(criteria, phrase);} // implemented
	void findBook(unsigned int bookId) {Book* b=warehouse.getBook(bookId); b->displayDetail(false);} // implemented
	void findAccount(unsigned int userId) {User* u=accounts.getUser(userId); u->displayDetail();} // implemented
	void checkOut(unsigned int userId, unsigned int bookId); // implemented
	void renewBook(unsigned int userId); // implemented
	bool returnBook(unsigned int bookId); // implemented
	bool addBook(Book& book) { return warehouse.addBook(book);} // implemented
	bool addBook(string newTitle, string newAuthor, string newGenre, unsigned int newPop=0); // implemented
	bool removeBook(unsigned int bookId); // implemented
	bool addAccount(string newName); // implemented
	bool removeAccount(unsigned int userId) { return accounts.delUser(userId);} // implemented
	
	// utilitie
	void importBooks(ifstream& newBooks); // implemented
	void importAccounts(ifstream& newAccounts); // implemented
	unsigned int getOverdueBooks() { return warehouse.getOverdueBooks();} // implemented
	unsigned int getOverdueUsers() { return accounts.getOverdueUsers();} // implemented
	void updateSystem(unsigned int timeAdded);
	bool checkDuplicates(string title, string author) { return warehouse.checkDuplicates(title, author);}
	bool isThereSomething(string target, unsigned int id);

private:
	BookWarehouse warehouse;
	Accounts accounts;
	unsigned int currentTime;
};

#endif