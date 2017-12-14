#ifndef LIBRARY_CPP
#define LIBRARY_CPP
#include <iostream>
#include "Library.h"

using namespace std;

bool Library::addBook(string newTitle, string newAuthor, string newGenre, unsigned int newPop) {
	unsigned int newId = warehouse.getNumBooks() + 1;
	Book* nBook = new Book(newId, newTitle, newAuthor, newGenre, newPop);

	cout << "BookID# " << newId << " successfully created." << endl;

	return warehouse.addBook(*nBook);
}

bool Library::addAccount(string newName) {
	unsigned int newId = accounts.getNumUsers() + 1;
	User* nUser = new User(newId, newName);

	cout << "AccountID# " << newId << " successfully created." << endl;

	return accounts.addUser(*nUser);
}

bool Library::removeBook(unsigned int bookId) { 
	Book* bT = warehouse.getBook(bookId);

	if (!bT->isAvailable()) {
		unsigned int userid = bT->getCheckedUser();
		User* uT = accounts.getUser(userid);
		cout << "Force returning book from AccountID# " << uT->getID() << "." << endl;
		uT->returnBook(bookId);
		return warehouse.delBook(bookId);
	} else 
		return warehouse.delBook(bookId);
}

void Library::checkOut(unsigned int userId, unsigned int bookId) {
	User* uT = accounts.getUser(userId);
	Book* bT = warehouse.getBook(bookId);

	if (uT->isOverdue()) {
		cout << "Account has books overdue." << endl << endl;
	} else if (uT->getNumCheckout() >= 10) {
		cout << "Account already has 10 books checked out." << endl << endl;
	} else if (!bT->isAvailable()) {
		cout << "Book already is checked out." << endl << endl;
	} else {
		bT->setDueDate(currentTime+15);
		uT->rentBook(*bT);
		cout << "Book successfully checked out." << endl;
		bT->displayDetail();
	}
}

void Library::renewBook(unsigned int userId) {
	User* uT = accounts.getUser(userId);
	uT->renewBook();
}

bool Library::returnBook(unsigned int bookId) {
	bool success = false;
	Book* bT = warehouse.getBook(bookId);

	if (bT->isAvailable()) {
		cout << "Book is not currently checked out." << endl;
		return success;
	}

	unsigned int userid = bT->getCheckedUser();
	int dueDate = bT->getDueDate();
	User* uT = accounts.getUser(userid);
	success = uT->returnBook(bookId);

	cout << "Book successfully returned by AccountID# " << uT->getID();

	if (currentTime <= dueDate) {
		cout << " (on time)." << endl;
	}
	else
		cout << " (overdue by " << (currentTime-dueDate) << " days)." << endl;

	return success;
}

void Library::recommendation(unsigned int userid) {
	User* uT = accounts.getUser(userid);

	warehouse.recommend(*uT);
}

void Library::updateSystem(unsigned int timeAdded) {
	unsigned int past = currentTime;
	currentTime += timeAdded;
	cout << "Travelled " << timeAdded << " days through time (" 
		 << past << " --> " << currentTime << ")." << endl;
	
	warehouse.updateStatus(currentTime);
	accounts.updateStatus();
}

bool Library::isThereSomething(string target, unsigned int id) {
	bool existed = true;
	if (target == "book") {
		if (!warehouse.isThereBook(id))
		 	existed = false;
	}
	else if (target == "account") {
		if (!accounts.isThereAccount(id))
			existed = false;
	}
	return existed;
}

void Library::importBooks(ifstream& newBooks) {
	string line;
	getline(newBooks, line);

	Book* temp;
	while (newBooks) {
		unsigned int id, popularity;
		string str_id, str_pop, title, author, genre;

		getline(newBooks, str_id, '|'); 
		getline(newBooks, title, '|');
		getline(newBooks, author, '|'); 
		getline(newBooks, genre, '|');
		getline(newBooks, str_pop);

		id = atoi(str_id.c_str());
		popularity = atoi(str_pop.c_str());

		temp = new Book(id, title, author, genre, popularity);
		warehouse.addBook(*temp);
	}
}

void Library::importAccounts(ifstream& newAccounts) {
	string line;
	getline(newAccounts, line);

	User* tempU;
	// user loop
	while (newAccounts) {
		unsigned int userId, numCheckout;
		string str_idU, str_numCheck, name;

		getline(newAccounts, str_idU, '|');
		getline(newAccounts, name, '|');
		getline(newAccounts, str_numCheck);

		// turn str into int
		userId = atoi(str_idU.c_str());
		numCheckout = atoi(str_numCheck.c_str());
		tempU = new User(userId, name, numCheckout);

		Book * tempB;
		// checked out book loop
		for (unsigned int i = 0; i < tempU->getNumCheckout(); ++i) {
			unsigned int bookId, dueDate, numRenew;
			string str_idB, str_due, str_renew;

			getline(newAccounts, str_idB, '|');
			getline(newAccounts, str_due, '|');
			getline(newAccounts, str_renew);

			// convert str into int
			bookId = atoi(str_idB.c_str());
			dueDate = atoi(str_due.c_str());
			numRenew = atoi(str_renew.c_str());

			// check bookid is valid
			if (isThereSomething("book", bookId)) {
				// get the book from warehouse
				tempB = warehouse.getBook(bookId);
				tempB->setDueDate(dueDate);
				tempB->setNumRenewed(numRenew);
				tempU->rentBook(*tempB);
			}
			else {
				cout << "Could not find library book with ID# " << bookId << "." << endl;
			}
		}
		accounts.addUser(*tempU);
	}
}
#endif
