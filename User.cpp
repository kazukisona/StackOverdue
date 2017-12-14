#ifndef USER_CPP
#define USER_CPP

#include <iostream>
#include "User.h"

using namespace std;

User::User(unsigned int newId, string newName, unsigned int newNumChecked) {
	ID = newId;
	name = newName;
	numCheckout = newNumChecked;
	overdue = false;
	favAuthor = "";
	firstG = "";
	secondG = "";
}

unsigned int User::getNumOverdue() {
	unsigned int numOverdue = 0;
	for (int i = 0; i < checkedOuts.size(); ++i) {
		if (checkedOuts[i]->isOverdue()) {
			numOverdue++;
		}
	}
	return numOverdue;
}

bool User::rentBook(Book& book) {
	bool success = false;
	if (checkedOuts.capacity() >= 10 || overdue) 
		return success;

	book.setCheckedUser(ID);
	checkedOuts.push_back(&book);

	if (!alreadyRead(book.getID()))
		history[book.getID()] = &book;

	if (!book.alreadyChecked(ID)) {
		book.addHistory(ID);
		book.incrPopularity();
	}

	setFavGenre();
	setFavAuthor();

	success = true;
	return success;
}

bool User::returnBook(unsigned int bookId) {
	bool success = false;

	for (int i = 0; i < checkedOuts.size(); ++i) {
		if (checkedOuts[i]->getID() == bookId) {
			checkedOuts[i]->clearChecked();
			checkedOuts.erase(checkedOuts.begin()+i);
			success = true;
			return success;
		}
	}
	return success;
}

void User::returnAll() {
	for (int i = 0; i < checkedOuts.size(); ++i) {
		cout << "\""<< checkedOuts[i]->getTitle() << "\" by " << checkedOuts[i]->getAuthor() 
		     << " (BookID# " << checkedOuts[i]->getID() << ") force returned." << endl;
		checkedOuts[i]->clearChecked();
	}
	checkedOuts.clear();
}

void User::renewBook() {
	int renewed = 0;
	int c = 1;
	for (int i = 0; i < checkedOuts.size(); ++i) {
		if (!(checkedOuts[i]->getNumRenewed() >= 2))
			renewed++;
		if (checkedOuts[i]->isOverdue()) {
			cout << "Account has books overdue." << endl;
			return;
		}
	}
	cout << renewed << " of " << checkedOuts.size() << " books successfully renewed." << endl;
	for (vector<Book*>::iterator it=checkedOuts.begin(); it!=checkedOuts.end(); ++it) {
		string message;
		if (!((*it)->getNumRenewed() >= 2)) {
			(*it)->renew();
			message = "Book successfully renewed.\n";
		} 
		else 
			message = "Book already renewed twice.\n";
		cout << "\t" << c << ". " << endl;
		(*it)->displayDetail(true);
		c++;
	}
}

void User::display() {
	cout << name << " (AccountID# " << ID << "). ";
	if (checkedOuts.size() > 0)
		cout << checkedOuts.size() << " books checked out: " << endl;
	else
		cout << "No books checked out." << endl;
	
	displayBooks();
}

void User::displayDetail() {
	cout << "Name: " << name << endl;
	cout << "AccountID#: " << ID << endl;
	cout << checkedOuts.size() << " books checked out";

	if (overdue) cout << " (" << numOverdue << " overdue):" << endl;
	else cout << "." << endl;

	int c = 1;
	for (vector<Book*>::iterator it = checkedOuts.begin(); it != checkedOuts.end(); ++it) {
		cout << "\t" << c << "." << endl;
		(*it)->displayDetail(true);
		c++;
	}
}

void User::displayBooks() {
	int c = 1;
	for (vector<Book*>::iterator it = checkedOuts.begin(); it != checkedOuts.end(); ++it) {
		cout << "\t" << c << ". ";
		(*it)->display();
		c++;
	}
}

bool User::alreadyRead(unsigned int bookid) {
	bool read = false;

	if (history.count(bookid) > 0)
		read = true;
	return read;
}

void User::setFavGenre() {
	multimap<string, Book*> favs;
	string key = "";
	for (map<int, Book*>::iterator it = history.begin(); it != history.end(); ++it) {
		key = it->second->getGenre();
		favs.insert(pair<string, Book*>(key, it->second));
	}

	multimap<int, string> tops;
	for (multimap<string, Book*>::iterator it = favs.begin(); it != favs.end(); ++it) {
		tops.insert(pair<int, string>(favs.count(it->first), it->first));
	}
		
	multimap<int, string>::reverse_iterator rit = tops.rbegin();
	firstG = rit->second;

	for (rit=tops.rbegin(); rit!=tops.rend(); ++rit) {
		if (rit->second != firstG) {
			secondG = rit->second;
			break;
		}
	}
}

void User::setFavAuthor() {
	multimap<string, Book*> favs;
	string key = "";
	for (map<int, Book*>::iterator it = history.begin(); it != history.end(); ++it) {
		key = it->second->getAuthor();
		favs.insert(pair<string, Book*>(key, it->second));
	}

	multimap<int, string> tops;
	for (multimap<string, Book*>::iterator it = favs.begin(); it != favs.end(); ++it) {
		tops.insert(pair<int, string>(favs.count(it->first), it->first));
	}

	multimap<int, string>::reverse_iterator rit = tops.rbegin();
	favAuthor = rit->second;
}

string User::outputFormat() {
	string output;
	string bar = "|";

	output = to_string(ID) + bar + name + bar + to_string(getNumCheckout()) + "\n";
	for (int i = 0; i < checkedOuts.size(); ++i) {
		output += to_string(checkedOuts[i]->getID()) + bar;
		output += to_string(checkedOuts[i]->getDueDate()) + bar;
		output += to_string(checkedOuts[i]->getNumRenewed()) + "\n";
	}

	return output;
}

#endif