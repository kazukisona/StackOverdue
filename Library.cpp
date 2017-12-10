#ifndef LIBRARY_CPP
#define LIBRARY_CPP

#include <iostream>
#include "Library.h"

using namespace std;

Library::Library(ifstream& fileBooks, ifstream& fileAccounts) {
	// books must come first so that we know which acount check out which books
	importBooks(fileBooks); // loading books
	importAccounts(fileAccounts); // loading users(accounts)
}

void Library::importBooks(ifstream& newBooks) {
	string line;
	getline(newBooks, line);

	Book* temp;
	while (newBooks) {
		unsigned int id, popularity;
		string str_id, str_pop;
		string title, author, genre;

		getline(newBooks, str_id, '|');  getline(newBooks, title, '|');
		getline(newBooks, author, '|');  getline(newBooks, genre, '|');
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
		string str_idU, str_numCheck;
		string name;

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

			// get the book from warehouse
			tempB = warehouse.getBook(bookId);
			tempB->setDueDate(dueDate);
			tempB->setNumRenewed(numRenew);
			tempU->rentBook(*tempB);
		}
		accounts.addUser(*tempU);
	}
}

bool Library::addBook(string newTitle, string newAuthor, string newGenre, unsigned int newPop) {
	unsigned int newId = warehouse.getNumBooks();
	Book nBook = Book(newId, newTitle, newAuthor, newGenre, newPop);

	return warehouse.addBook(nBook);
}

bool Library::addAccount(string newName) {
	unsigned int newId = accounts.getNumUsers();
	User nUser = User(newId, newName);

	return accounts.addUser(nUser);
}

void Library::findBook(unsigned int bookId) {
	Book * temp = warehouse.getBook(bookId);
	temp->displayDetail();
}

#endif