#ifndef STACKOVERDUE_CPP
#define STACKOVERDUE_CPP

#include <iostream>
#include "StackOverdue.h"

using namespace std;

StackOverdue::StackOverdue(ifstream& newBooks, ifstream& newUsers) {
	library = Library(newBooks, newUsers);
	systemTime = 0;
	systemStatus = true;
}

void StackOverdue::browse() {
	string criteria;
	cout << "Enter the criteria to sort by. (title/author/genre/bookid/popularity)" << endl;
	cout << "> ";
	cin >> criteria;

	// error handling for parameter

	library.browseBooks(criteria);
}

void StackOverdue::book() {
	unsigned int bookid;

	cout << "Enter the book id." << endl;
	cout << "> ";
	cin >> bookid;

	// error handling
	library.findBook(bookid);
}
#endif