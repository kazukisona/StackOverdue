#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;

class User {
public:
	
	// constructors
	User() {}
	User(unsigned int newId, string newName) { ID = newId; name = newName; numCheckout=0; overdue=false; numOverdue=0;}
	User(unsigned int newId, string newName, unsigned int newNumChecked);
	~User() {}

	// methods
	// mutator
	void setID(unsigned int newId) { ID = newId;} // implemented
	void setName(string newName) { name = newName;} // implemented
	void setCheckedBooks(vector<Book*> newBooks) { checkedOuts = newBooks;} // implemented
	void setNumCheckout() { numCheckout = checkedOuts.capacity();} // implemented
	void setOverdue(bool newValue) { overdue = newValue;} // implemented

	// accessor
	unsigned int getID() { return ID;} // implemented
	string getName() { return name;} // implemented
	vector<Book*> getCheckedouts() { return checkedOuts;} // implemented
	unsigned int getNumCheckout() { return numCheckout;} // implemented

	// other
	bool rentBook(Book& book);
	bool returnBook(unsigned int bookId);
	void returnAll();
	bool isOverdue() { return overdue;} // implemented
	void renewBook();
	void display();
	void displayDetail();
	void displayBooks();

private:
	unsigned int ID;
	string name;
	vector<Book*> checkedOuts;
	unsigned int numCheckout;
	bool overdue;
	unsigned int numOverdue;
};

#endif