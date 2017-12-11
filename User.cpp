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
	numOverdue = 0;
}

bool User::rentBook(Book& book) {
	bool success = false;
	if (checkedOuts.capacity() >= 10 || overdue) return success;
	book.setCheckedUser(ID);
	int current = 0;
	book.setDueDate(current+15);
	checkedOuts.push_back(&book);
	success = true;
	return success;
}

bool User::returnBook(unsigned int bookId) {
	bool success = false;

	for (int i = 0; i < checkedOuts.size(); ++i) {
		if (checkedOuts[i]->getID() == bookId) {
			checkedOuts[i]->clearChecked();
			checkedOuts[i]->clearRenewed();
			checkedOuts[i] = nullptr;
			success = true;
			return success;
		}
	}
	return success;
}

void User::returnAll() {
	for (int i = 0; i < checkedOuts.size(); ++i) {
		cout << "\""<< checkedOuts[i]->getTitle() << "\" by " << checkedOuts[i]->getAuthor() 
		     << " (BookID# " << checkedOuts[i]->getID() << ") force returned." << endl;
		checkedOuts[i]->clearChecked();
		checkedOuts[i]->clearRenewed();
		checkedOuts[i] = nullptr;
	}
}

void User::renewBook() {
	int renewed = 0;
	int i = 1;

	for (vector<Book*>::iterator it=checkedOuts.begin(); it!=checkedOuts.end(); ++it) {
		if (!((*it)->getNumRenewed() >= 2))
			renewed++;
		if ((*it)->isOverdue()) {
			cout << "Account has books overdue." << endl;
			return;
		}
	}
	cout << renewed << " of " << numCheckout << " books successfully renewed." << endl;
	for (vector<Book*>::iterator it=checkedOuts.begin(); it!=checkedOuts.end(); ++it) {
		string message;
		if (!((*it)->getNumRenewed() >= 2)) {
			(*it)->renew();
			message = "Book successfully renewed.\n";
		} 
		else 
			message = "Book already renewed twice.\n";

		cout << "\t" << i << ". " << endl;
		(*it)->displayDetail(true);
		i++;
	}
}

void User::display() {
	cout << name << " (AccountID# " << ID << "). " << numCheckout << " books checked out: " << endl;
	displayBooks();
}

void User::displayDetail() {
	cout << "Name: " << name << endl;
	cout << "AccountID#: " << ID << endl;
	cout << numCheckout << " books checked out";

	if (overdue) cout << " (" << numOverdue << " overdue):" << endl;
	else cout << "." << endl;

	int c = 1;
	for (vector<Book*>::iterator it = checkedOuts.begin(); it != checkedOuts.end(); ++it) {
		cout << "\t" << c << "." << endl;
		(*it)->displayDetail(true);
		c++;
	}
}

void User::displayBooks() {
	int c = 1;
	for (vector<Book*>::iterator it = checkedOuts.begin(); it != checkedOuts.end(); ++it) {
		cout << "\t" << c << ". ";
		(*it)->display();
		c++;
	}
}

#endif