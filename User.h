#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <map>
#include "Book.h"

using namespace std;

class User {
public:
	
	// constructors
	User() {}
	User(unsigned int newId, string newName) { ID = newId; name = newName; numCheckout=0; overdue=false;}
	User(unsigned int newId, string newName, unsigned int newNumChecked);
	~User() {}

	// methods
	// mutator
	void setID(unsigned int newId) { ID = newId;} // implemented
	void setName(string newName) { name = newName;} // implemented
	void setOverdue(bool newValue) { overdue = newValue;} // implemented

	// accessor
	unsigned int getID() { return ID;} // implemented
	string getName() { return name;} // implemented
	unsigned int getNumOverdue();
	unsigned int getNumCheckout() { return numCheckout;} // implemented

	// other
	bool rentBook(Book& book);
	bool returnBook(unsigned int bookId);
	void returnAll();
	bool isOverdue() { return overdue;} // implemented
	void renewBook();
	void display();
	void displayDetail();
	void displayBooks();
	bool alreadyRead(unsigned int bookid);
	string getFirstGenre() { return firstG;}
	string getSecondGenre() { return secondG;}
	string getFavAuthor() { return favAuthor;}
	void setFavGenre();
	void setFavAuthor();
	unsigned int getNumHistory() { return history.size();}
	string outputFormat();

private:
	unsigned int ID;
	string name;
	vector<Book*> checkedOuts;
	unsigned int numCheckout;
	unsigned int numOverdue;
	bool overdue;
	map<int, Book*> history;
	string favAuthor;
	string firstG;
	string secondG;
};

#endif