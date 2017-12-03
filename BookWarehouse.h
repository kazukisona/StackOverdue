#ifndef BOOKWAREHOUSE_H
#define BOOKWAREHOUSE_H

#include <iostream>
#include <map>
#include "Book.h"

using namespace std;

class BookWarehouse {
public:
	// constructor
	BookWarehouse();
	BookWarehouse(unsigned int newNumBooks, );
	~BookWarehouse();

	// method
	// mutator
	void setNumBooks(unsigned int newNumBooks) { numBooks = newNumBooks;};

	// accessor
	unsigned int getNumBooks() { return numBooks;};

	// other
	bool addBook();
	bool delBook();
	void exportBooks();
	void displayBook();
	void displayAll();
	void sortBooks(string criteria);
	void searchBooks(string criteria);

private:
	unsigned int numBooks;
	map<int, *Book> books;
};

#endif