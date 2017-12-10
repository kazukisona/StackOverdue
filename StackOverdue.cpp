#ifndef STACKOVERDUE_CPP
#define STACKOVERDUE_CPP

#include <iostream>
#include "StackOverdue.h"

using namespace std;

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

void StackOverdue::accounts() {
	string criteria;
	cout << "Enter the criteria to sort by. (name/accountid/checkouts)" << endl;
	cout >> "> ";
	cin >> criteria;
	// error handling
	library.browseAccounts(criteria);
}

void StackOverdue::account() {
	unsigned int userid;

	cout << "Enter the account id." << endl;
	cout << "> ";
	cin >> userid;
	// error handling
	library.findAccount(userid);
}
#endif