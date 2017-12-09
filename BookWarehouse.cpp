#ifndef BOOKWAREHOUSE_CPP
#define BOOKWAREHOUSE_CPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "BookWarehouse.h"

using namespace std;

BookWarehouse::BookWarehouse(ifstream& newBooks) {
	//importBooks(newBooks);
}

Book* BookWarehouse::getBook(unsigned int bookId) {
	
	Book* book = books[bookId];

	return book;
}

void BookWarehouse::displayBook(unsigned int bookId) {
	books[bookId]->display();
}

void BookWarehouse::displayAll() {
	for (map<int, Book*>::iterator it=books.begin(); it != books.end(); ++it) {
		it->second->display();
		cout << endl;
	}
}

bool BookWarehouse::addBook(Book& newBook) {
	bool success = false;
	
	unsigned int id = newBook.getID();
	books[id] = &newBook;

	// increment size
	numBooks++;

	return success;
}

#endif