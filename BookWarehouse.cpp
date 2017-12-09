#ifndef BOOKWAREHOUSE_CPP
#define BOOKWAREHOUSE_CPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "BookWarehouse.h"

using namespace std;

BookWarehouse::BookWarehouse(ifstream& newBooks) {
	importBooks(newBooks);
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

void BookWarehouse::importBooks(ifstream& newBooks) {
	unsigned int newNumBooks = 0;
	newBooks >> newNumBooks;
	setNumBooks(newNumBooks);
	
	Book* temp;

	while (newBooks) {
		
		unsigned int id, popularity;
		string str_id, str_pop;
		string title, author, genre;

		getline(newBooks, str_id, '|');
		getline(newBooks, title, '|');
		getline(newBooks, author, '|');
		getline(newBooks, genre, '|');
		getline(newBooks, str_pop);

		id = atoi(str_id.c_str());
		popularity = atoi(str_pop.c_str());
			
		temp = new Book(id, title, author, genre, popularity);
		addBook(*temp);
	}

	delete temp;
	temp = nullptr;
}

bool BookWarehouse::addBook(Book& newBook) {
	bool success = false;
	unsigned int id = newBook.getID();
	books[id] = &newBook;

	return success;
}


#endif