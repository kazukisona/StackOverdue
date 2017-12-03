#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;

class User {
public:
	const int MAX_CHECKED = 10; // maximum number of books a user can check out at a time
	
	// constructors
	User();
	User(unsigned int newId, string newName, unsigned int newNumChecked, vector<Book> newCheckedBooks);
	~User() {}

	// methods
	// mutator
	void setID(unsigned int newId) { ID = newId;}; // implemented
	void setName(string newName) { name = newName;}; // implemented
	void setCheckedBooks(vector<Book> newBooks) { checkedouts = newBooks;}; // implemented
	void setNumCheckout() { numCheckout = checkedouts.capacity();}; // implemented
	void setOverdue(bool newValue) { overdue = newValue;}; // implemented

	// accessor
	unsigned int getID() { return ID;}; // implemented
	string getName() { return name;}; // implemented
	vector<Book> getCheckedouts() { return checkedouts;}; // implemented
	unsigned int getNumCheckout() { return numCheckout;}; // implemented
	bool isOverdue() { return overdue;}; // implemented
	bool isRenewed() { return renewed;}; // implemented

	// other
	bool rentBook(unsigned int bookId);
	bool rentBook(vector<unsigned int> bookIds);
	bool returnBook(unsigned int bookId);
	bool returnBook(vector<unsigned int> bookIds);

private:
	unsigned int ID;
	string name;
	vector<Book> checkedouts;
	unsigned int numCheckout;
	bool overdue;
	bool renewed;
};

#endif