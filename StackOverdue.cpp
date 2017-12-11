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
	bookid = askBookID();

	library.findBook(bookid);
}

void searchBook() {
	string criteria, phrase;
	cout << "Enter the criteria to search by. (title/author)" << endl;
	cout >> "> ";
	cin >> criteria;

	//error handling
	cout << "Enter the search phrase.";
	cin >> phrase;
	// error handling

	library.searchBooks(criteria, phrase);
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
	userid = askUserID();
	library.findAccount(userid);
}

void StackOverdue::checkout() {
	unsigned int userid, bookid;
	userid = askUserID();
	bookid = askBookID();
	library.checkOut(userid, bookid);
}

void StackOverdue::renewBook() {
	unsigned int userid;
	userid = askUserID();

	library.renewBook(userid);
}

void StackOverdue::addB() {
	string title, author, genre;
	cout << "Enter the new book’s title." << endl;
	cin >> title;

	cout << "Enter the new book’s author." << endl;
	cin >> author;

	cout << "Enter the new book’s genre." << endl;
	cin >> genre;

	library.addBook(title, author, genre);
}

void StackOverdue::removeB() {
	unsigned int bookId = askBookID();

	library.removeBook(bookId);
}

void StackOverdue::addA() {
	string name;
	cout << "Enter the new user’s name." << endl;
	cin >> name;

	library.addAccount(name);
}

void StackOverdue::removeA() {
	unsigned int usrId = askUserID();
	
	library.removeAccount();
}

void StackOverdue::showHelp() {
	cout << "BROWSE: Provides the status of all the books." << endl;
	cout << "BOOK: Provides the status of a specific book." << endl;
	cout << "SEARCH: Searches for all books with a key-phrase in the title or author." << endl;
	cout << "ACCOUNTS: Provides account snapshots for all user accounts." << endl;
	cout << "ACCOUNT: Provides an account snapshot for a specific user account." << endl;
	cout << "CHECKOUT: Checks a book out to a user account." << endl;
	cout << "RENEW: Renews a checked out book. (Up to two times allowed)" << endl;
	cout << "RETURN: Returns a checked out book." << endl;
	cout << "RECOMMEND: Generates a list of recommended books for a given user." << endl;
	cout << "ADDB: Adds a new book to the library." << endl;
	cout << "REMOVEB: Removes a specific book from the library." << endl;
	cout << "ADDA: Creates a new user account in the library." << endl;
	cout << "REMOVEA: Removes a specific user account from the library." << endl;
	cout << "SYSTEM: Provides diagnostic information about the system." << endl;
	cout << "TIME: Fast forwards the system time by a specified number of days." << endl;
	cout << "EXPORT: Exports the library’s books and accounts to files." << endl;
	cout << "HELP: Displays this help menu." << endl;
	cout << "EXIT: Exits the program." << endl;
}

unsigned int StackOverdue::askBookID() {
	unsigned int bookid;
	cout << "Enter the book id." << endl;
	cout << "> ";
	cin >> bookid;
	return bookid;
}

unsigned int StackOverdue::askUserID() {
	unsigned int userid;
	cout << "Enter the account id." << endl;
	cout << "> ";
	cin >> userid;
	return userid;
}
#endif