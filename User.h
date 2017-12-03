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
	~User();

	// methods
	// mutator
	void setID(unsigned int newId) { ID = newId;};
	void setName(string newName) { name = newName;};
	void setCheckedBooks(vector<Book> newBooks) { checkedouts = newBooks;};
	void setNumCheckout() { numCheckout = checkedouts.capacity();};
	void setOverdue(bool newValue) { overdue = newValue;};

	// accessor
	unsigned int getID() { return ID;};
	string getName() { return name;};
	vector<Book> getCheckedouts() { return checkedouts;};
	unsigned int getNumCheckout() { return numCheckout;};
	bool isOverdue() { return overdue;};
	bool isRenewed() { return renewed;};

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