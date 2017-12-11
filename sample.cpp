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
	return 0;
}

#endif