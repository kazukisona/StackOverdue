/*
Author: Kazuki Sona
Date: 14th, Dec
Class: CSCI23500
Instructor: Simon Ayzman
Prgrram: Book.cpp
*/

#ifndef BOOK_CPP
#define BOOK_CPP

#include <iostream>
#include "Book.h"

using namespace std;

// implementation
Book::Book(unsigned int newId, string newTitle, string newAuthor, string newGenre, unsigned int newPop=0) {
	ID = newId;
	title = newTitle;
	author = newAuthor;
	genre = newGenre;
	popularity = newPop;
	checkedUser = 0;
	numRenewed = 0;
	dueDate = 0;
	available = true;
	overdue = false;
}

void Book::display() const {
	cout << "\"" << title << "\" by " << author << " (BookID# " << ID << ") [" << genre << "]. ";

	if (available)
		cout << "AVAILABLE." << endl;
	else
		cout << "CHECKED OUT (AccountID# " << checkedUser << ")." << endl;
}

void Book::displayDetail(bool space) const {
	string ch;
	if (!space) ch = ""; else ch = "\t"; 
	cout << ch << "Title: " << "\"" << title << "\"" << endl;
	cout << ch << "Author: " << author << endl;
	cout << ch << "BookID#: " << ID << endl;
	cout << ch << "Genre: " << genre << endl;
	cout << ch << "Popularity Score: " << popularity << endl;

	if (available)
		cout << ch << "AVAILABLE." << endl;
	else {
		cout << ch << "Borrower AccountID#: " << checkedUser << endl;
		cout << ch << "Due Date: " << dueDate << endl;
		cout << ch << "Times Renewed: " << numRenewed << endl;
		if (overdue)
			cout << ch << "OVERDUE" << endl;
	}
}

bool Book::alreadyChecked(unsigned int userid) {
	bool checked = false;
	if (history.count(userid) > 0) {
		checked = true;
	}
	return checked;
}

void Book::addHistory(unsigned int userid) {
	history[userid] += 1;
}

string Book::outputFormat() {
	string output;
	string bar = "|";

	output = to_string(ID) + bar + title + bar + author + bar + genre + bar + to_string(popularity) + "\n";
	return output;
}

#endif