#ifndef BOOK_CPP
#define BOOK_CPP

#include <iostream>
#include "Book.h"

using namespace std;

// implementation
Book::Book(unsigned int newId, string newTitle, string newAuthor, string newGenre, unsigned int newPop) {
	ID = newId;
	title = newTitle;
	author = newAuthor;
	genre = newGenre;
	popularity = newPop;
	checkedUser = 0;
	numRenewed = 0;
	dueDate = 0;
	available = true;
}

void Book::display() const {
	cout << "\"" << title << "\" by " << author << " (BookID# " << ID << ") [" << genre << "]. ";

	if (available)
		cout << "AVAILABLE." << endl;
	else
		cout << "CHECKED OUT (AccountID# " << checkedUser << ")." << endl;
}

#endif