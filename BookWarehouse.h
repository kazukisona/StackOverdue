#ifndef BOOKWAREHOUSE_H
#define BOOKWAREHOUSE_H

#include <iostream>
#include <fstream>
#include <map>
#include "Book.h"

using namespace std;

class BookWarehouse {
public:
	// constructor
	BookWarehouse() {}
	BookWarehouse(ifstream& newBooks) {}
	~BookWarehouse() {} // implemented

	// method
	// mutator
	void setNumBooks(unsigned int newNumBooks) { numBooks = newNumBooks;}; // implemented

	// accessor
	unsigned int getNumBooks() { return numBooks;}; // implemented
	Book* getBook(unsigned int bookId) { return books[bookId];}
	unsigned int getSize() { return books.size();} // implemented

	// other
	bool addBook(Book& newBook);// implemented
	bool addBooks(vector<Book*>& books);
	bool delBook(unsigned int bookId);
	bool delBooks(vector<unsigned int> removedIds);
	void exportBooks(ofstream& outBooks);
	void displayBook(unsigned int bookId);// implemented
	void displayAll(); // implemented
	void sortBooks(string criteria);
	void searchBooks(string criteria);

private:
	unsigned int numBooks;
	map<int, Book*> books;
};

#endif