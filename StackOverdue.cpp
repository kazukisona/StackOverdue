/*
Author: Kazuki Sona
Date: 14th, Dec
Class: CSCI23500
Instructor: Simon Ayzman
Prgrram: StackOverdue.cpp
*/

#ifndef STACKOVERDUE_CPP
#define STACKOVERDUE_CPP
#include <iostream>
#include "StackOverdue.h"

using namespace std;

void StackOverdue::browse() {

	if (getTotalBooks() == 0) {
		cout << "No books in your library." << endl;
		return;
	}

	string criteria;
	cout << "Enter the criteria to sort by. (title/author/genre/bookid/popularity)" << endl;
	cout << "> ";
	cin >> criteria;

	library.browseBooks(criteria);
}

void StackOverdue::book() {
	if (getTotalBooks() == 0) {
		cout << "No books in your library." << endl;
		return;
	}

	unsigned int bookid = askBookID();

	if (!isThereSomething("book", bookid)) {
		cout << "BookID# " << bookid << " not found." << endl;
		return;
	}

	library.findBook(bookid);
}

void StackOverdue::searchBook() {
	if (getTotalBooks() == 0) {
		cout << "No books in your library." << endl;
		return;
	}

	string criteria, phrase;
	cout << "Enter the criteria to search by. (title/author)" << endl;
	cout << "> ";
	cin >> criteria;

	cout << "Enter the search phrase." << endl;
	cout << "> ";
	cin >> phrase;

	library.searchBooks(criteria, phrase);
}

void StackOverdue::accounts() {
	if (getTotalAccounts() == 0) {
		cout << "No accounts in your library." << endl;
		return;
	}

	string criteria;
	cout << "Enter the criteria to sort by. (name/accountid/checkouts)" << endl;
	cout << "> ";
	cin >> criteria;

	library.browseAccounts(criteria);
}

void StackOverdue::account() {
	if (getTotalAccounts() == 0) {
		cout << "No accounts in your library." << endl;
		return;
	}

	unsigned int userid = askUserID();

	if (!isThereSomething("account", userid)) {
		cout << "AccountID# " << userid << " not found." << endl;
		return;
	}

	library.findAccount(userid);
}

void StackOverdue::checkout() {
	if (getTotalAccounts() == 0) {
		cout << "No accounts in your library." << endl;
		return;
	}

	unsigned int userid = askUserID();
	if (!isThereSomething("account", userid)) {
		cout << "AccountID# " << userid << " not found." << endl;
		return;
	}

	if (getTotalBooks() == 0) {
		cout << "No books in your library." << endl;
		return;
	}

	unsigned int bookid = askBookID();
	if (!isThereSomething("book", bookid)) {
		cout << "BookID# " << bookid << " not found." << endl;
		return;
	}

	library.checkOut(userid, bookid);
}

void StackOverdue::renewBook() {
	unsigned int userid = askUserID();

	if (!isThereSomething("account", userid)) {
		cout << "AccountID# " << userid << " not found." << endl;
		return;
	}

	library.renewBook(userid);
}

void StackOverdue::returnBook() {
	unsigned int bookid;
	bookid = askBookID();

	if (!isThereSomething("book", bookid)) {
		cout << "BookID# " << bookid << " not found." << endl;
		return;
	}

	library.returnBook(bookid);
}

void StackOverdue::recommend() {
	unsigned int userid = askUserID();

	if (!isThereSomething("account", userid)) {
		cout << "AccountID# " << userid << " not found." << endl;
		return;
	}

	library.recommendation(userid);
}

void StackOverdue::addB() {
	string title, author, genre;
	cin.ignore();
	cout << "Enter the new book’s title." << endl;
	cout << "> ";
	getline(cin, title);

	cout << "Enter the new book’s author." << endl;
	cout << "> ";
	getline(cin, author);

	if (library.checkDuplicates(title, author)) {
		cout << "Book with this title and author already exists." << endl;
		return;
	}

	cout << "Enter the new book’s genre." << endl;
	cout << "> ";
	getline(cin, genre);
	
	library.addBook(title, author, genre);
}

void StackOverdue::removeB() {
	if (getTotalBooks() == 0 || getTotalBooks() == 4294967295) {
		cout << "No books in your library." << endl;
		return;
	}

	unsigned int bookid = askBookID();	
	if (!isThereSomething("book", bookid)) {
		cout << "BookID# " << bookid << " not found." << endl;
		return;
	}

	library.removeBook(bookid);
}

void StackOverdue::addA() {
	string name;
	cin.ignore();
	cout << "Enter the new user’s name." << endl;
	cout << "> ";
	getline(cin, name);

	library.addAccount(name);
}

void StackOverdue::removeA() {
	
	if (getTotalAccounts() == 0 || getTotalAccounts() == 4294967295) {
		cout << "No accounts in your library." << endl;
		return;
	}

	unsigned int userid = askUserID();
	if (!isThereSomething("account", userid)) {
		cout << "AccountID# " << userid << " not found." << endl;
		return;
	}

	library.removeAccount(userid);
}

void StackOverdue::time() {
	unsigned int day = 0;
	cout << "Enter the number of days to time travel." << endl;
	cout << "> ";
	cin >> day;

	if (cin.fail()) {
		cout << "Invalid value." << endl;
		cin.clear();
		return;
	}

	systemTime += day;

	library.updateSystem(day);
}

void StackOverdue::exportLibrary() {
	ofstream bookOutput, accountOutput;
	string nameBookFile, nameAccountFile;

	cout << "Enter the name for the books file. (This may overwrite a file) " << endl;
	cout << "> ";
	cin >> nameBookFile;

	cout << "Enter the name for the accounts file. (This may overwrite a file) " << endl;
	cout << "> ";
	cin >> nameAccountFile;

	bookOutput.open(nameBookFile);
	accountOutput.open(nameAccountFile);

	library.exportBook(bookOutput);
	library.exportAccount(accountOutput);

	cout << "Books data successfully exported to \"" << nameBookFile << "\"." << endl;
	cout << "Accounts data successfully exported to \"" << nameAccountFile << "\"." << endl;
}

void StackOverdue::systemInfo() {
	cout << "System time: " << systemTime << "." << endl;
	cout << "Number of books: " << library.getNumBooks() << "." << endl;
	cout << "Number of overdue books: " << library.getOverdueBooks() << "." << endl;
	cout << "Number of accounts: " << library.getNumUsers() << "." << endl;
	cout << "Number of overdue books: " << library.getOverdueUsers() << "." << endl;
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

	if (cin.fail()) {
		cout << "Invalid value." << endl;
		cin.clear();
		return 0;
	}

	return bookid;
}

unsigned int StackOverdue::askUserID() {
	unsigned int userid;
	cout << "Enter the account id." << endl;
	cout << "> ";
	cin >> userid;

	if (cin.fail()) {
		cout << "Invalid value." << endl;
		cin.clear();
		return 0;
	}

	return userid;
}

bool StackOverdue::isThereSomething(string target, unsigned int id) {
	
	return library.isThereSomething(target, id);
}
#endif
