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

	library.browseBooks(criteria);
}

void StackOverdue::book() {
	unsigned int bookid;
	bookid = askBookID();

	if (!isThereSomething("book", bookid)) {
		cout << "Couldn't find the book with the ID in the Library." << endl;
		return;
	}

	library.findBook(bookid);
}

void StackOverdue::searchBook() {
	string criteria, phrase;
	cout << "Enter the criteria to search by. (title/author)" << endl;
	cout << "> ";
	cin >> criteria;

	cout << "Enter the search phrase." << endl;
	cout << "> ";
	cin >> phrase;
	// error handling

	library.searchBooks(criteria, phrase);
}

void StackOverdue::accounts() {
	string criteria;
	cout << "Enter the criteria to sort by. (name/accountid/checkouts)" << endl;
	cout << "> ";
	cin >> criteria;

	library.browseAccounts(criteria);
}

void StackOverdue::account() {
	unsigned int userid;
	userid = askUserID();

	if (!isThereSomething("account", userid)) {
		cout << "Couldn't find the account with the ID in the Library." << endl;
		return;
	}

	library.findAccount(userid);
}

void StackOverdue::checkout() {
	unsigned int userid, bookid;
	userid = askUserID();

	if (!isThereSomething("account", userid)) {
		cout << "Couldn't find the account with the ID in the Library." << endl;
		return;
	}

	bookid = askBookID();

	if (!isThereSomething("book", bookid)) {
		cout << "Couldn't find the book with the ID in the Library." << endl;
		return;
	}

	library.checkOut(userid, bookid);
}

void StackOverdue::renewBook() {
	unsigned int userid;
	userid = askUserID();

	if (!isThereSomething("account", userid)) {
		cout << "Couldn't find the account with the ID in the Library." << endl;
		return;
	}

	library.renewBook(userid);
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
	unsigned int bookId = askBookID();

	if (bookId > getTotalBooks())
		return;

	if (!isThereSomething("book", bookId)) {
		cout << "Couldn't find the book with the ID in the Library." << endl;
		return;
	}

	library.removeBook(bookId);
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
	unsigned int usrId = askUserID();

	if (usrId > getTotalAccounts())
		return;

	if (!isThereSomething("account", usrId)) {
		cout << "Couldn't find the account with the ID in the Library." << endl;
		return;
	}

	library.removeAccount(usrId);
}

void StackOverdue::time() {
	unsigned int day;
	cout << "Enter the number of days to time travel." << endl;
	cout << "> ";
	cin >> day;

	library.updateSystem(day);
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
	return bookid;
}

unsigned int StackOverdue::askUserID() {
	unsigned int userid;
	cout << "Enter the account id." << endl;
	cout << "> ";
	cin >> userid;
	return userid;
}

bool StackOverdue::isThereSomething(string target, unsigned int id) {
	
	return library.isThereSomething(target, id);
}
#endif