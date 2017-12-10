#ifndef BOOKWAREHOUSE_CPP
#define BOOKWAREHOUSE_CPP

#include <iostream>
#include <map>
#include "BookWarehouse.h"

using namespace std;

void BookWarehouse::displayAll() {
	for (map<int, Book*>::iterator it=books.begin(); it != books.end(); ++it) {
		if (it->first != 0) {
			cout << it->first << ". ";
			it->second->display();
			cout << endl;
		}
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

void BookWarehouse::sortBooks(string criteria) {
	if (criteria == "bookid") {
		displayAll(); 
		return;
	}
	else if (criteria == "title" || criteria == "author" || criteria == "genre") {
		multimap<string, Book*> sorted;
		multimap<string, Book*>::iterator sortedIt;
		for (map<int, Book*>::iterator it=books.begin(); it!=books.end(); ++it) {
			string key;
			if (criteria == "title") key = it->second->getTitle();
			else if (criteria == "author") key = it->second->getAuthor();
			else key = it->second->getGenre();
			if (it->first != 0)
				sorted.insert(pair<string, Book*>(key, it->second));
		}
		int c = 1;
		for (sortedIt=sorted.begin(); sortedIt != sorted.end(); ++sortedIt) {
			cout << c << ". ";
			sortedIt->second->display();
			c++;
		}
	}
	else {
		multimap<int, Book*> sorted;
		multimap<int, Book*>::iterator sortedIt;
		for (map<int, Book*>::iterator it=books.begin(); it!=books.end(); ++it) {
			unsigned int key = it->second->getPopularity();
			if (it->first != 0)
				sorted.insert(pair<int, Book*>(key, it->second));
		}
		int c = 1;
		for (sortedIt=sorted.begin(); sortedIt != sorted.end(); ++sortedIt) {
			cout << c << ". ";
			sortedIt->second->display();
			c++;
		}
	}
}

#endif