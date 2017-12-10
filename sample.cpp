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

	library1.browseAllAccounts();
	//library1.browseAllBooks();

	/**/
	//library1.browseBooks("title");
	cout << endl;
	library1.findBook(100);

	cout << endl;
	library1.findBook(46);

	library1.browseAccounts("checkouts");
	
	return 0;
}

#endif