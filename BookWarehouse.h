#ifndef BOOKWAREHOUSE_H
#define BOOKWAREHOUSE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "Book.h"

using namespace std;

class BookWarehouse {
public:
	// constructor
	BookWarehouse() {}
	BookWarehouse(ifstream& newBooks);
	~BookWarehouse() {} // implemented

	// method
	// mutator
	void setNumBooks(unsigned int newNumBooks) { numBooks = newNumBooks;}; // implemented

	// accessor
	unsigned int getNumBooks() { return numBooks;}; // implemented
	Book* getBook(unsigned int bookId);

	// other
	bool addBook(Book& newBook);
	bool addBooks();
	bool delBook();
	bool delBooks();
	void importBooks(ifstream& newBooks);
	void exportBooks(ofstream& outBooks);
	void displayBook(unsigned int bookId);
	void displayAll();
	void sortBooks(string criteria);
	void searchBooks(string criteria);

private:
	unsigned int numBooks;
	map<int, Book*> books;
};

#endif