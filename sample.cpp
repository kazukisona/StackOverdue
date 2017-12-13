#ifndef SAMPLE_CPP
#define SAMPLE_CPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "Book.cpp"
#include "User.cpp"
#include "BookWarehouse.cpp"
#include "Accounts.cpp"
#include "Library.cpp"
#include "StackOverdue.cpp"

using namespace std;

int main() {

	Book book2;
	User user1, user2;

	ifstream inputs;
	ifstream fileAccounts;

	inputs.open("data/library.small/books.data");
	fileAccounts.open("data/library.small/accounts.data");

	Library library1 = Library(inputs, fileAccounts);

	cout << endl;
	library1.findBook(100);

	cout << endl;
	library1.findBook(46);

	library1.browseAccounts("name");
	cout << endl;
	library1.findAccount(20);
	cout << endl;
	library1.searchBooks("author", "Ab");
	cout << endl;
	library1.checkOut(15, 100);
	cout << endl;
	library1.renewBook(20);
	library1.addAccount("Kazuki");
	library1.addAccount("Anne Garvey");
	library1.browseAccounts("accountid");

	library1.removeAccount(18);
	library1.browseAccounts("accountid");
	library1.addBook("Computer and Arts", "Graham", "Programming");
	//library1.browseBooks("bookid");
	library1.removeBook(170);
	library1.removeBook(201);
	//library1.browseAllBooks();
	//library1.browseAccounts("accountid");
	library1.checkOut(27, 186);
	library1.browseAllBooks();
	library1.updateSystem(1);
	library1.browseAllBooks();
	library1.findBook(100);
	library1.findBook(46);
	library1.renewBook(11);
	library1.renewBook(11);
	library1.updateSystem(4);
	library1.renewBook(11);
	library1.browseAccounts("accountid");

	StackOverdue stack = StackOverdue(inputs, fileAccounts);

	stack.showHelp();

	return 0;
}

#endif