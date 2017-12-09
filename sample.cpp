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

	inputs.open("data/library.small/books.data");

	//BookWarehouse warehouse = BookWarehouse(inputs);
	//warehouse.displayAll();
	//warehouse.displayBook(24);

	ifstream fileAccounts;

	fileAccounts.open("data/library.small/accounts.data");

	Library library1 = Library(inputs, fileAccounts);

	library1.browseAllBooks();
	cout << library1.getNumBooks() << endl;

	unsigned int newId = library1.getNumBooks();
	Book b1 = Book(newId, "Computer organization", "Patterson", "Textbook", 90);
	library1.addBook(b1);

	library1.browseAllBooks();
	library1.browseAllAccounts();
	cout << library1.getNumBooks() << endl;
	/*
	Book book1 = Book(1, "Computer Organization", "Patterson", "TextBook", 80);
	book2 = Book(2, "Harry Potter", "J. K. Rolling" , "Fiction", 1000);
	book1.display();

	vector<Book*> books1;
	books1.push_back(&book1);
	user1 = User(1, "Kazuki", 1, books1);
	user1.rentBook(book2);

	user1.displayBooks();

	user1.returnBook(1);

	user1.displayBooks();
	book1.display();

	book1.setDueDate(13);
	cout << book1.getDueDate() << endl;
	book1.renew();
	cout << book1.getDueDate() << endl;

	book1.renew();
	cout << book1.getDueDate() << endl;
	cout << book1.getNumRenewed() << endl;
	*/

	return 0;
}

#endif