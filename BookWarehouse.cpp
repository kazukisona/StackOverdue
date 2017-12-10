#ifndef BOOKWAREHOUSE_CPP
#define BOOKWAREHOUSE_CPP

#include <iostream>
#include <deque>
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

void BookWarehouse::searchBooks(string criteria, string phrase) {
	// use deque data structure because index O(1) access and insertion
	deque<Book*> results; 
	map<int, Book*>::iterator it;
	string title, author;
	// search in books
	for (it=books.begin(); it!=books.end(); ++it) {
		if (criteria == "title") {
			title = it->second->getTitle();
			if (title.find(phrase) != string::npos) 
				results.push_back(it->second);
		}
		else {
			author = it->second->getAuthor();
			if (author.find(phrase) != string::npos) 
				results.push_back(it->second);
		}
	}
	// display the results
	if (!results.empty()) {
		cout << "Search Results: " << endl;
		for (int i = 0; i < results.size(); ++i) {
			cout << (i+1) << ". ";
			results[i]->display();
		}
	} 
	else
		cout << "No search results found." << endl;
}

#endif