#ifndef BOOKWAREHOUSE_CPP
#define BOOKWAREHOUSE_CPP

#include <iostream>
#include <string>
#include "BookWarehouse.h"

using namespace std;

unsigned int BookWarehouse::getNumBooks() {
	int numBooks = 0;
	for (map<int, Book*>::iterator it = books.begin(); it != books.end(); ++it) {
		if (books.count(it->first) && it->first != 0)
			numBooks++;
	}
	return numBooks;
}

void BookWarehouse::displayAll() {
	int i = 1;
	for (map<int, Book*>::iterator it=books.begin(); it != books.end(); ++it) {
		if (it->first != 0) {
			cout << i << ". ";
			it->second->display();
			i++;
		}
	}
}

bool BookWarehouse::addBook(Book& newBook) {
	bool success = false;
	
	unsigned int id = newBook.getID();
	books[id] = &newBook;

	return success;
}

bool BookWarehouse::delBook(unsigned int delBookId) {
	for (map<int, Book*>::iterator it=books.begin(); it!=books.end(); ++it) {
		if (it->first == delBookId) {
			cout << "\"" << it->second->getTitle() << "\" by " << it->second->getAuthor()
			     << " successfully removed." << endl;
			delete it->second; // delete pointer 
			books.erase(it); 
			break;
		}
	}
	return true;
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
	else if (criteria == "popularity") { // popularity
		multimap<int, Book*> sorted;
		for (map<int, Book*>::iterator it=books.begin(); it!=books.end(); ++it) {
			unsigned int key = it->second->getPopularity();
			if (it->first != 0)
				sorted.insert(pair<int, Book*>(key, it->second));
		}
		int c = 1;
		for (multimap<int, Book*>::iterator sortedIt=sorted.begin(); sortedIt != sorted.end(); ++sortedIt) {
			cout << c << ". ";
			sortedIt->second->display();
			c++;
		}
	}
	else {
		cout << "Invalid value." << endl;
		return;
	}
}

void BookWarehouse::recommend(User& user) {

	if (user.getNumHistory() == 0) {
		cout << "No available recommendations." << endl;
		return;
	}

	multimap<int, Book*> sorted;
	for (map<int, Book*>::iterator it=books.begin(); it!=books.end(); ++it) {
		unsigned int key = it->second->getPopularity();
		if (it->first != 0)
			sorted.insert(pair<int, Book*>(key, it->second));
	}
	
	int c_first_genre = 0;
	cout << "You love " << user.getFirstGenre() << ". We recommend: " << endl;
	for (multimap<int, Book*>::iterator sortedIt=sorted.begin(); sortedIt != sorted.end(); ++sortedIt) {
		string key = sortedIt->second->getGenre();
		if (!user.alreadyRead(sortedIt->second->getID()) && key == user.getFirstGenre() && c_first_genre < 2) {
			cout << (c_first_genre+1) << ". " << endl;
			sortedIt->second->display();
			c_first_genre++;
		} else if (c_first_genre > 1) {
			break;
		}
	}

	int c_second_genre = 0;
	
	if (!(user.getSecondGenre() == ""))
		cout << "You love " << user.getSecondGenre() << ". We recommend: " << endl;

	for (multimap<int, Book*>::iterator sortedIt=sorted.begin(); sortedIt != sorted.end(); ++sortedIt) {
		string key = sortedIt->second->getGenre();
		if (!user.alreadyRead(sortedIt->second->getID()) && key == user.getSecondGenre() && c_second_genre < 2) {
			cout << (c_second_genre+1) << ". " << endl;
			sortedIt->second->display();
			c_second_genre++;
		} else if (c_second_genre > 1) {
			break;
		}
	}

	cout << "You love " << user.getFavAuthor() << ". We recommend: " << endl;
	for (multimap<int, Book*>::iterator sortedIt=sorted.begin(); sortedIt != sorted.end(); ++sortedIt) {
		string key = sortedIt->second->getAuthor();
		if (!user.alreadyRead(sortedIt->second->getID()) && key == user.getFavAuthor()) {
			sortedIt->second->display();
			break;
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
		else if (criteria == "author"){
			author = it->second->getAuthor();
			if (author.find(phrase) != string::npos) 
				results.push_back(it->second);
		}
		else {
			cout << "Invalid value." << endl;
			return;
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

unsigned int BookWarehouse::getOverdueBooks() {
	map<int, Book*>::iterator it;
	unsigned int count = 0;
	for (it=books.begin(); it != books.end(); ++it) {
		if (it->second->isOverdue())
			count++;
	}
	return count;
}

bool BookWarehouse::checkDuplicates(string title, string author) {
	bool duplicated = false;
	map<int, Book*>::iterator it;

	for (it=books.begin(); it != books.end(); ++it) {
		if (it->second->getTitle() == title && it->second->getAuthor() == author) {
			duplicated = true;
			break;
		}
	}
	return duplicated;
}

void BookWarehouse::updateStatus(unsigned int currentTime) {
	map<int, Book*>::iterator it;
	for (it = books.begin(); it != books.end(); ++it) {
		if (it->second->getDueDate() != 0 && currentTime > it->second->getDueDate())
			it->second->setOverdue();
	}
}

bool BookWarehouse::isThereBook(unsigned int id) {
	if (books.count(id) > 0)
		return true;
	else
		return false;
}

void BookWarehouse::exportBook(ofstream& output) {
	output << to_string(getNumBooks()) << "\n";

	for (map<int, Book*>::iterator it=books.begin(); it!=books.end(); ++it) {
		if (it->first != 0) {
			output << it->second->outputFormat();
		}
	}
}

#endif
