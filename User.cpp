#ifndef USER_CPP
#define USER_CPP

#include <iostream>
#include "User.h"

using namespace std;

User::User(unsigned int newId, string newName, unsigned int newNumChecked) {
	ID = newId;
	name = newName;
	numCheckout = newNumChecked;
	overdue = false;
}

User::User(unsigned int newId, string newName, unsigned int newNumChecked, vector<Book*> newCheckedBooks) {
	ID = newId;
	name = newName;
	numCheckout = newNumChecked;
	rentBook(newCheckedBooks);
	overdue = false;
}

bool User::rentBook(Book& book) {
	bool success = false;

	if (checkedOuts.capacity() >= 10)
		return success;

	book.setCheckedUser(ID);
	checkedOuts.push_back(&book);
	success = true;

	return success;
}

bool User::rentBook(vector<Book*> books) {
	bool success = false;

	for (int i = 0; i < books.size(); ++i) {
		if (checkedOuts.capacity() >= 10) 
			return success;

		books[i]->setCheckedUser(ID);
		checkedOuts.push_back(books[i]);
	}

	success = true;

	return success;
}

bool User::returnBook(unsigned int bookId) {
	bool success = false;

	for (int i = 0; i < checkedOuts.capacity(); ++i) {
		if (checkedOuts[i]->getID() == bookId) {
			checkedOuts[i]->clearChecked();
			checkedOuts[i]->clearRenewed();
			checkedOuts.erase(checkedOuts.begin()+i);
			success = true;
			return success;
		}
	}

	return success;
}

void User::displayBooks() {
	int c = 1;
	for (vector<Book*>::iterator it = checkedOuts.begin(); it != checkedOuts.end(); ++it) {
		cout << "\t" << c << ". ";
		(*it)->display();
		c++;
	}
}

void User::display() {
	cout << name << " (AccountID# " << ID << "). " << numCheckout << " books checked out: " << endl;
	displayBooks();
}

#endif