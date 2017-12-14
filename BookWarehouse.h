/*
Author: Kazuki Sona
Date: 14th, Dec
Class: CSCI23500
Instructor: Simon Ayzman
Prgrram: BookWarehouse.h
*/

#ifndef BOOKWAREHOUSE_H
#define BOOKWAREHOUSE_H

#include <iostream>
#include <fstream>
#include <map>
#include <deque>
#include "Book.h"
#include "User.h"

using namespace std;

class BookWarehouse {
public:
	// constructor
	BookWarehouse() {}
	BookWarehouse(ifstream& newBooks) {}
	~BookWarehouse() {} 

	// method
	// mutator
	void setNumBooks(unsigned int newNumBooks) { numBooks = newNumBooks;}; 

	// accessor
	unsigned int getNumBooks();
	Book* getBook(unsigned int bookId) { return books[bookId];}

	// other
	bool addBook(Book& newBook);
	bool addBooks(vector<Book*>& books);
	bool delBook(unsigned int delBookId);
	void exportBooks(ofstream& outBooks);
	void displayBook(unsigned int bookId) { books[bookId]->display();} 
	void displayAll(); 
	void sortBooks(string criteria);
	void searchBooks(string criteria, string phrase);
	void recommend(User& user);
	unsigned int getOverdueBooks();
	void updateStatus(unsigned int currentTime);
	// Returns true if there is already a book with the same tilte and author
	// check duplicated book before adding a new book
	bool checkDuplicates(string title, string author);
	bool isThereBook(unsigned int id);
	void exportBook(ofstream& output);

private:
	unsigned int numBooks;
	map<int, Book*> books;
};

#endif