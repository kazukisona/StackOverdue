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

	// other
	bool addBook(Book& newBook);// implemented
	bool addBooks(vector<Book*>& books);
	bool delBook(unsigned int bookId);
	void exportBooks(ofstream& outBooks);
	void displayBook(unsigned int bookId) { books[bookId]->display();} // implemented
	void displayAll(); // implemented
	void sortBooks(string criteria);
	void searchBooks(string criteria, string phrase);

private:
	unsigned int numBooks;
	map<int, Book*> books;
};

#endif